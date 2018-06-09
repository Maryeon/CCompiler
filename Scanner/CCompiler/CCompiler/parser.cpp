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
* parser.cpp
* C++ source file generated from parser.y.
* 
* Date: 06/10/18
* Time: 02:28:04
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "absyn.h"

using namespace std;

Block *programBlock;
extern FILE* yyin;
extern int yylineno;
void yyerror(char *);
extern int yylex(void);

#line 53 "parser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\parser.h"

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 68 ".\\parser.y"

		programBlock = yyattribute(1 - 1).block;
	
#line 176 "parser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 75 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).block = new Block();
		(*(YYSTYPE YYFAR*)yyvalptr).block->statements->push_back(shared_ptr<Statement>(yyattribute(1 - 1).statement));
	
#line 192 "parser.cpp"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 80 ".\\parser.y"

		yyattribute(1 - 2).block->statements->push_back(shared_ptr<Statement>(yyattribute(2 - 2).statement));
	
#line 207 "parser.cpp"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 87 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = yyattribute(1 - 2).statement;
	
#line 222 "parser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 91 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = yyattribute(1 - 1).statement;
	
#line 237 "parser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 95 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = yyattribute(1 - 2).statement;
	
#line 252 "parser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 99 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new ExpressionStatement(shared_ptr<Expression>(yyattribute(1 - 2).expression));
	
#line 267 "parser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 103 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new ReturnStatement(shared_ptr<Expression>(yyattribute(2 - 3).expression));
	
#line 282 "parser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 107 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = yyattribute(1 - 1).statement;
	
#line 297 "parser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 111 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = yyattribute(1 - 1).statement;
	
#line 312 "parser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 115 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = yyattribute(1 - 1).statement;
	
#line 327 "parser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 122 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).block = yyattribute(2 - 3).block;
	
#line 342 "parser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 126 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).block = new Block();
	
#line 357 "parser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 133 ".\\parser.y"
	
		(*(YYSTYPE YYFAR*)yyvalptr).identifier = new Identifier(*yyattribute(1 - 1).stringg);
		(*(YYSTYPE YYFAR*)yyvalptr).identifier->isType = true;
		delete yyattribute(1 - 1).stringg;
	
#line 374 "parser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 139 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).identifier = new Identifier(*yyattribute(1 - 1).stringg);
		(*(YYSTYPE YYFAR*)yyvalptr).identifier->isType = true;
		delete yyattribute(1 - 1).stringg;
	
#line 391 "parser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 145 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).identifier = new Identifier(*yyattribute(1 - 1).stringg);
		(*(YYSTYPE YYFAR*)yyvalptr).identifier->isType = true;
		delete yyattribute(1 - 1).stringg;
	
#line 408 "parser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 151 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).identifier = new Identifier(*yyattribute(1 - 1).stringg);
		(*(YYSTYPE YYFAR*)yyvalptr).identifier->isType = true;
		delete yyattribute(1 - 1).stringg;
	
#line 425 "parser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 157 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).identifier = new Identifier(*yyattribute(1 - 1).stringg);
		(*(YYSTYPE YYFAR*)yyvalptr).identifier->isType = true;
		delete yyattribute(1 - 1).stringg;
	
#line 442 "parser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 163 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).identifier = new Identifier(*yyattribute(1 - 1).stringg);
		(*(YYSTYPE YYFAR*)yyvalptr).identifier->isType = true;
		delete yyattribute(1 - 1).stringg;
	
#line 459 "parser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 172 ".\\parser.y"

		yyattribute(1 - 4).identifier->isArray = true;
		yyattribute(1 - 4).identifier->arraySize->push_back(make_shared<Interger>(atol(yyattribute(3 - 4).stringg->c_str())));
		(*(YYSTYPE YYFAR*)yyvalptr).identifier = yyattribute(1 - 4).identifier;
	
#line 476 "parser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 178 ".\\parser.y"

		yyattribute(1 - 4).identifier->arraySize = ->push_back(make_shared<Interger>(atol(yyattribute(3 - 4).stringg->c_str())));
		(*(YYSTYPE YYFAR*)yyvalptr).identifier = yyattribute(1 - 4).identifier;
	
#line 492 "parser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 186 ".\\parser.y"

		yyattribute(2 - 2).identifier->isType = true;
		(*(YYSTYPE YYFAR*)yyvalptr).identifier = yyattribute(2 - 2).identifier;
	
#line 508 "parser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 194 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).identifier = yyattribute(1 - 1).identifier;
	
#line 523 "parser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 198 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).identifier = yyattribute(1 - 1).identifier;
	
#line 538 "parser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 202 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).identifier = yyattribute(1 - 1).identifier;
	
#line 553 "parser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 209 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new VariableDeclaration(shared_ptr<Identifier>(yyattribute(1 - 2).identifier), shared_ptr<Identifier>(yyattribute(2 - 2).identifier), NULL);
	
#line 568 "parser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 213 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new VariableDeclaration(shared_ptr<Identifier>(yyattribute(1 - 4).identifier), shared_ptr<Identifier>(yyattribute(2 - 4).identifier), shared_ptr<Expression>(yyattribute(4 - 4).expression));
	
