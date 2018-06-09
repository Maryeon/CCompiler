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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 06/10/18
# Time: 02:03:59
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  "/*"

    2  "//"[^\n]*

    3  "bool"

    4  "char"

    5  "double"

    6  "else"

    7  "float"

    8  "for"

    9  "if"

   10  "int"

   11  "return"

   12  "struct"

   13  "void"

   14  "while"

   15  [a-zA-Z_]([a-zA-Z_]|[0-9])*

   16  [1-9][0-9]*((u|U)|(u|U)?(l|L|ll|LL)|(l|L|ll|LL)(u|U))?

   17  [0-9]+"."[0-9]*([Ee][+-]?[0-9]+)?(f|F|l|L)?

   18  L?\"(\\.|[^\\"\n])*\"

   19  "+="

   20  "-="

   21  "*="

   22  "/="

   23  "%="

   24  "&="

   25  "^="

   26  "|="

   27  "<="

   28  ">="

   29  "=="

   30  "!="

   31  ";"

   32  "{"

   33  "}"

   34  ","

   35  "="

   36  "("

   37  ")"

   38  "["

   39  "]"

   40  "."

   41  "&"

   42  "-"

   43  "+"

   44  "*"

   45  "/"

   46  "%"

   47  "<"

   48  ">"

   49  "^"

   50  "|"

   51  [ \t\v\n\f]

   52  .


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 4
	0x0b - 0x0c (2)    goto 4
	0x0d - 0x1f (19)   goto 3
	0x20               goto 4
	0x21               goto 5
	0x22               goto 6
	0x23 - 0x24 (2)    goto 3
	0x25               goto 7
	0x26               goto 8
	0x27               goto 3
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2e               goto 15
	0x2f               goto 16
	0x30               goto 17
	0x31 - 0x39 (9)    goto 18
	0x3a               goto 3
	0x3b               goto 19
	0x3c               goto 20
	0x3d               goto 21
	0x3e               goto 22
	0x3f - 0x40 (2)    goto 3
	0x41 - 0x4b (11)   goto 23
	0x4c               goto 24
	0x4d - 0x5a (14)   goto 23
	0x5b               goto 25
	0x5c               goto 3
	0x5d               goto 26
	0x5e               goto 27
	0x5f               goto 23
	0x60               goto 3
	0x61               goto 23
	0x62               goto 28
	0x63               goto 29
	0x64               goto 30
	0x65               goto 31
	0x66               goto 32
	0x67 - 0x68 (2)    goto 23
	0x69               goto 33
	0x6a - 0x71 (8)    goto 23
	0x72               goto 34
	0x73               goto 35
	0x74 - 0x75 (2)    goto 23
	0x76               goto 36
	0x77               goto 37
	0x78 - 0x7a (3)    goto 23
	0x7b               goto 38
	0x7c               goto 39
	0x7d               goto 40
	0x7e - 0xff (130)  goto 3


state 2
	^INITIAL

	0x00 - 0x08 (9)    goto 3
	0x09               goto 4
	0x0a               goto 4
	0x0b - 0x0c (2)    goto 4
	0x0d - 0x1f (19)   goto 3
	0x20               goto 4
	0x21               goto 5
	0x22               goto 6
	0x23 - 0x24 (2)    goto 3
	0x25               goto 7
	0x26               goto 8
	0x27               goto 3
	0x28               goto 9
	0x29               goto 10
	0x2a               goto 11
	0x2b               goto 12
	0x2c               goto 13
	0x2d               goto 14
	0x2e               goto 15
	0x2f               goto 16
	0x30               goto 17
	0x31 - 0x39 (9)    goto 18
	0x3a               goto 3
	0x3b               goto 19
	0x3c               goto 20
	0x3d               goto 21
	0x3e               goto 22
	0x3f - 0x40 (2)    goto 3
	0x41 - 0x4b (11)   goto 23
	0x4c               goto 24
	0x4d - 0x5a (14)   goto 23
	0x5b               goto 25
	0x5c               goto 3
	0x5d               goto 26
	0x5e               goto 27
	0x5f               goto 23
	0x60               goto 3
	0x61               goto 23
	0x62               goto 28
	0x63               goto 29
	0x64               goto 30
	0x65               goto 31
	0x66               goto 32
	0x67 - 0x68 (2)    goto 23
	0x69               goto 33
	0x6a - 0x71 (8)    goto 23
	0x72               goto 34
	0x73               goto 35
	0x74 - 0x75 (2)    goto 23
	0x76               goto 36
	0x77               goto 37
	0x78 - 0x7a (3)    goto 23
	0x7b               goto 38
	0x7c               goto 39
	0x7d               goto 40
	0x7e - 0xff (130)  goto 3


