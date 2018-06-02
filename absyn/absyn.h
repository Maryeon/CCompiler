typedef int A_pos;
typedef struct A_fundec_ *A_fundec;
typedef struct A_fundecList_ *A_fundecList;
typedef struct A_nametyList_ *A_nametyList;
A_dec A_FunctionDec(A_pos pos, A_fundecList function);
A_dec A_VarDec(A_pos pos, S_symbol var, S_symbol typ, A_exp init);

typedef enum {A_addOp, A_subOp, A_mulOp, A_divOp,
            A_add_assignOp, A_sub_assignOp, A_mul_assignOp,A_div_assignOp,
            A_mod_assignOp,A_or_assignOp, A_and_assignOp,A_xor_assignOp,
            A_incOp, A_decOp,A_ptrOp, A_andOp, A_orOp, A_leOp, A_geOp,
            A_eqOp,A_neOp, A_equal_sign_Op,A_ltOp,A_gtOp,
            A_single_andOp,A_single_orOp,A_exclamatoryOp,A_single_neOp,
            A_modOp, A_single_xorOp
             } A_oper;

typedef struct A_var_ *A_var;
struct A_var_{
	enum{A_simpleVar, A_subscriptVar} kind;
	A_pos pos;
	union{	S_symbol simple;
			struct{	A_var var;
					A_exp exp;} subscript;
    }u;
};

struct A_dec_ 
    {enum {A_functionDec, A_varDec} kind;
     A_pos pos;
     union {A_fundecList function;
        /* escape may change after the initial declaration */
        struct {S_symbol var; S_symbol typ; A_exp init; bool escape;} var;
        A_nametyList type;
      } u;
   };