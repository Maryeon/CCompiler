#include "CodeGen.h"

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



llvm::Value* StructDeclaration::codeGen(CodeGenContext& context) {
    cout << "Generating struct declaration of " << this->name->name << endl;

    std::vector<Type*> memberTypes;


    auto structType = StructType::create(context.llvmContext, this->name->name);
    context.typeSystem.addStructType(this->name->name, structType);

    for(auto& member: *this->members){
        context.typeSystem.addStructMember(this->name->name, member->type->name, member->name->name);
        //memberTypes.push_back(TypeOf(*member->type, context));
        memberTypes.push_back(context.typeSystem.getVarType(*member->type));
    }

    structType->setBody(memberTypes);

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

