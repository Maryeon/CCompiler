#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 8 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# parser.v
# YACC verbose file generated from parser.y.
# 
# Date: 06/10/18
# Time: 02:28:04
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : program $end

    1  program : statements

    2  statements : statement
    3             | statements statement

    4  statement : var_dec SEMICOLON
    5            | func_dec
    6            | struct_dec SEMICOLON
    7            | expr SEMICOLON
    8            | RETURN expr SEMICOLON
    9            | if_stmt
   10            | for_stmt
   11            | while_stmt

   12  block : LBRACE statements RBRACE
   13        | LBRACE RBRACE

   14  primary_typename : INT
   15                   | DOUBLE
   16                   | FLOAT
   17                   | CHAR
   18                   | BOOL
   19                   | VOID

   20  array_typename : primary_typename LBRACKET CONSTANT_INT RBRACKET
   21                 | array_typename LBRACKET CONSTANT_INT RBRACKET

   22  struct_typename : STRUCT ident

   23  typename : primary_typename
   24           | array_typename
   25           | struct_typename

   26  var_dec : typename ident
   27          | typename ident EQUAL expr
   28          | typename ident EQUAL LBRACE call_args RBRACE

   29  func_dec : typename ident LPAREN func_dec_args RPAREN block

   30  func_dec_args :
   31                | var_dec
   32                | func_dec_args COMMA var_dec

   33  ident : IDENTIFIER

   34  numeric : CONSTANT_INT
   35          | CONSTANT_DOUBLE

   36  expr : assign
   37       | ident LPAREN call_args RPAREN
   38       | ident
   39       | ident DOT ident
   40       | numeric
   41       | expr binary_operator expr
   42       | LPAREN expr RPAREN
   43       | MINUS_OP expr
   44       | array_index
   45       | STRING_LITERAL

   46  array_index : ident LBRACKET expr RBRACKET
   47              | array_index LBRACKET expr RBRACKET

   48  assign : ident assign_operator expr
   49         | array_index assign_operator expr
   50         | ident DOT ident assign_operator expr

   51  assign_operator : EQUAL
   52                  | MUL_ASSIGN
   53                  | DIV_ASSIGN
   54                  | MOD_ASSIGN
   55                  | ADD_ASSIGN
   56                  | SUB_ASSIGN
   57                  | AND_ASSIGN
   58                  | XOR_ASSIGN
   59                  | OR_ASSIGN

   60  call_args :
   61            | expr
   62            | call_args COMMA expr

   63  binary_operator : EQ_OP
   64                  | NE_OP
   65                  | LT_OP
   66                  | LE_OP
   67                  | GT_OP
   68                  | GE_OP
   69                  | AND_OP
   70                  | OR_OP
   71                  | XOR_OP
   72                  | MOD_OP
   73                  | MUL_OP
   74                  | DIV_OP
   75                  | PLUS_OP
   76                  | MINUS_OP

   77  if_stmt : IF expr block
   78          | IF expr block ELSE block
   79          | IF expr block ELSE if_stmt

   80  for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN block

   81  while_stmt : WHILE LPAREN expr RPAREN block

   82  struct_dec : STRUCT ident LBRACE struct_members RBRACE

   83  struct_members :
   84                 | var_dec
   85                 | struct_members var_dec


##############################################################################
# States
##############################################################################

state 0
	$accept : . program $end

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6
	CHAR  shift 7
	INT  shift 8
	FLOAT  shift 9
	DOUBLE  shift 10
	VOID  shift 11
	BOOL  shift 12
	STRUCT  shift 13
	IF  shift 14
	WHILE  shift 15
	FOR  shift 16
	RETURN  shift 17

	while_stmt  goto 18
	assign  goto 19
	statements  goto 20
	if_stmt  goto 21
	for_stmt  goto 22
	program  goto 23
	var_dec  goto 24
	func_dec  goto 25
	struct_dec  goto 26
	statement  goto 27
	typename  goto 28
	numeric  goto 29
	array_index  goto 30
	expr  goto 31
	ident  goto 32
	array_typename  goto 33
	primary_typename  goto 34
	struct_typename  goto 35


