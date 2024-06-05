/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "myparser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgen.h"

extern int yylex(void);
extern int line_num;

char* comp_name; // used to know the comptype name when do syntax analysis of comp_function


#line 84 "myparser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "myparser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_IDENTIFIER = 3,              /* TK_IDENTIFIER  */
  YYSYMBOL_TK_INTEGER = 4,                 /* TK_INTEGER  */
  YYSYMBOL_TK_REAL = 5,                    /* TK_REAL  */
  YYSYMBOL_TK_STRING = 6,                  /* TK_STRING  */
  YYSYMBOL_KW_INT = 7,                     /* KW_INT  */
  YYSYMBOL_KW_SCALAR = 8,                  /* KW_SCALAR  */
  YYSYMBOL_KW_STR = 9,                     /* KW_STR  */
  YYSYMBOL_KW_BOOLEAN = 10,                /* KW_BOOLEAN  */
  YYSYMBOL_KW_TRUE = 11,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 12,                  /* KW_FALSE  */
  YYSYMBOL_KW_CONST = 13,                  /* KW_CONST  */
  YYSYMBOL_KW_IF = 14,                     /* KW_IF  */
  YYSYMBOL_KW_ELSE = 15,                   /* KW_ELSE  */
  YYSYMBOL_KW_ENDIF = 16,                  /* KW_ENDIF  */
  YYSYMBOL_KW_FOR = 17,                    /* KW_FOR  */
  YYSYMBOL_KW_IN = 18,                     /* KW_IN  */
  YYSYMBOL_KW_ENDFOR = 19,                 /* KW_ENDFOR  */
  YYSYMBOL_KW_WHILE = 20,                  /* KW_WHILE  */
  YYSYMBOL_KW_ENDWHILE = 21,               /* KW_ENDWHILE  */
  YYSYMBOL_KW_BREAK = 22,                  /* KW_BREAK  */
  YYSYMBOL_KW_CONTINUE = 23,               /* KW_CONTINUE  */
  YYSYMBOL_KW_NOT = 24,                    /* KW_NOT  */
  YYSYMBOL_KW_AND = 25,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 26,                     /* KW_OR  */
  YYSYMBOL_KW_DEF = 27,                    /* KW_DEF  */
  YYSYMBOL_KW_ENDDEF = 28,                 /* KW_ENDDEF  */
  YYSYMBOL_KW_MAIN = 29,                   /* KW_MAIN  */
  YYSYMBOL_KW_RETURN = 30,                 /* KW_RETURN  */
  YYSYMBOL_KW_COMP = 31,                   /* KW_COMP  */
  YYSYMBOL_KW_ENDCOMP = 32,                /* KW_ENDCOMP  */
  YYSYMBOL_KW_OF = 33,                     /* KW_OF  */
  YYSYMBOL_OP_PLUS = 34,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 35,                  /* OP_MINUS  */
  YYSYMBOL_OP_MULT = 36,                   /* OP_MULT  */
  YYSYMBOL_OP_DIV = 37,                    /* OP_DIV  */
  YYSYMBOL_OP_MOD = 38,                    /* OP_MOD  */
  YYSYMBOL_OP_POWER = 39,                  /* OP_POWER  */
  YYSYMBOL_ROP_EQUALS = 40,                /* ROP_EQUALS  */
  YYSYMBOL_ROP_NOTEQUALS = 41,             /* ROP_NOTEQUALS  */
  YYSYMBOL_ROP_LESS = 42,                  /* ROP_LESS  */
  YYSYMBOL_ROP_LESSEQUALS = 43,            /* ROP_LESSEQUALS  */
  YYSYMBOL_ROP_GREATER = 44,               /* ROP_GREATER  */
  YYSYMBOL_ROP_GREATEREQUALS = 45,         /* ROP_GREATEREQUALS  */
  YYSYMBOL_AOP_ASSIGN = 46,                /* AOP_ASSIGN  */
  YYSYMBOL_AOP_PLUSASSIGN = 47,            /* AOP_PLUSASSIGN  */
  YYSYMBOL_AOP_MINASSIGN = 48,             /* AOP_MINASSIGN  */
  YYSYMBOL_AOP_MULASSIGN = 49,             /* AOP_MULASSIGN  */
  YYSYMBOL_AOP_DIVASSIGN = 50,             /* AOP_DIVASSIGN  */
  YYSYMBOL_AOP_MODASSIGN = 51,             /* AOP_MODASSIGN  */
  YYSYMBOL_AOP_COLONASSIGN = 52,           /* AOP_COLONASSIGN  */
  YYSYMBOL_AOP_ARROW = 53,                 /* AOP_ARROW  */
  YYSYMBOL_DEL_SMCOLON = 54,               /* DEL_SMCOLON  */
  YYSYMBOL_DEL_LPAR = 55,                  /* DEL_LPAR  */
  YYSYMBOL_DEL_RPAR = 56,                  /* DEL_RPAR  */
  YYSYMBOL_DEL_COMMA = 57,                 /* DEL_COMMA  */
  YYSYMBOL_DEL_LBRACKET = 58,              /* DEL_LBRACKET  */
  YYSYMBOL_DEL_RBRACKET = 59,              /* DEL_RBRACKET  */
  YYSYMBOL_DEL_COLON = 60,                 /* DEL_COLON  */
  YYSYMBOL_DEL_DOT = 61,                   /* DEL_DOT  */
  YYSYMBOL_HASH = 62,                      /* HASH  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_input = 64,                     /* input  */
  YYSYMBOL_declarations = 65,              /* declarations  */
  YYSYMBOL_declaration = 66,               /* declaration  */
  YYSYMBOL_main_func = 67,                 /* main_func  */
  YYSYMBOL_variable_declaration = 68,      /* variable_declaration  */
  YYSYMBOL_basic_data_type = 69,           /* basic_data_type  */
  YYSYMBOL_types = 70,                     /* types  */
  YYSYMBOL_identifier = 71,                /* identifier  */
  YYSYMBOL_comp = 72,                      /* comp  */
  YYSYMBOL_comp_body = 73,                 /* comp_body  */
  YYSYMBOL_comp_field = 74,                /* comp_field  */
  YYSYMBOL_comp_identifiers = 75,          /* comp_identifiers  */
  YYSYMBOL_comp_function = 76,             /* comp_function  */
  YYSYMBOL_const = 77,                     /* const  */
  YYSYMBOL_expr = 78,                      /* expr  */
  YYSYMBOL_arithmetic_expr = 79,           /* arithmetic_expr  */
  YYSYMBOL_identifier_expr = 80,           /* identifier_expr  */
  YYSYMBOL_relational_expr = 81,           /* relational_expr  */
  YYSYMBOL_logical_statements = 82,        /* logical_statements  */
  YYSYMBOL_function = 83,                  /* function  */
  YYSYMBOL_params = 84,                    /* params  */
  YYSYMBOL_func_body = 85,                 /* func_body  */
  YYSYMBOL_statements = 86,                /* statements  */
  YYSYMBOL_statement_body = 87,            /* statement_body  */
  YYSYMBOL_assign_statement = 88,          /* assign_statement  */
  YYSYMBOL_if_statement = 89,              /* if_statement  */
  YYSYMBOL_while_statement = 90,           /* while_statement  */
  YYSYMBOL_for_statement = 91,             /* for_statement  */
  YYSYMBOL_array_int_comprehension = 92,   /* array_int_comprehension  */
  YYSYMBOL_array_comprehension = 93,       /* array_comprehension  */
  YYSYMBOL_break_statement = 94,           /* break_statement  */
  YYSYMBOL_continue_statement = 95,        /* continue_statement  */
  YYSYMBOL_return_statement = 96,          /* return_statement  */
  YYSYMBOL_function_statement = 97,        /* function_statement  */
  YYSYMBOL_function_arguments = 98         /* function_arguments  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   742

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  285

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   178,   178,   179,   189,   201,   202,   206,   207,   208,
     209,   214,   221,   222,   223,   227,   228,   229,   230,   234,
     238,   239,   246,   257,   258,   262,   263,   267,   268,   272,
     278,   289,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   321,   322,   323,   324,   328,   329,   330,   331,   332,
     333,   337,   338,   339,   346,   347,   352,   353,   354,   355,
     356,   360,   361,   362,   363,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   385,   386,   387,   388,   393,
     394,   395,   396,   397,   398,   403,   404,   409,   413,   414,
     418,   423,   431,   435,   439,   440,   445,   446,   450,   451
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_IDENTIFIER",
  "TK_INTEGER", "TK_REAL", "TK_STRING", "KW_INT", "KW_SCALAR", "KW_STR",
  "KW_BOOLEAN", "KW_TRUE", "KW_FALSE", "KW_CONST", "KW_IF", "KW_ELSE",
  "KW_ENDIF", "KW_FOR", "KW_IN", "KW_ENDFOR", "KW_WHILE", "KW_ENDWHILE",
  "KW_BREAK", "KW_CONTINUE", "KW_NOT", "KW_AND", "KW_OR", "KW_DEF",
  "KW_ENDDEF", "KW_MAIN", "KW_RETURN", "KW_COMP", "KW_ENDCOMP", "KW_OF",
  "OP_PLUS", "OP_MINUS", "OP_MULT", "OP_DIV", "OP_MOD", "OP_POWER",
  "ROP_EQUALS", "ROP_NOTEQUALS", "ROP_LESS", "ROP_LESSEQUALS",
  "ROP_GREATER", "ROP_GREATEREQUALS", "AOP_ASSIGN", "AOP_PLUSASSIGN",
  "AOP_MINASSIGN", "AOP_MULASSIGN", "AOP_DIVASSIGN", "AOP_MODASSIGN",
  "AOP_COLONASSIGN", "AOP_ARROW", "DEL_SMCOLON", "DEL_LPAR", "DEL_RPAR",
  "DEL_COMMA", "DEL_LBRACKET", "DEL_RBRACKET", "DEL_COLON", "DEL_DOT",
  "HASH", "$accept", "input", "declarations", "declaration", "main_func",
  "variable_declaration", "basic_data_type", "types", "identifier", "comp",
  "comp_body", "comp_field", "comp_identifiers", "comp_function", "const",
  "expr", "arithmetic_expr", "identifier_expr", "relational_expr",
  "logical_statements", "function", "params", "func_body", "statements",
  "statement_body", "assign_statement", "if_statement", "while_statement",
  "for_statement", "array_int_comprehension", "array_comprehension",
  "break_statement", "continue_statement", "return_statement",
  "function_statement", "function_arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-192)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      75,   -50,    15,    11,    24,    31,    75,  -192,  -192,  -192,
      47,  -192,  -192,  -192,     6,  -192,   -20,   -10,    14,   -25,
    -192,  -192,  -192,    61,   175,    18,    22,   246,   100,    92,
     -16,  -192,  -192,  -192,  -192,  -192,  -192,    77,    96,   175,
      54,  -192,  -192,  -192,  -192,  -192,   246,   246,   246,   246,
     152,   304,  -192,  -192,  -192,  -192,  -192,    86,   104,   102,
     161,   163,   145,   -16,    72,  -192,  -192,   175,   125,    81,
      95,    64,   654,   654,   408,  -192,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     175,   130,   175,   -21,    97,   135,  -192,   139,  -192,   132,
     175,   141,  -192,  -192,   384,   140,   138,   144,  -192,   172,
    -192,   654,   654,   662,   662,   683,   683,   309,   197,     4,
     143,    -1,    64,   150,   149,   142,   175,    97,   684,   157,
     202,   160,   162,   167,   146,    97,    97,   171,   198,    97,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,   189,
     100,  -192,   241,   191,  -192,   246,  -192,  -192,  -192,  -192,
     175,   100,   186,   225,   246,   246,   246,   246,   246,   196,
       9,   246,   237,   246,  -192,  -192,  -192,   477,  -192,  -192,
     246,   205,  -192,  -192,   200,  -192,  -192,  -192,   204,  -192,
      97,   209,   498,   519,   540,   561,   582,   246,   207,   431,
     206,   454,  -192,   603,  -192,    21,   100,   239,  -192,  -192,
    -192,  -192,  -192,  -192,   633,    96,   211,   246,   212,  -192,
     175,    97,  -192,   215,   270,    97,   331,    97,   216,   247,
    -192,   218,    97,    97,    97,   108,   246,   262,    97,   230,
      87,  -192,  -192,  -192,   226,   244,   277,   245,   268,  -192,
     248,   286,   265,  -192,   249,   246,  -192,   251,   250,   303,
     242,   307,    97,   358,  -192,   175,   291,   271,   312,   266,
     274,   328,  -192,   279,    97,  -192,   296,  -192,   339,   299,
     306,   175,  -192,   308,  -192
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    20,     0,     0,     0,     0,     0,     6,     4,     7,
       0,     8,     9,    10,     0,    20,     0,     0,     0,     0,
       1,     5,     3,     0,     0,     0,     0,     0,    66,     0,
       0,    21,    15,    16,    17,    18,    19,     0,     0,     0,
      51,    41,    42,    33,    34,    35,     0,     0,     0,     0,
       0,     0,    37,    32,    38,    39,    40,     0,     0,     0,
       0,     0,     0,    23,     0,    26,    12,     0,     0,     0,
       0,    61,    49,    50,     0,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,     0,    27,     0,    24,     0,
       0,     0,    14,   106,   108,     0,     0,     0,    36,    62,
      63,    47,    48,    44,    45,    46,    43,    59,    60,    55,
      56,    57,    58,     0,     0,    67,     0,    71,    20,     0,
       0,     0,     0,     0,     0,    71,    71,     0,     0,    71,
      77,    75,    76,    78,    79,    80,    82,    83,    81,     0,
      66,    22,     0,     0,    13,     0,   107,    53,    54,    31,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,     0,    72,    73,
       0,     0,    74,    84,     0,    28,    25,   109,    69,    68,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,     0,    11,     0,    66,     0,    64,    90,
      91,    92,    93,    94,     0,    54,     0,     0,     0,    89,
       0,    71,    70,     0,     0,    85,     0,    85,     0,     0,
      65,     0,    85,    85,    85,     0,     0,     0,    71,     0,
       0,    86,    87,    88,     0,     0,     0,     0,     0,    29,
       0,     0,     0,    95,     0,     0,    97,     0,     0,     0,
      51,     0,    85,     0,    30,     0,     0,     0,     0,     0,
       0,     0,    96,     0,    85,   100,     0,    98,     0,     0,
       0,     0,    99,     0,   101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,  -192,   355,   357,     0,   -88,   -34,   375,  -192,
     315,  -192,  -192,  -192,     3,   -26,  -192,   -60,  -192,  -192,
    -192,  -133,  -120,   -99,  -191,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,   -14,   224
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,   135,    36,    37,    10,    11,
      62,    63,    64,    65,   136,   104,    52,    53,    54,    55,
      13,    58,   138,   139,   235,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    56,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    51,   123,    12,   125,    68,     9,   163,    14,    12,
      25,    60,   106,   198,    17,   178,   179,   184,    15,   182,
      71,    72,    73,    74,    76,    77,    27,    19,   189,    76,
      77,    20,   126,   101,   137,    30,   237,    23,   162,   127,
      18,   241,   242,   243,    89,    28,    61,    87,    88,    89,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    31,    26,   153,   137,    26,    29,
     207,   268,   188,   222,   220,   137,   137,    38,     1,   137,
     149,   221,    39,   278,    40,    41,    42,    43,     2,    76,
      77,   250,    44,    45,    32,    33,    34,    35,   106,   107,
     128,   229,     3,    57,    23,    46,     4,    24,   177,    69,
       2,   129,    70,   149,   130,    47,    48,   131,   248,   132,
     133,   149,   149,   244,   245,   149,   234,   134,   234,    99,
     137,    66,   100,   234,   234,   234,    49,   103,   192,   193,
     194,   195,   196,    50,    91,   199,    92,   201,    59,    40,
      41,    42,    43,   261,   203,    75,    67,    44,    45,    50,
      93,   137,    94,   234,    95,   137,    96,   137,    76,    77,
      46,   214,   137,   137,   137,   234,   149,    97,   137,   102,
      47,    48,    32,    33,    34,    35,   228,    88,    89,   124,
     150,   226,   137,   151,   152,   154,   156,   157,    77,   161,
     176,    49,   137,   158,   159,   172,   251,   149,    50,   160,
     246,   149,   171,   149,   137,   173,   174,   180,   149,   149,
     149,   175,    76,    77,   149,   232,   181,   232,   233,   263,
     233,   270,   232,   232,   232,   233,   233,   233,   149,    86,
      87,    88,    89,   183,   185,   186,   190,   283,   149,    40,
      41,    42,    43,   191,   197,   200,   205,    44,    45,   204,
     149,   206,   232,   208,   217,   233,   215,   223,   260,   230,
      46,   225,   227,   231,   232,   239,   238,   233,   240,   129,
      47,    48,   130,   247,   249,   131,   252,   132,   133,   164,
     165,   166,   167,   168,   169,   134,   257,    69,   253,   256,
      70,    49,    76,    77,   259,   264,   266,   258,    50,   262,
     265,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   267,   271,   272,   274,    50,   275,    76,
      77,   273,   276,   277,    76,    77,   254,   255,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      85,    86,    87,    88,    89,   279,    76,    77,   280,   281,
     282,    21,   284,    22,    90,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    16,    98,   187,
       0,     0,     0,    76,    77,     0,     0,     0,     0,     0,
       0,   236,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,     0,     0,    76,
      77,     0,     0,     0,     0,     0,     0,   269,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,    76,    77,     0,     0,     0,     0,     0,
       0,   155,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,    76,    77,     0,     0,
       0,     0,     0,     0,   108,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,    76,
      77,     0,     0,     0,     0,     0,     0,   216,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,    76,    77,     0,     0,     0,     0,     0,     0,
     218,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    76,    77,     0,     0,     0,     0,     0,
       0,   202,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    76,    77,     0,     0,     0,     0,
       0,     0,   209,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    76,    77,     0,     0,     0,
       0,     0,     0,   210,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    76,    77,     0,     0,
       0,     0,     0,     0,   211,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    76,    77,     0,
       0,     0,     0,     0,     0,   212,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    76,    77,
       0,     0,     0,     0,     0,     0,   213,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
     224,     0,     0,     0,     0,     0,     0,   219,    76,    77,
       0,     0,     0,     0,     0,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    76,
      77,     0,     0,     0,     0,     0,     0,    76,    77,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      82,    83,    84,    85,    86,    87,    88,    89,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    85,    86,    87,    88,    89,     0,
     -51,   164,   165,   166,   167,   168,   169,     0,     0,    69,
       0,     0,   170
};

static const yytype_int16 yycheck[] =
{
       0,    27,    90,     0,    92,    39,     6,   127,    58,     6,
       4,    27,     3,     4,     3,   135,   136,   150,     3,   139,
      46,    47,    48,    49,    25,    26,    46,     3,   161,    25,
      26,     0,    53,    67,    94,    60,   227,    57,   126,    60,
      29,   232,   233,   234,    45,    55,    62,    43,    44,    45,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     3,    59,   100,   127,    59,    55,
     190,   262,   160,   206,    53,   135,   136,    59,     3,   139,
      94,    60,    60,   274,     3,     4,     5,     6,    13,    25,
      26,     4,    11,    12,     7,     8,     9,    10,     3,     4,
       3,   221,    27,     3,    57,    24,    31,    60,   134,    55,
      13,    14,    58,   127,    17,    34,    35,    20,   238,    22,
      23,   135,   136,    15,    16,   139,   225,    30,   227,    57,
     190,    54,    60,   232,   233,   234,    55,    56,   164,   165,
     166,   167,   168,    62,    58,   171,    60,   173,    56,     3,
       4,     5,     6,   252,   180,     3,    60,    11,    12,    62,
      56,   221,    60,   262,     3,   225,     3,   227,    25,    26,
      24,   197,   232,   233,   234,   274,   190,    32,   238,    54,
      34,    35,     7,     8,     9,    10,   220,    44,    45,    59,
      55,   217,   252,    54,    62,    54,    56,    59,    26,    57,
      54,    55,   262,    59,    54,     3,   240,   221,    62,    60,
     236,   225,    55,   227,   274,    55,    54,    46,   232,   233,
     234,    54,    25,    26,   238,   225,    28,   227,   225,   255,
     227,   265,   232,   233,   234,   232,   233,   234,   252,    42,
      43,    44,    45,    54,     3,    54,    60,   281,   262,     3,
       4,     5,     6,    28,    58,    18,    56,    11,    12,    54,
     274,    57,   262,    54,    58,   262,    59,    28,     3,    54,
      24,    60,    60,     3,   274,    28,    60,   274,    60,    14,
      34,    35,    17,    21,    54,    20,    60,    22,    23,    47,
      48,    49,    50,    51,    52,    30,    28,    55,    54,    54,
      58,    55,    25,    26,    18,    54,     3,    59,    62,    60,
      60,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    16,    33,    54,    60,    62,    54,    25,
      26,    19,     4,    54,    25,    26,    59,    60,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      41,    42,    43,    44,    45,    59,    25,    26,    19,    60,
      54,     6,    54,     6,    60,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     2,    63,   155,
      -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    59,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    56,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    54,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      38,    39,    40,    41,    42,    43,    44,    45,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    -1,
      46,    47,    48,    49,    50,    51,    52,    -1,    -1,    55,
      -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    13,    27,    31,    64,    65,    66,    67,    68,
      71,    72,    77,    83,    58,     3,    71,     3,    29,     3,
       0,    66,    67,    57,    60,     4,    59,    46,    55,    55,
      60,     3,     7,     8,     9,    10,    69,    70,    59,    60,
       3,     4,     5,     6,    11,    12,    24,    34,    35,    55,
      62,    78,    79,    80,    81,    82,    97,     3,    84,    56,
      27,    62,    73,    74,    75,    76,    54,    60,    70,    55,
      58,    78,    78,    78,    78,     3,    25,    26,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      60,    58,    60,    56,    60,     3,     3,    32,    73,    57,
      60,    70,    54,    56,    78,    98,     3,     4,    56,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    69,    59,    69,    53,    60,     3,    14,
      17,    20,    22,    23,    30,    68,    77,    80,    85,    86,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      55,    54,    62,    70,    54,    57,    56,    59,    59,    54,
      60,    57,    69,    85,    47,    48,    49,    50,    51,    52,
      58,    55,     3,    55,    54,    54,    54,    78,    85,    85,
      46,    28,    85,    54,    84,     3,    54,    98,    69,    84,
      60,    28,    78,    78,    78,    78,    78,    58,     4,    78,
      18,    78,    54,    78,    54,    56,    57,    85,    54,    54,
      54,    54,    54,    54,    78,    59,    56,    58,    56,    54,
      53,    60,    84,    28,    17,    60,    78,    60,    70,    85,
      54,     3,    68,    77,    86,    87,    60,    87,    60,    28,
      60,    87,    87,    87,    15,    16,    78,    21,    85,    54,
       4,    70,    60,    54,    59,    60,    54,    28,    59,    18,
       3,    86,    60,    78,    54,    60,     3,    16,    87,    59,
      70,    33,    54,    19,    60,    54,     4,    54,    87,    59,
      19,    60,    54,    70,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    64,    64,    65,    65,    66,    66,    66,
      66,    67,    68,    68,    68,    69,    69,    69,    69,    70,
      71,    71,    72,    73,    73,    74,    74,    75,    75,    76,
      76,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    82,    82,    82,    83,    83,    84,    84,    84,    84,
      84,    85,    85,    85,    85,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    87,    87,    88,
      88,    88,    88,    88,    88,    89,    89,    90,    91,    91,
      92,    93,    94,    95,    96,    96,    97,    97,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     8,     4,     7,     6,     1,     1,     1,     1,     1,
       1,     3,     6,     1,     2,     4,     1,     2,     4,     9,
      11,     7,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     2,     4,     4,     3,     3,     3,     3,     3,
       3,     2,     3,     3,     9,    11,     0,     3,     5,     5,
       7,     0,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     0,     2,     2,     2,     4,
       4,     4,     4,     4,     4,     8,    11,     8,    12,    14,
      12,    16,     2,     2,     2,     3,     3,     4,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* input: declarations main_func  */