#line 583 "parser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 217 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new ArrayInitialization(make_shared<VariableDeclaration>(shared_ptr<Identifier>(yyattribute(1 - 6).identifier), shared_ptr<Identifier>(yyattribute(2 - 6).identifier), NULL), shared_ptr<ExpressionList>(yyattribute(5 - 6).expressionlist));
	
#line 598 "parser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 224 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new FunctionDeclaration(shared_ptr<Identifier>(yyattribute(1 - 6).identifier), shared_ptr<Identifier>(yyattribute(2 - 6).identifier), shared_ptr<VariableDeclarationList>(yyattribute(4 - 6).variabledeclarationlist), shared_ptr<Block>(yyattribute(6 - 6).block));
	
#line 613 "parser.cpp"
			}
		}
		break;
	case 29:
		{
#line 231 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).variabledeclarationlist = new VariableDeclarationList();
	
#line 623 "parser.cpp"
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 235 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).variabledeclarationlist = new VariableDeclarationList();
		(*(YYSTYPE YYFAR*)yyvalptr).variabledeclarationlist->push_back(shared_ptr<VariableDeclaration>(yyattribute(1 - 1).statement));
	
#line 638 "parser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 240 ".\\parser.y"

		yyattribute(1 - 3).variabledeclarationlist->push_back(shared_ptr<VariableDeclaration>(yyattribute(3 - 3).statement));
		(*(YYSTYPE YYFAR*)yyvalptr).variabledeclarationlist = yyattribute(1 - 3).variabledeclarationlist;
	
#line 654 "parser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 248 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).identifier = new Identifier(*yyattribute(1 - 1).stringg);
		delete yyattribute(1 - 1).stringg;
	
#line 670 "parser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 256 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = new Interger(atol(yyattribute(1 - 1).stringg->c_str()));
	
#line 685 "parser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 260 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = new Double(atof(yyattribute(1 - 1).stringg->c_str()));
	
#line 700 "parser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 267 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = yyattribute(1 - 1).expression;
	
#line 715 "parser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 271 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = new FuntionCall(shared_ptr<Identifier>(yyattribute(1 - 4).identifier), shared_ptr<ExpressionList>(yyattribute(3 - 4).expressionlist));
	
#line 730 "parser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 275 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = yyattribute(1 - 1).identifier;
	
#line 745 "parser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 279 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = new StructMember(shared_ptr<Identifier>(yyattribute(1 - 3).identifier), shared_ptr<Identifier>(yyattribute(3 - 3).identifier));
	
#line 760 "parser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 283 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = yyattribute(1 - 1).expression;
	
#line 775 "parser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 287 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = new BinaryOperation(shared_ptr<Expression>(yyattribute(1 - 3).expression), yyattribute(2 - 3).token, shared_ptr<Expression>(yyattribute(3 - 3).expression));
	
#line 790 "parser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 291 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = yyattribute(2 - 3).expression;
	
#line 805 "parser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 295 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = NULL;
	
#line 820 "parser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 299 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = yyattribute(1 - 1).arrayindex;
	
#line 835 "parser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 303 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = new Literal(*yyattribute(1 - 1).stringg); 
		delete yyattribute(1 - 1).stringg;
	
#line 851 "parser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 311 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).arrayindex = new ArrayIndex(shared_ptr<Identifier>(yyattribute(1 - 4).identifier), shared_ptr<Expression>(yyattribute(3 - 4).expression));
	
#line 866 "parser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 315 ".\\parser.y"

		yyattribute(1 - 4).arrayindex->expressions->push_back(shared_ptr<Expression>(yyattribute(3 - 4).expression));
		(*(YYSTYPE YYFAR*)yyvalptr).arrayindex = yyattribute(1 - 4).arrayindex;
	
#line 882 "parser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 323 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = new Assignment(yyattribute(2 - 3).token, shared_ptr<Identifier>(yyattribute(1 - 3).identifier), shared_ptr<Expression>(yyattribute(3 - 3).expression));
	
#line 897 "parser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 327 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expression = new ArrayAssignment(shared_ptr<ArrayIndex>(yyattribute(1 - 3).arrayindex), yyattribute(2 - 3).token, shared_ptr<Expression>(yyattribute(3 - 3).expression));
	
#line 912 "parser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 331 ".\\parser.y"

		StructMember member = new StructMember(shared_ptr<Identifier>(yyattribute(1 - 5).identifier), shared_ptr<Identifier>(yyattribute(3 - 5).identifier));
		(*(YYSTYPE YYFAR*)yyvalptr).expression = new StructAssignment(member, shared_ptr<Expression>(yyattribute(5 - 5).expression));
	
#line 928 "parser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 339 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 943 "parser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 343 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 958 "parser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 347 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 973 "parser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 351 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 988 "parser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 355 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1003 "parser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 359 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1018 "parser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 363 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1033 "parser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 367 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1048 "parser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 371 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1063 "parser.cpp"
			}
		}
		break;
	case 59:
		{
#line 378 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expressionlist = new ExpressionList();
	
#line 1073 "parser.cpp"
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 382 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).expressionlist = new ExpressionList();
		(*(YYSTYPE YYFAR*)yyvalptr).expressionlist->push_back(shared_ptr<Expression>(yyattribute(1 - 1).expression));
	
#line 1088 "parser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 387 ".\\parser.y"

		yyattribute(1 - 3).expressionlist->push_back(shared_ptr<Expression>(yyattribute(3 - 3).expression));
	
