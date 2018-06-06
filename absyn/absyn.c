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
		case 2: p->u.u2.u1 = argv[0];
				p->u.u2.u2 = argv[1];
				break;
		default:
				break;
	}
	
	return p;
}
/******************************END*****************************/

#endif