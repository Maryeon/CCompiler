#ifndef ABSYN_H
#define ABSYN_H

#include"absyn.h"

/******************************GUO******************************/

A_primary_expression A_identifier(A_pos pos, S_symbol symbol)
{
	A_primary_expression p = checked_malloc(sizeof(*p));
	p->kind = IDENTIFIER;
	p->pos = pos;
	p->u.symbol = symbol;
	return p;
}

A_primary_expression A_constant_int(A_pos pos, int intt)
{
	A_primary_expression p = checked_malloc(sizeof(*p));
	p->kind = CONSTANT_INT;
	p->pos = pos;
	p->u.intt = intt;
	return p;
}

A_primary_expression A_constant_double(A_pos pos, double doublee)
{
	A_primary_expression p = checked_malloc(sizeof(*p));
	p->kind = CONSTANT_DOUBLE;
	p->pos = pos;
	p->u.doublee = doublee;
	return p;
}
A_primary_expression A_string_literal(A_pos pos, string stringg)
{
	A_primary_expression p = checked_malloc(sizeof(*p));
	p->kind = STRING_LITERAL;
	p->pos = pos;
	p->u.stringg = stringg;
	return p;
}
A_primary_expression A_lp_expression_rp(A_pos pos, A_expression expression)
{
	A_primary_expression p = checked_malloc(sizeof(*p));
	p->kind = LP_expression_RP;
	p->pos = pos;
	p->u.expression = expression;
	return p;
}


A_postfix_expression A_Postfix_Expression(A_pos pos, int kind, void *argv[])
{
	A_postfix_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.primary_expression = (A_primary_expression)argv[0];
				break;
		case 2: p->u.post_e.postfix_expression = (A_postfix_expression)argv[0];
				p->u.post_e.expression = (A_expression)argv[1];
				break;
		case 3: p->u.postfix_expression = (A_postfix_expression)argv[0];
				break;
		case 4: p->u.post_lp_ael_rp.postfix_expression = (A_postfix_expression)argv[0];
				p->u.post_lp_ael_rp.argument_expression_list = (A_argument_expression_list)argv[1];
				break;
		case 5: p->u.post_dot_id.postfix_expression = (A_postfix_expression)argv[0];
				p->u.post_dot_id.symbol = (S_symbol)argv[1];
				break;
		case 6: p->u.postfix_expression = (A_postfix_expression)argv[0];
				break;
		case 7: p->u.postfix_expression = (A_postfix_expression)argv[0];
				break;
		case 8:	p->u.lr_tn_rp_il.type_name = (A_type_name)argv[0];
				p->u.lr_tn_rp_il.initializer_list = (A_initializer_list)argv[1];
				break;
		case 9: p->u.lp_tn_rp_il_semi.type_name = (A_type_name)argv[0];
				p->u.lp_tn_rp_il_semi.initializer_list = (A_initializer_list)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}


A_argument_expression_list A_Argument_Expression_List(A_pos pos, int kind, void *argv[])
{
	A_argument_expression_list p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.assignment_expression = (A_assignment_expression)argv[0];
				break;
		case 2: p->u.ael.argument_expression_list = (A_argument_expression_list)argv[0];
				p->u.ael.assignment_expression = (A_assignment_expression)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}


A_unary_expression A_Unary_Expression(A_pos pos, int kind, void *argv[])
{
	A_unary_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.postfix_expression = (A_postfix_expression)argv[0];
				break;
		case 2: p->u.unary_expression = (A_unary_expression)argv[0];
				break;
		case 3: p->u.unary_expression = (A_unary_expression)argv[0];
				break;
		case 4: p->u.lr_tn_rp_il.unary_operator = (A_unary_operator)argv[0];
				p->u.lr_tn_rp_il.cast_expression = (A_cast_expression)argv[1];
				break;
		case 5: p->u.unary_expression = (A_unary_expression)argv[0];
				break;
		case 6: p->u.type_name = (A_type_name)argv[0];
				break;
		default:
				return NULL;	
	}
	return p;
}


A_unary_operator A_Unary_Operator(A_pos pos, int kind, void *argv[])
{
	A_unary_operator p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;

	return p;
}


