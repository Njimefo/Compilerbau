/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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


/*
 * parser.y -- SPL parser specification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/errors.h>
#include <table/identifier.h>
#include <types/types.h>
#include <absyn/absyn.h>
#include <phases/_01_scanner/scanner.h>
#include <phases/_02_03_parser/parser.h>

int yylex();
void yyerror(Program**, char *);
extern int yylineno;

#line 91 "parser.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    ARRAY = 258,
    ELSE = 259,
    IF = 260,
    OF = 261,
    PROC = 262,
    REF = 263,
    TYPE = 264,
    VAR = 265,
    WHILE = 266,
    LPAREN = 267,
    RPAREN = 268,
    LBRACK = 269,
    RBRACK = 270,
    LCURL = 271,
    RCURL = 272,
    EQ = 273,
    NE = 274,
    LT = 275,
    LE = 276,
    GT = 277,
    GE = 278,
    ASGN = 279,
    COLON = 280,
    COMMA = 281,
    SEMIC = 282,
    PLUS = 283,
    MINUS = 284,
    STAR = 285,
    SLASH = 286,
    IDENT = 287,
    INTLIT = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "parser.y"

  NoVal noVal;
  IntVal intVal;
  StringVal stringVal;

  Expression *expression;
  Variable *variable;
  Statement *statement;
  TypeExpression *typeExpression;
  GlobalDeclaration *globalDeclaration;
  VariableDeclaration *variableDeclaration;
  ParameterDeclaration *parameterDeclaration;

  StatementList *statementList;
  ExpressionList *expressionList;
  VariableDeclarationList *variableList;
  ParameterList *parameterList;
  GlobalDeclarationList *globalDeclarationList;

  //Program * program;

#line 196 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (Program** program);





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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

#define YYUNDEFTOK  2
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    79,    80,    82,    83,    85,    86,    88,
      89,    92,    93,    94,    95,    97,    98,    99,   102,   103,
     108,   114,   115,   116,   117,   118,   120,   121,   125,   126,
     129,   130,   132,   133,   134,   135,   136,   138,   139,   141,
     142,   145,   146,   148,   151,   152,   153,   154,   156,   159,
     162,   165,   168,   171,   174,   176,   179,   182,   183,   186,
     189,   192,   195,   198,   201,   205,   207
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY", "ELSE", "IF", "OF", "PROC",
  "REF", "TYPE", "VAR", "WHILE", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LCURL", "RCURL", "EQ", "NE", "LT", "LE", "GT", "GE", "ASGN", "COLON",
  "COMMA", "SEMIC", "PLUS", "MINUS", "STAR", "SLASH", "IDENT", "INTLIT",
  "$accept", "program", "DeclarationList", "Declaration", "TypeDef",
  "ArrayDef", "ProcDef", "ProcDefParamList", "ProcDefParam",
  "ProcDefParamContent", "VariableDeclList", "VariableDecl",
  "VariableDeclContent", "StatementList", "Statement", "IfElseStatement",
  "IfElseBalanced", "IfElseUnBalanced", "BlockStatement", "EmptyStatement",
  "AssignStatement", "WhileStatement", "PocCallStatement",
  "PocCallParamList", "LogicalExpression", "ArithExpression", "ArithTherm",
  "ArithFactor", "Variable", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF (-90)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,   -14,    -5,    35,   -90,    23,   -90,   -90,    38,    29,
     -90,   -90,    -4,    11,    24,    54,    71,    76,   -90,    86,
      81,   106,   -90,   102,   119,    -4,    85,   -90,   -90,   -90,
      41,   -90,   121,   125,   107,   126,    43,   -90,   -90,   128,
      50,   131,   127,    58,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -90,     5,   136,    -7,   118,    -7,   -90,   129,    74,
     -90,   130,   -90,   -90,   -90,    59,    59,    12,    -7,    59,
     -90,   -90,   132,   103,    97,   -90,   134,    13,   137,   -90,
      59,   122,   138,    52,   -90,    -8,    88,   -90,   -90,   139,
      91,   -90,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,   -90,   -90,   133,    58,    36,   -90,   135,
      59,   -90,   -90,   -90,   -90,   -90,   149,    69,    69,    69,
      69,    69,    69,    97,    97,   -90,   -90,   -90,   -90,   -90,
     -90,    67,   -90,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     2,     4,     5,     6,     0,     0,
       1,     3,    15,     0,     0,     0,     0,    16,    18,     0,
       0,     0,    19,     0,     0,    15,     0,     7,     8,    20,
       0,    17,     0,     0,     0,     0,     0,    11,    41,    65,
       0,    21,     0,    26,    28,    30,    31,    35,    32,    33,
      29,    34,     0,     0,     0,     0,     0,    39,     0,     0,
      12,     0,    22,    14,    27,     0,     0,     0,     0,     0,
      65,    62,     0,     0,    57,    60,    63,     0,     0,    40,
       0,     0,     0,    46,    13,     0,     0,     9,    10,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,     0,     0,     0,    44,     0,
       0,    66,    42,    54,    64,    37,    30,    48,    49,    50,
      51,    52,    53,    55,    56,    58,    59,    23,    43,    45,
      47,     0,    36,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   150,   -90,   -90,    28,   -90,   140,   -90,   142,
     113,   -90,   -90,    53,   -75,   -90,   -89,    26,   -90,   -90,
     -90,   -90,   -90,    48,   -44,   -57,    30,   -68,   -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    21,     7,    16,    17,    18,
      40,    41,   105,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    82,    72,    73,    74,    75,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    91,    83,   116,    14,    68,    52,   111,    85,    86,
      52,    90,    78,    52,    19,    19,    19,   115,     8,    65,
      99,   100,    69,   107,    89,    70,    71,     9,    15,    66,
       1,   128,     2,   125,   126,    10,   117,   118,   119,   120,
     121,   122,   132,    20,    87,   103,    33,    13,    33,   114,
      12,    34,    35,    83,    35,    33,    15,    36,    37,    36,
      57,    35,    52,    33,    99,   100,    36,    60,    38,    35,
      38,    80,    33,    39,    36,    39,    52,    38,   110,    23,
      99,   100,    39,    36,    24,    38,    80,    81,    69,    58,
      39,    70,    71,    61,    38,    88,    64,    99,   100,    39,
      26,    52,    25,    69,   114,   104,    70,    71,    27,    93,
      94,    95,    96,    97,    98,   112,    99,   100,    32,    99,
     100,    93,    94,    95,    96,    97,    98,   101,   102,   123,
     124,    99,   100,    28,    29,    30,    53,    54,    56,    55,
      59,    34,    67,    77,    63,    92,    79,    84,    65,   108,
     106,   109,   113,   131,    62,    11,    22,   133,   130,     0,
     127,     0,   129,     0,     0,    31
};

static const yytype_int16 yycheck[] =
{
      30,    69,    59,    92,     8,    12,    36,    15,    65,    66,
      40,    68,    56,    43,     3,     3,     3,    92,    32,    14,
      28,    29,    29,    80,    68,    32,    33,    32,    32,    24,
       7,   106,     9,   101,   102,     0,    93,    94,    95,    96,
      97,    98,   131,    32,    32,    32,     5,    18,     5,    13,
      12,    10,    11,   110,    11,     5,    32,    16,    17,    16,
      17,    11,    92,     5,    28,    29,    16,    17,    27,    11,
      27,    12,     5,    32,    16,    32,   106,    27,    26,    25,
      28,    29,    32,    16,    13,    27,    12,    13,    29,    36,
      32,    32,    33,    40,    27,    67,    43,    28,    29,    32,
      14,   131,    26,    29,    13,    77,    32,    33,    27,    18,
      19,    20,    21,    22,    23,    27,    28,    29,    33,    28,
      29,    18,    19,    20,    21,    22,    23,    30,    31,    99,
     100,    28,    29,    27,    32,    16,    15,    12,    12,    32,
      12,    10,     6,    25,    17,    13,    17,    17,    14,    27,
      13,    13,    13,     4,    41,     5,    14,   131,   110,    -1,
      27,    -1,    27,    -1,    -1,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     9,    35,    36,    37,    38,    40,    32,    32,
       0,    36,    12,    18,     8,    32,    41,    42,    43,     3,
      32,    39,    43,    25,    13,    26,    14,    27,    27,    32,
      16,    41,    33,     5,    10,    11,    16,    17,    27,    32,
      44,    45,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    62,    15,    12,    32,    12,    17,    47,    12,
      17,    47,    44,    17,    47,    14,    24,     6,    12,    29,
      32,    33,    58,    59,    60,    61,    62,    25,    58,    17,
      12,    13,    57,    59,    17,    59,    59,    32,    39,    58,
      59,    61,    13,    18,    19,    20,    21,    22,    23,    28,
      29,    30,    31,    32,    39,    46,    13,    59,    27,    13,
      26,    15,    27,    13,    13,    48,    50,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    27,    48,    27,
      57,     4,    50,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    38,    39,
      39,    40,    40,    40,    40,    41,    41,    41,    42,    42,
      43,    44,    44,    45,    46,    46,    47,    47,    48,    48,
      49,    49,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    54,    55,    56,    56,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    59,    60,    60,
      60,    61,    61,    61,    61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     5,     5,     6,
       6,     7,     8,     9,     8,     0,     1,     3,     1,     2,
       3,     1,     2,     5,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     5,     7,     2,
       3,     1,     4,     5,     4,     5,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     2,     1,     1,     3,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (program, YY_("syntax error: cannot back up")); \
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
                  Type, Value, program); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, Program** program)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (program);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, Program** program)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, program);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule, Program** program)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , program);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, program); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, Program** program)
{
  YYUSE (yyvaluep);
  YYUSE (program);
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
yyparse (Program** program)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 77 "parser.y"
                                          { *program = ((yyvsp[0].globalDeclarationList)); }
#line 1469 "parser.tab.c"
    break;

  case 3:
#line 79 "parser.y"
                                                 {(yyval.globalDeclarationList) = newGlobalDeclarationList((yyvsp[-1].globalDeclaration), (yyvsp[0].globalDeclarationList));}
#line 1475 "parser.tab.c"
    break;

  case 4:
#line 80 "parser.y"
                                  {(yyval.globalDeclarationList) = emptyGlobalDeclarationList();}
#line 1481 "parser.tab.c"
    break;

  case 5:
#line 82 "parser.y"
                             { (yyval.globalDeclaration) = (yyvsp[0].globalDeclaration); }
#line 1487 "parser.tab.c"
    break;

  case 6:
#line 83 "parser.y"
                             { (yyval.globalDeclaration) = (yyvsp[0].globalDeclaration); }
#line 1493 "parser.tab.c"
    break;

  case 7:
#line 85 "parser.y"
                                               { (yyval.globalDeclaration) = newTypeDeclaration((yyvsp[-4].noVal).line, newIdentifier((yyvsp[-3].stringVal).val), newNamedTypeExpression((yyvsp[-4].noVal).line, newIdentifier((yyvsp[-1].stringVal).val)));}
#line 1499 "parser.tab.c"
    break;

  case 8:
#line 86 "parser.y"
                                                  {(yyval.globalDeclaration) = newTypeDeclaration((yyvsp[-4].noVal).line, newIdentifier((yyvsp[-3].stringVal).val), (yyvsp[-1].typeExpression));}
#line 1505 "parser.tab.c"
    break;

  case 9:
#line 88 "parser.y"
                                                         { (yyval.typeExpression) = newArrayTypeExpression((yyvsp[-5].noVal).line, newNamedTypeExpression((yyvsp[-5].noVal).line,newIdentifier((yyvsp[0].stringVal).val)), (yyvsp[-3].intVal).val); }
#line 1511 "parser.tab.c"
    break;

  case 10:
#line 89 "parser.y"
                                                                            { (yyval.typeExpression) = newArrayTypeExpression((yyvsp[-5].noVal).line, (yyvsp[0].typeExpression) ,(yyvsp[-3].intVal).val);}
#line 1517 "parser.tab.c"
    break;

  case 11:
#line 92 "parser.y"
                                                                           { (yyval.globalDeclaration) = newProcedureDeclaration((yyvsp[-6].noVal).line, newIdentifier((yyvsp[-5].stringVal).val), (yyvsp[-3].parameterList), emptyVariableList(), emptyStatementList());}
#line 1523 "parser.tab.c"
    break;

  case 12:
#line 93 "parser.y"
                                                                                             { (yyval.globalDeclaration) = newProcedureDeclaration((yyvsp[-7].noVal).line, newIdentifier((yyvsp[-6].stringVal).val), (yyvsp[-4].parameterList), (yyvsp[-1].variableList), emptyStatementList());}
#line 1529 "parser.tab.c"
    break;

  case 13:
#line 94 "parser.y"
                                                                                                          { (yyval.globalDeclaration) = newProcedureDeclaration((yyvsp[-8].noVal).line, newIdentifier((yyvsp[-7].stringVal).val), (yyvsp[-5].parameterList), (yyvsp[-2].variableList), (yyvsp[-1].statementList));}
#line 1535 "parser.tab.c"
    break;

  case 14:
#line 95 "parser.y"
                                                                                         { (yyval.globalDeclaration) = newProcedureDeclaration((yyvsp[-7].noVal).line, newIdentifier((yyvsp[-6].stringVal).val), (yyvsp[-4].parameterList), emptyVariableList(), (yyvsp[-1].statementList));}
#line 1541 "parser.tab.c"
    break;

  case 15:
#line 97 "parser.y"
                                                  { (yyval.parameterList) = emptyParameterList(); }
#line 1547 "parser.tab.c"
    break;

  case 16:
#line 98 "parser.y"
                                  { (yyval.parameterList) = newParameterList((yyvsp[0].parameterDeclaration), (yyval.parameterList)); }
#line 1553 "parser.tab.c"
    break;

  case 17:
#line 99 "parser.y"
                                                         {
                        (yyval.parameterList) = newParameterList((yyvsp[-2].parameterDeclaration), (yyvsp[0].parameterList));
                   }
#line 1561 "parser.tab.c"
    break;

  case 18:
#line 102 "parser.y"
                                                         { (yyval.parameterDeclaration) = (yyvsp[0].parameterDeclaration);}
#line 1567 "parser.tab.c"
    break;

  case 19:
#line 103 "parser.y"
                                                                  {
                        (yyvsp[0].parameterDeclaration)->isReference = true;
                        (yyval.parameterDeclaration) = (yyvsp[0].parameterDeclaration);
                   }
#line 1576 "parser.tab.c"
    break;

  case 20:
#line 108 "parser.y"
                                         {
                           Identifier * identifier = newIdentifier((yyvsp[0].stringVal).val);
                           TypeExpression * expression = newNamedTypeExpression((yyvsp[-2].stringVal).line, identifier);
                           (yyval.parameterDeclaration) = newParameterDeclaration((yyvsp[-2].stringVal).line,identifier, expression, false );
                      }
#line 1586 "parser.tab.c"
    break;

  case 21:
#line 114 "parser.y"
                                  { (yyval.variableList) = newVariableList((yyvsp[0].variableDeclaration), (yyval.variableList));}
#line 1592 "parser.tab.c"
    break;

  case 22:
#line 115 "parser.y"
                                                   { (yyval.variableList) = newVariableList((yyvsp[-1].variableDeclaration), (yyvsp[0].variableList));}
#line 1598 "parser.tab.c"
    break;

  case 23:
#line 116 "parser.y"
                                                               { (yyval.variableDeclaration) = newVariableDeclaration((yyvsp[-4].noVal).line, newIdentifier((yyvsp[-3].stringVal).val), (yyvsp[-1].typeExpression));}
#line 1604 "parser.tab.c"
    break;

  case 24:
#line 117 "parser.y"
                            { (yyval.typeExpression) = newNamedTypeExpression((yyvsp[0].stringVal).line, newIdentifier((yyvsp[0].stringVal).val));}
#line 1610 "parser.tab.c"
    break;

  case 25:
#line 118 "parser.y"
                               { (yyval.typeExpression) = (yyvsp[0].typeExpression); }
#line 1616 "parser.tab.c"
    break;

  case 26:
#line 120 "parser.y"
                               { (yyval.statementList) = newStatementList((yyvsp[0].statement), (yyval.statementList));}
#line 1622 "parser.tab.c"
    break;

  case 27:
#line 121 "parser.y"
                                            {
                        (yyval.statementList) = newStatementList((yyvsp[-1].statement), (yyvsp[0].statementList));
                   }
#line 1630 "parser.tab.c"
    break;

  case 28:
#line 125 "parser.y"
                                     { (yyval.statement) = (yyvsp[0].statement);}
#line 1636 "parser.tab.c"
    break;

  case 29:
#line 126 "parser.y"
                                    { (yyval.statement) = (yyvsp[0].statement);}
#line 1642 "parser.tab.c"
    break;

  case 30:
#line 129 "parser.y"
                                    { (yyval.statement) = (yyvsp[0].statement);}
#line 1648 "parser.tab.c"
    break;

  case 31:
#line 130 "parser.y"
                                      { (yyval.statement) = (yyvsp[0].statement);}
#line 1654 "parser.tab.c"
    break;

  case 32:
#line 132 "parser.y"
                                    { (yyval.statement) = (yyvsp[0].statement);}
#line 1660 "parser.tab.c"
    break;

  case 33:
#line 133 "parser.y"
                                     { (yyval.statement) = (yyvsp[0].statement);}
#line 1666 "parser.tab.c"
    break;

  case 34:
#line 134 "parser.y"
                                      { (yyval.statement) = (yyvsp[0].statement);}
#line 1672 "parser.tab.c"
    break;

  case 35:
#line 135 "parser.y"
                                    { (yyval.statement) = (yyvsp[0].statement);}
#line 1678 "parser.tab.c"
    break;

  case 36:
#line 136 "parser.y"
                                                                                           { (yyval.statement) = newIfStatement((yyvsp[-6].noVal).line, (yyvsp[-4].expression), (yyvsp[-2].statement), (yyvsp[0].statement));}
#line 1684 "parser.tab.c"
    break;

  case 37:
#line 138 "parser.y"
                                                                  { (yyval.statement) = newIfStatement((yyvsp[-4].noVal).line, (yyvsp[-2].expression), (yyvsp[0].statement), NULL);}
#line 1690 "parser.tab.c"
    break;

  case 38:
#line 139 "parser.y"
                                                                                             { (yyval.statement) = newIfStatement((yyvsp[-6].noVal).line, (yyvsp[-4].expression), (yyvsp[-2].statement), (yyvsp[0].statement));}
#line 1696 "parser.tab.c"
    break;

  case 39:
#line 141 "parser.y"
                                   { (yyval.statement) = newCompoundStatement((yyvsp[-1].noVal).line, emptyStatementList());}
#line 1702 "parser.tab.c"
    break;

  case 40:
#line 142 "parser.y"
                                                { (yyval.statement) = newCompoundStatement((yyvsp[-2].noVal).line, (yyvsp[-1].statementList));}
#line 1708 "parser.tab.c"
    break;

  case 41:
#line 145 "parser.y"
                           {(yyval.statement) = newEmptyStatement((yyvsp[0].noVal).line); }
#line 1714 "parser.tab.c"
    break;

  case 42:
#line 146 "parser.y"
                                                         { (yyval.statement) = newAssignStatement((yyvsp[-3].variable)->line, (yyvsp[-3].variable), (yyvsp[-1].expression));}
#line 1720 "parser.tab.c"
    break;

  case 43:
#line 148 "parser.y"
                                                                     { (yyval.statement) = newWhileStatement((yyvsp[-4].noVal).line, (yyvsp[-2].expression), (yyvsp[0].statement));}
#line 1726 "parser.tab.c"
    break;

  case 44:
#line 151 "parser.y"
                                               { (yyval.statement) = newCallStatement((yyvsp[-3].stringVal).line, newIdentifier((yyvsp[-3].stringVal).val) , emptyExpressionList());}
#line 1732 "parser.tab.c"
    break;

  case 45:
#line 152 "parser.y"
                                                                { (yyval.statement) = newCallStatement((yyvsp[-4].stringVal).line, newIdentifier((yyvsp[-4].stringVal).val) , (yyvsp[-2].expressionList));}
#line 1738 "parser.tab.c"
    break;

  case 46:
#line 153 "parser.y"
                                     { (yyval.expressionList) = newExpressionList((yyvsp[0].expression), (yyval.expressionList));}
#line 1744 "parser.tab.c"
    break;

  case 47:
#line 154 "parser.y"
                                                            { (yyval.expressionList) = newExpressionList((yyvsp[-2].expression), (yyvsp[0].expressionList));}
#line 1750 "parser.tab.c"
    break;

  case 48:
#line 156 "parser.y"
                                                       {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_EQU , (yyvsp[-2].expression) , (yyvsp[0].expression));
                        }
#line 1758 "parser.tab.c"
    break;

  case 49:
#line 159 "parser.y"
                                                       {
                         (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_NEQ , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1766 "parser.tab.c"
    break;

  case 50:
#line 162 "parser.y"
                                                       {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_LST , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1774 "parser.tab.c"
    break;

  case 51:
#line 165 "parser.y"
                                                       {
                         (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_LSE , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1782 "parser.tab.c"
    break;

  case 52:
#line 168 "parser.y"
                                                       {
                          (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_GRT , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1790 "parser.tab.c"
    break;

  case 53:
#line 171 "parser.y"
                                                       {
                          (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_GRE , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1798 "parser.tab.c"
    break;

  case 54:
#line 174 "parser.y"
                                                     { (yyval.expression) = (yyvsp[-1].expression);}
#line 1804 "parser.tab.c"
    break;

  case 55:
#line 176 "parser.y"
                                                     {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_ADD , (yyvsp[-2].expression) , (yyvsp[0].expression));
                    }
#line 1812 "parser.tab.c"
    break;

  case 56:
#line 179 "parser.y"
                                                      {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_SUB , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1820 "parser.tab.c"
    break;

  case 58:
#line 183 "parser.y"
                                                {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_MUL , (yyvsp[-2].expression) , (yyvsp[0].expression));
                    }
#line 1828 "parser.tab.c"
    break;

  case 59:
#line 186 "parser.y"
                                                  {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_DIV , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1836 "parser.tab.c"
    break;

  case 60:
#line 189 "parser.y"
                                 {
                        (yyval.expression) = (yyvsp[0].expression);
                   }
#line 1844 "parser.tab.c"
    break;

  case 61:
#line 192 "parser.y"
                                      {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_SUB , newIntLiteral ((yyvsp[-1].noVal).line, 0) , (yyvsp[0].expression));
                    }
#line 1852 "parser.tab.c"
    break;

  case 62:
#line 195 "parser.y"
                            {
                        (yyval.expression) = newIntLiteral ((yyvsp[0].intVal).line, (yyvsp[0].intVal).val);
                   }
#line 1860 "parser.tab.c"
    break;

  case 63:
#line 198 "parser.y"
                              {
                        (yyval.expression) = newVariableExpression((yyvsp[0].variable)->line, (yyvsp[0].variable));
                   }
#line 1868 "parser.tab.c"
    break;

  case 64:
#line 201 "parser.y"
                                                   {
                        (yyval.expression) = (yyvsp[-1].expression);
                   }
#line 1876 "parser.tab.c"
    break;

  case 65:
#line 205 "parser.y"
                           {
                        (yyval.variable) = newNamedVariable((yyvsp[0].stringVal).line, newIdentifier((yyvsp[0].stringVal).val) ); }
#line 1883 "parser.tab.c"
    break;

  case 66:
#line 208 "parser.y"
                           {
                                 (yyval.variable) = newArrayAccess((yyvsp[-2].noVal).line, (yyvsp[-3].variable), (yyvsp[-1].expression));
                           }
#line 1891 "parser.tab.c"
    break;


#line 1895 "parser.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (program, YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (program, yymsgp);
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
                      yytoken, &yylval, program);
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
                  yystos[yystate], yyvsp, program);
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
  yyerror (program, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, program);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, program);
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
#line 215 "parser.y"


void yyerror(Program** program, char *msg) {
    // The first parameter is needed because of '%parse-param {Program** program}'.
    // However, it is unused and gcc emits a warning for it. The following line "uses" the parameter,
    // but does nothing. It is used to silence the warning.
    (void)program;
    syntaxError(yylval.noVal.line, msg);
}
