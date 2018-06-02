typedef int A_pos;

typedef struct A_var_ *A_var;
struct A_var_{
	enum{A_simpleVar, A_subscriptVar} kind;
	A_pos pos;
	union{	S_symbol simple;
			struct{	A_var var;
					A_exp exp;} subscript;
    }u;
};