#include "../absyn.h"
#include "../Parser/parser.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

typedef struct arrow_ *arrow;
struct arrow_{
	char buf[100];
	arrow next;
};
arrow head = NULL, tail = NULL;

int nBlock = 0;
int nStm = 0;
int nDouble = 0;
int nConst = 0;
int nInteger = 0;
int nIdentifier = 0;
int nFunctionCall = 0;
int nBinaryOperation = 0;
int nAssignment = 0;
int nArrayIndex = 0;
int nStructMember = 0;
int nStatement = 0;
int nVariableDeclaration = 0;
int nArrayDeclaration = 0;
int nFunctionDeclaration = 0;
int nStructDeclaration = 0;
int nNULL = 0;

string getOpName(int op)
{
	switch(op)
	{
		case MOD_OP:	return string("%");
		case PLUS_OP:	return string("+");
		case MINUS_OP:	return string("-");
		case MUL_OP:	return string("*");
		case DIV_OP:	return string("/");
		case LT_OP:	return string("<");
		case LE_OP:	return string("<=");
		case GT_OP:	return string(">");
		case GE_OP:	return string(">=");
		case EQ_OP:	return string("==");
		case NE_OP:	return string("!=");
		case AND_OP:	return string("&");
		case XOR_OP:	return string("^");
		case OR_OP:	return string("|");
		default:	return string("error");
	}
}

void AddtoList(char *buf)
{
	if(head == NULL)
	{
		head = (arrow)malloc(sizeof(struct arrow_));
		tail = head;
		head->next = NULL;
		strcpy(head->buf, buf);
	}
	else
	{
		arrow p = (arrow)malloc(sizeof(struct arrow_));
		tail->next = p;
		tail = tail->next;
		strcpy(tail->buf, buf);
		tail->next = NULL;
	}
}