state 1
	ident : IDENTIFIER .  (33)

	.  reduce 33


state 2
	expr : STRING_LITERAL .  (45)

	.  reduce 45


state 3
	numeric : CONSTANT_INT .  (34)

	.  reduce 34


state 4
	numeric : CONSTANT_DOUBLE .  (35)

	.  reduce 35


state 5
	expr : LPAREN . expr RPAREN

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 36
	ident  goto 32


state 6
	expr : MINUS_OP . expr

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 37
	ident  goto 32


state 7
	primary_typename : CHAR .  (17)

	.  reduce 17


state 8
	primary_typename : INT .  (14)

	.  reduce 14


state 9
	primary_typename : FLOAT .  (16)

	.  reduce 16


state 10
	primary_typename : DOUBLE .  (15)

	.  reduce 15


state 11
	primary_typename : VOID .  (19)

	.  reduce 19


state 12
	primary_typename : BOOL .  (18)

	.  reduce 18


state 13
	struct_typename : STRUCT . ident
	struct_dec : STRUCT . ident LBRACE struct_members RBRACE

	IDENTIFIER  shift 1

	ident  goto 38


state 14
	if_stmt : IF . expr block ELSE if_stmt
	if_stmt : IF . expr block
	if_stmt : IF . expr block ELSE block

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 39
	ident  goto 32


state 15
	while_stmt : WHILE . LPAREN expr RPAREN block

	LPAREN  shift 40


state 16
	for_stmt : FOR . LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN block

	LPAREN  shift 41


state 17
	statement : RETURN . expr SEMICOLON

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 42
	ident  goto 32


state 18
	statement : while_stmt .  (11)

	.  reduce 11


state 19
	expr : assign .  (36)

	.  reduce 36


state 20
	program : statements .  (1)
	statements : statements . statement

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6
	CHAR  shift 7
	INT  shift 8
	FLOAT  shift 9
	DOUBLE  shift 10
	VOID  shift 11
	BOOL  shift 12
	STRUCT  shift 13
	IF  shift 14
	WHILE  shift 15
	FOR  shift 16
	RETURN  shift 17
	.  reduce 1

	while_stmt  goto 18
	assign  goto 19
	if_stmt  goto 21
	for_stmt  goto 22
	var_dec  goto 24
	func_dec  goto 25
	struct_dec  goto 26
	statement  goto 43
	typename  goto 28
	numeric  goto 29
	array_index  goto 30
	expr  goto 31
	ident  goto 32
	array_typename  goto 33
	primary_typename  goto 34
	struct_typename  goto 35


state 21
	statement : if_stmt .  (9)

	.  reduce 9


state 22
	statement : for_stmt .  (10)

	.  reduce 10


state 23
	$accept : program . $end  (0)

	$end  accept


state 24
	statement : var_dec . SEMICOLON

	SEMICOLON  shift 44


state 25
	statement : func_dec .  (5)

	.  reduce 5


state 26
	statement : struct_dec . SEMICOLON

	SEMICOLON  shift 45


state 27
	statements : statement .  (2)

	.  reduce 2


state 28
	var_dec : typename . ident EQUAL LBRACE call_args RBRACE
	func_dec : typename . ident LPAREN func_dec_args RPAREN block
	var_dec : typename . ident EQUAL expr
	var_dec : typename . ident

	IDENTIFIER  shift 1

	ident  goto 46


state 29
	expr : numeric .  (40)

	.  reduce 40


