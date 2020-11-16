/* Regexes */

digit 			[0-9]
whitespace	[ \r\t]


%%

{digit}+											printf("NUM %s\n", yytext);
whitespace										;
\n														;
.															printf("NON-NUM %s\n", yytext);

%%

int main(){
	yylex();
}
