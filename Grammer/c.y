%{
#include <stdio.h>
#include <stdlib.h>

extern FILE* yyin;
extern char yytext[];
extern int yylineno;
void yyerror(char *);
int yylex(void);
%}

%union{
	S_symbol symbol;
	int intt;
	double doublee;
	string stringg;
	A_translation_unit _A_translation_unit;
	A_external_declaration _A_external_declaration;
	A_direct_declarator _A_direct_declarator;
	A_primary_expression _A_primary_expression;
	A_argument_expression_list _A_argument_expression_list;
	A_unary_expression _A_unary_expression;
	A_unary_operator _A_unary_operator;
	A_cast_expression _A_cast_expression;
	A_multiplicative_expression _A_multiplicative_expression;
	A_additive_expression _A_additive_expression;
	A_shift_expression _A_shift_expression;
	A_relational_expression _A_relational_expression;
	A_equality_expression _A_equality_expression;
	A_and_expression _A_and_expression;
	A_exclusive_or_expression _A_exclusive_or_expression;
	A_inclusive_or_expression _A_inclusive_or_expression;
	A_logical_and_expression _A_logical_and_expression;
	A_logical_or_expression _A_logical_or_expression;
	A_conditional_expression _A_conditional_expression;
	A_assignment_expression _A_assignment_expression;
	A_assignment_operator _A_assignment_operator;
	A_pointer _A_pointer;
	A_type_qualifier _A_type_qualifier;
	A_type_qualifier_list _A_type_qualifier_list;
	A_parameter_type_list _A_parameter_type_list;
	A_parameter_list _A_parameter_list;
	A_parameter_declaration _A_parameter_declaration;
	A_identifier_list _A_identifier_list;
	A_type_name _A_type_name;
	A_abstract_declarator _A_abstract_declarator;
	A_direct_abstract_declarator _A_direct_abstract_declarator;
	A_initializer _A_initializer;
	A_initializer_list _A_initializer_list;
	A_designation _A_designation;
	A_designator_list _A_designator_list;
	A_designator _A_designator;
	A_statement _A_statement;
	A_labeled_statement _A_labeled_statement;
	A_compound_statement _A_compound_statement;
	A_block_item_list _A_block_item_list;
	A_block_item _A_block_item;
	A_expression_statement _A_expression_statement;
	A_selection_statement _A_selection_statement;
	A_iteration_statement _A_iteration_statement;
	A_jump_statement _A_jump_statement;
	A_function_definition _A_function_definition;
	A_declaration_list _A_declaration_list;
	A_declaration _A_declaration;
	A_declaration_specifiers _A_declaration_specifiers;
	A_init_declarator_list _A_init_declarator_list;
	A_init_declarator _A_init_declarator;
	A_type_specifier _A_type_specifier;
	A_specifier_qualifier_list _A_specifier_qualifier_list;
	A_declarator _A_declarator;
	A_expression _A_expression;
	A_constant_expression _A_constant_expression;
}

%token <symbol> IDENTIFIER 
%token <stringg> STRING_LITERAL 
%token SIZEOF 
%token <intt> CONSTANT_INT 
%token <doublee> CONSTANT_DOUBLE
%token PTR_OP INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF STATIC
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOID
%token BOOL
%token STRUCT UNION ENUM

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%type <_A_translation_unit> translation_unit
%type <_A_external_declaration> external_declaration
%type <_A_direct_declarator> direct_declarator
%type <_A_primary_expression> primary_expression
%type <_A_argument_expression_list> argument_expression_list
%type <_A_unary_expression> unary_expression
%type <_A_unary_operator> unary_operator
%type <_A_cast_expression> cast_expression
%type <_A_multiplicative_expression> multiplicative_expression
%type <_A_additive_expression> additive_expression
%type <_A_shift_expression> shift_expression
%type <_A_relational_expression> relational_expression
%type <_A_equality_expression> equality_expression
%type <_A_and_expression> and_expression
%type <_A_exclusive_or_expression> exclusive_or_expression
%type <_A_inclusive_or_expression> inclusive_or_expression
%type <_A_logical_and_expression> logical_and_expression
%type <_A_logical_or_expression> logical_or_expression
%type <_A_conditional_expression> conditional_expression
%type <_A_assignment_expression> assignment_expression
%type <_A_assignment_operator> assignment_operator
%type <_A_pointer> pointer
%type <_A_type_qualifier> type_qualifier
%type <_A_type_qualifier_list> type_qualifier_list
%type <_A_parameter_type_list> parameter_type_list
%type <_A_parameter_list> parameter_type_list
%type <_A_parameter_declaration> parameter_declaration
%type <_A_identifier_list> identifier_list
%type <_A_type_name> type_name
%type <_A_abstract_declarator> abstract_declarator
%type <_A_direct_abstract_declarator> direct_abstract_declarator
%type <_A_initializer> initializer
%type <_A_initializer_list> initializer_list
%type <_A_designation> designation
%type <_A_designator_list> designator_list
%type <_A_designator> designator
%type <_A_statement> statement
%type <_A_labeled_statement> labeled_statement
%type <_A_compound_statement> compound_statement
%type <_A_block_item_list> block_item_list
%type <_A_block_item> block_item
%type <_A_expression_statement> expression_statement
%type <_A_selection_statement> selection_statement
%type <_A_iteration_statement> iteration_statement
%type <_A_jump_statement> jump_statement
%type <_A_function_definition> function_definition
%type <_A_declaration_list> declaration_list
%type <_A_declaration> declaration
%type <_A_declaration_specifiers> declaration_specifiers
%type <_A_init_declarator_list> init_declarator_list
%type <_A_init_declarator> init_declarator
%type <_A_type_specifier> type_qualifier
%type <_A_specifier_qualifier_list> specifier_qualifier_list
%type <_A_declarator> declarator
%type <_A_expression> expression
%type <_A_constant_expression> constant_expression

