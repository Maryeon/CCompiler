#include "util.h"

typedef int A_pos;
typedef struct A_translation_unit_ *A_translation_unit;
typedef struct A_external_declaration_ *A_external_declaration;
typedef struct A_direct_declarator_ *A_direct_declarator;

typedef struct A_primary_expression_ *A_primary_expression;
typedef struct A_argument_expression_list_ *A_argument_expression_list;
typedef struct A_unary_expression_ *A_unary_expression;
typedef struct A_unary_operator_ *A_unary_operator;
typedef struct A_cast_expression_ *A_cast_expression;
typedef struct A_multiplicative_expression_ *A_multiplicative_expression;
typedef struct A_additive_expression_ *A_additive_expression;
typedef struct A_shift_expression_ *A_shift_expression;
typedef struct A_relational_expression_ *A_relational_expression;
typedef struct A_equality_expression_ *A_equality_expression;
typedef struct A_and_expression_ *A_and_expression;
typedef struct A_exclusive_or_expression_ *A_exclusive_or_expression;
typedef struct A_inclusive_or_expression_ *A_inclusive_or_expression;
typedef struct A_logical_and_expression_ *A_logical_and_expression;
typedef struct A_logical_or_expression_ *A_logical_or_expression;
typedef struct A_conditional_expression_ *A_conditional_expression;
typedef struct A_assignment_expression_ *A_assignment_expression;

typedef struct A_assignment_operator_ *A_assignment_operator;
typedef struct A_pointer_ *A_pointer;
typedef struct A_type_qualifier_ *A_type_qualifier;
typedef struct A_type_qualifier_list_ *A_type_qualifier_list;
typedef struct A_parameter_type_list_ *A_parameter_type_list;
typedef struct A_parameter_list_ *A_parameter_list;
typedef struct A_parameter_declaration_ *A_parameter_declaration;
typedef struct A_identifier_list_ *A_identifier_list;
typedef struct A_type_name_ *A_type_name;
typedef struct A_abstract_declarator_ *A_abstract_declarator;
typedef struct A_direct_abstract_declarator_ *A_direct_abstract_declarator;
typedef struct A_initializer_ *A_initializer;
typedef struct A_initializer_list_ *A_initializer_list;
typedef struct A_designation_ *A_designation;
typedef struct A_designator_list_ *A_designator_list;
typedef struct A_designator_ *A_designator;
typedef struct A_statement_ *A_statement;
typedef struct A_labeled_statement_ *A_labeled_statement;
typedef struct A_compound_statement_ *A_compound_statement;
typedef struct A_block_item_list_ *A_block_item_list;
typedef struct A_block_item_ *A_block_item;
typedef struct A_expression_statement_ *A_expression_statement;
typedef struct A_selection_statement_ *A_selection_statement;
typedef struct A_iteration_statement_ *A_iteration_statement;
typedef struct A_jump_statement_ *A_jump_statement;
typedef struct A_function_definition_ *A_function_definition;
typedef struct A_declaration_list_ *A_declaration_list;


typedef struct A_declaration_ *A_declaration;
typedef struct A_declaration_specifiers_ *A_declaration_specifiers;
typedef struct A_init_declarator_list_ *A_init_declarator_list;
typedef struct A_init_declarator_ *A_init_declarator;
typedef struct A_type_specifier_ *A_type_specifier;
typedef struct A_specifier_qualifier_list_ *A_specifier_qualifier_list;
typedef struct A_declarator_ *A_declarator;
typedef struct A_expression_ *A_expression;
typedef struct A_constant_expression_ *A_constant_expression;

struct A_constant_expression_{
	int grammer;
	A_pos pos;
	A_conditional_expression u;
};

struct A_expression_{
	int grammer;
	A_pos pos;
	union{
		A_assignment_expression u1;
		struct{
			A_expression u1;
			A_assignment_expression u2;
		}u2;
	}u;
};

