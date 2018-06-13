#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "absyn.h"
#include "IntermediateCodeGen/CodeGen.h"
#include "ObjGen/ObjGen.h"

extern FILE* yyin;
extern shared_ptr<Block> programBlock;
extern int yyparse();

int main()
{
	yyin = fopen("Test/test.c", "r");
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
    ObjGen(context);

	return 0;
}
