#include "absyn.h"



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
} 

A_exp A_AssignExp(A_pos pos, A_var var, A_exp exp)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_assignExp;
	p->pos = pos;
	p->var = var;
	p->exp = exp;
}

A_exp A_BoolExp(A_pos pos, bool booll)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_boolExp;
	p->pos = pos;
	p->booll = booll;
}

A_exp A_BreakExp(A_pos pos)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_breakExp;
	p->pos = pos;
}

A_exp A_CharExp(A_pos pos, char charr)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_charExp;
	p->pos = pos;
	p->charr = charr;
}
A_exp A_ContinueExp(A_pos pos)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_continueExp;
	p->pos = pos;
}	

A_exp A_DowhileExp(A_pos pos, A_exp test, A_exp body)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_dowhileExp;
	p->pos = pos;
	p->test = test;
	p->body = body;
}

A_exp A_DoubleExp(A_pos pos, double doublee)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_doubleExp;
	p->pos = pos;
	p->doublee = doublee;
}

A_exp A_IfelseExp(A_pos pos, A_exp test, A_exp then, A_exp elsee)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_ifelseExp;
	p->pos = pos;
	p->test = test;
	p->then = then;
	p->elsee = elsee;
}
		
A_exp A_FloatExp(A_pos pos, float floatt)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_floatExp;
	p->pos = pos;
	p->floatt = floatt;
}	
		
A_exp A_SizeofExp(A_pos pos, S_symbol typ)
{
	A_exp p = checked_malloc(sizeof(*p));
	p->kind = A_SizeofExp;
	p->pos = pos;
	p->typ = typ;
}	