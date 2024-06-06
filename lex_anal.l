%{
	#include <stdio.h>
	#include <string.h>  
	#include "cgen.h"
	#include "myparser.tab.h"
	
	int line_num = 1;
	int macro_count = 0;
	int macro_name_exists = -1;
	char* macro_table[50]; // 50 macros max 
	char macro_table_names[50][32];
   
  /* Function to get the macro value by giving the macro name id*/
  char* get_macro_value_by_macro_name(const char* identifier) {
    for (int i = macro_count - 1; i >= 0; i--) {
      if (strcmp(macro_table_names[i], identifier) == 0) {
        return macro_table[i];
      }
    }
    return NULL;
  }

%}

/********* NAME DEFINITIONS SECTION ***********/

IDENTIFIER                      [a-zA-Z]([a-zA-Z0-9_]*)
DIGIT                           [0-9]
NON_ZERO_DIGIT                  [1-9]
INTEGER                         0|{NON_ZERO_DIGIT}{DIGIT}*
REAL                            ({INTEGER})"."{DIGIT}+([eE][+-]?{INTEGER})?
DOUBLE_QUOTE                    "\""

/*ESCAPE_CHARS                  \\[ntr\\"]  characters \n,\t,\r,\",\\.To match them , we have to match the backslash using double \ */
/*COMMON_CHARS                  [^\"\\]       this excludes all the escape chars */

