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
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
typedef struct
{
	char * name;
	uint8_t initialized;
}symbol;
symbol ** symbol_table;
uint8_t symbol_count=0;

char ** function_table;
uint8_t function_count=0;

void add_symbol(char *);
void update_symbol(char *);
void add_function(char *);
int find_symbol(char *);
int find_function(char *);
char * fn_name;
char * var_name;

int yylex();
void yyerror(const char *);

extern char* symbol_name;
extern int lineno;

#line 102 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAIN = 3,                       /* MAIN  */
  YYSYMBOL_LPAREN = 4,                     /* LPAREN  */
  YYSYMBOL_RPAREN = 5,                     /* RPAREN  */
  YYSYMBOL_LBRACE = 6,                     /* LBRACE  */
  YYSYMBOL_RBRACE = 7,                     /* RBRACE  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_EQUAL = 9,                      /* EQUAL  */
  YYSYMBOL_SEMICOLON = 10,                 /* SEMICOLON  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_FLOAT = 19,                     /* FLOAT  */
  YYSYMBOL_CHAR = 20,                      /* CHAR  */
  YYSYMBOL_VOID = 21,                      /* VOID  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MINUS = 23,                     /* MINUS  */
  YYSYMBOL_MUL = 24,                       /* MUL  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_PERCENT = 26,                   /* PERCENT  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_LESS = 30,                      /* LESS  */
  YYSYMBOL_GREAT = 31,                     /* GREAT  */
  YYSYMBOL_COMPLEMENT = 32,                /* COMPLEMENT  */
  YYSYMBOL_NUM = 33,                       /* NUM  */
  YYSYMBOL_EQUAL_EQUAL = 34,               /* EQUAL_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 35,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 36,                /* LESS_EQUAL  */
  YYSYMBOL_GREAT_EQUAL = 37,               /* GREAT_EQUAL  */
  YYSYMBOL_PLUS_PLUS = 38,                 /* PLUS_PLUS  */
  YYSYMBOL_MINUS_MINUS = 39,               /* MINUS_MINUS  */
  YYSYMBOL_PLUS_EQUAL = 40,                /* PLUS_EQUAL  */
  YYSYMBOL_MINUS_EQUAL = 41,               /* MINUS_EQUAL  */
  YYSYMBOL_MUL_EQUAL = 42,                 /* MUL_EQUAL  */
  YYSYMBOL_DIV_EQUAL = 43,                 /* DIV_EQUAL  */
  YYSYMBOL_PERCENT_EQUAL = 44,             /* PERCENT_EQUAL  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_mainfunction = 47,              /* mainfunction  */
  YYSYMBOL_codes = 48,                     /* codes  */
  YYSYMBOL_code = 49,                      /* code  */
  YYSYMBOL_declarative = 50,               /* declarative  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_assignment = 52,                /* assignment  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_conditional = 54,               /* conditional  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_conditional1 = 56,              /* conditional1  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_conditional2 = 58,              /* conditional2  */
  YYSYMBOL_condition = 59,                 /* condition  */
  YYSYMBOL_iterative = 60,                 /* iterative  */
  YYSYMBOL_initialize = 61,                /* initialize  */
  YYSYMBOL_terminate = 62,                 /* terminate  */
  YYSYMBOL_update = 63,                    /* update  */
  YYSYMBOL_function_call = 64,             /* function_call  */
  YYSYMBOL_65_5 = 65,                      /* $@5  */
  YYSYMBOL_parameters = 66,                /* parameters  */
  YYSYMBOL_value = 67,                     /* value  */
  YYSYMBOL_return = 68,                    /* return  */
  YYSYMBOL_69_6 = 69,                      /* $@6  */
  YYSYMBOL_functions = 70,                 /* functions  */
  YYSYMBOL_function = 71,                  /* function  */
  YYSYMBOL_72_7 = 72,                      /* $@7  */
  YYSYMBOL_signature = 73,                 /* signature  */
  YYSYMBOL_type = 74,                      /* type  */
  YYSYMBOL_expr = 75,                      /* expr  */
  YYSYMBOL_76_8 = 76,                      /* $@8  */
  YYSYMBOL_77_9 = 77,                      /* $@9  */
  YYSYMBOL_78_10 = 78,                     /* $@10  */
  YYSYMBOL_79_11 = 79,                     /* $@11  */
  YYSYMBOL_80_12 = 80,                     /* $@12  */
  YYSYMBOL_81_13 = 81,                     /* $@13  */
  YYSYMBOL_expr1 = 82,                     /* expr1  */
  YYSYMBOL_L1 = 83,                        /* L1  */
  YYSYMBOL_Q = 84,                         /* Q  */
  YYSYMBOL_Q1 = 85,                        /* Q1  */
  YYSYMBOL_R = 86,                         /* R  */
  YYSYMBOL_R1 = 87,                        /* R1  */
  YYSYMBOL_E = 88,                         /* E  */
  YYSYMBOL_E1 = 89,                        /* E1  */
  YYSYMBOL_T = 90,                         /* T  */
  YYSYMBOL_T1 = 91,                        /* T1  */
  YYSYMBOL_F = 92                          /* F  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  206

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    46,    51,    51,    52,    52,    52,    52,
      52,    52,    54,    66,    66,    80,    80,    93,    93,    95,
      95,    96,    98,    99,   101,   103,   105,   107,   110,   110,
     110,   112,   112,   114,   114,   116,   116,   128,   128,   128,
     129,   134,   136,   136,   141,   141,   143,   143,   145,   145,
     151,   151,   151,   153,   153,   153,   153,   155,   155,   162,
     162,   169,   169,   176,   176,   183,   183,   190,   190,   197,
     199,   201,   201,   201,   203,   205,   205,   205,   207,   209,
     209,   209,   209,   209,   211,   213,   213,   213,   215,   217,
     217,   217,   217,   219,   226,   227,   228,   229,   230,   231,
     232,   240,   248,   256
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
  "\"end of file\"", "error", "\"invalid token\"", "MAIN", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "ID", "EQUAL", "SEMICOLON", "IF", "ELSE",
  "WHILE", "FOR", "DO", "RETURN", "COMMA", "INT", "FLOAT", "CHAR", "VOID",
  "PLUS", "MINUS", "MUL", "DIV", "PERCENT", "AND", "OR", "NOT", "LESS",
  "GREAT", "COMPLEMENT", "NUM", "EQUAL_EQUAL", "NOT_EQUAL", "LESS_EQUAL",
  "GREAT_EQUAL", "PLUS_PLUS", "MINUS_MINUS", "PLUS_EQUAL", "MINUS_EQUAL",
  "MUL_EQUAL", "DIV_EQUAL", "PERCENT_EQUAL", "$accept", "program",
  "mainfunction", "codes", "code", "declarative", "$@1", "assignment",
  "$@2", "conditional", "$@3", "conditional1", "$@4", "conditional2",
  "condition", "iterative", "initialize", "terminate", "update",
  "function_call", "$@5", "parameters", "value", "return", "$@6",
  "functions", "function", "$@7", "signature", "type", "expr", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "expr1", "L1", "Q", "Q1", "R",
  "R1", "E", "E1", "T", "T1", "F", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      32,   -66,   -66,   -66,   -66,    13,    19,    32,    21,   -66,
      53,   -66,   -66,   -66,    55,    60,    77,    32,    76,    80,
      85,    84,   111,   111,   114,   119,     2,   120,    76,   -66,
     -66,   -66,   -66,   -66,   -66,   118,   122,   112,   121,   127,
      16,   132,   133,     7,    76,   -66,   -66,   130,   -66,   -66,
     131,    76,    32,    16,     1,    16,   -20,    16,    16,    16,
      16,   -66,   134,   135,   139,     5,    75,     0,    44,    79,
      76,    76,   -66,   -66,   -66,   -66,    36,   138,   136,   -66,
     -66,   140,   141,   -66,   137,   -66,   -66,   145,   142,   146,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   125,
     126,   -66,    16,    16,   -66,    16,    16,    16,    16,   -66,
      16,    16,   -66,    16,    16,    16,   -66,   148,   149,    38,
     143,   -66,   -66,   111,   -66,    16,   -66,   -66,   147,     1,
     -66,    16,    16,    75,    75,     0,     0,     0,     0,    44,
      44,    79,    79,    79,   -66,   -66,   151,   123,   117,   124,
     128,   144,    36,   152,   154,   -66,   -66,     5,     5,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     156,    16,    16,    16,    16,    16,    16,   164,   -66,   -66,
     -66,   -66,   -66,    35,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   155,    76,   111,    76,   163,   168,   169,   -66,
      76,   -66,   170,   -66,   156,   -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      47,    53,    54,    55,    56,     0,     0,    47,     0,     1,
       0,     2,    46,    48,     0,     0,     0,    52,     5,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     5,    42,    44,     0,     3,     4,
      13,     5,    52,     0,    39,     0,    93,     0,     0,     0,
       0,    94,     0,     0,     0,    73,    77,    83,    87,    92,
       5,     5,    15,    30,    28,    29,    32,     0,     0,    45,
      12,     0,     0,    50,     0,    40,    41,     0,    38,     0,
     102,   103,    96,    97,    98,    99,   100,   101,    24,     0,
       0,    70,     0,     0,    74,     0,     0,     0,     0,    78,
       0,     0,    84,     0,     0,     0,    88,     0,     0,    93,
       0,    31,    69,     0,    43,     0,    49,    16,     0,    39,
      95,     0,     0,    77,    77,    83,    83,    83,    83,    87,
      87,    92,    92,    92,    17,    25,     0,     0,     0,     0,
       0,     0,    34,     0,     0,    36,    37,    73,    73,    75,
      76,    79,    80,    81,    82,    85,    86,    89,    90,    91,
      23,     0,     0,     0,     0,     0,     0,     0,    33,    26,
      14,    71,    72,     0,    18,    21,    58,    60,    62,    64,
      66,    68,     0,     5,     0,     5,     0,     0,     0,    22,
       5,    27,     0,    19,    23,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   -28,   -66,   150,   -66,   153,   -66,   -66,
     -66,   -29,   -66,   -66,   -21,   -66,   -66,   -66,   -66,   -66,
     -66,    49,   -66,   -66,   -66,   172,   -66,   -66,   129,     4,
      28,   -66,   -66,   -66,   -66,   -66,   -66,   -39,   -46,   -18,
     -17,    17,   -65,    -7,   -16,    11,   -35,   -52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,    11,    27,    28,    29,    81,    30,    38,    31,
     170,   184,   204,   185,    41,    32,    76,   120,   177,    33,
      39,    87,    88,    34,    78,     6,     7,    15,    19,    35,
     121,   146,   147,   148,   149,   150,   151,   122,   101,    65,
     104,    66,   109,    67,   112,    68,   116,    69
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    64,    42,    89,     8,    92,    93,    94,    95,    85,
      45,     8,    46,     9,    84,    72,    77,    73,    90,    91,
      55,    20,    10,    82,    56,     1,     2,     3,     4,    13,
     105,   106,    99,   100,    86,    47,   107,   108,    57,    58,
      55,   193,   117,   118,   119,    59,   194,   -57,    60,    61,
       1,     2,     3,     4,    62,    63,    20,    14,    57,    58,
      16,   141,   142,   143,    17,    59,   110,   111,    60,    61,
     161,   162,   163,   164,    62,    63,    90,    91,   -59,   -61,
     -63,   -65,   -67,    18,    21,    36,   154,    22,   -35,    23,
      24,    25,    26,    37,     1,     2,     3,     4,   135,   136,
     137,   138,   153,   113,   114,   115,   167,   168,   169,   102,
     103,   181,   182,   157,   158,    40,   159,   160,    43,   133,
     134,   139,   140,   165,   166,    44,    50,    48,    51,    52,
      53,    54,   186,   187,   188,   189,   190,   191,    70,    71,
      79,    80,    96,    97,    98,   123,   124,   127,   126,   125,
     128,   130,   131,   152,   132,   144,   145,   155,   173,   129,
     171,   195,   179,   172,   180,   196,   174,   198,   183,   192,
     199,   175,   202,   197,   200,   205,   201,   203,   156,    12,
     178,    83,     0,     0,     0,     0,     0,     0,   176,     0,
       0,     0,     0,    74,     0,     0,    75
};

static const yytype_int16 yycheck[] =
{
      28,    40,    23,    55,     0,    57,    58,    59,    60,     8,
       8,     7,    10,     0,    53,     8,    44,    10,    38,    39,
       4,    17,     3,    51,     8,    18,    19,    20,    21,     8,
      30,    31,    27,    28,    33,    33,    36,    37,    22,    23,
       4,     6,    70,    71,     8,    29,    11,     9,    32,    33,
      18,    19,    20,    21,    38,    39,    52,     4,    22,    23,
       5,   113,   114,   115,     4,    29,    22,    23,    32,    33,
     135,   136,   137,   138,    38,    39,    38,    39,    40,    41,
      42,    43,    44,     6,     8,     5,   125,    11,     4,    13,
      14,    15,    16,     8,    18,    19,    20,    21,   105,   106,
     107,   108,   123,    24,    25,    26,   141,   142,   143,    34,
      35,   157,   158,   131,   132,     4,   133,   134,     4,   102,
     103,   110,   111,   139,   140,     6,     8,     7,     6,    17,
       9,     4,   171,   172,   173,   174,   175,   176,     6,     6,
      10,    10,     8,     8,     5,     7,    10,    10,     7,     9,
       5,     5,    27,    10,    28,     7,     7,    10,    41,    17,
       9,     6,    10,    40,    10,   193,    42,   195,    12,     5,
       7,    43,   200,   194,     6,   204,     7,     7,   129,     7,
     152,    52,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    43,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    18,    19,    20,    21,    46,    70,    71,    74,     0,
       3,    47,    70,     8,     4,    72,     5,     4,     6,    73,
      74,     8,    11,    13,    14,    15,    16,    48,    49,    50,
      52,    54,    60,    64,    68,    74,     5,     8,    53,    65,
       4,    59,    59,     4,     6,     8,    10,    33,     7,    48,
       8,     6,    17,     9,     4,     4,     8,    22,    23,    29,
      32,    33,    38,    39,    82,    84,    86,    88,    90,    92,
       6,     6,     8,    10,    50,    52,    61,    48,    69,    10,
      10,    51,    48,    73,    82,     8,    33,    66,    67,    92,
      38,    39,    92,    92,    92,    92,     8,     8,     5,    27,
      28,    83,    34,    35,    85,    30,    31,    36,    37,    87,
      22,    23,    89,    24,    25,    26,    91,    48,    48,     8,
      62,    75,    82,     7,    10,     9,     7,    10,     5,    17,
       5,    27,    28,    86,    86,    88,    88,    88,    88,    90,
      90,    92,    92,    92,     7,     7,    76,    77,    78,    79,
      80,    81,    10,    59,    82,    10,    66,    84,    84,    85,
      85,    87,    87,    87,    87,    89,    89,    91,    91,    91,
      55,     9,    40,    41,    42,    43,    44,    63,    75,    10,
      10,    83,    83,    12,    56,    58,    82,    82,    82,    82,
      82,    82,     5,     6,    11,     6,    48,    59,    48,     7,
       6,     7,    48,     7,    57,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    49,    49,    49,    49,
      49,    49,    50,    51,    50,    53,    52,    55,    54,    57,
      56,    56,    58,    58,    59,    60,    60,    60,    61,    61,
      61,    62,    62,    63,    63,    65,    64,    66,    66,    66,
      67,    67,    69,    68,    68,    68,    70,    70,    72,    71,
      73,    73,    73,    74,    74,    74,    74,    76,    75,    77,
      75,    78,    75,    79,    75,    80,    75,    81,    75,    75,
      82,    83,    83,    83,    84,    85,    85,    85,    86,    87,
      87,    87,    87,    87,    88,    89,    89,    89,    90,    91,
      91,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     6,     2,     0,     1,     1,     1,     1,
       1,     1,     3,     0,     6,     0,     5,     0,     7,     0,
       8,     1,     4,     0,     3,     5,     6,    10,     1,     1,
       1,     1,     0,     1,     0,     0,     6,     3,     1,     0,
       1,     1,     0,     4,     2,     3,     2,     0,     0,     9,
       4,     2,     0,     1,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     1,
       2,     4,     4,     0,     2,     3,     3,     0,     2,     3,
       3,     3,     3,     0,     2,     3,     3,     0,     2,     3,
       3,     3,     0,     1,     1,     3,     2,     2,     2,     2,
       2,     2,     2,     2
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
  case 3: /* mainfunction: MAIN LPAREN RPAREN LBRACE codes RBRACE  */
