/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parser/parser.y" /* yacc.c:339  */

	#include "../absyn.h"
	#include <stdio.h>
	#include <stdlib.h>
	#include <iostream>
	

	Block *programBlock;
	extern int yylineno;
	extern void yyerror(const char *);
	int yylex(void);

#line 79 "Parser/parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    STRING_LITERAL = 259,
    CONSTANT_INT = 260,
    CONSTANT_DOUBLE = 261,
    UMINUS = 262,
    LE_OP = 263,
    GE_OP = 264,
    EQ_OP = 265,
    NE_OP = 266,
    LT_OP = 267,
    GT_OP = 268,
    SEMICOLON = 269,
    LBRACE = 270,
    RBRACE = 271,
    COMMA = 272,
    EQUAL = 273,
    RPAREN = 274,
    LPAREN = 275,
    LBRACKET = 276,
    RBRACKET = 277,
    DOT = 278,
    AND_OP = 279,
    MINUS_OP = 280,
    PLUS_OP = 281,
    MUL_OP = 282,
    DIV_OP = 283,
    MOD_OP = 284,
    XOR_OP = 285,
    OR_OP = 286,
    CHAR = 287,
    INT = 288,
    FLOAT = 289,
    DOUBLE = 290,
    VOID = 291,
    BOOL = 292,
    STRUCT = 293,
    IF = 294,
    ELSE = 295,
    WHILE = 296,
    FOR = 297,
    RETURN = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "Parser/parser.y" /* yacc.c:355  */

	std::string *stringg;
	int token;
	
	Block *block;
	Expression *expression;
	Statement *statement;
	Identifier *identifier;
	VariableDeclaration *variabledeclaration;
	ArrayDeclaration *arraydeclaration;
	ArrayIndex *arrayindex;
	std::vector<shared_ptr<VariableDeclaration>>* variabledeclarationlist;
	std::vector<shared_ptr<Expression>>* expressionlist;

