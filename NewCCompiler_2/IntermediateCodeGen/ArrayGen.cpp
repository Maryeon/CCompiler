#include "CodeGen.h"

//Resolve Array

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