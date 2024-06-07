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

/*Used in array comprehension , to get the new expression with replaced elm->array[array_i] */
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


#line 115 "myparser.tab.c"

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   799

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  289

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
       0,   209,   209,   210,   220,   232,   233,   237,   238,   239,
     240,   245,   252,   256,   257,   258,   259,   263,   264,   268,
     271,   272,   273,   274,   281,   289,   290,   295,   296,   301,
     302,   303,   304,   305,   306,   311,   317,   328,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   361,   362,   363,
     364,   369,   370,   371,   372,   373,   374,   378,   379,   380,
     387,   388,   393,   394,   395,   396,   397,   401,   402,   403,
     404,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   426,   427,   428,   429,   434,   435,   436,   437,   438,
     439,   444,   445,   450,   454,   455,   459,   464,   472,   476,
     480,   481,   486,   487,   491,   492
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

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -49,     1,     5,    28,    34,    15,    11,  -161,  -161,
    -161,   107,  -161,  -161,  -161,  -161,   253,   -13,    -8,    13,
      18,  -161,  -161,  -161,  -161,    36,   136,    97,  -161,  -161,
    -161,  -161,  -161,   169,   169,   169,   169,  -161,   704,    24,
    -161,  -161,  -161,  -161,   169,    82,    46,   -21,    55,  -161,
    -161,  -161,  -161,  -161,  -161,    61,    92,   293,  -161,   110,
      96,  -161,   725,   725,   458,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,  -161,
     354,   -15,    86,    57,   129,   150,   125,   -21,   132,  -161,
       7,  -161,  -161,   434,   122,  -161,   158,  -161,   725,   725,
     733,   733,   754,   754,   157,   314,   275,    45,    74,    96,
     101,   135,   101,   -24,   321,   133,   139,   153,  -161,   146,
     136,   151,  -161,   169,  -161,   159,   160,   161,   101,   321,
      76,   156,   214,   164,   171,   172,   268,   321,   321,   389,
     205,   321,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,   180,    82,     8,  -161,   241,   193,  -161,  -161,  -161,
     101,    82,   186,   220,   191,   169,   232,   169,  -161,  -161,
    -161,   527,  -161,  -161,   169,   169,   169,   169,   169,   169,
     206,  -161,  -161,   207,   202,  -161,   204,  -161,   210,  -161,
     321,   216,   169,   481,   217,   504,  -161,   548,   569,   590,
     611,   632,   653,  -161,    12,  -161,    23,    82,   240,  -161,
     683,   223,   169,   224,  -161,  -161,  -161,  -161,  -161,  -161,
     136,   321,   226,  -161,  -161,   222,   283,   321,   381,   321,
     229,   262,  -161,  -161,   231,   321,   321,   321,   154,   169,
     272,   321,   252,   401,  -161,  -161,  -161,   235,   255,   327,
     256,   279,  -161,   254,   296,   192,  -161,   251,   169,  -161,
     267,   265,   313,    78,   389,   310,   321,   408,  -161,   136,
     298,   278,   317,   269,   288,   329,  -161,   291,   321,  -161,
     287,  -161,   318,   289,   300,   136,  -161,   306,  -161
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    57,     0,     0,     0,     0,     0,     0,     6,     4,
       7,     0,     8,     9,    19,    10,     0,     0,     0,     0,
       0,    58,     1,     5,     3,     0,     0,    57,    47,    48,
      39,    40,    41,     0,     0,     0,     0,    20,     0,    43,
      38,    44,    45,    46,     0,    72,     0,     0,    21,    18,
      13,    14,    15,    16,    17,     0,     0,     0,    59,    57,
      67,    43,    55,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
       0,     0,     0,     0,     0,     0,     0,    25,     0,    28,
       0,    12,   112,   114,     0,    42,    68,    69,    53,    54,
      50,    51,    52,    49,    65,    66,    61,    62,    63,    64,
       0,     0,     0,     0,    77,     0,    29,     0,    26,     0,
       0,     0,    23,     0,   113,     0,     0,    73,     0,    77,
      57,     0,     0,     0,     0,     0,     0,    77,    77,    19,
       0,    77,    83,    81,    82,    84,    85,    86,    88,    89,
      87,     0,    72,     0,    24,     0,     0,    22,   115,    37,
       0,    72,     0,     0,     0,     0,     0,     0,   108,   109,
     110,     0,    78,    79,     0,     0,     0,     0,     0,     0,
       0,    80,    90,     0,     0,    31,    32,    27,    75,    74,
      77,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,     0,    11,     0,    30,     0,    72,     0,    70,
       0,     0,     0,     0,    95,    96,    97,    98,    99,   100,
       0,    77,     0,    34,    76,     0,     0,    91,     0,    91,
       0,     0,    33,    71,     0,    91,    91,    91,     0,     0,
       0,    77,     0,     0,    92,    93,    94,     0,     0,     0,
       0,     0,    35,     0,     0,     0,   101,     0,     0,   103,
       0,     0,     0,    57,     0,     0,    91,     0,    36,     0,
       0,     0,     0,     0,     0,     0,   102,     0,    91,   106,
       0,   104,     0,     0,     0,     0,   105,     0,   107
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,  -161,   340,   343,     3,   -80,  -119,   371,  -161,
     290,  -161,  -161,  -161,    16,   -16,   -11,     0,  -161,  -161,
    -161,  -126,  -116,  -143,  -160,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,   -50,   258
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,   137,    54,    55,    11,    12,
      86,    87,    88,    89,   138,    38,    61,    40,    41,    42,
      15,    82,   140,   141,   238,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    43,    94
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,   156,    14,    10,     1,    39,    84,    14,    18,    16,
      10,   121,   184,   163,     1,    22,    13,    60,    62,    63,
      64,   172,   173,    13,     2,   181,   183,   222,    80,   128,
     125,    20,   127,    44,    19,   189,   129,    21,     3,    48,
      93,    85,     4,   111,    25,   112,    39,    45,   162,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     5,   151,   220,   122,   185,    46,   240,
      65,    66,   221,     5,   208,   244,   245,   246,    47,   151,
     188,   224,   223,    79,   237,    81,   237,   151,   151,    77,
      78,   151,   237,   237,   237,    59,    28,    29,    30,    65,
      66,   230,    83,    31,    32,   231,   272,    93,    50,    51,
      52,    53,   265,    90,   139,    91,    33,   114,   282,    78,
     171,    65,    66,   237,   254,   251,    34,    35,   164,   139,
     164,    56,   115,    56,    16,   237,    57,   139,   139,    49,
     151,   139,   113,    50,    51,    52,    53,    36,    92,   193,
     274,   195,    56,   116,     5,    57,    58,   117,   197,   198,
     199,   200,   201,   202,    25,    56,   287,    26,    57,   247,
     248,   151,    59,    28,    29,    30,   210,   151,   124,   151,
      31,    32,    65,    66,    66,   151,   151,   151,   152,   119,
     139,   151,   120,    33,   126,   263,   228,   153,    74,    75,
      76,    77,    78,    34,    35,   151,   131,   154,   155,   132,
     157,   165,   133,   159,   134,   135,   151,   166,   161,   167,
     160,   139,   136,   249,    36,   168,   169,   139,   151,   139,
     235,     5,   235,   180,   182,   139,   139,   139,   235,   235,
     235,   139,   267,   236,   186,   236,   190,   187,   191,   192,
     194,   236,   236,   236,     5,   264,    27,    28,    29,    30,
     203,   205,   206,   204,    31,    32,   139,   207,   225,   235,
     209,    59,    28,    29,    30,   212,   233,    33,   139,    31,
      32,   235,   236,   227,   229,   232,   234,    34,    35,   241,
     242,   243,    33,   250,   236,   255,    27,    28,    29,    30,
      65,    66,    34,    35,    31,    32,   252,   260,    36,   256,
     259,   266,    37,   261,   262,     5,   270,    33,    76,    77,
      78,   268,   170,    36,   130,   269,   271,    34,    35,   278,
       5,   275,   276,   280,     2,   131,   277,   284,   132,    65,
      66,   133,   279,   134,   135,   281,   283,    23,    36,   285,
      24,   136,    65,    66,   286,     5,    75,    76,    77,    78,
     288,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    17,     0,     0,     0,   118,     0,    65,
      66,   158,     0,     5,     0,     0,   257,   258,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,     0,     0,     0,    49,   253,    65,    66,    50,    51,
      52,    53,     0,     0,   110,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,     0,    65,    66,   174,   175,   176,   177,   178,
     179,   239,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,     0,     0,     0,     0,    65,
      66,     0,     0,     0,     0,     0,     0,   273,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,     0,     0,    65,    66,     0,     0,     0,     0,     0,
       0,   123,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,     0,    65,    66,     0,     0,
       0,     0,     0,     0,    95,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     0,    65,
      66,     0,     0,     0,     0,     0,     0,   211,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,     0,    65,    66,     0,     0,     0,     0,     0,     0,
     213,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    65,    66,     0,     0,     0,     0,     0,
       0,   196,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    65,    66,     0,     0,     0,     0,
       0,     0,   214,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    65,    66,     0,     0,     0,
       0,     0,     0,   215,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    65,    66,     0,     0,
       0,     0,     0,     0,   216,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    65,    66,     0,
       0,     0,     0,     0,     0,   217,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    65,    66,
       0,     0,     0,     0,     0,     0,   218,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
     226,     0,     0,     0,     0,     0,     0,   219,    65,    66,
       0,     0,     0,     0,     0,     0,     0,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    65,
      66,     0,     0,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      65,    66,     0,     0,     0,     0,     0,     0,    65,    66,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    71,    72,    73,    74,    75,    76,    77,    78,    65,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,    74,    75,    76,    77,    78
};