#line 47 "parser.y"
             {
		printf("Parsed main function\n\n");
	     }
#line 1321 "parser.tab.c"
    break;

  case 12: /* declarative: type ID SEMICOLON  */
#line 55 "parser.y"
            {
		char * variable = symbol_name;
		if(find_symbol(variable)!=-1)
		{
			printf("Error : Line no : %d : Variable %s already declared\n",lineno,variable);
			YYABORT;
		}
		else{
		add_symbol(variable);
		printf("Line no : %d : Declared variable %s\n", lineno,variable);}
                memset(symbol_name,'\0',sizeof(symbol_name));
	    }
#line 1338 "parser.tab.c"
    break;

  case 13: /* $@1: %empty  */
#line 66 "parser.y"
                       {strcpy(var_name,symbol_name);}
#line 1344 "parser.tab.c"
    break;

  case 14: /* declarative: type ID $@1 EQUAL expr1 SEMICOLON  */
#line 67 "parser.y"
            {
		if(find_symbol(var_name)!=-1)
		{
			printf("Error : Line no : %d : Variable %s already declared\n",lineno, var_name);
			YYABORT;
		}
		else{
		add_symbol(var_name);
		update_symbol(var_name);
		printf("Line no : %d : Initialized variable %s\n",lineno, var_name);}
               
	    }
