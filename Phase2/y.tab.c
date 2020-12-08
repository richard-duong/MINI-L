/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mini.y" /* yacc.c:339  */

#include "stdio.h"
#include "stdlib.h"



extern int currLine;
extern int currPos;
extern char* yytext;

int yylex(void);
int yyerror(const char* msg){
  printf("BISON: Error at line %d, column %d : unexpected value \"%s\" encountered\n", currLine, currPos, yytext);
  exit(1);
  return 1;
}


#line 85 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCTION = 258,
    BEGINPARAMS = 259,
    ENDPARAMS = 260,
    BEGINLOCALS = 261,
    ENDLOCALS = 262,
    BEGINBODY = 263,
    ENDBODY = 264,
    INTEGER = 265,
    ARRAY = 266,
    OF = 267,
    IF = 268,
    THEN = 269,
    ENDIF = 270,
    ELSE = 271,
    WHILE = 272,
    DO = 273,
    FOR = 274,
    BEGINLOOP = 275,
    ENDLOOP = 276,
    CONTINUE = 277,
    READ = 278,
    WRITE = 279,
    AND = 280,
    OR = 281,
    NOT = 282,
    TRUE = 283,
    FALSE = 284,
    RETURN = 285,
    SEMICOLON = 286,
    L_PAREN = 287,
    R_PAREN = 288,
    L_BRACK = 289,
    R_BRACK = 290,
    COLON = 291,
    COMMA = 292,
    ASSIGN = 293,
    NUM = 294,
    IDEN = 295,
    MULT = 296,
    DIV = 297,
    MOD = 298,
    ADD = 299,
    SUB = 300,
    LT = 301,
    LTE = 302,
    GT = 303,
    GTE = 304,
    EQ = 305,
    NEQ = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "mini.y" /* yacc.c:355  */

  int num;
  char iden[50];

