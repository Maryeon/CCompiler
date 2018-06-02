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

struct A_exp_
      {enum {A_varExp, A_nilExp, A_callExp, A_opExp, A_seqExp, 
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
		A_longExp,		
		A_returnExp,	
		A_shortExp,			
		A_signedExp,		
		A_sizeofExp,	 		
		A_typedefExp,		
		A_unsignedExp,		
		A_voidExp,			
		A_whileExp,	
		A_arrayExp
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
		  long longg;
		  /* return; - need only the pos */
		  short shortt;
		  struct {A_exp type) signedd;
		  struct {string type} sizeoff;
		  struct {string type, astype} typedeff;
		  struct {A_exp type) unsignedd;
		  struct {A_exp test, body;} whilee;	
		  struct {S_symbol typ; A_exp size, init;} array;
	    } u;
     };