%start translation_unit
%%


primary_expression
	: IDENTIFIER
	{
		$$ = A_identifier(yylineno, $1);
	}
	| CONSTANT_INT
	{
		$$ = A_constant_int(yylineno, $1);
	}
	| CONSTANT_DOUBLE
	{
		$$ = A_constant_double(yylineno, $1);
	}
	| STRING_LITERAL
	{
		$$ = A_string_literal(yylineno, $1);
	}
	| '(' expression ')'
	{	
		$$ = A_lp_expression_rp($2->pos, $2);
	}
	;


postfix_expression
	: primary_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Postfix_Expression($1->pos, 1, argv);
	}
	| postfix_expression '[' expression ']'
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Postfix_Expression($1->pos, 2, argv);
	}
	| postfix_expression '(' ')'
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Postfix_Expression($1->pos, 3, argv);
	}
	| postfix_expression '(' argument_expression_list ')'
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Postfix_Expression($1->pos, 4, argv);
	}
	| postfix_expression '.' IDENTIFIER
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Postfix_Expression($1->pos, 5, argv);
	}
	| postfix_expression PTR_OP IDENTIFIER
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| postfix_expression INC_OP
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Postfix_Expression($1->pos, 6, argv);
	}
	| postfix_expression DEC_OP
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Postfix_Expression($1->pos, 7, argv);
	}
	| '(' type_name ')' '{' initializer_list '}'
	{
		void *argv[2];
		argv[0] = (void *)$2;
		argv[1] = (void *)$5;
		$$ = A_Postfix_Expression($2->pos, 8, argv);
	}
	| '(' type_name ')' '{' initializer_list ',' '}'
	{
		void *argv[2];
		argv[0] = (void *)$2;
		argv[1] = (void *)$5;
		$$ = A_Postfix_Expression($2->pos, 9, argv);
	}
	;

argument_expression_list
	: assignment_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Argument_Expression_List($1->pos, 1, argv);
	}
	| argument_expression_list ',' assignment_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Argument_Expression_List($1->pos, 2, argv);
	}
	;

unary_expression
	: postfix_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Unary_Expression($1->pos, 1, argv);
	}
	| INC_OP unary_expression
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Unary_Expression($2->pos, 2, argv);
	}
	| DEC_OP unary_expression
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Unary_Expression($2->pos, 3, argv);
	}
	| unary_operator cast_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Unary_Expression($1->pos, 4, argv);
	}
	| SIZEOF unary_expression
	{
		void *argv[1];
		argv[0] = (void *)$2;
		$$ = A_Unary_Expression($2->pos, 5, argv);
	}
	| SIZEOF '(' type_name ')'
	{
		void *argv[1];
		argv[0] = (void *)$3;
		$$ = A_Unary_Expression($3->pos, 6, argv);
	}
	;


