#include "CodeGen.h"

#define ISTYPE(value, id) (value->getType()->getTypeID() == id)

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

llvm::Value* ReturnStatement::codeGen(CodeGenContext &context) {
    cout << "Generate Return Statement" << endl;
    Value* returnValue = this->expression->codeGen(context);
    context.setCurrentReturnValue(returnValue);
    return returnValue;
}

llvm::Value* IfStatement::codeGen(CodeGenContext &context) {
    cout << "Generate If statement" << endl;
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

    if( thenBB->getTerminator() == nullptr ){       
        context.builder.CreateBr(mergeBB);
    }

    if( this->falseBlock ){
        theFunction->getBasicBlockList().push_back(falseBB);    
        context.builder.SetInsertPoint(falseBB);            

        context.pushBlock(thenBB);

        this->falseBlock->codeGen(context);

        context.popBlock();

        context.builder.CreateBr(mergeBB);
    }

    theFunction->getBasicBlockList().push_back(mergeBB);        
    context.builder.SetInsertPoint(mergeBB);        

    return nullptr;
}

llvm::Value* ForStatement::codeGen(CodeGenContext &context) {
    cout << "Generate For statement" << endl;

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

llvm::Value* WhileStatement::codeGen(CodeGenContext &context) {
    cout << "Generate While statement" << endl;

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

