typedef int A_pos;
typedef struct A_fundec_ *A_fundec;
typedef struct A_fundecList_ *A_fundecList;
typedef struct A_nametyList_ *A_nametyList;

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
    {enum {A_functionDec, A_varDec, A_arrvarDec} kind;
     A_pos pos;
     union {A_fundecList function;
        /* escape may change after the initial declaration */
        struct {S_symbol var; S_symbol typ; A_exp init; bool escape;} var;
      } u;
   };

struct A_exp_
      {enum {A_varExp, 
	    A_nilExp, 
		A_callExp, 
		A_opExp, 
		A_seqExp, 
		A_assignExp,
		A_boolExp,			
		A_breakExp,				
		A_charExp,		
		A_continueExp,		
		A_dowhileExp,	
		A_doubleExp,		
		A_ifelseExp,				
		A_floatExp,		
		A_forExp,		
		A_ifExp,			
		A_intExp,		
		A_returnExp,			
		A_sizeofExp,			
		A_whileExp
		   } kind;
       A_pos pos;
       union {A_var var;
	      /* nil; - needs only the pos */
		  struct {S_symbol func; A_expList args;} call;
		  struct {A_oper oper; A_exp left; A_exp right;} op;
		  A_expList seq;
		  struct {A_var var; A_exp exp;} assign;
		  bool booll;
		  /* breakk; - need only the pos */
		  char charr;
		  /* continue; - need only the pos */
		  struct {A_exp test, body;} dowhile;
		  double doublee;
		  struct {A_exp test, then, elsee;} ifelse;
		  float floatt;
		  struct {A_exp init, test, last, body;} forr;
		  struct {A_exp test, then;} iff;	
		  int intt;
		  struct {A_exp ret;} returnn;
		  struct {A_exp type) signedd;
		  struct {string type} sizeoff;
		  struct {A_exp test, body;} whilee;	
	    } u;
     };

/* Function Prototypes */
A_var A_SimpleVar(A_pos pos, S_symbol sym);
A_var A_SubscriptVar(A_pos pos, A_var var, A_exp exp);
A_dec A_FunctionDec(A_pos pos, A_fundecList function);
A_dec A_VarDec(A_pos pos, S_symbol var, A_exp init);
A_dec A_arrVarDec(A_pos pos, S_symbol var, A_exp init);
A_exp A_VarExp(A_pos pos, A_var var);
A_exp A_NilExp(A_pos pos); 
A_exp A_CallExp(A_pos pos, S_symbol func, A_expList args); 
A_exp A_OpExp(A_pos pos, A_oper oper, A_exp left, A_exp right); 
A_exp A_SeqExp(A_pos pos); 
A_exp A_AssignExp(A_pos pos, A_var var, A_exp exp);
A_exp A_BoolExp(A_pos pos, bool booll);			
A_exp A_BreakExp(A_pos pos);				
A_exp A_CharExp(A_pos pos, char charr);		
A_exp A_ContinueExp(A_pos pos);		
A_exp A_DowhileExp(A_pos pos, A_exp test, A_exp body);	
A_exp A_DoubleExp(A_pos pos, double doublee);		
A_exp A_IfelseExp(A_pos pos, A_exp test, A_exp then, A_exp elsee);				
A_exp A_FloatExp(A_pos pos, float floatt);		
A_exp A_ForExp(A_pos pos, A_exp init, A_exp test, A_exp last, A_exp body);		
A_exp A_IfExp(A_pos pos, A_exp test, A_exp then);			
A_exp A_IntExp(A_pos pos, int intt);				
A_exp A_returnExp(A_pos pos, A_exp exp);			
A_exp A_sizeofExp(A_pos pos, string type);	 			
A_exp A_whileExp(A_pos pos, A_exp test, A_exp body);	
