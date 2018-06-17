%{
	#include "../absyn.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <iostream>
	

	Block *programBlock;
	extern int yylineno;
	extern void yyerror(const char *);
	int yylex(void);
%}
%union{
	std::string *stringg;
	int token;
	
	Block *block;
	Expression *expression;
	Statement *statement;
	Identifier *identifier;
	VariableDeclaration *variabledeclaration;
	ArrayDeclaration *arraydeclaration;
	ArrayIndex *arrayindex;
	std::vector<shared_ptr<VariableDeclaration>>* variabledeclarationlist;
	std::vector<shared_ptr<Expression>>* expressionlist;
}

%token <stringg> IDENTIFIER STRING_LITERAL CONSTANT_INT CONSTANT_DOUBLE UMINUS 
%token <token> LE_OP GE_OP EQ_OP NE_OP LT_OP GT_OP
%token <token> SEMICOLON LBRACE RBRACE COMMA EQUAL RPAREN LPAREN LBRACKET RBRACKET
%token <token> DOT AND_OP MINUS_OP PLUS_OP MUL_OP DIV_OP MOD_OP XOR_OP OR_OP

%token <stringg> CHAR INT FLOAT DOUBLE VOID BOOL EXTERN
%token <token> STRUCT
%token <token> IF ELSE WHILE FOR RETURN

%type <arrayindex> array_index
%type <identifier> ident primary_type
%type <expression> numeric expr assign
%type <variabledeclarationlist> func_dec_args struct_members
%type <arraydeclaration> array_dec array_initialization
%type <expressionlist> call_args
%type <block> program statements block
%type <statement> statement var_dec func_dec struct_dec if_stmt for_stmt while_stmt

%start program

%right EQUAL
%left OR_OP
%left XOR_OP
%left AND_OP
%left EQ_OP NE_OP
%left LT_OP LE_OP GT_OP GE_OP
%left PLUS_OP MINUS_OP
%left MUL_OP DIV_OP MOD_OP
%left UMINUS
%left DOT
%%


program 
	: statements
	{
		programBlock = $1;
	}
	;

statements 
	: statement
	{
		$$ = new Block();
		$$->statements->push_back(shared_ptr<Statement>($1));
	}
	| statements statement
	{
		$1->statements->push_back(shared_ptr<Statement>($2));
		$$ = $1;
	}
	;
	
statement 
	: var_dec SEMICOLON
	{
		$$ = $1;
	}
	| func_dec 
	{
		$$ = $1;
	}
	| array_dec SEMICOLON
	{
		$$ = $1;
	}
	| array_initialization SEMICOLON
	{
		$$ = $1;
	}
	| struct_dec SEMICOLON
	{
		$$ = $1;
	}
	| expr SEMICOLON
	{
		$$ = new ExpressionStatement(shared_ptr<Expression>($1));
	}
	| RETURN expr SEMICOLON
	{
		$$ = new ReturnStatement(shared_ptr<Expression>($2));
	}
	| if_stmt
	{
		$$ = $1;
	}
	| for_stmt
	{
		$$ = $1;
	}
	| while_stmt
	{
		$$ = $1;
	}
	;

block 
	: LBRACE statements RBRACE
	{
		$$ = $2;
	}
	| LBRACE RBRACE
	{
		$$ = new Block();
	}
	;

primary_type
	: INT
	{	
		$$ = new Identifier(*$1);
		$$->isType = true;
		delete $1;
	}
	| DOUBLE
	{
		$$ = new Identifier(*$1);
		$$->isType = true;
		delete $1;
	}
	| FLOAT
	{
		$$ = new Identifier(*$1);
		$$->isType = true;
		delete $1;
	}
	| CHAR
	{
		$$ = new Identifier(*$1);
		$$->isType = true;
		delete $1;
	}
	| BOOL
	{
		$$ = new Identifier(*$1);
		$$->isType = true;
		delete $1;
	}
	| VOID
	{
		$$ = new Identifier(*$1);
		$$->isType = true;
		delete $1;
	}
	;
	
array_dec
	: primary_type ident LBRACKET CONSTANT_INT RBRACKET
	{
		$$ = new ArrayDeclaration(shared_ptr<Identifier>($1), shared_ptr<Identifier>($2));
		$$->arraySize->push_back(make_shared<Integer>(atoi($4->c_str())));
	}
	| array_dec LBRACKET CONSTANT_INT RBRACKET
	{
		$1->arraySize->push_back(make_shared<Integer>(atoi($3->c_str())));
		$$ = $1;
	}
	;

array_initialization
	:
	array_dec EQUAL LBRACE call_args RBRACE
	{
		$1->inits = shared_ptr<ExpressionList>($4);
		$$ = $1;
	}
	;
	
var_dec
	: primary_type ident
	{
		$$ = new VariableDeclaration(shared_ptr<Identifier>($1), shared_ptr<Identifier>($2), NULL);
	}
	| primary_type ident EQUAL expr
	{
		$$ = new VariableDeclaration(shared_ptr<Identifier>($1), shared_ptr<Identifier>($2), shared_ptr<Expression>($4));
	}
	;

func_dec
	: primary_type ident LPAREN func_dec_args RPAREN block
	{
		$$ = new FunctionDeclaration(shared_ptr<Identifier>($1), shared_ptr<Identifier>($2), shared_ptr<VariableDeclarationList>($4), shared_ptr<Block>($6));
	}
	| EXTERN primary_type ident LPAREN func_dec_args RPAREN SEMICOLON
	{
		$$ = new FunctionDeclaration(shared_ptr<Identifier>($2), shared_ptr<Identifier>($3), shared_ptr<VariableDeclarationList>($5), nullptr, true);
	}
	;