#line 1103 "parser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 394 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1118 "parser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 398 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1133 "parser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 402 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1148 "parser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 406 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1163 "parser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 410 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1178 "parser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 414 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1193 "parser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 418 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1208 "parser.cpp"
			}
		}
		break;
	case 69:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 422 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1223 "parser.cpp"
			}
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 426 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1238 "parser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 430 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1253 "parser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 434 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1268 "parser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 438 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1283 "parser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 442 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1298 "parser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 446 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).token = yyattribute(1 - 1).token;
	
#line 1313 "parser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 453 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new IfStatement(shared_ptr<Expression>(yyattribute(2 - 3).expression), shared_ptr<Block>(yyattribute(3 - 3).block));
	
#line 1328 "parser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 457 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new IfStatement(shared_ptr<Expression>(yyattribute(2 - 5).expression), shared_ptr<Block>(yyattribute(3 - 5).block), shared_ptr<Block>(yyattribute(5 - 5).block));
	
#line 1343 "parser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 461 ".\\parser.y"

		Block block = new Block();
		block->statements->push_back(shared_ptr<Statement>(yyattribute(5 - 5).statement));
		(*(YYSTYPE YYFAR*)yyvalptr).statement = new IfStatement(shared_ptr<Expression>(yyattribute(2 - 5).expression), shared_ptr<Block>(yyattribute(3 - 5).block), shared_ptr<Block>block);
	
#line 1360 "parser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[10];
			yyinitdebug((void YYFAR**)yya, 10);
