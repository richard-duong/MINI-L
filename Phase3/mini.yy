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

%code requires
{	
	#include <iostream>
	#include <string>
	#include <vector>
	using namespace std;


	/* Define structures for non-terminals */
	struct nonterminal 
	{
		string name;
		string type;
		int arr_size;
		vector<string> code;
	};

	/* Define prototypes used */
	ostream& operator<< (ostream& out, const vector<string> list);
	ostream& operator<< (ostream& out, const nonterminal item);
	bool isSymbol(string item);
	bool isKeyword(string item);
	string makeVar();
	string makeLabel();


}


%code
{
	#include "parser.tab.hh"
	#include <iostream>
	#include <sstream>
	#include <map>
	#include <regex>
	#include <string>
	#include <unordered_set>
	using namespace std;

	/*yy::parser::symbol_type yylex();*/



	
	/* Define symbol table, globals, and keywords list here */	

	map<string, nonterminal> symbol_table;
	
	unordered_set<string> keywords = 
	{	
		"function", 
		"beginparams", 
		"endparams",
		"beginlocals",
		"endlocals",
		"beginbody",
		"endbody",
		"integer",
		"array",
		"of",
		"if",
		"then",
		"endif",
		"else",
		"while",
		"do",
		"for",
		"beginloop",
		"endloop",
		"continue",
		"read",
		"write",
		"and",
		"or",
		"not",
		"true",
		"false",
		"return"
	}

}


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

// all nonterminals fall within this struct
%type <nonterminal> prog func_cycle decl_cycle decl iden_cycle stmt_cycle arr_cycle stmt assign_cycle if_cycle else_cycle while_cycle do_cycle for_cycle read_cycle write_cycle continue_cycle return_cycle var_cycle bool_exp rel_and_exp rel_exp rel_exp_base comp exp mult_exp term term_base param_cycle exp_cycle var


/*
  Ten levels of precedence
  Reverse order of highest precedence
*/

%right ASSIGN
%left OR
%left AND
%right NOT
%left LT LTE GT GTE EQ NEQ
%left ADD SUB
%left MULT DIV MOD
%right UMINUS
%left L_BRACK R_BRACK
%left L_PAREN R_PAREN


%%

prog:             	

	func_cycle 
	{
		cout << $1;
	}
;



func_cycle:       

	// eps
	{

	}

	| func_cycle FUNCTION IDEN SEMICOLON BEGINPARAMS decl_cycle ENDPARAMS BEGINLOCALS decl_cycle ENDLOCALS BEGINBODY stmt_cycle ENDBODY 
	{ 	
		// error checks
		string name = $3;
		if(isKeyword(name))
		{
			cout << "This function " << name << " is already an existing keyword" << endl;
			yyerror("exit");
		}

		if(isSymbol(name))
		{
			cout << "This function: " << name << " is already an existing symbol" << endl;
		}
			
		// insert previous functions
		$$.insert($$.code.end(), $1.code.begin(), $1.code.end());

		// insert current function
		$$.push_back("func " + name);
		$$.insert($$.code.end(), $6.code.begin(), $6.code.end());
		$$.insert($$.code.end(), $9.code.begin(), $9.code.end());
		$$.insert($$.code.end(), $12.code.begin(), $12.code.end());		
		$$.push_back("endfunc");

		// insert item into symbol_table
		nonterminal temp;		
		temp.type = "func";
		symbol_table[name] = temp;

	}
;



decl_cycle:       

	// eps  
	{

	}
                  
	| decl_cycle decl SEMICOLON 
	{
		// insert each decl as a separate line
		$$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());
		$$.code.insert($$.code.end(), $2.code.begin(), $2.code.end());

	}
;



decl:
	iden_cycle COLON arr_cycle INTEGER 
	{
		// error checks	
		for(auto item: $1.code)
		{
			// temp declaration
			string declaration = ".";
			nonterminal temp;

			if(isKeyword(item))
			{
				cout << "Error: " << item << " is an existing keyword!" << endl;
				yyerror("exit");
			}
			
			if(isSymbol(item))
			{
				cout << "Error: " << item << " is already an existing symbol!" << endl;
				yyerror("exit");
			}

			// standalone variable, no array
			if($3.code.size() == 0)
			{
				declaration += " " + item;
				temp.type = "var";
				symbol_table[item] = temp;
			}

			// array variable
			else
			{
				declaration += "[] " + item + ", " + $3.code[0];
				temp.type = "arr";
				temp.arr_size = $3.code[0];
				symbol_table[item] = "arr";
			}
		
			// push back the resulting variable
			$$.code.push_back(declaration);	
		}
	}
;

iden_cycle:       

	IDEN 
	{ 
		// if only 1 identifier, then push the 1 identifier in
		string name = $1;
		$$.code.push_back(name);
	}

	
    | iden_cycle COMMA IDEN
	{
		// insert previous code first
		$$.code.insert($$.code.end(), $1.code.begin());

		// add last item in afterward
		string name = $3;
		$$.code.push_back(name);
	}
;



stmt_cycle:       
		  
	stmt SEMICOLON 
	{
		$$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());
	}
                  
	| stmt_cycle stmt SEMICOLON 
	{
		$$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());
		$$.code.insert($$.code.end(), $2.code.begin(), $2.code.end());
	}
;


