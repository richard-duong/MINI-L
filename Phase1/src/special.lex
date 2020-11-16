/*Special keyword */


%%

\;								printf("SEMICOLON\n");
\(								printf("L_PAREN\n");
\)								printf("R_PAREN\n");
\[								printf("L_SQUARE_BRACKET\n");
\]								printf("R_SQUARE_BRACKET\n");
\:								printf("COLON\n");
\,								printf("COMMA\n");
\:=								printf("ASSIGN\n");

%%

int main(){
	yylex();
}
