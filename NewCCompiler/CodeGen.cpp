#include <llvm/IR/Value.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/IRPrintingPasses.h>
#include <llvm/Support/raw_ostream.h>

#include "absyn.h"
#include "CodeGen.h"
#include "TypeSystem.h"
using legacy::PassManager;
#define ISTYPE(value, id) (value->getType()->getTypeID() == id)


static Type* TypeOf(const Identifier & type, CodeGenContext& context){        // get llvm::type of variable base on its identifier
    return context.typeSystem.getVarType(type);
}

static Value* CastToBoolean(CodeGenContext& context, Value* condValue){

    if( ISTYPE(condValue, Type::IntegerTyID) ){
        condValue = context.builder.CreateIntCast(condValue, Type::getInt1Ty(context.llvmContext), true);
        return context.builder.CreateICmpNE(condValue, ConstantInt::get(Type::getInt1Ty(context.llvmContext), 0, true));
    }else if( ISTYPE(condValue, Type::DoubleTyID) ){
        return context.builder.CreateFCmpONE(condValue, ConstantFP::get(context.llvmContext, APFloat(0.0)));
    }else{
        return condValue;
    }
}

static llvm::Value* calcArrayIndex(shared_ptr<ArrayIndex> index, CodeGenContext &context){
    auto sizeVec = context.getArraySize(index->arrayName->name);
    cout << "sizeVec:" << sizeVec.size() << ", expressions: " << index->expressions->size() << endl;
    assert(sizeVec.size() > 0 && sizeVec.size() == index->expressions->size());
    auto expression = *(index->expressions->rbegin());

    for(unsigned int i=sizeVec.size()-1; i>=1; i--){
        auto temp = make_shared<BinaryOperation>( MUL_OP,make_shared<Integer>(sizeVec[i]), index->expressions->at(i-1));

        expression = make_shared<BinaryOperation>(PLUS_OP, temp,  expression);

    }

    return expression->codeGen(context);
}

void CodeGenContext::generateCode(Block& root) {
    cout << "Generating IR code" << endl;

    std::vector<Type*> sysArgs;
    FunctionType* mainFuncType = FunctionType::get(Type::getVoidTy(this->llvmContext), makeArrayRef(sysArgs), false);
    Function* mainFunc = Function::Create(mainFuncType, GlobalValue::ExternalLinkage, "main");
    BasicBlock* block = BasicBlock::Create(this->llvmContext, "entry");

    pushBlock(block);
    Value* retValue = root.codeGen(*this);
    popBlock();

    cout << "Code generate success" << endl;

    PassManager passManager;
    passManager.add(createPrintModulePass(outs()));
    passManager.run(*(this->theModule.get()));
    return;
}



llvm::Value* Double::codeGen(CodeGenContext &context) {
    cout << "Generating Double: " << this->value << endl;
    return ConstantFP::get(Type::getDoubleTy(context.llvmContext), this->value);

}

llvm::Value* Integer::codeGen(CodeGenContext &context) {
    cout << "Generating Integer: " << this->value << endl;
    return ConstantInt::get(Type::getInt32Ty(context.llvmContext), this->value, true);

}

llvm::Value* Identifier::codeGen(CodeGenContext &context) {
    cout << "Generating identifier " << this->name << endl;
    Value* value = context.getSymbolValue(this->name);
    if( !value ){
        return LogErrorV("Unknown variable name " + this->name);
    }
    if( value->getType()->isPointerTy() ){
        auto arrayPtr = context.builder.CreateLoad(value, "arrayPtr");
        if( arrayPtr->getType()->isArrayTy() ){
            cout << "(Array Type)" << endl;

            std::vector<Value*> indices;
            indices.push_back(ConstantInt::get(context.typeSystem.intTy, 0, false));
            auto ptr = context.builder.CreateInBoundsGEP(value, indices, "arrayPtr");
            return ptr;
        }
    }

    return context.builder.CreateLoad(value, false, "");

}

