%{
#include <stdio.h>
#include <string.h>
int linenum = 1;
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

%x single_line_comment
%x macro_value_definition
%s macro

%%


"integer"                       {printf("integer keyword found\n"); if(macro_initialization){exit(-1);}}
"scalar"                        {}
"str"                           {}
"bool"                          {}
"True"                          {}
"False"                         {}
"const"                         {}
"if"                            {}
"else"                          {}
"endif"                         {}
"for"                           {}
"in"                            {}
"endfor"                        {}
"while"                         {}
"endwhile"                      {}
"break"                         {}
"continue"                      {}
"not"                           {}
"and"                           {}
"or"                            {}
"def"                           {}
"enddef"                        {}
"main"                          {}
"return"                        {}
"comp"                          {}
"endcomp"                       {}
"of"                            {}

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

{IDENTIFIER}                    { printf("Identifier found : %s at line: %d\n", yytext,linenum); }
{INTEGER}                       { printf("Integer found: %s at line: %d\n", yytext,linenum); }
{REAL}                          { printf("Real found: %s at line: %d\n", yytext,linenum); }
{CONSTANT_STRING}               { printf("Constant string found %s at line: %d\n", yytext,linenum); }


"+"                             {}
"-"                             {}
"*"                             {}
"/"                             {}
"%"                             {}
"**"                            {}

"=="                            {}
"!="                            {}
"<"                             {}
"<="                            {}
">"                             {}
">="                            {}

"="                             {}
"+="                            {}
"-+"                            {}
"*="                            {}
"/+"                            {}
"%="                            {}
":="                            {}


";"                             {}
"("                             {}
")"                             {}
","                             {}
"["                             {}
"]"                             {}
":"                             {}
"."                             {}

[ \r\t]+                        /* skip whitespaces,tabs and carriage returns */
\n                              {linenum++;}

"--"                            { BEGIN(single_line_comment); }
<single_line_comment>[^\n]*     /*Eat anything in the line comment */
<single_line_comment>"\n"       { linenum++; BEGIN(INITIAL); }

<<EOF>>                         { return EOF; }  /*End of file*/
.                               { printf("Unrecognized token at line %d\n",linenum); }

%%

/********* CODE SECTION ***********/

int main()
{
  yylex();

  for(int i=0 ; i<macro_count; i++)
    free(macro_table[i]);
  
  return 0;
}