%{
#include <stdio.h>
    int linenum = 1;
%}

/********* NAME DEFINITIONS SECTION ***********/

IDENTIFIER                      [a-zA-Z][a-zA-Z0-9_]*
DIGIT                           [0-9]
NON_ZERO_DIGIT                  [1-9]
INTEGER                         0|{NON_ZERO_DIGIT}{DIGIT}* 
REAL                            ({INTEGER})"."{DIGIT}+([eE][+-]?{INTEGER})?

/*ESCAPE_CHARS                    \\[ntr\\"]  characters \n,\t,\r,\",\\.To match them , we have to match the backslash using double \ */
/*COMMON_CHARS                    [^\"\\]       this excludes all the escape chars */

CONSTANT_STRING                 (\"(([^\"\\]|\\[ntr\\"'])*)\")

%%

{IDENTIFIER}            { printf("Identifier found : %s\n", yytext); linenum++; }
{INTEGER}               { printf("Integer found: %s\n", yytext);     linenum++; }
{REAL}                  { printf("Real found: %s\n", yytext);     linenum++; }
{CONSTANT_STRING}          { printf("Constant string found %s \n ", yytext); }

%% 

/********* CODE SECTION ***********/

int main() 
{
  yylex();
  return 0;
}