#line 179 "myparser.y"
                             { 
        if (yyerror_count == 0) {
            printf("Expression evaluates to:\n");
            printf("************************\n");
            puts(c_prologue);
            printf("\n\n%s\n%s\n", (yyvsp[-1].str), (yyvsp[0].str));
            printf("************************\n");
        }  
    }
#line 1456 "myparser.tab.c"
    break;

  case 4: /* input: main_func  */
#line 189 "myparser.y"
                { 
        if (yyerror_count == 0) {
            printf("Expression evaluates to:\n");
            printf("************************\n");
            puts(c_prologue);
            printf("\n\n%s\n", (yyvsp[0].str));
            printf("************************\n"); 
        }  
    }
#line 1470 "myparser.tab.c"
    break;

  case 5: /* declarations: declarations declaration  */
#line 201 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1476 "myparser.tab.c"
    break;

  case 6: /* declarations: declaration  */
#line 202 "myparser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1482 "myparser.tab.c"
    break;

  case 7: /* declaration: variable_declaration  */
#line 206 "myparser.y"
                       { (yyval.str) = (yyvsp[0].str); }
#line 1488 "myparser.tab.c"
    break;

  case 8: /* declaration: comp  */
#line 207 "myparser.y"
         { (yyval.str) = (yyvsp[0].str); }