llvm::Value* FuntionCall::codeGen(CodeGenContext &context) {
    cout << "Generating method call of " << this->name->name << endl;
    Function * calleeF = context.theModule->getFunction(this->name->name);
    if( !calleeF ){
        LogErrorV("Function name not found");
    }
    if( calleeF->arg_size() != this->arguments->size() ){
        LogErrorV("Function arguments size not match, calleeF=" + std::to_string(calleeF->size()) + ", this->arguments=" + std::to_string(this->arguments->size()) );
    }
    std::vector<Value*> argsv;
    for(auto it=this->arguments->begin(); it!=this->arguments->end(); it++){
        argsv.push_back((*it)->codeGen(context));
        if( !argsv.back() ){        // if any argument codegen fail
            return nullptr;
        }
    }
    return context.builder.CreateCall(calleeF, argsv, "calltmp");
}

llvm::Value* BinaryOperation::codeGen(CodeGenContext &context) {
    cout << "Generating binary operator" << endl;

    Value* L = this->loperand->codeGen(context);
    Value* R = this->roperand->codeGen(context);
    bool fp = false;

    if( (L->getType()->getTypeID() == Type::DoubleTyID) || (R->getType()->getTypeID() == Type::DoubleTyID) ){  // type upgrade
        fp = true;
        if( (R->getType()->getTypeID() != Type::DoubleTyID) ){
            R = context.builder.CreateUIToFP(R, Type::getDoubleTy(context.llvmContext), "ftmp");
        }
        if( (L->getType()->getTypeID() != Type::DoubleTyID) ){
            L = context.builder.CreateUIToFP(L, Type::getDoubleTy(context.llvmContext), "ftmp");
        }
    }

    if( !L || !R ){
        return nullptr;
    }
    cout << "fp = " << ( fp ? "true" : "false" ) << endl;
    cout << "L is " << TypeSystem::llvmTypeToStr(L) << endl;
    cout << "R is " << TypeSystem::llvmTypeToStr(R) << endl;

    switch (this->op){
        case PLUS_OP:
            return fp ? context.builder.CreateFAdd(L, R, "addftmp") : context.builder.CreateAdd(L, R, "addtmp");
        case MINUS_OP:
            return fp ? context.builder.CreateFSub(L, R, "subftmp") : context.builder.CreateSub(L, R, "subtmp");
        case MUL_OP:
            return fp ? context.builder.CreateFMul(L, R, "mulftmp") : context.builder.CreateMul(L, R, "multmp");
        case DIV_OP:
            return fp ? context.builder.CreateFDiv(L, R, "divftmp") : context.builder.CreateSDiv(L, R, "divtmp");
        case AND_OP:
            return fp ? LogErrorV("Double type has no AND operation") : context.builder.CreateAnd(L, R, "andtmp");
        case OR_OP:
            return fp ? LogErrorV("Double type has no OR operation") : context.builder.CreateOr(L, R, "ortmp");
        case XOR_OP:
            return fp ? LogErrorV("Double type has no XOR operation") : context.builder.CreateXor(L, R, "xortmp");
        

        case LT_OP:
            return fp ? context.builder.CreateFCmpULT(L, R, "cmpftmp") : context.builder.CreateICmpULT(L, R, "cmptmp");
        case LE_OP:
            return fp ? context.builder.CreateFCmpOLE(L, R, "cmpftmp") : context.builder.CreateICmpSLE(L, R, "cmptmp");
        case GE_OP:
            return fp ? context.builder.CreateFCmpOGE(L, R, "cmpftmp") : context.builder.CreateICmpSGE(L, R, "cmptmp");
        case GT_OP:
            return fp ? context.builder.CreateFCmpOGT(L, R, "cmpftmp") : context.builder.CreateICmpSGT(L, R, "cmptmp");
        case EQ_OP:
            return fp ? context.builder.CreateFCmpOEQ(L, R, "cmpftmp") : context.builder.CreateICmpEQ(L, R, "cmptmp");
        case NE_OP:
            return fp ? context.builder.CreateFCmpONE(L, R, "cmpftmp") : context.builder.CreateICmpNE(L, R, "cmptmp");
        default:
            return LogErrorV("Unknown binary operator");
    }
}

llvm::Value* Assignment::codeGen(CodeGenContext &context) {
    cout << "Generating assignment of " << this->loperand->name << " = " << endl;
    Value* dst = context.getSymbolValue(this->loperand->name);
    auto dstType = context.getSymbolType(this->loperand->name);
    string dstTypeStr = dstType->name;
    if( !dst ){
        return LogErrorV("Undeclared variable");
    }
    Value* exp = exp = this->roperand->codeGen(context);

    cout << "dst typeid = " << TypeSystem::llvmTypeToStr(context.typeSystem.getVarType(dstTypeStr)) << endl;
    cout << "exp typeid = " << TypeSystem::llvmTypeToStr(exp) << endl;

    exp = context.typeSystem.cast(exp, context.typeSystem.getVarType(dstTypeStr), context.currentBlock());
    context.builder.CreateStore(exp, dst);
    return dst;
}

