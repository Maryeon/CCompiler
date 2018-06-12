all: compiler

OBJS = Parser/parser.o \
			 Lexer/lexer.o  \
		 	 IntermediateCodeGen/CodeGen.o \
		 	 main.o	 \
			 ObjGen/ObjGen.o \
			 TypeSystem/TypeSystem.o \

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++11
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib 
LIBS = `$(LLVMCONFIG) --libs`

clean:
	$(RM) -rf Parser/parser.cpp Parser/parser.hpp  compiler Lexer/lexer.cpp  $(OBJS)

#ObjGen.cpp: ObjGen.h

#CodeGen.cpp: CodeGen.h absyn.h

Parser/parser.cpp: Parser/parser.y
	bison -d -o $@ $<

Parser/parser.hpp: Parser/parser.cpp

Lexer/lexer.cpp: Lexer/lexer.l Parser/parser.hpp
	flex -o $@ $<

ObjGen/ObjGen.o: ObjGen/ObjGen.cpp

IntermediateCodeGen/CodeGen.o: IntermediateCodeGen/CodeGen.cpp

TypeSystem/TypeSystem.o: TypeSystem/TypeSystem.cpp

%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

compiler: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)