state 30
	assign : array_index . assign_operator expr
	array_index : array_index . LBRACKET expr RBRACKET
	expr : array_index .  (44)

	MUL_ASSIGN  shift 47
	DIV_ASSIGN  shift 48
	MOD_ASSIGN  shift 49
	ADD_ASSIGN  shift 50
	SUB_ASSIGN  shift 51
	AND_ASSIGN  shift 52
	XOR_ASSIGN  shift 53
	OR_ASSIGN  shift 54
	EQUAL  shift 55
	LBRACKET  shift 56
	.  reduce 44

	assign_operator  goto 57


state 31
	expr : expr . binary_operator expr
	statement : expr . SEMICOLON

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	SEMICOLON  shift 64
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72

	binary_operator  goto 73


state 32
	expr : ident . DOT ident
	expr : ident . LPAREN call_args RPAREN
	assign : ident . assign_operator expr
	expr : ident .  (38)
	assign : ident . DOT ident assign_operator expr
	array_index : ident . LBRACKET expr RBRACKET

	MUL_ASSIGN  shift 47
	DIV_ASSIGN  shift 48
	MOD_ASSIGN  shift 49
	ADD_ASSIGN  shift 50
	SUB_ASSIGN  shift 51
	AND_ASSIGN  shift 52
	XOR_ASSIGN  shift 53
	OR_ASSIGN  shift 54
	EQUAL  shift 55
	LPAREN  shift 74
	LBRACKET  shift 75
	DOT  shift 76
	.  reduce 38

	assign_operator  goto 77


state 33
	array_typename : array_typename . LBRACKET CONSTANT_INT RBRACKET
	typename : array_typename .  (24)

	LBRACKET  shift 78
	.  reduce 24


state 34
	array_typename : primary_typename . LBRACKET CONSTANT_INT RBRACKET
	typename : primary_typename .  (23)

	LBRACKET  shift 79
	.  reduce 23


state 35
	typename : struct_typename .  (25)

	.  reduce 25


state 36
	expr : expr . binary_operator expr
	expr : LPAREN expr . RPAREN

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	RPAREN  shift 80
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72

	binary_operator  goto 73


state 37
	expr : expr . binary_operator expr
	expr : MINUS_OP expr .  (43)

	.  reduce 43

	binary_operator  goto 73


state 38
	struct_typename : STRUCT ident .  (22)
	struct_dec : STRUCT ident . LBRACE struct_members RBRACE

	LBRACE  shift 81
	.  reduce 22


state 39
	expr : expr . binary_operator expr
	if_stmt : IF expr . block ELSE if_stmt
	if_stmt : IF expr . block
	if_stmt : IF expr . block ELSE block

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	LBRACE  shift 82
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72

	block  goto 83
	binary_operator  goto 73


state 40
	while_stmt : WHILE LPAREN . expr RPAREN block

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 84
	ident  goto 32


state 41
	for_stmt : FOR LPAREN . expr SEMICOLON expr SEMICOLON expr RPAREN block

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 85
	ident  goto 32


state 42
	expr : expr . binary_operator expr
	statement : RETURN expr . SEMICOLON

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	SEMICOLON  shift 86
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72

	binary_operator  goto 73


state 43
	statements : statements statement .  (3)

	.  reduce 3


state 44
	statement : var_dec SEMICOLON .  (4)

	.  reduce 4


state 45
	statement : struct_dec SEMICOLON .  (6)

	.  reduce 6


state 46
	var_dec : typename ident . EQUAL LBRACE call_args RBRACE
	func_dec : typename ident . LPAREN func_dec_args RPAREN block
	var_dec : typename ident . EQUAL expr
	var_dec : typename ident .  (26)

	EQUAL  shift 87
	LPAREN  shift 88
	.  reduce 26


state 47
	assign_operator : MUL_ASSIGN .  (52)

	.  reduce 52


state 48
	assign_operator : DIV_ASSIGN .  (53)

	.  reduce 53


state 49
	assign_operator : MOD_ASSIGN .  (54)

	.  reduce 54


