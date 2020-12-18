%{
#include "stdio.h"
#include "stdlib.h"



extern int currLine;
extern int currPos;
extern char* yytext;

int yylex(void);
int yyerror(const char* msg){
  printf("BISON: Error at line %d, column %d : unexpected value \"%s\" encountered\n", currLine, currPos, yytext);
  exit(1);
  return 1;
}

%}

%union
{
  int num;
  char iden[50];
}

%error-verbose
%start prog

%token FUNCTION BEGINPARAMS ENDPARAMS BEGINLOCALS ENDLOCALS BEGINBODY
%token ENDBODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOR BEGINLOOP
%token ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN
%token SEMICOLON L_PAREN R_PAREN L_BRACK R_BRACK COLON COMMA ASSIGN

%token <num> NUM
%token <iden> IDEN

%left MULT DIV MOD ADD SUB
%left LT LTE GT GTE EQ NEQ
%right NOT
%left AND OR
%right ASSIGN

%%

prog:             func_cycle { printf("prog -> func_cycle\n"); }
                  ;

func_cycle:       // eps { printf("func_cycle -> epsilon\n"); }
                  | func_cycle FUNCTION IDEN SEMICOLON BEGINPARAMS decl_cycle ENDPARAMS BEGINLOCALS decl_cycle ENDLOCALS BEGINBODY stmt_cycle ENDBODY { printf("func_cycle -> func_cycle FUNCTION IDEN %s SEMICOLON BEGINPARAMS decl_cycle ENDPARAMS BEGINLOCALS decl_cycle ENDLOCALS BEGINBODY stmt_cycle ENDBODY\n", $3); }
                  ;

decl_cycle:       // eps  { printf("decl_cycle -> epsilon\n"); }
                  | decl_cycle decl SEMICOLON { printf("decl_cycle -> decl_cycle decl SEMICOLON\n"); }
                  ;

decl:             iden_cycle COLON arr_cycle INTEGER { printf("decl -> iden_cycle COLON arr_cycle INTEGER\n"); }
                  ;

iden_cycle:       IDEN { printf("iden_cycle -> IDEN %s\n", $1); }
                  | iden_cycle COMMA IDEN { printf("iden_cycle -> iden_cycle COMMA IDEN %s\n", $3); }
                  ;

arr_cycle:        // eps { printf("arr_cycle -> epsilon\n"); }
                  | ARRAY L_BRACK NUM R_BRACK inner_arr OF  { printf("arr_cycle -> ARRAY L_BRACK NUM %d R_BRACK inner_arr OF\n", $3); }
                  ;


inner_arr:        // eps { printf("inner_arr -> epsilon\n"); }
                  | L_BRACK NUM R_BRACK { printf("L_BRACK NUM %d R_BRACK\n", $2); }
                  ;


stmt_cycle:       stmt SEMICOLON { printf("stmt_cycle -> stmt SEMICOLON\n"); }
                  | stmt_cycle stmt SEMICOLON  { printf("stmt_cycle -> stmt_cycle stmt SEMICOLON\n"); }
                  ;

assign_cycle:     var ASSIGN exp { printf("assign_cycle -> var ASSIGN exp\n"); }
                  ;

if_cycle:         IF bool_exp THEN stmt_cycle stmt SEMICOLON else_cycle ENDIF { printf("if_cycle -> IF bool_exp THEN stmt_cycle stmt SEMICOLON else_cycle ENDIF\n"); }
                  ;

else_cycle:       // eps  { printf("else_cycle -> epsilon\n"); }
                  | ELSE stmt_cycle stmt SEMICOLON { printf("else_cycle -> ELSE stmt_cycle stmt SEMICOLON\n"); }
                  ;

while_cycle:      WHILE bool_exp BEGINLOOP stmt_cycle stmt SEMICOLON ENDLOOP { printf("while_cycle -> WHILE bool_exp BEGINLOOP stmt_cycle stmt SEMICOLON ENDLOOP\n"); }
                  ;

do_cycle:         DO BEGINLOOP stmt_cycle stmt SEMICOLON ENDLOOP WHILE bool_exp { printf("do_cycle -> DO BEGINLOOP stmt_cycle stmt SEMICOLON ENDLOOP WHILE bool_exp\n"); }
                  ;

for_cycle:        FOR var ASSIGN NUM SEMICOLON bool_exp SEMICOLON var ASSIGN exp BEGINLOOP stmt_cycle stmt SEMICOLON ENDLOOP { printf("for_cycle -> FOR var ASSIGN NUM %d SEMICOLON bool_exp SEMICOLON var ASSIGN exp BEGINLOOP stmt_cycle stmt SEMICOLON ENDLOOP\n", $4); }
                  ;

read_cycle:       READ var_cycle { printf("read_cycle -> READ var_cycle\n"); }
                  ;

