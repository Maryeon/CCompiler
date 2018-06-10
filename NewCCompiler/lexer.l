%{
/*C Declarations: */
#include <string>
#include <iostream>
#include "parser.tab.h"
#include "absyn.h"

using namespace std;

void count(void);
%}

%option yylineno

/*Lex Definitions: */
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			([Ee][+-]?{D}+)
P           ([Pp][+-]?{D}+)
FS			(f|F|l|L)
IS			((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))

/*Regular Expressions and Actions: */
%%
"/*"H"*/"			{ cout << "comments" << endl;}
"//"[^\n]*              { /* consume //-comment */ }


"bool"			{ count(); yylval.stringg = new string(yytext); return BOOL; }
"char"			{ count(); yylval.stringg = new string(yytext); return CHAR; }
"double"		{ count(); yylval.stringg = new string(yytext); return DOUBLE; }
"else"			{ count(); yylval.token = ELSE; return ELSE; }
"float"			{ count(); yylval.stringg = new string(yytext); return FLOAT; }
"for"			{ count(); yylval.token = FOR; return FOR; }
"if"			{ count(); yylval.token = IF; return IF; }
"int"			{ count(); yylval.stringg = new string(yytext); return INT; }
"return"		{ count(); yylval.token = RETURN; return RETURN; }
"struct"		{ count(); yylval.token = STRUCT; return STRUCT; }
"void"			{ count(); yylval.stringg = new string(yytext); return VOID ; }
"while"			{ count(); yylval.token = WHILE; return WHILE; }

{L}({L}|{D})*		{ count(); yylval.stringg = new string(yytext); return IDENTIFIER;}

[1-9]{D}*{IS}?		{ count(); yylval.stringg = new string(yytext); return CONSTANT_INT;}

{D}+"."{D}*{E}?{FS}?		{ count(); yylval.stringg = new string(yytext); return CONSTANT_DOUBLE; /*¸¡µãÊý*/}


L?\"(\\.|[^\\"\n])*\"	{ count(); yylval.stringg = new string(yytext); return STRING_LITERAL; }

"<="			{ count(); yylval.token = LE_OP; return LE_OP; }
">="			{ count(); yylval.token = GE_OP; return GE_OP; }
"=="			{ count(); yylval.token = EQ_OP; return EQ_OP; }
"!="			{ count(); yylval.token = NE_OP; return NE_OP; }
";"				{ count(); yylval.token = SEMICOLON; return SEMICOLON; }
"{"				{ count(); yylval.token = LBRACE; return LBRACE; }
"}"				{ count(); yylval.token = RBRACE; return RBRACE; }
","				{ count(); yylval.token = COMMA; return COMMA; }
"="				{ count(); yylval.token = EQUAL; return EQUAL; }
"("				{ count(); yylval.token = LPAREN; return LPAREN; }
")"				{ count(); yylval.token = RPAREN; return RPAREN; }
"["				{ count(); yylval.token = LBRACKET; return LBRACKET; }
"]"				{ count(); yylval.token = RBRACKET; return RBRACKET; }
"."				{ count(); yylval.token = DOT; return DOT; }
"&"				{ count(); yylval.token = AND_OP; return AND_OP; }
"-"				{ count(); yylval.token = MINUS_OP; return MINUS_OP; }
"+"				{ count(); yylval.token = PLUS_OP; return PLUS_OP; }
"*"				{ count(); yylval.token = MUL_OP; return MUL_OP; }
"/"				{ count(); yylval.token = DIV_OP; return DIV_OP; }
"%"				{ count(); yylval.token = MOD_OP; return MOD_OP; }
"<"				{ count(); yylval.token = LT_OP; return LT_OP; }
">"				{ count(); yylval.token = GT_OP; return GT_OP; }
"^"				{ count(); yylval.token = XOR_OP; return XOR_OP; }
"|"				{ count(); yylval.token = OR_OP; return OR_OP; }

[ \t\v\n\f]		{ count(); }
.				{ printf("Unknown token:%s\n", yytext); yyterminate(); }

%%

int yywrap(void)
{
	return 1;
}


int column = 0;

void count(void)
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
		{
			column = 0;
		}
		else if (yytext[i] == '\t')
			column += 4 - (column % 4);
		else
			column++;

	ECHO;
}