state 50
	assign_operator : ADD_ASSIGN .  (55)

	.  reduce 55


state 51
	assign_operator : SUB_ASSIGN .  (56)

	.  reduce 56


state 52
	assign_operator : AND_ASSIGN .  (57)

	.  reduce 57


state 53
	assign_operator : XOR_ASSIGN .  (58)

	.  reduce 58


state 54
	assign_operator : OR_ASSIGN .  (59)

	.  reduce 59


state 55
	assign_operator : EQUAL .  (51)

	.  reduce 51


state 56
	array_index : array_index LBRACKET . expr RBRACKET

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 89
	ident  goto 32


state 57
	assign : array_index assign_operator . expr

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 90
	ident  goto 32


state 58
	binary_operator : LE_OP .  (66)

	.  reduce 66


state 59
	binary_operator : GE_OP .  (68)

	.  reduce 68


state 60
	binary_operator : EQ_OP .  (63)

	.  reduce 63


state 61
	binary_operator : NE_OP .  (64)

	.  reduce 64


state 62
	binary_operator : LT_OP .  (65)

	.  reduce 65


state 63
	binary_operator : GT_OP .  (67)

	.  reduce 67


state 64
	statement : expr SEMICOLON .  (7)

	.  reduce 7


state 65
	binary_operator : AND_OP .  (69)

	.  reduce 69


state 66
	binary_operator : MINUS_OP .  (76)

	.  reduce 76


state 67
	binary_operator : PLUS_OP .  (75)

	.  reduce 75


state 68
	binary_operator : MUL_OP .  (73)

	.  reduce 73


state 69
	binary_operator : DIV_OP .  (74)

	.  reduce 74


state 70
	binary_operator : MOD_OP .  (72)

	.  reduce 72


state 71
	binary_operator : XOR_OP .  (71)

	.  reduce 71


state 72
	binary_operator : OR_OP .  (70)

	.  reduce 70


state 73
	expr : expr binary_operator . expr

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 91
	ident  goto 32


state 74
	expr : ident LPAREN . call_args RPAREN
	call_args : .  (60)

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6
	.  reduce 60

	assign  goto 19
	call_args  goto 92
	numeric  goto 29
	array_index  goto 30
	expr  goto 93
	ident  goto 32


state 75
	array_index : ident LBRACKET . expr RBRACKET

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 94
	ident  goto 32


state 76
	expr : ident DOT . ident
	assign : ident DOT . ident assign_operator expr

	IDENTIFIER  shift 1

	ident  goto 95


state 77
	assign : ident assign_operator . expr

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 96
	ident  goto 32


state 78
	array_typename : array_typename LBRACKET . CONSTANT_INT RBRACKET

	CONSTANT_INT  shift 97


state 79
	array_typename : primary_typename LBRACKET . CONSTANT_INT RBRACKET

	CONSTANT_INT  shift 98


state 80
	expr : LPAREN expr RPAREN .  (42)

	.  reduce 42


81: shift-reduce conflict (shift 7, reduce 83) on CHAR
81: shift-reduce conflict (shift 8, reduce 83) on INT
81: shift-reduce conflict (shift 9, reduce 83) on FLOAT
81: shift-reduce conflict (shift 10, reduce 83) on DOUBLE
81: shift-reduce conflict (shift 11, reduce 83) on VOID
81: shift-reduce conflict (shift 12, reduce 83) on BOOL
81: shift-reduce conflict (shift 99, reduce 83) on STRUCT
state 81
	struct_dec : STRUCT ident LBRACE . struct_members RBRACE
	struct_members : .  (83)

	CHAR  shift 7
	INT  shift 8
	FLOAT  shift 9
	DOUBLE  shift 10
	VOID  shift 11
	BOOL  shift 12
	STRUCT  shift 99
	.  reduce 83

	struct_members  goto 100
	var_dec  goto 101
	typename  goto 102
	array_typename  goto 33
	primary_typename  goto 34
	struct_typename  goto 35


