#include "CodeGen.h"

//Resolve Struct 

llvm::Value* StructAssignment::codeGen(CodeGenContext &context) {
    cout << "Generate Struct Assignment of: " << this->loperand->name->name << "." << this->loperand->member->name << endl;
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



llvm::Value* StructDeclaration::codeGen(CodeGenContext& context) {
    cout << "Generate Struct Declaration of: " << this->typeName->name << endl;

    std::vector<Type*> memberTypes;
    Value* inst = nullptr;

    auto structType = StructType::create(context.llvmContext, this->typeName->name);
    context.typeSystem.addStructType(this->typeName->name, structType);

    for(auto& member: *this->members){
        context.typeSystem.addStructMember(this->typeName->name, member->type->name, member->name->name);
        memberTypes.push_back(context.typeSystem.getVarType(*member->type));
    }

    structType->setBody(memberTypes);

    ////////////////////////////////////////////////////////////////////////////

    if(this->instName!=nullptr){
        
       this->typeName->isType=true;
        Value* inst = nullptr;
        Type* type = context.typeSystem.getVarType(*this->typeName);
        inst = context.builder.CreateAlloca(type);

        context.setSymbolType(this->instName->name, this->typeName);
        context.setSymbolValue(this->instName->name, inst);

        context.PrintSymTable();

    }    

    return nullptr;
}

llvm::Value *StructMember::codeGen(CodeGenContext &context) {
    cout << "Generate Struct Member of: " << this->name->name << "." << this->member->name << endl;

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

