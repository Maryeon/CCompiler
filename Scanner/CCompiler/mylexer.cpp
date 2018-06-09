/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 8 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.cpp
* C++ source file generated from mylexer.l.
* 
* Date: 06/10/18
* Time: 02:03:59
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\mylexer.l"

/*C Declarations: */
#include <stdio.h>
#include "parser.h"
#include <string>

void count(void);

#line 47 "mylexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\mylexer.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 23 ".\\mylexer.l"
 comment(); 
#line 130 "mylexer.cpp"
		}
		break;
	case 2:
		{
#line 24 ".\\mylexer.l"
 /* consume //-comment */ 
#line 137 "mylexer.cpp"
		}
		break;
	case 3:
		{
#line 27 ".\\mylexer.l"
 count(); yylval.stringg = new string(yytext); return BOOL; 
#line 144 "mylexer.cpp"
		}
		break;
	case 4:
		{
#line 28 ".\\mylexer.l"
 count(); yylval.stringg = new string(yytext); return CHAR; 
#line 151 "mylexer.cpp"
		}
		break;
	case 5:
		{
#line 29 ".\\mylexer.l"
 count(); yylval.stringg = new string(yytext); return DOUBLE; 
#line 158 "mylexer.cpp"
		}
		break;
	case 6:
		{
#line 30 ".\\mylexer.l"
 count(); yylval.token = ELSE; return ELSE; 
#line 165 "mylexer.cpp"
		}
		break;
	case 7:
		{
#line 31 ".\\mylexer.l"
 count(); yylval.stringg = new string(yytext); return FLOAT; 
#line 172 "mylexer.cpp"
		}
		break;
	case 8:
		{
#line 32 ".\\mylexer.l"
 count(); yylval.token = FOR; return FOR; 
#line 179 "mylexer.cpp"
		}
		break;
	case 9:
		{
#line 33 ".\\mylexer.l"
 count(); yylval.token = IF; return IF; 
#line 186 "mylexer.cpp"
		}
		break;
	case 10:
		{
#line 34 ".\\mylexer.l"
 count(); yylval.stringg = new string(yytext); return INT; 
#line 193 "mylexer.cpp"
		}
		break;
	case 11:
		{
#line 35 ".\\mylexer.l"
 count(); yylval.token = RETURN; return RETURN; 
#line 200 "mylexer.cpp"
		}
		break;
	case 12:
		{
#line 36 ".\\mylexer.l"
 count(); yylval.token = STRUCT; return STRUCT; 
#line 207 "mylexer.cpp"
		}
		break;
	case 13:
		{
#line 37 ".\\mylexer.l"
 count(); yylval.stringg = new string(yytext); return VOID ; 
#line 214 "mylexer.cpp"
		}
		break;
	case 14:
		{
#line 38 ".\\mylexer.l"
 count(); yylval.token = WHILE; return WHILE; 
#line 221 "mylexer.cpp"
		}
		break;
	case 15:
		{
#line 40 ".\\mylexer.l"
 count(); yylval.stringg = new string(yytext); return IDENTIFIER;
#line 228 "mylexer.cpp"
		}
		break;
	case 16:
		{
#line 46 ".\\mylexer.l"
 count(); yylval.stringg = new string(yytext); return CONSTANT_INT;
#line 235 "mylexer.cpp"
		}
		break;
	case 17:
		{
#line 60 ".\\mylexer.l"
 count(); yylval.stringg = new string(yytext); return CONSTANT_DOUBLE; /*¸¡µãÊý*/
#line 242 "mylexer.cpp"
		}
		break;
	case 18:
		{
#line 67 ".\\mylexer.l"
 count(); yylval.stringg = new string(yytext); return STRING_LITERAL; 
#line 249 "mylexer.cpp"
		}
		break;
	case 19:
		{
#line 69 ".\\mylexer.l"
 count(); yylval.token = ADD_ASSIGN; return ADD_ASSIGN; 
#line 256 "mylexer.cpp"
		}
		break;
	case 20:
		{
#line 70 ".\\mylexer.l"
 count(); yylval.token = SUB_ASSIGN; return SUB_ASSIGN; 
#line 263 "mylexer.cpp"
		}
		break;
	case 21:
		{
#line 71 ".\\mylexer.l"
 count(); yylval.token = MUL_ASSIGN; return MUL_ASSIGN; 
#line 270 "mylexer.cpp"
		}
		break;
	case 22:
		{
#line 72 ".\\mylexer.l"
 count(); yylval.token = DIV_ASSIGN; return DIV_ASSIGN; 
#line 277 "mylexer.cpp"
		}
		break;
	case 23:
		{
#line 73 ".\\mylexer.l"
 count(); yylval.token = MOD_ASSIGN; return MOD_ASSIGN; 
#line 284 "mylexer.cpp"
		}
		break;
	case 24:
		{
#line 74 ".\\mylexer.l"
 count(); yylval.token = AND_ASSIGN; return AND_ASSIGN; 
#line 291 "mylexer.cpp"
		}
		break;
	case 25:
		{
#line 75 ".\\mylexer.l"
 count(); yylval.token = XOR_ASSIGN; return XOR_ASSIGN; 
#line 298 "mylexer.cpp"
		}
		break;
	case 26:
		{
#line 76 ".\\mylexer.l"
 count(); yylval.token = OR_ASSIGN; return OR_ASSIGN; 
#line 305 "mylexer.cpp"
		}
		break;
	case 27:
		{
#line 77 ".\\mylexer.l"
 count(); yylval.token = LE_OP; return LE_OP; 
#line 312 "mylexer.cpp"
		}
		break;
	case 28:
		{
#line 78 ".\\mylexer.l"
 count(); yylval.token = GE_OP; return GE_OP; 
#line 319 "mylexer.cpp"
		}
		break;
	case 29:
		{
#line 79 ".\\mylexer.l"
 count(); yylval.token = EQ_OP; return EQ_OP; 
#line 326 "mylexer.cpp"
		}
		break;
	case 30:
		{
#line 80 ".\\mylexer.l"
 count(); yylval.token = NE_OP; return NE_OP; 
#line 333 "mylexer.cpp"
		}
		break;
	case 31:
		{
#line 81 ".\\mylexer.l"
 count(); yylval.token = SEMICOLON; return SEMICOLON; 
#line 340 "mylexer.cpp"
		}
		break;
	case 32:
		{
#line 82 ".\\mylexer.l"
 count(); yylval.token = LBRACE; return LBRACE; 
#line 347 "mylexer.cpp"
		}
		break;
	case 33:
		{
#line 83 ".\\mylexer.l"
 count(); yylval.token = RBRACE; return RBRACE; 
#line 354 "mylexer.cpp"
		}
		break;
	case 34:
		{
#line 84 ".\\mylexer.l"
 count(); yylval.token = COMMA; return COMMA; 
#line 361 "mylexer.cpp"
		}
		break;
	case 35:
		{
#line 85 ".\\mylexer.l"
 count(); yylval.token = EQUAL; return EQUAL; 
#line 368 "mylexer.cpp"
		}
		break;
	case 36:
		{
#line 86 ".\\mylexer.l"
 count(); yylval.token = RPAREN; return RPAREN; 
#line 375 "mylexer.cpp"
		}
		break;
	case 37:
		{
#line 87 ".\\mylexer.l"
 count(); yylval.token = LPAREN; return LPAREN; 
#line 382 "mylexer.cpp"
		}
		break;
	case 38:
		{
#line 88 ".\\mylexer.l"
 count(); yylval.token = LBRACKET; return LBRACKET; 
#line 389 "mylexer.cpp"
		}
		break;
	case 39:
		{
#line 89 ".\\mylexer.l"
 count(); yylval.token = RBRACKET; return RBRACKET; 
#line 396 "mylexer.cpp"
		}
		break;
	case 40:
		{
#line 90 ".\\mylexer.l"
 count(); yylval.token = DOT; return DOT; 
#line 403 "mylexer.cpp"
		}
		break;
	case 41:
		{
#line 91 ".\\mylexer.l"
 count(); yylval.token = AND_OP; return AND_OP; 
#line 410 "mylexer.cpp"
		}
		break;
	case 42:
		{
#line 92 ".\\mylexer.l"
 count(); yylval.token = MINUS_OP; return MINUS_OP; 
#line 417 "mylexer.cpp"
		}
		break;
	case 43:
		{
#line 93 ".\\mylexer.l"
 count(); yylval.token = PLUS_OP; return PLUS_OP; 
#line 424 "mylexer.cpp"
		}
		break;
	case 44:
		{
#line 94 ".\\mylexer.l"
 count(); yylval.token = MUL_OP; return MUL_OP; 
#line 431 "mylexer.cpp"
		}
		break;
	case 45:
		{
#line 95 ".\\mylexer.l"
 count(); yylval.token = DIV_OP; return DIV_OP; 
#line 438 "mylexer.cpp"
		}
		break;
	case 46:
		{
#line 96 ".\\mylexer.l"
 count(); yylval.token = MOD_OP; return MOD_OP; 
#line 445 "mylexer.cpp"
		}
		break;
	case 47:
		{
#line 97 ".\\mylexer.l"
 count(); yylval.token = LT_OP; return LT_OP; 
#line 452 "mylexer.cpp"
		}
		break;
	case 48:
		{
#line 98 ".\\mylexer.l"
 count(); yylval.token = GT_OP; return GT_OP; 
#line 459 "mylexer.cpp"
		}
		break;
	case 49:
		{
#line 99 ".\\mylexer.l"
 count(); yylval.token = XOR_OP; return XOR_OP; 
#line 466 "mylexer.cpp"
		}
		break;
	case 50:
		{
#line 100 ".\\mylexer.l"
 count(); yylval.token = OR_OP; return OR_OP; 
#line 473 "mylexer.cpp"
		}
		break;
	case 51:
		{
#line 102 ".\\mylexer.l"
 count(); 
#line 480 "mylexer.cpp"
		}
		break;
	case 52:
		{
#line 103 ".\\mylexer.l"
 printf("Unknown token:%s\n", yytext); yyterminate(); 
#line 487 "mylexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 287;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 4, 1 },
		{ 4, 1 },
		{ 4, 1 },
		{ 4, 1 },
		{ 62, 28 },
		{ 68, 33 },
		{ 66, 32 },
		{ 50, 16 },
		{ 92, 75 },
		{ 67, 32 },
		{ 92, 75 },
		{ 63, 29 },
		{ 51, 16 },
		{ 69, 33 },
		{ 64, 30 },
		{ 65, 31 },
		{ 46, 8 },
		{ 78, 77 },
		{ 47, 11 },
		{ 70, 34 },
		{ 71, 35 },
		{ 72, 36 },
		{ 79, 56 },
		{ 4, 1 },
		{ 5, 1 },
		{ 6, 1 },
		{ 52, 16 },
		{ 73, 37 },
		{ 7, 1 },
		{ 8, 1 },
		{ 74, 39 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 15, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 18, 1 },
		{ 78, 77 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 22, 1 },
		{ 80, 56 },
		{ 48, 12 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 24, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 25, 1 },
		{ 0, 44 },
		{ 26, 1 },
		{ 27, 1 },
		{ 23, 1 },
		{ 0, 51 },
		{ 23, 1 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 33, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 36, 1 },
		{ 37, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 23, 1 },
		{ 38, 1 },
		{ 39, 1 },
		{ 40, 1 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 49, 14 },
		{ 41, 5 },
		{ 77, 55 },
		{ 45, 7 },
		{ 77, 57 },
		{ 81, 62 },
		{ 82, 63 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 43, 42 },
		{ 83, 64 },
		{ 84, 65 },
		{ 85, 66 },
		{ 23, 110 },
		{ 86, 67 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 23, 110 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 18, 18 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 93, 93 },
		{ 87, 69 },
		{ 0, 92 },
		{ 88, 70 },
		{ 89, 71 },
		{ 90, 72 },
		{ 91, 73 },
		{ 44, 42 },
		{ 0, 92 },
		{ 55, 18 },
		{ 58, 20 },
		{ 59, 21 },
		{ 78, 79 },
		{ 76, 93 },
		{ 78, 80 },
		{ 94, 81 },
		{ 95, 82 },
		{ 96, 83 },
		{ 56, 18 },
		{ 76, 93 },
		{ 97, 84 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 53, 53 },
		{ 98, 85 },
		{ 99, 88 },
		{ 100, 89 },
		{ 0, 92 },
		{ 101, 90 },
		{ 102, 91 },
		{ 60, 22 },
		{ 42, 24 },
		{ 103, 96 },
		{ 0, 92 },
		{ 57, 18 },
		{ 75, 53 },
		{ 104, 98 },
		{ 105, 99 },
		{ 76, 93 },
		{ 106, 100 },
		{ 107, 102 },
		{ 108, 103 },
		{ 109, 105 },
		{ 56, 18 },
		{ 76, 93 },
		{ 53, 54 },
		{ 110, 106 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 54, 54 },
		{ 61, 27 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 75, 53 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ -3, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 0, 52 },
		{ 0, 0, 51 },
		{ 0, 68, 52 },
		{ 42, 0, 52 },
		{ 0, 70, 46 },
		{ 0, -44, 41 },
		{ 0, 0, 36 },
		{ 0, 0, 37 },
		{ 0, -42, 44 },
		{ 0, -5, 43 },
		{ 0, 0, 34 },
		{ 0, 67, 42 },
		{ 0, 0, 40 },
		{ 0, -34, 45 },
		{ 54, 0, 52 },
		{ 54, 145, 16 },
		{ 0, 0, 31 },
		{ 0, 161, 47 },
		{ 0, 162, 35 },
		{ 0, 188, 48 },
		{ 110, 0, 15 },
		{ 110, 216, 15 },
		{ 0, 0, 38 },
		{ 0, 0, 39 },
		{ 0, 215, 49 },
		{ 110, -106, 15 },
		{ 110, -92, 15 },
		{ 110, -96, 15 },
		{ 110, -92, 15 },
		{ 110, -101, 15 },
		{ 110, -96, 15 },
		{ 110, -81, 15 },
		{ 110, -95, 15 },
		{ 110, -89, 15 },
		{ 110, -76, 15 },
		{ 0, 0, 32 },
		{ 0, -30, 50 },
		{ 0, 0, 33 },
		{ 0, 0, 30 },
		{ 44, 127, 0 },
		{ 0, 0, 18 },
		{ -42, 74, 0 },
		{ 0, 0, 23 },
		{ 0, 0, 24 },
		{ 0, 0, 21 },
		{ 0, 0, 19 },
		{ 0, 0, 20 },
		{ 0, 0, 1 },
		{ -51, 78, 2 },
		{ 0, 0, 22 },
		{ 93, 185, 17 },
		{ 0, 218, 0 },
		{ 77, 54, 16 },
		{ 0, -53, 16 },
		{ 77, 24, 16 },
		{ 0, 0, 27 },
		{ 0, 0, 29 },
		{ 0, 0, 28 },
		{ 0, 0, 25 },
		{ 110, 22, 15 },
		{ 110, 37, 15 },
		{ 110, 45, 15 },
		{ 110, 48, 15 },
		{ 110, 53, 15 },
		{ 110, 52, 15 },
		{ 110, 0, 9 },
		{ 110, 97, 15 },
		{ 110, 99, 15 },
		{ 110, 102, 15 },
		{ 110, 112, 15 },
		{ 110, 113, 15 },
		{ 0, 0, 26 },
		{ 92, -34, 0 },
		{ 0, 0, 17 },
		{ 0, -67, 16 },
		{ 0, 0, 16 },
		{ 0, 148, 16 },
		{ 0, 118, 16 },
		{ 110, 119, 15 },
		{ 110, 114, 15 },
		{ 110, 131, 15 },
		{ 110, 131, 15 },
		{ 110, 146, 15 },
		{ 110, 0, 8 },
		{ 110, 0, 10 },
		{ 110, 127, 15 },
		{ 110, 128, 15 },
		{ 110, 147, 15 },
		{ 110, 140, 15 },
		{ 93, 144, 0 },
		{ 0, 155, 17 },
		{ 110, 0, 3 },
		{ 110, 0, 4 },
		{ 110, 143, 15 },
		{ 110, 0, 6 },
		{ 110, 139, 15 },
		{ 110, 142, 15 },
		{ 110, 159, 15 },
		{ 110, 0, 13 },
		{ 110, 158, 15 },
		{ 110, 159, 15 },
		{ 110, 0, 7 },
		{ 110, 151, 15 },
		{ 110, 149, 15 },
		{ 110, 0, 14 },
		{ 110, 0, 5 },
		{ 110, 0, 11 },
		{ 0, 70, 12 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 105 ".\\mylexer.l"


int yywrap(void)
{
	return 1;
}


void comment(void)
{
	char c, prev = 0;
  
	while ((c = input()) != 0)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	error("unterminated comment");
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
