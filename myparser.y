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
  int num;
}

// used for the semantic values of identifiers, integers , scalars and strings.
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


//delimiters
%token DEL_SMCOLON
%token DEL_LPAR
%token DEL_RPAR
%token DEL_COMMA
%token DEL_LBRACKET
%token DEL_RBRACKET
%token DEL_COLON
%token DEL_DOT




//%type <str> input

%start input
%type <str> expr

// Precedence:
//%left OP_MINUS OP_PLUS 


%left OP_PLUS OP_MINUS 

%left OP_MULT OP_DIV

%left OP_MOD

%right OP_POWER

%%
/******************************************* RULES SECTION *******************************************/

input:  
  %empty 
| input expr DEL_SMCOLON 
{ 
  if (yyerror_count == 0) {
    puts(c_prologue);
    printf("Expression evaluates to: %s\n", $2); 
  }  
}
;

expr:
  TK_INTEGER { $$ = $1; }
| TK_REAL	 { $$ = $1; }
| DEL_LPAR expr DEL_RPAR { $$ = template("(%s)", $2); }
| expr OP_PLUS expr { $$ = template("%s + %s", $1, $3); }
| expr OP_MINUS expr { $$ = template("%s - %s", $1, $3); }
| expr OP_MULT expr { $$ = template("%s * %s", $1, $3); }
| expr OP_DIV expr { $$ = template("%s / %s", $1, $3); }
;



%%
/******************************************* CODE SECTION *******************************************/


int main () {
  if ( yyparse() == 0 )
    printf("Accepted!\n");
  else
    printf("Rejected!\n");
}