#line 178 "Parser/parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 195 "Parser/parser.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   473

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    69,    74,    82,    86,    90,    94,    98,
     102,   106,   110,   114,   118,   125,   129,   136,   142,   148,
     154,   160,   166,   175,   180,   188,   196,   200,   207,   215,
     218,   223,   231,   239,   243,   250,   254,   258,   262,   266,
     270,   274,   278,   282,   286,   290,   294,   298,   302,   306,
     310,   314,   318,   322,   326,   330,   334,   338,   346,   350,
     358,   362,   366,   375,   378,   383,   392,   396,   400,   409,
     416,   423,   427,   431,   439,   442,   447
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "CONSTANT_INT", "CONSTANT_DOUBLE", "UMINUS", "LE_OP", "GE_OP", "EQ_OP",
  "NE_OP", "LT_OP", "GT_OP", "SEMICOLON", "LBRACE", "RBRACE", "COMMA",
  "EQUAL", "RPAREN", "LPAREN", "LBRACKET", "RBRACKET", "DOT", "AND_OP",
  "MINUS_OP", "PLUS_OP", "MUL_OP", "DIV_OP", "MOD_OP", "XOR_OP", "OR_OP",
  "CHAR", "INT", "FLOAT", "DOUBLE", "VOID", "BOOL", "STRUCT", "IF", "ELSE",
  "WHILE", "FOR", "RETURN", "$accept", "program", "statements",
  "statement", "block", "primary_type", "array_dec",
  "array_initialization", "var_dec", "func_dec", "func_dec_args", "ident",
  "numeric", "expr", "array_index", "assign", "call_args", "if_stmt",
  "for_stmt", "while_stmt", "struct_dec", "struct_members", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -79

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-79)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     139,   -79,   -79,   -79,   -79,    12,    12,   -79,   -79,   -79,
     -79,   -79,   -79,     8,    12,   -12,     0,    12,    21,   139,
     -79,     8,     5,    34,    41,   -79,     4,   -79,   175,    15,
     -79,   -79,   -79,   -79,    55,   199,   -79,    60,   223,    12,
      12,   231,   -79,   -79,    10,   -79,    61,    85,   -79,   -79,
      12,    12,    12,     8,    12,    12,    12,    12,    12,    12,
     -79,    12,    12,    12,    12,    12,    12,    12,    12,    12,
      12,   -79,   -79,   133,    67,    51,   255,   279,   -79,    12,
     133,   106,    12,    91,   385,   385,    78,   289,    98,    53,
      53,   444,   444,    53,    53,   422,    57,    57,   -79,   -79,
     -79,   416,   393,   385,   313,     8,   108,   296,   -79,   115,
     -10,   109,    12,   385,   -79,    79,   101,    22,   -79,    12,
     -79,   -79,    12,   -79,   110,   -79,     8,   112,   -79,   -79,
     -79,   -79,   337,   133,   109,   -79,   -79,   385,   385,   111,
     -79,    12,   -79,   -79,   117,   361,    12,   109,    27,   -79,
     -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    32,    57,    33,    34,     0,     0,    20,    17,    19,
      18,    22,    21,     0,     0,     0,     0,     0,     0,     2,
       3,     0,     0,     0,     0,     6,    37,    39,     0,    56,
      35,    12,    13,    14,     0,     0,    55,     0,     0,     0,
       0,     0,     1,     4,    26,     7,     0,     0,     8,     5,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,    54,    74,     0,    66,     0,     0,    11,     0,
      29,     0,    63,     0,    60,    64,     0,     0,    38,    46,
      48,    49,    50,    45,    47,    51,    42,    41,    43,    44,
      40,    52,    53,    61,     0,     0,     0,     0,    16,     0,
       0,     0,     0,    27,    30,     0,     0,     0,    24,     0,
      36,    58,     0,    59,    26,    75,    71,     0,    15,    67,
      68,    70,     0,     0,     0,    23,    25,    65,    62,    72,
      76,     0,    31,    28,     0,     0,    63,     0,     0,    69,
      73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,    56,   -16,   -22,   -67,   -79,   -79,   -66,   -79,
     -79,   -11,   -79,    -5,   -79,   -79,   -78,    17,   -79,   -79,
     -79,   -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    18,    19,    20,    75,    21,    22,    23,    24,    25,
     115,    26,    27,    28,    29,    30,    86,    31,    32,    33,
      34,   107
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      35,    36,    37,    43,   117,    74,   105,   106,    39,    38,
      44,     1,    41,   105,   114,     1,     2,     3,     4,    45,
      40,    42,    50,    46,    51,    52,    47,    53,    79,    14,
      80,    81,     5,    69,    76,    77,    70,     6,   136,   119,
     105,   127,    88,   150,   119,    84,    85,    87,    48,    89,
      90,    91,    92,    93,    94,    49,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   142,   148,    71,
       1,     2,     3,     4,   113,    73,    82,    85,    62,    63,
      64,    65,    66,   108,    64,    65,    66,     5,   129,   131,
      83,   110,     6,    43,   124,   119,   133,   120,   134,     7,
       8,     9,    10,    11,    12,    13,    14,   132,    15,    16,
      17,   116,   143,   118,   137,   139,   122,   138,     1,     2,
       3,     4,   125,   135,    74,   149,   140,   130,    79,   144,
     109,   128,   146,     0,     0,     5,   145,     0,     0,     0,
       6,    85,     1,     2,     3,     4,     0,     7,     8,     9,
      10,    11,    12,    13,    14,     0,    15,    16,    17,     5,
       0,     0,     0,     0,     6,     7,     8,     9,    10,    11,
      12,     7,     8,     9,    10,    11,    12,    13,    14,     0,
      15,    16,    17,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,    72,     0,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      68,    54,    55,    56,    57,    58,    59,     0,    74,    54,
      55,    56,    57,    58,    59,    78,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    61,    62,    63,    64,    65,
      66,    67,    68,    54,    55,    56,    57,    58,    59,     0,
       0,     0,     0,     0,   111,     0,     0,     0,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    54,    55,    56,
      57,    58,    59,   112,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    61,    62,    63,    64,    65,    66,    67,
      68,   121,   126,    61,    62,    63,    64,    65,    66,    67,
      68,    54,    55,    56,    57,    58,    59,     0,     7,     8,
       9,    10,    11,    12,     0,   123,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    54,    55,    56,    57,    58,
      59,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    62,    63,    64,    65,    66,    67,    68,    54,
      55,    56,    57,    58,    59,     0,     0,     0,     0,     0,
     147,     0,     0,     0,     0,    61,    62,    63,    64,    65,
      66,    67,    68,    54,    55,    56,    57,    58,    59,     0,
       0,    54,    55,    56,    57,    58,    59,     0,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    61,    62,    63,
      64,    65,    66,    67,    54,    55,    56,    57,    58,    59,
      54,    55,    56,    57,    58,    59,     0,     0,     0,     0,
      61,    62,    63,    64,    65,    66,     0,    62,    63,    64,
      65,    66,    54,    55,     0,     0,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      63,    64,    65,    66
};