state 82
	block : LBRACE . statements RBRACE
	block : LBRACE . RBRACE

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	RBRACE  shift 103
	LPAREN  shift 5
	MINUS_OP  shift 6
	CHAR  shift 7
	INT  shift 8
	FLOAT  shift 9
	DOUBLE  shift 10
	VOID  shift 11
	BOOL  shift 12
	STRUCT  shift 13
	IF  shift 14
	WHILE  shift 15
	FOR  shift 16
	RETURN  shift 17

	while_stmt  goto 18
	assign  goto 19
	statements  goto 104
	if_stmt  goto 21
	for_stmt  goto 22
	var_dec  goto 24
	func_dec  goto 25
	struct_dec  goto 26
	statement  goto 27
	typename  goto 28
	numeric  goto 29
	array_index  goto 30
	expr  goto 31
	ident  goto 32
	array_typename  goto 33
	primary_typename  goto 34
	struct_typename  goto 35


state 83
	if_stmt : IF expr block . ELSE if_stmt
	if_stmt : IF expr block .  (77)
	if_stmt : IF expr block . ELSE block

	ELSE  shift 105
	.  reduce 77


state 84
	expr : expr . binary_operator expr
	while_stmt : WHILE LPAREN expr . RPAREN block

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	RPAREN  shift 106
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72

	binary_operator  goto 73


state 85
	expr : expr . binary_operator expr
	for_stmt : FOR LPAREN expr . SEMICOLON expr SEMICOLON expr RPAREN block

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	SEMICOLON  shift 107
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72

	binary_operator  goto 73


state 86
	statement : RETURN expr SEMICOLON .  (8)

	.  reduce 8


state 87
	var_dec : typename ident EQUAL . LBRACE call_args RBRACE
	var_dec : typename ident EQUAL . expr

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LBRACE  shift 108
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 109
	ident  goto 32


state 88
	func_dec : typename ident LPAREN . func_dec_args RPAREN block
	func_dec_args : .  (30)

	CHAR  shift 7
	INT  shift 8
	FLOAT  shift 9
	DOUBLE  shift 10
	VOID  shift 11
	BOOL  shift 12
	STRUCT  shift 99
	.  reduce 30

	func_dec_args  goto 110
	var_dec  goto 111
	typename  goto 102
	array_typename  goto 33
	primary_typename  goto 34
	struct_typename  goto 35


state 89
	expr : expr . binary_operator expr
	array_index : array_index LBRACKET expr . RBRACKET

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	RBRACKET  shift 112
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72

	binary_operator  goto 73


90: shift-reduce conflict (shift 58, reduce 49) on LE_OP
90: shift-reduce conflict (shift 59, reduce 49) on GE_OP
90: shift-reduce conflict (shift 60, reduce 49) on EQ_OP
90: shift-reduce conflict (shift 61, reduce 49) on NE_OP
90: shift-reduce conflict (shift 62, reduce 49) on LT_OP
90: shift-reduce conflict (shift 63, reduce 49) on GT_OP
90: shift-reduce conflict (shift 65, reduce 49) on AND_OP
90: shift-reduce conflict (shift 66, reduce 49) on MINUS_OP
90: shift-reduce conflict (shift 67, reduce 49) on PLUS_OP
90: shift-reduce conflict (shift 68, reduce 49) on MUL_OP
90: shift-reduce conflict (shift 69, reduce 49) on DIV_OP
90: shift-reduce conflict (shift 70, reduce 49) on MOD_OP
90: shift-reduce conflict (shift 71, reduce 49) on XOR_OP
90: shift-reduce conflict (shift 72, reduce 49) on OR_OP
state 90
	expr : expr . binary_operator expr
	assign : array_index assign_operator expr .  (49)

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72
	.  reduce 49

	binary_operator  goto 73