A_cast_expression A_Cast_Expression(A_pos pos, int kind, void *argv[])
{
	A_cast_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.unary_expression = (A_unary_expression)argv[0];
				break;
		case 2: p->u.tn_ce.type_name = (A_type_name)argv[0];
				p->u.tn_ce.cast_expression = (A_cast_expression)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}

A_multiplicative_expression A_Multiplicative_Expression(A_pos pos, int kind, void *argv[])
{
	A_multiplicative_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.cast_expression = (A_cast_expression)argv[0];
				break;
		case 2: p->u.mul.multiplicative_expression = (A_multiplicative_expression)argv[0];
				p->u.mul.cast_expression = (A_cast_expression)argv[1];
				break;
		case 3: p->u.div.multiplicative_expression = (A_multiplicative_expression)argv[0];
				p->u.div.cast_expression = (A_cast_expression)argv[1];
				break;
		case 4: p->u.mod.multiplicative_expression = (A_multiplicative_expression)argv[0];
				p->u.mod.cast_expression = (A_cast_expression)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}



A_additive_expression A_Additive_Expression(A_pos pos, int kind, void *argv[])
{
	A_additive_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.multiplicative_expression = (A_multiplicative_expression)argv[0];
				break;
		case 2: p->u.add.additive_expression = (A_additive_expression)argv[0];
				p->u.add.multiplicative_expression = (A_multiplicative_expression)argv[1];
				break;
		case 3: p->u.minus.additive_expression = (A_additive_expression)argv[0];
				p->u.minus.multiplicative_expression = (A_multiplicative_expression)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}

A_shift_expression A_Shift_Expression(A_pos pos, int kind, void *argv[])
{
	A_shift_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.additive_expression = (A_additive_expression)argv[0];
				break;
		default:
				return NULL;	
	}
	return p;
}


A_relational_expression A_Relational_Expression(A_pos pos, int kind, void *argv[])
{
	A_relational_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.shift_expression = (A_shift_expression)argv[0];
				break;
		case 2: p->u.lt.relational_expression = (A_relational_expression)argv[0];
				p->u.lt.shift_expression = (A_shift_expression)argv[1];
				break;
		case 3: p->u.gt.relational_expression = (A_relational_expression)argv[0];
				p->u.gt.shift_expression = (A_shift_expression)argv[1];
				break;
		case 4: p->u.le.relational_expression = (A_relational_expression)argv[0];
				p->u.le.shift_expression = (A_shift_expression)argv[1];
				break;
		case 5: p->u.ge.relational_expression = (A_relational_expression)argv[0];
				p->u.ge.shift_expression = (A_shift_expression)argv[1];
				break;

		default:
				return NULL;	
	}
	return p;
}



A_equality_expression A_Equality_Expression(A_pos pos, int kind, void *argv[])
{
	A_equality_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.relational_expression = (A_relational_expression)argv[0];
				break;
		case 2: p->u.eq.equality_expression = (A_equality_expression)argv[0];
				p->u.eq.shift_expression = (A_shift_expression)argv[1];
				break;
		case 3: p->u.neq.equality_expression = (A_equality_expression)argv[0];
				p->u.neq.shift_expression = (A_shift_expression)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}

A_and_expression A_And_Expression(A_pos pos, int kind, void *argv[])
{
	A_and_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.equality_expression = (A_equality_expression)argv[0];
				break;
		case 2: p->u.andd.and_expression = (A_and_expression)argv[0];
				p->u.andd.equality_expression = (A_equality_expression)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}


A_exclusive_or_expression A_Exclusive_Or_Expression(A_pos pos, int kind, void *argv[])
{
	A_exclusive_or_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.and_expression = (A_and_expression)argv[0];
				break;
		case 2: p->u.xorr.exclusive_or_expression = (A_exclusive_or_expression)argv[0];
				p->u.xorr.and_expression = (A_and_expression)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}

A_inclusive_or_expression A_Inclusive_Or_Expression(A_pos pos, int kind, void *argv[])
{
	A_inclusive_or_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.exclusive_or_expression = (A_exclusive_or_expression)argv[0];
				break;
		case 2: p->u.orr.inclusive_or_expression = (A_inclusive_or_expression)argv[0];
				p->u.orr.exclusive_or_expression = (A_exclusive_or_expression)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}