func_dec_args 
	:
	{
		$$ = new VariableDeclarationList();
	}
	| var_dec
	{
		$$ = new VariableDeclarationList();
		$$->push_back(shared_ptr<VariableDeclaration>($<variabledeclaration>1));
	}
	| func_dec_args COMMA var_dec
	{
		$1->push_back(shared_ptr<VariableDeclaration>($<variabledeclaration>3));
		$$ = $1;
	}
	;

ident
	: IDENTIFIER
	{
		$$ = new Identifier(*$1);
		delete $1;
	}
	;

numeric 
	: CONSTANT_INT
	{
		$$ = new Integer(atoi($1->c_str()));
	}
	| CONSTANT_DOUBLE
	{
		$$ = new Double(atof($1->c_str()));
	}
	;
	
expr 
	: assign
	{
		$$ = $1;
	}
	| ident LPAREN call_args RPAREN
	{
		$$ = new FunctionCall(shared_ptr<Identifier>($1), shared_ptr<ExpressionList>($3));
	}
	| ident
	{
		$$ = $1;
	}
	| ident DOT ident
	{
		$$ = new StructMember(shared_ptr<Identifier>($1), shared_ptr<Identifier>($3));
	}
	| numeric
	{
		$$ = $1;
	}
	| expr MOD_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr PLUS_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr MINUS_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr MUL_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr DIV_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr LT_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr LE_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr GT_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr GE_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr EQ_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr NE_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr AND_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr XOR_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| expr OR_OP expr
	{
		$$ = new BinaryOperation($2, shared_ptr<Expression>($1), shared_ptr<Expression>($3));
	}
	| LPAREN expr RPAREN
	{
		$$ = $2;
	}
	| MINUS_OP expr	%prec UMINUS
	{
		$$ = NULL;
	}
	| array_index
	{
		$$ = $1;
	}
	| STRING_LITERAL
	{
		$$ = new Literal(*$1); 
		delete $1;
	}
	;

array_index 
	: ident LBRACKET expr RBRACKET
	{
		$$ = new ArrayIndex(shared_ptr<Identifier>($1), shared_ptr<Expression>($3));
	}	
	| array_index LBRACKET expr RBRACKET 
	{
		$1->expressions->push_back(shared_ptr<Expression>($3));
		$$ = $1;
	}
	;
	
assign 
	: ident EQUAL expr
	{
		$$ = new Assignment(shared_ptr<Identifier>($1), shared_ptr<Expression>($3));
	}
	| array_index EQUAL expr
	{
		$$ = new ArrayAssignment(shared_ptr<ArrayIndex>($1), shared_ptr<Expression>($3));
	}
	| ident DOT ident EQUAL expr
	{
		shared_ptr<StructMember>member = make_shared<StructMember>(shared_ptr<Identifier>($1), shared_ptr<Identifier>($3));
		$$ = new StructAssignment(member, shared_ptr<Expression>($5));
	}
	;

call_args 
	: /* blank */
	{
		$$ = new ExpressionList();
	}
	| expr
	{
		$$ = new ExpressionList();
		$$->push_back(shared_ptr<Expression>($1));
	}
	| call_args COMMA expr
	{
		$1->push_back(shared_ptr<Expression>($3));
		$$ = $1;
	}
	;
	
	
if_stmt 
	: IF expr block
	{
		$$ = new IfStatement(shared_ptr<Expression>($2), shared_ptr<Block>($3));
	}
	| IF expr block ELSE block
	{
		$$ = new IfStatement(shared_ptr<Expression>($2), shared_ptr<Block>($3), shared_ptr<Block>($5));
	}
	| IF expr block ELSE if_stmt
	{
		Block *block = new Block();
		block->statements->push_back(shared_ptr<Statement>($5));
		$$ = new IfStatement(shared_ptr<Expression>($2), shared_ptr<Block>($3), shared_ptr<Block>(block));
	}
	;

for_stmt 
	: FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN block
	{
		$$ = new ForStatement(shared_ptr<Block>($9), shared_ptr<Expression>($3), shared_ptr<Expression>($5), shared_ptr<Expression>($7));
	}
	;
		
while_stmt 
	: WHILE LPAREN expr RPAREN block
	{
		$$ = new WhileStatement(shared_ptr<Expression>($3), shared_ptr<Block>($5));
	}
	;

struct_dec
	: STRUCT ident LBRACE struct_members RBRACE
	{
		$$ = new StructDeclaration(shared_ptr<Identifier>($2), shared_ptr<VariableDeclarationList>($4));
	}
	| STRUCT ident LBRACE struct_members RBRACE ident
	{
		$$ = new StructDeclaration(shared_ptr<Identifier>($2), shared_ptr<VariableDeclarationList>($4), shared_ptr<Identifier>($6));
	}
	| STRUCT ident LBRACE struct_members RBRACE ident EQUAL LBRACE call_args RBRACE
	{
		$$ = new StructDeclaration(shared_ptr<Identifier>($2), shared_ptr<VariableDeclarationList>($4), shared_ptr<Identifier>($6), shared_ptr<ExpressionList>($9));
	}
	;

struct_members 
	: /* blank */
	{
		$$ = new VariableDeclarationList();
	}
	| var_dec SEMICOLON
	{
		$$ = new VariableDeclarationList();
		$$->push_back(shared_ptr<VariableDeclaration>($<variabledeclaration>1));
	}
	| struct_members var_dec SEMICOLON
	{
		$1->push_back(shared_ptr<VariableDeclaration>($<variabledeclaration>2));
		$$ = $1;
	}
	;

%%
void yyerror(const char * errormsg)
{
	fprintf(stderr, "%s\n", errormsg);
}