#line 182 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 199 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    45,    46,    49,    50,    53,    56,    57,
      60,    61,    65,    66,    67,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    81,    84,    87,    88,    91,    94,
      97,   100,   103,   106,   109,   112,   113,   116,   117,   120,
     121,   124,   125,   128,   129,   130,   131,   134,   135,   136,
     137,   138,   139,   142,   145,   146,   147,   150,   153,   154,
     155,   156,   159,   160,   161,   164,   165,   166,   169,   170,
     173,   174,   177,   178,   179
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGINPARAMS", "ENDPARAMS",
  "BEGINLOCALS", "ENDLOCALS", "BEGINBODY", "ENDBODY", "INTEGER", "ARRAY",
  "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "FOR", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE",
  "FALSE", "RETURN", "SEMICOLON", "L_PAREN", "R_PAREN", "L_BRACK",
  "R_BRACK", "COLON", "COMMA", "ASSIGN", "NUM", "IDEN", "MULT", "DIV",
  "MOD", "ADD", "SUB", "LT", "LTE", "GT", "GTE", "EQ", "NEQ", "$accept",
  "prog", "func_cycle", "decl_cycle", "decl", "iden_cycle", "stmt_cycle",
  "arr_cycle", "stmt", "assign_cycle", "if_cycle", "else_cycle",
  "while_cycle", "do_cycle", "for_cycle", "read_cycle", "write_cycle",
  "continue_cycle", "return_cycle", "var_cycle", "bool_exp", "rel_and_exp",
  "rel_exp", "rel_exp_base", "comp", "exp", "mult_cycle", "mult_exp",
  "term_cycle", "term", "term_base", "param_cycle", "exp_cycle", "var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -57,    16,    81,   -57,    22,    58,    94,   -57,    -1,   111,
     -57,    87,   -12,   -57,   -57,   108,    80,     3,    90,   115,
     -57,   119,    89,   -57,   173,    95,   -10,   -10,   121,    96,
     -57,    96,    96,    43,   109,    14,   114,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   104,     0,    19,   -57,
     -57,   -10,   -57,    21,   -26,    35,   126,   -57,   -57,    46,
      42,    61,   -57,   -57,    59,   173,   122,   120,   -57,   120,
      43,   -57,    43,   -57,   128,   -57,    43,   -57,   113,   -57,
      24,    23,    43,   -57,   173,   -10,   -10,   -57,   -57,   -57,
     -57,   -57,   -57,    43,    43,    43,   -57,    43,    43,    43,
     -57,   173,   116,   134,    96,   132,   135,   -57,   -57,   139,
     -57,   -57,   -57,   146,   147,   131,   126,   -57,   -57,    42,
      42,    61,    61,    61,   145,   170,   157,   -57,   160,   181,
     -57,    43,   173,   183,   -57,   -57,   -57,   -57,   -57,   -57,
     -10,   -10,    43,   -57,   -57,   173,   -57,   174,   -11,   166,
      96,   -57,   164,    43,   184,   173,   159,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     5,     0,     0,
       8,     0,     0,     5,     6,    12,     0,     0,     0,     0,
       9,     0,     0,     7,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,    72,     0,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,     0,     0,     0,    44,
      45,     0,    66,    72,     0,     0,    37,    39,    41,     0,
      54,    58,    62,    65,     0,     0,     0,    31,    35,    32,
       0,    34,     0,     4,     0,    10,     0,    13,     0,    42,
       0,     0,    68,    63,     0,     0,     0,    49,    51,    50,
      52,    47,    48,     0,     0,     0,    53,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,    11,    24,     0,
      46,    67,    70,     0,    69,    26,    38,    40,    43,    54,
      54,    58,    58,    58,     0,     0,     0,    36,    73,     0,
      64,     0,     0,     0,    55,    56,    59,    60,    61,    28,
       0,     0,     0,    14,    71,    27,    25,    29,     0,     0,
       0,    74,     0,     0,     0,     0,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   -57,   192,   -57,   -57,   -56,   -57,   -34,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   -57,   175,
     -25,   123,   124,   158,   -57,   -30,    -6,    15,   -16,   -32,
     155,   -57,   -57,   -24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,    11,    12,    35,    19,    36,    37,
      38,   133,    39,    40,    41,    42,    43,    44,    45,    67,
      55,    56,    57,    58,    93,    59,    96,    60,   100,    61,
      62,   113,   114,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      46,    74,    64,    71,     9,    66,    70,    68,    68,   102,
      21,    46,    77,    52,    34,    85,     3,    48,    49,    50,
     150,    81,    51,    73,    15,    16,    80,    26,   115,    52,
      53,    27,    28,    29,    78,    54,    30,    31,    32,    10,
     105,    46,   106,    10,    33,   124,   108,    49,    50,    84,
      85,    51,   112,    82,    34,    72,   111,   110,    52,    53,
      46,    85,     5,   118,    54,   121,   122,   123,    74,    87,
      88,    89,    90,    91,    92,    70,   145,    46,    46,   101,
     127,    74,    52,    53,     4,    85,    94,    95,    54,     6,
      74,    46,    87,    88,    89,    90,    91,    92,     7,   156,
      46,   144,    97,    98,    99,   136,   137,   138,    46,   119,
     120,    74,   149,   134,   135,   147,   148,    13,    14,    18,
      20,    46,    74,   154,    22,    23,   152,    24,    25,    26,
      47,    46,    46,    27,    28,    29,    34,   125,    30,    31,
      32,    65,    76,    72,    26,    75,    33,   132,    27,    28,
      29,    86,   109,    30,    31,    32,    34,   104,    26,   107,
     103,    33,    27,    28,    29,   111,   139,    30,    31,    32,
     128,    34,    26,   126,   129,    33,    27,    28,    29,   130,
     157,    30,    31,    32,   131,    34,    26,   140,   141,    33,
      27,    28,    29,   143,   142,    30,    31,    32,   146,    34,
      85,   151,   153,    33,   155,    17,    79,    69,   116,    83,
     117,     0,     0,    34
};

