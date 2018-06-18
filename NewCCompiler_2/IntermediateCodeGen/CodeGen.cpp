#include "CodeGen.h"

void CodeGenContext::generateCode(Block& root) {
    cout << "Generating IR code" << endl;

    std::vector<Type*> sysArgs;
    FunctionType* mainFuncType = FunctionType::get(Type::getVoidTy(this->llvmContext), makeArrayRef(sysArgs), false);
    Function* mainFunc = Function::Create(mainFuncType, GlobalValue::ExternalLinkage, "main");
    BasicBlock* block = BasicBlock::Create(this->llvmContext, "entry");

    pushBlock(block);
    Value* retValue = root.codeGen(*this);
    popBlock();

    cout << "Code generate finished" << endl;

    legacy::PassManager passManager;
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
        if( !argsv.back() ){        
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

    if( (L->getType()->getTypeID() == Type::DoubleTyID) || (R->getType()->getTypeID() == Type::DoubleTyID) ){  
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
            return LogErrorV("This operator cannot be identified!!!");
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