#endif
			{
#line 470 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new ForStatement(shared_ptr<Expression>(yyattribute(3 - 9).expression), shared_ptr<Expression>(yyattribute(5 - 9).expression), shared_ptr<Expression>(%7), shared_ptr<Block>(yyattribute(9 - 9).block));
	
#line 1375 "parser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 477 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new WhileStatement(shared_ptr<Expression>(yyattribute(3 - 5).expression), shared_ptr<Block>(yyattribute(5 - 5).block));
	
#line 1390 "parser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 484 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).statement = new StructDeclaration(shared_ptr<Identifier>(yyattribute(2 - 5).identifier), shared_ptr<VariableDeclarationList>(yyattribute(4 - 5).variabledeclarationlist));
	
#line 1405 "parser.cpp"
			}
		}
		break;
	case 82:
		{
#line 491 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).variabledeclarationlist = new VariableDeclarationList();
	
#line 1415 "parser.cpp"
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 495 ".\\parser.y"

		(*(YYSTYPE YYFAR*)yyvalptr).variabledeclarationlist = new VariableDeclarationList();
		(*(YYSTYPE YYFAR*)yyvalptr).variabledeclarationlist->push_back(shared_ptr<VariableDeclaration>(yyattribute(1 - 1).statement));
	
#line 1430 "parser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 500 ".\\parser.y"

		yyattribute(1 - 2).variabledeclarationlist->push_back(shared_ptr<VariableDeclaration>(yyattribute(2 - 2).statement));
		(*(YYSTYPE YYFAR*)yyvalptr).variabledeclarationlist = yyattribute(1 - 2).variabledeclarationlist;
	
#line 1446 "parser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "IDENTIFIER", 257 },
		{ "STRING_LITERAL", 258 },
		{ "CONSTANT_INT", 259 },
		{ "CONSTANT_DOUBLE", 260 },
		{ "UMINUS", 261 },
		{ "LE_OP", 262 },
		{ "GE_OP", 263 },
		{ "EQ_OP", 264 },
		{ "NE_OP", 265 },
		{ "LT_OP", 266 },
		{ "GT_OP", 267 },
		{ "MUL_ASSIGN", 268 },
		{ "DIV_ASSIGN", 269 },
		{ "MOD_ASSIGN", 270 },
		{ "ADD_ASSIGN", 271 },
		{ "SUB_ASSIGN", 272 },
		{ "AND_ASSIGN", 273 },
		{ "XOR_ASSIGN", 274 },
		{ "OR_ASSIGN", 275 },
		{ "SEMICOLON", 276 },
		{ "LBRACE", 277 },
		{ "RBRACE", 278 },
		{ "COMMA", 279 },
		{ "EQUAL", 280 },
		{ "RPAREN", 281 },
		{ "LPAREN", 282 },
		{ "LBRACKET", 283 },
		{ "RBRACKET", 284 },
		{ "DOT", 285 },
		{ "AND_OP", 286 },
		{ "MINUS_OP", 287 },
		{ "PLUS_OP", 288 },
		{ "MUL_OP", 289 },
		{ "DIV_OP", 290 },
		{ "MOD_OP", 291 },
		{ "XOR_OP", 292 },
		{ "OR_OP", 293 },
		{ "CHAR", 294 },
		{ "INT", 295 },
		{ "FLOAT", 296 },
		{ "DOUBLE", 297 },
		{ "VOID", 298 },
		{ "BOOL", 299 },
		{ "STRUCT", 300 },
		{ "IF", 301 },
		{ "ELSE", 302 },
		{ "WHILE", 303 },
		{ "FOR", 304 },
		{ "RETURN", 305 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: program",
		"program: statements",
		"statements: statement",
		"statements: statements statement",
		"statement: var_dec SEMICOLON",
		"statement: func_dec",
		"statement: struct_dec SEMICOLON",
		"statement: expr SEMICOLON",
		"statement: RETURN expr SEMICOLON",
		"statement: if_stmt",
		"statement: for_stmt",
		"statement: while_stmt",
		"block: LBRACE statements RBRACE",
		"block: LBRACE RBRACE",
		"primary_typename: INT",
		"primary_typename: DOUBLE",
		"primary_typename: FLOAT",
		"primary_typename: CHAR",
		"primary_typename: BOOL",
		"primary_typename: VOID",
		"array_typename: primary_typename LBRACKET CONSTANT_INT RBRACKET",
		"array_typename: array_typename LBRACKET CONSTANT_INT RBRACKET",
		"struct_typename: STRUCT ident",
		"typename: primary_typename",
		"typename: array_typename",
		"typename: struct_typename",
		"var_dec: typename ident",
		"var_dec: typename ident EQUAL expr",
		"var_dec: typename ident EQUAL LBRACE call_args RBRACE",
		"func_dec: typename ident LPAREN func_dec_args RPAREN block",
		"func_dec_args:",
		"func_dec_args: var_dec",
		"func_dec_args: func_dec_args COMMA var_dec",
		"ident: IDENTIFIER",
		"numeric: CONSTANT_INT",
		"numeric: CONSTANT_DOUBLE",
		"expr: assign",
		"expr: ident LPAREN call_args RPAREN",
		"expr: ident",
		"expr: ident DOT ident",
		"expr: numeric",
		"expr: expr binary_operator expr",
		"expr: LPAREN expr RPAREN",
		"expr: MINUS_OP expr",
		"expr: array_index",
		"expr: STRING_LITERAL",
		"array_index: ident LBRACKET expr RBRACKET",
		"array_index: array_index LBRACKET expr RBRACKET",
		"assign: ident assign_operator expr",
		"assign: array_index assign_operator expr",
		"assign: ident DOT ident assign_operator expr",
		"assign_operator: EQUAL",
		"assign_operator: MUL_ASSIGN",
		"assign_operator: DIV_ASSIGN",
		"assign_operator: MOD_ASSIGN",
		"assign_operator: ADD_ASSIGN",
		"assign_operator: SUB_ASSIGN",
		"assign_operator: AND_ASSIGN",
		"assign_operator: XOR_ASSIGN",
		"assign_operator: OR_ASSIGN",
		"call_args:",
		"call_args: expr",
		"call_args: call_args COMMA expr",
		"binary_operator: EQ_OP",
		"binary_operator: NE_OP",
		"binary_operator: LT_OP",
		"binary_operator: LE_OP",
		"binary_operator: GT_OP",
		"binary_operator: GE_OP",
		"binary_operator: AND_OP",
		"binary_operator: OR_OP",
		"binary_operator: XOR_OP",
		"binary_operator: MOD_OP",
		"binary_operator: MUL_OP",
		"binary_operator: DIV_OP",
		"binary_operator: PLUS_OP",
		"binary_operator: MINUS_OP",
		"if_stmt: IF expr block",
		"if_stmt: IF expr block ELSE block",
		"if_stmt: IF expr block ELSE if_stmt",
		"for_stmt: FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN block",
		"while_stmt: WHILE LPAREN expr RPAREN block",
		"struct_dec: STRUCT ident LBRACE struct_members RBRACE",
		"struct_members:",
		"struct_members: var_dec",
		"struct_members: struct_members var_dec"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, 0 },
		{ 2, 1, 1 },
		{ 2, 2, 2 },
		{ 3, 2, 3 },
		{ 3, 1, 4 },
		{ 3, 2, 5 },
		{ 3, 2, 6 },
		{ 3, 3, 7 },
		{ 3, 1, 8 },
		{ 3, 1, 9 },
		{ 3, 1, 10 },
		{ 4, 3, 11 },
		{ 4, 2, 12 },
		{ 5, 1, 13 },
		{ 5, 1, 14 },
		{ 5, 1, 15 },
		{ 5, 1, 16 },
		{ 5, 1, 17 },
		{ 5, 1, 18 },
		{ 6, 4, 19 },
		{ 6, 4, 20 },
		{ 7, 2, 21 },
		{ 8, 1, 22 },
		{ 8, 1, 23 },
		{ 8, 1, 24 },
		{ 9, 2, 25 },
		{ 9, 4, 26 },
		{ 9, 6, 27 },
		{ 10, 6, 28 },
		{ 11, 0, 29 },
		{ 11, 1, 30 },
		{ 11, 3, 31 },
		{ 12, 1, 32 },
		{ 13, 1, 33 },
		{ 13, 1, 34 },
		{ 14, 1, 35 },
		{ 14, 4, 36 },
		{ 14, 1, 37 },
		{ 14, 3, 38 },
		{ 14, 1, 39 },
		{ 14, 3, 40 },
		{ 14, 3, 41 },
		{ 14, 2, 42 },
		{ 14, 1, 43 },
		{ 14, 1, 44 },
		{ 15, 4, 45 },
		{ 15, 4, 46 },
		{ 16, 3, 47 },
		{ 16, 3, 48 },
		{ 16, 5, 49 },
		{ 17, 1, 50 },
		{ 17, 1, 51 },
		{ 17, 1, 52 },
		{ 17, 1, 53 },
		{ 17, 1, 54 },
		{ 17, 1, 55 },
		{ 17, 1, 56 },
		{ 17, 1, 57 },
		{ 17, 1, 58 },
		{ 18, 0, 59 },
		{ 18, 1, 60 },
		{ 18, 3, 61 },
		{ 19, 1, 62 },
		{ 19, 1, 63 },
		{ 19, 1, 64 },
		{ 19, 1, 65 },
		{ 19, 1, 66 },
		{ 19, 1, 67 },
		{ 19, 1, 68 },
		{ 19, 1, 69 },
		{ 19, 1, 70 },
		{ 19, 1, 71 },
		{ 19, 1, 72 },
		{ 19, 1, 73 },
		{ 19, 1, 74 },
		{ 19, 1, 75 },
		{ 20, 3, 76 },
		{ 20, 5, 77 },
		{ 20, 5, 78 },
		{ 21, 9, 79 },
		{ 22, 5, 80 },
		{ 23, 5, 81 },
		{ 24, 0, 82 },
		{ 24, 1, 83 },
		{ 24, 2, 84 }
	};
	yyreduction = reduction;

	yytokenaction_size = 251;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 20, YYAT_SHIFT, 1 },
		{ 20, YYAT_SHIFT, 2 },
		{ 20, YYAT_SHIFT, 3 },
		{ 20, YYAT_SHIFT, 4 },
		{ 32, YYAT_SHIFT, 47 },
		{ 32, YYAT_SHIFT, 48 },
		{ 32, YYAT_SHIFT, 49 },
		{ 32, YYAT_SHIFT, 50 },
		{ 32, YYAT_SHIFT, 51 },
		{ 32, YYAT_SHIFT, 52 },
		{ 32, YYAT_SHIFT, 53 },
		{ 32, YYAT_SHIFT, 54 },
		{ 127, YYAT_SHIFT, 133 },
		{ 110, YYAT_SHIFT, 129 },
		{ 138, YYAT_SHIFT, 82 },
		{ 110, YYAT_SHIFT, 130 },
		{ 32, YYAT_SHIFT, 55 },
		{ 127, YYAT_ERROR, 0 },
		{ 32, YYAT_SHIFT, 74 },
		{ 32, YYAT_SHIFT, 75 },
		{ 39, YYAT_SHIFT, 82 },
		{ 32, YYAT_SHIFT, 76 },
		{ 122, YYAT_SHIFT, 87 },
		{ 94, YYAT_ERROR, 0 },
		{ 39, YYAT_ERROR, 0 },
		{ 20, YYAT_SHIFT, 5 },
		{ 94, YYAT_SHIFT, 115 },
		{ 92, YYAT_SHIFT, 113 },
		{ 105, YYAT_SHIFT, 14 },
		{ 92, YYAT_SHIFT, 114 },
		{ 20, YYAT_SHIFT, 6 },
		{ 137, YYAT_SHIFT, 58 },
		{ 137, YYAT_SHIFT, 59 },
		{ 137, YYAT_SHIFT, 60 },
		{ 137, YYAT_SHIFT, 61 },
		{ 137, YYAT_SHIFT, 62 },
		{ 137, YYAT_SHIFT, 63 },
		{ 20, YYAT_SHIFT, 7 },
		{ 20, YYAT_SHIFT, 8 },
		{ 20, YYAT_SHIFT, 9 },
		{ 20, YYAT_SHIFT, 10 },
		{ 20, YYAT_SHIFT, 11 },
		{ 20, YYAT_SHIFT, 12 },
		{ 20, YYAT_SHIFT, 13 },
		{ 20, YYAT_SHIFT, 14 },
		{ 102, YYAT_SHIFT, 1 },
		{ 20, YYAT_SHIFT, 15 },
		{ 20, YYAT_SHIFT, 16 },
		{ 20, YYAT_SHIFT, 17 },
		{ 46, YYAT_SHIFT, 87 },
		{ 137, YYAT_SHIFT, 138 },
		{ 46, YYAT_SHIFT, 88 },
		{ 128, YYAT_SHIFT, 134 },
		{ 128, YYAT_SHIFT, 113 },
		{ 100, YYAT_SHIFT, 120 },
		{ 137, YYAT_SHIFT, 65 },
		{ 137, YYAT_SHIFT, 66 },
		{ 137, YYAT_SHIFT, 67 },
		{ 137, YYAT_SHIFT, 68 },
		{ 137, YYAT_SHIFT, 69 },
		{ 137, YYAT_SHIFT, 70 },
		{ 137, YYAT_SHIFT, 71 },
		{ 137, YYAT_SHIFT, 72 },
		{ 131, YYAT_SHIFT, 58 },
		{ 131, YYAT_SHIFT, 59 },
		{ 131, YYAT_SHIFT, 60 },
		{ 131, YYAT_SHIFT, 61 },
		{ 131, YYAT_SHIFT, 62 },
		{ 131, YYAT_SHIFT, 63 },
		{ 98, YYAT_SHIFT, 118 },
		{ 97, YYAT_SHIFT, 117 },
		{ 109, YYAT_SHIFT, 58 },
		{ 109, YYAT_SHIFT, 59 },
		{ 109, YYAT_SHIFT, 60 },
		{ 109, YYAT_SHIFT, 61 },
		{ 109, YYAT_SHIFT, 62 },
		{ 109, YYAT_SHIFT, 63 },
		{ 89, YYAT_SHIFT, 112 },
		{ 87, YYAT_SHIFT, 108 },
		{ 96, YYAT_SHIFT, 58 },
		{ 96, YYAT_SHIFT, 59 },
		{ 96, YYAT_SHIFT, 60 },
		{ 96, YYAT_SHIFT, 61 },
		{ 96, YYAT_SHIFT, 62 },
		{ 96, YYAT_SHIFT, 63 },
		{ 85, YYAT_SHIFT, 107 },
		{ 84, YYAT_SHIFT, 106 },
		{ 131, YYAT_SHIFT, 65 },
		{ 131, YYAT_SHIFT, 66 },
		{ 131, YYAT_SHIFT, 67 },
		{ 131, YYAT_SHIFT, 68 },
		{ 131, YYAT_SHIFT, 69 },
		{ 131, YYAT_SHIFT, 70 },
		{ 131, YYAT_SHIFT, 71 },
		{ 131, YYAT_SHIFT, 72 },
		{ 109, YYAT_SHIFT, 65 },
		{ 109, YYAT_SHIFT, 66 },
		{ 109, YYAT_SHIFT, 67 },
		{ 109, YYAT_SHIFT, 68 },
		{ 109, YYAT_SHIFT, 69 },
		{ 109, YYAT_SHIFT, 70 },
		{ 109, YYAT_SHIFT, 71 },
		{ 109, YYAT_SHIFT, 72 },
		{ 96, YYAT_SHIFT, 65 },
		{ 96, YYAT_SHIFT, 66 },
		{ 96, YYAT_SHIFT, 67 },
		{ 96, YYAT_SHIFT, 68 },
		{ 96, YYAT_SHIFT, 69 },
		{ 96, YYAT_SHIFT, 70 },
		{ 96, YYAT_SHIFT, 71 },
		{ 96, YYAT_SHIFT, 72 },
		{ 93, YYAT_SHIFT, 58 },
		{ 93, YYAT_SHIFT, 59 },
		{ 93, YYAT_SHIFT, 60 },
		{ 93, YYAT_SHIFT, 61 },
		{ 93, YYAT_SHIFT, 62 },
		{ 93, YYAT_SHIFT, 63 },
		{ 83, YYAT_SHIFT, 105 },
		{ 82, YYAT_SHIFT, 103 },
		{ 91, YYAT_SHIFT, 58 },
		{ 91, YYAT_SHIFT, 59 },
		{ 91, YYAT_SHIFT, 60 },
		{ 91, YYAT_SHIFT, 61 },
		{ 91, YYAT_SHIFT, 62 },
		{ 91, YYAT_SHIFT, 63 },
		{ 79, YYAT_SHIFT, 98 },
		{ 78, YYAT_SHIFT, 97 },
		{ 90, YYAT_SHIFT, 58 },
		{ 90, YYAT_SHIFT, 59 },
		{ 90, YYAT_SHIFT, 60 },
		{ 90, YYAT_SHIFT, 61 },
		{ 90, YYAT_SHIFT, 62 },
		{ 90, YYAT_SHIFT, 63 },
		{ 42, YYAT_SHIFT, 86 },
		{ 38, YYAT_SHIFT, 81 },
		{ 93, YYAT_SHIFT, 65 },
		{ 93, YYAT_SHIFT, 66 },
		{ 93, YYAT_SHIFT, 67 },
		{ 93, YYAT_SHIFT, 68 },
		{ 93, YYAT_SHIFT, 69 },
		{ 93, YYAT_SHIFT, 70 },
		{ 93, YYAT_SHIFT, 71 },
		{ 93, YYAT_SHIFT, 72 },
		{ 91, YYAT_SHIFT, 65 },
		{ 91, YYAT_SHIFT, 66 },
		{ 91, YYAT_SHIFT, 67 },
		{ 91, YYAT_SHIFT, 68 },
		{ 91, YYAT_SHIFT, 69 },
		{ 91, YYAT_SHIFT, 70 },
		{ 91, YYAT_SHIFT, 71 },
		{ 91, YYAT_SHIFT, 72 },
		{ 90, YYAT_SHIFT, 65 },
		{ 90, YYAT_SHIFT, 66 },
		{ 90, YYAT_SHIFT, 67 },
		{ 90, YYAT_SHIFT, 68 },
		{ 90, YYAT_SHIFT, 69 },
		{ 90, YYAT_SHIFT, 70 },
		{ 90, YYAT_SHIFT, 71 },
		{ 90, YYAT_SHIFT, 72 },
		{ 104, YYAT_SHIFT, 123 },
		{ 95, YYAT_SHIFT, 47 },
		{ 95, YYAT_SHIFT, 48 },
		{ 95, YYAT_SHIFT, 49 },
		{ 95, YYAT_SHIFT, 50 },
		{ 95, YYAT_SHIFT, 51 },
		{ 95, YYAT_SHIFT, 52 },
		{ 95, YYAT_SHIFT, 53 },
		{ 95, YYAT_SHIFT, 54 },
		{ 36, YYAT_SHIFT, 80 },
		{ 34, YYAT_SHIFT, 79 },
		{ 33, YYAT_SHIFT, 78 },
		{ 31, YYAT_SHIFT, 64 },
		{ 95, YYAT_SHIFT, 55 },
		{ 26, YYAT_SHIFT, 45 },
		{ 24, YYAT_SHIFT, 44 },
		{ 104, YYAT_SHIFT, 7 },
		{ 104, YYAT_SHIFT, 8 },
		{ 104, YYAT_SHIFT, 9 },
		{ 104, YYAT_SHIFT, 10 },
		{ 104, YYAT_SHIFT, 11 },
		{ 104, YYAT_SHIFT, 12 },
		{ 104, YYAT_SHIFT, 13 },
		{ 104, YYAT_SHIFT, 14 },
		{ 23, YYAT_ACCEPT, 0 },
		{ 104, YYAT_SHIFT, 15 },
		{ 104, YYAT_SHIFT, 16 },
		{ 104, YYAT_SHIFT, 17 },
		{ 30, YYAT_SHIFT, 47 },
		{ 30, YYAT_SHIFT, 48 },
		{ 30, YYAT_SHIFT, 49 },
		{ 30, YYAT_SHIFT, 50 },
		{ 30, YYAT_SHIFT, 51 },
		{ 30, YYAT_SHIFT, 52 },
		{ 30, YYAT_SHIFT, 53 },
		{ 30, YYAT_SHIFT, 54 },
		{ 108, YYAT_SHIFT, 1 },
		{ 108, YYAT_SHIFT, 2 },
		{ 108, YYAT_SHIFT, 3 },
		{ 108, YYAT_SHIFT, 4 },
		{ 30, YYAT_SHIFT, 55 },
		{ 16, YYAT_SHIFT, 41 },
		{ 15, YYAT_SHIFT, 40 },
		{ 30, YYAT_SHIFT, 56 },
		{ 74, YYAT_SHIFT, 1 },
		{ 74, YYAT_SHIFT, 2 },
		{ 74, YYAT_SHIFT, 3 },
		{ 74, YYAT_SHIFT, 4 },
		{ 133, YYAT_SHIFT, 2 },
		{ 133, YYAT_SHIFT, 3 },
		{ 133, YYAT_SHIFT, 4 },
		{ 129, YYAT_SHIFT, 7 },
		{ 129, YYAT_SHIFT, 8 },
		{ 129, YYAT_SHIFT, 9 },
		{ 129, YYAT_SHIFT, 10 },
		{ 129, YYAT_SHIFT, 11 },
		{ 129, YYAT_SHIFT, 12 },
		{ 129, YYAT_SHIFT, 99 },
		{ 0, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 108, YYAT_SHIFT, 5 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 108, YYAT_SHIFT, 6 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 74, YYAT_SHIFT, 5 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 133, YYAT_SHIFT, 5 },
		{ -1, YYAT_ERROR, 0 },
		{ 74, YYAT_SHIFT, 6 },
		{ -1, YYAT_ERROR, 0 },
		{ -1, YYAT_ERROR, 0 },
		{ 133, YYAT_SHIFT, 6 },
		{ 88, YYAT_SHIFT, 7 },
		{ 88, YYAT_SHIFT, 8 },
		{ 88, YYAT_SHIFT, 9 },
		{ 88, YYAT_SHIFT, 10 },
		{ 88, YYAT_SHIFT, 11 },
		{ 88, YYAT_SHIFT, 12 },
		{ 88, YYAT_SHIFT, 99 },
		{ 81, YYAT_SHIFT, 7 },
		{ 81, YYAT_SHIFT, 8 },
		{ 81, YYAT_SHIFT, 9 },
		{ 81, YYAT_SHIFT, 10 },
		{ 81, YYAT_SHIFT, 11 },
		{ 81, YYAT_SHIFT, 12 },
		{ 81, YYAT_SHIFT, 99 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -61, 1, YYAT_DEFAULT, 104 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 14 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_DEFAULT, 102 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ -81, 1, YYAT_ERROR, 0 },
		{ -82, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 11 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ -257, 1, YYAT_REDUCE, 1 },
		{ 0, 0, YYAT_REDUCE, 9 },
		{ 0, 0, YYAT_REDUCE, 10 },
		{ 183, 1, YYAT_ERROR, 0 },
		{ -102, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ -103, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_DEFAULT, 102 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ -81, 1, YYAT_REDUCE, 44 },
		{ -105, 1, YYAT_DEFAULT, 127 },
		{ -264, 1, YYAT_REDUCE, 38 },
		{ -113, 1, YYAT_REDUCE, 24 },
		{ -114, 1, YYAT_REDUCE, 23 },
		{ 0, 0, YYAT_REDUCE, 25 },
		{ -113, 1, YYAT_DEFAULT, 137 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ -143, 1, YYAT_REDUCE, 22 },
		{ -257, 1, YYAT_DEFAULT, 137 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ -143, 1, YYAT_DEFAULT, 127 },
		{ 0, 0, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ 0, 0, YYAT_REDUCE, 6 },
		{ -231, 1, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 57 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_REDUCE, 51 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_REDUCE, 69 },
		{ 0, 0, YYAT_REDUCE, 76 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 71 },
		{ 0, 0, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ -54, 1, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_DEFAULT, 102 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ -133, 1, YYAT_ERROR, 0 },
		{ -134, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ -50, 1, YYAT_REDUCE, 83 },
		{ -160, 1, YYAT_DEFAULT, 104 },
		{ -185, 1, YYAT_REDUCE, 77 },
		{ -195, 1, YYAT_DEFAULT, 137 },
		{ -191, 1, YYAT_DEFAULT, 127 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ -199, 1, YYAT_DEFAULT, 133 },
		{ -57, 1, YYAT_REDUCE, 30 },
		{ -207, 1, YYAT_DEFAULT, 94 },
		{ -135, 1, YYAT_REDUCE, 49 },
		{ -143, 1, YYAT_REDUCE, 41 },
		{ -252, 1, YYAT_ERROR, 0 },
		{ -151, 1, YYAT_REDUCE, 61 },
		{ -258, 1, YYAT_DEFAULT, 137 },
		{ -108, 1, YYAT_REDUCE, 39 },
		{ -183, 1, YYAT_REDUCE, 48 },
		{ -214, 1, YYAT_ERROR, 0 },
		{ -215, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 102 },
		{ -224, 1, YYAT_DEFAULT, 129 },
		{ 0, 0, YYAT_REDUCE, 84 },
		{ -212, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 13 },
		{ -119, 1, YYAT_DEFAULT, 133 },
		{ -273, 1, YYAT_DEFAULT, 138 },
		{ 0, 0, YYAT_DEFAULT, 138 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ -62, 1, YYAT_REDUCE, 60 },
		{ -191, 1, YYAT_REDUCE, 27 },
		{ -266, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_DEFAULT, 133 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_REDUCE, 85 },
		{ -258, 1, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ -264, 1, YYAT_DEFAULT, 137 },
		{ -226, 1, YYAT_ERROR, 0 },
		{ -84, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 138 },
		{ -199, 1, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ -51, 1, YYAT_DEFAULT, 102 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -231, 1, YYAT_ERROR, 0 },
		{ -263, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 80 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 64;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 104, 43 },
		{ 81, 101 },
		{ 104, 34 },
		{ 104, 33 },
		{ 104, 35 },
		{ 104, 28 },
		{ 104, 24 },
		{ 104, 25 },
		{ 105, 124 },
		{ 108, 93 },
		{ 88, 111 },
		{ 104, 31 },
		{ 88, 110 },
		{ 108, 128 },
		{ 82, 104 },
		{ 82, 27 },
		{ 81, 100 },
		{ 104, 21 },
		{ 104, 22 },
		{ 104, 18 },
		{ 104, 26 },
		{ 0, 23 },
		{ 0, 20 },
		{ 138, 139 },
		{ 105, 125 },
		{ 133, 32 },
		{ 133, 29 },
		{ 133, 137 },
		{ 133, 30 },
		{ 133, 19 },
		{ 129, 34 },
		{ 129, 33 },
		{ 129, 35 },
		{ 129, 102 },
		{ 129, 135 },
		{ 137, 73 },
		{ 130, 136 },
		{ 116, 132 },
		{ 113, 131 },
		{ 107, 127 },
		{ 106, 126 },
		{ 102, 122 },
		{ 100, 121 },
		{ 99, 119 },
		{ 95, 116 },
		{ 87, 109 },
		{ 77, 96 },
		{ 76, 95 },
		{ 75, 94 },
		{ 74, 92 },
		{ 73, 91 },
		{ 57, 90 },
		{ 56, 89 },
		{ 41, 85 },
		{ 40, 84 },
		{ 39, 83 },
		{ 32, 77 },
		{ 30, 57 },
		{ 28, 46 },
		{ 17, 42 },
		{ 14, 39 },
		{ 13, 38 },
		{ 6, 37 },
		{ 5, 36 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 20, 82 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, 133 },
		{ 48, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 49, -1 },
		{ 46, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 45, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 104 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 46, -1 },
		{ 0, -1 },
		{ 40, -1 },
		{ 0, 137 },
		{ 39, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 137 },
		{ 0, 137 },
		{ 0, -1 },
		{ 51, 137 },
		{ 40, 133 },
		{ 39, 133 },
		{ 0, 137 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 38, 133 },
		{ 37, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 36, 133 },
		{ 31, 108 },
		{ 34, 133 },
		{ 35, -1 },
		{ 32, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -8, 129 },
		{ 12, 104 },
		{ 0, -1 },
		{ 0, 137 },
		{ 0, 137 },
		{ 0, -1 },
		{ 31, 133 },
		{ 1, 129 },
		{ 0, 137 },
		{ 0, 137 },
		{ 0, 137 },
		{ 0, -1 },
		{ 0, 137 },
		{ 0, 137 },
		{ 27, -1 },
		{ 0, 137 },
		{ 0, -1 },
		{ 0, -1 },
		{ 31, -1 },
		{ 33, 129 },
		{ 0, -1 },
		{ 29, -1 },
		{ 0, -1 },
		{ -3, 133 },
		{ 4, -1 },
		{ 36, -1 },
		{ 25, 133 },
		{ -5, 133 },
		{ 0, 137 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 24, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 23, 133 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 137 },
		{ 0, -1 },
		{ 25, -1 },
		{ 32, -1 },
		{ 0, 137 },
		{ 0, 137 },
		{ 13, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 16, -1 },
		{ 19, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 506 ".\\parser.y"

void yyerror(char const *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

int main(int avgs, char *argv[])
{
	yyin = fopen(argv[1], "r");
	if(!yyin)
	{
		printf("Cannot Open the File!\n");
		exit(0);
	}
	yyparse();
	return 0;
}
