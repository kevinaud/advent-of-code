CFLAGS= -O

OFILES=y.tab.o lex.yy.o main.o global.o

Parser: $(OFILES)
	g++ $(CFLAGS) $(OFILES) -o Parser

$(OFILES): global.h y.tab.h

y.tab.cpp y.tab.h: parser.yacc global.h
	yacc -d parser.yacc
	mv y.tab.c y.tab.cpp

lex.yy.cpp: parser.lex global.h
	lex parser.lex
	mv lex.yy.c lex.yy.cpp

.cpp.o:
	g++ -c $(CFLAGS) $*.cpp

clean:
	rm -f $(OFILES)