CONSTANT_STRING                 {DOUBLE_QUOTE}(([^\"\\]|\\[ntr\\"'])*){DOUBLE_QUOTE}

MACRO_VALUE                     ([^ \n])+

/* Conditions  */
%x single_line_comment
%x macro


%%


"integer"                       {printf("TOKEN KW_INT:\t\t %s\n" ,yytext ); return KW_INT; }
"scalar"                        {printf("TOKEN KW_SCALAR:\t\t %s\n" ,yytext ); return KW_SCALAR;}
"str"                           {printf("TOKEN KW_STR:\t\t %s\n" ,yytext ); return KW_STR;}
"bool"                          {printf("TOKEN KW_BOOLEAN:\t\t %s\n" ,yytext ); return KW_BOOLEAN;}
"True"                          {printf("TOKEN KW_TRUE:\t\t %s\n" ,yytext ); return KW_TRUE;}
"False"                         {printf("TOKEN KW_FALSE:\t\t %s\n" ,yytext ); return KW_FALSE;}
"const"                         {printf("TOKEN KW_CONST:\t\t %s\n" ,yytext ); return KW_CONST;}
"if"                            {printf("TOKEN KW_IF:\t\t %s\n" ,yytext ); return KW_IF;}
"else"                          {printf("TOKEN KW_ELSE:\t\t %s\n" ,yytext ); return KW_ELSE;}
"endif"                         {printf("TOKEN KW_ENDIF:\t\t %s\n" ,yytext ); return KW_ENDIF;}
"for"                           {printf("TOKEN KW_FOR:\t\t %s\n" ,yytext ); return KW_FOR;}
"in"                            {printf("TOKEN KW_IN:\t\t %s\n" ,yytext ); return KW_IN;}
"endfor"                        {printf("TOKEN KW_ENDFOR:\t\t %s\n" ,yytext ); return KW_ENDFOR;}
"while"                         {printf("TOKEN KW_WHILE:\t\t %s\n" ,yytext ); return KW_WHILE;}
"endwhile"                      {printf("TOKEN KW_ENDWHILE:\t\t %s\n" ,yytext ); return KW_ENDWHILE;}
"break"                         {printf("TOKEN KW_BREAK:\t\t %s\n" ,yytext ); return KW_BREAK;}
"continue"                      {printf("TOKEN KW_CONTINUE:\t\t %s\n" ,yytext ); return KW_CONTINUE;}
"not"                           {printf("TOKEN KW_NOT:\t\t %s\n" ,yytext ); return KW_NOT;}
"and"                           {printf("TOKEN KW_AND:\t\t %s\n" ,yytext ); return KW_AND;}
"or"                            {printf("TOKEN KW_OR:\t\t %s\n" ,yytext ); return KW_OR;}
"def"                           {printf("TOKEN KW_DEF:\t\t %s\n" ,yytext ); return KW_DEF;}
"enddef"                        {printf("TOKEN KW_ENDDEF:\t\t %s\n" ,yytext ); return KW_ENDDEF;}
"main"                          {printf("TOKEN KW_MAIN:\t\t %s\n" ,yytext ); return KW_MAIN;}
"return"                        {printf("TOKEN KW_RETURN:\t\t %s\n" ,yytext ); return KW_RETURN;}
"comp"                          {printf("TOKEN KW_COMP:\t\t %s\n" ,yytext ); return KW_COMP;}
"endcomp"                       {printf("TOKEN KW_ENDCOMP:\t\t %s\n" ,yytext ); return KW_ENDCOMP;}
"of"                            {printf("TOKEN KW_OF\t\t %s\n" ,yytext ); return KW_OF;}


"@defmacro"                     { BEGIN(macro);  }
<macro>{IDENTIFIER}             { 
                                  for(int i=0; i < macro_count; i++){
                                      char* macro_name = macro_table_names[i];
                                      if(!strcmp(macro_name,yytext))
                                          macro_name_exists = i;
                                  }
                                  //printf("num = %d\n",macro_name_exists);
                                  if(macro_name_exists == -1) //if the macro is not previously defined,define it now.
                                    strcpy(macro_table_names[macro_count],yytext);      
                                }
                                
                                                 
<macro>{MACRO_VALUE}            { 
                                  if(macro_name_exists == -1){
                                    macro_table[macro_count] = (char*)malloc(sizeof(char) * strlen(yytext));
                                    strcpy(macro_table[macro_count],yytext);               
                                    //printf("macro id:%s value: %s \n",macro_table_names[macro_count],macro_table[macro_count]);
                                    macro_count++;
                                  }
                                  else{
                                      //"macro_name_exists" var contains the index of the macros name.
                                      free(macro_table[macro_name_exists]);
                                      macro_table[macro_name_exists] = (char*)malloc(sizeof(char) * strlen(yytext));
                                      strcpy(macro_table[macro_name_exists],yytext);
                                      //printf("macro id:%s value: %s \n",macro_table_names[macro_name_exists],macro_table[macro_name_exists]);
                                      macro_name_exists = -1;
                                  }
                                  BEGIN(INITIAL); }


{IDENTIFIER}                    {
                                  char* macro_value = get_macro_value_by_macro_name(yytext);
                                  if (macro_value) { // if macro_value is not NULL, then this id is a macro definition
                                      //printf("Replacing identifier %s with macro value %s\n", yytext, macro_value);
                                      // Push the macro value back onto the input stream in reverse order
                                      for (int i = strlen(macro_value) - 1; i >= 0; i--) {
                                          unput(macro_value[i]);
                                      }
                                  } else {
                                      printf("TOKEN TK_IDENTIFIER:\t\t %s\n" ,yytext );
                                      yylval.str = strdup(yytext);
                                      return TK_IDENTIFIER;
                                  }
                                }


{INTEGER}                       { printf("TOKEN TK_INTEGER:\t\t %s\n" ,yytext );			yylval.str = strdup(yytext);	return TK_INTEGER; }
{REAL}                          { printf("TOKEN TK_REAL:\t\t %s\n" ,yytext ); 				yylval.str = strdup(yytext);	return TK_REAL; }
{CONSTANT_STRING}               { printf("TOKEN TK_STRING:\t\t %s\n" ,yytext ); 	yylval.str = strdup(yytext);	return TK_STRING; }


"+"                             {printf("TOKEN OP_PLUS:\t\t %s\n" ,yytext ); return OP_PLUS;}
"-"                             {printf("TOKEN OP_MINUS:\t\t %s\n" ,yytext ); return OP_MINUS;}
"*"                             {printf("TOKEN OP_MULT:\t\t %s\n" ,yytext ); return OP_MULT;}
"/"                             {printf("TOKEN OP_DIV:\t\t %s\n" ,yytext ); return OP_DIV;}
"%"                             {printf("TOKEN OP_MOD:\t\t %s\n" ,yytext ); return OP_MOD;}
"**"                            {printf("TOKEN OP_POWER:\t\t %s\n" ,yytext ); return OP_POWER;}

"=="                            {printf("TOKEN ROP_EQUALS:\t\t %s\n" ,yytext ); return ROP_EQUALS;}
"!="                            {printf("TOKEN ROP_NOTEQUALS:\t\t %s\n" ,yytext ); return ROP_NOTEQUALS;}
"<"                             {printf("TOKEN ROP_LESS:\t\t %s\n" ,yytext ); return ROP_LESS;}
"<="                            {printf("TOKEN ROP_LESSEQUALS:\t\t %s\n" ,yytext ); return ROP_LESSEQUALS;}
">"                             {printf("TOKEN ROP_GREATER:\t\t %s\n" ,yytext ); return ROP_GREATER;}
">="                            {printf("TOKEN ROP_GREATEREQUALS:\t\t %s\n" ,yytext ); return ROP_GREATEREQUALS;}

"="                             {printf("TOKEN AOP_ASSIGN:\t\t %s\n" ,yytext ); return AOP_ASSIGN;}
"+="                            {printf("TOKEN AOP_PLUSASSIGN:\t\t %s\n" ,yytext ); return AOP_PLUSASSIGN;}
"-+"                            {printf("TOKEN AOP_MINASSIGN:\t\t %s\n" ,yytext ); return AOP_MINASSIGN;}
"*="                            {printf("TOKEN AOP_MULASSIGN:\t\t %s\n" ,yytext ); return AOP_MULASSIGN;}
"/+"                            {printf("TOKEN AOP_DIVASSIGN:\t\t %s\n" ,yytext ); return AOP_DIVASSIGN;}
"%="                            {printf("TOKEN AOP_MODASSIGN:\t\t %s\n" ,yytext ); return AOP_MODASSIGN;}
":="                            {printf("TOKEN AOP_COLONASSIGN:\t\t %s\n" ,yytext ); return AOP_COLONASSIGN;}
"->"                        	  {printf("Token AOP_ARROW: \t%s\n", yytext); return AOP_ARROW;};


";"                             {printf("TOKEN DEL_SMCOLON\t\t %s\n" ,yytext ); return DEL_SMCOLON;}
"("                             {printf("TOKEN DEL_LPAR:\t\t %s\n" ,yytext ); return DEL_LPAR;}
")"                             {printf("TOKEN DEL_RPAR:\t\t %s\n" ,yytext ); return DEL_RPAR;}
","                             {printf("TOKEN DEL_COMMA:\t\t %s\n" ,yytext ); return DEL_COMMA;}
"["                             {printf("TOKEN DEL_LBRACKET:\t\t %s\n" ,yytext ); return DEL_LBRACKET;}
"]"                             {printf("TOKEN DEL_RBRACKET:\t\t %s\n" ,yytext ); return DEL_RBRACKET;}
":"                             {printf("TOKEN DEL_COLON:\t\t %s\n" ,yytext ); return DEL_COLON;}
"."                             {printf("TOKEN DEL_DOT:\t\t %s\n" ,yytext ); return DEL_DOT;}
"#"								              {printf("TOKEN HASH\t\t %s\n" ,yytext ); return HASH; }


[ \r\t]+                        /* skip whitespaces,tabs and carriage returns */
\n                              {line_num++;}


"--"                            { BEGIN(single_line_comment); }
<single_line_comment>[^\n]*     /*Eat anything in the line comment */
<single_line_comment>"\n"       { line_num++; BEGIN(INITIAL); }

<<EOF>>                         { return EOF; }  /*End of file*/
.                               { yyerror("lexical error: unrecognized literal '%s'\n", yytext); }

%%