#line 1361 "parser.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 80 "parser.y"
               {strcpy(var_name,symbol_name);}
#line 1367 "parser.tab.c"
    break;

  case 16: /* assignment: ID $@2 EQUAL expr1 SEMICOLON  */
#line 81 "parser.y"
           {
		if(find_symbol(var_name)==-1)
		{
			printf("Error : Line no : %d : Variable %s not declared\n",lineno, var_name);
			YYABORT;
		}
		else{
		update_symbol(var_name);
		printf("Line no : %d : Assigned variabled %s\n",lineno, var_name);}
		
	   }
#line 1383 "parser.tab.c"
    break;

  case 17: /* $@3: %empty  */
#line 93 "parser.y"
                                               {printf("Parsed if\n\n");}
#line 1389 "parser.tab.c"
    break;

  case 19: /* $@4: %empty  */
#line 95 "parser.y"
                                                     {printf("Parsed else if\n\n");}
#line 1395 "parser.tab.c"
    break;

  case 22: /* conditional2: ELSE LBRACE codes RBRACE  */
#line 99 "parser.y"
             { printf("Parsed else\n\n");}
#line 1401 "parser.tab.c"
    break;

  case 25: /* iterative: WHILE condition LBRACE codes RBRACE  */
#line 104 "parser.y"
         { printf("Parsed while loop\n\n");}