A_logical_and_expression A_Logical_And_Expression(A_pos pos, int kind, void *argv[])
{
	A_logical_and_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.inclusive_or_expression = (A_inclusive_or_expression)argv[0];
				break;
		case 2: p->u.and_op.logical_and_expression = (A_logical_and_expression)argv[0];
				p->u.and_op.inclusive_or_expression = (A_inclusive_or_expression)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}


A_logical_or_expression A_Logical_Or_Expression(A_pos pos, int kind, void *argv[])
{
	A_logical_or_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.logical_and_expression = (A_logical_and_expression)argv[0];
				break;
		case 2: p->u.or_op.logical_or_expression = (A_logical_or_expression)argv[0];
				p->u.or_op.logical_and_expression = (A_logical_and_expression)argv[1];
				break;
		default:
				return NULL;	
	}
	return p;
}

A_conditional_expression A_Conditional_Expression(A_pos pos, int kind, void *argv[])
{
	A_conditional_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.logical_or_expression = (A_logical_or_expression)argv[0];
				break;
		case 2: p->u.cond.logical_or_expression = (A_logical_or_expression)argv[0];
				p->u.cond.expression = (A_expression)argv[1];
				p->u.cond.conditional_expression = (A_conditional_expression)argv[2];
				break;
		default:
				return NULL;	
	}
	return p;
}

A_assignment_expression A_Assignment_Expression(A_pos pos, int kind, void *argv[])
{
	A_assignment_expression p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	switch(kind)
	{
		case 1:	p->u.conditional_expression = (A_conditional_expression)argv[0];
				break;
		case 2: p->u.assignn.unary_expression = (A_unary_expression)argv[0];
				p->u.assignn.assignment_operator = (A_assignment_operator)argv[1];
				p->u.assignn.assignment_expression = (A_assignment_expression)argv[2];
				break;
		default:
				return NULL;	
	}
	return p;
}

A_assignment_operator A_Assignment_Operator(A_pos pos, int kind, void *argv[])
{
	A_assignment_operator p = checked_malloc(sizeof(*p));
	p->kind = kind;
	p->pos = pos;
	return p;
}



/******************************Liu******************************/

A_declaration A_Declaration(A_pos pos, int kind, void *argv[]){
	A_declaration p = checked_malloc(sizeof(*p));
	p->kind = kind;
	switch(kind){

		case 1: p->u.declaration_specifiers = (A_declaration_specifiers)argv[0];
			   	break;
		case 2: p->u.dec2.declaration_specifiers = (A_declaration_specifiers)argv[0];
				p->u.dec2.init_declarator_list = (A_init_declarator_list)argv[1];
				break;

		default:
				return NULL;
	}

	return p;

}


A_declaration_specifiers A_Declaration_Specifiers(A_pos pos, int kind, void *argv[]){
	A_declaration_specifiers p = checked_malloc(sizeof(*p));
	p->kind = kind;
	switch(kind){

		case 1: p->u.type_specifier = (A_type_specifier)argv[0];
				break;
		case 2: p->u.type_s_dec.type_specifier = (A_type_specifier)argv[0];
				p->u.type_s_dec.declaration_specifiers = (A_declaration_specifiers)argv[1];
				break;
		default:
				return NULL;
		
	}

	return p;

}


A_init_declarator_list A_Init_Declarator_List(A_pos pos, int kind, void *argv[]){
	A_init_declarator_list p = checked_malloc(sizeof(*p));
	p->kind = kind;
	switch(kind){

		case 1: p->u.init_declarator = (A_init_declarator)argv[0];
				break;
		case 2: p->u.init_dec_list.init_declarator_list = (A_init_declarator_list)argv[0];
				p->u.init_dec_list.init_declarator = (A_init_declarator)argv[1];
				break;
		default:
				return NULL;
	}

	return p;

}


