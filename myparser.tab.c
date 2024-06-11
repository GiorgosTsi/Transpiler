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


#line 126 "myparser.tab.c"

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
#define YYLAST   993

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

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
       0,   220,   220,   221,   231,   243,   244,   248,   249,   250,
     251,   256,   263,   296,   297,   298,   299,   303,   304,   308,
     309,   310,   311,   312,   319,   336,   337,   342,   387,   392,
     393,   394,   395,   396,   397,   402,   439,   480,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   513,   514,   515,
     516,   517,   518,   522,   523,   524,   525,   526,   527,   531,
     532,   533,   539,   540,   545,   546,   547,   548,   549,   553,
     554,   555,   556,   565,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   578,   579,   580,   581,   586,   587,   588,
     589,   590,   591,   596,   597,   602,   606,   607,   611,   616,
     624,   628,   632,   633,   638,   639,   640,   641,   645,   646
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

#define YYPACT_NINF (-159)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      81,   -52,    10,     9,    11,    29,    19,    81,  -159,  -159,
    -159,    -5,  -159,  -159,    36,  -159,    87,    -7,    23,    48,
      46,    60,  -159,  -159,  -159,   123,    37,    12,    25,  -159,
    -159,  -159,  -159,  -159,   428,   428,   428,   428,  -159,   514,
    -159,    73,  -159,  -159,  -159,   428,   127,    85,   -26,   428,
      89,  -159,  -159,  -159,  -159,  -159,  -159,    96,  -159,   167,
     288,   428,    84,   940,   940,   694,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
    -159,    17,   460,    69,   115,   122,   181,   183,   156,   -26,
      45,  -159,   540,   292,  -159,  -159,  -159,   670,   131,  -159,
     166,  -159,   940,   940,   948,   948,   114,   114,   180,   191,
      70,    31,    75,    84,   140,   155,   137,    37,   -49,   190,
     142,   141,   144,  -159,   149,    37,  -159,  -159,   566,   428,
    -159,   325,   148,   159,   169,    37,   190,    -4,   160,   224,
     173,   175,   178,   329,   190,   190,   259,   210,   190,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,   189,   127,
     362,  -159,   241,   200,  -159,  -159,  -159,   201,  -159,    37,
     127,   196,   230,   206,   428,   251,   428,  -159,  -159,  -159,
     763,  -159,  -159,   428,   428,   428,   428,   428,   428,   205,
    -159,  -159,   219,  -159,   592,   218,  -159,  -159,   221,  -159,
     190,   225,   428,   717,   222,   740,  -159,   784,   805,   826,
     847,   868,   889,  -159,   -11,  -159,   395,   127,   254,  -159,
     919,   223,   428,   227,  -159,  -159,  -159,  -159,  -159,  -159,
      37,   190,  -159,   618,  -159,   231,   281,   190,   487,   190,
     228,   273,  -159,  -159,   253,   190,   190,   190,   158,   428,
     290,   190,   260,   263,  -159,  -159,  -159,   255,   264,   433,
     265,   289,  -159,   262,   306,   190,  -159,   278,   428,  -159,
     271,   279,   339,   330,   190,   644,  -159,    37,   312,   294,
     333,   295,   302,   353,  -159,   304,   190,  -159,   303,  -159,
     342,   309,   316,    37,  -159,   317,  -159
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    57,     0,     0,     0,     0,     0,     0,     6,     4,
       7,     0,     8,     9,    19,    10,     0,     0,     0,     0,
       0,    58,     1,     5,     3,     0,     0,     0,    57,    47,
      48,    39,    40,    41,     0,     0,     0,     0,    20,     0,
      43,    38,    44,    45,    46,     0,    74,     0,     0,     0,
      21,    18,    13,    14,    15,    16,    17,     0,    62,     0,
       0,     0,    69,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      59,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,    28,     0,     0,    12,    61,   114,   118,     0,    42,
      70,    71,    53,    54,    50,    51,    52,    49,    67,    68,
      63,    64,    65,    66,    62,     0,     0,     0,     0,    79,
       0,    29,     0,    26,     0,     0,    60,    23,     0,     0,
     115,     0,     0,     0,    75,     0,    79,    57,     0,     0,
       0,     0,     0,     0,    79,    79,    19,     0,    79,    85,
      83,    84,    86,    87,    88,    90,    91,    89,     0,    74,
       0,    24,     0,     0,    22,   119,   116,     0,    37,     0,
      74,     0,     0,     0,     0,     0,     0,   110,   111,   112,
       0,    80,    81,     0,     0,     0,     0,     0,     0,     0,
      82,    92,     0,    31,     0,    32,    27,   117,    77,    76,
      79,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,    11,     0,    30,     0,    74,     0,    72,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
       0,    79,    34,     0,    78,     0,     0,    93,     0,    93,
       0,     0,    33,    73,     0,    93,    93,    93,     0,     0,
       0,    79,     0,     0,    94,    95,    96,     0,     0,     0,
       0,     0,    35,     0,     0,    93,   103,     0,     0,   105,
       0,     0,     0,     0,    93,     0,    36,     0,     0,     0,
       0,     0,     0,     0,   104,     0,    93,   108,     0,   106,
       0,     0,     0,     0,   107,     0,   109
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,   365,   368,     3,   261,   -92,   375,  -159,
     293,  -159,  -159,  -159,    16,    -8,  -159,     0,  -159,  -159,
    -159,  -135,  -127,   -56,  -158,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -114,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,   144,    56,    57,    11,    12,
      88,    89,    90,    91,   145,    97,    40,    41,    42,    43,
      15,    84,   147,   148,   248,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    44,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    86,    14,    10,   135,   158,    16,    14,    39,   172,
      10,   136,    18,     1,    20,    58,    13,   181,   182,    22,
     114,   190,   158,    13,   192,   134,    62,    63,    64,    65,
     158,   158,    21,   163,   158,   199,    87,    82,    19,    45,
      51,    92,   230,   171,    52,    53,    54,    55,   173,   231,
      25,    60,    25,    39,    16,    26,    66,    67,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     5,   218,    59,    78,    79,   198,    46,    59,
      60,   250,   234,    61,     1,   128,   158,   254,   255,   256,
      28,    29,    30,    31,     2,    66,    67,    27,    32,    33,
      66,    67,   124,    47,   241,   125,    48,   273,     3,    66,
      67,    34,     4,    77,    78,    79,   280,   158,    49,   146,
      79,    35,    36,   158,   261,   158,    50,   116,   290,   117,
      83,   158,   158,   158,    81,   180,   146,   158,   240,    66,
      67,    85,    37,     5,   146,   146,    38,    93,   146,     5,
      94,   158,   194,    73,    74,    75,    76,    77,    78,    79,
     158,   264,    52,    53,    54,    55,   203,   165,   205,   167,
      95,   118,   158,   257,   258,   207,   208,   209,   210,   211,
     212,   247,   119,   247,   120,   282,   121,   130,   122,   247,
     247,   247,    67,   137,   220,   131,   133,   159,   161,   160,
     146,   295,   168,     2,   138,    66,    67,   139,   233,   247,
     140,   162,   141,   142,   238,   174,    66,    67,   247,   169,
     143,    75,    76,    77,    78,    79,   170,   175,   176,   177,
     247,   146,   178,    76,    77,    78,    79,   146,   189,   146,
     245,   259,   245,   191,   195,   146,   146,   146,   245,   245,
     245,   146,     5,   246,   196,   246,   200,   197,   201,   213,
     275,   246,   246,   246,   202,   146,    51,   263,   245,   204,
      52,    53,    54,    55,   146,   214,   216,   245,   217,   219,
     222,   246,   235,   237,   244,   243,   146,   239,   251,   245,
     246,    28,    29,    30,    31,    28,    29,    30,    31,    32,
      33,   252,   246,    32,    33,   183,   184,   185,   186,   187,
     188,   260,    34,   253,   262,   265,    34,   270,   266,   269,
      81,   271,    35,    36,   272,   276,    35,    36,    28,    29,
      30,    31,    28,    29,    30,    31,    32,    33,   274,   277,
      32,    33,   278,    37,    96,   283,   279,    37,   284,    34,
       5,   127,   285,    34,     5,   286,   287,   288,   289,    35,
      36,   292,   291,    35,    36,    28,    29,    30,    31,   293,
     294,   296,    23,    32,    33,    24,   132,    17,     0,     0,
      37,   166,   123,   179,    37,     0,    34,     5,     0,     0,
       0,     5,     0,     0,     0,     0,    35,    36,    28,    29,
      30,    31,     0,     0,     0,     0,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    34,
       0,   193,     0,     0,     5,     0,     0,     0,     0,    35,
      36,    28,    29,    30,    31,     0,     0,     0,     0,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,    34,     0,   232,     0,     0,     5,    66,    67,
       0,     0,    35,    36,     0,     0,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,    37,     0,    66,    67,     0,     0,     0,
       5,     0,   267,   268,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,     0,    66,    67,     0,     0,     0,     0,     0,     0,
     115,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,     0,     0,     0,     0,    66,
      67,     0,     0,     0,     0,     0,     0,   249,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,     0,     0,     0,    66,    67,     0,     0,     0,
       0,     0,     0,    80,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,     0,
       0,    66,    67,     0,     0,     0,     0,     0,     0,   126,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,     0,     0,     0,    66,    67,     0,
       0,     0,     0,     0,     0,   164,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
       0,     0,     0,    66,    67,     0,     0,     0,     0,     0,
       0,   215,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,     0,     0,     0,    66,
      67,     0,     0,     0,     0,     0,     0,   242,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,     0,     0,     0,    66,    67,     0,     0,     0,
       0,     0,     0,   281,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,     0,    66,
      67,     0,     0,     0,     0,     0,     0,   129,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,    66,    67,     0,     0,     0,     0,     0,     0,
      99,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    66,    67,     0,     0,     0,
       0,     0,     0,   221,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    66,    67,
       0,     0,     0,     0,     0,     0,   223,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    66,
      67,     0,     0,     0,     0,     0,     0,   206,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      66,    67,     0,     0,     0,     0,     0,     0,   224,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    66,    67,     0,     0,     0,     0,     0,     0,   225,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    66,    67,     0,     0,     0,     0,     0,     0,
     226,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    66,    67,     0,     0,     0,     0,     0,
       0,   227,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    66,    67,     0,     0,     0,     0,
       0,     0,   228,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,   236,     0,     0,     0,
       0,     0,     0,   229,    66,    67,     0,     0,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    66,    67,     0,     0,     0,
       0,     0,     0,    66,    67,     0,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    72,    73,    74,    75,
      76,    77,    78,    79
};