/******************GUO***************/

struct A_primary_expression_{
	enum{IDENTIFIER, CONSTANT_INT, CONSTANT_DOUBLE, STRING_LITERAL, LP_expression_RP}kind;
	//int kind;
	A_pos pos;
	union{
		S_symbol symbol;
		int intt;
		double doublee;
		string stringg;
		A_expression expression;
	}u;
};

struct A_postfix_expression_{
	//enum{PRI_E, POST_E, POST_LP_RP, POST_LP_AEL_RP, POST_DOT_ID, //POST_PTR_OP_ID,
	//POST_INC_OP, POST_DEC_OP, LR_TN_RP_IL, LP_TN_RP_IL_SEMI}kind;
	int kind;
	A_pos pos;
	union{
		A_primary_expression primary_expression;
		struct{A_postfix_expression postfix_expression; A_expression expression; }post_e;
		A_postfix_expression postfix_expression;
		struct{A_postfix_expression postfix_expression; A_argument_expression_list argument_expression_list; }post_lp_ael_rp;
		struct{A_postfix_expression postfix_expression; S_symbol symbol; }post_dot_id;
		//postfix_expression PTR_OP IDENTIFIER,
		A_postfix_expression postfix_expression;
		A_postfix_expression postfix_expression;
		struct{A_type_name type_name; A_initializer_list initializer_list; }lr_tn_rp_il;
		struct{A_type_name type_name; A_initializer_list initializer_list; }lp_tn_rp_il_semi;
	}u;
};

struct A_argument_expression_list_{
	//enum{ASS_E, AEL}kind;
	int kind;
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
	/* enum{
		ASSIGN,//'='
		MUL_ASSIGN,
		DIV_ASSIGN,
		MOD_ASSIGN,
		ADD_ASSIGN,
		SUB_ASSIGN,
		AND_ASSIGN,
		XOR_ASSIGN,
		OR_ASSIGN
	}kind; */
	int kind;
	A_pos pos;
};

/******************END***************/

/******************MA***************/
struct A_translation_unit_{
	int grammer;
	union{
		A_external_declaration u1;
		struct{
			A_translation_unit u1;
			A_external_declaration u2;
		}u2;
	}u;
	A_pos pos;
};

struct A_external_declaration_{
	int grammer;
	A_pos pos;
	union{
		A_function_definition u1;
		A_declaration u2;
	}u;
};

struct A_type_qualifier_{
	enum{
		CONST,
		RESTRICT,
		VOLATILE
	}kind;
	A_pos pos;
};
/******************END***************/


//Liu===============================================================
struct A_declaration_{
	enum{Fenhao} kind;
	A_pos pos;
	union{
		A_declaration_specifiers declaration_specifiers;
		struct{A_declaration_specifiers declaration_specifiers;A_init_declarator_list init_declarator_list;}dec2;
	}u;
}

struct A_declaration_specifiers_{
	int kind;
	A_pos pos;
	union{
		//storage_class_specifier
		//storage_class_specifier declaration_specifiers
		A_type_specifier type_specifier;
		struct{A_type_specifier type_specifier;A_declaration_specifiers declaration_specifiers;}type_s_dec;
		//A_type_qualifier type_qualifier;
		//struct{A_type_qualifier type_qualifier;A_declaration_specifiers declaration_specifiers;}type_q_dec;
		//function_specifier
		//function_specifier declaration_specifiers
	}u;
}

struct A_init_declarator_list_{
	enum{Douhao} kind;
	A_pos pos;
	union{
		A_init_declarator init_declarator;
		struct{A_init_declarator_list init_declarator_list;A_init_declarator init_declarator;}init_dec_list;
	
	}u;
}

struct A_init_declarator_{
	enum{Equal} kind;
	A_pos pos;
	union{
		A_declarator declarator;
		struct{A_declarator declarator;A_initializer initializer;}init_dec2;
	}u;
}

