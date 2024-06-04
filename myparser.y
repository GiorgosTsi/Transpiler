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
%token AOP_HASHASSIGN
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


/*********************** Non-terminal symbols: *******************/
%type <str> main_func
%type <str> func_body

%type <str> basic_data_type
%type <str> types
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
%type <str> params
%type <str> declarations

//expressions
%type <str> expr
%type <str> arithmetic_expr
%type <str> relational_expr

//statements
%type <str> while_statement
%type <str> if_statement
%type <str> statements
%type <str> statement_body
%type <str> assign_statement
%type <str> for_statement
%type <str> array_int_comprehension
%type <str> array_comprehension
%type <str> return_statement
%type <str> function_statement
%type <str> function_arguments
%type <str> logical_statements


// Precedence:

%left OP_MINUS OP_PLUS 
%left OP_MULT OP_DIV
%left OP_MOD
%right OP_POWER

%left ROP_EQUALS
%left ROP_NOTEQUALS
%left ROP_LESS
%left ROP_LESSEQUALS
%left ROP_GREATER
%left ROP_GREATEREQUALS

%right AOP_ASSIGN
%right AOP_HASHASSIGN
%right AOP_PLUSASSIGN 
%right AOP_MINASSIGN
%right AOP_MULASSIGN
%right AOP_DIVASSIGN
%right AOP_MODASSIGN
%right AOP_COLONASSIGN
%right AOP_ARROW

%left DEL_DOT
%left DEL_LPAR
%left DEL_RPAR
%left DEL_LBRACKET
%left DEL_RBRACKET

%left KW_NOT
%left KW_AND
%left KW_OR

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

types:
	basic_data_type 
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
    | function { $$ = template("%s", $1); }
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
	 TK_IDENTIFIER { $$ = $1; }
    | TK_STRING { $$ = $1; }
    | KW_TRUE {$$ = template("1");}
    | KW_FALSE {$$ = template("0");}    
    | DEL_LPAR expr DEL_RPAR { $$ = template("(%s)", $2); }
    | arithmetic_expr {$$ = $1;}
    | relational_expr {$$ = $1;}
    | logical_statements {$$ = $1;}
    ;

arithmetic_expr:
    TK_INTEGER {$$ = $1;}
    | TK_REAL {$$ = $1;}
    | expr OP_POWER expr {$$ = template("pow(%s, %s)", $1, $3);}
    | expr OP_MULT expr {$$ = template("%s * %s",$1, $3);}
    | expr OP_DIV expr {$$ = template("%s / %s", $1, $3);}
    | expr OP_MOD expr {$$ = template("%s %% %s", $1, $3);}
    | expr OP_PLUS expr {$$ = template("%s + %s", $1, $3);}
    | expr OP_MINUS expr {$$ = template("%s - %s", $1, $3);}
    | OP_PLUS expr {$$ = template("+%s", $2);}
    | OP_MINUS expr {$$ = template("-%s", $2);}
    ;

relational_expr:
  expr ROP_LESS expr {$$ = template("%s < %s",$1, $3);}
  | expr ROP_LESSEQUALS expr {$$ = template("%s <= %s", $1, $3);}
  | expr ROP_GREATER expr {$$ = template("%s > %s", $1, $3);}
  | expr ROP_GREATEREQUALS expr {$$ = template("%s >= %s", $1, $3);}
  | expr ROP_EQUALS expr {$$ = template("%s == %s", $1, $3);}
  | expr ROP_NOTEQUALS expr {$$ = template("%s != %s", $1, $3);}
  ;

logical_statements:
    KW_NOT expr {$$ = template("! %s", $2);}
    | expr KW_AND expr {$$ = template("%s && %s", $1, $3);}
    | expr KW_OR expr {$$ = template("%s || %s", $1, $3);}
    ;


/************************* Function Declaration *************************/ 

function: 
  KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON 								{$$ = template("\nvoid %s(%s) {\n%s\n}\n", $2, $4, $7);}
  | KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW basic_data_type DEL_COLON func_body KW_ENDDEF DEL_SMCOLON 	{$$ = template("\n%s %s(%s) {\n%s\n\n}\n", $7, $2, $4, $9);}
  ;