static const yytype_int16 yycheck[] =
{
       5,     6,    13,    19,    82,    15,    73,    73,    20,    14,
      21,     3,    17,    80,    80,     3,     4,     5,     6,    14,
      20,     0,    18,    18,    20,    21,    21,    23,    18,    39,
      20,    21,    20,    18,    39,    40,    21,    25,    16,    17,
     107,   107,    53,    16,    17,    50,    51,    52,    14,    54,
      55,    56,    57,    58,    59,    14,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,   133,   133,   146,    14,
       3,     4,     5,     6,    79,    15,    15,    82,    25,    26,
      27,    28,    29,    16,    27,    28,    29,    20,   110,   111,
       5,    40,    25,   109,   105,    17,    17,    19,    19,    32,
      33,    34,    35,    36,    37,    38,    39,   112,    41,    42,
      43,     5,   134,    22,   119,   126,    18,   122,     3,     4,
       5,     6,    14,    22,    15,   147,    14,   110,    18,    18,
      74,    16,    15,    -1,    -1,    20,   141,    -1,    -1,    -1,
      25,   146,     3,     4,     5,     6,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    20,
      -1,    -1,    -1,    -1,    25,    32,    33,    34,    35,    36,
      37,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,     8,     9,    10,    11,    12,    13,    -1,    15,     8,
       9,    10,    11,    12,    13,    14,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    24,    25,    26,    27,    28,
      29,    30,    31,     8,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,     8,     9,    10,
      11,    12,    13,    14,    -1,    -1,    -1,     8,     9,    10,
      11,    12,    13,    24,    25,    26,    27,    28,    29,    30,
      31,    22,    16,    24,    25,    26,    27,    28,    29,    30,
      31,     8,     9,    10,    11,    12,    13,    -1,    32,    33,
      34,    35,    36,    37,    -1,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,     8,     9,    10,    11,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,     8,     9,    10,    11,    12,    13,    -1,
      -1,     8,     9,    10,    11,    12,    13,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    24,    25,    26,
      27,    28,    29,    30,     8,     9,    10,    11,    12,    13,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    -1,    25,    26,    27,
      28,    29,     8,     9,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    20,    25,    32,    33,    34,
      35,    36,    37,    38,    39,    41,    42,    43,    45,    46,
      47,    49,    50,    51,    52,    53,    55,    56,    57,    58,
      59,    61,    62,    63,    64,    57,    57,    55,    57,    20,
      20,    57,     0,    47,    55,    14,    18,    21,    14,    14,
      18,    20,    21,    23,     8,     9,    10,    11,    12,    13,
      14,    24,    25,    26,    27,    28,    29,    30,    31,    18,
      21,    14,    19,    15,    15,    48,    57,    57,    14,    18,
      20,    21,    15,     5,    57,    57,    60,    57,    55,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    49,    52,    65,    16,    46,
      40,    19,    14,    57,    52,    54,     5,    60,    22,    17,
      19,    22,    18,    22,    55,    14,    16,    52,    16,    48,
      61,    48,    57,    17,    19,    22,    16,    57,    57,    55,
      14,    14,    52,    48,    18,    57,    15,    19,    60,    48,
      16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    48,    48,    49,    49,    49,
      49,    49,    49,    50,    50,    51,    52,    52,    53,    54,
      54,    54,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    59,    60,    60,    60,    61,    61,    61,    62,
      63,    64,    64,    64,    65,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     2,     2,     2,
       2,     3,     1,     1,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     5,     4,     5,     2,     4,     6,     0,
       1,     3,     1,     1,     1,     1,     4,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     1,     4,     4,
       3,     3,     5,     0,     1,     3,     3,     5,     5,     9,
       5,     5,     6,    10,     0,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 63 "Parser/parser.y" /* yacc.c:1646  */
    {
		programBlock = (yyvsp[0].block);
	}
#line 1443 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.block) = new Block();
		(yyval.block)->statements->push_back(shared_ptr<Statement>((yyvsp[0].statement)));
	}