A_init_declarator A_Init_Declarator(A_pos pos, int kind, void *argv[]){
	A_init_declarator p = checked_malloc(sizeof(*p));
	p->kind = kind;
	switch(kind){

		case 1: p->u.declarator = (A_declarator)argv[0];
				break;
		case 2: p->u.init_dec2.declarator = (A_declarator)argv[0];
				p->u.init_dec2.initializer = (A_initializer)argv[1];
				break;
		default:
				return NULL;

	}

	return p;
	
}


A_type_specifier A_Type_Specifier(A_pos pos, int kind, void *argv[]){
	A_type_specifier p = checked_malloc(sizeof(*p));
	p->kind = kind;

	return p;
}


A_specifier_qualifier_list A_Specifier_Qualifier_List(A_pos pos, int kind, void *argv[]){
	A_specifier_qualifier_list p = checked_malloc(sizeof(*p));
	p->kind = kind;
	switch(kind){

		case 1: p->u.type_specifier = (A_type_specifier)argv[0];
				break;
		case 2: p->u.sql.type_specifier = (A_type_specifier)argv[0];
				p->u.sql.specifier_qualifier_list = (A_specifier_qualifier_list)argv[1];
				break;
		default:
				return NULL;

	}

	return p;

}


A_declarator A_Declarator(A_pos pos, int kind, void *argv[]){
	A_declarator p = checked_malloc(sizeof(*p));
	p->kind = kind;
	switch(kind){

		case 1: p->u.direct_declarator = (A_direct_declarator)argv[0];
				break;
		case 2: p->u.dec.pointer = (A_pointer)argv[0];
				p->u.dec.direct_declarator = (A_direct_declarator)argv[1];
				break;
		default:
				return NULL;

	}

	return p;

}




/******************************End Liu******************************/