static const yytype_int16 yycheck[] =
{
      24,    35,    27,    33,     5,    29,    32,    31,    32,    65,
       7,    35,    12,    39,    40,    26,     0,    27,    28,    29,
      31,    51,    32,     9,    36,    37,    51,    13,    84,    39,
      40,    17,    18,    19,    34,    45,    22,    23,    24,    40,
      70,    65,    72,    40,    30,   101,    76,    28,    29,    14,
      26,    32,    82,    32,    40,    34,    33,    33,    39,    40,
      84,    26,    40,    93,    45,    97,    98,    99,   102,    46,
      47,    48,    49,    50,    51,    32,   132,   101,   102,    20,
     104,   115,    39,    40,     3,    26,    44,    45,    45,    31,
     124,   115,    46,    47,    48,    49,    50,    51,     4,   155,
     124,   131,    41,    42,    43,   121,   122,   123,   132,    94,
      95,   145,   142,   119,   120,   140,   141,     6,    31,    11,
      40,   145,   156,   153,    34,    10,   150,     8,    39,    13,
      35,   155,   156,    17,    18,    19,    40,    21,    22,    23,
      24,    20,    38,    34,    13,    31,    30,    16,    17,    18,
      19,    25,    39,    22,    23,    24,    40,    37,    13,    31,
      38,    30,    17,    18,    19,    33,    21,    22,    23,    24,
      35,    40,    13,    39,    35,    30,    17,    18,    19,    33,
      21,    22,    23,    24,    37,    40,    13,    17,    31,    30,
      17,    18,    19,    12,    34,    22,    23,    24,    15,    40,
      26,    35,    38,    30,    20,    13,    48,    32,    85,    54,
      86,    -1,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    53,    54,     0,     3,    40,    31,     4,    55,     5,
      40,    56,    57,     6,    31,    36,    37,    55,    11,    59,
      40,     7,    34,    10,     8,    39,    13,    17,    18,    19,
      22,    23,    24,    30,    40,    58,    60,    61,    62,    64,
      65,    66,    67,    68,    69,    70,    85,    35,    27,    28,
      29,    32,    39,    40,    45,    72,    73,    74,    75,    77,
      79,    81,    82,    85,    72,    20,    85,    71,    85,    71,
      32,    77,    34,     9,    60,    31,    38,    12,    34,    75,
      72,    77,    32,    82,    14,    26,    25,    46,    47,    48,
      49,    50,    51,    76,    44,    45,    78,    41,    42,    43,
      80,    20,    58,    38,    37,    77,    77,    31,    77,    39,
      33,    33,    77,    83,    84,    58,    73,    74,    77,    79,
      79,    81,    81,    81,    58,    21,    39,    85,    35,    35,
      33,    37,    16,    63,    78,    78,    80,    80,    80,    21,
      17,    31,    34,    12,    77,    58,    15,    72,    72,    77,
      31,    35,    85,    38,    77,    20,    58,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    57,    57,
      58,    58,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    62,    63,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    77,    78,    78,    78,    79,    80,    80,
      80,    80,    81,    81,    81,    82,    82,    82,    83,    83,
      84,    84,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,    13,     0,     3,     4,     1,     3,
       2,     3,     0,     5,     8,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     0,     2,     5,     6,
      13,     2,     2,     1,     2,     1,     3,     1,     3,     1,
       3,     1,     2,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     2,     0,     3,     3,     2,     0,     3,
       3,     3,     1,     2,     4,     1,     1,     3,     0,     1,
       1,     3,     1,     4,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 42 "mini.y" /* yacc.c:1646  */
    { printf("prog -> func_cycle\n"); }
#line 1399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 46 "mini.y" /* yacc.c:1646  */
    { printf("func_cycle -> func_cycle FUNCTION IDEN %s SEMICOLON BEGINPARAMS decl_cycle ENDPARAMS BEGINLOCALS decl_cycle ENDLOCALS BEGINBODY stmt_cycle ENDBODY\n", (yyvsp[-10].iden)); }
#line 1405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 50 "mini.y" /* yacc.c:1646  */
    { printf("decl_cycle -> decl_cycle decl SEMICOLON\n"); }
#line 1411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 53 "mini.y" /* yacc.c:1646  */
    { printf("decl -> iden_cycle COLON arr_cycle INTEGER\n"); }
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 56 "mini.y" /* yacc.c:1646  */
    { printf("iden_cycle -> IDEN %s\n", (yyvsp[0].iden)); }
#line 1423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 57 "mini.y" /* yacc.c:1646  */
    { printf("iden_cycle -> iden_cycle COMMA IDEN %s\n", (yyvsp[0].iden)); }
#line 1429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 60 "mini.y" /* yacc.c:1646  */
    { printf("stmt_cycle -> stmt SEMICOLON\n"); }
#line 1435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 61 "mini.y" /* yacc.c:1646  */
    { printf("stmt_cycle -> stmt_cycle stmt SEMICOLON\n"); }
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 66 "mini.y" /* yacc.c:1646  */
    { printf("arr_cycle -> ARRAY L_BRACK NUM %d R_BRACK OF\n", (yyvsp[-2].num)); }
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 67 "mini.y" /* yacc.c:1646  */
    { printf("arr_cycle -> ARRAY L_BRACK NUM %d R_BRACK L_BRACK NUM %d R_BRACK OF\n", (yyvsp[-5].num), (yyvsp[-2].num)); }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 70 "mini.y" /* yacc.c:1646  */
    { printf("stmt -> assign_cycle\n"); }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 71 "mini.y" /* yacc.c:1646  */
    { printf("stmt -> if_cycle\n"); }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 72 "mini.y" /* yacc.c:1646  */
    { printf("stmt -> while_cycle\n"); }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 73 "mini.y" /* yacc.c:1646  */
    { printf("stmt -> do_cycle\n"); }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 74 "mini.y" /* yacc.c:1646  */
    { printf("stmt -> for_cycle\n"); }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 75 "mini.y" /* yacc.c:1646  */
    { printf("stmt -> read_cycle\n"); }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 76 "mini.y" /* yacc.c:1646  */
    { printf("stmt -> write_cycle\n"); }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 77 "mini.y" /* yacc.c:1646  */
    { printf("stmt -> continue_cycle\n"); }
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 78 "mini.y" /* yacc.c:1646  */
    { printf("stmt -> return_cycle\n"); }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 81 "mini.y" /* yacc.c:1646  */
    { printf("assign_cycle -> var ASSIGN exp\n"); }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 84 "mini.y" /* yacc.c:1646  */
    { printf("if_cycle -> IF bool_exp THEN stmt_cycle else_cycle ENDIF\n"); }
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 88 "mini.y" /* yacc.c:1646  */
    { printf("else_cycle -> ELSE stmt_cycle\n"); }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 91 "mini.y" /* yacc.c:1646  */
    { printf("while_cycle -> WHILE bool_exp BEGINLOOP stmt_cycle ENDLOOP\n"); }
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 94 "mini.y" /* yacc.c:1646  */
    { printf("do_cycle -> DO BEGINLOOP stmt_cycle ENDLOOP WHILE bool_exp\n"); }
#line 1537 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 97 "mini.y" /* yacc.c:1646  */
    { printf("for_cycle -> FOR var ASSIGN NUM %d SEMICOLON bool_exp SEMICOLON var ASSIGN exp BEGINLOOP stmt_cycle ENDLOOP\n", (yyvsp[-9].num)); }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 100 "mini.y" /* yacc.c:1646  */
    { printf("read_cycle -> READ var_cycle\n"); }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 103 "mini.y" /* yacc.c:1646  */
    { printf("write_cycle -> WRITE var_cycle\n"); }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 106 "mini.y" /* yacc.c:1646  */
    { printf("continue_cycle -> CONTINUE\n"); }
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 109 "mini.y" /* yacc.c:1646  */
    { printf("return_cycle -> RETURN exp\n"); }
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 112 "mini.y" /* yacc.c:1646  */
    { printf("var_cycle -> var\n"); }
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 113 "mini.y" /* yacc.c:1646  */
    { printf("var_cycle -> var_cycle COMMA var\n"); }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 116 "mini.y" /* yacc.c:1646  */
    { printf("bool_exp -> rel_and_exp\n"); }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 117 "mini.y" /* yacc.c:1646  */
    { printf("bool_exp -> bool_exp OR rel_and_exp\n"); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 120 "mini.y" /* yacc.c:1646  */
    { printf("rel_and_exp -> rel_exp\n"); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 121 "mini.y" /* yacc.c:1646  */
    { printf("rel_and_exp -> rel_and_exp AND rel_exp\n"); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 124 "mini.y" /* yacc.c:1646  */
    { printf("rel_exp -> rel_exp_base\n"); }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 125 "mini.y" /* yacc.c:1646  */
    { printf(" rel_exp -> NOT rel_exp_base\n"); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 128 "mini.y" /* yacc.c:1646  */
    { printf("rel_exp_base -> exp comp exp\n"); }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 129 "mini.y" /* yacc.c:1646  */
    { printf("rel_exp_base -> TRUE\n"); }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 130 "mini.y" /* yacc.c:1646  */
    { printf("rel_exp_base -> FALSE\n"); }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 131 "mini.y" /* yacc.c:1646  */
    { printf("rel_exp_base -> L_PAREN bool_exp R_PAREN\n"); }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 134 "mini.y" /* yacc.c:1646  */
    { printf("comp -> EQ\n"); }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 135 "mini.y" /* yacc.c:1646  */
    { printf("comp -> NEQ\n"); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 136 "mini.y" /* yacc.c:1646  */
    { printf("comp -> LT\n"); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 137 "mini.y" /* yacc.c:1646  */
    { printf("comp -> GT\n"); }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 138 "mini.y" /* yacc.c:1646  */
    { printf("comp -> LTE\n"); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 139 "mini.y" /* yacc.c:1646  */
    { printf("comp -> GTE\n"); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 142 "mini.y" /* yacc.c:1646  */
    { printf("exp -> mult_exp mult_cycle\n"); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 146 "mini.y" /* yacc.c:1646  */
    { printf("mult_cycle -> ADD mult_exp mult_cycle\n"); }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 147 "mini.y" /* yacc.c:1646  */
    { printf("mult_cycle -> SUB mult_exp mult_cycle\n"); }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 150 "mini.y" /* yacc.c:1646  */
    { printf("mult_exp -> term term_cycle\n"); }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 154 "mini.y" /* yacc.c:1646  */
    { printf("term_cycle -> MULT term term_cycle\n"); }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 155 "mini.y" /* yacc.c:1646  */
    { printf("term_cycle -> DIV term term_cycle\n"); }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 156 "mini.y" /* yacc.c:1646  */
    { printf("term_cycle -> MOD term term_cycle\n"); }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 159 "mini.y" /* yacc.c:1646  */
    { printf("term -> term_base\n"); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 160 "mini.y" /* yacc.c:1646  */
    { printf("term -> SUB term_base\n"); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 161 "mini.y" /* yacc.c:1646  */
    { printf("term -> IDEN %s L_PAREN param_cycle R_PAREN\n", (yyvsp[-3].iden)); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 164 "mini.y" /* yacc.c:1646  */
    { printf("term_base -> var\n"); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 165 "mini.y" /* yacc.c:1646  */
    { printf("term_base -> NUM %d\n", (yyvsp[0].num)); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 166 "mini.y" /* yacc.c:1646  */
    { printf("term_base -> L_PAREN exp R_PAREN\n"); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 170 "mini.y" /* yacc.c:1646  */
    { printf("param_cycle -> exp_cycle\n"); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 173 "mini.y" /* yacc.c:1646  */
    { printf("exp_cycle -> exp\n"); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 174 "mini.y" /* yacc.c:1646  */
    { printf("exp_cycle -> exp_cycle COMMA exp\n"); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 177 "mini.y" /* yacc.c:1646  */
    { printf("var -> IDEN %s\n", (yyvsp[0].iden)); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 178 "mini.y" /* yacc.c:1646  */
    { printf("var -> IDEN %s L_BRACK exp R_BRACK\n", (yyvsp[-3].iden)); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 179 "mini.y" /* yacc.c:1646  */
    { printf("var -> IDEN %s L_BRACK exp R_BRACK L_BRACK exp R_BRACK\n", (yyvsp[-6].iden)); }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1793 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 182 "mini.y" /* yacc.c:1906  */




int main(){
  yyparse();

}
