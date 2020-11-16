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

%token FUNCTION BEGINPARAMS ENDPARAMS BEGINLOCALS ENDLOCALS BEGINBODY ENDBODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOR BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN SEMICOLON L_PAREN R_PAREN L_BRACK R_BRACK COLON COMMA ASSIGN

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
                  | iden_cycle COMMA IDEN{ printf("iden_cycle -> iden_cycle COMMA IDEN %s\n", $3); }
                  ;

stmt_cycle:       stmt SEMICOLON { printf("stmt_cycle -> stmt SEMICOLON\n"); }
                  | stmt_cycle stmt SEMICOLON { printf("stmt_cycle -> stmt_cycle stmt SEMICOLON\n"); }
                  ;


arr_cycle:        // epsilon { printf("arr_cycle -> epsilon\n"); }
                  | ARRAY L_BRACK NUM R_BRACK OF { printf("arr_cycle -> ARRAY L_BRACK NUM %d R_BRACK OF\n", $3); }
                  | ARRAY L_BRACK NUM R_BRACK L_BRACK NUM R_BRACK OF { printf("arr_cycle -> ARRAY L_BRACK NUM %d R_BRACK L_BRACK NUM %d R_BRACK OF\n", $3, $6); }
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

assign_cycle:     var ASSIGN exp { printf("assign_cycle -> var ASSIGN exp\n"); }
                  ;

if_cycle:         IF bool_exp THEN stmt_cycle else_cycle ENDIF { printf("if_cycle -> IF bool_exp THEN stmt_cycle else_cycle ENDIF\n"); }
                  ;

else_cycle:       // eps  { printf("else_cycle -> epsilon\n"); }
                  | ELSE stmt_cycle { printf("else_cycle -> ELSE stmt_cycle\n"); }
                  ;

while_cycle:      WHILE bool_exp BEGINLOOP stmt_cycle ENDLOOP { printf("while_cycle -> WHILE bool_exp BEGINLOOP stmt_cycle ENDLOOP\n"); }
                  ;

do_cycle:         DO BEGINLOOP stmt_cycle ENDLOOP WHILE bool_exp { printf("do_cycle -> DO BEGINLOOP stmt_cycle ENDLOOP WHILE bool_exp\n"); }
                  ;

for_cycle:        FOR var ASSIGN NUM SEMICOLON bool_exp SEMICOLON var ASSIGN exp BEGINLOOP stmt_cycle ENDLOOP { printf("for_cycle -> FOR var ASSIGN NUM %d SEMICOLON bool_exp SEMICOLON var ASSIGN exp BEGINLOOP stmt_cycle ENDLOOP\n", $4); }
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

exp:              mult_exp mult_cycle { printf("exp -> mult_exp mult_cycle\n"); }
                  ;

mult_cycle:       // epsilon { printf("mult_cycle -> epsilon\n"); }
                  | ADD mult_exp mult_cycle { printf("mult_cycle -> ADD mult_exp mult_cycle\n"); }
                  | SUB mult_exp mult_cycle { printf("mult_cycle -> SUB mult_exp mult_cycle\n"); }
                  ;

mult_exp:         term term_cycle{ printf("mult_exp -> term term_cycle\n"); }
                  ;

term_cycle:       // epsilon { printf("term_cycle -> epsilon\n"); }
                  | MULT term term_cycle { printf("term_cycle -> MULT term term_cycle\n"); }
                  | DIV term term_cycle { printf("term_cycle -> DIV term term_cycle\n"); }
                  | MOD term term_cycle { printf("term_cycle -> MOD term term_cycle\n"); }
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

var:              IDEN{ printf("var -> IDEN %s\n", $1); }
                  | IDEN L_BRACK exp R_BRACK { printf("var -> IDEN %s L_BRACK exp R_BRACK\n", $1); }
                  | IDEN L_BRACK exp R_BRACK L_BRACK exp R_BRACK { printf("var -> IDEN %s L_BRACK exp R_BRACK L_BRACK exp R_BRACK\n", $1); }
                  ;

%%



int main(){
  yyparse();

}