static const yytype_int16 yycheck[] =
{
       0,    27,     2,     0,    53,   119,    58,     7,    16,   136,
       7,    60,     3,     3,     3,     3,     0,   144,   145,     0,
       3,   148,   136,     7,   159,   117,    34,    35,    36,    37,
     144,   145,     3,   125,   148,   170,    62,    45,    29,    46,
       3,    49,    53,   135,     7,     8,     9,    10,    52,    60,
      57,    55,    57,    61,    58,    60,    25,    26,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    62,   200,    62,    44,    45,   169,    55,    62,
      55,   239,   217,    58,     3,    93,   200,   245,   246,   247,
       3,     4,     5,     6,    13,    25,    26,    61,    11,    12,
      25,    26,    57,    55,   231,    60,    60,   265,    27,    25,
      26,    24,    31,    43,    44,    45,   274,   231,    58,   119,
      45,    34,    35,   237,   251,   239,     3,    58,   286,    60,
       3,   245,   246,   247,    61,   143,   136,   251,   230,    25,
      26,    56,    55,    62,   144,   145,    59,    58,   148,    62,
      54,   265,   160,    39,    40,    41,    42,    43,    44,    45,
     274,   253,     7,     8,     9,    10,   174,   129,   176,   131,
       3,    56,   286,    15,    16,   183,   184,   185,   186,   187,
     188,   237,    60,   239,     3,   277,     3,    56,    32,   245,
     246,   247,    26,     3,   202,    55,    59,    55,    54,    58,
     200,   293,    54,    13,    14,    25,    26,    17,   216,   265,
      20,    62,    22,    23,   222,    55,    25,    26,   274,    60,
      30,    41,    42,    43,    44,    45,    57,     3,    55,    54,
     286,   231,    54,    42,    43,    44,    45,   237,    28,   239,
     237,   249,   239,    54,     3,   245,   246,   247,   245,   246,
     247,   251,    62,   237,    54,   239,    60,    56,    28,    54,
     268,   245,   246,   247,    58,   265,     3,     4,   265,    18,
       7,     8,     9,    10,   274,    56,    58,   274,    57,    54,
      58,   265,    28,    60,     3,    54,   286,    60,    60,   286,
     274,     3,     4,     5,     6,     3,     4,     5,     6,    11,
      12,    28,   286,    11,    12,    46,    47,    48,    49,    50,
      51,    21,    24,    60,    54,    60,    24,    28,    54,    54,
      61,    59,    34,    35,    18,    54,    34,    35,     3,     4,
       5,     6,     3,     4,     5,     6,    11,    12,    60,    60,
      11,    12,     3,    55,    56,    33,    16,    55,    54,    24,
      62,    59,    19,    24,    62,    60,    54,     4,    54,    34,
      35,    19,    59,    34,    35,     3,     4,     5,     6,    60,
      54,    54,     7,    11,    12,     7,   115,     2,    -1,    -1,
      55,    56,    89,    54,    55,    -1,    24,    62,    -1,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    34,    35,     3,     4,
       5,     6,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    24,
      -1,    59,    -1,    -1,    62,    -1,    -1,    -1,    -1,    34,
      35,     3,     4,     5,     6,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,    24,    -1,    59,    -1,    -1,    62,    25,    26,
      -1,    -1,    34,    35,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    55,    -1,    25,    26,    -1,    -1,    -1,
      62,    -1,    59,    60,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    60,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    59,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    59,    34,    35,
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
      -1,    -1,    -1,    25,    26,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    38,    39,    40,    41,
      42,    43,    44,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    13,    27,    31,    62,    64,    65,    66,    67,
      68,    71,    72,    77,    80,    83,    58,    71,     3,    29,
       3,     3,     0,    66,    67,    57,    60,    61,     3,     4,
       5,     6,    11,    12,    24,    34,    35,    55,    59,    78,
      79,    80,    81,    82,    97,    46,    55,    55,    60,    58,
       3,     3,     7,     8,     9,    10,    69,    70,     3,    62,
      55,    58,    78,    78,    78,    78,    25,    26,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      59,    61,    78,     3,    84,    56,    27,    62,    73,    74,
      75,    76,    78,    58,    54,     3,    56,    78,    98,    56,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,     3,    60,    58,    60,    56,    60,
       3,     3,    32,    73,    57,    60,    59,    59,    78,    57,
      56,    55,    69,    59,    70,    53,    60,     3,    14,    17,
      20,    22,    23,    30,    68,    77,    80,    85,    86,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    55,
      58,    54,    62,    70,    59,    98,    56,    98,    54,    60,
      57,    70,    85,    52,    55,     3,    55,    54,    54,    54,
      78,    85,    85,    46,    47,    48,    49,    50,    51,    28,
      85,    54,    84,    59,    78,     3,    54,    56,    70,    84,
      60,    28,    58,    78,    18,    78,    54,    78,    78,    78,
      78,    78,    78,    54,    56,    59,    58,    57,    85,    54,
      78,    56,    58,    56,    54,    54,    54,    54,    54,    54,
      53,    60,    59,    78,    84,    28,    17,    60,    78,    60,
      70,    85,    59,    54,     3,    68,    77,    86,    87,    60,
      87,    60,    28,    60,    87,    87,    87,    15,    16,    78,
      21,    85,    54,     4,    70,    60,    54,    59,    60,    54,
      28,    59,    18,    87,    60,    78,    54,    60,     3,    16,
      87,    59,    70,    33,    54,    19,    60,    54,     4,    54,
      87,    59,    19,    60,    54,    70,    54
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
      80,    80,    80,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    83,    83,    84,    84,    84,    84,    84,    85,
      85,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    89,    89,    90,    91,    91,    92,    93,
      94,    95,    96,    96,    97,    97,    97,    97,    98,    98
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
       5,     4,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     9,    11,     0,     3,     5,     5,     7,     0,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     0,     2,     2,     2,     4,     4,     4,
       4,     4,     4,     8,    11,     8,    12,    14,    12,    16,
       2,     2,     2,     3,     3,     4,     5,     6,     1,     3
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
#line 221 "myparser.y"
                             { 
        if (yyerror_count == 0) {
            printf("Expression evaluates to:\n");
            printf("************************\n");
            puts(c_prologue);
            printf("\n\n%s\n%s\n", (yyvsp[-1].str), (yyvsp[0].str));
            printf("************************\n");
        }  
    }
#line 1554 "myparser.tab.c"
    break;

  case 4: /* input: main_func  */
#line 231 "myparser.y"
                { 
        if (yyerror_count == 0) {
            printf("Expression evaluates to:\n");
            printf("************************\n");
            puts(c_prologue);
            printf("\n\n%s\n", (yyvsp[0].str));
            printf("************************\n"); 
        }  
    }
#line 1568 "myparser.tab.c"
    break;

  case 5: /* declarations: declarations declaration  */
#line 243 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1574 "myparser.tab.c"
    break;

  case 6: /* declarations: declaration  */
#line 244 "myparser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1580 "myparser.tab.c"
    break;

  case 7: /* declaration: variable_declaration  */
#line 248 "myparser.y"
                       { (yyval.str) = (yyvsp[0].str); }
#line 1586 "myparser.tab.c"
    break;

  case 8: /* declaration: comp  */
#line 249 "myparser.y"
         { (yyval.str) = (yyvsp[0].str); }
#line 1592 "myparser.tab.c"
    break;

  case 9: /* declaration: const  */
#line 250 "myparser.y"
          { (yyval.str) = (yyvsp[0].str); }
#line 1598 "myparser.tab.c"
    break;

  case 10: /* declaration: function  */
#line 251 "myparser.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1604 "myparser.tab.c"
    break;

  case 11: /* main_func: KW_DEF KW_MAIN DEL_LPAR DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 256 "myparser.y"
                                                                               { (yyval.str) = template("int main () {\n%s\n}", (yyvsp[-2].str)); }
#line 1610 "myparser.tab.c"
    break;

  case 12: /* variable_declaration: identifier DEL_COLON types DEL_SMCOLON  */
#line 264 "myparser.y"
   {
    // if its a basic data type then declare it as normal : i.e int x;
    if (is_basic_data_type((yyvsp[-1].str))) 
      (yyval.str) = template("%s %s;", (yyvsp[-1].str), (yyvsp[-3].str));
    //if it is a complex type declare it as: i.e Coordinates x = ctor_Coordinates ;
    else{ 
      char* token = strtok((yyvsp[-3].str), ", ");
      char* final_str = strdup("");
      int first = 1;

      while (token != NULL) {
        char* new_str = template("%s = ctor_%s", token, (yyvsp[-1].str));

        if (first) {
            first = 0;
            final_str = template("%s%s", final_str, new_str);
        } else {
            final_str = template("%s, %s", final_str, new_str);
        }

        free(new_str);
        token = strtok(NULL, ", ");
      }

      char* final_result = template("%s %s;",(yyvsp[-1].str), final_str );
      free(final_str);
      (yyval.str) = final_result;
    }
   }
#line 1644 "myparser.tab.c"
    break;

  case 13: /* basic_data_type: KW_INT  */
#line 296 "myparser.y"
             { (yyval.str) = template("%s", "int"); }
#line 1650 "myparser.tab.c"
    break;

  case 14: /* basic_data_type: KW_SCALAR  */
#line 297 "myparser.y"
                { (yyval.str) = template("%s", "double"); }
#line 1656 "myparser.tab.c"
    break;

  case 15: /* basic_data_type: KW_STR  */
#line 298 "myparser.y"
             { (yyval.str) = template("%s", "StringType"); }
#line 1662 "myparser.tab.c"
    break;

  case 16: /* basic_data_type: KW_BOOLEAN  */
#line 299 "myparser.y"
                 { (yyval.str) = template("%s", "int"); }
#line 1668 "myparser.tab.c"
    break;

  case 20: /* identifier: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET  */
#line 309 "myparser.y"
                                              {(yyval.str) = template("*%s", (yyvsp[-2].str));}
#line 1674 "myparser.tab.c"
    break;

  case 21: /* identifier: identifier DEL_COMMA TK_IDENTIFIER  */
#line 310 "myparser.y"
                                          { (yyval.str) = template("%s, %s" , (yyvsp[-2].str) , (yyvsp[0].str)); }
#line 1680 "myparser.tab.c"
    break;

  case 22: /* identifier: identifier DEL_COMMA TK_IDENTIFIER DEL_LBRACKET expr DEL_RBRACKET  */
#line 311 "myparser.y"
                                                                         { (yyval.str) = template("%s, %s[%s]" , (yyvsp[-5].str) , (yyvsp[-3].str) , (yyvsp[-1].str)); }
#line 1686 "myparser.tab.c"
    break;

  case 23: /* identifier: identifier DEL_COMMA TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET  */
#line 312 "myparser.y"
                                                                    { (yyval.str) = template("%s, *%s" , (yyvsp[-4].str) , (yyvsp[-2].str) ); }
#line 1692 "myparser.tab.c"
    break;

  case 24: /* comp: KW_COMP TK_IDENTIFIER DEL_COLON comp_body KW_ENDCOMP DEL_SMCOLON  */
#line 320 "myparser.y"
    {
       (yyval.str) = template("\n#define SELF struct %s *self\n\ntypedef struct %s {\n%s\n} %s;\n%s\nconst %s ctor_%s = { %s  %s%s };\n#undef SELF\n", (yyvsp[-4].str), (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-4].str) ,( all_funcs ? all_funcs : "" ), (yyvsp[-4].str) , (yyvsp[-4].str) , (all_funcs_names ? all_funcs_names : "" ) ,(all_comp_object_members ? ", " : "") , (all_comp_object_members ? all_comp_object_members : "")); 
    
       // reset the all_funcs string , to get new funcs on the next comp and dont rewrite the old ones.
       free(all_funcs);
       free(all_funcs_names);
       free(all_comp_object_members);
       all_funcs = NULL;
       all_funcs_names = NULL;
       all_comp_object_members = NULL;
       
    }
