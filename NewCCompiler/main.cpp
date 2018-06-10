#include <stdio.h>
#include <stdlib.h>
#include "absyn.h"
#include "CodeGen.h"
#include "ObjGen.h"

extern FILE* yyin;
extern shared_ptr<Block> programBlock;
extern int yyparse();

int main()
{
	yyin = fopen("test.c", "r");
	if(!yyin)
	{
		printf("Cannot Open the File!\n");
		exit(0);
	}
	yyparse();

	//programBlock->print("--");
    	
	//    cout << root;

	//    cout << root << endl;
    CodeGenContext context;
	//    createCoreFunctions(context);
    context.generateCode(*programBlock);


	return 0;
}
