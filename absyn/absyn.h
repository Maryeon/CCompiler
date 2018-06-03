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


struct A_translationUnit_{
	A_externalDeclaration *head;
};

struct A_externalDeclaration_{
	int grammer;
	union{
		A_functionDefinition functiondefinition;
		A_declaration declaration;
	}u;
};

struct A_directDeclarator_{
	int grammer;
	union{
		S_symbol u1;
	}u;
};

struct A_pointer_{
	int grammer;
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
};

struct A_parameterList_{
	int grammer;
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
	union{
		A_abstractDeclarator u1;
	}u;
};

struct A_initializer_{
	int grammer;
	union{
		A_assignExpression u1;
		A_initializerList u2;
		A_initializerList u3;
	}u;
};

struct A_initializerList_{
	int grammer;
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
};

struct A_designationList_{
	int grammer;
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
	union{
		A_constantExpression u1;
		S_symbol u2;
	}u;
};

struct A_statement_{
	int grammer;
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
};

struct A_blockItemList_{
	int grammer;
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
	union{
		A_declaration u1;
		A_statement u2;
	}u;
};

struct A_expressionStatement_{
	int grammer;
	A_expression u;
};

struct A_selectionStatement_{
	int grammer;
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
	union{
		S_symbol u1;
		A_expression u5;
	}u;
};

struct A_functionDefinition_{
	int grammer;
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
	union{
		A_declaration u1;
		struct{
			A_declarationList u1;
			A_declaration u2;
		}u2;
	}u;
};