#include "CodeGen.h"

void CodeGenContext::generateCode(Block& root) {
    cout << "Now Generate IR code" << endl;

    std::vector<Type*> sysArgs;
    FunctionType* mainFuncType = FunctionType::get(Type::getVoidTy(this->llvmContext), makeArrayRef(sysArgs), false);
    Function* mainFunc = Function::Create(mainFuncType, GlobalValue::ExternalLinkage, "main");
    BasicBlock* block = BasicBlock::Create(this->llvmContext, "entry");

    pushBlock(block);
    Value* retValue = root.codeGen(*this);
    popBlock();

    cout << "Code Generate Succeed!" << endl;

    legacy::PassManager passManager;
    passManager.add(createPrintModulePass(outs()));
    passManager.run(*(this->theModule.get()));
    return;
}

llvm::Value* Double::codeGen(CodeGenContext &context) {
    cout << "Generate Double: " << this->value << endl;
    return ConstantFP::get(Type::getDoubleTy(context.llvmContext), this->value);

}

llvm::Value* Integer::codeGen(CodeGenContext &context) {
    cout << "Generate Integer: " << this->value << endl;
    return ConstantInt::get(Type::getInt32Ty(context.llvmContext), this->value, true);

}

llvm::Value* Identifier::codeGen(CodeGenContext &context) {
    cout << "Generate Identifier: " << this->name << endl;

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

llvm::Value* FunctionCall::codeGen(CodeGenContext &context) {
    cout << "Generate Function Call: " << this->name->name << endl;
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
    cout << "Generate Binary Operation: " << endl;

    Value* Left = this->loperand->codeGen(context);
    Value* Right = this->roperand->codeGen(context);
    bool fp = false;

    if( (Left->getType()->getTypeID() == Type::DoubleTyID) || (Right->getType()->getTypeID() == Type::DoubleTyID) ){  
        fp = true;
        if( (Right->getType()->getTypeID() != Type::DoubleTyID) ){
            Right = context.builder.CreateUIToFP(Right, Type::getDoubleTy(context.llvmContext), "ftmp");
        }
        if( (Left->getType()->getTypeID() != Type::DoubleTyID) ){
            Left = context.builder.CreateUIToFP(Left, Type::getDoubleTy(context.llvmContext), "ftmp");
        }
    }

    if( !Left || !Right ){
        return nullptr;
    }
    cout << "fp = " << ( fp ? "true" : "false" ) << endl;
    cout << "Left is " << TypeSystem::llvmTypeToStr(Left) << endl;
    cout << "Right is " << TypeSystem::llvmTypeToStr(Right) << endl;

    switch (this->op){
        case PLUS_OP:
            return fp ? context.builder.CreateFAdd(Left, Right, "addftmp") : context.builder.CreateAdd(Left, Right, "addtmp");
        case MINUS_OP:
            return fp ? context.builder.CreateFSub(Left, Right, "subftmp") : context.builder.CreateSub(Left, Right, "subtmp");
        case MUL_OP:
            return fp ? context.builder.CreateFMul(Left, Right, "mulftmp") : context.builder.CreateMul(Left, Right, "multmp");
        case DIV_OP:
            return fp ? context.builder.CreateFDiv(Left, Right, "divftmp") : context.builder.CreateSDiv(Left, Right, "divtmp");
        case AND_OP:
            return fp ? LogErrorV("Double cannot excute AND") : context.builder.CreateAnd(Left, Right, "andtmp");
        case OR_OP:
            return fp ? LogErrorV("Double cannot excute OR") : context.builder.CreateOr(Left, Right, "ortmp");
        case XOR_OP:
            return fp ? LogErrorV("Double cannot excute XOR") : context.builder.CreateXor(Left, Right, "xortmp");
        case LT_OP:
            return fp ? context.builder.CreateFCmpULT(Left, Right, "cmpftmp") : context.builder.CreateICmpULT(Left, Right, "cmptmp");
        case LE_OP:
            return fp ? context.builder.CreateFCmpOLE(Left, Right, "cmpftmp") : context.builder.CreateICmpSLE(Left, Right, "cmptmp");
        case GE_OP:
            return fp ? context.builder.CreateFCmpOGE(Left, Right, "cmpftmp") : context.builder.CreateICmpSGE(Left, Right, "cmptmp");
        case GT_OP:
            return fp ? context.builder.CreateFCmpOGT(Left, Right, "cmpftmp") : context.builder.CreateICmpSGT(Left, Right, "cmptmp");
        case EQ_OP:
            return fp ? context.builder.CreateFCmpOEQ(Left, Right, "cmpftmp") : context.builder.CreateICmpEQ(Left, Right, "cmptmp");
        case NE_OP:
            return fp ? context.builder.CreateFCmpONE(Left, Right, "cmpftmp") : context.builder.CreateICmpNE(Left, Right, "cmptmp");
        default:
            return LogErrorV("This operator cannot be identified!!!");
    }
}

llvm::Value* Assignment::codeGen(CodeGenContext &context) {
    cout << "Generate Assignment of " << this->loperand->name << " = " << endl;
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
    cout << "Generate Block" << endl;
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


