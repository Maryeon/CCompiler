#include "absyn.h"
#include "util.h"
#include "symbol.h" 
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

A_exp A_VarExp(A_pos pos, A_var var)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_varExp;
	p->pos = pos;
	p->u.var = var;
	return p;
}

A_exp A_NilExp(A_pos pos)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_nilExp;
	p->pos = pos;
	return p;
}

A_exp A_CallExp(A_pos pos, S_symbol func, A_expList args)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_callExp;
	p->pos = pos;
	p->func = func;
	p->args = args;
	return p;
}

A_exp A_OpExp(A_pos pos, A_oper oper, A_exp left, A_exp right)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_opExp;
	p->pos = pos;
	p->oper = oper;
	p->left = left;
	p->right = right;
	return p;
}

A_exp A_SeqExp(A_pos pos)
{
	A_exp p =checked_malloc(sizeof(*p));
	p->kind = A_seqExp;
	p->pos = pos;
	return p;
} 

A_exp A_AssignExp(A_pos pos, A_var var, A_exp exp)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_assignExp;
	p->pos = pos;
	p->var = var;
	p->exp = exp;
	return p;
}

A_exp A_BoolExp(A_pos pos, bool booll)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_boolExp;
	p->pos = pos;
	p->booll = booll;
	return p;
}

A_exp A_BreakExp(A_pos pos)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_breakExp;
	p->pos = pos;
	return p;
}

A_exp A_CharExp(A_pos pos, char charr)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_charExp;
	p->pos = pos;
	p->charr = charr;
	return p;
}
A_exp A_ContinueExp(A_pos pos)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_continueExp;
	p->pos = pos;
	return p;
}	

A_exp A_DowhileExp(A_pos pos, A_exp test, A_exp body)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_dowhileExp;
	p->pos = pos;
	p->test = test;
	p->body = body;
	return p;
}

A_exp A_DoubleExp(A_pos pos, double doublee)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_doubleExp;
	p->pos = pos;
	p->doublee = doublee;
	return p;
}

A_exp A_IfelseExp(A_pos pos, A_exp test, A_exp then, A_exp elsee)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_ifelseExp;
	p->pos = pos;
	p->test = test;
	p->then = then;
	p->elsee = elsee;
	return p;
}
		
A_exp A_FloatExp(A_pos pos, float floatt)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_floatExp;
	p->pos = pos;
	p->floatt = floatt;
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

A_exp A_SizeofExp(A_pos pos, S_symbol typ)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_SizeofExp;
	p->pos = pos;
	p->typ = typ;
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

