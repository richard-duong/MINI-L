
%{
  #include "parser.tab.hh"
	int currLine = 1;
	int currPos = 1;
%}

digit 					[0-9]
alpha 					[a-zA-Z]
iden						[a-zA-Z0-9_]
comment					##[^\n]*\n
whitespace 			[ \r\t]+
newline					\n

%%

										/***** Comments *****/
										/********************/
{comment}						{ ++currLine; currPos = 1; }

										/***** Keywords *****/
										/********************/
function						{ currPos += yyleng; return FUNCTION; }
beginparams					{ currPos += yyleng; return BEGINPARAMS; }
endparams						{ currPos += yyleng; return ENDPARAMS; }
beginlocals					{ currPos += yyleng; return BEGINLOCALS; }
endlocals						{ currPos += yyleng; return ENDLOCALS; }
beginbody						{ currPos += yyleng; return BEGINBODY; }
endbody							{ currPos += yyleng; return ENDBODY; }
integer 						{ currPos += yyleng; return INTEGER; }
array								{ currPos += yyleng; return ARRAY; }
of									{ currPos += yyleng; return OF; }
if									{	currPos += yyleng; return IF; }
then								{ currPos += yyleng; return THEN; }
endif								{	currPos += yyleng; return ENDIF; }
else								{ currPos += yyleng; return ELSE; }
while								{	currPos += yyleng; return WHILE; }
do									{	currPos += yyleng; return DO; }
for									{	currPos += yyleng; return FOR; }
beginloop	          {	currPos += yyleng; return BEGINLOOP; }
endloop							{	currPos += yyleng; return ENDLOOP; }
continue						{	currPos += yyleng; return CONTINUE; }
read								{	currPos += yyleng; return READ; }
write								{	currPos += yyleng; return WRITE; }
and									{	currPos += yyleng; return AND; }
or									{	currPos += yyleng; return OR; }
not									{	currPos += yyleng; return NOT; }
true								{	currPos += yyleng; return TRUE; }
false								{	currPos += yyleng; return FALSE; }
return							{	currPos += yyleng; return RETURN; }

										/***** Nums, Identifier Errors, Identifiers *****/
										/************************************************/
{digit}+						{ currPos += yyleng; yylval.num = atoi(yytext); return NUM; }
{digit}+{iden}+			{	printf("Error	at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos, yytext); currPos += yyleng; exit(1);}
_+{iden}+						{ printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currLine, currPos, yytext); currPos += yyleng; exit(1);}
{alpha}+{iden}*_		{ printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n",
											currLine, currPos, yytext); currPos += yyleng; exit(1);}
{alpha}+{iden}*			{ currPos += yyleng; strcpy(yylval.iden, yytext); return IDEN; }

										/***** Operators *****/
										/*********************/
-										{ currPos += yyleng; return SUB; }
\+									{ currPos += yyleng; return ADD; }
\*									{ currPos += yyleng; return MULT; }
\/									{ currPos += yyleng; return DIV; }
\%									{ currPos += yyleng; return MOD; }
\=\=								{ currPos += yyleng; return EQ; }
\!\=								{ currPos += yyleng; return NEQ; }
\<\=								{ currPos += yyleng; return LTE; }
\>\=								{ currPos += yyleng; return GTE; }
\<									{ currPos += yyleng; return LT; }
\>									{ currPos += yyleng; return GT; }

										/***** Special Symbols *****/
										/***************************/
\;									{ currPos += yyleng; return SEMICOLON; }
\(									{ currPos += yyleng; return L_PAREN; }
\)									{ currPos += yyleng; return R_PAREN; }
\[									{ currPos += yyleng; return L_BRACK; }
\]									{ currPos += yyleng; return R_BRACK; }
\:									{ currPos += yyleng; return COLON; }
\,									{ currPos += yyleng; return COMMA; }
\:=									{ currPos += yyleng; return ASSIGN; }
	
										/***** Whitespace *****/
										/**********************/
{whitespace}				{ currPos += yyleng; }
\n									{ ++currLine; currPos = 1; } 

										/***** Unexpected Symbols *****/
										/******************************/
.										{ printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext); currPos += yyleng; exit(1);}	

%%

