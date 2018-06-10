all: compiler

OBJS = parser.o \
		lexer.o  \
		CodeGen.o \
		utils.o \
		main.o	 \
		ObjGen.o \
		TypeSystem.o \

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++11
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib -ljsoncpp
LIBS = `$(LLVMCONFIG) --libs`

clean:
	$(RM) -rf parser.cpp parser.hpp test compiler tokens.cpp *.output $(OBJS)

ObjGen.cpp: ObjGen.h

CodeGen.cpp: CodeGen.h absyn.h

parser.cpp: parser.y
	bison -d -o $@ $<

parser.hpp: parser.cpp

lexer.cpp: lexer.l parser.hpp
	flex -o $@ $<

%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

compiler: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)

test: compiler test.c
	cat test.c | ./compiler

