CC=gcc
F=flex
CFLAGS=-o
LFLAGS=-lfl
FNAME=mini.lex

###################################
# ========== Core Makes ========= #
###################################

all: mini tests

mini: primes.min mytest.min fibonacci.min

fibonacci.min: lexer-mini
	cat tests/fibonacci.min | bin/./lexer > output/fibonacci.out

primes.min:	lexer-mini
	cat tests/primes.min | bin/./lexer > output/primes.out

mytest.min: lexer-mini
	cat tests/mytest.min | bin/./lexer > output/mytest.out

error1.min: lexer-mini
	cat tests/error1.min | bin/./lexer > output/error1.out

error2.min: lexer-mini
	cat tests/error2.min | bin/./lexer > output/error2.out

error3.min: lexer-mini
	cat tests/error3.min | bin/./lexer > output/error3.out

error4.min: lexer-mini
	cat tests/error4.min | bin/./lexer > output/error4.out

lexer-mini: flex-mini
	$(CC) $(CFLAGS) bin/lexer lex.yy.c $(LFLAGS)

flex-mini:
	$(F) $(FNAME)

clean:
	rm lex.yy.c tests_output/*.out bin/* output/*.out

#####################################
# ========== Custom Makes ========= #
#####################################



# ===== Make Tests ===== #

tests: op.min iden.min num.min keyword.min special.min comments.min iden_error.min


# ===== Operators ===== #

op.min: lexer-op
	cat tests/op.min | bin/./lexer-op > tests_output/op.out

lexer-op: flex-op
	$(CC) $(CFLAGS) bin/lexer-op lex.yy.c $(LFLAGS)

flex-op:
	$(F) src/op.lex




# ===== Identifiers ===== #

iden.min: lexer-iden
	cat tests/iden.min | bin/./lexer-iden > tests_output/iden.out

lexer-iden: flex-iden
	$(CC) $(CFLAGS) bin/lexer-iden lex.yy.c $(LFLAGS)

flex-iden:
	$(F) src/iden.lex




# ===== Numbers ===== #

num.min: lexer-num
	cat tests/num.min | bin/./lexer-num > tests_output/num.out

lexer-num: flex-num
	$(CC) $(CFLAGS) bin/lexer-num lex.yy.c $(LFLAGS)

flex-num: 
	$(F) src/num.lex




# ===== Keywords ===== #

keyword.min: lexer-keyword
	cat tests/keyword.min | bin/./lexer-keyword > tests_output/keyword.out

lexer-keyword: flex-keyword
	$(CC) $(CFLAGS) bin/lexer-keyword lex.yy.c $(LFLAGS)	

flex-keyword:
	$(F) src/keyword.lex



# ===== Special ===== #

special.min: lexer-special
	cat tests/special.min | bin/./lexer-special > tests_output/special.out

lexer-special: flex-special
	$(CC) $(CFLAGS) bin/lexer-special lex.yy.c $(LFLAGS)

flex-special:
	$(F) src/special.lex



# ===== Comments ===== #
comments.min: lexer-comments
	cat tests/comments.min | bin/./lexer-comments > tests_output/comments.out

lexer-comments: flex-comments
	$(CC) $(CFLAGS) bin/lexer-comments lex.yy.c $(LFLAGS)

flex-comments:
	$(F) src/comments.lex


# ===== Error Identifiers ===== #

iden_error.min: lexer-iden_error
	cat tests/iden_error.min | bin/./lexer-iden_error > tests_output/iden_error.out

lexer-iden_error: flex-iden_error
	$(CC) $(CFLAGS) bin/lexer-iden_error lex.yy.c $(LFLAGS)

flex-iden_error:
	$(F) src/iden_error.lex