static const yytype_int16 yycheck[] =
{
       0,   120,     2,     0,     3,    16,    27,     7,     3,    58,
       7,     4,     4,   129,     3,     0,     0,    33,    34,    35,
      36,   137,   138,     7,    13,   141,   152,     4,    44,    53,
     110,     3,   112,    46,    29,   161,    60,     3,    27,     3,
      56,    62,    31,    58,    57,    60,    57,    55,   128,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    62,   114,    53,    59,    59,    55,   229,
      25,    26,    60,    62,   190,   235,   236,   237,    60,   129,
     160,   207,    59,    59,   227,     3,   229,   137,   138,    44,
      45,   141,   235,   236,   237,     3,     4,     5,     6,    25,
      26,   220,    56,    11,    12,   221,   266,   123,     7,     8,
       9,    10,   255,    58,   114,    54,    24,    60,   278,    45,
     136,    25,    26,   266,   243,   241,    34,    35,    52,   129,
      52,    55,     3,    55,    58,   278,    58,   137,   138,     3,
     190,   141,    56,     7,     8,     9,    10,    55,    56,   165,
     269,   167,    55,     3,    62,    58,    59,    32,   174,   175,
     176,   177,   178,   179,    57,    55,   285,    60,    58,    15,
      16,   221,     3,     4,     5,     6,   192,   227,    56,   229,
      11,    12,    25,    26,    26,   235,   236,   237,    55,    57,
     190,   241,    60,    24,    59,     3,   212,    58,    41,    42,
      43,    44,    45,    34,    35,   255,    14,    54,    62,    17,
      59,    55,    20,    54,    22,    23,   266,     3,    57,    55,
      60,   221,    30,   239,    55,    54,    54,   227,   278,   229,
     227,    62,   229,    28,    54,   235,   236,   237,   235,   236,
     237,   241,   258,   227,     3,   229,    60,    54,    28,    58,
      18,   235,   236,   237,    62,   255,     3,     4,     5,     6,
      54,    59,    58,    56,    11,    12,   266,    57,    28,   266,
      54,     3,     4,     5,     6,    58,    54,    24,   278,    11,
      12,   278,   266,    60,    60,    59,     3,    34,    35,    60,
      28,    60,    24,    21,   278,    60,     3,     4,     5,     6,
      25,    26,    34,    35,    11,    12,    54,    28,    55,    54,
      54,    60,    59,    59,    18,    62,     3,    24,    43,    44,
      45,    54,    54,    55,     3,    60,    16,    34,    35,    60,
      62,    33,    54,     4,    13,    14,    19,    19,    17,    25,
      26,    20,    54,    22,    23,    54,    59,     7,    55,    60,
       7,    30,    25,    26,    54,    62,    42,    43,    44,    45,
      54,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     2,    -1,    -1,    -1,    87,    -1,    25,
      26,   123,    -1,    62,    -1,    -1,    59,    60,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,     3,     4,    25,    26,     7,     8,
       9,    10,    -1,    -1,    60,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    46,    47,    48,    49,    50,
      51,    60,    34,    35,    36,    37,    38,    39,    40,    41,
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
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    38,    39,    40,    41,    42,    43,    44,    45,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    13,    27,    31,    62,    64,    65,    66,    67,
      68,    71,    72,    77,    80,    83,    58,    71,     3,    29,
       3,     3,     0,    66,    67,    57,    60,     3,     4,     5,
       6,    11,    12,    24,    34,    35,    55,    59,    78,    79,
      80,    81,    82,    97,    46,    55,    55,    60,     3,     3,
       7,     8,     9,    10,    69,    70,    55,    58,    59,     3,
      78,    79,    78,    78,    78,    25,    26,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    59,
      78,     3,    84,    56,    27,    62,    73,    74,    75,    76,
      58,    54,    56,    78,    98,    56,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      60,    58,    60,    56,    60,     3,     3,    32,    73,    57,
      60,     4,    59,    57,    56,    69,    59,    69,    53,    60,
       3,    14,    17,    20,    22,    23,    30,    68,    77,    80,
      85,    86,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    55,    58,    54,    62,    70,    59,    98,    54,
      60,    57,    69,    85,    52,    55,     3,    55,    54,    54,
      54,    78,    85,    85,    46,    47,    48,    49,    50,    51,
      28,    85,    54,    84,     4,    59,     3,    54,    69,    84,
      60,    28,    58,    78,    18,    78,    54,    78,    78,    78,
      78,    78,    78,    54,    56,    59,    58,    57,    85,    54,
      78,    56,    58,    56,    54,    54,    54,    54,    54,    54,
      53,    60,     4,    59,    84,    28,    17,    60,    78,    60,
      70,    85,    59,    54,     3,    68,    77,    86,    87,    60,
      87,    60,    28,    60,    87,    87,    87,    15,    16,    78,
      21,    85,    54,     4,    70,    60,    54,    59,    60,    54,
      28,    59,    18,     3,    80,    86,    60,    78,    54,    60,
       3,    16,    87,    59,    70,    33,    54,    19,    60,    54,
       4,    54,    87,    59,    19,    60,    54,    70,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    64,    64,    65,    65,    66,    66,    66,
      66,    67,    68,    69,    69,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    82,    82,    82,
      83,    83,    84,    84,    84,    84,    84,    85,    85,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    89,    89,    90,    91,    91,    92,    93,    94,    95,
      96,    96,    97,    97,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     1,     1,
       1,     8,     4,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     6,     5,     6,     1,     2,     4,     1,     2,
       5,     4,     4,     7,     6,     9,    11,     7,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     2,     4,
       4,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       9,    11,     0,     3,     5,     5,     7,     0,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     2,     2,     2,     4,     4,     4,     4,     4,
       4,     8,    11,     8,    12,    14,    12,    16,     2,     2,
       2,     3,     3,     4,     1,     3
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
#line 210 "myparser.y"
                             { 
        if (yyerror_count == 0) {
            printf("Expression evaluates to:\n");
            printf("************************\n");
            puts(c_prologue);
            printf("\n\n%s\n%s\n", (yyvsp[-1].str), (yyvsp[0].str));
            printf("************************\n");
        }  
    }
#line 1500 "myparser.tab.c"
    break;

  case 4: /* input: main_func  */
#line 220 "myparser.y"
                { 
        if (yyerror_count == 0) {
            printf("Expression evaluates to:\n");
            printf("************************\n");
            puts(c_prologue);
            printf("\n\n%s\n", (yyvsp[0].str));
            printf("************************\n"); 
        }  
    }
#line 1514 "myparser.tab.c"
    break;

  case 5: /* declarations: declarations declaration  */
#line 232 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1520 "myparser.tab.c"
    break;

  case 6: /* declarations: declaration  */
#line 233 "myparser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1526 "myparser.tab.c"
    break;

  case 7: /* declaration: variable_declaration  */
#line 237 "myparser.y"
                       { (yyval.str) = (yyvsp[0].str); }
#line 1532 "myparser.tab.c"
    break;

  case 8: /* declaration: comp  */
#line 238 "myparser.y"
         { (yyval.str) = (yyvsp[0].str); }
#line 1538 "myparser.tab.c"
    break;

  case 9: /* declaration: const  */
#line 239 "myparser.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 1544 "myparser.tab.c"
    break;

  case 10: /* declaration: function  */
#line 240 "myparser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1550 "myparser.tab.c"
    break;

  case 11: /* main_func: KW_DEF KW_MAIN DEL_LPAR DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 245 "myparser.y"
                                                                               { (yyval.str) = template("int main () {\n%s\n}", (yyvsp[-2].str)); }
#line 1556 "myparser.tab.c"
    break;

  case 12: /* variable_declaration: identifier DEL_COLON types DEL_SMCOLON  */
#line 252 "myparser.y"
                                         { (yyval.str) = template("%s %s;", (yyvsp[-1].str), (yyvsp[-3].str)); }
#line 1562 "myparser.tab.c"
    break;

  case 13: /* basic_data_type: KW_INT  */
#line 256 "myparser.y"
             { (yyval.str) = template("%s", "int"); }
#line 1568 "myparser.tab.c"
    break;

  case 14: /* basic_data_type: KW_SCALAR  */
#line 257 "myparser.y"
                { (yyval.str) = template("%s", "double"); }
#line 1574 "myparser.tab.c"
    break;

  case 15: /* basic_data_type: KW_STR  */
#line 258 "myparser.y"
             { (yyval.str) = template("%s", "char*"); }
#line 1580 "myparser.tab.c"
    break;

  case 16: /* basic_data_type: KW_BOOLEAN  */
#line 259 "myparser.y"
                 { (yyval.str) = template("%s", "int"); }
#line 1586 "myparser.tab.c"
    break;

  case 20: /* identifier: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET  */
#line 271 "myparser.y"
                                              {(yyval.str) = template("*%s", (yyvsp[-2].str));}
#line 1592 "myparser.tab.c"
    break;

  case 21: /* identifier: identifier DEL_COMMA TK_IDENTIFIER  */
#line 272 "myparser.y"
                                          { (yyval.str) = template("%s, %s" , (yyvsp[-2].str) , (yyvsp[0].str)); }
#line 1598 "myparser.tab.c"
    break;

  case 22: /* identifier: identifier DEL_COMMA TK_IDENTIFIER DEL_LBRACKET TK_INTEGER DEL_RBRACKET  */
#line 273 "myparser.y"
                                                                               { (yyval.str) = template("%s, %s[%s]" , (yyvsp[-5].str) , (yyvsp[-3].str) , (yyvsp[-1].str)); }
#line 1604 "myparser.tab.c"
    break;

  case 23: /* identifier: identifier DEL_COMMA TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET  */
#line 274 "myparser.y"
                                                                    { (yyval.str) = template("%s, *%s" , (yyvsp[-4].str) , (yyvsp[-2].str) ); }
#line 1610 "myparser.tab.c"
    break;

  case 24: /* comp: KW_COMP TK_IDENTIFIER DEL_COLON comp_body KW_ENDCOMP DEL_SMCOLON  */
#line 282 "myparser.y"
    {
       (yyval.str) = template("\n#define SELF struct %s *self\n\ntypedef struct %s {\n%s\n} %s;\n\n#undef SELF\n", (yyvsp[-4].str), (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-4].str)); 
    }
