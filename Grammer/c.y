%{
#include <stdio.h>
#include <stdlib.h>

extern FILE* yyin;
extern int yylineno;
void yyerror(char *);
extern int yylex(void);
%}

%union{
	string stringg;
	int token;
}

%token <stringg> IDENTIFIER STRING_LITERAL CONSTANT_INT CONSTANT_DOUBLE UMINUS
%token <token> LE_OP GE_OP EQ_OP NE_OP
%token <token> MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token <token> SUB_ASSIGN AND_ASSIGN
%token <token> XOR_ASSIGN OR_ASSIGN

%token <stringg> CHAR INT FLOAT DOUBLE VOID BOOL
%token <token> STRUCT
%token <token> IF ELSE WHILE DO FOR CONTINUE BREAK RETURN

%start program

%left TPLUS TMINUS
%left TMUL TDIV TMOD
%%


program 
	: statements
	;

statements 
	: statement
	| statements statement
	;
	
statement 
	: var_dec
	| func_dec
	| struct_dec
	| expr
	| RETURN expr
	| if_stmt
	| for_stmt
	| while_stmt
	;

block 
	: '{' statements '}'
	| '{' '}'
	;

primary_typename 
	: INT
	| DOUBLE
	| FLOAT
	| CHAR
	| BOOL
	| VOID

array_typename 
	: primary_typename '[' CONSTANT_INT']'
	| array_typename '[' CONSTANT_INT ']'
	;
	
struct_typename 
	: STRUCT ident

typename 
	: primary_typename
	| array_typename
	| struct_typename

var_dec
	: typename ident
	| typename ident '=' expr
	| typename ident '=' '{' call_args '}'
	;

func_dec
	: typename ident '(' func_dec_args ')' block
	;

func_dec_args 
	: /* blank */
	| var_dec
	| func_dec_args ',' var_dec
	;

ident
	: IDENTIFIER
	;

numeric 
	: CONSTANT_INT
	| CONSTANT_DOUBLE
	;
	
expr 
	: assign
	| ident '(' call_args ')'
	| ident
	| ident '.' ident
	| numeric
	| expr comparison expr
	| expr '%' expr
	| expr '*' expr
	| expr '/' expr
	| expr '+' expr
	| expr '-' expr
	| '(' expr ')'
	| '-' expr
	| array_index
	| STRING_LITERAL
	;

array_index 
	: ident '[' expr ']' 
	| array_index '[' expr '] 
	;
	
assign 
	: ident assign_operator expr
	| array_index assign_operator expr
	| ident '.' ident assign_operator expr
	;
	
assign_operator
	: MUL_ASSIGN
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
	| call_args ',' expr
	;
	
comparison 
	: EQ_OP
	| NE_OP
	| '<'
	| LE_OP 
	| '>'
	| GE_OP
	| '&'
	| '|' 
	| '^' 
	;
	
if_stmt 
	: IF expr block
	| IF expr block ELSE block
	| IF expr block ELSE if_stmt
	;

for_stmt 
	: FOR '(' expr ';' expr ';' expr ')' block
	;
		
while_stmt 
	: WHILE '( expr ')' block
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