llvm::Value *ArrayAssignment::codeGen(CodeGenContext &context) {
    cout << "Generating array index assignment of " << this->loperand->arrayName->name << endl;
    auto varPtr = context.getSymbolValue(this->loperand->arrayName->name);

    if( varPtr == nullptr ){
        return LogErrorV("Unknown variable name");
    }
    
    auto arrayPtr = context.builder.CreateLoad(varPtr, "arrayPtr");

    if( !arrayPtr->getType()->isArrayTy() && !arrayPtr->getType()->isPointerTy() ){
        return LogErrorV("The variable is not array");
    }

    auto index = calcArrayIndex(loperand, context);

    ArrayRef<Value*> gep2_array{ ConstantInt::get(Type::getInt64Ty(context.llvmContext), 0), index };
    auto ptr = context.builder.CreateInBoundsGEP(varPtr, gep2_array, "elementPtr");

    return context.builder.CreateAlignedStore(this->roperand->codeGen(context), ptr, 4);
}

llvm::Value* StructAssignment::codeGen(CodeGenContext &context) {
    cout << "Generating struct assignment of " << this->loperand->name->name << "." << this->loperand->name->name << endl;
    auto varPtr = context.getSymbolValue(this->loperand->name->name);
    auto structPtr = context.builder.CreateLoad(varPtr, "structPtr");

    structPtr->setAlignment(4);

    if( !structPtr->getType()->isStructTy() ){
        return LogErrorV("The variable is not struct");
    }

    string structName = structPtr->getType()->getStructName().str();
    long memberIndex = context.typeSystem.getStructMemberIndex(structName, this->loperand->member->name);

    std::vector<Value*> indices;
    auto value = this->roperand->codeGen(context);

    indices.push_back(ConstantInt::get(context.typeSystem.intTy, 0, false));
    indices.push_back(ConstantInt::get(context.typeSystem.intTy, (uint64_t)memberIndex, false));

    auto ptr = context.builder.CreateInBoundsGEP(varPtr, indices, "structMemberPtr");

    return context.builder.CreateStore(value, ptr);
}

llvm::Value *ArrayIndex::codeGen(CodeGenContext &context) {
    cout << "Generating array index expression of " << this->arrayName->name << endl;
    auto varPtr = context.getSymbolValue(this->arrayName->name);
    auto type = context.getSymbolType(this->arrayName->name);
    string typeStr = type->name;

    assert(type->isArray);

    auto value = calcArrayIndex(make_shared<ArrayIndex>(*this), context);
    ArrayRef<Value*> indices;
    if(context.isFuncArg(this->arrayName->name) ){
        cout << "isFuncArg" << endl;
        varPtr = context.builder.CreateLoad(varPtr, "actualArrayPtr");
        //indices = { value };
    }else if( varPtr->getType()->isPointerTy() ){
        cout << this->arrayName->name << "Not isFuncArg" << endl;
        indices = { ConstantInt::get(Type::getInt64Ty(context.llvmContext), 0), value };
    }else{
        return LogErrorV("The variable is not array");
    }
    auto ptr = context.builder.CreateInBoundsGEP(varPtr, indices, "elementPtr");

    return context.builder.CreateAlignedLoad(ptr, 4);
}

llvm::Value *Literal::codeGen(CodeGenContext &context) {
    return context.builder.CreateGlobalString(this->value, "string");
}

llvm::Value* Block::codeGen(CodeGenContext &context) {
    cout << "Generating block" << endl;
    Value* last = nullptr;
    for(auto it=this->statements->begin(); it!=this->statements->end(); it++){
        last = (*it)->codeGen(context);
    }
    return last;
}

llvm::Value* ExpressionStatement::codeGen(CodeGenContext &context) {
    return this->expression->codeGen(context);
}

