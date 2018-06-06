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
		case 1:	p->u.u1 = argv[0];
				break;
		case 2: p->u.u2 = argv[1];
				break;
		default:
				return NULL;
	}
	
	return p;
}
/******************************END*****************************/

#endif