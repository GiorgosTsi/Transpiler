/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MYPARSER_TAB_H_INCLUDED
# define YY_YY_MYPARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_IDENTIFIER = 258,           /* TK_IDENTIFIER  */
    TK_INTEGER = 259,              /* TK_INTEGER  */
    TK_REAL = 260,                 /* TK_REAL  */
    TK_STRING = 261,               /* TK_STRING  */
    KW_INT = 262,                  /* KW_INT  */
    KW_SCALAR = 263,               /* KW_SCALAR  */
    KW_STR = 264,                  /* KW_STR  */
    KW_BOOLEAN = 265,              /* KW_BOOLEAN  */
    KW_TRUE = 266,                 /* KW_TRUE  */
    KW_FALSE = 267,                /* KW_FALSE  */
    KW_CONST = 268,                /* KW_CONST  */
    KW_IF = 269,                   /* KW_IF  */
    KW_ELSE = 270,                 /* KW_ELSE  */
    KW_ENDIF = 271,                /* KW_ENDIF  */
    KW_FOR = 272,                  /* KW_FOR  */
    KW_IN = 273,                   /* KW_IN  */
    KW_ENDFOR = 274,               /* KW_ENDFOR  */
    KW_WHILE = 275,                /* KW_WHILE  */
    KW_ENDWHILE = 276,             /* KW_ENDWHILE  */
    KW_BREAK = 277,                /* KW_BREAK  */
    KW_CONTINUE = 278,             /* KW_CONTINUE  */
    KW_NOT = 279,                  /* KW_NOT  */
    KW_AND = 280,                  /* KW_AND  */
    KW_OR = 281,                   /* KW_OR  */
    KW_DEF = 282,                  /* KW_DEF  */
    KW_ENDDEF = 283,               /* KW_ENDDEF  */
    KW_MAIN = 284,                 /* KW_MAIN  */
    KW_RETURN = 285,               /* KW_RETURN  */
    KW_COMP = 286,                 /* KW_COMP  */
    KW_ENDCOMP = 287,              /* KW_ENDCOMP  */
    KW_OF = 288,                   /* KW_OF  */
    OP_PLUS = 289,                 /* OP_PLUS  */
    OP_MINUS = 290,                /* OP_MINUS  */
    OP_MULT = 291,                 /* OP_MULT  */
    OP_DIV = 292,                  /* OP_DIV  */
    OP_MOD = 293,                  /* OP_MOD  */
    OP_POWER = 294,                /* OP_POWER  */
    ROP_EQUALS = 295,              /* ROP_EQUALS  */
    ROP_NOTEQUALS = 296,           /* ROP_NOTEQUALS  */
    ROP_LESS = 297,                /* ROP_LESS  */
    ROP_LESSEQUALS = 298,          /* ROP_LESSEQUALS  */
    ROP_GREATER = 299,             /* ROP_GREATER  */
    ROP_GREATEREQUALS = 300,       /* ROP_GREATEREQUALS  */
    AOP_ASSIGN = 301,              /* AOP_ASSIGN  */
    AOP_PLUSASSIGN = 302,          /* AOP_PLUSASSIGN  */
    AOP_MINASSIGN = 303,           /* AOP_MINASSIGN  */
    AOP_MULASSIGN = 304,           /* AOP_MULASSIGN  */
    AOP_DIVASSIGN = 305,           /* AOP_DIVASSIGN  */
    AOP_MODASSIGN = 306,           /* AOP_MODASSIGN  */
    AOP_COLONASSIGN = 307,         /* AOP_COLONASSIGN  */
    AOP_ARROW = 308,               /* AOP_ARROW  */
    DEL_SMCOLON = 309,             /* DEL_SMCOLON  */
    DEL_LPAR = 310,                /* DEL_LPAR  */
    DEL_RPAR = 311,                /* DEL_RPAR  */
    DEL_COMMA = 312,               /* DEL_COMMA  */
    DEL_LBRACKET = 313,            /* DEL_LBRACKET  */
    DEL_RBRACKET = 314,            /* DEL_RBRACKET  */
    DEL_COLON = 315,               /* DEL_COLON  */
    DEL_DOT = 316,                 /* DEL_DOT  */
    HASH = 317                     /* HASH  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "myparser.y"

  char* str;

#line 130 "myparser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MYPARSER_TAB_H_INCLUDED  */
