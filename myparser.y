%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgen.h"

extern int yylex(void);
extern int line_num;
%}

/******************************************* DECLARATION SECTION *******************************************/

%union
{
  char* str;
}

// used for the semantic values of identifiers, integers, scalars, and strings.
%token <str> TK_IDENTIFIER
%token <str> TK_INTEGER
%token <str> TK_REAL
%token <str> TK_STRING

//keywords
%token KW_INT
%token KW_SCALAR
%token KW_STR
%token KW_BOOLEAN
%token KW_TRUE
%token KW_FALSE
%token KW_CONST
%token KW_IF
%token KW_ELSE
%token KW_ENDIF
%token KW_FOR
%token KW_IN
%token KW_ENDFOR
%token KW_WHILE
%token KW_ENDWHILE
%token KW_BREAK
%token KW_CONTINUE
%token KW_NOT
%token KW_AND
%token KW_OR
%token KW_DEF
%token KW_ENDDEF
%token KW_MAIN
%token KW_RETURN
%token KW_COMP
%token KW_ENDCOMP
%token KW_OF

//arithmetic operators
%token OP_PLUS
%token OP_MINUS
%token OP_MULT
%token OP_DIV
%token OP_MOD
%token OP_POWER

//relational operators
%token ROP_EQUALS
%token ROP_NOTEQUALS
%token ROP_LESS
%token ROP_LESSEQUALS
%token ROP_GREATER
%token ROP_GREATEREQUALS

//assignment operators
%token AOP_ASSIGN
%token AOP_PLUSASSIGN 
%token AOP_MINASSIGN
%token AOP_MULASSIGN
%token AOP_DIVASSIGN
%token AOP_MODASSIGN
%token AOP_COLONASSIGN
%token AOP_ARROW

//delimiters
%token DEL_SMCOLON
%token DEL_LPAR
%token DEL_RPAR
%token DEL_COMMA
%token DEL_LBRACKET
%token DEL_RBRACKET
%token DEL_COLON
%token DEL_DOT
%token HASH

%start input
%type <str> expr

// Precedence:
%left OP_MINUS OP_PLUS 
%left OP_MULT OP_DIV
%left OP_MOD
%right OP_POWER

// Non-terminal symbols:
%type <str> main_func
%type <str> func_body
%type <str> basic_data_type
%type <str> identifier
%type <str> variable_declaration
//%type <str> comp_declarations
%type <str> comp
%type <str> comp_body
%type <str> comp_field
%type <str> comp_identifiers
//%type <str> const_declarations
%type <str> const
%type <str> declaration
%type <str> function
%type <str> parameters_declaration
%type <str> declarations

%%
/******************************************* RULES SECTION *******************************************/

input:  
    %empty 
    | declarations main_func { 
        if (yyerror_count == 0) {
            puts(c_prologue);
            printf("Expression evaluates to:\n%s\n%s\n", $1, $2); 
        }  
    }
    
    | main_func { 
        if (yyerror_count == 0) {
            puts(c_prologue);
            printf("Expression evaluates to:\n%s\n", $1); 
        }  
    }
	; 

declarations:
  declarations declaration { $$ = template("%s\n%s", $1, $2); }
  | declaration { $$ = $1; };


declaration:
  variable_declaration { $$ = $1; }
  | comp { $$ = $1; } 
  | const { $$ = $1; }
  | function { $$ = $1; }
  ;
  
  
main_func:
    KW_DEF KW_MAIN DEL_LPAR DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON { $$ = template("int main () {\n%s\n}", $6); }


func_body:
      %empty { $$ = strdup(""); }
    | variable_declaration func_body { $$ = template("%s\n%s", $1, $2); } 
	;
    
    
/************************* Variable Declaration *************************/ 

variable_declaration:
      identifier DEL_COLON basic_data_type DEL_SMCOLON { $$ = template("%s %s; ", $3, $1); }
    | TK_IDENTIFIER DEL_LBRACKET TK_INTEGER DEL_RBRACKET DEL_COLON basic_data_type DEL_SMCOLON { $$ = template("%s %s[%s]; ", $6, $1, $3); }
    | TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type DEL_SMCOLON { $$ = template("%s* %s;", $5 , $1); } // pointer
	;
    
basic_data_type:
      KW_INT { $$ = template("%s", "int"); }
    | KW_SCALAR { $$ = template("%s", "double"); }
    | KW_STR { $$ = template("%s", "char*"); }
    | KW_BOOLEAN { $$ = template("%s", "int"); }
	;

identifier:
      TK_IDENTIFIER { $$ = $1; }
    | identifier DEL_COMMA TK_IDENTIFIER { $$ = template("%s, %s", $1, $3); }
	;

/************************* Composite Types Declaration *************************/ 


comp:
    KW_COMP TK_IDENTIFIER DEL_COLON comp_body KW_ENDCOMP DEL_SMCOLON { $$ = template("typedef struct %s {\n%s\n} %s;\n", $2, $4, $2); }
	;

comp_body:
      comp_field { $$ = $1; }
    | comp_field comp_body { $$ = template("%s\n%s", $1, $2); }
	;

comp_field:
    comp_identifiers DEL_COLON basic_data_type DEL_SMCOLON { $$ = template("%s %s;", $3, $1); }
	;

comp_identifiers:
      HASH TK_IDENTIFIER { $$ = $2; }
    | comp_identifiers DEL_COMMA HASH TK_IDENTIFIER { $$ = template("%s, %s" , $1 , $4); }
	;

/************************* Const Declaration *************************/ 
    
const:
    KW_CONST identifier AOP_ASSIGN expr DEL_COLON basic_data_type DEL_SMCOLON { $$ = template("const %s %s = %s;", $6, $2, $4); }
	;

/************************* Expressions Declaration *************************/ 

expr:
      TK_INTEGER { $$ = $1; }
    | TK_REAL { $$ = $1; }
    | DEL_LPAR expr DEL_RPAR { $$ = template("(%s)", $2); }
    | expr OP_PLUS expr { $$ = template("%s + %s", $1, $3); }
    | expr OP_MINUS expr { $$ = template("%s - %s", $1, $3); }
    | expr OP_MULT expr { $$ = template("%s * %s", $1, $3); }
    | expr OP_DIV expr { $$ = template("%s / %s", $1, $3); }
;

/************************* Functions Declaration *************************/ 

function: 
  KW_DEF TK_IDENTIFIER DEL_LPAR parameters_declaration DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON 								{$$ = template("\nvoid %s(%s) {\n%s\n}\n", $2, $4, $7);}
  | KW_DEF TK_IDENTIFIER DEL_LPAR parameters_declaration DEL_RPAR AOP_ARROW basic_data_type DEL_COLON func_body KW_ENDDEF DEL_SMCOLON 	{$$ = template("\n%s %s(%s) {\n%s\n\n}\n", $7, $2, $4, $9);}
  ;


parameters_declaration: 
  %empty { $$ = "" ;}
  | TK_IDENTIFIER DEL_COLON basic_data_type {$$ = template("%s %s", $3, $1);}
  | TK_IDENTIFIER DEL_COLON basic_data_type DEL_COMMA parameters_declaration {$$ = template("%s %s, %s", $3, $1, $5);};
  | TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type {$$ = template("%s *%s", $5, $1);}
  | TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type DEL_COMMA parameters_declaration {$$ = template("%s *%s, %s", $5, $1, $7);}


%%
/******************************************* CODE SECTION *******************************************/

int main () {
    if ( yyparse() == 0 )
        printf("Accepted!\n");
    else
        printf("Rejected!\n");
}

