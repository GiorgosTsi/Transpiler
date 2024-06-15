%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgen.h"


extern int yylex(void);
extern int line_num;

char* all_funcs = NULL;
char* all_funcs_names = NULL;
char* all_comp_object_members = NULL;


/*Used in array comprehension , to get the new expression with replaced elm->array[array_i] 
  And also in the comp_functions to replace #var with self->var
*/
char* replace_str(const char *str, const char *old, const char *new) {
    char *result;
    int i, cnt = 0;
    int newlen = strlen(new);
    int oldlen = strlen(old);

    // Count the number of times old word occur in the string
    for (i = 0; str[i] != '\0'; i++) {
        if (strstr(&str[i], old) == &str[i]) {
            cnt++;
            i += oldlen - 1;
        }
    }

    // Allocate memory for the new result string
    result = (char *)malloc(i + cnt * (newlen - oldlen) + 1);

    i = 0;
    while (*str) {
        if (strstr(str, old) == str) {
            strcpy(&result[i], new);
            i += newlen;
            str += oldlen;
        } else
            result[i++] = *str++;
    }

    result[i] = '\0';
    return result;
}

int is_basic_data_type(const char *type) {
    return strcmp(type, "int") == 0 || strcmp(type, "double") == 0 || strcmp(type, "StringType") == 0 ;
}

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


/*********************** Non-terminal symbols: *******************/
%type <str> main_func
%type <str> func_body