#line 1618 "myparser.tab.c"
    break;

  case 25: /* comp_body: comp_field  */
#line 289 "myparser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1624 "myparser.tab.c"
    break;

  case 26: /* comp_body: comp_field comp_body  */
#line 290 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1630 "myparser.tab.c"
    break;

  case 27: /* comp_field: comp_identifiers DEL_COLON types DEL_SMCOLON  */
#line 295 "myparser.y"
                                                 { (yyval.str) = template("%s %s;", (yyvsp[-1].str), (yyvsp[-3].str)); }
#line 1636 "myparser.tab.c"
    break;

  case 28: /* comp_field: comp_function  */
#line 296 "myparser.y"
                    { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 1642 "myparser.tab.c"
    break;

  case 29: /* comp_identifiers: HASH TK_IDENTIFIER  */
#line 301 "myparser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1648 "myparser.tab.c"
    break;

  case 30: /* comp_identifiers: HASH TK_IDENTIFIER DEL_LBRACKET TK_INTEGER DEL_RBRACKET  */
#line 302 "myparser.y"
                                                              {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1654 "myparser.tab.c"
    break;

  case 31: /* comp_identifiers: HASH TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET  */
#line 303 "myparser.y"
                                                   {(yyval.str) = template("*%s", (yyvsp[-2].str));}
#line 1660 "myparser.tab.c"
    break;

  case 32: /* comp_identifiers: comp_identifiers DEL_COMMA HASH TK_IDENTIFIER  */
#line 304 "myparser.y"
                                                    { (yyval.str) = template("%s, %s" , (yyvsp[-3].str) , (yyvsp[0].str)); }
#line 1666 "myparser.tab.c"
    break;

  case 33: /* comp_identifiers: comp_identifiers DEL_COMMA HASH TK_IDENTIFIER DEL_LBRACKET TK_INTEGER DEL_RBRACKET  */
#line 305 "myparser.y"
                                                                                         { (yyval.str) = template("%s, %s[%s]" , (yyvsp[-6].str) , (yyvsp[-3].str) , (yyvsp[-1].str)); }
#line 1672 "myparser.tab.c"
    break;

  case 34: /* comp_identifiers: comp_identifiers DEL_COMMA HASH TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET  */
#line 306 "myparser.y"
                                                                              { (yyval.str) = template("%s, *%s" , (yyvsp[-5].str) , (yyvsp[-2].str) ); }
#line 1678 "myparser.tab.c"
    break;

  case 35: /* comp_function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 312 "myparser.y"
    {
      char *func_declaration = template("void (*%s)(SELF %s%s)", (yyvsp[-7].str), ( ((yyvsp[-5].str)[0] != '\0') ? ", " : "" ) , (yyvsp[-5].str));
      char *func_definition = template("void %s(SELF, %s) {\n%s\n}\n", (yyvsp[-7].str), ( ((yyvsp[-5].str)[0] != '\0') ? ", " : "" ), (yyvsp[-2].str));
      (yyval.str) = template("%s;\n", func_declaration);
    }
#line 1688 "myparser.tab.c"
    break;

  case 36: /* comp_function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW types DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 318 "myparser.y"
    {
      char *func_declaration = template("%s (*%s)(SELF %s%s)", (yyvsp[-4].str), (yyvsp[-9].str), ((yyvsp[-7].str)[0] != '\0') ? ", " : "", (yyvsp[-7].str));
      char *func_definition = template("%s %s(SELF, %s) {\n%s\n}\n", (yyvsp[-4].str), (yyvsp[-9].str), ( ((yyvsp[-7].str)[0] != '\0') ? ", " : "" ), (yyvsp[-4].str));
      (yyval.str) = template("%s;\n", func_declaration);
    }
#line 1698 "myparser.tab.c"
    break;

  case 37: /* const: KW_CONST identifier AOP_ASSIGN expr DEL_COLON basic_data_type DEL_SMCOLON  */
#line 328 "myparser.y"
                                                                              { (yyval.str) = template("const %s %s = %s;", (yyvsp[-1].str), (yyvsp[-5].str), (yyvsp[-3].str)); }
#line 1704 "myparser.tab.c"
    break;

  case 38: /* expr: identifier_expr  */
#line 334 "myparser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1710 "myparser.tab.c"
    break;

  case 39: /* expr: TK_STRING  */
#line 335 "myparser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1716 "myparser.tab.c"
    break;

  case 40: /* expr: KW_TRUE  */
#line 336 "myparser.y"
              {(yyval.str) = template("1");}
#line 1722 "myparser.tab.c"
    break;

  case 41: /* expr: KW_FALSE  */
#line 337 "myparser.y"
               {(yyval.str) = template("0");}
#line 1728 "myparser.tab.c"
    break;

  case 42: /* expr: DEL_LPAR expr DEL_RPAR  */
#line 338 "myparser.y"
                             { (yyval.str) = template("(%s)", (yyvsp[-1].str)); }
#line 1734 "myparser.tab.c"
    break;

  case 43: /* expr: arithmetic_expr  */
#line 339 "myparser.y"
                      {(yyval.str) = (yyvsp[0].str);}
#line 1740 "myparser.tab.c"
    break;

  case 44: /* expr: relational_expr  */
#line 340 "myparser.y"
                      {(yyval.str) = (yyvsp[0].str);}
#line 1746 "myparser.tab.c"
    break;

  case 45: /* expr: logical_statements  */
#line 341 "myparser.y"
                         {(yyval.str) = (yyvsp[0].str);}
#line 1752 "myparser.tab.c"
    break;

  case 46: /* expr: function_statement  */
#line 342 "myparser.y"
                         {(yyval.str) = (yyvsp[0].str);}
#line 1758 "myparser.tab.c"
    break;

  case 47: /* arithmetic_expr: TK_INTEGER  */
#line 347 "myparser.y"
               {(yyval.str) = (yyvsp[0].str);}
#line 1764 "myparser.tab.c"
    break;

  case 48: /* arithmetic_expr: TK_REAL  */
#line 348 "myparser.y"
              {(yyval.str) = (yyvsp[0].str);}
#line 1770 "myparser.tab.c"
    break;

  case 49: /* arithmetic_expr: expr OP_POWER expr  */
#line 349 "myparser.y"
                         {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1776 "myparser.tab.c"
    break;

  case 50: /* arithmetic_expr: expr OP_MULT expr  */
#line 350 "myparser.y"
                        {(yyval.str) = template("%s * %s",(yyvsp[-2].str), (yyvsp[0].str));}
#line 1782 "myparser.tab.c"
    break;

  case 51: /* arithmetic_expr: expr OP_DIV expr  */
#line 351 "myparser.y"
                       {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1788 "myparser.tab.c"
    break;

  case 52: /* arithmetic_expr: expr OP_MOD expr  */
#line 352 "myparser.y"
                       {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1794 "myparser.tab.c"
    break;

  case 53: /* arithmetic_expr: expr OP_PLUS expr  */
#line 353 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1800 "myparser.tab.c"
    break;

  case 54: /* arithmetic_expr: expr OP_MINUS expr  */
#line 354 "myparser.y"
                         {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1806 "myparser.tab.c"
    break;

  case 55: /* arithmetic_expr: OP_PLUS expr  */
#line 355 "myparser.y"
                   {(yyval.str) = template("+%s", (yyvsp[0].str));}
#line 1812 "myparser.tab.c"
    break;

  case 56: /* arithmetic_expr: OP_MINUS expr  */
#line 356 "myparser.y"
                    {(yyval.str) = template("-%s", (yyvsp[0].str));}
#line 1818 "myparser.tab.c"
    break;

  case 57: /* identifier_expr: TK_IDENTIFIER  */
#line 361 "myparser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1824 "myparser.tab.c"
    break;

  case 58: /* identifier_expr: HASH TK_IDENTIFIER  */
#line 362 "myparser.y"
                       { {(yyval.str) = template("%s", (yyvsp[0].str));} }
#line 1830 "myparser.tab.c"
    break;

  case 59: /* identifier_expr: TK_IDENTIFIER DEL_LBRACKET TK_IDENTIFIER DEL_RBRACKET  */
#line 363 "myparser.y"
                                                          { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1836 "myparser.tab.c"
    break;

  case 60: /* identifier_expr: TK_IDENTIFIER DEL_LBRACKET arithmetic_expr DEL_RBRACKET  */
#line 364 "myparser.y"
                                                            { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1842 "myparser.tab.c"
    break;

  case 61: /* relational_expr: expr ROP_LESS expr  */
#line 369 "myparser.y"
                     {(yyval.str) = template("%s < %s",(yyvsp[-2].str), (yyvsp[0].str));}
#line 1848 "myparser.tab.c"
    break;

  case 62: /* relational_expr: expr ROP_LESSEQUALS expr  */
#line 370 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1854 "myparser.tab.c"
    break;

  case 63: /* relational_expr: expr ROP_GREATER expr  */
#line 371 "myparser.y"
                          {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1860 "myparser.tab.c"
    break;

  case 64: /* relational_expr: expr ROP_GREATEREQUALS expr  */
#line 372 "myparser.y"
                                {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1866 "myparser.tab.c"
    break;

  case 65: /* relational_expr: expr ROP_EQUALS expr  */
#line 373 "myparser.y"
                         {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1872 "myparser.tab.c"
    break;

  case 66: /* relational_expr: expr ROP_NOTEQUALS expr  */
#line 374 "myparser.y"
                            {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1878 "myparser.tab.c"
    break;

  case 67: /* logical_statements: KW_NOT expr  */
#line 378 "myparser.y"
                {(yyval.str) = template("! %s", (yyvsp[0].str));}
#line 1884 "myparser.tab.c"
    break;

  case 68: /* logical_statements: expr KW_AND expr  */
#line 379 "myparser.y"
                       {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1890 "myparser.tab.c"
    break;

  case 69: /* logical_statements: expr KW_OR expr  */
#line 380 "myparser.y"
                      {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1896 "myparser.tab.c"
    break;

  case 70: /* function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 387 "myparser.y"
                                                                                                                                                        {(yyval.str) = template("\nvoid %s(%s) {\n%s\n}\n", (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 1902 "myparser.tab.c"
    break;

  case 71: /* function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW basic_data_type DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 388 "myparser.y"
                                                                                                                        {(yyval.str) = template("\n%s %s(%s) {\n%s\n\n}\n", (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));}
#line 1908 "myparser.tab.c"
    break;

  case 72: /* params: %empty  */
#line 393 "myparser.y"
         { (yyval.str) = "" ;}
#line 1914 "myparser.tab.c"
    break;

  case 73: /* params: TK_IDENTIFIER DEL_COLON basic_data_type  */
#line 394 "myparser.y"
                                            {(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 1920 "myparser.tab.c"
    break;

  case 74: /* params: TK_IDENTIFIER DEL_COLON basic_data_type DEL_COMMA params  */
#line 395 "myparser.y"
                                                             {(yyval.str) = template("%s %s, %s", (yyvsp[-2].str), (yyvsp[-4].str), (yyvsp[0].str));}
#line 1926 "myparser.tab.c"
    break;

  case 75: /* params: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type  */
#line 396 "myparser.y"
                                                                      {(yyval.str) = template("%s *%s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 1932 "myparser.tab.c"
    break;

  case 76: /* params: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON basic_data_type DEL_COMMA params  */
#line 397 "myparser.y"
                                                                                      {(yyval.str) = template("%s *%s, %s", (yyvsp[-2].str), (yyvsp[-6].str), (yyvsp[0].str));}
#line 1938 "myparser.tab.c"
    break;

  case 77: /* func_body: %empty  */
#line 401 "myparser.y"
             { (yyval.str) = strdup(""); }
#line 1944 "myparser.tab.c"
    break;

  case 78: /* func_body: variable_declaration func_body  */
#line 402 "myparser.y"
                                     { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1950 "myparser.tab.c"
    break;

  case 79: /* func_body: const func_body  */
#line 403 "myparser.y"
                      { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1956 "myparser.tab.c"
    break;

  case 80: /* func_body: statements func_body  */
#line 404 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1962 "myparser.tab.c"
    break;

  case 90: /* statements: function_statement DEL_SMCOLON  */
#line 422 "myparser.y"
                                    { (yyval.str) = template("%s;", (yyvsp[-1].str)); }
#line 1968 "myparser.tab.c"
    break;

  case 91: /* statement_body: %empty  */
#line 426 "myparser.y"
               { (yyval.str) = "" ;}
#line 1974 "myparser.tab.c"
    break;

  case 92: /* statement_body: variable_declaration statement_body  */
#line 427 "myparser.y"
                                              {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1980 "myparser.tab.c"
    break;

  case 93: /* statement_body: const statement_body  */
#line 428 "myparser.y"
                          {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1986 "myparser.tab.c"
    break;

  case 94: /* statement_body: statements statement_body  */
#line 429 "myparser.y"
                                    {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1992 "myparser.tab.c"
    break;

  case 95: /* assign_statement: identifier_expr AOP_ASSIGN expr DEL_SMCOLON  */
#line 434 "myparser.y"
                                                          { (yyval.str) = template("%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 1998 "myparser.tab.c"
    break;

  case 96: /* assign_statement: identifier_expr AOP_PLUSASSIGN expr DEL_SMCOLON  */
#line 435 "myparser.y"
                                                          { (yyval.str) = template("%s += %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2004 "myparser.tab.c"
    break;

  case 97: /* assign_statement: identifier_expr AOP_MINASSIGN expr DEL_SMCOLON  */
#line 436 "myparser.y"
                                                          { (yyval.str) = template("%s -= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2010 "myparser.tab.c"
    break;

  case 98: /* assign_statement: identifier_expr AOP_MULASSIGN expr DEL_SMCOLON  */
#line 437 "myparser.y"
                                                          { (yyval.str) = template("%s *= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2016 "myparser.tab.c"
    break;

  case 99: /* assign_statement: identifier_expr AOP_DIVASSIGN expr DEL_SMCOLON  */
#line 438 "myparser.y"
                                                          { (yyval.str) = template("%s /= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2022 "myparser.tab.c"
    break;

  case 100: /* assign_statement: identifier_expr AOP_MODASSIGN expr DEL_SMCOLON  */
#line 439 "myparser.y"
                                                          { (yyval.str) = template("%s %%= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2028 "myparser.tab.c"
    break;

  case 101: /* if_statement: KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDIF DEL_SMCOLON  */
#line 444 "myparser.y"
                                                                                     {(yyval.str) = template("if (%s) {\n%s\n}", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2034 "myparser.tab.c"
    break;

  case 102: /* if_statement: KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ELSE DEL_COLON statements KW_ENDIF DEL_SMCOLON  */
#line 445 "myparser.y"
                                                                                                                  {(yyval.str) = template("if (%s) {\n%s\n} else {\n%s\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2040 "myparser.tab.c"
    break;

  case 103: /* while_statement: KW_WHILE DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDWHILE DEL_SMCOLON  */
#line 450 "myparser.y"
                                                                                           { (yyval.str) = template("while (%s)\n\t%s", (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 2046 "myparser.tab.c"
    break;

  case 104: /* for_statement: KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON  */
#line 454 "myparser.y"
                                                                                                                                  {(yyval.str) = template("for (int %s = %s; %s < %s; %s++) {\n%s\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-2].str));}
#line 2052 "myparser.tab.c"
    break;

  case 105: /* for_statement: KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON  */
#line 455 "myparser.y"
                                                                                                                                                   {(yyval.str) = template("for (int %s = %s; %s < %s; %s = %s + %s) 		{\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-12].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2058 "myparser.tab.c"
    break;

  case 106: /* array_int_comprehension: TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 459 "myparser.y"
                                                                                                                                     {(yyval.str) = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(%s %s = 0; %s < %s; ++%s) {\n %s[%s] = %s;\n}", (yyvsp[-1].str), (yyvsp[-11].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-8].str));}
#line 2064 "myparser.tab.c"
    break;

  case 107: /* array_comprehension: TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON types KW_IN TK_IDENTIFIER KW_OF TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 465 "myparser.y"
        {
	char* replaced_expr = replace_str((yyvsp[-12].str), (yyvsp[-10].str), template("%s[%s_i]", (yyvsp[-6].str), (yyvsp[-6].str)));
	(yyval.str) = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(int %s_i = 0; %s_i < %s; ++%s_i) {\n\t%s[%s_i] = %s;\n}", (yyvsp[-1].str), (yyvsp[-15].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-15].str), (yyvsp[-6].str), replaced_expr);
	}
#line 2073 "myparser.tab.c"
    break;

  case 108: /* break_statement: KW_BREAK DEL_SMCOLON  */
#line 472 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2079 "myparser.tab.c"
    break;

  case 109: /* continue_statement: KW_CONTINUE DEL_SMCOLON  */
#line 476 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2085 "myparser.tab.c"
    break;

  case 110: /* return_statement: KW_RETURN DEL_SMCOLON  */
#line 480 "myparser.y"
                       {(yyval.str) = template("return;");}
#line 2091 "myparser.tab.c"
    break;

  case 111: /* return_statement: KW_RETURN expr DEL_SMCOLON  */
#line 481 "myparser.y"
                              {(yyval.str) = template("return %s;", (yyvsp[-1].str));}
#line 2097 "myparser.tab.c"
    break;

  case 112: /* function_statement: TK_IDENTIFIER DEL_LPAR DEL_RPAR  */
#line 486 "myparser.y"
                                  {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 2103 "myparser.tab.c"
    break;

  case 113: /* function_statement: TK_IDENTIFIER DEL_LPAR function_arguments DEL_RPAR  */
#line 487 "myparser.y"
                                                       {(yyval.str) = template("%s(%s)", (yyvsp[-3].str),(yyvsp[-1].str));}
#line 2109 "myparser.tab.c"
    break;

  case 114: /* function_arguments: expr  */
#line 491 "myparser.y"
       { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2115 "myparser.tab.c"
    break;

  case 115: /* function_arguments: expr DEL_COMMA function_arguments  */
#line 492 "myparser.y"
                                      { (yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2121 "myparser.tab.c"
    break;


#line 2125 "myparser.tab.c"

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

#line 497 "myparser.y"

/******************************************* CODE SECTION *******************************************/

int main () {
    if ( yyparse() == 0 )
        printf( GREEN "Your program is syntactically correct!\n" RESET);
    else
        printf(RED "Rejected!\n" RESET);
}