struct A_type_specifier_{
	enum{eVOID,eCHAR,eINT,eLONG,eSHORT,eFLOAT,eDOUBLE,eSIGHED,eUNSIGNED,eBOOL}kind;
	A_pos pos;
	union{
		A_struct_or_union_specifier struct_or_union_specifier;
		//enum_specifier
	}u;
}


struct A_specifier_qualifier_list_{
	int kind;
	A_pos pos;
	union{
		struct{A_type_specifier type_specifier;A_specifier_qualifier_list specifier_qualifier_list;}sql;
		A_type_specifier type_specifier;
		//type_qualifier specifier_qualifier_list
		//type_qualifier
	}u;
}

struct A_declarator_{
	int kind;
	A_pos pos;
	union{
		struct{A_pointer pointer; A_direct_declarator direct_declarator;}dec;
		A_direct_declarator direct_declarator;
	}u;
}


//end===============================================================


struct A_direct_declarator_{
	int grammer;
	A_pos pos;
	union{
		S_symbol u1;
	}u;
};

struct A_pointer_{
	int grammer;
	A_pos pos;
	union{
		A_type_qualifier_list u1;
		A_pointer u2;
		struct{
			A_type_qualifier_list u1;
			A_pointer u2;
		}u3;
	}u;
};

struct A_type_qualifier_list_{
	int grammer;
	A_pos pos;
	union{
		A_type_qualifier u1;
		struct{
			A_type_qualifier_list u1;
			A_type_qualifier u2;
		}u2;
	}u;
};

struct A_parameter_type_list_{
	A_parameter_list u;
	A_pos pos;
};

struct A_parameter_list_{
	int grammer;
	A_pos pos;
	union{
		A_parameter_declaration u1;
		struct{
			A_parameter_list u1;
			A_parameter_declaration u2;
		}u2;
	}u;
};

struct A_parameter_declaration_{
	int grammer;
	A_pos pos;
	union{
		struct{
			A_declaration_specifiers u1;
			A_declarator u2;
		}u1;
		struct{
			A_declaration_specifiers u1;
			A_abstract_declarator u2;
		}u2;
		A_declaration_specifiers u3;
	}u;
};

struct A_identifier_list_{
	int grammer;
	A_pos pos;
	union{
		S_symbol u1;
		struct{
			A_identifier_list u1;
			S_symbol u2;
		}u2;
	}u;
};

struct A_type_name_{
	int grammer;
	A_pos pos;
	union{
		A_specifier_qualifier_list u1;
		struct{
			A_specifier_qualifier_list u1;
			A_abstract_declarator u2;
		}u2;
	}u;
};

struct A_abstract_declarator_{
	int grammer;
	A_pos pos;
	union{
		A_pointer u1;
		A_direct_abstract_declarator u2;
		struct{
			A_pointer u1;
			A_direct_abstract_declarator u2;
		}u3;
	}u;
};

struct A_direct_abstract_declarator_{
	int grammer;
	A_pos pos;
	union{
		A_abstract_declarator u1;
	}u;
};

struct A_initializer_{
	int grammer;
	A_pos pos;
	union{
		A_assignment_expression u1;
		A_initializer_list u2;
		A_initializer_list u3;
	}u;
};

struct A_initializer_list_{
	int grammer;
	A_pos pos;
	union{
		A_initializer u1;
		struct{
			A_designation u1;
			A_initializer u2;
		}u2;
		struct{
			A_initializer_list u1;
			A_initializer u2;
		}u3;
		struct{
			A_initializer_list u1;
			A_designation u2;
			A_initializer u3;
		}u4;
	}u;
};

struct A_designation_{
	A_designator_list u;
	A_pos pos;
};

struct A_designator_list_{
	int grammer;
	A_pos pos;
	union{
		A_designator u1;
		struct{
			A_designator_list u1;
			A_designator u2;
		}u2;
	}u;
};