arr_cycle:        
	
	// eps
	{
		$$.arr_size = 0;
	}
                  

	| ARRAY L_BRACK NUM R_BRACK OF 
	{ 
		$$.arr_size = $3;
	}


	| ARRAY L_BRACK NUM R_BRACK L_BRACK NUM R_BRACK OF 
	{
		$$.arr_size = $3;	
		// language doesn't include 2nd array
	}
;


stmt:             
	
	assign_cycle 
	{	
		$$.code.push_back($1.code);
	}
                  

	| if_cycle 
	{
		for(auto item: $1)
		{

		}	
	}
                 

	| while_cycle 
	{
		for(auto item: $1)
		{

		}
	}
                  | do_cycle { printf("stmt -> do_cycle\n"); }
                  | for_cycle { printf("stmt -> for_cycle\n"); }
                  | read_cycle { printf("stmt -> read_cycle\n"); }
                  | write_cycle { printf("stmt -> write_cycle\n"); }
                  | continue_cycle { printf("stmt -> continue_cycle\n"); }
                  | return_cycle { printf("stmt -> return_cycle\n"); }
                  ;

assign_cycle:     

	var ASSIGN exp 
	{
		string assign = "";
		if($1.type == "var")
		{
			assign = "= " + $1.name + ", " + $3.name;
		}
		
		else if($1.type == "arr")
		{
			assign = "=" + $1.name + ", " + $3.name + ", " + to_string($1.arr_size);
		}

		// insert expected assignment
		$$.code.push_back(assign);
		$$.code.insert($$.end(), $1.begin(), $1.end());
		$$.code.insert($$.end(), $3.begin(), $3.end());
	}
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

var_cycle:        

	var 
	{		
		// insert each component of the variable
		$$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());
	}
                  

	| var_cycle COMMA var
	{
	
		// insert all the variables
		$$.code.insert($$.code.end(), $1.code.begin(), $1.code.end());	
		$$.code.insert($$.code.end(), $3.code.begin(), $3.code.end());
	}
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

exp:              
   
	mult_exp 
	{
		$$.name = $1.name;
		$$.code.insert($$.end(), $1.begin(), $1.end());	
	}


    | exp ADD mult_exp
	{
		$$.name = makeVar();
	}
    


	| exp SUB mult_exp
	{
	
	}
;



mult_exp:         term
                  | mult_exp MULT term
                  | mult_exp DIV term
                  | mult_exp MOD term
                  ;

term:             term_base { printf("term -> term_base\n"); }
                  | SUB term_base %prec UMINUS { printf("term -> SUB term_base \%prec UMINUS\n"); }
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

var:

	IDEN
	{
		string name = $1; 

		if(isKeyword(name))
		{
			cout << "Error: Tried to use an existing keyword!" << endl;
			yyerror("exit");
		}
		
		else if(!isSymbol(name))
		{
			cout << "Error: Tried to use nonexisting variable!" << endl;
			yyerror("exit");
		}

		else if(symbol_table[name].type == "arr")
		{
			cout << "Error: Tried to use an array variable!" << endl;	
			yyerror("exit");	
		}	
		$$.name = name;	
		$$.type = "var";
		$$.code.push_back(name);
	}
                  

	| IDEN L_BRACK exp R_BRACK 
	{
		string name = $1;

		if(isKeyword(name))
		{
			cout << "Error: Tried to use an existing keyword!" << endl;
			yyerror("exit");
		}

		else if(!isSymbol(name))
		{
			cout << "Error: Tried to use nonexisting variable!" << endl;
		}

		else if(symbol_table[name].type == "var")
		{
			cout << "Error: Tried to use a scalar variable!" << endl;
		}

		// check out of bounds here
		
		$$.name = makeVar();
		$$.type = "arr";
		$$.code.push_back(name)
		$$.code.push_back($3.name);
	
	}




	| IDEN L_BRACK exp R_BRACK L_BRACK exp R_BRACK 
	{
		string name = $1;

		if(isKeyword(name))
		{
			cout << "Error: Tried to use an existing keyword!" << endl;
			yyerror("exit");
		}

		else if(!isSymbol(name))
		{
			cout << "Error: Tried to use nonexisting variable!" << endl;
		}

		else if(symbol_table[name].type == "var")
		{
			cout << "Error: Tried to use a scalar variable!" << endl;
		}

		// check out of bounds here
		
		$$.name = makeVar();
		$$.code.push_back(".[] " + name + ", " + $3.name);	
	}	
;


%%



int main(){
  yyparse();
}



// print vector of strings to stdout
ostream& operator <<(ostream& out, const vector<string> list)
{
	for(auto item: list)
	{
		cout << item << endl;
	}
}


// print nonterminal to stdout
ostream& operator <<(ostream& out, const nonterminal item)
{
	// calls vector print operation
	cout << item.code << endl;
}


// verifies if item exists in symbol table
bool isSymbol(string item)
{
	return symbol_table.find(item) != symbol_table.end();
}


// verifies if item is an existing keyword
bool isKeyword(string item)
{
	return keywords.find(item) != keywords.end();
}


// generate a temporary variable
string makeVar()
{
	static int totalVar = 0;
	return "__temp__" + to_string(totalVar++);
}


// generate a temporary label
string makeLabel()
{
	static int totalLabel = 0;
	return "__label__" + to_string(totalLabel++);
}