llvm::Value* VariableDeclaration::codeGen(CodeGenContext &context) {
    cout << "Generating variable declaration of " << this->type->name << " " << this->name->name << endl;
    Type* type = TypeOf(*this->type, context);
    Value* initial = nullptr;

    Value* inst = nullptr;

    if( this->type->isArray ){
        uint64_t arraySize = 1;
        std::vector<uint64_t> arraySizes;
        for(auto it=this->type->arraySize->begin(); it!=this->type->arraySize->end(); it++){
            Integer* integer = dynamic_cast<Integer*>(it->get());
            arraySize *= integer->value;
            arraySizes.push_back(integer->value);
        }

        context.setArraySize(this->name->name, arraySizes);
        Value* arraySizeValue = Integer(arraySize).codeGen(context);
        auto arrayType = ArrayType::get(context.typeSystem.getVarType(this->type->name), arraySize);
        inst = context.builder.CreateAlloca(arrayType, arraySizeValue, "arraytmp");
    }else{
        inst = context.builder.CreateAlloca(type);
    }

    context.setSymbolType(this->name->name, this->type);
    context.setSymbolValue(this->name->name, inst);

    context.PrintSymTable();

    if( this->init != nullptr ){
        Assignment assignment(this->name, this->init);
        assignment.codeGen(context);
    }
    return inst;
}








llvm::Value *ArrayInitialization::codeGen(CodeGenContext &context) {
    cout << "Generating array initialization of " << this->declaration->name->name << endl;
    auto arrayPtr = this->declaration->codeGen(context);
    auto sizeVec = context.getArraySize(this->declaration->name->name);
    // TODO: multi-dimension array initialization
    assert(sizeVec.size() == 1);

    for(int index=0; index < this->expressions->size(); index++){
        shared_ptr<Integer> indexValue = make_shared<Integer>(index);

        shared_ptr<ArrayIndex> arrayIndex = make_shared<ArrayIndex>(this->declaration->name, indexValue);
        ArrayAssignment assignment(arrayIndex, this->expressions->at(index));
        assignment.codeGen(context);
    }
    return nullptr;
}


llvm::Value* FunctionDeclaration::codeGen(CodeGenContext &context) {
    cout << "Generating function declaration of " << this->name->name << endl;
    std::vector<Type*> argTypes;

    for(auto &arg: *this->arguments){
        if( arg->type->isArray ){
            argTypes.push_back(PointerType::get(context.typeSystem.getVarType(arg->type->name), 0));
        } else{
            argTypes.push_back(TypeOf(*arg->type, context));
        }
    }
    Type* retType = nullptr;
    if( this->retType->isArray )
        retType = PointerType::get(context.typeSystem.getVarType(this->retType->name), 0);
    else
        retType = TypeOf(*this->retType, context);

    FunctionType* functionType = FunctionType::get(retType, argTypes, false);
    Function* function = Function::Create(functionType, GlobalValue::ExternalLinkage, this->name->name.c_str(), context.theModule.get());

    return function;
}


llvm::Value* StructDeclaration::codeGen(CodeGenContext& context) {
    cout << "Generating struct declaration of " << this->name->name << endl;

    std::vector<Type*> memberTypes;

//    context.builder.createstr
    auto structType = StructType::create(context.llvmContext, this->name->name);
    context.typeSystem.addStructType(this->name->name, structType);

    for(auto& member: *this->members){
        context.typeSystem.addStructMember(this->name->name, member->type->name, member->name->name);
        memberTypes.push_back(TypeOf(*member->type, context));
    }

    structType->setBody(memberTypes);

    return nullptr;
}


llvm::Value* ReturnStatement::codeGen(CodeGenContext &context) {
    cout << "Generating return statement" << endl;
    Value* returnValue = this->expression->codeGen(context);
    context.setCurrentReturnValue(returnValue);
    return returnValue;
}

