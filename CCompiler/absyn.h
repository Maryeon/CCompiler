#ifndef ABSYN_H
#define ABSYN_H
#include <llvm/IR/Value.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class CodeGenContext;
class Block;
class Expression;
class Statement;
class VariableDeclaration;

typedef std::vector<shared_ptr<Expression>> ExpressionList;
typedef std::vector<shared_ptr<Statement>> StatementList;
typedef std::vector<shared_ptr<VariableDeclaration>> VariableDeclarationList;

class Node{
public:
	Node(){}
	virtual ~Node(){}
	virtual string getType() const = 0;
	virtual llvm::Value *codeGen(CodeGenContext &context) { return (llvm::Value *)0; }
};

class Expression: public Node{
public:
	Expression(){}
	
	string getType()const override{
		return "Expression";
	}
};

class Statement: public Node{
public:
	Statement(){}
	
	string getType()const override{
		return "Statement";
	}
};

class Double: public Expression{
public:
	double value;
	
	Double(){};
	
	Double(double value):value(value){}
	
	string getType()const override{
		return "Double";
	}
	
	double getValue()const{
		return value;
	}

	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
	
};

class Integer: public Expression{
public:	
	int value;
	
	Integer(){}
	
	Integer(int value):value(value){}
	
	string getType()const override{
		return "Integer";
	}
	
	int getValue()const{
		return value;
	}

	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class Identifier: public Expression{
public:
	string name;
	bool isType = false;
	
	Identifier(){}
	
	Identifier(const std::string &name)
		:name(name){}
		
	string getType()const override{
		return "Identifier";
	}
	
	string getName()const{
		return name;
	}

	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
	
};

class FuntionCall: public Expression{
public:
	const shared_ptr<Identifier> name;
	shared_ptr<ExpressionList> arguments = make_shared<ExpressionList>();

	FuntionCall(){}
	
	FuntionCall(const shared_ptr<Identifier> name, shared_ptr<ExpressionList> arguments)
		:name(name), arguments(arguments){}
		
	FuntionCall(const shared_ptr<Identifier> name)
		:name(name){}
		
