%{
#include <stdio.h>
#include <string.h>
    int linenum = 1;
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
MACRO_VALUE                     ([^\n])+

%x single_line_comment
%s macro

%%


"integer"                       {printf("integer keyword found\n");}
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

"@defmacro"                     { printf("Macro definition found\n"); BEGIN(macro); }
<macro>{IDENTIFIER}             { printf("Macro identifier found %s\n",yytext); }
<macro>{MACRO_VALUE}            { printf("Macro value found %s\n",yytext); }

{IDENTIFIER}                    { printf("Identifier found : %s at line: %d\n", yytext,linenum); linenum++; }
{INTEGER}                       { printf("Integer found: %s at line: %d\n", yytext,linenum);     linenum++; }
{REAL}                          { printf("Real found: %s at line: %d\n", yytext,linenum);     linenum++; }
{CONSTANT_STRING}               { printf("Constant string found %s at line: %d\n", yytext,linenum); linenum++; }


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
  return 0;
}
