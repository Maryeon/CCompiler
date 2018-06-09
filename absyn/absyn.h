#ifndef ABSYN_H
#define ABSYN_H
#include <iostream>
#include <string>
#include <vector>

typedef std::vector<shared_ptr<Expression>> ExpressionList;
typedef std::vector<shared_ptr<Statement>> StatementList;
typedef std::vector<shared_ptr<VariableDeclaration>> VariableDeclarationList;

class Node{
public:
	Node(){}
	virtual ~Node(){}
	virtual string getType()const = 0;
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
private:
	double value;
	
public:
	Double(){};
	
	Double(double value):value(value){}
	
	string getType()const override{
		return "Double";
	}
	
	double getValue()const{
		return value;
	}
	
};

class Interger: public Expression{
private:
	int value;
	
public:
	Interger(){}
	
	Interger(int value):value(value){}
	
	string getType()const override{
		return "Interger";
	}
	
	int getValue()const{
		return value;
	}
	
};

class Identifier: public Expression{
private:
	string name;
	
public:
	Identifier(){}
	
	Identifier(const string &name)name(name){}
	
	string getType()const override{
		return "Identifier";
	}
	
	string getName()const{
		return name;
	}
	
};

class FuntionCall: public Expression{
private:
	const shared_ptr<Identifier> name;
	shared_ptr<ExpressionList> arguments = make_shared<ExpressionList>();
	
public:
	FunctionCall(){}
	
	FunctionCall(const shared_ptr<Identifier> name, shared_ptr<ExpressionList> arguments)
		:name(name), arguments(arguments){}
		
	FunctionCall(const shared_ptr<Identifier> name)
		:name(name){}
		
	string getType()const override{
		return "FunctionCall";
	}
	
};

class BinaryOperation: public Expression{
private:
	int op;
	shared_ptr<Expression> loperand;
	shared_ptr<Expression> roperand;
	
public:
	BinaryOperation(){};
	
	BinaryOperation(int op, shared_ptr<Expression> loperand, shared_ptr<Expression> roperand)
		:op(op), loperand(loperand), roperand(roperand){}
		
	string getType()const name{
		return "BinaryOperation";
	}
};

class Assignment: public Expression{
private:
	shared_ptr<Identifier> loperand;
	shared_ptr<Expression> roperand;
	
public:
	Assignment(){}
	
	Assignment(shared_ptr<Identifier> loperand, shared_ptr<Expression> roperand)
		:loperand(loperand), roperand(roperand){}
		
	string getType()const override{
		return "Assignment";
	}
};

class ArrayAssignment: public Expression{
private:
	shared_ptr<ArrayIndex> loperand;
	shared_ptr<Expression> roperand;
	
public:
	ArrayAssignment(){}
	
	ArrayAssignment(shared_ptr<ArrayIndex> loperand, shared_ptr<Expression> roperand)
		:loperand(loperand), roperand(roperand){}

	string getType()const override{
		return "ArrayAssignment";
	}
}; 


class StructAssignment: public Expression{
private:
	shared_ptr<StructMember> loperand;
	shared_ptr<Expression> roperand;

public:	
	StructAssignment(){}
	
	StructAssignment(shared_ptr<StructMember> loperand, shared_ptr<Expression> roperand)
		:loperand(loperand), roperand(roperand){}

	string getType()const override{
		return "StructAssignment";
	}		
};

class ArrayIndex: public Expression{
private:
	shared_ptr<Identifier> arrayName;
	shared_ptr<ExpressionList> expressions = make_shared<ExpressionList>();
	
public:
	ArrayIndex(){};
	
	ArrayIndex(shared_ptr<Identifier> arrayName, shared_ptr<ExpressionList> expressions)
		:arrayName(arrayName), expressions(exceptions){}
		
	ArrayIndex(shared_ptr<Identifier> arrayName, shared_ptr<Expression> expression)
		:arrayName(arrayName){
		expressions->push_back(expression);
	}

	string getType()const override{
		return "ArrayIndex";
	}
};

class Literal: public Expression{
private:
	string value;
	
public:
	Literal(){}
	
	Literal(const string &value):value(value){}
	
	string getType()const override{
		return "Literal";
	}
};

class Block: public Statement{
private:
	shared_ptr<StatementList> statements = make_shared<StatementList>();
	
public:
	Block(){}
	
	Block(shared_ptr<StatementList> statements): statements(statements){}
	