%type <str> basic_data_type
%type <str> types
%type <str> identifier
%type <str> variable_declaration
%type <str> comp
%type <str> comp_body
%type <str> comp_field
%type <str> comp_identifiers
%type <str> comp_function

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
%type <str> identifier_expr
%type <str> for_statement
%type <str> array_int_comprehension
%type <str> array_comprehension
%type <str> return_statement
%type <str> break_statement
%type <str> continue_statement
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
            printf("C equivalent code:\n");
            printf("************************\n");
            puts(c_prologue);
            printf("\n\n%s\n%s\n", $1, $2);
            printf("************************\n");
        }  
    }
    
    | main_func { 
        if (yyerror_count == 0) {
            printf("C equivalent code:\n");
            printf("************************\n");
            puts(c_prologue);
            printf("\n\n%s\n", $1);
            printf("************************\n"); 
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
  identifier DEL_COLON types DEL_SMCOLON
   {
    // If it's a basic data type, declare it normally
    if (is_basic_data_type($3)) {
      $$ = template("%s %s;", $3, $1);

    // If it's a Comp type declare it by using the constructor : i.e Circle x = ctor_Circle;
    } else {

      /*Tokenize by ',' because there may be multiple declarations in the same line! */
      char* token = strtok($1, ", ");
      char* final_str = strdup("");

      while (token != NULL) {

        /* If it is an array of composite types : */
        char* bracket_pos = strchr(token, '['); // Find the bracket position
        if (bracket_pos != NULL) {
          // Handle array initialization
          char* size_str = strdup(bracket_pos + 1); // Copy the size part
          char* end_bracket_pos = strchr(size_str, ']'); // Find the closing bracket
          if (end_bracket_pos != NULL) {
              *end_bracket_pos = '\0'; // Truncate to get only the size
          }
          *bracket_pos = '\0'; // Truncate the identifier to remove the size

          int size = atoi(size_str); // Convert size_str to integer
          free(size_str);
          
          char* loop_str = template("for (int i = 0; i < %d; i++) \n{ %s[i] = ctor_%s; }", size, token, $3);

          final_str = template("%s\n%s %s[%d];\n%s", final_str, $3, token, size, loop_str);
          
          free(loop_str);

        } 
        else {
          // Handle regular composite types initialization
          char * new_str = NULL;

          if (strchr(token, '*') != NULL) // if its a pointer you dont need the ctor initialization!
            new_str = template("%s %s;\n", $3, token);
          else
            new_str = template("%s %s = ctor_%s;\n", $3, token, $3);
          
          final_str = template("%s\n%s", final_str, new_str);
          free(new_str);
        }

        token = strtok(NULL, ", ");
      }

      $$ = final_str;
    }
   }
    

basic_data_type:
      KW_INT { $$ = template("%s", "int"); }
    | KW_SCALAR { $$ = template("%s", "double"); }
    | KW_STR { $$ = template("%s", "StringType"); }
    | KW_BOOLEAN { $$ = template("%s", "int"); }
	;

types:
	basic_data_type 
  | TK_IDENTIFIER //used for comp types
	;
	
identifier:
    identifier_expr // used for simple TK_IDENTIFIER , ARRAY with expression .
    | TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET {$$ = template("*%s", $1);};
    | identifier DEL_COMMA  TK_IDENTIFIER { $$ = template("%s, %s" , $1 , $3); }
    | identifier DEL_COMMA  TK_IDENTIFIER DEL_LBRACKET expr DEL_RBRACKET { $$ = template("%s, %s[%s]" , $1 , $3 , $5); }
    | identifier DEL_COMMA  TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET { $$ = template("%s, *%s" , $1 , $3 ); }
	;

/************************* Composite Types Declaration *************************/ 


comp:
    KW_COMP TK_IDENTIFIER DEL_COLON comp_body KW_ENDCOMP DEL_SMCOLON 
    {
       $$ = template("\n#define SELF struct %s *self\n\ntypedef struct %s {\n%s\n} %s;\n%s\nconst %s ctor_%s = { %s  %s%s };\n#undef SELF\n", $2, $2, $4, $2 ,( all_funcs ? all_funcs : "" ), $2 , $2 , (all_funcs_names ? all_funcs_names : "" ) ,(all_comp_object_members ? ", " : "") , (all_comp_object_members ? all_comp_object_members : "")); 
    
       // reset the all_funcs string , to get new funcs on the next comp and dont rewrite the old ones.
       free(all_funcs);
       free(all_funcs_names);
       free(all_comp_object_members);
       all_funcs = NULL;
       all_funcs_names = NULL;
       all_comp_object_members = NULL;
       
    }
	  ;


comp_body:
      comp_field { $$ = $1; }
    | comp_field comp_body { $$ = template("%s\n%s", $1, $2); }
	;


comp_field:
    comp_identifiers DEL_COLON types DEL_SMCOLON 
    { 
        $$ = template("%s %s;", $3, $1); 

        /* Now if it is an object and not a basic data type, we need to add it in the constructor, to initialize it: */
        if (!is_basic_data_type($3)) {
            char *object_name;
            char *identifier_copy = strdup($1); // Create a copy to modify
            char *bracket_pos = strchr(identifier_copy, '['); // Find the bracket position

            if (bracket_pos != NULL) {  // Check if the identifier is an array
                char *size_str = strdup(bracket_pos + 1); // Copy the size part
                char *end_bracket_pos = strchr(size_str, ']'); // Find the closing bracket
                if (end_bracket_pos != NULL) {
                    *end_bracket_pos = '\0'; // Truncate to get only the size
                }
                *bracket_pos = '\0'; // Truncate the identifier to remove the size
                // Create the initializer for the array
                object_name = template(".%s = {[0 ... %s - 1] = ctor_%s}", identifier_copy, size_str, $3);
                free(size_str); // Free the allocated memory for size_str
            } else {
                // Create the initializer for a regular member
                object_name = template(".%s = ctor_%s", $1, $3);
            }

            if (all_comp_object_members) {
                // Append the new object name to the existing members
                size_t new_size = strlen(all_comp_object_members) + strlen(object_name) + 2; // +2 for comma and null terminator
                all_comp_object_members = (char*)realloc(all_comp_object_members, new_size);
                if (all_comp_object_members) {
                    strcat(all_comp_object_members, ",");
                    strcat(all_comp_object_members, object_name);
                } else {
                    // Handle memory allocation failure
                    fprintf(stderr, "Memory allocation failed\n");
                    exit(EXIT_FAILURE);
                }
            } else {
                // Initialize the member list with the new object name
                all_comp_object_members = strdup(object_name);
            }
            free(object_name); // Free the allocated memory
            free(identifier_copy); // Free the allocated memory
        }
    }
    | comp_function { $$ = template("%s", $1); }
	  ;


comp_identifiers:
      HASH TK_IDENTIFIER { $$ = $2; }
    | HASH TK_IDENTIFIER DEL_LBRACKET expr DEL_RBRACKET {$$ = template("%s[%s]", $2, $4);};
    | HASH TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET {$$ = template("*%s", $2);};
    | comp_identifiers DEL_COMMA HASH TK_IDENTIFIER { $$ = template("%s, %s" , $1 , $4); }
    | comp_identifiers DEL_COMMA HASH TK_IDENTIFIER DEL_LBRACKET expr DEL_RBRACKET { $$ = template("%s, %s[%s]" , $1 , $4 , $6); }
    | comp_identifiers DEL_COMMA HASH TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET { $$ = template("%s, *%s" , $1 , $4 ); }
	  ;


comp_function:
    KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON 								
    {
      char *func_declaration = template("void (*%s)(SELF %s%s)", $2, ( ($4[0] != '\0') ? ", " : "" ) , $4);
      
      char * func = template("void %s(SELF %s%s) {\n%s\n}\n", $2, ( ($4[0] != '\0') ? ", " : "" ),$4, $7);

      /*1. Store func body: */
      //replace all #var with self->var:
      func = replace_str(func , "#" , "self->" );
      size_t new_size = all_funcs ? strlen(all_funcs) + strlen(func) + 1 : strlen(func) + 1;
      all_funcs = (char*)realloc(all_funcs, new_size);
      if (all_funcs) {
          if (strlen(all_funcs) > 0) {
            strcat(all_funcs, "\n");
          }
          strcat(all_funcs, func);
      } else {
          all_funcs = strdup(func);
      }

      /*2. Store func name: */
      char* func_name = template(".%s=%s" , $2 , $2);
      size_t size = all_funcs_names ? strlen(all_funcs_names) + strlen(func_name) + 1 : strlen(func_name) + 1;
      all_funcs_names = (char*)realloc(all_funcs_names, size);
      if (all_funcs_names) {
          if (strlen(all_funcs_names) > 0) {
            strcat(all_funcs_names, ",");
          }
          strcat(all_funcs_names, func_name);
      } else {
          all_funcs_names = strdup(func_name);
      }

      $$ = template("%s;\n", func_declaration);
      
    }

    | KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW types DEL_COLON func_body KW_ENDDEF DEL_SMCOLON 	
    {
      char *func_declaration = template("%s (*%s)(SELF %s%s)", $7, $2, ($4[0] != '\0') ? ", " : "", $4);

      char *func = template("%s %s(SELF %s%s) {\n%s\n}\n", $7, $2, ( ($4[0] != '\0') ? ", " : "" ), $4, $9);
      
      
      /*1. Store func body: */
      //replace all #var with self->var:
      func = replace_str(func , "#" , "self->" );
      size_t new_size = all_funcs ? strlen(all_funcs) + strlen(func) + 1 : strlen(func) + 1;
      all_funcs = (char*)realloc(all_funcs, new_size);
      if (all_funcs) {
        if (strlen(all_funcs) > 0) {
          strcat(all_funcs, "\n");
        }
        strcat(all_funcs, func);
      } else {
        all_funcs = strdup(func);
      }

      /*2. Store func name: */
      char* func_name = template(".%s=%s" , $2 , $2);
      size_t size = all_funcs_names ? strlen(all_funcs_names) + strlen(func_name) + 1 : strlen(func_name) + 1;
      all_funcs_names = (char*)realloc(all_funcs_names, size);
      if (all_funcs_names) {
          if (strlen(all_funcs_names) > 0) {
            strcat(all_funcs_names, ",");
          }
          strcat(all_funcs_names, func_name);
      } else {
          all_funcs_names = strdup(func_name);
      }

      $$ = template("%s;\n", func_declaration);
    }
    ;

/************************* Const Declaration *************************/ 
    
const:
    KW_CONST identifier AOP_ASSIGN expr DEL_COLON basic_data_type DEL_SMCOLON { $$ = template("const %s %s = %s;", $6, $2, $4); }
	;

/************************* Expressions Declaration *************************/ 

expr:
    TK_STRING { $$ = $1; }
    | KW_TRUE {$$ = template("1");}
    | KW_FALSE {$$ = template("0");}    
    | DEL_LPAR expr DEL_RPAR { $$ = template("(%s)", $2); }
    | identifier_expr { $$ = $1; }
    | arithmetic_expr {$$ = $1;}
    | relational_expr {$$ = $1;}
    | logical_statements {$$ = $1;}
    | function_statement {$$ = $1;}
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


identifier_expr:
   TK_IDENTIFIER { $$ = $1; } // used for x = 5 assign statements
  | HASH TK_IDENTIFIER { {$$ = template("#%s", $2);} } // used for #x = .. assign statements in comp funcs body
  | TK_IDENTIFIER DEL_LBRACKET expr DEL_RBRACKET { $$ = template("%s[%s]", $1, $3); } // used for arr[expr] = .. assign statements
  | HASH TK_IDENTIFIER DEL_LBRACKET expr DEL_RBRACKET { $$ = template("#%s[%s]", $2, $4); } // used for #x[#y] = ..
  | identifier_expr DEL_DOT HASH TK_IDENTIFIER {$$ = template("%s.%s" , $1 , $4 ); } // used for : #comp.#comp_members in comp funcs
  | identifier_expr DEL_DOT TK_IDENTIFIER {$$ = template("%s.%s" , $1 , $3 ); } // used in main functions for x.y = .. statements
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
  | KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW types DEL_COLON func_body KW_ENDDEF DEL_SMCOLON 	{$$ = template("\n%s %s(%s) {\n%s\n\n}\n", $7, $2, $4, $9);}
  ;


params: 
  %empty { $$ = "" ;}
  | TK_IDENTIFIER DEL_COLON types {$$ = template("%s %s", $3, $1);}
  | TK_IDENTIFIER DEL_COLON types DEL_COMMA params {$$ = template("%s %s, %s", $3, $1, $5);};
  | TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON types {$$ = template("%s *%s", $5, $1);}
  | TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON types DEL_COMMA params{$$ = template("%s *%s, %s", $5, $1, $7);}
  ;
  
func_body:
      %empty { $$ = strdup(""); }
    | variable_declaration func_body { $$ = template("%s\n%s", $1, $2); }
    | const func_body { $$ = template("%s\n%s", $1, $2); } 
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
  |  break_statement
  |  continue_statement
  |  function_statement DEL_SMCOLON { $$ = template("%s;", $1); };
	;
	
statement_body:
	%empty { $$ = "" ;}
	| variable_declaration statement_body {$$ = template("%s\n%s",$1,$2);} 
  | const statement_body  {$$ = template("%s\n%s",$1,$2);}
	| statements statement_body {$$ = template("%s\n%s",$1,$2);}
	;
	

assign_statement:
    identifier_expr AOP_ASSIGN expr DEL_SMCOLON           { $$ = template("%s = %s;", $1, $3); }
  | identifier_expr AOP_PLUSASSIGN expr DEL_SMCOLON       { $$ = template("%s += %s;", $1, $3); }
  | identifier_expr AOP_MINASSIGN expr DEL_SMCOLON        { $$ = template("%s -= %s;", $1, $3); }
  | identifier_expr AOP_MULASSIGN expr DEL_SMCOLON        { $$ = template("%s *= %s;", $1, $3); }
  | identifier_expr AOP_DIVASSIGN expr DEL_SMCOLON        { $$ = template("%s /= %s;", $1, $3); }
  | identifier_expr AOP_MODASSIGN expr DEL_SMCOLON        { $$ = template("%s %%= %s;", $1, $3); }
  ;
	

if_statement:
	  KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDIF DEL_SMCOLON {$$ = template("if (%s) {\n%s\n}", $3, $6);}
	| KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ELSE DEL_COLON statement_body KW_ENDIF DEL_SMCOLON {$$ = template("if (%s) {\n%s\n} else {\n%s\n}", $3, $6, $9);}
	;
  
 
while_statement:
	  KW_WHILE DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDWHILE DEL_SMCOLON { $$ = template("while (%s){\n%s\n}\n", $3, $6); }
	  
	  
for_statement:
	  KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON {$$ = template("for (int %s = %s; %s < %s; %s++) {\n%s\n}", $2, $5, $2, $7, $2, $10);}
	  | KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON {$$ = template("for (int %s = %s; %s < %s; %s = %s + %s) 		{\n%s\n}", $2, $5, $2, $7, $2, $2, $9, $12);}
	  ;

array_int_comprehension:
  TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON expr DEL_RBRACKET DEL_COLON types DEL_SMCOLON {$$ = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(%s %s = 0; %s < %s; ++%s) {\n %s[%s] = %s;\n}", $11, $1, $11, $8, $11, $11, $6, $6, $8, $6, $1, $6, $4);}
  ;
  
 
array_comprehension:
	TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON types KW_IN TK_IDENTIFIER KW_OF expr DEL_RBRACKET DEL_COLON types DEL_SMCOLON 
	{
	char* replaced_expr = replace_str($4, $6, template("%s[%s_i]", $10, $10));
	$$ = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(int %s_i = 0; %s_i < %s; ++%s_i) {\n\t%s[%s_i] = %s;\n}", $15, $1, $15, $12, $15, $10, $10, $12, $10, $1, $10, replaced_expr);
	}
	;

break_statement:
  KW_BREAK DEL_SMCOLON {$$ = template("break;");}


continue_statement:
  KW_CONTINUE DEL_SMCOLON {$$ = template("continue;");}


return_statement:
  KW_RETURN DEL_SMCOLON{$$ = template("return;");}
  | KW_RETURN expr DEL_SMCOLON{$$ = template("return %s;", $2);}
  ;


function_statement:
  TK_IDENTIFIER DEL_LPAR DEL_RPAR {$$ = template("%s()", $1);}
  | TK_IDENTIFIER DEL_LPAR function_arguments DEL_RPAR {$$ = template("%s(%s)", $1,$3);}
  | identifier_expr DEL_DOT TK_IDENTIFIER DEL_LPAR DEL_RPAR {$$ = template("%s.%s(&%s)" , $1 , $3 ,$1); }
  | identifier_expr DEL_DOT TK_IDENTIFIER DEL_LPAR function_arguments DEL_RPAR {$$ = template("%s.%s(&%s,%s)" , $1 , $3 ,$1, $5); }
  ;

function_arguments:
  expr { $$ = template("%s", $1);}
  | expr DEL_COMMA function_arguments { $$ = template("%s, %s", $1, $3); }
  ;
  
	

%%
/******************************************* CODE SECTION *******************************************/

int main () {
    if ( yyparse() == 0 )
        printf( GREEN "Your program is syntactically correct!\n" RESET);
    else
        printf(RED "Rejected!\n" RESET);
}

