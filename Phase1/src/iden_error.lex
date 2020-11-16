
alpha 				[a-zA-Z]
digit					[0-9]
iden					[a-zA-Z0-9_]
whitespace 		[ \r\t]

%{
	int currLine = 1;
	int currPos = 1;	
%}

%%

{digit}+						{	printf("Number: %s\n", yytext); currPos += yyleng;}
{digit}+{iden}+			{	printf("Error	at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos, yytext); currPos += yyleng;}
_+{iden}+						{ printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos, yytext); currPos += yyleng;}
{alpha}+{iden}*_		{ printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currLine, currPos, yytext); currPos += yyleng;}
{alpha}+{iden}*			{ printf("Identifier: %s\n", yytext);	currPos += yyleng;}

{whitespace}+				{currPos += yyleng;}
\n									{ ++currLine;		currPos = 1;}

%%


int main(){
	yylex();
}