unary_operator
	: '&'
	{
		$$ = A_Unary_Expression(yylineno, 1, NULL);
	}
	| '*'
	{
		$$ = A_Unary_Expression(yylineno, 2, NULL);
	}
	| '+'
	{
		$$ = A_Unary_Expression(yylineno, 3, NULL);
	}
	| '-'
	{
		$$ = A_Unary_Expression(yylineno, 4, NULL);
	}
	| '~'
	{
		$$ = A_Unary_Expression(yylineno, 5, NULL);
	}
	| '!'
	{
		$$ = A_Unary_Expression(yylineno, 6, NULL);
	}
	;


cast_expression
	: unary_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Cast_Expression($1->pos, 1, argv);
	}
	| '(' type_name ')' cast_expression
	{
		void *argv[2];
		argv[0] = (void *)$2;
		argv[1] = (void *)$4;
		$$ = A_Cast_Expression($2->pos, 2, argv);
	}
	;


multiplicative_expression
	: cast_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Multiplicative_Expression($1->pos, 1, argv);
	}
	| multiplicative_expression '*' cast_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Multiplicative_Expression($1->pos, 2, argv);
	}
	| multiplicative_expression '/' cast_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Multiplicative_Expression($1->pos, 3, argv);
	}
	| multiplicative_expression '%' cast_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Multiplicative_Expression($1->pos, 4, argv);
	}
	;

additive_expression
	: multiplicative_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Additive_Expression($1->pos, 1, argv);
	}
	| additive_expression '+' multiplicative_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Additive_Expression($1->pos, 2, argv);
	}
	| additive_expression '-' multiplicative_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Additive_Expression($1->pos, 3, argv);
	}
	;
shift_expression
	: additive_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Additive_Expression($1->pos, 1, argv);
	}
	;



relational_expression
	: shift_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Relational_Expression($1->pos, 1, argv);
	}
	| relational_expression '<' shift_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Relational_Expression($1->pos, 2, argv);
	}
	| relational_expression '>' shift_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Relational_Expression($1->pos, 3, argv);
	}
	| relational_expression LE_OP shift_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Relational_Expression($1->pos, 4, argv);
	}
	| relational_expression GE_OP shift_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Relational_Expression($1->pos, 5, argv);
	}
	;


equality_expression
	: relational_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Equality_Expression($1->pos, 1, argv);
	}
	| equality_expression EQ_OP relational_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Equality_Expression($1->pos, 2, argv);
	}
	| equality_expression NE_OP relational_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Equality_Expression($1->pos, 3, argv);
	}
	;



	
and_expression
	: equality_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_And_Expression($1->pos, 1, argv);
	}
	| and_expression '&' equality_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_And_Expression($1->pos, 2, argv);
	}
	;


exclusive_or_expression
	: and_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Exclusive_Or_Expression($1->pos, 1, argv);
	}
	| exclusive_or_expression '^' and_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Exclusive_Or_Expression($1->pos, 2, argv);
	}
	;

inclusive_or_expression
	: exclusive_or_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Inclusive_Or_Expression($1->pos, 1, argv);
	}
	| inclusive_or_expression '|' exclusive_or_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Inclusive_Or_Expression($1->pos, 2, argv);
	}
	;


logical_and_expression
	: inclusive_or_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Logical_And_Expression($1->pos, 1, argv);
	}
	| logical_and_expression AND_OP inclusive_or_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Logical_And_Expression($1->pos, 2, argv);
	}
	;


logical_or_expression
	: logical_and_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Logical_Or_Expression($1->pos, 1, argv);
	}
	| logical_or_expression OR_OP logical_and_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Logical_Or_Expression($1->pos, 2, argv);
	}
	;


conditional_expression
	: logical_or_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Conditional_Expression($1->pos, 1, argv);
	}
	| logical_or_expression '?' expression ':' conditional_expression
	{
		void *argv[3];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		argv[2] = (void *)$5;
		$$ = A_Conditional_Expression($1->pos, 2, argv);
	}
	;


assignment_expression
	: conditional_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Assignment_Expression($1->pos, 1, argv);
	}
	| unary_expression assignment_operator assignment_expression
	{
		void *argv[3];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		argv[2] = (void *)$3;
		$$ = A_Assignment_Expression($1->pos, 2, argv);
	}
	;