#line 1452 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 75 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyvsp[-1].block)->statements->push_back(shared_ptr<Statement>((yyvsp[0].statement)));
		(yyval.block) = (yyvsp[-1].block);
	}
#line 1461 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 83 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = (yyvsp[-1].statement);
	}
#line 1469 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 87 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = (yyvsp[0].statement);
	}
#line 1477 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 91 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = (yyvsp[-1].arraydeclaration);
	}
#line 1485 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 95 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = (yyvsp[-1].arraydeclaration);
	}
#line 1493 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 99 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = (yyvsp[-1].statement);
	}
#line 1501 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 103 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new ExpressionStatement(shared_ptr<Expression>((yyvsp[-1].expression)));
	}
#line 1509 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 107 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new ReturnStatement(shared_ptr<Expression>((yyvsp[-1].expression)));
	}
#line 1517 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 111 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = (yyvsp[0].statement);
	}
#line 1525 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 115 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = (yyvsp[0].statement);
	}
#line 1533 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 119 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = (yyvsp[0].statement);
	}
#line 1541 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 126 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.block) = (yyvsp[-1].block);
	}
#line 1549 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 130 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.block) = new Block();
	}
#line 1557 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 137 "Parser/parser.y" /* yacc.c:1646  */
    {	
		(yyval.identifier) = new Identifier(*(yyvsp[0].stringg));
		(yyval.identifier)->isType = true;
		delete (yyvsp[0].stringg);
	}
#line 1567 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 143 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.identifier) = new Identifier(*(yyvsp[0].stringg));
		(yyval.identifier)->isType = true;
		delete (yyvsp[0].stringg);
	}
#line 1577 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 149 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.identifier) = new Identifier(*(yyvsp[0].stringg));
		(yyval.identifier)->isType = true;
		delete (yyvsp[0].stringg);
	}
#line 1587 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 155 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.identifier) = new Identifier(*(yyvsp[0].stringg));
		(yyval.identifier)->isType = true;
		delete (yyvsp[0].stringg);
	}
#line 1597 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 161 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.identifier) = new Identifier(*(yyvsp[0].stringg));
		(yyval.identifier)->isType = true;
		delete (yyvsp[0].stringg);
	}
#line 1607 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 167 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.identifier) = new Identifier(*(yyvsp[0].stringg));
		(yyval.identifier)->isType = true;
		delete (yyvsp[0].stringg);
	}
#line 1617 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 176 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.arraydeclaration) = new ArrayDeclaration(shared_ptr<Identifier>((yyvsp[-4].identifier)), shared_ptr<Identifier>((yyvsp[-3].identifier)));
		(yyval.arraydeclaration)->arraySize->push_back(make_shared<Integer>(atol((yyvsp[-1].stringg)->c_str())));
	}
#line 1626 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 181 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.arraydeclaration)->arraySize->push_back(make_shared<Integer>(atol((yyvsp[-1].stringg)->c_str())));
	}
