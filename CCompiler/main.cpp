#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include "absyn.h"
#include "IntermediateCodeGen/CodeGen.h"
#include "ObjGen/ObjGen.h"

extern FILE* yyin;
extern Block* programBlock;
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

	char path[100];
	char command[100] = {"bash "};
	treeDisplay(programBlock);
	
	getcwd(path, sizeof(path));
	strcat(path, "/TreeDisplay/transfer.sh");
	strcat(command, path);
	

    	CodeGenContext context;
	//    createCoreFunctions(context);
    	context.generateCode(*programBlock);
   		ObjGen(context);
	   system(command);

	return 0;
}