write_cycle:      WRITE var_cycle { printf("write_cycle -> WRITE var_cycle\n"); }
                  ;

continue_cycle:   CONTINUE { printf("continue_cycle -> CONTINUE\n"); }
                  ;

return_cycle:     RETURN exp { printf("return_cycle -> RETURN exp\n"); }
                  ;

var_cycle:        var { printf("var_cycle -> var\n"); }
                  | var_cycle COMMA var { printf("var_cycle -> var_cycle COMMA var\n"); }
                  ;

stmt:             assign_cycle { printf("stmt -> assign_cycle\n"); }
                  | if_cycle { printf("stmt -> if_cycle\n"); }
                  | while_cycle { printf("stmt -> while_cycle\n"); }
                  | do_cycle { printf("stmt -> do_cycle\n"); }
                  | for_cycle { printf("stmt -> for_cycle\n"); }
                  | read_cycle { printf("stmt -> read_cycle\n"); }
                  | write_cycle { printf("stmt -> write_cycle\n"); }
                  | continue_cycle { printf("stmt -> continue_cycle\n"); }
                  | return_cycle { printf("stmt -> return_cycle\n"); }
                  ;

bool_exp:         rel_and_exp { printf("bool_exp -> rel_and_exp\n"); }
                  | bool_exp OR rel_and_exp { printf("bool_exp -> bool_exp OR rel_and_exp\n"); }
                  ;

rel_and_exp:      rel_exp { printf("rel_and_exp -> rel_exp\n"); }
                  | rel_and_exp AND rel_exp { printf("rel_and_exp -> rel_and_exp AND rel_exp\n"); }
                  ;

rel_exp:          rel_exp_base { printf("rel_exp -> rel_exp_base\n"); }
                  | NOT rel_exp_base { printf(" rel_exp -> NOT rel_exp_base\n"); }
                  ;

rel_exp_base:     exp comp exp { printf("rel_exp_base -> exp comp exp\n"); } 
                  | TRUE { printf("rel_exp_base -> TRUE\n"); }
                  | FALSE { printf("rel_exp_base -> FALSE\n"); }
                  | L_PAREN bool_exp R_PAREN { printf("rel_exp_base -> L_PAREN bool_exp R_PAREN\n"); }
                  ;

comp:             EQ { printf("comp -> EQ\n"); }
                  | NEQ { printf("comp -> NEQ\n"); }
                  | LT { printf("comp -> LT\n"); }
                  | GT { printf("comp -> GT\n"); }
                  | LTE { printf("comp -> LTE\n"); }
                  | GTE { printf("comp -> GTE\n"); }
                  ;

exp:              mult_exp { printf("exp -> mult_exp\n"); }
                  | exp mult_cycle mult_exp { printf("exp -> exp mult_cycle mult_exp\n"); }
                  ;



mult_cycle:       ADD { printf("mult_cycle -> ADD\n"); }
                  | SUB { printf("mult_cycle -> SUB\n"); }
                  ;

mult_exp:         term { printf("mult_exp -> term\n"); }
                  | mult_exp term_cycle term { printf("mult_exp -> mult_exp term_cycle term\n"); }
                  ;

term_cycle:       MULT { printf("term_cycle -> MULT\n"); }
                  | DIV { printf("term_cycle -> DIV\n"); }
                  | MOD { printf("term_cycle -> MOD\n"); }
                  ;

term:             term_base { printf("term -> term_base\n"); }
                  | SUB term_base { printf("term -> SUB term_base\n"); }
                  | IDEN L_PAREN param_cycle R_PAREN { printf("term -> IDEN %s L_PAREN param_cycle R_PAREN\n", $1); }
                  ;

term_base:        var { printf("term_base -> var\n"); }
                  | NUM { printf("term_base -> NUM %d\n", $1); }
                  | L_PAREN exp R_PAREN { printf("term_base -> L_PAREN exp R_PAREN\n"); }
                  ;

param_cycle:      // eps { printf("param_cycle -> epsilon\n"); }
                  | exp_cycle { printf("param_cycle -> exp_cycle\n"); }
                  ;

exp_cycle:        exp { printf("exp_cycle -> exp\n"); }
                  | exp_cycle COMMA exp { printf("exp_cycle -> exp_cycle COMMA exp\n"); }
                  ;

var:              IDEN var_cycle { printf("var -> IDEN %s var_cycle\n", $1); }
                  ;

var_cycle:        // eps { printf("var_cycle -> epsilon\n"); }
                  | L_BRACK exp R_BRACK inner_var { printf("var_cycle -> L_BRACK exp R_BRACK inner_var\n"); }
                  ;


inner_var:        // eps { printf("inner_var -> epsilon\n"); }
                  | L_BRACK exp R_BRACK { printf("inner_var -> L_BRACK exp R_BRACK\n"); }
                  ;

*/
%%



int main(){
  yyparse();

}
