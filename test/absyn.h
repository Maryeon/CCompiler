#ifndef ABSYN_H
#define ABSYN_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;





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

typedef std::vector<shared_ptr<Expression>> ExpressionList;

class Statement: public Node{
public:
	Statement(){}
	
	string getType()const override{
		return "Statement";
	}
};

typedef std::vector<shared_ptr<Statement>> StatementList;

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
	
};

class Interger: public Expression{
public:	
	int value;
	
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
public:
	string name;
	bool isType = false;
	bool isArray = false;
	
	shared_ptr<ExpressionList> arraySize = make_shared<ExpressionList>();
	
	Identifier(){}
	
	Identifier(const string &name):name(name){}
		
	string getType()const override{
		return "Identifier";
	}
	
	string getName()const{
		return name;
	}
	
};

class FunctionCall: public Expression{
public:
	const shared_ptr<Identifier> name;
	shared_ptr<ExpressionList> arguments = make_shared<ExpressionList>();

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
public:
	int op;
	shared_ptr<Expression> loperand;
	shared_ptr<Expression> roperand;
	
	BinaryOperation(){};
	
	BinaryOperation(int op, shared_ptr<Expression> loperand, shared_ptr<Expression> roperand)
		:op(op), loperand(loperand), roperand(roperand){}
		
	string getType()const override{
		return "BinaryOperation";
	}
};

class Assignment: public Expression{
public:	
	int op;
	shared_ptr<Identifier> loperand;
	shared_ptr<Expression> roperand;

	Assignment(){}
	
	Assignment(int op, shared_ptr<Identifier> loperand, shared_ptr<Expression> roperand)
		:op(op), loperand(loperand), roperand(roperand){}
		
	string getType()const override{
		return "Assignment";
	}
};

class ArrayIndex : public Expression {
public:
	shared_ptr<Identifier> arrayName;
	shared_ptr<ExpressionList> expressions = make_shared<ExpressionList>();

	ArrayIndex() {};

	ArrayIndex(shared_ptr<Identifier> arrayName, shared_ptr<ExpressionList> expressions)
		:arrayName(arrayName), expressions(expressions) {}

	ArrayIndex(shared_ptr<Identifier> arrayName, shared_ptr<Expression> expression)
		:arrayName(arrayName) {
		expressions->push_back(expression);
	}

	string getType()const override {
		return "ArrayIndex";
	}
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
}; 

class StructMember :public Expression {
public:
	shared_ptr<Identifier> name;
	shared_ptr<Identifier> member;

	StructMember() {}

	StructMember(shared_ptr<Identifier> name, shared_ptr<Identifier> member)
		:name(name), member(member) {}

	string getType()const override {
		return "StructMember";
	}


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
};



class Literal: public Expression{
public:	
	string value;

	Literal(){}
	
	Literal(const string &value):value(value){}
	
	string getType()const override{
		return "Literal";
	}
};

class Block: public Statement{
public:
	shared_ptr<StatementList> statements = make_shared<StatementList>();
	
	Block(){}
	
	Block(shared_ptr<StatementList> statements): statements(statements){}
	
	string getType()const override{
		return "Block";
	}
};

class ExpressionStatement: public Statement{
public:
	shared_ptr<Expression> expression;
	
	ExpressionStatement(){}
	
	ExpressionStatement(shared_ptr<Expression>): expression(expression){}
	
	string getType()const override{
		return "ExpressionStatement";
	}
};

class VariableDeclaration: public Statement{
public:
	const shared_ptr<Identifier> type;
	shared_ptr<Identifier> name;
	shared_ptr<Expression> init = NULL;
	
	VariableDeclaration(){}
	
	VariableDeclaration(const shared_ptr<Identifier> type, shared_ptr<Identifier> name, shared_ptr<Expression> init = NULL)
		:type(type), name(name), init(init){}
		
	string getType()const override{
		return "VariableDeclaration";
	}
};
typedef std::vector<shared_ptr<VariableDeclaration>> VariableDeclarationList;

class ArrayInitialization: public Statement{
public:
	shared_ptr<VariableDeclaration> declaration;
	shared_ptr<ExpressionList> expressions = make_shared<ExpressionList>();
	
	ArrayInitialization(){}
	
	ArrayInitialization(shared_ptr<VariableDeclaration> declaration, shared_ptr<ExpressionList> exceptions)
		:declaration(declaration), expressions(expressions){}
		
	string getType()const override{
		return "ArrayInitialization";
	}
	
	

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
	
	
};

class StructDeclaration: public Statement{
public:
	shared_ptr<Identifier> name;
	shared_ptr<VariableDeclarationList> members = make_shared<VariableDeclarationList>();

	StructDeclaration();
	
	StructDeclaration(shared_ptr<Identifier> name, shared_ptr<VariableDeclarationList> members)
		:name(name), members(members){}
		
	string getType()const override{
		return "StructDeclaration";
	}
	
	
};

class ReturnStatement: public Statement{
public:
	shared_ptr<Expression> expression;
	
	ReturnStatement(){}
	
	ReturnStatement(shared_ptr<Expression> expression):expression(expression){}
	
	string getType()const override{
		return "ReturnStatement";
	}
	
	
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
	
	
};

#endif

























