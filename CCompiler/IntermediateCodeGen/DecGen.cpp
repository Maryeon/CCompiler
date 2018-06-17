#include "CodeGen.h"

static Type* TypeOf(const Identifier & type, CodeGenContext& context){        
    return context.typeSystem.getVarType(type);
}

llvm::Value* VariableDeclaration::codeGen(CodeGenContext &context) {
    cout << "Generate Variable declaration of " << this->type->name << " " << this->name->name << endl;
    Type* type = TypeOf(*this->type, context);
    Value* initial = nullptr;

    Value* inst = nullptr;
    
    inst = context.builder.CreateAlloca(type);

    context.setSymbolType(this->name->name, this->type);
    context.setSymbolValue(this->name->name, inst);

    context.PrintSymTable();

    if( this->init != nullptr ){
        Assignment assignment(this->name, this->init);
        assignment.codeGen(context);
    }
    return inst;
}

llvm::Value* FunctionDeclaration::codeGen(CodeGenContext &context) {
    cout << "Generate Function Declaration of " << this->name->name << endl;
    std::vector<Type*> argTypes;

    for(auto &arg: *this->arguments){

            argTypes.push_back(TypeOf(*arg->type, context));

    }
    Type* retType = nullptr;

    retType = TypeOf(*this->retType, context);

    FunctionType* functionType = FunctionType::get(retType, argTypes, false);
    Function* function = Function::Create(functionType, GlobalValue::ExternalLinkage, this->name->name.c_str(), context.theModule.get());

    BasicBlock* basicBlock = BasicBlock::Create(context.llvmContext, "entry", function, nullptr);

        context.builder.SetInsertPoint(basicBlock);
        context.pushBlock(basicBlock);

        
        auto origin_arg = this->arguments->begin();

        for(auto &ir_arg_it: function->args()){
            ir_arg_it.setName((*origin_arg)->name->name);
            Value* argAlloc;

            argAlloc = (*origin_arg)->codeGen(context);

            context.builder.CreateStore(&ir_arg_it, argAlloc, false);
            context.setSymbolValue((*origin_arg)->name->name, argAlloc);
            context.setSymbolType((*origin_arg)->name->name, (*origin_arg)->type);
            context.setFuncArg((*origin_arg)->name->name, true);
            origin_arg++;
        }

        this->block->codeGen(context);
        if( context.getCurrentReturnValue() ){
            context.builder.CreateRet(context.getCurrentReturnValue());
        } else{
            return LogErrorV("Function block return value not founded");
        }
        context.popBlock();

    return function;
}


