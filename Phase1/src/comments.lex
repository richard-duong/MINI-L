/* Comments ## with code until newline*/
/*Regex*/
comment		##[^\n]*\n

%%
{comment}						printf("COMMENT\n");
%%

int main(){
	yylex();
}