state 3
	match 52


state 4
	match 51


state 5
	0x3d               goto 41

	match 52


state 6
	0x00 - 0x09 (10)   goto 42
	0x0b - 0x21 (23)   goto 42
	0x22               goto 43
	0x23 - 0x5b (57)   goto 42
	0x5c               goto 44
	0x5d - 0xff (163)  goto 42

	match 52


state 7
	0x3d               goto 45

	match 46


state 8
	0x3d               goto 46

	match 41


state 9
	match 36


state 10
	match 37


state 11
	0x3d               goto 47

	match 44


state 12
	0x3d               goto 48

	match 43


state 13
	match 34


state 14
	0x3d               goto 49

	match 42


state 15
	match 40


state 16
	0x2a               goto 50
	0x2f               goto 51
	0x3d               goto 52

	match 45


state 17
	0x2e               goto 53
	0x30 - 0x39 (10)   goto 54

	match 52


state 18
	0x2e               goto 53
	0x30 - 0x39 (10)   goto 18
	0x4c               goto 55
	0x55               goto 56
	0x6c               goto 57
	0x75               goto 56

	match 16


state 19
	match 31


state 20
	0x3d               goto 58

	match 47


state 21
	0x3d               goto 59

	match 35


state 22
	0x3d               goto 60

	match 48


state 23
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 15


state 24
	0x22               goto 42
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 15


state 25
	match 38


state 26
	match 39


state 27
	0x3d               goto 61

	match 49


state 28
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6e (14)   goto 23
	0x6f               goto 62
	0x70 - 0x7a (11)   goto 23

	match 15


state 29
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x67 (7)    goto 23
	0x68               goto 63
	0x69 - 0x7a (18)   goto 23

	match 15


state 30
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6e (14)   goto 23
	0x6f               goto 64
	0x70 - 0x7a (11)   goto 23

	match 15


state 31
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 65
	0x6d - 0x7a (14)   goto 23

	match 15


state 32
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 66
	0x6d - 0x6e (2)    goto 23
	0x6f               goto 67
	0x70 - 0x7a (11)   goto 23

	match 15


state 33
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x65 (5)    goto 23
	0x66               goto 68
	0x67 - 0x6d (7)    goto 23
	0x6e               goto 69
	0x6f - 0x7a (12)   goto 23

	match 15


state 34
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 70
	0x66 - 0x7a (21)   goto 23

	match 15


state 35
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 71
	0x75 - 0x7a (6)    goto 23

	match 15


state 36
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6e (14)   goto 23
	0x6f               goto 72
	0x70 - 0x7a (11)   goto 23

	match 15


state 37
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x67 (7)    goto 23
	0x68               goto 73
	0x69 - 0x7a (18)   goto 23

	match 15


state 38
	match 32


state 39
	0x3d               goto 74

	match 50


state 40
	match 33


state 41
	match 30


state 42
	0x00 - 0x09 (10)   goto 42
	0x0b - 0x21 (23)   goto 42
	0x22               goto 43
	0x23 - 0x5b (57)   goto 42
	0x5c               goto 44
	0x5d - 0xff (163)  goto 42


state 43
	match 18


state 44
	0x00 - 0x09 (10)   goto 42
	0x0b - 0xff (245)  goto 42


state 45
	match 23


state 46
	match 24


state 47
	match 21


state 48
	match 19


state 49
	match 20


state 50
	match 1


state 51
	0x00 - 0x09 (10)   goto 51
	0x0b - 0xff (245)  goto 51

	match 2


state 52
	match 22


state 53
	0x30 - 0x39 (10)   goto 53
	0x45               goto 75
	0x46               goto 76
	0x4c               goto 76
	0x65               goto 75
	0x66               goto 76
	0x6c               goto 76

	match 17


state 54
	0x2e               goto 53
	0x30 - 0x39 (10)   goto 54


state 55
	0x4c               goto 77
	0x55               goto 78
	0x75               goto 78

	match 16


state 56
	0x4c               goto 79
	0x6c               goto 80

	match 16


state 57
	0x55               goto 78
	0x6c               goto 77
	0x75               goto 78

	match 16