#line 1494 "myparser.tab.c"
    break;

  case 9: /* declaration: const  */
#line 208 "myparser.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 1500 "myparser.tab.c"
    break;

  case 10: /* declaration: function  */
#line 209 "myparser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1506 "myparser.tab.c"
    break;

  case 11: /* main_func: KW_DEF KW_MAIN DEL_LPAR DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 214 "myparser.y"
                                                                               { (yyval.str) = template("int main () {\n%s\n}", (yyvsp[-2].str)); }
#line 1512 "myparser.tab.c"
    break;

  case 12: /* variable_declaration: identifier DEL_COLON types DEL_SMCOLON  */
#line 221 "myparser.y"
                                             { (yyval.str) = template("%s %s; ", (yyvsp[-1].str), (yyvsp[-3].str)); }
#line 1518 "myparser.tab.c"
    break;

  case 13: /* variable_declaration: TK_IDENTIFIER DEL_LBRACKET TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 222 "myparser.y"
                                                                                     { (yyval.str) = template("%s %s[%s]; ", (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-4].str)); }
#line 1524 "myparser.tab.c"
    break;

  case 14: /* variable_declaration: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 223 "myparser.y"
                                                                          { (yyval.str) = template("%s* %s;", (yyvsp[-1].str) , (yyvsp[-5].str)); }
#line 1530 "myparser.tab.c"
    break;

  case 15: /* basic_data_type: KW_INT  */