string displayChild(FILE* fp, Node* node)
{
	if(node == nullptr)
	{
		char buf[100];
		nNULL++;
		fprintf(fp, "	NULL%d [label = \"NULL\"];\n", nNULL);
		sprintf(buf, "NULL%d",nNULL);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("Double") == 0)
	{
		nDouble++;
		nConst++;

		int mySeq1 = nDouble;
		int mySeq2 = nConst;
		Double* obj = dynamic_cast<Double*>(node);
		fprintf(fp, "	Double%d [label = \"const\"];\n", mySeq1);
		fprintf(fp, "	Const%d [label = \"%lf\"];\n", mySeq2, obj->getValue());

		char buf[100];
		sprintf(buf, "	Double%d -> Const%d;\n", mySeq1, mySeq2);
		AddtoList(buf);

		sprintf(buf, "Double%d", mySeq1);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("Integer") == 0)
	{
		nInteger++;
		nConst++;

		int mySeq1 = nInteger;
		int mySeq2 = nConst;
		Integer* obj = dynamic_cast<Integer*>(node);
		fprintf(fp, "	Integer%d [label = \"const\"];\n", mySeq1);
		fprintf(fp, "	Const%d [label = \"%d\"];\n", mySeq2, obj->getValue());

		char buf[100];
		sprintf(buf, "	Integer%d -> Const%d;\n", mySeq1, mySeq2);
		AddtoList(buf);

		sprintf(buf, "Integer%d", mySeq1);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("Identifier") == 0)
	{
		Identifier* obj = dynamic_cast<Identifier*>(node);
		if(!obj->isType)
		{	
			nIdentifier++;
			nConst++;

			int mySeq1 = nIdentifier;
			int mySeq2 = nConst;
				
			fprintf(fp, "	Identifier%d [label = \"id\"];\n", mySeq1);
			fprintf(fp, "	Const%d [label = \"%s\"];\n", mySeq2, obj->getName().c_str());

			char buf[100];
			sprintf(buf, "	Identifier%d -> Const%d;\n", mySeq1, mySeq2);
			AddtoList(buf);

			sprintf(buf, "Identifier%d", mySeq1);
			string ret(buf);
			return ret;
		}
		else
		{
			nConst++;

			int mySeq = nConst;
				
			fprintf(fp, "	Const%d [label = \"%s\"];\n", mySeq, obj->getName().c_str());

			char buf[100];

			sprintf(buf, "Const%d", mySeq);
			string ret(buf);
			return ret;
		}
	}
	else if(node->getType().compare("FunctionCall") == 0)
	{
		nFunctionCall++;

		int mySeq = nFunctionCall;
		FunctionCall* obj = dynamic_cast<FunctionCall*>(node);
		fprintf(fp, "	FunctionCall%d [label = \"call\"];\n", mySeq);
		
		char buf[100];

		string toIt = displayChild(fp, obj->name.get());
		sprintf(buf, "	FunctionCall%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);

		shared_ptr<ExpressionList> explist = obj->arguments;
		int size;
		if(explist != NULL)
			size = explist->size();
		else
			size = 0;
		for(int i = 0; i < size; i++)
		{
			toIt = displayChild(fp, (*explist)[i].get());
			sprintf(buf, "	FunctionCall%d -> %s;\n", mySeq, toIt.c_str());
			AddtoList(buf);
		}

		sprintf(buf, "FunctionCall%d", mySeq);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("BinaryOperation") == 0)
	{
		nBinaryOperation++;

		int mySeq = nBinaryOperation;
		BinaryOperation* obj = dynamic_cast<BinaryOperation*>(node);
		fprintf(fp, "	BinaryOperation%d [label = \"%s\"];\n", mySeq, getOpName(obj->op).c_str());
		
		char buf[100];

		string toIt = displayChild(fp, obj->loperand.get());
		sprintf(buf, "	BinaryOperation%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->roperand.get());
		sprintf(buf, "	BinaryOperation%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "BinaryOperation%d", mySeq);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("Assignment") == 0)
	{
		nAssignment++;

		int mySeq = nAssignment;
		Assignment* obj = dynamic_cast<Assignment*>(node);
		fprintf(fp, "	Assignment%d [label = \"=\"];\n", mySeq);
		
		char buf[100];

		string toIt = displayChild(fp, obj->loperand.get());
		sprintf(buf, "	Assignment%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->roperand.get());
		sprintf(buf, "	Assignment%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "Assignment%d", mySeq);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("ArrayIndex") == 0)
	{
		nArrayIndex++;

		int mySeq = nArrayIndex;
		ArrayIndex* obj = dynamic_cast<ArrayIndex*>(node);
		fprintf(fp, "	ArrayIndex%d [label = \"arrayindex\"];\n", mySeq);
		
		char buf[100];

		string toIt = displayChild(fp, obj->arrayName.get());
		sprintf(buf, "	ArrayIndex%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);

		shared_ptr<ExpressionList> explist = obj->expressions;
		int size;
		if(explist != NULL)
			size = explist->size();
		else
			size = 0;
		for(int i = 0; i < size; i++)
		{
			toIt = displayChild(fp, (*explist)[i].get());
			sprintf(buf, "	ArrayIndex%d -> %s;\n", mySeq, toIt.c_str());
			AddtoList(buf);
		}

		sprintf(buf, "ArrayIndex%d", mySeq);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("ArrayAssignment") == 0)
	{
		nAssignment++;

		int mySeq = nAssignment;
		ArrayAssignment* obj = dynamic_cast<ArrayAssignment*>(node);
		fprintf(fp, "	Assignment%d [label = \"=\"];\n", mySeq);
		
		char buf[100];

		string toIt = displayChild(fp, obj->loperand.get());
		sprintf(buf, "	Assignment%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->roperand.get());
		sprintf(buf, "	Assignment%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "Assignment%d", mySeq);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("StructMember") == 0)
	{
		nStructMember++;

		int mySeq = nStructMember;
		StructMember* obj = dynamic_cast<StructMember*>(node);
		fprintf(fp, "	StructMember%d [label = \".\"];\n", mySeq);
		
		char buf[100];

		string toIt = displayChild(fp, obj->name.get());
		sprintf(buf, "	StructMember%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->member.get());
		sprintf(buf, "	StructMember%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "StructMember%d", mySeq);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("StructAssignment") == 0)
	{
		nAssignment++;

		int mySeq = nAssignment;
		StructAssignment* obj = dynamic_cast<StructAssignment*>(node);
		fprintf(fp, "	Assignment%d [label = \"=\"];\n", mySeq);
		
		char buf[100];

		string toIt = displayChild(fp, obj->loperand.get());
		sprintf(buf, "	Assignment%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->roperand.get());
		sprintf(buf, "	Assignment%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "Assignment%d", mySeq);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("Literal") == 0)
	{
		nConst++;

		int mySeq = nConst;
		Literal* obj = dynamic_cast<Literal*>(node);
		fprintf(fp, "	Const%d [label = %s];\n", mySeq, obj->value.c_str());
		
		char buf[100];
		
		sprintf(buf, "Const%d", mySeq);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("Block") == 0)
	{
		nBlock++;

		int mySeq = nBlock;
		Block* obj = dynamic_cast<Block*>(node);
		fprintf(fp, "	Block%d [label = \"Block\"];\n", mySeq);
		shared_ptr<StatementList> stmlist = obj->statements;
		int size;
		if(stmlist != NULL)
			size = stmlist->size();
		else
			size = 0;
		char buf[100];
		string toIt;
		for(int i = 0; i < size; i++)
		{
			toIt = displayChild(fp, (*stmlist)[i].get());
			sprintf(buf, "	Block%d -> %s;\n", mySeq, toIt.c_str());
			AddtoList(buf);
		}
		
		sprintf(buf, "Block%d", mySeq);
		string ret(buf);

		return ret;
	}
	else if(node->getType().compare("ExpressionStatement") == 0)
	{
		nStatement++;

		int mySeq = nStatement;
		ExpressionStatement* obj = dynamic_cast<ExpressionStatement*>(node);
		fprintf(fp, "	Statement%d [label = \"Stm\"];\n", mySeq);

		char buf[100];
		string toIt = displayChild(fp, obj->expression.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "Statement%d", mySeq);
		string ret(buf);

		return ret;
	}
	else if(node->getType().compare("VariableDeclaration") == 0)
	{
		nVariableDeclaration++;

		int mySeq = nVariableDeclaration;
		VariableDeclaration* obj = dynamic_cast<VariableDeclaration*>(node);
		fprintf(fp, "	VariableDeclaration%d [label = \"VarDec\"];\n", mySeq);

		char buf[100];
		string toIt = displayChild(fp, obj->type.get());
		sprintf(buf, "	VariableDeclaration%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->name.get());
		sprintf(buf, "	VariableDeclaration%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->init.get());
		sprintf(buf, "	VariableDeclaration%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "VariableDeclaration%d", mySeq);
		string ret(buf);

		return ret;
	}
	else if(node->getType().compare("ArrayDeclaration") == 0)
	{
		nArrayDeclaration++;

		int mySeq = nArrayDeclaration;
		ArrayDeclaration* obj = dynamic_cast<ArrayDeclaration*>(node);
		fprintf(fp, "	ArrayDeclaration%d [label = \"ArrDec\"];\n", mySeq);

		char buf[100];
		string toIt = displayChild(fp, obj->type.get());
		sprintf(buf, "	ArrayDeclaration%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->name.get());
		sprintf(buf, "	ArrayDeclaration%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);

		shared_ptr<ExpressionList> explist1 = obj->arraySize;
		int size;
		if(explist1 != NULL)
			size = explist1->size();
		else
			size = 0;
		for(int i = 0; i < size; i++)
		{
			toIt = displayChild(fp, (*explist1)[i].get());
			sprintf(buf, "	ArrayDeclaration%d -> %s;\n", mySeq, toIt.c_str());			
			AddtoList(buf);
		}
		shared_ptr<ExpressionList> explist2 = obj->inits;
		if(explist2 != NULL)
			size = explist2->size();		
		else
			size = 0;
		for(int i = 0; i < size; i++)
		{
			toIt = displayChild(fp, (*explist2)[i].get());
			sprintf(buf, "	ArrayDeclaration%d -> %s;\n", mySeq, toIt.c_str());
			AddtoList(buf);
		}
		
		sprintf(buf, "ArrayDeclaration%d", mySeq);
		string ret(buf);

		return ret;
	}
	else if(node->getType().compare("FunctionDeclaration") == 0)
	{
		nFunctionDeclaration++;

		int mySeq = nFunctionDeclaration;
		FunctionDeclaration* obj = dynamic_cast<FunctionDeclaration*>(node);
		fprintf(fp, "	FunctionDeclaration%d [label = \"FunDec\"];\n", mySeq);
		
		char buf[100];

		string toIt = displayChild(fp, obj->retType.get());
		sprintf(buf, "	FunctionDeclaration%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->name.get());
		sprintf(buf, "	FunctionDeclaration%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);

		shared_ptr<VariableDeclarationList> declist = obj->arguments;
		int size;
		if(declist != NULL)
			size = declist->size();
		else
			size = 0;
		for(int i = 0; i < size; i++)
		{
			toIt = displayChild(fp, (*declist)[i].get());
			sprintf(buf, "	FunctionDeclaration%d -> %s;\n", mySeq, toIt.c_str());
			AddtoList(buf);
		}

		toIt = displayChild(fp, obj->block.get());
		sprintf(buf, "	FunctionDeclaration%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);

		sprintf(buf, "FunctionDeclaration%d", mySeq);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("StructDeclaration") == 0)
	{
		nStructDeclaration++;

		int mySeq = nStructDeclaration;
		StructDeclaration* obj = dynamic_cast<StructDeclaration*>(node);
		fprintf(fp, "	StructDeclaration%d [label = \"StructDec\"];\n", mySeq);
		
		char buf[100];

		string toIt = displayChild(fp, obj->typeName.get());
		sprintf(buf, "	StructDeclaration%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);

		shared_ptr<VariableDeclarationList> declist = obj->members;
		int size;
		if(declist != NULL)
			size = declist->size();
		else
			size = 0;
		for(int i = 0; i < size; i++)
		{
			toIt = displayChild(fp, (*declist)[i].get());
			sprintf(buf, "	StructDeclaration%d -> %s;\n", mySeq, toIt.c_str());
			AddtoList(buf);
		}

		toIt = displayChild(fp, obj->instName.get());
		sprintf(buf, "	StructDeclaration%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		shared_ptr<ExpressionList> explist = obj->inits;
		if(explist != NULL)
			size = explist->size();
		else
			size = 0;
		for(int i = 0; i < size; i++)
		{
			toIt = displayChild(fp, (*explist)[i].get());
			sprintf(buf, "	StructDeclaration%d -> %s;\n", mySeq, toIt.c_str());
			AddtoList(buf);
		}

		sprintf(buf, "StructDeclaration%d", mySeq);
		string ret(buf);
		return ret;
	}
	else if(node->getType().compare("ReturnStatement") == 0)
	{
		nStatement++;

		int mySeq = nStatement;
		ReturnStatement* obj = dynamic_cast<ReturnStatement*>(node);
		fprintf(fp, "	Statement%d [label = \"Return\"];\n", mySeq);

		char buf[100];
		string toIt = displayChild(fp, obj->expression.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "Statement%d", mySeq);
		string ret(buf);

		return ret;
	}
	else if(node->getType().compare("IfStatement") == 0)
	{
		nStatement++;

		int mySeq = nStatement;
		IfStatement* obj = dynamic_cast<IfStatement*>(node);
		fprintf(fp, "	Statement%d [label = \"If\"];\n", mySeq);

		char buf[100];
		string toIt = displayChild(fp, obj->condition.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->trueBlock.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->falseBlock.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "Statement%d", mySeq);
		string ret(buf);

		return ret;
	}
	else if(node->getType().compare("ForStatement") == 0)
	{
		nStatement++;

		int mySeq = nStatement;
		ForStatement* obj = dynamic_cast<ForStatement*>(node);
		fprintf(fp, "	Statement%d [label = \"For\"];\n", mySeq);

		char buf[100];
		string toIt = displayChild(fp, obj->init.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->condition.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->increment.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->block.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "Statement%d", mySeq);
		string ret(buf);

		return ret;
	}
	else if(node->getType().compare("WhileStatement") == 0)
	{
		nStatement++;

		int mySeq = nStatement;
		WhileStatement* obj = dynamic_cast<WhileStatement*>(node);
		fprintf(fp, "	Statement%d [label = \"While\"];\n", mySeq);

		char buf[100];
		string toIt = displayChild(fp, obj->condition.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		toIt = displayChild(fp, obj->block.get());
		sprintf(buf, "	Statement%d -> %s;\n", mySeq, toIt.c_str());
		AddtoList(buf);
		
		sprintf(buf, "Statement%d", mySeq);
		string ret(buf);

		return ret;
	}
	else
	{
		printf("error!\n");
		return NULL;
	}
}

void treeTraverse(FILE* fp, Block* programBlock)
{
	if(programBlock == NULL)
		return;
	else
	{
		shared_ptr<StatementList> stmlist = programBlock->statements;
		int size;
		if(stmlist != NULL)
			size = stmlist->size();
		else
			size = 0;
		int mySeq;
		nBlock++;
		mySeq = nBlock;

		fprintf(fp, "	Block%d [label = \"Block\"];\n", mySeq);

		for(int i = 0; i < size; i++)
		{
			string toIt = displayChild(fp, (*stmlist)[i].get());
			char buf[100];
			sprintf(buf, "	Block%d -> %s;\n", mySeq, toIt.c_str());
			AddtoList(buf);
		}
	}

	arrow p = head;
	while(p != NULL)
	{
		fprintf(fp, "%s", p->buf);
		p = p->next;
	}

	while(head != NULL)
	{
		p = head;
		head = head->next;
		free(p);
	}
}

void treeDisplay(Block* programBlock)
{
	FILE *fp;
	
	fp = fopen("TreeDisplay/tree.dot", "w");
	
	if(fp == NULL)
	{
		printf("Cannot open file tree.dot\n");
		exit(0);
	}
	fprintf(fp, "digraph absynTree{\n");
	
	treeTraverse(fp, programBlock);

	fprintf(fp, "}");
	
	fclose(fp);
}
