%{
#include <stdio.h>
#include <stdlib.h>

extern FILE* yyin;
extern char yytext[];
extern int yylineno;
void yyerror(char *);
int yylex(void);
%}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF CONSTANT_INT CONSTANT_DOUBLE
%token PTR_OP INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF STATIC
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOID
%token BOOL
%token STRUCT UNION ENUM

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
	: IDENTIFIER
	| CONSTANT_INT
	| CONSTANT_DOUBLE
	| STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| '(' type_name ')' '{' initializer_list '}'
	| '(' type_name ')' '{' initializer_list ',' '}'
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	| function_specifier
	| function_specifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| BOOL
	| COMPLEX
	| IMAGINARY
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	;

function_specifier
	: INLINE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;


direct_declarator
	: IDENTIFIER
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Direct_Declarator(yylineno, 1, argv);
	}
	| '(' declarator ')'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '[' type_qualifier_list ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '[' assignment_expression ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '[' type_qualifier_list '*' ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '[' '*' ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '[' ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '(' parameter_type_list ')'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '(' identifier_list ')'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_declarator '(' ')'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

pointer
	: '*'
	{
		$$ = A_Pointer(yylineno, 1, NULL);
	}
	| '*' type_qualifier_list
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Pointer($1->pos, 2, argv);
	}
	| '*' pointer
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Pointer($1->pos, 3, argv);
	}
	| '*' type_qualifier_list pointer
	{
		void *argv[2];
		argv[0] = (void *)$2;
		argv[1] = (void *)$3;
		$$ = A_Pointer($1->pos, 4, argv);
	}
	;

type_qualifier_list
	: type_qualifier
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Type_Qualifier_List($1->pos, 1, argv);
	}
	| type_qualifier_list type_qualifier
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Type_Qualifier_List($1->pos, 2, argv);
	}
	;


parameter_type_list
	: parameter_list
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Parameter_Type_List($1->pos, 1, argv);
	}
	;

parameter_list
	: parameter_declaration
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Parameter_List($1->pos, 1, argv);
	}
	| parameter_list ',' parameter_declaration
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Parameter_List($1->pos, 2, argv);
	}
	;

parameter_declaration
	: declaration_specifiers declarator
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Parameter_Declaration($1->pos, 1, argv);
	}
	| declaration_specifiers abstract_declarator
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Parameter_Declaration($1->pos, 2, argv);
	}
	| declaration_specifiers
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Parameter_Declaration($1->pos, 3, argv);
	}
	;

identifier_list
	: IDENTIFIER
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Identifier_List($1->pos, 1, argv);
	}
	| identifier_list ',' IDENTIFIER
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Identifier_List($1->pos, 2, argv);
	}
	;

type_name
	: specifier_qualifier_list
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Type_Name($1->pos, 1, argv);
	}
	| specifier_qualifier_list abstract_declarator
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Type_Name($1->pos, 2, argv);
	}
	;

abstract_declarator
	: pointer
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Abstract_Declarator($1->pos, 1, argv);
	}
	| direct_abstract_declarator
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Abstract_Declarator($1->pos, 2, argv);
	}
	| pointer direct_abstract_declarator
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Abstract_Declarator($1->pos, 3, argv);
	}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Direct_Abstract_Declarator($2->pos, 1, argv);
	}
	| '[' ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| '[' assignment_expression ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_abstract_declarator '[' ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_abstract_declarator '[' assignment_expression ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| '[' '*' ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_abstract_declarator '[' '*' ']'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| '(' ')'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| '(' parameter_type_list ')'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_abstract_declarator '(' ')'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| direct_abstract_declarator '(' parameter_type_list ')'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

initializer
	: assignment_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Initializer($1->pos, 1, argv);
	}
	| '{' initializer_list '}'
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Initializer($2->pos, 2, argv);
	}
	| '{' initializer_list ',' '}'
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Initializer($2->pos, 3, argv);
	}
	;

initializer_list
	: initializer
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Initializer_List($1->pos, 1, argv);
	}
	| designation initializer
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Initializer_List($1->pos, 2, argv);
	}
	| initializer_list ',' initializer
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Initializer_List($1->pos, 3, argv);
	}
	| initializer_list ',' designation initializer
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Initializer_List($1->pos, 4, argv);
	}
	;

designation
	: designator_list '='
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Designation($1->pos, 1, argv);
	}
	;

designator_list
	: designator
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Designation_List($1->pos, 1, argv);
	}
	| designator_list designator
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Designation_List($1->pos, 2, argv);
	}
	;

designator
	: '[' constant_expression ']'
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Designator($2->pos, 1, argv);
	}
	| '.' IDENTIFIER
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Designator($2->pos, 1, argv);
	}
	;

statement
	: labeled_statement
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Statement($1->pos, 1, argv);
	}
	| compound_statement
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Statement($1->pos, 2, argv);
	}
	| expression_statement
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Statement($1->pos, 3, argv);
	}
	| selection_statement
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Statement($1->pos, 4, argv);
	}
	| iteration_statement
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Statement($1->pos, 5, argv);
	}
	| jump_statement
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Statement($1->pos, 6, argv);
	}
	;

