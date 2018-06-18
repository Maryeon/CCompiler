all: compiler

OBJS = Parser/parser.o \
			 Lexer/lexer.o  \
		 	 IntermediateCodeGen/CodeGen.o \
			 IntermediateCodeGen/ArrayGen.o \
			 IntermediateCodeGen/StructGen.o \
			 IntermediateCodeGen/LogicGen.o \
			 IntermediateCodeGen/DecGen.o \
		 	 main.o	 \
			 ObjGen/ObjGen.o \
			 TypeSystem/TypeSystem.o \

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++11
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib 
LIBS = `$(LLVMCONFIG) --libs`

clean:
	$(RM) -rf compiler Parser/parser.cpp Parser/parser.hpp  Lexer/lexer.cpp  $(OBJS)

#ObjGen.cpp: ObjGen.h

#CodeGen.cpp: CodeGen.h absyn.h

Parser/parser.cpp: Parser/parser.y
	bison -d -o $@ $<

Parser/parser.hpp: Parser/parser.cpp

Parser/parser.o: Parser/parser.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

Lexer/lexer.cpp: Lexer/lexer.l Parser/parser.hpp
	flex -o $@ $<

ObjGen/ObjGen.o: ObjGen/ObjGen.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

IntermediateCodeGen/CodeGen.o: IntermediateCodeGen/CodeGen.cpp 
	g++  -c $(CPPFLAGS) -o $@ $<

IntermediateCodeGen/ArrayGen.o: IntermediateCodeGen/ArrayGen.cpp
	g++  -c $(CPPFLAGS) -o $@ $<

IntermediateCodeGen/StructGen.o: IntermediateCodeGen/StructGen.cpp
	g++  -c $(CPPFLAGS) -o $@ $<

IntermediateCodeGen/LogicGen.o:  IntermediateCodeGen/LogicGen.cpp
	g++  -c $(CPPFLAGS) -o $@ $<

IntermediateCodeGen/DecGen.o: IntermediateCodeGen/DecGen.cpp
	g++  -c $(CPPFLAGS) -o $@ $<

TypeSystem/TypeSystem.o: TypeSystem/TypeSystem.cpp
	g++ -c $(CPPFLAGS) -o $@ $<

#%.o: %.cpp
#	g++ -c $(CPPFLAGS) -o $@ $<

compiler: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)


