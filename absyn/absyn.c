#ifndef ABSYN_H
#define ABSYN_H

#include"absyn.h"

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