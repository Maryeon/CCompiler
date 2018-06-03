<<<<<<< HEAD
#include "absyn.h"

A_expList A_ExpList(A_exp head, A_expList tail)
{A_expList p = checked_malloc(sizeof(*p));
 p->head=head;
 p->tail=tail;
 return p;
}

A_fundecList A_FundecList(A_fundec head, A_fundecList tail)
{A_fundecList p = checked_malloc(sizeof(*p));
 p->head=head;
 p->tail=tail;
 return p;
}

A_dec A_FunctionDec(A_pos pos, A_fundecList function)
{A_dec p = checked_malloc(sizeof(*p));
 p->kind=A_functionDec;
 p->pos=pos;
 p->u.function=function;
 return p;
}

A_dec A_VarDec(A_pos pos, S_symbol var, A_expList init)
{A_dec p = checked_malloc(sizeof(*p));
 p->kind=A_varDec;
 p->pos=pos;
 p->u.var.var=var;
 p->u.var.init=init;
 p->u.var.escape=TRUE;
 return p;
}
=======
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
>>>>>>> b54c9cda79f81a1045c075c7a8f0aca5adee7136