#line 1407 "parser.tab.c"
    break;

  case 26: /* iterative: DO LBRACE codes RBRACE condition SEMICOLON  */
#line 106 "parser.y"
        { printf("Parsed do while loop\n\n");}
#line 1413 "parser.tab.c"
    break;

  case 27: /* iterative: FOR LPAREN initialize terminate SEMICOLON update RPAREN LBRACE codes RBRACE  */
#line 108 "parser.y"
        { printf("Parsed for loop\n\n");}
#line 1419 "parser.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 116 "parser.y"
                   {strcpy(fn_name, symbol_name);}
#line 1425 "parser.tab.c"
    break;

  case 36: /* function_call: ID $@5 LPAREN parameters RPAREN SEMICOLON  */
#line 117 "parser.y"
              {
		if(find_function(fn_name)==-1)
		{
			printf("Error : Line no : %d : Function %s not defined\n",lineno,fn_name);
			YYABORT;
	        }
		else{
			printf("Line no : %d : Function call of %s()\n",lineno,fn_name);
		}
	      }
#line 1440 "parser.tab.c"
    break;

  case 40: /* value: ID  */
#line 129 "parser.y"
          {if(find_symbol(symbol_name)==-1)
      	   {
		printf("Error : Line no : %d : Variable %s not defined\n",lineno,symbol_name);
                YYABORT;
	   }
	  }