assignment_operator
	: '='
	{
		$$ = A_Assignment_Operator(yylineno, 1, NULL);
	}
	| MUL_ASSIGN
	{
		$$ = A_Assignment_Operator(yylineno, 2, NULL);
	}
	| DIV_ASSIGN
	{
		$$ = A_Assignment_Operator(yylineno, 3, NULL);
	}
	| MOD_ASSIGN
	{
		$$ = A_Assignment_Operator(yylineno, 4, NULL);
	}
	| ADD_ASSIGN
	{
		$$ = A_Assignment_Operator(yylineno, 5, NULL);
	}
	| SUB_ASSIGN
	{
		$$ = A_Assignment_Operator(yylineno, 6, NULL);
	}
	| AND_ASSIGN
	{
		$$ = A_Assignment_Operator(yylineno, 7, NULL);
	}
	| XOR_ASSIGN
	{
		$$ = A_Assignment_Operator(yylineno, 8, NULL);
	}
	| OR_ASSIGN
	{
		$$ = A_Assignment_Operator(yylineno, 9, NULL);
	}
	;

	


expression
	: assignment_expression
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Assignment_Expression($1->pos, 1, argv);
	}
	| expression ',' assignment_expression
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Assignment_Expression($1->pos, 2, argv);
	}
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Declaration($1->pos, 1, argv);
	}
	| declaration_specifiers init_declarator_list ';'
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Declaration($1->pos, 2, argv);
	}
	;

declaration_specifiers
	: storage_class_specifier
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| storage_class_specifier declaration_specifiers
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| type_specifier
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Declaration_Specifiers($1->pos, 1, argv);
	}
	| type_specifier declaration_specifiers
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Declaration_Specifiers($1->pos, 2, argv);
	}
	| type_qualifier
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| type_qualifier declaration_specifiers
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| function_specifier
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| function_specifier declaration_specifiers
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

init_declarator_list
	: init_declarator
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Init_Declarator_List($1->pos, 1, argv);
	}
	| init_declarator_list ',' init_declarator
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Init_Declarator_List($1->pos, 2, argv);
	}
	;

init_declarator
	: declarator
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Init_Declarator($1->pos, 1, argv);
	}
	| declarator '=' initializer
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$3;
		$$ = A_Init_Declarator($1->pos, 2, argv);
	}
	;

storage_class_specifier
	: TYPEDEF
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| EXTERN
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| STATIC
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| AUTO
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| REGISTER
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

type_specifier
	: VOID
	{
		$$ = A_Type_Specifier(yylineno, 1, NULL);
	}
	| CHAR
	{
		$$ = A_Type_Specifier(yylineno, 2, NULL);
	}
	| SHORT
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| INT
	{
		$$ = A_Type_Specifier(yylineno, 3, NULL);
	}
	| LONG
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| FLOAT
	{
		$$ = A_Type_Specifier(yylineno, 4, NULL);
	}
	| DOUBLE
	{
		$$ = A_Type_Specifier(yylineno, 5, NULL);
	}
	| SIGNED
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| UNSIGNED
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| BOOL
	{
		$$ = A_Type_Specifier(yylineno, 6, NULL);
	}
	| COMPLEX
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| IMAGINARY
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| struct_or_union_specifier
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| enum_specifier
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| TYPE_NAME
	{
		$$ = A_Type_Specifier(yylineno, 7, NULL);
	}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| struct_or_union '{' struct_declaration_list '}'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| struct_or_union IDENTIFIER
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

struct_or_union
	: STRUCT
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| UNION
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

struct_declaration_list
	: struct_declaration
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| struct_declaration_list struct_declaration
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Specifier_Qualifier_List($1->pos, 2, argv);
	}
	| type_specifier
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Specifier_Qualifier_List($1->pos, 1, argv);
	}
	| type_qualifier specifier_qualifier_list
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| type_qualifier
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

struct_declarator_list
	: struct_declarator
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| struct_declarator_list ',' struct_declarator
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

struct_declarator
	: declarator
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| ':' constant_expression
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| declarator ':' constant_expression
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| ENUM IDENTIFIER '{' enumerator_list '}'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| ENUM '{' enumerator_list ',' '}'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| ENUM IDENTIFIER
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

enumerator_list
	: enumerator
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| enumerator_list ',' enumerator
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

enumerator
	: IDENTIFIER
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| IDENTIFIER '=' constant_expression
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

type_qualifier
	: CONST
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| RESTRICT
	{
		printf("Not Supported!\n");
		exit(0);
	}
	| VOLATILE
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

function_specifier
	: INLINE
	{
		printf("Not Supported!\n");
		exit(0);
	}
	;

declarator
	: pointer direct_declarator
	{
		void *argv[2];
		argv[0] = (void *)$1;
		argv[1] = (void *)$2;
		$$ = A_Declarator($1->pos, 2, argv);
	}
	| direct_declarator
	{
		void *argv[1];
		argv[0] = (void *)$1;
		$$ = A_Declarator($1->pos, 1, argv);
	}
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