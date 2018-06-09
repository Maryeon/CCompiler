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
* parser.h
* C++ header file generated from parser.y.
* 
* Date: 06/10/18
* Time: 02:28:04
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _PARSER_H
#define _PARSER_H

#include <yycpars.h>

#ifndef YYSTYPE
union tagYYSTYPE {
#line 16 ".\\parser.y"

	string *stringg;
	int token;
	
	Block *block;
	Expression *expression;
	Statement *statement;
	Identifier *identifier;
	VariableDeclaration *variabledeclaration;
	ArrayIndex *arrayindex;
	std::vector<shared_ptr<VariableDeclaration>>* variabledeclarationlist;
	std::vector<shared_ptr<Expression>>* expressionlist;

#line 49 "parser.h"
};

#define YYSTYPE union tagYYSTYPE
#endif

#define IDENTIFIER 257
#define STRING_LITERAL 258
#define CONSTANT_INT 259
#define CONSTANT_DOUBLE 260
#define UMINUS 261
#define LE_OP 262
#define GE_OP 263
#define EQ_OP 264
#define NE_OP 265
#define LT_OP 266
#define GT_OP 267
#define MUL_ASSIGN 268
#define DIV_ASSIGN 269
#define MOD_ASSIGN 270
#define ADD_ASSIGN 271
#define SUB_ASSIGN 272
#define AND_ASSIGN 273
#define XOR_ASSIGN 274
#define OR_ASSIGN 275
#define SEMICOLON 276
#define LBRACE 277
#define RBRACE 278
#define COMMA 279
#define EQUAL 280
#define RPAREN 281
#define LPAREN 282
#define LBRACKET 283
#define RBRACKET 284
#define DOT 285
#define AND_OP 286
#define MINUS_OP 287
#define PLUS_OP 288
#define MUL_OP 289
#define DIV_OP 290
#define MOD_OP 291
#define XOR_OP 292
#define OR_OP 293
#define CHAR 294
#define INT 295
#define FLOAT 296
#define DOUBLE 297
#define VOID 298
#define BOOL 299
#define STRUCT 300
#define IF 301
#define ELSE 302
#define WHILE 303
#define FOR 304
#define RETURN 305
#endif
