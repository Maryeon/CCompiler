#include <stdio.h>
#include <stdlib.h>

extern FILE* yyin;
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

	return 0;
}