#line 1634 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 189 "Parser/parser.y" /* yacc.c:1646  */
    {
		shared_ptr<ArrayDeclaration>((yyvsp[-4].arraydeclaration))->inits = shared_ptr<ExpressionList>((yyvsp[-1].expressionlist));
		(yyval.arraydeclaration) = (yyvsp[-4].arraydeclaration);
	}
#line 1643 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 197 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new VariableDeclaration(shared_ptr<Identifier>((yyvsp[-1].identifier)), shared_ptr<Identifier>((yyvsp[0].identifier)), NULL);
	}
#line 1651 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 201 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new VariableDeclaration(shared_ptr<Identifier>((yyvsp[-3].identifier)), shared_ptr<Identifier>((yyvsp[-2].identifier)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1659 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 208 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new FunctionDeclaration(shared_ptr<Identifier>((yyvsp[-5].identifier)), shared_ptr<Identifier>((yyvsp[-4].identifier)), shared_ptr<VariableDeclarationList>((yyvsp[-2].variabledeclarationlist)), shared_ptr<Block>((yyvsp[0].block)));
	}
#line 1667 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 215 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.variabledeclarationlist) = new VariableDeclarationList();
	}
#line 1675 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 219 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.variabledeclarationlist) = new VariableDeclarationList();
		(yyval.variabledeclarationlist)->push_back(shared_ptr<VariableDeclaration>((yyvsp[0].variabledeclaration)));
	}
#line 1684 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 224 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].variabledeclarationlist)->push_back(shared_ptr<VariableDeclaration>((yyvsp[0].variabledeclaration)));
		(yyval.variabledeclarationlist) = (yyvsp[-2].variabledeclarationlist);
	}
#line 1693 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 232 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.identifier) = new Identifier(*(yyvsp[0].stringg));
		delete (yyvsp[0].stringg);
	}
#line 1702 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 240 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Integer(atol((yyvsp[0].stringg)->c_str()));
	}
#line 1710 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 244 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Double(atof((yyvsp[0].stringg)->c_str()));
	}
#line 1718 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 251 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1726 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 255 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new FuntionCall(shared_ptr<Identifier>((yyvsp[-3].identifier)), shared_ptr<ExpressionList>((yyvsp[-1].expressionlist)));
	}
#line 1734 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 259 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = (yyvsp[0].identifier);
	}
#line 1742 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 263 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new StructMember(shared_ptr<Identifier>((yyvsp[-2].identifier)), shared_ptr<Identifier>((yyvsp[0].identifier)));
	}
#line 1750 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 267 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = (yyvsp[0].expression);
	}
#line 1758 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 271 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1766 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 275 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1774 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 279 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1782 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 283 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1790 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 287 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1798 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 291 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1806 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 295 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1814 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 299 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1822 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 303 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1830 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 307 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1838 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 311 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1846 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 315 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1854 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 319 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1862 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 323 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new BinaryOperation((yyvsp[-1].token), shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1870 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 327 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = (yyvsp[-1].expression);
	}
#line 1878 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 331 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = NULL;
	}
#line 1886 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 335 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = (yyvsp[0].arrayindex);
	}
#line 1894 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 339 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Literal(*(yyvsp[0].stringg)); 
		delete (yyvsp[0].stringg);
	}
#line 1903 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 347 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.arrayindex) = new ArrayIndex(shared_ptr<Identifier>((yyvsp[-3].identifier)), shared_ptr<Expression>((yyvsp[-1].expression)));
	}
#line 1911 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 351 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyvsp[-3].arrayindex)->expressions->push_back(shared_ptr<Expression>((yyvsp[-1].expression)));
		(yyval.arrayindex) = (yyvsp[-3].arrayindex);
	}