/******************************MA******************************/
A_translation_unit A_Translation_Unit(A_pos pos, int grammer, void *argv[])
{
	A_translation_unit p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_external_declaration)argv[0];
				break;
		case 2: p->u.u2.u1 = (A_translation_unit)argv[0];
				p->u.u2.u2 = (A_external_declaration)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_external_declaration A_External_Declaration(A_pos, int grammer, void *argv[])
{
	A_external_declaration p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_function_definition)argv[0];
				break;
		case 2: p->u.u2 = (A_declaration)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_direct_declarator A_Direct_Declarator(A_pos pos, int grammer, void *argv[])
{
	A_direct_declarator p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (S_symbol)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_pointer A_Pointer(A_pos pos, int grammer, void *argv[])
{
	A_pointer p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	break;
		case 2:	p->u.u1 = (A_type_qualifier)argv[0];
				break;
		case 3:	p->u.u2 = (A_pointer)argv[0];
				break;
		case 4:	p->u.u3.u1 = (A_type_qualifier_list)argv[0];
				p->u.u3.u2 = (A_pointer)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_type_qualifier_list A_Type_Qualifier_List(A_pos pos, int grammer, void *argv[])
{
	A_type_qualifier_list p = checked_malloc(sizeof(*p));
	p->pos = pos;
	p->grammer = grammer;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_type_qualifier)argv[0];
				break;
		case 2:	p->u.u2.u1 = (A_type_qualifier_list)argv[0];
				p->u.u2.u2 = (A_type_qualifier)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_parameter_type_list A_Parameter_Type_List(A_pos pos, int grammer, void *argv[])
{
	A_parameter_type_list p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u = (A_parameter_list)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_parameter_list A_Parameter_List(A_pos pos, int grammer, void *argv[])
{
	A_parameter_list p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_parameter_declaration)argv[0];
				break;
		case 2:	p->u.u2.u1 = (A_parameter_list)argv[0];
				p->u.u2.u2 = (A_parameter_declaration)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_parameter_declaration A_Parameter_Declaration(A_pos pos, int grammer, void *argv[])
{
	A_parameter_declaration p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1.u1 = (A_declaration_specifiers)argv[0];
				p->u.u1.u2 = (A_declarator)argv[1];
				break;
		case 2:	p->u.u2.u1 = (A_declaration_specifiers)argv[0];
				p->u.u2.u2 = (A_abstract_declarator)argv[1];
				break;
		case 3:	p->u.u3 = (A_declaration_specifiers)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_identifier_list A_Identifier_List(A_pos pos, int grammer, void *argv[])
{
	A_identifier_list p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (S_symbol)argv[0];
				break;
		case 2:	p->u.u2.u1 = (A_identifier_list)argv[0];
				p->u.u2.u2 = (S_symbol)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_type_name A_Type_Name(A_pos pos, int grammer, void *argv[])
{
	A_type_name p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_specifier_qualifier_list)argv[0];
				break;
		case 2:	p->u.u2.u1 = (A_specifier_qualifier_list)argv[0];
				p->u.u2.u2 = (A_abstract_declarator)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_abstract_declarator A_Abstract_Declarator(A_pos pos, int grammer, void *argv[])
{
	A_abstract_declarator p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_pointer)argv[0];
				break;
		case 2:	p->u.u2 = (A_direct_abstract_declarator)argv[0];
				break;
		case 3:	p->u.u3.u1 = (A_pointer)argv[0];
				p->u.u3.u2 = (A_direct_abstract_declarator)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_direct_abstract_declarator A_Direct_Abstract_Declarator(A_pos pos, int grammer, void *argv[])
{
	A_direct_abstract_declarator p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_abstract_declarator)argv[0];
				break;
		case 2:	break;
		case 3:	break;
		case 4:	break;
		case 5:	break;
		case 6:	break;
		case 7:	break;
		case 8:	break;
		case 9:	break;
		case 10:break;
		case 11:break;
		default:
				return NULL;
	}
	
	return p;
}

A_initializer A_Initializer(A_pos pos, int grammer, void *argv[])
{
	A_initializer p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_assignment_expression)argv[0];
				break;
		case 2:	p->u.u2 = (A_initializer_list)argv[0];
				break;
		case 3:	p->u.u3 = (A_initializer_list)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_initializer_list A_Initializer_List(A_pos pos, int grammer, void *argv[])
{
	A_initializer_list p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_initializer)argv[0];
				break;
		case 2:	p->u.u2.u1 = (A_designation)argv[0];
				p->u.u2.u2 = (A_initializer)argv[1];
				break;
		case 3:	p->u.u3.u1 = (A_initializer_list)argv[0];
				p->u.u3.u2 = (A_initializer)argv[1];
				break;
		case 4:	p->u.u4.u1 = (A_initializer_list)argv[0];
				p->u.u4.u2 = (A_designation)argv[1];
				p->u.u4.u3 = (A_initializer)argv[2];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_designation A_Designation(A_pos pos, int grammer, void *argv[])
{
	A_designation p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u = (A_designator_list)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_designator_list A_Designator_List(A_pos pos, int grammer, void *argv[])
{
	A_designator_list p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_declarator)argv[0];
				break;
		case 2:	p->u.u2.u1 = (A_designator_list)argv[0];
				p->u.u2.u2 = (A_designator)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_designator A_Designator(A_pos pos, int grammer, void *argv[])
{
	A_designator p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_constant_expression)argv[0];
				break;
		case 2:	p->u.u2 = (S_symbol)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_statement A_Statement(A_pos pos, int grammer, void *argv[])
{
	A_statement p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_labeled_statement)argv[0];
				break;
		case 2:	p->u.u2 = (A_compound_statement)argv[0];
				break;
		case 3:	p->u.u3 = (A_expression_statement)argv[0];
				break;
		case 4:	p->u.u4 = (A_selection_statement)argv[0];
				break;
		case 5:	p->u.u5 = (A_iteration_statement)argv[0];
				break;
		case 6:	p->u.u6 = (A_jump_statement)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_labeled_statement A_Labeled_Statement(A_pos pos, int grammer, void *argv[])
{
	A_labeled_statement p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1.u1 = (S_symbol)argv[0];
				p->u.u1.u2 = (A_statement)argv[1];
				break;
		case 2:	p->u.u2.u1 = (A_constant_expression)argv[0];
				p->u.u2.u2 = (A_statement)argv[1];
				break;
		case 3:	p->u.u3 = (A_statement)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_compound_statement A_Compound_Statement(A_pos pos, int grammer, void *argv[])
{
	A_compound_statement p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:break;
		case 2:	p->u = (A_block_item_list)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_block_item_list A_Block_Item_List(A_pos pos, int grammer, void *argv[])
{
	A_block_item_list p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_block_item)argv[0];
				break;
		case 2:	p->u.u2.u1 = (A_block_item_list)argv[0];
				p->u.u2.u2 = (A_block_item)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_block_item A_Block_Item(A_pos pos, int grammer, void *argv[])
{
	A_block_item p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_declaration)argv[0];
				break;
		case 2:	p->u.u2 = (A_statement)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_expression_statement A_Expression_Statement(A_pos pos, int grammer, void *argv[])
{
	A_expression_statement p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1: break;
		case 2:	p->u = (A_expression)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_selection_statement A_Selection_Statement(A_pos pos, int grammer, void *argv[])
{
	A_selection_statement p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1.u1 = (A_expression)argv[0];
				p->u.u1.u2 = (A_statement)argv[1];
				break;
		case 2:	p->u.u2.u1 = (A_expression)argv[0];
				p->u.u2.u2 = (A_statement)argv[1];
				p->u.u2.u3 = (A_statement)argv[2];
				break;
		case 3:	p->u.u3.u1 = (A_expression)argv[0];
				p->u.u3.u2 = (A_statement)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_iteration_statement A_Iteration_Statement(A_pos pos, int grammer, void *argv[])
{
	A_iteration_statement p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1.u1 = (A_expression)argv[0];
				p->u.u1.u2 = (A_statement)argv[1];
				break;
		case 2:	p->u.u2.u1 = (A_statement)argv[0];
				p->u.u2.u2 = (A_expression)argv[1];
				break;
		case 3:	p->u.u3.u1 = (A_expression_statement)argv[0];
				p->u.u3.u2 = (A_expression_statement)argv[1];
				p->u.u3.u3 = (A_statement)argv[2];
				break;
		case 4:	p->u.u4.u1 = (A_expression_statement)argv[0];
				p->u.u4.u2 = (A_expression_statement)argv[1];
				p->u.u4.u3 = (A_expression)argv[2];
				p->u.u4.u4 = (A_statement)argv[3];
				break;
		case 5:	p->u.u5.u1 = (A_declaration)argv[0];
				p->u.u5.u2 = (A_expression_statement)argv[1];
				p->u.u5.u3 = (A_statement)argv[2];
				break;
		case 6:	p->u.u6.u1 = (A_declaration)argv[0];
				p->u.u7.u2 = (A_expression_statement)argv[1];
				p->u.u7.u3 = (A_expression)argv[2];
				p->u.u7.u4 = (A_statement)argv[3];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_jump_statement A_Jump_Statement(A_pos pos, int grammer, void *argv[])
{
	A_jump_statement p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (S_symbol)argv[0];
				break;
		case 2:	break;
		case 3:	break;
		case 4:	break;
		case 5:	p->u.u5 = (A_expression)argv[0];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_function_definition A_Function_Definition(A_pos pos, int grammer, void *argv[])
{
	A_function_definition p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1.u1 = (A_declaration_specifiers)argv[0];
				p->u.u1.u2 = (A_declarator)argv[1];
				p->u.u1.u3 = (A_declaration_list)argv[2];
				p->u.u1.u4 = (A_compound_statement)argv[3];
				break;
		case 2:	p->u.u2.u1 = (A_declaration_specifiers)argv[0];
				p->u.u2.u2 = (A_declarator)argv[1];
				p->u.u2.u3 = (A_compound_statement)argv[2];
				break;
		default:
				return NULL;
	}
	
	return p;
}

A_declaration_list A_Declaration_List(A_pos pos, int grammer, void *argv[])
{
	A_declaration_list p = checked_malloc(sizeof(*p));
	p->grammer = grammer;
	p->pos = pos;
	switch(grammer)
	{
		case 1:	p->u.u1 = (A_declaration)argv[0];
				break;
		case 2:	p->u.u2.u1 = (A_declaration_list)argv[0];
				p->u.u2.u2 = (A_declaration)argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}
/******************************END*****************************/










































#endif