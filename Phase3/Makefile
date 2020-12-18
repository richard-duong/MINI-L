CC=g++
F=flex
B=bison
CFLAGS=-std=c++14
LFLAGS=-lfl
BFLAGS=-v -d --file-prefix=parser
FNAME=mini.lex
BNAME=mini.yy
PARSER=bin/./parser

###################################
# ========== Core Makes ========= #
###################################

all: fibonacci.min mytest.min test1.min

mini: bison-mini
	$(CC) $(CFLAGS) -o bin/parser parser.tab.cc lex.yy.c $(LFLAGS)

bison-mini: flex-mini
	$(B) $(BNAME) $(BFLAGS)

flex-mini:
	$(F) $(FNAME)

fibonacci.min: mini
	cat tests/fibonacci.min | bin/parser > output/fibonacci.mil

mytest.min: mini
	cat tests/mytest.min | bin/parser > output/mytest.mil

test1.min:
	cat tests/test1.min | bin/parser > output/test1.mil

clean:
	rm lex.yy.c tests_output/*.out bin/* output/*.out y.tab.h y.tab.c y.output
