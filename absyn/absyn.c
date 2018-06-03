#include "absyn.h"
#include <stdlib.h>

A_var A_SimpleVar(A_pos pos, S_symbol sym)
{
	A_var p = checked_malloc(sizeof(*p));
	p->kind = A_simpleVar;
	p->pos = pos;
	p->u.simple = sym;
	return p;
}

A_var A_SubscriptVar(A_pos pos, A_var var, A_exp exp)
{
	A_var p = checked_malloc(sizeof(*p));
	p->kind = A_subscriptVar;
	p->pos = pos;
	p->u.subscript.var = var;
	p->u.subscript.exp = exp;
	return p;
}

A_exp A_ForExp(A_pos pos, A_exp init, A_exp test, A_exp last, A_exp body)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_forExp;
	p->pos = pos;
	p->forr.init = init;
	p->forr.test = test;
	p->forr.last = last;
	p->forr.body = body;
	return p;
}

A_exp A_IfExp(A_pos pos, A_exp test, A_exp then)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_ifExp;
	p->iff.test = test;
	p->iff.then = then;
	return p;
}

A_exp A_IntExp(A_pos pos, int intt)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_intExp;
	p->intt = intt;
	return p;
}

A_exp A_ReturnExp(A_pos pos, A_exp ret)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_returnExp;
	p->returnn.ret = ret;
	return p;
}

A_exp A_WhileExp(A_pos pos, A_exp test, A_exp body)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_whileExp;
	p->whilee.test = test;
	p->whilee.body = body;
	return p;
}