#line 1451 "parser.tab.c"
    break;

  case 42: /* $@6: %empty  */
#line 136 "parser.y"
                  {if(find_symbol(symbol_name)==-1)
           {
                printf("Error : Line no : %d : Variable %s not defined\n",lineno,symbol_name);
                YYABORT;
           }
          }
#line 1462 "parser.tab.c"
    break;

  case 43: /* return: RETURN ID $@6 SEMICOLON  */
#line 141 "parser.y"
                     {printf("Line no : %d : Parsed Return statement\n",lineno);}
#line 1468 "parser.tab.c"
    break;

  case 44: /* return: RETURN SEMICOLON  */
#line 141 "parser.y"
                                                                                                    {printf("Line no : %d : Parsed Return statement\n",lineno);}
#line 1474 "parser.tab.c"
    break;

  case 45: /* return: RETURN NUM SEMICOLON  */
#line 141 "parser.y"
                                                                                                                                                                                       {printf("Line no : %d : Parsed Return statement\n",lineno);}
#line 1480 "parser.tab.c"
    break;

  case 48: /* $@7: %empty  */
#line 145 "parser.y"
                  {strcpy(fn_name,symbol_name);}
#line 1486 "parser.tab.c"
    break;

  case 49: /* function: type ID $@7 LPAREN signature RPAREN LBRACE codes RBRACE  */