#line 1709 "myparser.tab.c"
    break;

  case 25: /* comp_body: comp_field  */
#line 336 "myparser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1715 "myparser.tab.c"
    break;

  case 26: /* comp_body: comp_field comp_body  */
#line 337 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 1721 "myparser.tab.c"
    break;

  case 27: /* comp_field: comp_identifiers DEL_COLON types DEL_SMCOLON  */
#line 343 "myparser.y"
    { 
        (yyval.str) = template("%s %s;", (yyvsp[-1].str), (yyvsp[-3].str)); 

        /* Now if it is an object and not a basic data type, we need to add it in the constructor, to initialize it: */
        if (!is_basic_data_type((yyvsp[-1].str))) {
            char *object_name;
            char *identifier_copy = strdup((yyvsp[-3].str)); // Create a copy to modify
            char *bracket_pos = strchr(identifier_copy, '['); // Find the bracket position

            if (bracket_pos != NULL) {  // Check if the identifier is an array
                char *size_str = strdup(bracket_pos + 1); // Copy the size part
                char *end_bracket_pos = strchr(size_str, ']'); // Find the closing bracket
                if (end_bracket_pos != NULL) {
                    *end_bracket_pos = '\0'; // Truncate to get only the size
                }
                *bracket_pos = '\0'; // Truncate the identifier to remove the size
                // Create the initializer for the array
                object_name = template(".%s = {[0 ... %s - 1] = ctor_%s}", identifier_copy, size_str, (yyvsp[-1].str));
                free(size_str); // Free the allocated memory for size_str
            } else {
                // Create the initializer for a regular member
                object_name = template(".%s = ctor_%s", (yyvsp[-3].str), (yyvsp[-1].str));
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
#line 1770 "myparser.tab.c"
    break;

  case 28: /* comp_field: comp_function  */
#line 387 "myparser.y"
                    { (yyval.str) = template("%s", (yyvsp[0].str)); }
#line 1776 "myparser.tab.c"
    break;

  case 29: /* comp_identifiers: HASH TK_IDENTIFIER  */
#line 392 "myparser.y"
                         { (yyval.str) = (yyvsp[0].str); }
#line 1782 "myparser.tab.c"
    break;

  case 30: /* comp_identifiers: HASH TK_IDENTIFIER DEL_LBRACKET expr DEL_RBRACKET  */
#line 393 "myparser.y"
                                                        {(yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str));}
#line 1788 "myparser.tab.c"
    break;

  case 31: /* comp_identifiers: HASH TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET  */
#line 394 "myparser.y"
                                                   {(yyval.str) = template("*%s", (yyvsp[-2].str));}
#line 1794 "myparser.tab.c"
    break;

  case 32: /* comp_identifiers: comp_identifiers DEL_COMMA HASH TK_IDENTIFIER  */
#line 395 "myparser.y"
                                                    { (yyval.str) = template("%s, %s" , (yyvsp[-3].str) , (yyvsp[0].str)); }
#line 1800 "myparser.tab.c"
    break;

  case 33: /* comp_identifiers: comp_identifiers DEL_COMMA HASH TK_IDENTIFIER DEL_LBRACKET expr DEL_RBRACKET  */
#line 396 "myparser.y"
                                                                                   { (yyval.str) = template("%s, %s[%s]" , (yyvsp[-6].str) , (yyvsp[-3].str) , (yyvsp[-1].str)); }
#line 1806 "myparser.tab.c"
    break;

  case 34: /* comp_identifiers: comp_identifiers DEL_COMMA HASH TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET  */
#line 397 "myparser.y"
                                                                              { (yyval.str) = template("%s, *%s" , (yyvsp[-5].str) , (yyvsp[-2].str) ); }
#line 1812 "myparser.tab.c"
    break;

  case 35: /* comp_function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 403 "myparser.y"
    {
      char *func_declaration = template("void (*%s)(SELF %s%s)", (yyvsp[-7].str), ( ((yyvsp[-5].str)[0] != '\0') ? ", " : "" ) , (yyvsp[-5].str));
      
      char * func = template("void %s(SELF %s%s) {\n%s\n}\n", (yyvsp[-7].str), ( ((yyvsp[-5].str)[0] != '\0') ? ", " : "" ),(yyvsp[-5].str), (yyvsp[-2].str));

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
      char* func_name = template(".%s=%s" , (yyvsp[-7].str) , (yyvsp[-7].str));
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

      (yyval.str) = template("%s;\n", func_declaration);
      
    }
#line 1852 "myparser.tab.c"
    break;

  case 36: /* comp_function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW types DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 440 "myparser.y"
    {
      char *func_declaration = template("%s (*%s)(SELF %s%s)", (yyvsp[-4].str), (yyvsp[-9].str), ((yyvsp[-7].str)[0] != '\0') ? ", " : "", (yyvsp[-7].str));

      char *func = template("%s %s(SELF %s%s) {\n%s\n}\n", (yyvsp[-4].str), (yyvsp[-9].str), ( ((yyvsp[-7].str)[0] != '\0') ? ", " : "" ), (yyvsp[-7].str), (yyvsp[-2].str));
      
      
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
      char* func_name = template(".%s=%s" , (yyvsp[-9].str) , (yyvsp[-9].str));
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

      (yyval.str) = template("%s;\n", func_declaration);
    }
#line 1892 "myparser.tab.c"
    break;

  case 37: /* const: KW_CONST identifier AOP_ASSIGN expr DEL_COLON basic_data_type DEL_SMCOLON  */
#line 480 "myparser.y"
                                                                              { (yyval.str) = template("const %s %s = %s;", (yyvsp[-1].str), (yyvsp[-5].str), (yyvsp[-3].str)); }
#line 1898 "myparser.tab.c"
    break;

  case 38: /* expr: identifier_expr  */
#line 486 "myparser.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1904 "myparser.tab.c"
    break;

  case 39: /* expr: TK_STRING  */
#line 487 "myparser.y"
                { (yyval.str) = (yyvsp[0].str); }
#line 1910 "myparser.tab.c"
    break;

  case 40: /* expr: KW_TRUE  */
#line 488 "myparser.y"
              {(yyval.str) = template("1");}
#line 1916 "myparser.tab.c"
    break;

  case 41: /* expr: KW_FALSE  */
#line 489 "myparser.y"
               {(yyval.str) = template("0");}
#line 1922 "myparser.tab.c"
    break;

  case 42: /* expr: DEL_LPAR expr DEL_RPAR  */
#line 490 "myparser.y"
                             { (yyval.str) = template("(%s)", (yyvsp[-1].str)); }
#line 1928 "myparser.tab.c"
    break;

  case 43: /* expr: arithmetic_expr  */
#line 491 "myparser.y"
                      {(yyval.str) = (yyvsp[0].str);}
#line 1934 "myparser.tab.c"
    break;

  case 44: /* expr: relational_expr  */
#line 492 "myparser.y"
                      {(yyval.str) = (yyvsp[0].str);}
#line 1940 "myparser.tab.c"
    break;

  case 45: /* expr: logical_statements  */
#line 493 "myparser.y"
                         {(yyval.str) = (yyvsp[0].str);}
#line 1946 "myparser.tab.c"
    break;

  case 46: /* expr: function_statement  */
#line 494 "myparser.y"
                         {(yyval.str) = (yyvsp[0].str);}
#line 1952 "myparser.tab.c"
    break;

  case 47: /* arithmetic_expr: TK_INTEGER  */
#line 499 "myparser.y"
               {(yyval.str) = (yyvsp[0].str);}
#line 1958 "myparser.tab.c"
    break;

  case 48: /* arithmetic_expr: TK_REAL  */
#line 500 "myparser.y"
              {(yyval.str) = (yyvsp[0].str);}
#line 1964 "myparser.tab.c"
    break;

  case 49: /* arithmetic_expr: expr OP_POWER expr  */
#line 501 "myparser.y"
                         {(yyval.str) = template("pow(%s, %s)", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1970 "myparser.tab.c"
    break;

  case 50: /* arithmetic_expr: expr OP_MULT expr  */
#line 502 "myparser.y"
                        {(yyval.str) = template("%s * %s",(yyvsp[-2].str), (yyvsp[0].str));}
#line 1976 "myparser.tab.c"
    break;

  case 51: /* arithmetic_expr: expr OP_DIV expr  */
#line 503 "myparser.y"
                       {(yyval.str) = template("%s / %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1982 "myparser.tab.c"
    break;

  case 52: /* arithmetic_expr: expr OP_MOD expr  */
#line 504 "myparser.y"
                       {(yyval.str) = template("%s %% %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1988 "myparser.tab.c"
    break;

  case 53: /* arithmetic_expr: expr OP_PLUS expr  */
#line 505 "myparser.y"
                        {(yyval.str) = template("%s + %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 1994 "myparser.tab.c"
    break;

  case 54: /* arithmetic_expr: expr OP_MINUS expr  */
#line 506 "myparser.y"
                         {(yyval.str) = template("%s - %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2000 "myparser.tab.c"
    break;

  case 55: /* arithmetic_expr: OP_PLUS expr  */
#line 507 "myparser.y"
                   {(yyval.str) = template("+%s", (yyvsp[0].str));}
#line 2006 "myparser.tab.c"
    break;

  case 56: /* arithmetic_expr: OP_MINUS expr  */
#line 508 "myparser.y"
                    {(yyval.str) = template("-%s", (yyvsp[0].str));}
#line 2012 "myparser.tab.c"
    break;

  case 57: /* identifier_expr: TK_IDENTIFIER  */
#line 513 "myparser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 2018 "myparser.tab.c"
    break;

  case 58: /* identifier_expr: HASH TK_IDENTIFIER  */
#line 514 "myparser.y"
                       { {(yyval.str) = template("#%s", (yyvsp[0].str));} }
#line 2024 "myparser.tab.c"
    break;

  case 59: /* identifier_expr: TK_IDENTIFIER DEL_LBRACKET expr DEL_RBRACKET  */
#line 515 "myparser.y"
                                                 { (yyval.str) = template("%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2030 "myparser.tab.c"
    break;

  case 60: /* identifier_expr: HASH TK_IDENTIFIER DEL_LBRACKET expr DEL_RBRACKET  */
#line 516 "myparser.y"
                                                      { (yyval.str) = template("#%s[%s]", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2036 "myparser.tab.c"
    break;

  case 61: /* identifier_expr: identifier_expr DEL_DOT HASH TK_IDENTIFIER  */
#line 517 "myparser.y"
                                               {(yyval.str) = template("%s.%s" , (yyvsp[-3].str) , (yyvsp[0].str) ); }
#line 2042 "myparser.tab.c"
    break;

  case 62: /* identifier_expr: identifier_expr DEL_DOT TK_IDENTIFIER  */
#line 518 "myparser.y"
                                          {(yyval.str) = template("%s.%s" , (yyvsp[-2].str) , (yyvsp[0].str) ); }
#line 2048 "myparser.tab.c"
    break;

  case 63: /* relational_expr: expr ROP_LESS expr  */
#line 522 "myparser.y"
                     {(yyval.str) = template("%s < %s",(yyvsp[-2].str), (yyvsp[0].str));}
#line 2054 "myparser.tab.c"
    break;

  case 64: /* relational_expr: expr ROP_LESSEQUALS expr  */
#line 523 "myparser.y"
                             {(yyval.str) = template("%s <= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2060 "myparser.tab.c"
    break;

  case 65: /* relational_expr: expr ROP_GREATER expr  */
#line 524 "myparser.y"
                          {(yyval.str) = template("%s > %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2066 "myparser.tab.c"
    break;

  case 66: /* relational_expr: expr ROP_GREATEREQUALS expr  */
#line 525 "myparser.y"
                                {(yyval.str) = template("%s >= %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2072 "myparser.tab.c"
    break;

  case 67: /* relational_expr: expr ROP_EQUALS expr  */
#line 526 "myparser.y"
                         {(yyval.str) = template("%s == %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2078 "myparser.tab.c"
    break;

  case 68: /* relational_expr: expr ROP_NOTEQUALS expr  */
#line 527 "myparser.y"
                            {(yyval.str) = template("%s != %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2084 "myparser.tab.c"
    break;

  case 69: /* logical_statements: KW_NOT expr  */
#line 531 "myparser.y"
                {(yyval.str) = template("! %s", (yyvsp[0].str));}
#line 2090 "myparser.tab.c"
    break;

  case 70: /* logical_statements: expr KW_AND expr  */
#line 532 "myparser.y"
                       {(yyval.str) = template("%s && %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2096 "myparser.tab.c"
    break;

  case 71: /* logical_statements: expr KW_OR expr  */
#line 533 "myparser.y"
                      {(yyval.str) = template("%s || %s", (yyvsp[-2].str), (yyvsp[0].str));}
#line 2102 "myparser.tab.c"
    break;

  case 72: /* function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 539 "myparser.y"
                                                                                                                                                        {(yyval.str) = template("\nvoid %s(%s) {\n%s\n}\n", (yyvsp[-7].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2108 "myparser.tab.c"
    break;

  case 73: /* function: KW_DEF TK_IDENTIFIER DEL_LPAR params DEL_RPAR AOP_ARROW types DEL_COLON func_body KW_ENDDEF DEL_SMCOLON  */
#line 540 "myparser.y"
                                                                                                                {(yyval.str) = template("\n%s %s(%s) {\n%s\n\n}\n", (yyvsp[-4].str), (yyvsp[-9].str), (yyvsp[-7].str), (yyvsp[-2].str));}
#line 2114 "myparser.tab.c"
    break;

  case 74: /* params: %empty  */
#line 545 "myparser.y"
         { (yyval.str) = "" ;}
#line 2120 "myparser.tab.c"
    break;

  case 75: /* params: TK_IDENTIFIER DEL_COLON types  */
#line 546 "myparser.y"
                                  {(yyval.str) = template("%s %s", (yyvsp[0].str), (yyvsp[-2].str));}
#line 2126 "myparser.tab.c"
    break;

  case 76: /* params: TK_IDENTIFIER DEL_COLON types DEL_COMMA params  */
#line 547 "myparser.y"
                                                   {(yyval.str) = template("%s %s, %s", (yyvsp[-2].str), (yyvsp[-4].str), (yyvsp[0].str));}
#line 2132 "myparser.tab.c"
    break;

  case 77: /* params: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON types  */
#line 548 "myparser.y"
                                                            {(yyval.str) = template("%s *%s", (yyvsp[0].str), (yyvsp[-4].str));}
#line 2138 "myparser.tab.c"
    break;

  case 78: /* params: TK_IDENTIFIER DEL_LBRACKET DEL_RBRACKET DEL_COLON types DEL_COMMA params  */
#line 549 "myparser.y"
                                                                            {(yyval.str) = template("%s *%s, %s", (yyvsp[-2].str), (yyvsp[-6].str), (yyvsp[0].str));}
#line 2144 "myparser.tab.c"
    break;

  case 79: /* func_body: %empty  */
#line 553 "myparser.y"
             { (yyval.str) = strdup(""); }
#line 2150 "myparser.tab.c"
    break;

  case 80: /* func_body: variable_declaration func_body  */
#line 554 "myparser.y"
                                     { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2156 "myparser.tab.c"
    break;

  case 81: /* func_body: const func_body  */
#line 555 "myparser.y"
                      { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2162 "myparser.tab.c"
    break;

  case 82: /* func_body: statements func_body  */
#line 556 "myparser.y"
                           { (yyval.str) = template("%s\n%s", (yyvsp[-1].str), (yyvsp[0].str)); }
#line 2168 "myparser.tab.c"
    break;

  case 92: /* statements: function_statement DEL_SMCOLON  */
#line 574 "myparser.y"
                                    { (yyval.str) = template("%s;", (yyvsp[-1].str)); }
#line 2174 "myparser.tab.c"
    break;

  case 93: /* statement_body: %empty  */
#line 578 "myparser.y"
               { (yyval.str) = "" ;}
#line 2180 "myparser.tab.c"
    break;

  case 94: /* statement_body: variable_declaration statement_body  */
#line 579 "myparser.y"
                                              {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 2186 "myparser.tab.c"
    break;

  case 95: /* statement_body: const statement_body  */
#line 580 "myparser.y"
                          {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 2192 "myparser.tab.c"
    break;

  case 96: /* statement_body: statements statement_body  */
#line 581 "myparser.y"
                                    {(yyval.str) = template("%s\n%s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 2198 "myparser.tab.c"
    break;

  case 97: /* assign_statement: identifier_expr AOP_ASSIGN expr DEL_SMCOLON  */
#line 586 "myparser.y"
                                                          { (yyval.str) = template("%s = %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2204 "myparser.tab.c"
    break;

  case 98: /* assign_statement: identifier_expr AOP_PLUSASSIGN expr DEL_SMCOLON  */
#line 587 "myparser.y"
                                                          { (yyval.str) = template("%s += %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2210 "myparser.tab.c"
    break;

  case 99: /* assign_statement: identifier_expr AOP_MINASSIGN expr DEL_SMCOLON  */
#line 588 "myparser.y"
                                                          { (yyval.str) = template("%s -= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2216 "myparser.tab.c"
    break;

  case 100: /* assign_statement: identifier_expr AOP_MULASSIGN expr DEL_SMCOLON  */
#line 589 "myparser.y"
                                                          { (yyval.str) = template("%s *= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2222 "myparser.tab.c"
    break;

  case 101: /* assign_statement: identifier_expr AOP_DIVASSIGN expr DEL_SMCOLON  */
#line 590 "myparser.y"
                                                          { (yyval.str) = template("%s /= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2228 "myparser.tab.c"
    break;

  case 102: /* assign_statement: identifier_expr AOP_MODASSIGN expr DEL_SMCOLON  */
#line 591 "myparser.y"
                                                          { (yyval.str) = template("%s %%= %s;", (yyvsp[-3].str), (yyvsp[-1].str)); }
#line 2234 "myparser.tab.c"
    break;

  case 103: /* if_statement: KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDIF DEL_SMCOLON  */
#line 596 "myparser.y"
                                                                                     {(yyval.str) = template("if (%s) {\n%s\n}", (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2240 "myparser.tab.c"
    break;

  case 104: /* if_statement: KW_IF DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ELSE DEL_COLON statement_body KW_ENDIF DEL_SMCOLON  */
#line 597 "myparser.y"
                                                                                                                      {(yyval.str) = template("if (%s) {\n%s\n} else {\n%s\n}", (yyvsp[-8].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2246 "myparser.tab.c"
    break;

  case 105: /* while_statement: KW_WHILE DEL_LPAR expr DEL_RPAR DEL_COLON statement_body KW_ENDWHILE DEL_SMCOLON  */
#line 602 "myparser.y"
                                                                                           { (yyval.str) = template("while (%s){\n%s\n}\n", (yyvsp[-5].str), (yyvsp[-2].str)); }
#line 2252 "myparser.tab.c"
    break;

  case 106: /* for_statement: KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON  */
#line 606 "myparser.y"
                                                                                                                                  {(yyval.str) = template("for (int %s = %s; %s < %s; %s++) {\n%s\n}", (yyvsp[-10].str), (yyvsp[-7].str), (yyvsp[-10].str), (yyvsp[-5].str), (yyvsp[-10].str), (yyvsp[-2].str));}
#line 2258 "myparser.tab.c"
    break;

  case 107: /* for_statement: KW_FOR TK_IDENTIFIER KW_IN DEL_LBRACKET expr DEL_COLON expr DEL_COLON expr DEL_RBRACKET DEL_COLON statement_body KW_ENDFOR DEL_SMCOLON  */
#line 607 "myparser.y"
                                                                                                                                                   {(yyval.str) = template("for (int %s = %s; %s < %s; %s = %s + %s) 		{\n%s\n}", (yyvsp[-12].str), (yyvsp[-9].str), (yyvsp[-12].str), (yyvsp[-7].str), (yyvsp[-12].str), (yyvsp[-12].str), (yyvsp[-5].str), (yyvsp[-2].str));}
#line 2264 "myparser.tab.c"
    break;

  case 108: /* array_int_comprehension: TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 611 "myparser.y"
                                                                                                                                     {(yyval.str) = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(%s %s = 0; %s < %s; ++%s) {\n %s[%s] = %s;\n}", (yyvsp[-1].str), (yyvsp[-11].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-11].str), (yyvsp[-6].str), (yyvsp[-8].str));}
#line 2270 "myparser.tab.c"
    break;

  case 109: /* array_comprehension: TK_IDENTIFIER AOP_COLONASSIGN DEL_LBRACKET expr KW_FOR TK_IDENTIFIER DEL_COLON types KW_IN TK_IDENTIFIER KW_OF TK_INTEGER DEL_RBRACKET DEL_COLON types DEL_SMCOLON  */
#line 617 "myparser.y"
        {
	char* replaced_expr = replace_str((yyvsp[-12].str), (yyvsp[-10].str), template("%s[%s_i]", (yyvsp[-6].str), (yyvsp[-6].str)));
	(yyval.str) = template("%s* %s = (%s*)malloc(%s*sizeof(%s));\nfor(int %s_i = 0; %s_i < %s; ++%s_i) {\n\t%s[%s_i] = %s;\n}", (yyvsp[-1].str), (yyvsp[-15].str), (yyvsp[-1].str), (yyvsp[-4].str), (yyvsp[-1].str), (yyvsp[-6].str), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-6].str), (yyvsp[-15].str), (yyvsp[-6].str), replaced_expr);
	}
#line 2279 "myparser.tab.c"
    break;

  case 110: /* break_statement: KW_BREAK DEL_SMCOLON  */
#line 624 "myparser.y"
                       {(yyval.str) = template("break;");}
#line 2285 "myparser.tab.c"
    break;

  case 111: /* continue_statement: KW_CONTINUE DEL_SMCOLON  */
#line 628 "myparser.y"
                          {(yyval.str) = template("continue;");}
#line 2291 "myparser.tab.c"
    break;

  case 112: /* return_statement: KW_RETURN DEL_SMCOLON  */
#line 632 "myparser.y"
                       {(yyval.str) = template("return;");}
#line 2297 "myparser.tab.c"
    break;

  case 113: /* return_statement: KW_RETURN expr DEL_SMCOLON  */
#line 633 "myparser.y"
                              {(yyval.str) = template("return %s;", (yyvsp[-1].str));}
#line 2303 "myparser.tab.c"
    break;

  case 114: /* function_statement: TK_IDENTIFIER DEL_LPAR DEL_RPAR  */
#line 638 "myparser.y"
                                  {(yyval.str) = template("%s()", (yyvsp[-2].str));}
#line 2309 "myparser.tab.c"
    break;

  case 115: /* function_statement: TK_IDENTIFIER DEL_LPAR function_arguments DEL_RPAR  */
#line 639 "myparser.y"
                                                       {(yyval.str) = template("%s(%s)", (yyvsp[-3].str),(yyvsp[-1].str));}
#line 2315 "myparser.tab.c"
    break;

  case 116: /* function_statement: identifier_expr DEL_DOT TK_IDENTIFIER DEL_LPAR DEL_RPAR  */
#line 640 "myparser.y"
                                                            {(yyval.str) = template("%s.%s(&%s)" , (yyvsp[-4].str) , (yyvsp[-2].str) ,(yyvsp[-4].str)); }
#line 2321 "myparser.tab.c"
    break;

  case 117: /* function_statement: identifier_expr DEL_DOT TK_IDENTIFIER DEL_LPAR function_arguments DEL_RPAR  */
#line 641 "myparser.y"
                                                                               {(yyval.str) = template("%s.%s(&%s,%s)" , (yyvsp[-5].str) , (yyvsp[-3].str) ,(yyvsp[-5].str), (yyvsp[-1].str)); }
#line 2327 "myparser.tab.c"
    break;

  case 118: /* function_arguments: expr  */
#line 645 "myparser.y"
       { (yyval.str) = template("%s", (yyvsp[0].str));}
#line 2333 "myparser.tab.c"
    break;

  case 119: /* function_arguments: expr DEL_COMMA function_arguments  */
#line 646 "myparser.y"
                                      { (yyval.str) = template("%s, %s", (yyvsp[-2].str), (yyvsp[0].str)); }
#line 2339 "myparser.tab.c"
    break;


#line 2343 "myparser.tab.c"

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

#line 651 "myparser.y"

/******************************************* CODE SECTION *******************************************/

int main () {
    if ( yyparse() == 0 )
        printf( GREEN "Your program is syntactically correct!\n" RESET);
    else
        printf(RED "Rejected!\n" RESET);
}