struct A_designator_{
	int grammer;
	A_pos pos;
	union{
		A_constant_expression u1;
		S_symbol u2;
	}u;
};

struct A_statement_{
	int grammer;
	A_pos pos;
	union{
		A_labeled_statement u1;
		A_compound_statement u2;
		A_expression_statement u3;
		A_selection_statement u4;
		A_iteration_statement u5;
		A_jump_statement u6;
	}u;
};

struct A_labeled_statement_{
	int grammer;
	A_pos pos;
	union{
		struct{
			S_symbol u1;
			A_statement u2;
		}u1;
		struct{
			A_constant_expression u1;
			A_statement u2;
		}u2;
		A_statement u3;
	}u;
};

struct A_compound_statement_{
	int grammer;
	A_block_item_list u;
	A_pos pos;
};

struct A_block_item_list_{
	int grammer;
	A_pos pos;
	union{
		A_block_item u1;
		struct{
			A_block_item_list u1;
			A_block_item u2;
		}u2;
	}u;
};

struct A_block_item_{
	int grammer;
	A_pos pos;
	union{
		A_declaration u1;
		A_statement u2;
	}u;
};

struct A_expression_statement_{
	int grammer;
	A_pos pos;
	A_expression u;
};

struct A_selection_statement_{
	int grammer;
	A_pos pos;
	union{
		struct{
			A_expression u1;
			A_statement u2;
		}u1;
		struct{
			A_expression u1;
			A_statement u2;
			A_statement u3;
		}u2;
		struct{
			A_expression u1;
			A_statement u2;
		}u3;
	}u;
};

struct A_iteration_statement_{
	int grammer;
	A_pos pos;
	union{
		struct{
			A_expression u1;
			A_statement u2;
		}u1;
		struct{
			A_statement u1;
			A_expression u2;
		}u2;
		struct{
			A_expression_statement u1;
			A_expression_statement u2;
			A_statement u3;
		}u3;
		struct{
			A_expression_statement u1;
			A_expression_statement u2;
			A_expression u3;
			A_statement u4;
		}u4;
		struct{
			A_declaration u1;
			A_expression_statement u2;
			A_statement u3;
		}u5;
		struct{
			A_declaration u1;
			A_expression_statement u2;
			A_expression u3;
			A_statement u4;
		}u6;
	}u;
};

struct A_jump_statement_{
	int grammer;
	A_pos pos;
	union{
		S_symbol u1;
		A_expression u5;
	}u;
};

struct A_function_definition_{
	int grammer;
	A_pos pos;
	union{
		struct{
			A_declaration_specifiers u1;
			A_declarator u2;
			A_declaration_list u3;
			A_compound_statement u4;
		}u1;
		struct{
			A_declaration_specifiers u1;
			A_declarator u2;
			A_compound_statement u3;
		}u2;
	}u;
};

struct A_declaration_list_{
	int grammer;
	A_pos pos;
	union{
		A_declaration u1;
		struct{
			A_declaration_list u1;
			A_declaration u2;
		}u2;
	}u;
};



A_primary_expression A_identifier(A_pos pos, S_symbol symbol);
A_primary_expression A_constant_int(A_pos pos, int intt);
A_primary_expression A_constant_double(A_pos pos, double doublee);
A_primary_expression A_string_literal(A_pos pos, string stringg);
A_primary_expression A_lp_expression_rp(A_pos pos, A_expression expression);