#line 1920 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 359 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new Assignment(shared_ptr<Identifier>((yyvsp[-2].identifier)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1928 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 363 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expression) = new ArrayAssignment(shared_ptr<ArrayIndex>((yyvsp[-2].arrayindex)), shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1936 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 367 "Parser/parser.y" /* yacc.c:1646  */
    {
		shared_ptr<StructMember>member = make_shared<StructMember>(shared_ptr<Identifier>((yyvsp[-4].identifier)), shared_ptr<Identifier>((yyvsp[-2].identifier)));
		(yyval.expression) = new StructAssignment(member, shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1945 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 375 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expressionlist) = new ExpressionList();
	}
#line 1953 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 379 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.expressionlist) = new ExpressionList();
		(yyval.expressionlist)->push_back(shared_ptr<Expression>((yyvsp[0].expression)));
	}
#line 1962 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 384 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].expressionlist)->push_back(shared_ptr<Expression>((yyvsp[0].expression)));
		(yyval.expressionlist) = (yyvsp[-2].expressionlist);
	}
#line 1971 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 393 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new IfStatement(shared_ptr<Expression>((yyvsp[-1].expression)), shared_ptr<Block>((yyvsp[0].block)));
	}
#line 1979 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 397 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new IfStatement(shared_ptr<Expression>((yyvsp[-3].expression)), shared_ptr<Block>((yyvsp[-2].block)), shared_ptr<Block>((yyvsp[0].block)));
	}
#line 1987 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 401 "Parser/parser.y" /* yacc.c:1646  */
    {
		Block *block = new Block();
		block->statements->push_back(shared_ptr<Statement>((yyvsp[0].statement)));
		(yyval.statement) = new IfStatement(shared_ptr<Expression>((yyvsp[-3].expression)), shared_ptr<Block>((yyvsp[-2].block)), shared_ptr<Block>(block));
	}
#line 1997 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 410 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new ForStatement(shared_ptr<Block>((yyvsp[0].block)), shared_ptr<Expression>((yyvsp[-6].expression)), shared_ptr<Expression>((yyvsp[-4].expression)), shared_ptr<Expression>((yyvsp[-2].expression)));
	}
#line 2005 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 417 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new WhileStatement(shared_ptr<Expression>((yyvsp[-2].expression)), shared_ptr<Block>((yyvsp[0].block)));
	}
#line 2013 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 424 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new StructDeclaration(shared_ptr<Identifier>((yyvsp[-3].identifier)), shared_ptr<VariableDeclarationList>((yyvsp[-1].variabledeclarationlist)));
	}
#line 2021 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 428 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new StructDeclaration(shared_ptr<Identifier>((yyvsp[-4].identifier)), shared_ptr<VariableDeclarationList>((yyvsp[-2].variabledeclarationlist)), shared_ptr<Identifier>((yyvsp[0].identifier)));
	}
#line 2029 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 432 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.statement) = new StructDeclaration(shared_ptr<Identifier>((yyvsp[-8].identifier)), shared_ptr<VariableDeclarationList>((yyvsp[-6].variabledeclarationlist)), shared_ptr<Identifier>((yyvsp[-4].identifier)), shared_ptr<ExpressionList>((yyvsp[-1].expressionlist)));
	}
#line 2037 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 439 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.variabledeclarationlist) = new VariableDeclarationList();
	}
#line 2045 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 443 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyval.variabledeclarationlist) = new VariableDeclarationList();
		(yyval.variabledeclarationlist)->push_back(shared_ptr<VariableDeclaration>((yyvsp[-1].variabledeclaration)));
	}
#line 2054 "Parser/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 448 "Parser/parser.y" /* yacc.c:1646  */
    {
		(yyvsp[-2].variabledeclarationlist)->push_back(shared_ptr<VariableDeclaration>((yyvsp[-1].variabledeclaration)));
		(yyval.variabledeclarationlist) = (yyvsp[-2].variabledeclarationlist);
	}
#line 2063 "Parser/parser.cpp" /* yacc.c:1646  */
    break;


#line 2067 "Parser/parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 454 "Parser/parser.y" /* yacc.c:1906  */

void yyerror(const char * errormsg)
{
	fprintf(stderr, "%s\n", errormsg);
}