91: shift-reduce conflict (shift 58, reduce 41) on LE_OP
91: shift-reduce conflict (shift 59, reduce 41) on GE_OP
91: shift-reduce conflict (shift 60, reduce 41) on EQ_OP
91: shift-reduce conflict (shift 61, reduce 41) on NE_OP
91: shift-reduce conflict (shift 62, reduce 41) on LT_OP
91: shift-reduce conflict (shift 63, reduce 41) on GT_OP
91: shift-reduce conflict (shift 65, reduce 41) on AND_OP
91: shift-reduce conflict (shift 66, reduce 41) on MINUS_OP
91: shift-reduce conflict (shift 67, reduce 41) on PLUS_OP
91: shift-reduce conflict (shift 68, reduce 41) on MUL_OP
91: shift-reduce conflict (shift 69, reduce 41) on DIV_OP
91: shift-reduce conflict (shift 70, reduce 41) on MOD_OP
91: shift-reduce conflict (shift 71, reduce 41) on XOR_OP
91: shift-reduce conflict (shift 72, reduce 41) on OR_OP
state 91
	expr : expr binary_operator expr .  (41)
	expr : expr . binary_operator expr

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72
	.  reduce 41

	binary_operator  goto 73


state 92
	expr : ident LPAREN call_args . RPAREN
	call_args : call_args . COMMA expr

	COMMA  shift 113
	RPAREN  shift 114


state 93
	call_args : expr .  (61)
	expr : expr . binary_operator expr

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72
	.  reduce 61

	binary_operator  goto 73


state 94
	expr : expr . binary_operator expr
	array_index : ident LBRACKET expr . RBRACKET

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	RBRACKET  shift 115
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72

	binary_operator  goto 73


state 95
	expr : ident DOT ident .  (39)
	assign : ident DOT ident . assign_operator expr

	MUL_ASSIGN  shift 47
	DIV_ASSIGN  shift 48
	MOD_ASSIGN  shift 49
	ADD_ASSIGN  shift 50
	SUB_ASSIGN  shift 51
	AND_ASSIGN  shift 52
	XOR_ASSIGN  shift 53
	OR_ASSIGN  shift 54
	EQUAL  shift 55
	.  reduce 39

	assign_operator  goto 116


96: shift-reduce conflict (shift 58, reduce 48) on LE_OP
96: shift-reduce conflict (shift 59, reduce 48) on GE_OP
96: shift-reduce conflict (shift 60, reduce 48) on EQ_OP
96: shift-reduce conflict (shift 61, reduce 48) on NE_OP
96: shift-reduce conflict (shift 62, reduce 48) on LT_OP
96: shift-reduce conflict (shift 63, reduce 48) on GT_OP
96: shift-reduce conflict (shift 65, reduce 48) on AND_OP
96: shift-reduce conflict (shift 66, reduce 48) on MINUS_OP
96: shift-reduce conflict (shift 67, reduce 48) on PLUS_OP
96: shift-reduce conflict (shift 68, reduce 48) on MUL_OP
96: shift-reduce conflict (shift 69, reduce 48) on DIV_OP
96: shift-reduce conflict (shift 70, reduce 48) on MOD_OP
96: shift-reduce conflict (shift 71, reduce 48) on XOR_OP
96: shift-reduce conflict (shift 72, reduce 48) on OR_OP
state 96
	assign : ident assign_operator expr .  (48)
	expr : expr . binary_operator expr

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72
	.  reduce 48

	binary_operator  goto 73


state 97
	array_typename : array_typename LBRACKET CONSTANT_INT . RBRACKET

	RBRACKET  shift 117


state 98
	array_typename : primary_typename LBRACKET CONSTANT_INT . RBRACKET

	RBRACKET  shift 118


state 99
	struct_typename : STRUCT . ident

	IDENTIFIER  shift 1

	ident  goto 119


