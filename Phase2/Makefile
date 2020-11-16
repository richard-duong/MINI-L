CC=gcc
F=flex
B=bison
CFLAGS=-o
LFLAGS=-lfl
BFLAGS=-v -d --file-prefix=y
FNAME=mini.lex
BNAME=mini.y
PARSER=bin/./parser

###################################
# ========== Core Makes ========= #
###################################

all: fibonacci.min mytest.min test1.min

mini: bison-mini
	$(CC) $(CFLAGS) bin/parser y.tab.c lex.yy.c $(LFLAGS)

bison-mini: flex-mini
	$(B) $(BNAME) $(BFLAGS)

flex-mini:
	$(F) $(FNAME)

fibonacci.min: mini
	cat tests/fibonacci.min | bin/parser > output/fibonacci.out

mytest.min: mini
	cat tests/mytest.min | bin/parser > output/mytest.out

test1.min:
	cat tests/test1.min | bin/parser > output/test1.out

clean:
	rm lex.yy.c tests_output/*.out bin/* output/*.out y.tab.h y.tab.c y.output