	string getType()const override{
		return "FunctionCall";
	}
	
	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class BinaryOperation: public Expression{
public:
	int op;
	shared_ptr<Expression> loperand;
	shared_ptr<Expression> roperand;
	
	BinaryOperation(){};
	
	BinaryOperation(int op, shared_ptr<Expression> loperand,  shared_ptr<Expression> roperand)
		:op(op), loperand(loperand),  roperand(roperand){}
		
	string getType()const override{
		return "BinaryOperation";
	}

	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class Assignment: public Expression{
public:	
	//int op;
	shared_ptr<Identifier> loperand;
	shared_ptr<Expression> roperand;

	Assignment(){}
	
	Assignment( shared_ptr<Identifier> loperand, shared_ptr<Expression> roperand)
		:loperand(loperand), roperand(roperand){}
		
	string getType()const override{
		return "Assignment";
	}

	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class ArrayIndex: public Expression{
public:
	shared_ptr<Identifier> arrayName;
	shared_ptr<ExpressionList> expressions = make_shared<ExpressionList>();

	ArrayIndex(){};
	
	ArrayIndex(shared_ptr<Identifier> arrayName, shared_ptr<ExpressionList> expressions)
		:arrayName(arrayName), expressions(expressions){}
		
	ArrayIndex(shared_ptr<Identifier> arrayName, shared_ptr<Expression> expression)
		:arrayName(arrayName){
		expressions->push_back(expression);
	}

	string getType()const override{
		return "ArrayIndex";
	}

	llvm::Value *codeGen(CodeGenContext &context) override ;
};

class ArrayAssignment: public Expression{
public:
	shared_ptr<ArrayIndex> loperand;
	shared_ptr<Expression> roperand;
	
	ArrayAssignment(){}
	
	ArrayAssignment(shared_ptr<ArrayIndex> loperand, shared_ptr<Expression> roperand)
		:loperand(loperand), roperand(roperand){}

	string getType()const override{
		return "ArrayAssignment";
	}

	llvm::Value *codeGen(CodeGenContext &context) override ;
}; 

class StructMember :public Expression{
public:
	shared_ptr<Identifier> name;
	shared_ptr<Identifier> member;
	
	StructMember(){}
	
	StructMember(shared_ptr<Identifier> name, shared_ptr<Identifier> member)
		:name(name), member(member){}

	string getType()const override{
		return "StructMember";
	}
	
	llvm::Value *codeGen(CodeGenContext &context) override ;
};


class StructAssignment: public Expression{
public:
	shared_ptr<StructMember> loperand;
	shared_ptr<Expression> roperand;
	
	StructAssignment(){}
	
	StructAssignment(shared_ptr<StructMember> loperand, shared_ptr<Expression> roperand)
		:loperand(loperand), roperand(roperand){}

	string getType()const override{
		return "StructAssignment";
	}

	llvm::Value *codeGen(CodeGenContext &context) override;		
};



class Literal: public Expression{
public:	
	string value;

	Literal(){}
	
	Literal(const string &value):value(value){}
	
	string getType()const override{
		return "Literal";
	}

	llvm::Value *codeGen(CodeGenContext &context) override;
};

class Block: public Statement{
public:
	shared_ptr<StatementList> statements = make_shared<StatementList>();
	
	Block(){
		cout<<"BLOCKhdsa"<<endl;
	}
	
	Block(shared_ptr<StatementList> statements): statements(statements){}
	
	string getType()const override{
		return "Block";
	}

	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class ExpressionStatement: public Statement{
public:
	shared_ptr<Expression> expression;
	
	ExpressionStatement(){}
	
	ExpressionStatement(shared_ptr<Expression> expression): expression(expression){}
	
	string getType()const override{
		return "ExpressionStatement";
	}

	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class VariableDeclaration: public Statement{
public:
	const shared_ptr<Identifier> type;
	shared_ptr<Identifier> name;
	shared_ptr<Expression> init = nullptr;
	
	VariableDeclaration(){}
	
	VariableDeclaration(const shared_ptr<Identifier> type, shared_ptr<Identifier> name, shared_ptr<Expression> init = NULL)
		:type(type), name(name), init(init){}
		
	string getType()const override{
		return "VariableDeclaration";
	}

	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class ArrayDeclaration: public Statement{
public:
	const shared_ptr<Identifier> type;
	shared_ptr<Identifier> name;
	shared_ptr<ExpressionList> arraySize = make_shared<ExpressionList>();
	shared_ptr<ExpressionList> inits = nullptr;

	ArrayDeclaration(){}

	ArrayDeclaration(const shared_ptr<Identifier> type, shared_ptr<Identifier> name)
		:type(type), name(name){}

	string getType()const override{
		return "ArrayDeclaration";
	}

	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class FunctionDeclaration: public Statement{
public:
	shared_ptr<Identifier> retType;
	shared_ptr<Identifier> name;
	shared_ptr<VariableDeclarationList> arguments = make_shared<VariableDeclarationList>();
	shared_ptr<Block> block;

	FunctionDeclaration(){}
	
	FunctionDeclaration(shared_ptr<Identifier> retType, shared_ptr<Identifier> name, shared_ptr<VariableDeclarationList> arguments, shared_ptr<Block> block)
		:retType(retType), name(name), arguments(arguments), block(block){}
		
	string getType()const override{
		return "FunctionDeclaration";
	}
	
	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class StructDeclaration: public Statement{
public:
	shared_ptr<Identifier> typeName;
	shared_ptr<VariableDeclarationList> members = make_shared<VariableDeclarationList>();
	shared_ptr<Identifier> instName = nullptr;
	shared_ptr<ExpressionList> inits = nullptr;

	StructDeclaration();
	
	StructDeclaration(shared_ptr<Identifier> typeName, shared_ptr<VariableDeclarationList> members, shared_ptr<Identifier> instName = nullptr, shared_ptr<ExpressionList> inits = nullptr)
		:typeName(typeName), members(members), instName(instName), inits(inits){}
		
	string getType()const override{
		return "StructDeclaration";
	}
	
	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class ReturnStatement: public Statement{
public:
	shared_ptr<Expression> expression;
	
	ReturnStatement(){}
	
	ReturnStatement(shared_ptr<Expression> expression):expression(expression){}
	
	string getType()const override{
		return "ReturnStatement";
	}
	
	virtual llvm::Value* codeGen(CodeGenContext& context) override ;
};

class IfStatement: public Statement{
public:
	shared_ptr<Expression> condition;
	shared_ptr<Block> trueBlock;
	shared_ptr<Block> falseBlock = NULL;
	
	IfStatement(){}
	
	IfStatement(shared_ptr<Expression> condition, shared_ptr<Block> trueBlock, shared_ptr<Block> falseBlock = NULL)
		:condition(condition), trueBlock(trueBlock), falseBlock(falseBlock){}
	
	string getType()const override{
		return "IfStatement";
	}
	
	llvm::Value *codeGen(CodeGenContext &context) override ;
};

class ForStatement: public Statement{
public:
	shared_ptr<Expression> init = NULL, condition = NULL, increment = NULL;
	shared_ptr<Block> block;
	
	ForStatement(){}
	
	ForStatement(shared_ptr<Block> block,shared_ptr<Expression> init = NULL, shared_ptr<Expression> condition = NULL, shared_ptr<Expression> increment = NULL)
		:init(init), condition(condition), increment(increment), block(block){}
	
	string getType()const override{
		return "ForStatement";
	}
	
	llvm::Value *codeGen(CodeGenContext &context) override ;
};



struct WhileStatement: public Statement{
public:
	shared_ptr<Expression> condition;
	shared_ptr<Block> block;
	
	WhileStatement(){}
	WhileStatement(shared_ptr<Expression> condition, shared_ptr<Block> block)
		:condition(condition), block(block){}

	string getType()const override{
		return "WhileStatement";
	}
	
	llvm::Value *codeGen(CodeGenContext &context) override ;
};

std::unique_ptr<Expression> LogError(const char* srt);


#endif

