state 58
	match 27


state 59
	match 29


state 60
	match 28


state 61
	match 25


state 62
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6e (14)   goto 23
	0x6f               goto 81
	0x70 - 0x7a (11)   goto 23

	match 15


state 63
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61               goto 82
	0x62 - 0x7a (25)   goto 23

	match 15


state 64
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x74 (20)   goto 23
	0x75               goto 83
	0x76 - 0x7a (5)    goto 23

	match 15


state 65
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x72 (18)   goto 23
	0x73               goto 84
	0x74 - 0x7a (7)    goto 23

	match 15


state 66
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6e (14)   goto 23
	0x6f               goto 85
	0x70 - 0x7a (11)   goto 23

	match 15


state 67
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 86
	0x73 - 0x7a (8)    goto 23

	match 15


state 68
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 9


state 69
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 87
	0x75 - 0x7a (6)    goto 23

	match 15


state 70
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 88
	0x75 - 0x7a (6)    goto 23

	match 15


state 71
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 89
	0x73 - 0x7a (8)    goto 23

	match 15


state 72
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x68 (8)    goto 23
	0x69               goto 90
	0x6a - 0x7a (17)   goto 23

	match 15


state 73
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x68 (8)    goto 23
	0x69               goto 91
	0x6a - 0x7a (17)   goto 23

	match 15


state 74
	match 26


state 75
	0x2b               goto 92
	0x2d               goto 92
	0x30 - 0x39 (10)   goto 93


state 76
	match 17


state 77
	0x55               goto 78
	0x75               goto 78

	match 16


state 78
	match 16


state 79
	0x4c               goto 78

	match 16


state 80
	0x6c               goto 78

	match 16


state 81
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 94
	0x6d - 0x7a (14)   goto 23

	match 15


state 82
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 95
	0x73 - 0x7a (8)    goto 23

	match 15


state 83
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61               goto 23
	0x62               goto 96
	0x63 - 0x7a (24)   goto 23

	match 15


state 84
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 97
	0x66 - 0x7a (21)   goto 23

	match 15


state 85
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61               goto 98
	0x62 - 0x7a (25)   goto 23

	match 15


state 86
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 8


state 87
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 10


state 88
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x74 (20)   goto 23
	0x75               goto 99
	0x76 - 0x7a (5)    goto 23

	match 15


state 89
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x74 (20)   goto 23
	0x75               goto 100
	0x76 - 0x7a (5)    goto 23

	match 15


state 90
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x63 (3)    goto 23
	0x64               goto 101
	0x65 - 0x7a (22)   goto 23

	match 15


state 91
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 102
	0x6d - 0x7a (14)   goto 23

	match 15


state 92
	0x30 - 0x39 (10)   goto 93


state 93
	0x30 - 0x39 (10)   goto 93
	0x46               goto 76
	0x4c               goto 76
	0x66               goto 76
	0x6c               goto 76

	match 17


state 94
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 3


state 95
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 4


state 96
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6b (11)   goto 23
	0x6c               goto 103
	0x6d - 0x7a (14)   goto 23

	match 15


state 97
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 6


state 98
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 104
	0x75 - 0x7a (6)    goto 23

	match 15


state 99
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x71 (17)   goto 23
	0x72               goto 105
	0x73 - 0x7a (8)    goto 23

	match 15


state 100
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x62 (2)    goto 23
	0x63               goto 106
	0x64 - 0x7a (23)   goto 23

	match 15


state 101
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 13


state 102
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 107
	0x66 - 0x7a (21)   goto 23

	match 15


state 103
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x64 (4)    goto 23
	0x65               goto 108
	0x66 - 0x7a (21)   goto 23

	match 15


state 104
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 7


state 105
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x6d (13)   goto 23
	0x6e               goto 109
	0x6f - 0x7a (12)   goto 23

	match 15


state 106
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x73 (19)   goto 23
	0x74               goto 110
	0x75 - 0x7a (6)    goto 23

	match 15


state 107
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 14


state 108
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 5


state 109
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 11


state 110
	0x30 - 0x39 (10)   goto 23
	0x41 - 0x5a (26)   goto 23
	0x5f               goto 23
	0x61 - 0x7a (26)   goto 23

	match 12


#############################################################################
# Summary
#############################################################################

1 start state(s)
52 expression(s), 110 state(s)


#############################################################################
# End of File
#############################################################################
