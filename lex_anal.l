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
   
	int macro_initialization = 0;   // 1 if macros identifier is not a keyword,else 0.

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

MACRO_WS                        [ \t\r]+
MACRO_VALUE                     ([^ \n])+

/* Conditions  */
%x single_line_comment
%x macro_value_definition
%s macro


%%


"integer"                       {printf("integer keyword found\n"); if(macro_initialization){exit(-1);} else { return KW_INT; } }
"scalar"                        {return KW_SCALAR;}
"str"                           {return KW_STR;}
"bool"                          {return KW_BOOLEAN;}
"True"                          {return KW_TRUE;}
"False"                         {return KW_FALSE;}
"const"                         {return KW_CONST;}
"if"                            {return KW_IF;}
"else"                          {return KW_ELSE;}
"endif"                         {return KW_ENDIF;}
"for"                           {return KW_FOR;}
"in"                            {return KW_IN;}
"endfor"                        {return KW_ENDFOR;}
"while"                         {return KW_WHILE;}
"endwhile"                      {return KW_ENDWHILE;}
"break"                         {return KW_BREAK;}
"continue"                      {return KW_CONTINUE;}
"not"                           {return KW_NOT;}
"and"                           {return KW_AND;}
"or"                            {return KW_OR;}
"def"                           {return KW_DEF;}
"enddef"                        {return KW_ENDDEF;}
"main"                          {return KW_MAIN;}
"return"                        {return KW_RETURN;}
"comp"                          {return KW_COMP;}
"endcomp"                       {return KW_ENDCOMP;}
"of"                            {return KW_OF;}


"@defmacro"                     { printf("Macro definition found\n"); BEGIN(macro); macro_initialization = 1; }
<macro>{IDENTIFIER}             { printf("Macro identifier found %s\n",yytext);
                                  
                                  for(int i=0; i < macro_count; i++){
                                      char* macro_name = macro_table_names[i];
                                      if(!strcmp(macro_name,yytext))
                                          macro_name_exists = i;
                                  }
                                  printf("num = %d\n",macro_name_exists);
                                  if(macro_name_exists == -1) //if the macro is not previously defined,define it now.
                                    strcpy(macro_table_names[macro_count],yytext);      
                                  BEGIN(macro_value_definition);
                                }
                                
                                                 
<macro_value_definition>{MACRO_VALUE}            { printf("Macro value found %s\n",yytext);
                                  if(macro_name_exists == -1){
                                  macro_table[macro_count] = (char*)malloc(sizeof(char) * strlen(yytext));
                                  strcpy(macro_table[macro_count],yytext);
                                  macro_initialization = 0;                
                                  printf("macro id:%s value: %s \n",macro_table_names[macro_count],macro_table[macro_count]);
                                  macro_count++;
                                  }
                                  else{
                                      //macro_name_exists contains the index of the macros name.
                                      free(macro_table[macro_name_exists]);
                                      macro_table[macro_name_exists] = (char*)malloc(sizeof(char) * strlen(yytext));
                                      strcpy(macro_table[macro_name_exists],yytext);
                                      printf("macro id:%s value: %s \n",macro_table_names[macro_name_exists],macro_table[macro_name_exists]);
                                      macro_name_exists = -1;
                                  }
                                  BEGIN(INITIAL); }


{IDENTIFIER}                    { printf("Identifier found : %s at line: %d\n", yytext,line_num);		yylval.str = strdup(yytext);	return TK_IDENTIFIER; }
{INTEGER}                       { printf("Integer found: %s at line: %d\n", yytext,line_num);			yylval.str = strdup(yytext);	return TK_INTEGER; }
{REAL}                          { printf("Real found: %s at line: %d\n", yytext,line_num); 				yylval.str = strdup(yytext);	return TK_REAL; }
{CONSTANT_STRING}               { printf("Constant string found %s at line: %d\n", yytext,line_num); 	yylval.str = strdup(yytext);	return TK_STRING; }


"+"                             {return OP_PLUS;}
"-"                             {return OP_MINUS;}
"*"                             {return OP_MULT;}
"/"                             {return OP_DIV;}
"%"                             {return OP_MOD;}
"**"                            {return OP_POWER;}

"=="                            {return ROP_EQUALS;}
"!="                            {return ROP_NOTEQUALS;}
"<"                             {return ROP_LESS;}
"<="                            {return ROP_LESSEQUALS;}
">"                             {return ROP_GREATER;}
">="                            {return ROP_GREATEREQUALS;}

"="                             {return AOP_ASSIGN;}
"+="                            {return AOP_PLUSASSIGN;}
"-+"                            {return AOP_MINASSIGN;}
"*="                            {return AOP_MULASSIGN;}
"/+"                            {return AOP_DIVASSIGN;}
"%="                            {return AOP_MODASSIGN;}
":="                            {return AOP_COLONASSIGN;}


";"                             {return DEL_SMCOLON;}
"("                             {return DEL_LPAR;}
")"                             {return DEL_RPAR;}
","                             {return DEL_COMMA;}
"["                             {return DEL_LBRACKET;}
"]"                             {return DEL_RBRACKET;}
":"                             {return DEL_COLON;}
"."                             {return DEL_DOT;}


[ \r\t]+                        /* skip whitespaces,tabs and carriage returns */
\n                              {line_num++;}


"--"                            { BEGIN(single_line_comment); }
<single_line_comment>[^\n]*     /*Eat anything in the line comment */
<single_line_comment>"\n"       { line_num++; BEGIN(INITIAL); }

<<EOF>>                         { return EOF; }  /*End of file*/
.                               { yyerror("lexical error: unrecognized literal '%s'\n", yytext); }

%%
/********* CODE SECTION ***********/