llvm::Value* IfStatement::codeGen(CodeGenContext &context) {
    cout << "Generating if statement" << endl;
    Value* condValue = this->condition->codeGen(context);
    if( !condValue )
        return nullptr;

    condValue = CastToBoolean(context, condValue);

    Function* theFunction = context.builder.GetInsertBlock()->getParent();      // the function where if statement is in

    BasicBlock *thenBB = BasicBlock::Create(context.llvmContext, "then", theFunction);
    BasicBlock *falseBB = BasicBlock::Create(context.llvmContext, "else");
    BasicBlock *mergeBB = BasicBlock::Create(context.llvmContext, "ifcont");

    if( this->falseBlock ){
        context.builder.CreateCondBr(condValue, thenBB, falseBB);
    } else{
        context.builder.CreateCondBr(condValue, thenBB, mergeBB);
    }

    context.builder.SetInsertPoint(thenBB);

    context.pushBlock(thenBB);

    this->trueBlock->codeGen(context);

    context.popBlock();

    thenBB = context.builder.GetInsertBlock();

    if( thenBB->getTerminator() == nullptr ){       //
        context.builder.CreateBr(mergeBB);
    }

    if( this->falseBlock ){
        theFunction->getBasicBlockList().push_back(falseBB);    //
        context.builder.SetInsertPoint(falseBB);            //

        context.pushBlock(thenBB);

        this->falseBlock->codeGen(context);

        context.popBlock();

        context.builder.CreateBr(mergeBB);
    }

    theFunction->getBasicBlockList().push_back(mergeBB);        //
    context.builder.SetInsertPoint(mergeBB);        //

    return nullptr;
}

llvm::Value* ForStatement::codeGen(CodeGenContext &context) {

    Function* theFunction = context.builder.GetInsertBlock()->getParent();

    BasicBlock *block = BasicBlock::Create(context.llvmContext, "forloop", theFunction);
    BasicBlock *after = BasicBlock::Create(context.llvmContext, "forcont");

    // execute the initial
    if( this->init )
        this->init->codeGen(context);

    Value* condValue = this->condition->codeGen(context);
    if( !condValue )
        return nullptr;

    condValue = CastToBoolean(context, condValue);

    // fall to the block
    context.builder.CreateCondBr(condValue, block, after);

    context.builder.SetInsertPoint(block);

    context.pushBlock(block);

    this->block->codeGen(context);

    context.popBlock();

    // do increment
    if( this->increment ){
        this->increment->codeGen(context);
    }

    // execute the again or stop
    condValue = this->condition->codeGen(context);
    condValue = CastToBoolean(context, condValue);
    context.builder.CreateCondBr(condValue, block, after);

    // insert the after block
    theFunction->getBasicBlockList().push_back(after);
    context.builder.SetInsertPoint(after);

    return nullptr;
}

llvm::Value *StructMember::codeGen(CodeGenContext &context) {
    cout << "Generating struct member expression of " << this->name->name << "." << this->member->name << endl;

    auto varPtr = context.getSymbolValue(this->name->name);
    auto structPtr = context.builder.CreateLoad(varPtr, "structPtr");
    structPtr->setAlignment(4);

    if( !structPtr->getType()->isStructTy() ){
        return LogErrorV("The variable is not struct");
    }

    string structName = structPtr->getType()->getStructName().str();
    long memberIndex = context.typeSystem.getStructMemberIndex(structName, this->member->name);

    std::vector<Value*> indices;
    indices.push_back(ConstantInt::get(context.typeSystem.intTy, 0, false));
    indices.push_back(ConstantInt::get(context.typeSystem.intTy, (uint64_t)memberIndex, false));
    auto ptr = context.builder.CreateInBoundsGEP(varPtr, indices, "memberPtr");

    return context.builder.CreateLoad(ptr);
}

llvm::Value* WhileStatement::codeGen(CodeGenContext &context) 
{
    Function* theFunction = context.builder.GetInsertBlock()->getParent();
    BasicBlock *block = BasicBlock::Create(context.llvmContext, "whileloop", theFunction);
    BasicBlock *after = BasicBlock::Create(context.llvmContext, "whilecont");

    // execute the initial
    Value* condValue = this->condition->codeGen(context);
    if( !condValue )
        return nullptr;
    condValue = CastToBoolean(context, condValue);

    // fall to the block
    context.builder.CreateCondBr(condValue, block, after);
    context.builder.SetInsertPoint(block);
    context.pushBlock(block);
    this->block->codeGen(context);
    context.popBlock();

    // execute the again or stop
    condValue = this->condition->codeGen(context);
    condValue = CastToBoolean(context, condValue);
    context.builder.CreateCondBr(condValue, block, after);

    // insert the after block
    theFunction->getBasicBlockList().push_back(after);
    context.builder.SetInsertPoint(after);
    return nullptr;
}

std::unique_ptr<Expression> LogError(const char *str) {
    fprintf(stderr, "LogError: %s\n", str);
    return nullptr;
}

Value *LogErrorV(string str){
    return LogErrorV(str.c_str());
}

Value *LogErrorV(const char *str) {
    LogError(str);
    return nullptr;
}