params: 
  %empty { $$ = "" ;}
  | TK_IDENTIFIER DEL_COLON basic_data_type {$$ = template("%s %s", $3, $1);}
  | TK_IDENTIFIER DEL_COLON basic_data_type DEL_COMMA params {$$ = template("%s %s, %s", $3, $1, $5);};
  | TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type {$$ = template("%s *%s", $5, $1);}
  | TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type DEL_COMMA params{$$ = template("%s *%s, %s", $5, $1, $7);}
  ;
  
func_body:
      %empty { $$ = strdup(""); }
    | variable_declaration func_body { $$ = template("%s\n%s", $1, $2); } 
    | statements func_body { $$ = template("%s\n%s", $1, $2); } 
	  ;
    
    
  

/************************* STATEMENTS *************************/ 

statements:
	 if_statement
	|  while_statement
	|  assign_statement
	|  for_statement
	|  array_int_comprehension
	|  array_comprehension
  |  return_statement
  |  function_statement
	;
	
statement_body:
	%empty { $$ = "" ;}
	| variable_declaration statement_body {$$ = template("%s\n%s",$1,$2);} 
	| statements statement_body {$$ = template("%s\n%s",$1,$2);}
	;
	
assign_statement:
    TK_IDENTIFIER AOP_ASSIGN expr DEL_SMCOLON           { $$ = template("%s = %s;", $1, $3); }
  | TK_IDENTIFIER AOP_PLUSASSIGN expr DEL_SMCOLON       { $$ = template("%s += %s;", $1, $3); }
  | TK_IDENTIFIER AOP_MINASSIGN expr DEL_SMCOLON        { $$ = template("%s -= %s;", $1, $3); }
  | TK_IDENTIFIER AOP_MULASSIGN expr DEL_SMCOLON        { $$ = template("%s *= %s;", $1, $3); }
  | TK_IDENTIFIER AOP_DIVASSIGN expr DEL_SMCOLON        { $$ = template("%s /= %s;", $1, $3); }
  | TK_IDENTIFIER AOP_MODASSIGN expr DEL_SMCOLON        { $$ = template("%s %%= %s;", $1, $3); }
  ;
	
//if else statements
if_statement:
	  KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDIF DEL_SMCOLON {$$ = template("if (%s) {\n%s\n}", $3, $6);}
	| KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ELSE DEL_COLON statements KW_ENDIF DEL_SMCOLON {$$ = template("if (%s) {\n%s\n} else {\n%s\n}", $3, $6, $9);}
	;
  
 
while_statement:
	  KW_WHILE DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDWHILE DEL_SMCOLON { $$ = template("while (%s)\n\t%s", $3, $6); }
	  
	  
for_statement:
	  KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON {$$ = template("for (int %s = %s; %s < %s; %s++) {\n%s\n}", $2, $5, $2, $7, $2, $10);}
	  | KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON {$$ = template("for (int %s = %s; %s < %s; %s = %s + %s) 		{\n%s\n}", $2, $5, $2, $7, $2, $2, $9, $12);}
	  ;

array_int_comprehension:
  TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON {$$ = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(%s %s = 0; %s < %s; ++%s) {\n %s[%s] = %s;\n}", $11, $1, $11, $8, $11, $11, $6, $6, $8, $6, $1, $6, $4);}
  ;
  
 
array_comprehension:
	TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON types KW_IN TK_IDENTIFIER KW_OF TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON 
	{
	char* replaced_expr = replace_str($4, $6, template("%s[%s_i]", $10, $10));
	$$ = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(int %s_i = 0; %s_i < %s; ++%s_i) {\n\t%s[%s_i] = %s;\n}", $15, $1, $15, $12, $15, $10, $10, $12, $10, $1, $10, replaced_expr);
	}
	;

return_statement:
  KW_RETURN DEL_SMCOLON{$$ = template("return;");}
  | KW_RETURN expr DEL_SMCOLON{$$ = template("return %s;", $2);}
  ;


function_statement:
  TK_IDENTIFIER DEL_LPAR DEL_RPAR DEL_SMCOLON{$$ = template("%s();", $1);}
  | TK_IDENTIFIER DEL_LPAR function_arguments DEL_RPAR DEL_SMCOLON{$$ = template("%s(%s);", $1,$3);}
  ;

function_arguments:
  expr { $$ = template("%s", $1);}
  | expr DEL_COMMA function_arguments { $$ = template("%s, %s", $1, $3); }
  ;
  
	

%%
/******************************************* CODE SECTION *******************************************/

int main () {
    if ( yyparse() == 0 )
        printf("Accepted!\n");
    else
        printf("Rejected!\n");
}

