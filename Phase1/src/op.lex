/* Regexes */

%%
-							printf("SUB\n");
\+						printf("ADD\n");
\*						printf("MULT\n");
\/						printf("DIV\n");
\%						printf("MOD\n");
\=\=					printf("EQ\n");
\<\>					printf("NEQ\n");
\<\=					printf("LTE\n");
\>\=					printf("GTE\n");
\<						printf("LT\n");
\>						printf("GT\n");
.							;
\n						;
%%

int main(){
	yylex();
}
