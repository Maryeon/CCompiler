typedef int A_pos;
typedef struct A_translationUnit_ *A_translationUnit;
typedef struct A_externalDeclaration_ *A_externalDeclaration;
typedef struct A_directDeclarator_ *A_directDeclarator;
typedef struct A_pointer_ *A_pointer;
typedef struct A_typeQualifierList_ *A_typeQualifierList;
typedef struct A_parameterTypeList_ *A_parameterTypeList;
typedef struct A_parameterList_ *A_parameterList;
typedef struct A_parameterDeclaration_ *A_parameterDeclaration;
typedef struct A_identifierList_ *A_identifierList;
typedef struct A_typeName_ *A_typeName;
typedef struct A_abstractDeclarator_ *A_abstractDeclarator;
typedef struct A_directAbstractDeclarator_ *A_directAbstractDeclarator;
typedef struct A_initializer_ *A_initializer;
typedef struct A_initializerList_ *A_initializerList;
typedef struct A_designation_ *A_designation;
typedef struct A_designationList_ *A_designationList;
typedef struct A_designator_ *A_designator;
typedef struct A_statement_ *A_statement;
typedef struct A_labeledStatement_ *A_labeledStatement;
typedef struct A_compoundStatement_ *A_compoundStatement;
typedef struct A_blockItemList_ *A_blockItemList;
typedef struct A_blockItem_ *A_blockItem;
typedef struct A_expressionStatement_ *A_expressionStatement;
typedef struct A_selectionStatement_ *A_selectionStatement;
typedef struct A_iterationStatement_ *A_iterationStatement;
typedef struct A_jumpStatement_ *A_jumpStatement;
typedef struct A_functionDefinition_ *A_functionDefinition;
typedef struct A_declarationList_ *A_declarationList;


typedef struct A_declaration_ *A_declaration;
typedef struct A_declaration_specifiers_ *A_declaration_specifiers;
typedef struct A_init_declarator_list_ *A_init_declarator_list;
typedef struct A_init_declarator_ *A_init_declarator;
typedef struct A_type_specifier_ *A_type_specifier;
typedef struct A_specifier_qualifier_list_ *A_specifier_qualifier_list;
typedef struct A_declarator_ *A_declarator;


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
	int grammer;
	enum{A_FUNCTIONDEFINITION, A_DECLARATION}kind;
	A_pos pos;
	union{
		A_functionDefinition functiondefinition;
		A_declaration declaration;
	}u;
};


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


struct A_directDeclarator_{
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
		A_typeQualifierList u1;
		A_pointer u2;
		struct{
			A_typeQualifierList typequalifierlist;
			A_pointer pointer;
		}u3;
	}u;
};

struct A_typeQualifierList_{
	int grammer;
	A_pos pos;
	union{
		A_typeQualifier u1;
		struct{
			A_typeQualifierList u1;
			A_typeQualifier u2;
		}u2;
	}u;
};

struct A_parameterTypeList_{
	A_parameterList u;
	A_pos pos;
};

struct A_parameterList_{
	int grammer;
	A_pos pos;
	union{
		A_parameterDeclaration u1;
		struct{
			A_parameterList u1;
			A_parameterDeclaration u2;
		}u2;
	}u;
};

struct A_parameterDeclaration_{
	int grammer;
	A_pos pos;
	union{
		struct{
			A_declarationSpecifiers u1;
			A_declarator u2;
		}u1;
		struct{
			A_declarationSpecifiers u1;
			A_abstractDeclarator u2;
		}u2;
		struct{
			A_declarationSpecifiers u;
		}u3;
	}u;
};

struct A_identifierList_{
	int grammer;
	A_pos pos;
	union{
		A_var u1;
		struct{
			A_identifierList u1;
			S_symbol u2;
		}u2;
	}u;
};

struct A_typeName_{
	int grammer;
	A_pos pos;
	union{
		A_specifierQualifierList u1;
		struct{
			A_specifierQualifierList u1;
			A_abstractDeclarator u2;
		}u2;
	}u;
};

