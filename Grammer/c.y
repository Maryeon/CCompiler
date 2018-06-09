%{
#include <stdio.h>
#include <stdlib.h>

Block *programBlock;
extern FILE* yyin;
extern int yylineno;
void yyerror(char *);
extern int yylex(void);
%}

%union{
	string *stringg;
	int token;
	
	Block *block;
	Expression *expression;
	Statement *statement;
	Identifier *identifier;
	VariableDeclaration *variabledeclaration;
	ArrayIndex *arrayindex;
	std::vector<shared_ptr<VariableDeclaration>>* variabledeclarationlist;
	std::vector<shared_ptr<Expression>>* expressionlist;
}

%token <stringg> IDENTIFIER STRING_LITERAL CONSTANT_INT CONSTANT_DOUBLE UMINUS
%token <token> LE_OP GE_OP EQ_OP NE_OP
%token <token> MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token <token> SUB_ASSIGN AND_ASSIGN
%token <token> XOR_ASSIGN OR_ASSIGN
%token <token> SEMICOLON LBRACE RBRACE COMMA EQUAL RPAREN LPAREN LBRACKET RBRACKET
%token <token> DOT AND_OP MINUS_OP PLUS_OP MUL_OP DIV_OP MOD_OP LT_OP GT_OP XOR_OP OR_OP

%token <stringg> CHAR INT FLOAT DOUBLE VOID BOOL
%token <token> STRUCT
%token <token> IF ELSE WHILE DO FOR CONTINUE BREAK RETURN

%type <arrayindex> array_index
%type <identifier> ident, primary_typename array_typename struct_typename typename
%type <expression> numeric expr assign
%type <variabledeclarationlist> func_dec_args struct_members
%type <expressionlist> call_args
%type <block> program statements block
%type <statement> statement var_dec func_dec struct_dec if_stmt for_stmt while_stmt
%type <token> comparison

%start program

%left PLUS_OP MINUS_OP
%left MUL_OP DIV_OP MOD_OP
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

primary_typename 
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
	
array_typename 
	: primary_typename LBRACKET CONSTANT_INT RBRACKET
	{
		$1->isArray = true;
		$1->arraySize->push_back(make_shared<Interger>(atol($3->c_str())));
		$$ = $1;
	}
	| array_typename LBRACKET CONSTANT_INT RBRACKET
	{
		$1->arraySize = ->push_back(make_shared<Interger>(atol($3->c_str())));
		$$ = $1;
	}
	;
	
struct_typename 
	: STRUCT ident
	{
		$2->isType = true;
		$$ = $2;
	}
	;
	
typename 
	: primary_typename
	{
		$$ = $1;
	}
	| array_typename
	{
		$$ = $1;
	}
	| struct_typename
	{
		$$ = $1;
	}
	;
	
var_dec
	: typename ident
	{
		$$ = new VariableDeclaration(shared_ptr<Identifier>($1), shared_ptr<Identifier>($2), NULL);
	}
	| typename ident EQUAL expr
	{
		$$ = new VariableDeclaration(shared_ptr<Identifier>($1), shared_ptr<Identifier>($2), shared_ptr<Expression>($4));
	}
	| typename ident EQUAL LBRACE call_args RBRACE
	{
		$$ = new ArrayInitialization(make_shared<VariableDeclaration>(shared_ptr<Identifier>($1), shared_ptr<Identifier>($2), NULL), shared_ptr<ExpressionList>($5));
	}
	;

func_dec
	: typename ident LPAREN func_dec_args RPAREN block
	{
		$$ = new FunctionDeclaration(shared_ptr<Identifier>($1), shared_ptr<Identifier>($2), shared_ptr<VariableDeclarationList>($4), shared_ptr<Block>($6));
	}
	;

func_dec_args 
	: /* blank */
	{
		$$ = new VariableDeclarationList();
	}
	| var_dec
	{
		$$ = new VariableDeclarationList();
		$$->push_back(shared_ptr<VariableDeclaration>($1));
	}
	| func_dec_args COMMA var_dec
	{
		$1->push_back(shared_ptr<VariableDeclaration>($3));
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
		$$ = new Interger(atol($1->c_str()));
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
		$$ = new FuntionCall(shared_ptr<Identifier>($1), shared_ptr<ExpressionList>($3));
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
	| expr comparison expr
	{
		$$ = new BinaryOperation(shared_ptr<Expression>($1), $2, shared_ptr<Expression>($3));
	}
	| expr MOD_OP expr
	{
		$$ = new BinaryOperation(shared_ptr<Expression>($1), $2, shared_ptr<Expression>($3));
	}
	| expr MUL_OP expr
	{
		$$ = new BinaryOperation(shared_ptr<Expression>($1), $2, shared_ptr<Expression>($3));
	}
	| expr DIV_OP expr
	{
		$$ = new BinaryOperation(shared_ptr<Expression>($1), $2, shared_ptr<Expression>($3));
	}
	| expr PLUS_OP expr
	{
		$$ = new BinaryOperation(shared_ptr<Expression>($1), $2, shared_ptr<Expression>($3));
	}
	| expr MINUS_OP expr
	{
		$$ = new BinaryOperation(shared_ptr<Expression>($1), $2, shared_ptr<Expression>($3));
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
	: ident assign_operator expr
	{
		$$ = new Assignment($2, shared_ptr<Identifier>($1), shared_ptr<Expression>($3));
	}
	| array_index assign_operator expr
	{
		
	}
	| ident DOT ident assign_operator expr
	;
	
assign_operator
	: EQUAL
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN 
	| OR_ASSIGN
	;

call_args 
	: /* blank */
	| expr
	| call_args COMMA expr
	;
	
comparison 
	: EQ_OP
	| NE_OP
	| LT_OP
	| LE_OP 
	| GT_OP
	| GE_OP
	| AND_OP
	| OR_OP 
	| XOR_OP 
	;
	
if_stmt 
	: IF expr block
	| IF expr block ELSE block
	| IF expr block ELSE if_stmt
	;

for_stmt 
	: FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN block
	;
		
while_stmt 
	: WHILE '( expr RPAREN block
	;

struct_dec
	: STRUCT ident { struct_members }
	;

struct_members 
	: /* blank */
	| var_dec
	| struct_members var_dec
	;

%%
void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main(int avgs, char *argv[])
{
	yyin = fopen(argv[1], "r");
	if(!yyin)
	{
		printf("Cannot Open the File!\n");
		exit(0);
	}
	yyparse();
	return 0;
}