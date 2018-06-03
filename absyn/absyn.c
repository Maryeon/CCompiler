#include "absyn.h"
#include <stdlib.h>

A_var A_SimpleVar(A_pos pos, S_symbol sym)
{
	A_var p = (A_var)checked_malloc(sizeof(*p));
	p->kind = A_simpleVar;
	p->pos = pos;
	p->u.simple = sym;
	return p;
}

A_var A_SubscriptVar(A_pos pos, A_var var, A_exp exp)
{
	A_var p = (A_var)checked_malloc(sizeof(*p));
	p->kind = A_subscriptVar;
	p->pos = pos;
	p->u.subscript.var = var;
	p->u.subscript.exp = exp;
	return p;
}