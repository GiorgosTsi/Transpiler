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
#define YYLAST   739

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  282

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

#define YYPACT_NINF (-148)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -39,    24,     7,    61,    79,    11,  -148,  -148,  -148,
      21,  -148,  -148,  -148,     8,  -148,   -20,    38,    39,    72,
    -148,  -148,  -148,   122,   240,    74,    75,   249,   143,    92,
     -19,  -148,  -148,  -148,  -148,  -148,  -148,    98,    89,   240,
      50,  -148,  -148,  -148,  -148,  -148,   249,   249,   249,   249,
     150,   280,  -148,  -148,  -148,  -148,  -148,   -47,   100,    94,
     157,   159,   126,   -19,    56,  -148,  -148,   240,   109,    95,
     274,     9,   651,   651,   384,  -148,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     240,   105,   240,   -28,   162,   115,  -148,   119,  -148,   107,
     240,   120,  -148,  -148,   360,   121,    37,   630,   128,  -148,
     152,  -148,   651,   651,   659,   659,   680,   680,     4,    78,
     155,    44,    65,     9,   134,   130,   136,   240,   162,   681,
     139,   188,   140,   151,   169,   234,   162,   162,   178,   162,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,   187,
     143,  -148,   194,   189,  -148,   249,  -148,  -148,  -148,  -148,
     240,   143,   144,   181,   249,   249,   249,   249,   249,   249,
     184,   249,   233,   249,  -148,  -148,  -148,   453,  -148,  -148,
     202,  -148,  -148,   201,  -148,  -148,  -148,   206,  -148,   162,
     210,   474,   495,   516,   537,   558,   579,   249,   407,   207,
     430,  -148,  -148,    58,   143,   238,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,   609,   212,   249,   215,   240,   162,  -148,
     213,   267,   162,   307,   162,   216,   253,  -148,   222,   162,
     162,   162,    25,   249,   273,   162,   241,   283,  -148,  -148,
    -148,   237,   245,   176,   246,   275,  -148,   242,   284,   114,
    -148,   247,   249,  -148,   256,   252,   310,   661,   311,   162,
     334,  -148,   240,   293,   276,   309,   271,   281,   330,  -148,
     285,   162,  -148,   278,  -148,   319,   294,   299,   240,  -148,
     301,  -148
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
       0,     0,    14,   106,   108,     0,    51,     0,    37,    36,
      62,    63,    47,    48,    44,    45,    46,    43,    59,    60,
      55,    56,    57,    58,     0,     0,    67,     0,    71,    20,
       0,     0,     0,     0,     0,     0,    71,    71,     0,    71,
      77,    75,    76,    78,    79,    80,    82,    83,    81,     0,
      66,    22,     0,     0,    13,     0,   107,    53,    54,    31,
       0,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,   103,   104,     0,    72,    73,
       0,    74,    84,     0,    28,    25,   109,    69,    68,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,    11,     0,    66,     0,    64,    89,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,    71,    70,
       0,     0,    85,     0,    85,     0,     0,    65,     0,    85,
      85,    85,     0,     0,     0,    71,     0,     0,    86,    87,
      88,     0,     0,     0,     0,     0,    29,     0,     0,     0,
      95,     0,     0,    97,     0,     0,     0,     0,     0,    85,
       0,    30,     0,     0,     0,     0,     0,     0,     0,    96,
       0,    85,   100,     0,    98,     0,     0,     0,     0,    99,
       0,   101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,   350,   351,     0,   -88,   -34,   356,  -148,
     298,  -148,  -148,  -148,     3,   -26,   292,  -148,  -148,  -148,
    -148,  -133,  -121,  -147,  -144,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,   -63,   208
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,     8,   136,    36,    37,    10,    11,
      62,    63,    64,    65,   137,   104,    52,    53,    54,    55,
      13,    58,   138,   139,   232,   140,   141,   142,   143,   144,
     145,   146,   147,   148,    56,   105
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    51,   124,    12,   126,    68,     9,   163,    60,    12,
      17,    91,    25,    92,     1,   178,   179,   183,   181,    14,
      71,    72,    73,    74,     2,   127,    27,    15,   188,    76,
      77,   149,   128,   101,    76,    77,    18,    23,     3,   162,
     241,   242,     4,    61,   107,    85,    86,    87,    88,    89,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,    19,   149,   153,    26,   205,    76,
      77,   219,   187,   149,   149,   231,   149,   231,    23,    20,
     234,    24,   231,   231,   231,   238,   239,   240,    88,    89,
      76,    77,    69,    28,    29,    70,   157,   226,    40,    41,
      42,    43,   258,    76,    77,    69,    44,    45,    70,   177,
      89,   217,   231,    99,   245,   265,   100,   257,   218,    46,
      86,    87,    88,    89,   231,    31,   149,   275,   130,    47,
      48,   131,    30,    38,   132,    39,   133,   134,   191,   192,
     193,   194,   195,   196,   135,   198,    57,   200,    59,    67,
      49,   103,    66,    75,    94,   149,    93,    50,    97,   149,
      95,   149,    96,   102,   125,   129,   149,   149,   149,   152,
     150,   213,   149,   151,   154,     2,   130,   156,    77,   131,
      76,    77,   132,   225,   133,   134,   149,   158,   159,   223,
     160,   172,   135,   161,   171,   173,   149,   184,    87,    88,
      89,    76,    77,   248,   189,   174,   180,   243,   149,   190,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,   229,   175,   229,   230,   260,   230,   267,   229,
     229,   229,   230,   230,   230,   251,   252,    40,    41,    42,
      43,   182,   197,   185,   280,    44,    45,    32,    33,    34,
      35,   199,    40,    41,    42,    43,   202,   203,    46,   229,
      44,    45,   230,   204,   206,   215,   220,   227,    47,    48,
     228,   229,   222,    46,   230,   224,   235,   106,    41,    42,
      43,   236,   237,    47,    48,    44,    45,   247,   176,    49,
      32,    33,    34,    35,   244,   246,    50,   249,    46,   250,
     253,   255,   256,   254,    49,    76,    77,   259,    47,    48,
     261,    50,   262,   263,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,   268,   264,   270,    49,
     269,   271,    76,    77,   273,   272,    50,   276,   277,   274,
      90,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,   279,   278,   281,    21,    22,    16,    76,
      77,    98,   108,   186,     0,     0,     0,   233,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,   266,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    76,
      77,     0,     0,     0,     0,     0,     0,   155,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,    76,    77,     0,     0,     0,     0,     0,     0,
     109,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,   214,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,    76,    77,
       0,     0,     0,     0,     0,     0,   216,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    76,
      77,     0,     0,     0,     0,     0,     0,   201,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      76,    77,     0,     0,     0,     0,     0,     0,   207,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    76,    77,     0,     0,     0,     0,     0,     0,   208,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    76,    77,     0,     0,     0,     0,     0,     0,
     209,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    76,    77,     0,     0,     0,     0,     0,
       0,   210,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    76,    77,     0,     0,     0,     0,
       0,     0,   211,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,   221,     0,     0,     0,
       0,     0,     0,   212,    76,    77,     0,     0,     0,     0,
       0,     0,     0,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    76,    77,     0,     0,     0,
       0,     0,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    76,    77,     0,     0,
       0,     0,     0,     0,    76,    77,     0,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    82,    83,    84,
      85,    86,    87,    88,    89,    76,    77,   164,   165,   166,
     167,   168,   169,   170,     0,     0,    69,     0,     0,    83,
      84,    85,    86,    87,    88,    89,     0,   164,   165,   166,
     167,   168,   169,   170,     0,     0,    69,     0,     0,    14
};