labeled_statement
	: IDENTIFIER ':' statement
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Labeled_Statement($1->pos, 1, argv);
	}
	| CASE constant_expression ':' statement
	{
		void *argv[2];
		argv[0] = (void *)$2;
		argv[1] = (void *)$4;
		$$ = A_Labeled_Statement($2->pos, 2, argv);
	}
	| DEFAULT ':' statement
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Labeled_Statement($1->pos, 3, argv);
	}
	;

compound_statement
	: '{' '}'
	{
		$$ = A_Compound_Statement(yylineno, 1, NULL);
	}
	| '{' block_item_list '}'
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Compound_Statement($2->pos, 2, argv);
	}
	;

block_item_list
	: block_item
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Block_Item_List($1->pos, 1, argv);
	}
	| block_item_list block_item
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Block_Item_List($1->pos, 2, argv);
	}
	;

block_item
	: declaration
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Block_Item($1->pos, 1, argv);
	}
	| statement
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Block_Item($1->pos, 2, argv);
	}
	;

expression_statement
	: ';'
	{
		$$ = A_Expression_Statement(yylineno, 1, NULL);
	}
	| expression ';'
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Expression_Statement($1->pos, 2, argv);
	}
	;

selection_statement
	: IF '(' expression ')' statement
	{
		void *argv[2];
		argv[0] = (void *)$3;
		argv[1] = (void *)$5;
		$$ = A_Selection_Statement($3->pos, 1, argv);
	}
	| IF '(' expression ')' statement ELSE statement
	{
		void *argv[3];
		argv[0] = (void *)$3;
		argv[1] = (void *)$5;
		argv[2] = (void *)$7;
		$$ = A_Selection_Statement($3->pos, 2, argv);
	}
	| SWITCH '(' expression ')' statement
	{
		void *argv[2];
		argv[0] = (void *)$3;
		argv[1] = (void *)$5;
		$$ = A_Selection_Statement($3->pos, 3, argv);
	}
	;

iteration_statement
	: WHILE '(' expression ')' statement
	{
		void *argv[2];
		argv[0] = (void *)$3;
		argv[1] = (void *)$5;
		$$ = A_Iteration_Statement($3->pos, 1, argv);
	}
	| DO statement WHILE '(' expression ')' ';'
	{
		void *argv[2];
		argv[0] = (void *)$2;
		argv[1] = (void *)$5;
		$$ = A_Iteration_Statement($2->pos, 2, argv);
	}
	| FOR '(' expression_statement expression_statement ')' statement
	{
		void *argv[3];
		argv[0] = (void *)$3;
		argv[1] = (void *)$4;
		argv[2] = (void *)$6;
		$$ = A_Iteration_Statement($3->pos, 3, argv);
	}
	| FOR '(' expression_statement expression_statement expression ')' statement
	{
		void *argv[4];
		argv[0] = (void *)$3;
		argv[1] = (void *)$4;
		argv[2] = (void *)$5;
		argv[3] = (void *)$7;
		$$ = A_Iteration_Statement($3->pos, 4, argv);
	}
	| FOR '(' declaration expression_statement ')' statement
	{
		void *argv[3];
		argv[0] = (void *)$3;
		argv[1] = (void *)$4;
		argv[2] = (void *)$6;
		$$ = A_Iteration_Statement($3->pos, 5, argv);
	}
	| FOR '(' declaration expression_statement expression ')' statement
	{
		void *argv[4];
		argv[0] = (void *)$3;
		argv[1] = (void *)$4;
		argv[2] = (void *)$5;
		argv[3] = (void *)$7;
		$$ = A_Iteration_Statement($3->pos, 6, argv);
	}
	;

jump_statement
	: GOTO IDENTIFIER ';'
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Jump_Statement($2->pos, 1, argv);
	}
	| CONTINUE ';'
	{
		$$ = A_Jump_Statement(yylineno, 2, NULL);
	}
	| BREAK ';'
	{
		$$ = A_Jump_Statement(yylineno, 3, NULL);
	}
	| RETURN ';'
	{
		$$ = A_Jump_Statement(yylineno, 4, NULL);
	}
	| RETURN expression ';'
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Jump_Statement($2->pos, 5, argv);
	}
	;

external_declaration
	: function_definition
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_External_Declaration($1->pos, 1, argv);
	}
	| declaration
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_External_Declaration($1->pos, 2, argv);
	}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	{
		void *argv[4];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		argv[2] = (void *)$3;
		argv[3] = (void *)$4;
		$$ = A_Function_Definition($1->pos, 1, argv);
	}
	| declaration_specifiers declarator compound_statement
	{
		void *argv[3];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		argv[2] = (void *)$3;
		$$ = A_Function_Definition($1->pos, 2, argv);
	}
	;

declaration_list
	: declaration
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Declaration_List($1->pos, 1, argv);
	}
	| declaration_list declaration
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Declaration_List($1->pos, 2, argv);
	}
	;

translation_unit
	: external_declaration
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Translation_Unit($1->pos, 1, argv);
	}
	| translation_unit external_declaration
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Translation_Unit($1->pos, 2, argv);
	}
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