state 100
	struct_members : struct_members . var_dec
	struct_dec : STRUCT ident LBRACE struct_members . RBRACE

	RBRACE  shift 120
	CHAR  shift 7
	INT  shift 8
	FLOAT  shift 9
	DOUBLE  shift 10
	VOID  shift 11
	BOOL  shift 12
	STRUCT  shift 99

	var_dec  goto 121
	typename  goto 102
	array_typename  goto 33
	primary_typename  goto 34
	struct_typename  goto 35


state 101
	struct_members : var_dec .  (84)

	.  reduce 84


state 102
	var_dec : typename . ident EQUAL LBRACE call_args RBRACE
	var_dec : typename . ident EQUAL expr
	var_dec : typename . ident

	IDENTIFIER  shift 1

	ident  goto 122


state 103
	block : LBRACE RBRACE .  (13)

	.  reduce 13


state 104
	statements : statements . statement
	block : LBRACE statements . RBRACE

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	RBRACE  shift 123
	LPAREN  shift 5
	MINUS_OP  shift 6
	CHAR  shift 7
	INT  shift 8
	FLOAT  shift 9
	DOUBLE  shift 10
	VOID  shift 11
	BOOL  shift 12
	STRUCT  shift 13
	IF  shift 14
	WHILE  shift 15
	FOR  shift 16
	RETURN  shift 17

	while_stmt  goto 18
	assign  goto 19
	if_stmt  goto 21
	for_stmt  goto 22
	var_dec  goto 24
	func_dec  goto 25
	struct_dec  goto 26
	statement  goto 43
	typename  goto 28
	numeric  goto 29
	array_index  goto 30
	expr  goto 31
	ident  goto 32
	array_typename  goto 33
	primary_typename  goto 34
	struct_typename  goto 35


state 105
	if_stmt : IF expr block ELSE . if_stmt
	if_stmt : IF expr block ELSE . block

	LBRACE  shift 82
	IF  shift 14

	block  goto 124
	if_stmt  goto 125


state 106
	while_stmt : WHILE LPAREN expr RPAREN . block

	LBRACE  shift 82

	block  goto 126


state 107
	for_stmt : FOR LPAREN expr SEMICOLON . expr SEMICOLON expr RPAREN block

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 127
	ident  goto 32


state 108
	var_dec : typename ident EQUAL LBRACE . call_args RBRACE
	call_args : .  (60)

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6
	.  reduce 60

	assign  goto 19
	call_args  goto 128
	numeric  goto 29
	array_index  goto 30
	expr  goto 93
	ident  goto 32


state 109
	var_dec : typename ident EQUAL expr .  (27)
	expr : expr . binary_operator expr

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72
	.  reduce 27

	binary_operator  goto 73


state 110
	func_dec : typename ident LPAREN func_dec_args . RPAREN block
	func_dec_args : func_dec_args . COMMA var_dec

	COMMA  shift 129
	RPAREN  shift 130


state 111
	func_dec_args : var_dec .  (31)

	.  reduce 31


state 112
	array_index : array_index LBRACKET expr RBRACKET .  (47)

	.  reduce 47


state 113
	call_args : call_args COMMA . expr

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 131
	ident  goto 32


state 114
	expr : ident LPAREN call_args RPAREN .  (37)

	.  reduce 37


state 115
	array_index : ident LBRACKET expr RBRACKET .  (46)

	.  reduce 46


state 116
	assign : ident DOT ident assign_operator . expr

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 132
	ident  goto 32


state 117
	array_typename : array_typename LBRACKET CONSTANT_INT RBRACKET .  (21)

	.  reduce 21


state 118
	array_typename : primary_typename LBRACKET CONSTANT_INT RBRACKET .  (20)

	.  reduce 20


state 119
	struct_typename : STRUCT ident .  (22)

	.  reduce 22


state 120
	struct_dec : STRUCT ident LBRACE struct_members RBRACE .  (82)

	.  reduce 82