#line 227 "myparser.y"
             { (yyval.str) = template("%s", "int"); }
#line 1536 "myparser.tab.c"
    break;

  case 16: /* basic_data_type: KW_SCALAR  */
#line 228 "myparser.y"
                { (yyval.str) = template("%s", "double"); }
#line 1542 "myparser.tab.c"
    break;

  case 17: /* basic_data_type: KW_STR  */
#line 229 "myparser.y"
             { (yyval.str) = template("%s", "char*"); }
#line 1548 "myparser.tab.c"
    break;

  case 18: /* basic_data_type: KW_BOOLEAN  */
#line 230 "myparser.y"
                 { (yyval.str) = template("%s", "int"); }
#line 1554 "myparser.tab.c"
    break;

  case 20: /* identifier: TK_IDENTIFIER  */
#line 238 "myparser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1560 "myparser.tab.c"
    break;

  case 21: /* identifier: identifier DEL_COMMA TK_IDENTIFIER  */
#line 239 "myparser.y"
                                         { (yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1566 "myparser.tab.c"
    break;

  case 22: /* comp: KW_COMP TK_IDENTIFIER DEL_COLON comp_body KW_ENDCOMP DEL_SMCOLON  */
#line 247 "myparser.y"
    {

       //comp_name = strdup( template("%s", $2) );
       comp_name = strdup( (yyvsp[-4].str) );
       
       (yyval.str) = template("typedef struct %s {\n%s\n} %s;\n", (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-4].str)); 
    }
#line 1578 "myparser.tab.c"
    break;

  case 23: /* comp_body: comp_field  */
#line 257 "myparser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1584 "myparser.tab.c"
    break;

  case 24: /* comp_body: comp_field comp_body  */
#line 258 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1590 "myparser.tab.c"
    break;

  case 25: /* comp_field: comp_identifiers DEL_COLON types DEL_SMCOLON  */
#line 262 "myparser.y"
                                                 { (yyval.str) = template("%s %s;", (yyvsp[-1].str), (yyvsp[-3].str)); }
#line 1596 "myparser.tab.c"
    break;

  case 26: /* comp_field: comp_function  */
#line 263 "myparser.y"
                    { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 1602 "myparser.tab.c"
    break;

  case 27: /* comp_identifiers: HASH TK_IDENTIFIER  */
#line 267 "myparser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1608 "myparser.tab.c"
    break;

  case 28: /* comp_identifiers: comp_identifiers DEL_COMMA HASH TK_IDENTIFIER  */
#line 268 "myparser.y"
                                                    { (yyval.str) = template("%s, %s" , (yyvsp[-3].str) , (yyvsp[0].str)); }
#line 1614 "myparser.tab.c"
    break;

  case 29: /* comp_function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 273 "myparser.y"
    {
      char *func_declaration = template("void (*%s)(struct %s *self %s%s)", (yyvsp[-7].str), comp_name, ((yyvsp[-5].str)[0] != '\0') ? ", " : "" , (yyvsp[-5].str));
      char *func_definition = template("void %s(struct %s *self, %s) {\n%s\n}\n", (yyvsp[-7].str), (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-2].str));
      (yyval.str) = template("%s;\n", func_declaration);
    }
#line 1624 "myparser.tab.c"
    break;

  case 30: /* comp_function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW types DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 279 "myparser.y"
    {
      char *func_declaration = template("%s (*%s)(struct %s *self %s%s)", (yyvsp[-4].str), (yyvsp[-9].str), comp_name, ((yyvsp[-7].str)[0] != '\0') ? ", " : "", (yyvsp[-7].str));
      char *func_definition = template("%s %s(struct %s *self, %s) {\n%s\n}\n", (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-4].str));
      (yyval.str) = template("%s;\n", func_declaration);
    }
#line 1634 "myparser.tab.c"
    break;

  case 31: /* const: KW_CONST identifier AOP_ASSIGN expr DEL_COLON basic_data_type DEL_SMCOLON  */
#line 289 "myparser.y"
                                                                              { (yyval.str) = template("const %s %s = %s;", (yyvsp[-1].str), (yyvsp[-5].str), (yyvsp[-3].str)); }
#line 1640 "myparser.tab.c"
    break;

  case 32: /* expr: identifier_expr  */
#line 295 "myparser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1646 "myparser.tab.c"
    break;

  case 33: /* expr: TK_STRING  */
#line 296 "myparser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1652 "myparser.tab.c"
    break;

  case 34: /* expr: KW_TRUE  */
#line 297 "myparser.y"
              {(yyval.str) = template("1");}
#line 1658 "myparser.tab.c"
    break;

  case 35: /* expr: KW_FALSE  */
#line 298 "myparser.y"
               {(yyval.str) = template("0");}
#line 1664 "myparser.tab.c"
    break;

  case 36: /* expr: DEL_LPAR expr DEL_RPAR  */
#line 299 "myparser.y"
                             { (yyval.str) = template("(%s)", (yyvsp[-1].str)); }
#line 1670 "myparser.tab.c"
    break;

  case 37: /* expr: arithmetic_expr  */
#line 300 "myparser.y"
                      {(yyval.str) = (yyvsp[0].str);}
#line 1676 "myparser.tab.c"
    break;

  case 38: /* expr: relational_expr  */
#line 301 "myparser.y"
                      {(yyval.str) = (yyvsp[0].str);}
#line 1682 "myparser.tab.c"
    break;

  case 39: /* expr: logical_statements  */
#line 302 "myparser.y"
                         {(yyval.str) = (yyvsp[0].str);}
#line 1688 "myparser.tab.c"
    break;

  case 40: /* expr: function_statement  */
#line 303 "myparser.y"
                         {(yyval.str) = (yyvsp[0].str);}
#line 1694 "myparser.tab.c"
    break;

  case 41: /* arithmetic_expr: TK_INTEGER  */
#line 307 "myparser.y"
               {(yyval.str) = (yyvsp[0].str);}
#line 1700 "myparser.tab.c"
    break;

  case 42: /* arithmetic_expr: TK_REAL  */
#line 308 "myparser.y"
              {(yyval.str) = (yyvsp[0].str);}
#line 1706 "myparser.tab.c"
    break;

  case 43: /* arithmetic_expr: expr OP_POWER expr  */
#line 309 "myparser.y"
                         {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1712 "myparser.tab.c"
    break;

  case 44: /* arithmetic_expr: expr OP_MULT expr  */
#line 310 "myparser.y"
                        {(yyval.str) = template("%s * %s",(yyvsp[-2].str), (yyvsp[0].str));}
#line 1718 "myparser.tab.c"
    break;

  case 45: /* arithmetic_expr: expr OP_DIV expr  */
#line 311 "myparser.y"
                       {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1724 "myparser.tab.c"
    break;

  case 46: /* arithmetic_expr: expr OP_MOD expr  */
#line 312 "myparser.y"
                       {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1730 "myparser.tab.c"
    break;

  case 47: /* arithmetic_expr: expr OP_PLUS expr  */
#line 313 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1736 "myparser.tab.c"
    break;

  case 48: /* arithmetic_expr: expr OP_MINUS expr  */
#line 314 "myparser.y"
                         {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1742 "myparser.tab.c"
    break;

  case 49: /* arithmetic_expr: OP_PLUS expr  */
#line 315 "myparser.y"
                   {(yyval.str) = template("+%s", (yyvsp[0].str));}
#line 1748 "myparser.tab.c"
    break;

  case 50: /* arithmetic_expr: OP_MINUS expr  */
#line 316 "myparser.y"
                    {(yyval.str) = template("-%s", (yyvsp[0].str));}
#line 1754 "myparser.tab.c"
    break;

  case 51: /* identifier_expr: TK_IDENTIFIER  */
#line 321 "myparser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1760 "myparser.tab.c"
    break;

  case 52: /* identifier_expr: HASH TK_IDENTIFIER  */
#line 322 "myparser.y"
                       { {(yyval.str) = template("%s", (yyvsp[0].str));} }
#line 1766 "myparser.tab.c"
    break;

  case 53: /* identifier_expr: TK_IDENTIFIER DEL_LBRACKET TK_IDENTIFIER DEL_RBRACKET  */
#line 323 "myparser.y"
                                                          { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1772 "myparser.tab.c"
    break;

  case 54: /* identifier_expr: TK_IDENTIFIER DEL_LBRACKET TK_INTEGER DEL_RBRACKET  */
#line 324 "myparser.y"
                                                       { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1778 "myparser.tab.c"
    break;

  case 55: /* relational_expr: expr ROP_LESS expr  */
#line 328 "myparser.y"
                     {(yyval.str) = template("%s < %s",(yyvsp[-2].str), (yyvsp[0].str));}
#line 1784 "myparser.tab.c"
    break;

  case 56: /* relational_expr: expr ROP_LESSEQUALS expr  */
#line 329 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1790 "myparser.tab.c"
    break;

  case 57: /* relational_expr: expr ROP_GREATER expr  */
#line 330 "myparser.y"
                          {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1796 "myparser.tab.c"
    break;

  case 58: /* relational_expr: expr ROP_GREATEREQUALS expr  */
#line 331 "myparser.y"
                                {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1802 "myparser.tab.c"
    break;

  case 59: /* relational_expr: expr ROP_EQUALS expr  */
#line 332 "myparser.y"
                         {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1808 "myparser.tab.c"
    break;

  case 60: /* relational_expr: expr ROP_NOTEQUALS expr  */
#line 333 "myparser.y"
                            {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1814 "myparser.tab.c"
    break;

  case 61: /* logical_statements: KW_NOT expr  */
#line 337 "myparser.y"
                {(yyval.str) = template("! %s", (yyvsp[0].str));}
#line 1820 "myparser.tab.c"
    break;

  case 62: /* logical_statements: expr KW_AND expr  */
#line 338 "myparser.y"
                       {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1826 "myparser.tab.c"
    break;

  case 63: /* logical_statements: expr KW_OR expr  */
#line 339 "myparser.y"
                      {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1832 "myparser.tab.c"
    break;

  case 64: /* function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 346 "myparser.y"
                                                                                                                                                        {(yyval.str) = template("\nvoid %s(%s) {\n%s\n}\n", (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 1838 "myparser.tab.c"
    break;

  case 65: /* function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW basic_data_type DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 347 "myparser.y"
                                                                                                                        {(yyval.str) = template("\n%s %s(%s) {\n%s\n\n}\n", (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));}
#line 1844 "myparser.tab.c"
    break;

  case 66: /* params: %empty  */
#line 352 "myparser.y"
         { (yyval.str) = "" ;}
#line 1850 "myparser.tab.c"
    break;

  case 67: /* params: TK_IDENTIFIER DEL_COLON basic_data_type  */
#line 353 "myparser.y"
                                            {(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 1856 "myparser.tab.c"
    break;

  case 68: /* params: TK_IDENTIFIER DEL_COLON basic_data_type DEL_COMMA params  */
#line 354 "myparser.y"
                                                             {(yyval.str) = template("%s %s, %s", (yyvsp[-2].str), (yyvsp[-4].str), (yyvsp[0].str));}
#line 1862 "myparser.tab.c"
    break;

  case 69: /* params: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type  */
#line 355 "myparser.y"
                                                                      {(yyval.str) = template("%s *%s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 1868 "myparser.tab.c"
    break;

  case 70: /* params: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type DEL_COMMA params  */
#line 356 "myparser.y"
                                                                                      {(yyval.str) = template("%s *%s, %s", (yyvsp[-2].str), (yyvsp[-6].str), (yyvsp[0].str));}
#line 1874 "myparser.tab.c"
    break;

  case 71: /* func_body: %empty  */
#line 360 "myparser.y"
             { (yyval.str) = strdup(""); }
#line 1880 "myparser.tab.c"
    break;

  case 72: /* func_body: variable_declaration func_body  */
#line 361 "myparser.y"
                                     { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1886 "myparser.tab.c"
    break;

  case 73: /* func_body: const func_body  */
#line 362 "myparser.y"
                      { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1892 "myparser.tab.c"
    break;

  case 74: /* func_body: statements func_body  */
#line 363 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1898 "myparser.tab.c"
    break;

  case 84: /* statements: function_statement DEL_SMCOLON  */
#line 381 "myparser.y"
                                    { (yyval.str) = template("%s;", (yyvsp[-1].str)); }
#line 1904 "myparser.tab.c"
    break;

  case 85: /* statement_body: %empty  */
#line 385 "myparser.y"
               { (yyval.str) = "" ;}
#line 1910 "myparser.tab.c"
    break;

  case 86: /* statement_body: variable_declaration statement_body  */
#line 386 "myparser.y"
                                              {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1916 "myparser.tab.c"
    break;

  case 87: /* statement_body: const statement_body  */
#line 387 "myparser.y"
                          {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1922 "myparser.tab.c"
    break;

  case 88: /* statement_body: statements statement_body  */
#line 388 "myparser.y"
                                    {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1928 "myparser.tab.c"
    break;

  case 89: /* assign_statement: identifier_expr AOP_ASSIGN expr DEL_SMCOLON  */
#line 393 "myparser.y"
                                                          { (yyval.str) = template("%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1934 "myparser.tab.c"
    break;

  case 90: /* assign_statement: TK_IDENTIFIER AOP_PLUSASSIGN expr DEL_SMCOLON  */
#line 394 "myparser.y"
                                                        { (yyval.str) = template("%s += %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1940 "myparser.tab.c"
    break;

  case 91: /* assign_statement: TK_IDENTIFIER AOP_MINASSIGN expr DEL_SMCOLON  */
#line 395 "myparser.y"
                                                        { (yyval.str) = template("%s -= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1946 "myparser.tab.c"
    break;

  case 92: /* assign_statement: TK_IDENTIFIER AOP_MULASSIGN expr DEL_SMCOLON  */
#line 396 "myparser.y"
                                                        { (yyval.str) = template("%s *= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1952 "myparser.tab.c"
    break;

  case 93: /* assign_statement: TK_IDENTIFIER AOP_DIVASSIGN expr DEL_SMCOLON  */
#line 397 "myparser.y"
                                                        { (yyval.str) = template("%s /= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1958 "myparser.tab.c"
    break;

  case 94: /* assign_statement: TK_IDENTIFIER AOP_MODASSIGN expr DEL_SMCOLON  */
#line 398 "myparser.y"
                                                        { (yyval.str) = template("%s %%= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1964 "myparser.tab.c"
    break;

  case 95: /* if_statement: KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDIF DEL_SMCOLON  */
#line 403 "myparser.y"
                                                                                     {(yyval.str) = template("if (%s) {\n%s\n}", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 1970 "myparser.tab.c"
    break;

  case 96: /* if_statement: KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ELSE DEL_COLON statements KW_ENDIF DEL_SMCOLON  */
#line 404 "myparser.y"
                                                                                                                  {(yyval.str) = template("if (%s) {\n%s\n} else {\n%s\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 1976 "myparser.tab.c"
    break;

  case 97: /* while_statement: KW_WHILE DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDWHILE DEL_SMCOLON  */
#line 409 "myparser.y"
                                                                                           { (yyval.str) = template("while (%s)\n\t%s", (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 1982 "myparser.tab.c"
    break;

  case 98: /* for_statement: KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON  */
#line 413 "myparser.y"
                                                                                                                                  {(yyval.str) = template("for (int %s = %s; %s < %s; %s++) {\n%s\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-2].str));}
#line 1988 "myparser.tab.c"
    break;

  case 99: /* for_statement: KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON  */
#line 414 "myparser.y"
                                                                                                                                                   {(yyval.str) = template("for (int %s = %s; %s < %s; %s = %s + %s) 		{\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-12].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 1994 "myparser.tab.c"
    break;

  case 100: /* array_int_comprehension: TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 418 "myparser.y"
                                                                                                                                     {(yyval.str) = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(%s %s = 0; %s < %s; ++%s) {\n %s[%s] = %s;\n}", (yyvsp[-1].str), (yyvsp[-11].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-8].str));}
#line 2000 "myparser.tab.c"
    break;

  case 101: /* array_comprehension: TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON types KW_IN TK_IDENTIFIER KW_OF TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 424 "myparser.y"
        {
	char* replaced_expr = replace_str((yyvsp[-12].str), (yyvsp[-10].str), template("%s[%s_i]", (yyvsp[-6].str), (yyvsp[-6].str)));
	(yyval.str) = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(int %s_i = 0; %s_i < %s; ++%s_i) {\n\t%s[%s_i] = %s;\n}", (yyvsp[-1].str), (yyvsp[-15].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-15].str), (yyvsp[-6].str), replaced_expr);
	}
#line 2009 "myparser.tab.c"
    break;

  case 102: /* break_statement: KW_BREAK DEL_SMCOLON  */
#line 431 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2015 "myparser.tab.c"
    break;

  case 103: /* continue_statement: KW_CONTINUE DEL_SMCOLON  */
#line 435 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2021 "myparser.tab.c"
    break;

  case 104: /* return_statement: KW_RETURN DEL_SMCOLON  */
#line 439 "myparser.y"
                       {(yyval.str) = template("return;");}
#line 2027 "myparser.tab.c"
    break;

  case 105: /* return_statement: KW_RETURN expr DEL_SMCOLON  */
#line 440 "myparser.y"
                              {(yyval.str) = template("return %s;", (yyvsp[-1].str));}
#line 2033 "myparser.tab.c"
    break;

  case 106: /* function_statement: TK_IDENTIFIER DEL_LPAR DEL_RPAR  */
#line 445 "myparser.y"
                                  {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 2039 "myparser.tab.c"
    break;

  case 107: /* function_statement: TK_IDENTIFIER DEL_LPAR function_arguments DEL_RPAR  */
#line 446 "myparser.y"
                                                       {(yyval.str) = template("%s(%s)", (yyvsp[-3].str),(yyvsp[-1].str));}
#line 2045 "myparser.tab.c"
    break;

  case 108: /* function_arguments: expr  */
#line 450 "myparser.y"
       { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2051 "myparser.tab.c"
    break;

  case 109: /* function_arguments: expr DEL_COMMA function_arguments  */
#line 451 "myparser.y"
                                      { (yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2057 "myparser.tab.c"
    break;


#line 2061 "myparser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 456 "myparser.y"

/******************************************* CODE SECTION *******************************************/

int main () {
    if ( yyparse() == 0 )
        printf("Accepted!\n");
    else
        printf("Rejected!\n");
}