struct A_abstractDeclarator_{
	int grammer;
	A_pos pos;
	union{
		A_pointer u1;
		A_directAbstractDeclarator u2;
		struct{
			A_pointer u1;
			A_directAbstractDeclarator u2;
		}u3;
	}u;
};

struct A_directAbstractDeclarator_{
	int grammer;
	A_pos pos;
	union{
		A_abstractDeclarator u1;
	}u;
};

struct A_initializer_{
	int grammer;
	A_pos pos;
	union{
		A_assignExpression u1;
		A_initializerList u2;
		A_initializerList u3;
	}u;
};

struct A_initializerList_{
	int grammer;
	A_pos pos;
	union{
		A_initializer u1;
		struct{
			A_designation u1;
			A_initializer u2;
		}u2;
		struct{
			A_initializerList u1;
			A_initializer u2;
		}u3;
		struct{
			A_initializerList u1;
			A_designation u2;
			A_initializer u3;
		}u4;
	}u;
};

struct A_designation_{
	A_designatorList u;
	A_pos pos;
};

struct A_designationList_{
	int grammer;
	A_pos pos;
	union{
		A_designator u1;
		struct{
			A_designatorList u1;
			A_designator u2;
		}u2;
	}u;
};

struct A_designator_{
	int grammer;
	A_pos pos;
	union{
		A_constantExpression u1;
		S_symbol u2;
	}u;
};

struct A_statement_{
	int grammer;
	A_pos pos;
	union{
		A_labeledStatement u1;
		A_compoundStatement u2;
		A_expressionStatement u3;
		A_selectionStatement u4;
		A_iterationStatement u5;
		A_jumpStatement u6;
	}u;
};

struct A_labeledStatement_{
	int grammer;
	A_pos pos;
	union{
		struct{
			S_symbol u1;
			A_statement u2;
		}u1;
		struct{
			A_constantExpression u1;
			A_statement u2;
		}u2;
		A_statement u3;
	}u;
};

struct A_compoundStatement_{
	int grammer;
	A_blockItemList u;
	A_pos pos;
};

struct A_blockItemList_{
	int grammer;
	A_pos pos;
	union{
		A_blockItem u1;
		struct{
			A_blockItemList u1;
			A_blockItem u2;
		}u2;
	}u;
};

struct A_blockItem_{
	int grammer;
	A_pos pos;
	union{
		A_declaration u1;
		A_statement u2;
	}u;
};

struct A_expressionStatement_{
	int grammer;
	A_pos pos;
	A_expression u;
};

struct A_selectionStatement_{
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

struct A_iterationStatement_{
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
			A_expressionStatement u1;
			A_expressionStatement u2;
			A_statement u3;
		}u3;
		struct{
			A_expressionStatement u1;
			A_expressionStatement u2;
			A_expression u3;
			A_statement u4;
		}u4;
		struct{
			A_declaration u1;
			A_expressionStatement u2;
			A_statement u3;
		}u5;
		struct{
			A_declaration u1;
			A_expressionStatement u2;
			A_expression u3;
			A_statement u4;
		}u6;
	}u;
};

struct A_jumpStatement_{
	int grammer;
	A_pos pos;
	union{
		S_symbol u1;
		A_expression u5;
	}u;
};

struct A_functionDefinition_{
	int grammer;
	A_pos pos;
	union{
		struct{
			A_declarationSpecifiers u1;
			A_declarator u2;
			A_declarationList u3;
			A_compoundStatement u4;
		}u1;
		struct{
			A_declarationSpecifiers u1;
			A_declarator u2;
			A_compoundStatement u3;
		}u2;
	}u;
};

struct A_declarationList_{
	int grammer;
	A_pos pos;
	union{
		A_declaration u1;
		struct{
			A_declarationList u1;
			A_declaration u2;
		}u2;
	}u;
};