state 121
	struct_members : struct_members var_dec .  (85)

	.  reduce 85


state 122
	var_dec : typename ident . EQUAL LBRACE call_args RBRACE
	var_dec : typename ident . EQUAL expr
	var_dec : typename ident .  (26)

	EQUAL  shift 87
	.  reduce 26


state 123
	block : LBRACE statements RBRACE .  (12)

	.  reduce 12


state 124
	if_stmt : IF expr block ELSE block .  (78)

	.  reduce 78


state 125
	if_stmt : IF expr block ELSE if_stmt .  (79)

	.  reduce 79


state 126
	while_stmt : WHILE LPAREN expr RPAREN block .  (81)

	.  reduce 81


state 127
	expr : expr . binary_operator expr
	for_stmt : FOR LPAREN expr SEMICOLON expr . SEMICOLON expr RPAREN block

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	SEMICOLON  shift 133
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72

	binary_operator  goto 73


state 128
	var_dec : typename ident EQUAL LBRACE call_args . RBRACE
	call_args : call_args . COMMA expr

	RBRACE  shift 134
	COMMA  shift 113


state 129
	func_dec_args : func_dec_args COMMA . var_dec

	CHAR  shift 7
	INT  shift 8
	FLOAT  shift 9
	DOUBLE  shift 10
	VOID  shift 11
	BOOL  shift 12
	STRUCT  shift 99

	var_dec  goto 135
	typename  goto 102
	array_typename  goto 33
	primary_typename  goto 34
	struct_typename  goto 35


state 130
	func_dec : typename ident LPAREN func_dec_args RPAREN . block

	LBRACE  shift 82

	block  goto 136


state 131
	expr : expr . binary_operator expr
	call_args : call_args COMMA expr .  (62)

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72
	.  reduce 62

	binary_operator  goto 73


state 132
	expr : expr . binary_operator expr
	assign : ident DOT ident assign_operator expr .  (50)

	.  reduce 50

	binary_operator  goto 73


state 133
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON . expr RPAREN block

	IDENTIFIER  shift 1
	STRING_LITERAL  shift 2
	CONSTANT_INT  shift 3
	CONSTANT_DOUBLE  shift 4
	LPAREN  shift 5
	MINUS_OP  shift 6

	assign  goto 19
	numeric  goto 29
	array_index  goto 30
	expr  goto 137
	ident  goto 32


state 134
	var_dec : typename ident EQUAL LBRACE call_args RBRACE .  (28)

	.  reduce 28


state 135
	func_dec_args : func_dec_args COMMA var_dec .  (32)

	.  reduce 32


state 136
	func_dec : typename ident LPAREN func_dec_args RPAREN block .  (29)

	.  reduce 29


state 137
	expr : expr . binary_operator expr
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr . RPAREN block

	LE_OP  shift 58
	GE_OP  shift 59
	EQ_OP  shift 60
	NE_OP  shift 61
	LT_OP  shift 62
	GT_OP  shift 63
	RPAREN  shift 138
	AND_OP  shift 65
	MINUS_OP  shift 66
	PLUS_OP  shift 67
	MUL_OP  shift 68
	DIV_OP  shift 69
	MOD_OP  shift 70
	XOR_OP  shift 71
	OR_OP  shift 72

	binary_operator  goto 73


state 138
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN . block

	LBRACE  shift 82

	block  goto 139


state 139
	for_stmt : FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN block .  (80)

	.  reduce 80


##############################################################################
# Summary
##############################################################################

State 81 contains 7 shift-reduce conflict(s)
State 90 contains 14 shift-reduce conflict(s)
State 91 contains 14 shift-reduce conflict(s)
State 96 contains 14 shift-reduce conflict(s)


51 token(s), 25 nonterminal(s)
86 grammar rule(s), 140 state(s)


##############################################################################
# End of File
##############################################################################