	string getType()const override{
		return "Block";
	}
};

class ExpressionStatement: public Statement{
private:
	shared_ptr<Expression> expression;
	
public:
	ExpressionStatement(){}
	
	ExpressionStatement(shared_ptr<Expression>): expression(expression){}
	
	string getType()const override{
		return "ExpressionStatement";
	}
};

class VariableDeclaration: public Statement{
private:
	const shared_ptr<Identifier> type;
	shared_ptr<Identifier> name;
	shared_ptr<Expression> init = NULL;
	
public:
	VariableDeclaration(){}
	
	VariableDeclaration(const shared_ptr<Identifier> type, shared_ptr<Identifier> name, shared_ptr<Expression> init = NULL)
		:type(type), name(name), init(init){}
		
	string getType()const override{
		return "VariableDeclaration";
	}
};

class ArrayInitialization: public Statement{
private:
	shared_ptr<VariableDeclaration> declaration;
	shared_ptr<ExpressionList> expressions = make_shared<ExpressionList>();
	
public:
	ArrayInitialization(){}
	
	ArrayInitialization(shared_ptr<VariableDeclaration> declaration, shared_ptr<ExpressionList> exceptions)
		:declaration(declaration), expressions(expressions){}
		
	string getType()const override{
		return "ArrayInitialization";
	}
};

class FunctionDeclaration: public Statement{
private:
	shared_ptr<Identifier> retType;
	shared_ptr<Identifier> name;
	shared_ptr<VariableDeclarationList> arguments = make_shared<VariableDeclarationList>();
	shared_ptr<Block> block;

public:
	FunctionDeclaration(){}
	
	FunctionDeclaration(shared_ptr<Identifier> retType, shared_ptr<Identifier> name, shared_ptr<VariableDeclarationList> arguments, shared_ptr<Block> block)
		:retType(retType), name(name), arguments(arguments), block(block){}
		
	string getType()const override{
		return "FunctionDeclaration";
	}
};

class StructDeclaration: public Statement{
private:
	shared_ptr<Identifier> name;
	shared_ptr<VariableDeclarationList> members = make_shared<VariableDeclarationList>();

public:
	StructDeclaration();
	
	StructDeclaration(shared_ptr<Identifier> name, shared_ptr<VariableDeclarationList> members)
		:name(name), members(members){}
		
	string getType()const override{
		return "StructDeclaration";
	}
};

class ReturnStatement: public Statement{
private:
	shared_ptr<Expression> expression;
	
public:
	ReturnStatement(){}
	
	ReturnStatement(shared_ptr<Expression> expression):expression(expression){}
	
	string getType()const override{
		return "ReturnStatement";
	}
};

class IfStatement: public Statement{
private:
	shared_ptr<Expression> condition;
	shared_ptr<Block> trueBlock;
	shared_ptr<Block> falseBlock = NULL;
	
public:
	IfStatement(){}
	
	IfStatement(shared_ptr<Expression> condition, shared_ptr<Block> trueBlock, shared_ptr<Block> falseBlock = NULL)
		:condition(condition), trueBlock(trueBlock), falseBlock(falseBlock){}
	
	string getType()const override{
		return "IfStatement";
	}
};

class ForStatement: public Statement{
private:
	shared_ptr<Expression> init = NULL, condition = NULL, increment = NULL;
	shared_ptr<Block> block;
	
public:
	ForStatement(){}
	
	ForStatement(shared_ptr<Expression> init = NULL, shared_ptr<Expression> condition = NULL, shared_ptr<Expression> increment = NULL, shared_ptr<Block> block)
		:init(init), condition(condition), increment(increment), block(block){}
	
	string getType()const override{
		return "ForStatement";
	}
};

class StructMember :public Expression{
private:
	shared_ptr<Identifier> name;
	shared_ptr<Identifier> member;
	
public:
	StructMember(){}
	
	StructMember(shared_ptr<Identifier> name, shared_ptr<Identifier> member)
		:name(name), member(member){}

	string getType()const override{
		return "StructMember";
	}
};

struct WhileStatement: public Statement{
private:
	shared_ptr<Expression> condition;
	shared_ptr<Block> block;
	
public:
	WhileStatement(){}
	WhileStatement(shared_ptr<Expression> condition, shared_ptr<Block> block)
		:condition(condition), block(block){}

	string getType()const override{
		return "WhileStatement";
	}
};
#endif

