static const yytype_int16 yycheck[] =
{
       0,    27,    90,     0,    92,    39,     6,   128,    27,     6,
       3,    58,     4,    60,     3,   136,   137,   150,   139,    58,
      46,    47,    48,    49,    13,    53,    46,     3,   161,    25,
      26,    94,    60,    67,    25,    26,    29,    57,    27,   127,
      15,    16,    31,    62,    70,    41,    42,    43,    44,    45,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     3,   128,   100,    59,   189,    25,
      26,   204,   160,   136,   137,   222,   139,   224,    57,     0,
     224,    60,   229,   230,   231,   229,   230,   231,    44,    45,
      25,    26,    55,    55,    55,    58,    59,   218,     3,     4,
       5,     6,   249,    25,    26,    55,    11,    12,    58,   135,
      45,    53,   259,    57,   235,   259,    60,     3,    60,    24,
      42,    43,    44,    45,   271,     3,   189,   271,    14,    34,
      35,    17,    60,    59,    20,    60,    22,    23,   164,   165,
     166,   167,   168,   169,    30,   171,     3,   173,    56,    60,
      55,    56,    54,     3,    60,   218,    56,    62,    32,   222,
       3,   224,     3,    54,    59,     3,   229,   230,   231,    62,
      55,   197,   235,    54,    54,    13,    14,    56,    26,    17,
      25,    26,    20,   217,    22,    23,   249,    59,    54,   215,
      60,     3,    30,    57,    55,    55,   259,     3,    43,    44,
      45,    25,    26,   237,    60,    54,    28,   233,   271,    28,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   222,    54,   224,   222,   252,   224,   262,   229,
     230,   231,   229,   230,   231,    59,    60,     3,     4,     5,
       6,    54,    58,    54,   278,    11,    12,     7,     8,     9,
      10,    18,     3,     4,     5,     6,    54,    56,    24,   259,
      11,    12,   259,    57,    54,    58,    28,    54,    34,    35,
       3,   271,    60,    24,   271,    60,    60,     3,     4,     5,
       6,    28,    60,    34,    35,    11,    12,     4,    54,    55,
       7,     8,     9,    10,    21,    54,    62,    60,    24,    54,
      54,    59,    18,    28,    55,    25,    26,    60,    34,    35,
      54,    62,    60,     3,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    33,    16,    19,    55,
      54,    60,    25,    26,     4,    54,    62,    59,    19,    54,
      60,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    54,    60,    54,     6,     6,     2,    25,
      26,    63,    70,   155,    -1,    -1,    -1,    60,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    57,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    54,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    54,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    38,    39,    40,
      41,    42,    43,    44,    45,    25,    26,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,    58
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
      60,    70,    54,    56,    78,    98,     3,    78,    79,    56,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    69,    59,    69,    53,    60,     3,
      14,    17,    20,    22,    23,    30,    68,    77,    85,    86,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      55,    54,    62,    70,    54,    57,    56,    59,    59,    54,
      60,    57,    69,    85,    46,    47,    48,    49,    50,    51,
      52,    55,     3,    55,    54,    54,    54,    78,    85,    85,
      28,    85,    54,    84,     3,    54,    98,    69,    84,    60,
      28,    78,    78,    78,    78,    78,    78,    58,    78,    18,
      78,    54,    54,    56,    57,    85,    54,    54,    54,    54,
      54,    54,    54,    78,    56,    58,    56,    53,    60,    84,
      28,    17,    60,    78,    60,    70,    85,    54,     3,    68,
      77,    86,    87,    60,    87,    60,    28,    60,    87,    87,
      87,    15,    16,    78,    21,    85,    54,     4,    70,    60,
      54,    59,    60,    54,    28,    59,    18,     3,    86,    60,
      78,    54,    60,     3,    16,    87,    59,    70,    33,    54,
      19,    60,    54,     4,    54,    87,    59,    19,    60,    54,
      70,    54
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
#line 1454 "myparser.tab.c"
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
#line 1468 "myparser.tab.c"
    break;

  case 5: /* declarations: declarations declaration  */
#line 201 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1474 "myparser.tab.c"
    break;

  case 6: /* declarations: declaration  */
#line 202 "myparser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1480 "myparser.tab.c"
    break;

  case 7: /* declaration: variable_declaration  */
#line 206 "myparser.y"
                       { (yyval.str) = (yyvsp[0].str); }
#line 1486 "myparser.tab.c"
    break;

  case 8: /* declaration: comp  */
#line 207 "myparser.y"
         { (yyval.str) = (yyvsp[0].str); }
#line 1492 "myparser.tab.c"
    break;

  case 9: /* declaration: const  */
#line 208 "myparser.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 1498 "myparser.tab.c"
    break;

  case 10: /* declaration: function  */
#line 209 "myparser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1504 "myparser.tab.c"
    break;

  case 11: /* main_func: KW_DEF KW_MAIN DEL_LPAR DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 214 "myparser.y"
                                                                               { (yyval.str) = template("int main () {\n%s\n}", (yyvsp[-2].str)); }
#line 1510 "myparser.tab.c"
    break;

  case 12: /* variable_declaration: identifier DEL_COLON types DEL_SMCOLON  */
#line 221 "myparser.y"
                                             { (yyval.str) = template("%s %s; ", (yyvsp[-1].str), (yyvsp[-3].str)); }
#line 1516 "myparser.tab.c"
    break;

  case 13: /* variable_declaration: TK_IDENTIFIER DEL_LBRACKET TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 222 "myparser.y"
                                                                                     { (yyval.str) = template("%s %s[%s]; ", (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-4].str)); }
#line 1522 "myparser.tab.c"
    break;

  case 14: /* variable_declaration: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 223 "myparser.y"
                                                                          { (yyval.str) = template("%s* %s;", (yyvsp[-1].str) , (yyvsp[-5].str)); }
#line 1528 "myparser.tab.c"
    break;

  case 15: /* basic_data_type: KW_INT  */
#line 227 "myparser.y"
             { (yyval.str) = template("%s", "int"); }
#line 1534 "myparser.tab.c"
    break;

  case 16: /* basic_data_type: KW_SCALAR  */
#line 228 "myparser.y"
                { (yyval.str) = template("%s", "double"); }
#line 1540 "myparser.tab.c"
    break;

  case 17: /* basic_data_type: KW_STR  */
#line 229 "myparser.y"
             { (yyval.str) = template("%s", "char*"); }
#line 1546 "myparser.tab.c"
    break;

  case 18: /* basic_data_type: KW_BOOLEAN  */
#line 230 "myparser.y"
                 { (yyval.str) = template("%s", "int"); }
#line 1552 "myparser.tab.c"
    break;

  case 20: /* identifier: TK_IDENTIFIER  */
#line 238 "myparser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1558 "myparser.tab.c"
    break;

  case 21: /* identifier: identifier DEL_COMMA TK_IDENTIFIER  */
#line 239 "myparser.y"
                                         { (yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 1564 "myparser.tab.c"
    break;

  case 22: /* comp: KW_COMP TK_IDENTIFIER DEL_COLON comp_body KW_ENDCOMP DEL_SMCOLON  */
#line 247 "myparser.y"
    {

       //comp_name = strdup( template("%s", $2) );
       comp_name = strdup( (yyvsp[-4].str) );
       
       (yyval.str) = template("typedef struct %s {\n%s\n} %s;\n", (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-4].str)); 
    }
#line 1576 "myparser.tab.c"
    break;

  case 23: /* comp_body: comp_field  */
#line 257 "myparser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1582 "myparser.tab.c"
    break;

  case 24: /* comp_body: comp_field comp_body  */
#line 258 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1588 "myparser.tab.c"
    break;

  case 25: /* comp_field: comp_identifiers DEL_COLON types DEL_SMCOLON  */
#line 262 "myparser.y"
                                                 { (yyval.str) = template("%s %s;", (yyvsp[-1].str), (yyvsp[-3].str)); }
#line 1594 "myparser.tab.c"
    break;

  case 26: /* comp_field: comp_function  */
#line 263 "myparser.y"
                    { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 1600 "myparser.tab.c"
    break;

  case 27: /* comp_identifiers: HASH TK_IDENTIFIER  */
#line 267 "myparser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1606 "myparser.tab.c"
    break;

  case 28: /* comp_identifiers: comp_identifiers DEL_COMMA HASH TK_IDENTIFIER  */
#line 268 "myparser.y"
                                                    { (yyval.str) = template("%s, %s" , (yyvsp[-3].str) , (yyvsp[0].str)); }
#line 1612 "myparser.tab.c"
    break;

  case 29: /* comp_function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 273 "myparser.y"
    {
      char *func_declaration = template("void (*%s)(struct %s *self %s%s)", (yyvsp[-7].str), comp_name, ((yyvsp[-5].str)[0] != '\0') ? ", " : "" , (yyvsp[-5].str));
      char *func_definition = template("void %s(struct %s *self, %s) {\n%s\n}\n", (yyvsp[-7].str), (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-2].str));
      (yyval.str) = template("%s;\n", func_declaration);
    }
#line 1622 "myparser.tab.c"
    break;

  case 30: /* comp_function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW types DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 279 "myparser.y"
    {
      char *func_declaration = template("%s (*%s)(struct %s *self %s%s)", (yyvsp[-4].str), (yyvsp[-9].str), comp_name, ((yyvsp[-7].str)[0] != '\0') ? ", " : "", (yyvsp[-7].str));
      char *func_definition = template("%s %s(struct %s *self, %s) {\n%s\n}\n", (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-4].str));
      (yyval.str) = template("%s;\n", func_declaration);
    }
#line 1632 "myparser.tab.c"
    break;

  case 31: /* const: KW_CONST identifier AOP_ASSIGN expr DEL_COLON basic_data_type DEL_SMCOLON  */
#line 289 "myparser.y"
                                                                              { (yyval.str) = template("const %s %s = %s;", (yyvsp[-1].str), (yyvsp[-5].str), (yyvsp[-3].str)); }
#line 1638 "myparser.tab.c"
    break;

  case 32: /* expr: identifier_expr  */
#line 295 "myparser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1644 "myparser.tab.c"
    break;

  case 33: /* expr: TK_STRING  */
#line 296 "myparser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1650 "myparser.tab.c"
    break;

  case 34: /* expr: KW_TRUE  */
#line 297 "myparser.y"
              {(yyval.str) = template("1");}
#line 1656 "myparser.tab.c"
    break;

  case 35: /* expr: KW_FALSE  */
#line 298 "myparser.y"
               {(yyval.str) = template("0");}
#line 1662 "myparser.tab.c"
    break;

  case 36: /* expr: DEL_LPAR expr DEL_RPAR  */
#line 299 "myparser.y"
                             { (yyval.str) = template("(%s)", (yyvsp[-1].str)); }
#line 1668 "myparser.tab.c"
    break;

  case 37: /* expr: arithmetic_expr  */
#line 300 "myparser.y"
                      {(yyval.str) = (yyvsp[0].str);}
#line 1674 "myparser.tab.c"
    break;

  case 38: /* expr: relational_expr  */
#line 301 "myparser.y"
                      {(yyval.str) = (yyvsp[0].str);}
#line 1680 "myparser.tab.c"
    break;

  case 39: /* expr: logical_statements  */
#line 302 "myparser.y"
                         {(yyval.str) = (yyvsp[0].str);}
#line 1686 "myparser.tab.c"
    break;

  case 40: /* expr: function_statement  */
#line 303 "myparser.y"
                         {(yyval.str) = (yyvsp[0].str);}
#line 1692 "myparser.tab.c"
    break;

  case 41: /* arithmetic_expr: TK_INTEGER  */
#line 307 "myparser.y"
               {(yyval.str) = (yyvsp[0].str);}
#line 1698 "myparser.tab.c"
    break;

  case 42: /* arithmetic_expr: TK_REAL  */
#line 308 "myparser.y"
              {(yyval.str) = (yyvsp[0].str);}
#line 1704 "myparser.tab.c"
    break;

  case 43: /* arithmetic_expr: expr OP_POWER expr  */
#line 309 "myparser.y"
                         {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1710 "myparser.tab.c"
    break;

  case 44: /* arithmetic_expr: expr OP_MULT expr  */
#line 310 "myparser.y"
                        {(yyval.str) = template("%s * %s",(yyvsp[-2].str), (yyvsp[0].str));}
#line 1716 "myparser.tab.c"
    break;

  case 45: /* arithmetic_expr: expr OP_DIV expr  */
#line 311 "myparser.y"
                       {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1722 "myparser.tab.c"
    break;

  case 46: /* arithmetic_expr: expr OP_MOD expr  */
#line 312 "myparser.y"
                       {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1728 "myparser.tab.c"
    break;

  case 47: /* arithmetic_expr: expr OP_PLUS expr  */
#line 313 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1734 "myparser.tab.c"
    break;

  case 48: /* arithmetic_expr: expr OP_MINUS expr  */
#line 314 "myparser.y"
                         {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1740 "myparser.tab.c"
    break;

  case 49: /* arithmetic_expr: OP_PLUS expr  */
#line 315 "myparser.y"
                   {(yyval.str) = template("+%s", (yyvsp[0].str));}
#line 1746 "myparser.tab.c"
    break;

  case 50: /* arithmetic_expr: OP_MINUS expr  */
#line 316 "myparser.y"
                    {(yyval.str) = template("-%s", (yyvsp[0].str));}
#line 1752 "myparser.tab.c"
    break;

  case 51: /* identifier_expr: TK_IDENTIFIER  */
#line 321 "myparser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1758 "myparser.tab.c"
    break;

  case 52: /* identifier_expr: HASH TK_IDENTIFIER  */
#line 322 "myparser.y"
                       { {(yyval.str) = template("%s", (yyvsp[0].str));} }
#line 1764 "myparser.tab.c"
    break;

  case 53: /* identifier_expr: TK_IDENTIFIER DEL_LBRACKET TK_IDENTIFIER DEL_RBRACKET  */
#line 323 "myparser.y"
                                                          { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1770 "myparser.tab.c"
    break;

  case 54: /* identifier_expr: TK_IDENTIFIER DEL_LBRACKET arithmetic_expr DEL_RBRACKET  */
#line 324 "myparser.y"
                                                            { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1776 "myparser.tab.c"
    break;

  case 55: /* relational_expr: expr ROP_LESS expr  */
#line 328 "myparser.y"
                     {(yyval.str) = template("%s < %s",(yyvsp[-2].str), (yyvsp[0].str));}
#line 1782 "myparser.tab.c"
    break;

  case 56: /* relational_expr: expr ROP_LESSEQUALS expr  */
#line 329 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1788 "myparser.tab.c"
    break;

  case 57: /* relational_expr: expr ROP_GREATER expr  */
#line 330 "myparser.y"
                          {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1794 "myparser.tab.c"
    break;

  case 58: /* relational_expr: expr ROP_GREATEREQUALS expr  */
#line 331 "myparser.y"
                                {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1800 "myparser.tab.c"
    break;

  case 59: /* relational_expr: expr ROP_EQUALS expr  */
#line 332 "myparser.y"
                         {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1806 "myparser.tab.c"
    break;

  case 60: /* relational_expr: expr ROP_NOTEQUALS expr  */
#line 333 "myparser.y"
                            {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1812 "myparser.tab.c"
    break;

  case 61: /* logical_statements: KW_NOT expr  */
#line 337 "myparser.y"
                {(yyval.str) = template("! %s", (yyvsp[0].str));}
#line 1818 "myparser.tab.c"
    break;

  case 62: /* logical_statements: expr KW_AND expr  */
#line 338 "myparser.y"
                       {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1824 "myparser.tab.c"
    break;

  case 63: /* logical_statements: expr KW_OR expr  */
#line 339 "myparser.y"
                      {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1830 "myparser.tab.c"
    break;

  case 64: /* function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 346 "myparser.y"
                                                                                                                                                        {(yyval.str) = template("\nvoid %s(%s) {\n%s\n}\n", (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 1836 "myparser.tab.c"
    break;

  case 65: /* function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW basic_data_type DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 347 "myparser.y"
                                                                                                                        {(yyval.str) = template("\n%s %s(%s) {\n%s\n\n}\n", (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));}
#line 1842 "myparser.tab.c"
    break;

  case 66: /* params: %empty  */
#line 352 "myparser.y"
         { (yyval.str) = "" ;}
#line 1848 "myparser.tab.c"
    break;

  case 67: /* params: TK_IDENTIFIER DEL_COLON basic_data_type  */
#line 353 "myparser.y"
                                            {(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 1854 "myparser.tab.c"
    break;

  case 68: /* params: TK_IDENTIFIER DEL_COLON basic_data_type DEL_COMMA params  */
#line 354 "myparser.y"
                                                             {(yyval.str) = template("%s %s, %s", (yyvsp[-2].str), (yyvsp[-4].str), (yyvsp[0].str));}
#line 1860 "myparser.tab.c"
    break;

  case 69: /* params: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type  */
#line 355 "myparser.y"
                                                                      {(yyval.str) = template("%s *%s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 1866 "myparser.tab.c"
    break;

  case 70: /* params: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type DEL_COMMA params  */
#line 356 "myparser.y"
                                                                                      {(yyval.str) = template("%s *%s, %s", (yyvsp[-2].str), (yyvsp[-6].str), (yyvsp[0].str));}
#line 1872 "myparser.tab.c"
    break;

  case 71: /* func_body: %empty  */
#line 360 "myparser.y"
             { (yyval.str) = strdup(""); }
#line 1878 "myparser.tab.c"
    break;

  case 72: /* func_body: variable_declaration func_body  */
#line 361 "myparser.y"
                                     { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1884 "myparser.tab.c"
    break;

  case 73: /* func_body: const func_body  */
#line 362 "myparser.y"
                      { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1890 "myparser.tab.c"
    break;

  case 74: /* func_body: statements func_body  */
#line 363 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1896 "myparser.tab.c"
    break;

  case 84: /* statements: function_statement DEL_SMCOLON  */
#line 381 "myparser.y"
                                    { (yyval.str) = template("%s;", (yyvsp[-1].str)); }
#line 1902 "myparser.tab.c"
    break;

  case 85: /* statement_body: %empty  */
#line 385 "myparser.y"
               { (yyval.str) = "" ;}
#line 1908 "myparser.tab.c"
    break;

  case 86: /* statement_body: variable_declaration statement_body  */
#line 386 "myparser.y"
                                              {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1914 "myparser.tab.c"
    break;

  case 87: /* statement_body: const statement_body  */
#line 387 "myparser.y"
                          {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1920 "myparser.tab.c"
    break;

  case 88: /* statement_body: statements statement_body  */
#line 388 "myparser.y"
                                    {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1926 "myparser.tab.c"
    break;

  case 89: /* assign_statement: TK_IDENTIFIER AOP_ASSIGN expr DEL_SMCOLON  */
#line 393 "myparser.y"
                                                        { (yyval.str) = template("%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1932 "myparser.tab.c"
    break;

  case 90: /* assign_statement: TK_IDENTIFIER AOP_PLUSASSIGN expr DEL_SMCOLON  */
#line 394 "myparser.y"
                                                        { (yyval.str) = template("%s += %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1938 "myparser.tab.c"
    break;

  case 91: /* assign_statement: TK_IDENTIFIER AOP_MINASSIGN expr DEL_SMCOLON  */
#line 395 "myparser.y"
                                                        { (yyval.str) = template("%s -= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1944 "myparser.tab.c"
    break;

  case 92: /* assign_statement: TK_IDENTIFIER AOP_MULASSIGN expr DEL_SMCOLON  */
#line 396 "myparser.y"
                                                        { (yyval.str) = template("%s *= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1950 "myparser.tab.c"
    break;

  case 93: /* assign_statement: TK_IDENTIFIER AOP_DIVASSIGN expr DEL_SMCOLON  */
#line 397 "myparser.y"
                                                        { (yyval.str) = template("%s /= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1956 "myparser.tab.c"
    break;

  case 94: /* assign_statement: TK_IDENTIFIER AOP_MODASSIGN expr DEL_SMCOLON  */
#line 398 "myparser.y"
                                                        { (yyval.str) = template("%s %%= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1962 "myparser.tab.c"
    break;

  case 95: /* if_statement: KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDIF DEL_SMCOLON  */
#line 403 "myparser.y"
                                                                                     {(yyval.str) = template("if (%s) {\n%s\n}", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 1968 "myparser.tab.c"
    break;

  case 96: /* if_statement: KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ELSE DEL_COLON statements KW_ENDIF DEL_SMCOLON  */
#line 404 "myparser.y"
                                                                                                                  {(yyval.str) = template("if (%s) {\n%s\n} else {\n%s\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 1974 "myparser.tab.c"
    break;

  case 97: /* while_statement: KW_WHILE DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDWHILE DEL_SMCOLON  */
#line 409 "myparser.y"
                                                                                           { (yyval.str) = template("while (%s)\n\t%s", (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 1980 "myparser.tab.c"
    break;

  case 98: /* for_statement: KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON  */
#line 413 "myparser.y"
                                                                                                                                  {(yyval.str) = template("for (int %s = %s; %s < %s; %s++) {\n%s\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-2].str));}
#line 1986 "myparser.tab.c"
    break;

  case 99: /* for_statement: KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON  */
#line 414 "myparser.y"
                                                                                                                                                   {(yyval.str) = template("for (int %s = %s; %s < %s; %s = %s + %s) 		{\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-12].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 1992 "myparser.tab.c"
    break;

  case 100: /* array_int_comprehension: TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 418 "myparser.y"
                                                                                                                                     {(yyval.str) = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(%s %s = 0; %s < %s; ++%s) {\n %s[%s] = %s;\n}", (yyvsp[-1].str), (yyvsp[-11].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-8].str));}
#line 1998 "myparser.tab.c"
    break;

  case 101: /* array_comprehension: TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON types KW_IN TK_IDENTIFIER KW_OF TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 424 "myparser.y"
        {
	char* replaced_expr = replace_str((yyvsp[-12].str), (yyvsp[-10].str), template("%s[%s_i]", (yyvsp[-6].str), (yyvsp[-6].str)));
	(yyval.str) = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(int %s_i = 0; %s_i < %s; ++%s_i) {\n\t%s[%s_i] = %s;\n}", (yyvsp[-1].str), (yyvsp[-15].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-15].str), (yyvsp[-6].str), replaced_expr);
	}
#line 2007 "myparser.tab.c"
    break;

  case 102: /* break_statement: KW_BREAK DEL_SMCOLON  */
#line 431 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2013 "myparser.tab.c"
    break;

  case 103: /* continue_statement: KW_CONTINUE DEL_SMCOLON  */
#line 435 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2019 "myparser.tab.c"
    break;

  case 104: /* return_statement: KW_RETURN DEL_SMCOLON  */
#line 439 "myparser.y"
                       {(yyval.str) = template("return;");}
#line 2025 "myparser.tab.c"
    break;

  case 105: /* return_statement: KW_RETURN expr DEL_SMCOLON  */
#line 440 "myparser.y"
                              {(yyval.str) = template("return %s;", (yyvsp[-1].str));}
#line 2031 "myparser.tab.c"
    break;

  case 106: /* function_statement: TK_IDENTIFIER DEL_LPAR DEL_RPAR  */
#line 445 "myparser.y"
                                  {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 2037 "myparser.tab.c"
    break;

  case 107: /* function_statement: TK_IDENTIFIER DEL_LPAR function_arguments DEL_RPAR  */
#line 446 "myparser.y"
                                                       {(yyval.str) = template("%s(%s)", (yyvsp[-3].str),(yyvsp[-1].str));}
#line 2043 "myparser.tab.c"
    break;

  case 108: /* function_arguments: expr  */
#line 450 "myparser.y"
       { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2049 "myparser.tab.c"
    break;

  case 109: /* function_arguments: expr DEL_COMMA function_arguments  */
#line 451 "myparser.y"
                                      { (yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2055 "myparser.tab.c"
    break;


#line 2059 "myparser.tab.c"

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

