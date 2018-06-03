typedef int A_pos;
typedef struct A_translationUnit_ *A_translationUnit;
typedef struct A_externalDeclaration_ *A_externalDeclaration;
typedef struct A_var_ *A_var;
typedef struct A_exp_ *A_exp;
typedef struct A_dec_ *A_dec;
typedef struct A_fundec_ *A_fundec;
typedef struct A_fundecList_ *A_fundecList;
typedef struct A_nametyList_ *A_nametyList;
typedef struct A_expList_ *A_expList;



struct A_primaryExpression_{
	enum{IDENTIFIER, CONSTANT_INT, CONSTANT_DOUBLE, STRING_LITERAL, LP_expression_RP}kind;
	A_pos pos;
	union{
		S_Symbol symbol;
		int intt;
		double doublee;
		string stringg;
		A_expression expression;
	}u;
};

struct A_postfix_expression_{
	enum{PRI_E, POST_E, POST_LP_RP, POST_LP_AEL_RP, POST_DOT_ID, //POST_PTR_OP_ID,
	POST_INC_OP, POST_DEC_OP, LR_TN_RP_IL, LP_TN_RP_IL_SEMI}kind;
	A_pos pos;
	union{
		A_primaryExpression primary_expression;
		struct{A_postfix_expression postfix_expression; A_expression expression; }post_e;
		A_postfix_expression postfix_expression;
		struct{A_postfix_expression postfix_expression; A_argument_expression_list argument_expression_list; }post_lp_ael_rp;
		struct{A_postfix_expression postfix_expression; S_Symbol symbol; }post_dot_id;
		//postfix_expression PTR_OP IDENTIFIER,
		A_postfix_expression postfix_expression;
		A_postfix_expression postfix_expression;
		struct{A_type_name type_name; A_initializer_list initializer_list; }lr_tn_rp_il;
		struct{A_type_name type_name; A_initializer_list initializer_list; }lp_tn_rp_il_semi;
	}u;
};

struct A_argument_expression_list_{
	enum{ASS_E, AEL}kind;
	A_pos pos;
	union{
		A_assignment_expression assignment_expression;
		struct{A_argument_expression_list argument_expression_list; A_assignment_expression assignment_expression; }ael;
	}u;
};

struct A_unary_expression_{
	int kind;
	A_pos pos;
	union{
		A_postfix_expression postfix_expression;
		A_unary_expression unary_expression;
		A_unary_expression unary_expression;
		struct{A_unary_operator unary_operator; A_cast_expression cast_expression; }lr_tn_rp_il;
		A_unary_expression unary_expression;
		A_type_name type_name;
	}u;
};

struct A_unary_operator_{
	int kind;
	A_pos pos;
		//'&'
		//'*'
		//'+'
		//'-'
		//'~'
		//'!'
};

struct A_cast_expression_{
	int kind;
	A_pos pos;
	union{
		A_unary_expression unary_expression;
		struct{A_type_name type_name; A_cast_expression cast_expression; }tn_ce;
	}u;
};
	

struct A_multiplicative_expression_{
	int kind;
	A_pos pos;
	union{
		A_cast_expression cast_expression; 
		struct{A_multiplicative_expression multiplicative_expression; A_cast_expression cast_expression; }mul;
		struct{A_multiplicative_expression multiplicative_expression; A_cast_expression cast_expression; }div;
		struct{A_multiplicative_expression multiplicative_expression; A_cast_expression cast_expression; }mod;
	}u;
};

struct A_additive_expression_{
	int kind;
	A_pos pos;
	union{
		A_multiplicative_expression multiplicative_expression;
		struct{A_additive_expression additive_expression; A_multiplicative_expression multiplicative_expression;}add;
		struct{A_additive_expression additive_expression; A_multiplicative_expression multiplicative_expression;}minus;
	}u;
};

struct A_shift_expression_{
	int kind;
	A_pos pos;
	union{
		A_additive_expression additive_expression;
	}u;
};

struct A_relational_expression_{
	int kind;
	A_pos pos;
	union{
		A_shift_expression shift_expression;
		struct{A_relational_expression relational_expression; A_shift_expression shift_expression;}lt;
		struct{A_relational_expression relational_expression; A_shift_expression shift_expression;}gt;
		struct{A_relational_expression relational_expression; A_shift_expression shift_expression;}le;
		struct{A_relational_expression relational_expression; A_shift_expression shift_expression;}ge;
	}u;
};

struct A_equality_expression_{
	int kind;
	A_pos pos;
	union{
		A_relational_expression relational_expression;
		struct{A_equality_expression equality_expression; A_relational_expression relational_expression;}eq;
		struct{A_equality_expression equality_expression; A_relational_expression relational_expression;}neq;
	}u;
};

struct A_and_expression_{
	int kind;
	A_pos pos;
	union{
		A_equality_expression equality_expression; 
		struct{A_and_expression and_expression; A_equality_expression equality_expression;}andd;
	}u;
};

struct A_exclusive_or_expression_{
	int kind;
	A_pos pos;
	union{
		A_and_expression and_expression;
		struct{A_exclusive_or_expression exclusive_or_expression; A_and_expression and_expression;}xorr;
	}u;
};

struct A_inclusive_or_expression_{
	int kind;
	A_pos pos;
	union{
		A_exclusive_or_expression exclusive_or_expression;
		struct{A_inclusive_or_expression inclusive_or_expression; A_exclusive_or_expression exclusive_or_expression;}orr;
	}u;
};

struct A_logical_and_expression_{
	int kind;
	A_pos pos;
	union{
		A_inclusive_or_expression inclusive_or_expression;
		struct{A_logical_and_expression logical_and_expression; A_inclusive_or_expression inclusive_or_expression;}and_op;
	}u;
};

struct A_logical_or_expression_{
	int kind;
	A_pos pos;
	union{
		A_logical_and_expression logical_and_expression;
		struct{A_logical_or_expression logical_or_expression; A_logical_and_expression logical_and_expression;}or_op;
	}u;
};

struct A_conditional_expression_{
	int kind;
	A_pos pos;
	union{
		A_logical_or_expression logical_or_expression;
		struct{A_logical_or_expression logical_or_expression; A_expression expression; A_conditional_expression conditional_expression;}cond;
	}u;
};

struct A_assignment_expression_{
	int kind;
	A_pos pos;
	union{
		A_conditional_expression conditional_expression;
		struct{A_unary_expression unary_expression; A_assignment_operator assignment_operator; A_assignment_expression assignment_expression;}assignn;
	}u;
};

struct A_assignment_operator_{
	enum{
		ASSIGN,//'='
		MUL_ASSIGN,
		DIV_ASSIGN,
		MOD_ASSIGN,
		ADD_ASSIGN,
		SUB_ASSIGN,
		AND_ASSIGN,
		XOR_ASSIGN,
		OR_ASSIGN
	}kind;
	A_pos pos;
};



/******************example*************/
struct A_translationUnit_{
	A_externalDeclaration *head;
	A_pos pos;
};

struct A_externalDeclaration_{
	enum{A_FUNCTIONDEFINITION, A_DECLARATION}kind;
	A_pos pos;
	union{
		A_functionDefinition functiondefinition;
		A_declaration declaration;
	}u;
};