#line 146 "parser.y"
         {
		add_function(fn_name);
		printf("Function %s defined\n\n",fn_name);
	 }
#line 1495 "parser.tab.c"
    break;

  case 57: /* $@8: %empty  */
#line 155 "parser.y"
         {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1507 "parser.tab.c"
    break;

  case 59: /* $@9: %empty  */
#line 162 "parser.y"
         {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1519 "parser.tab.c"
    break;

  case 61: /* $@10: %empty  */
#line 169 "parser.y"
         {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1531 "parser.tab.c"
    break;

  case 63: /* $@11: %empty  */
#line 176 "parser.y"
         {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1543 "parser.tab.c"
    break;

  case 65: /* $@12: %empty  */
#line 183 "parser.y"
         {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1555 "parser.tab.c"
    break;

  case 67: /* $@13: %empty  */
#line 190 "parser.y"
         {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1567 "parser.tab.c"
    break;

  case 93: /* F: ID  */
#line 219 "parser.y"
      {
  	if(find_symbol(symbol_name)==-1)
  	 {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1579 "parser.tab.c"
    break;

  case 100: /* F: PLUS_PLUS ID  */
#line 233 "parser.y"
     {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1591 "parser.tab.c"
    break;

  case 101: /* F: MINUS_MINUS ID  */
#line 241 "parser.y"
     {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1603 "parser.tab.c"
    break;

  case 102: /* F: ID PLUS_PLUS  */
#line 249 "parser.y"
     {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1615 "parser.tab.c"
    break;

  case 103: /* F: ID MINUS_MINUS  */
#line 257 "parser.y"
     {
        if(find_symbol(symbol_name)==-1)
         {
            printf("Error : Line no : %d : Variable %s not declared\n",lineno, symbol_name);
            YYABORT;
         }
       }
#line 1627 "parser.tab.c"
    break;


#line 1631 "parser.tab.c"

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

#line 266 "parser.y"


int find_symbol(char * id)
{
	for(int i=0;i<symbol_count;++i)
	{
		if(strcmp(symbol_table[i]->name,id)==0)
			return i;
	}
	return -1;
}
void add_symbol(char * id)
{
	strcpy(symbol_table[symbol_count]->name,id);
	symbol_table[symbol_count++]->initialized=0;
}
void update_symbol(char * id)
{
	symbol_table[find_symbol(id)]->initialized=1;
}
void add_function(char * id)
{
	strcpy(function_table[function_count++],id);
}
int find_function(char * id)
{
	for(int i=0;i<function_count;++i)
	{
		if(strcmp(function_table[i],id)==0)
			return i;
	}
	return -1;
}
void yyerror(const char *s) {
	printf("%s at line no %d\n",s,lineno);   
}
int main()
{
	symbol_name = (char*)malloc(100*sizeof(char));//initialize the token value variable
	memset(symbol_name,'\0',sizeof(symbol_name));

	fn_name = (char*)malloc(100*sizeof(char));//initialize  fn_name
	memset(fn_name,'\0',sizeof(fn_name));

	var_name = (char*)malloc(100*sizeof(char));
	memset(var_name,'\0',sizeof(var_name));

	symbol_table = (symbol **)malloc(sizeof(symbol*)*100); //symbol table initialized
	for(int i=0;i<100;++i)
	{
		symbol_table[i] = (symbol*)malloc(sizeof(symbol));
		symbol_table[i]->name = (char*)malloc(100*sizeof(char));
		memset(symbol_table[i]->name,'\0',sizeof(char)*100);
		symbol_table[i]->initialized = 0;
	}

	function_table = (char **)malloc(sizeof(char*)*100); //function table initialized
	for(int i=0;i<100;++i)
	{
		function_table[i] = (char*)malloc(sizeof(char)*100);
	}	

	lineno=1;
	yyparse();

	for(int i=0;i<100;++i)	
	{
		free(symbol_table[i]->name);
		free(function_table[i]);
	}
	free(symbol_table);
	free(function_table);
}