A_postfix_expression A_Postfix_Expression(A_pos pos, int kind, void *argv[]);
A_argument_expression_list A_Argument_Expression_List(A_pos pos, int kind, void *argv[]);
A_unary_expression A_Unary_Expression(A_pos pos, int kind, void *argv[]);
A_unary_operator A_Unary_Operator(A_pos pos, int kind, void *argv[]);
A_cast_expression A_Cast_Expression(A_pos pos, int kind, void *argv[]);
A_multiplicative_expression A_Multiplicative_Expression(A_pos pos, int kind, void *argv[]);
A_additive_expression A_Additive_Expression(A_pos pos, int kind, void *argv[]);
A_shift_expression A_Shift_Expression(A_pos pos, int kind, void *argv[]);
A_relational_expression A_Relational_Expression(A_pos pos, int kind, void *argv[]);
A_equality_expression A_Equality_Expression(A_pos pos, int kind, void *argv[]);
A_and_expression A_And_Expression(A_pos pos, int kind, void *argv[]);
A_exclusive_or_expression A_Exclusive_Or_Expression(A_pos pos, int kind, void *argv[]);
A_inclusive_or_expression A_Inclusive_Or_Expression(A_pos pos, int kind, void *argv[]);
A_logical_and_expression A_Logical_And_Expression(A_pos pos, int kind, void *argv[]);
A_logical_or_expression A_Logical_Or_Expression(A_pos pos, int kind, void *argv[]);
A_conditional_expression A_Conditional_Expression(A_pos pos, int kind, void *argv[]);
A_assignment_expression A_Assignment_Expression(A_pos pos, int kind, void *argv[]);
A_assignment_operator A_Assignment_Operator(A_pos pos, int kind, void *argv[]);


A_translation_unit A_Translation_Unit(A_pos pos, int grammer, void *argv[]);
A_external_declaration A_External_Declaration(A_pos pos, int grammer, void *argv[]);
A_direct_declarator A_Direct_Declarator(A_pos pos, int grammer, void *argv[]);
A_pointer A_Pointer(A_pos pos, int grammer, void *argv[]);
A_type_qualifier_list A_Type_Qualifier_List(A_pos pos, int grammer, void *argv[]);
A_parameter_type_list A_Parameter_Type_List(A_pos pos, int grammer, void *argv[]);
A_parameter_list A_Parameter_List(A_pos pos, int grammer, void *argv[]);
A_parameter_declaration A_Parameter_Declaration(A_pos pos, int grammer, void *argv[]);
A_identifier_list A_Identifier_List(A_pos pos, int grammer, void *argv[]);
A_type_name A_Type_Name(A_pos pos, int grammer, void *argv[]);
A_abstract_declarator A_Abstract_Declarator(A_pos pos, int grammer, void *argv[]);
A_direct_abstract_declarator A_Direct_Abstract_Declarator(A_pos pos, int grammer, void *argv[]);
A_initializer A_Initializer(A_pos pos, int grammer, void *argv[]);
A_initializer_list A_Initializer_List(A_pos pos, int grammer, void *argv[]);
A_designation A_Designation(A_pos pos, int grammer, void *argv[]);
A_designator_list A_Designator_List(A_pos pos, int grammer, void *argv[]);
A_designator A_Designator(A_pos pos, int grammer, void *argv[]);
A_statement A_Statement(A_pos pos, int grammer, void *argv[]);
A_labeled_statement A_Labeled_Statement(A_pos pos, int grammer, void *argv[]);
A_compound_statement A_Compound_Statement(A_pos pos, int grammer, void *argv[]);
A_block_item_list A_Block_Item_List(A_pos pos, int grammer, void *argv[]);
A_block_item A_Block_Item(A_pos pos, int grammer, void *argv[]);
A_expression_statement A_Expression_Statement(A_pos pos, int grammer, void *argv[]);
A_selection_statement A_Selection_Statement(A_pos pos, int grammer, void *argv[]);
A_iteration_statement A_Iteration_Statement(A_pos pos, int grammer, void *argv[]);
A_jump_statement A_Jump_Statement(A_pos pos, int grammer, void *argv[]);
A_function_definition A_Function_Definition(A_pos pos, int grammer, void *argv[]);
A_declaration_list A_Declaration_List(A_pos pos, int grammer, void *argv[]);

