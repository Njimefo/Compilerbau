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
#line 1 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"


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

#line 91 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_HOME_PROMETHEUS_DOCUMENTS_BRIGHT_FOLDER_SEMESTER_4_COMPILERBAU_MYTEST_CC_SRC_PHASES_02_03_PARSER_PARSER_H_INCLUDED
# define YY_YY_HOME_PROMETHEUS_DOCUMENTS_BRIGHT_FOLDER_SEMESTER_4_COMPILERBAU_MYTEST_CC_SRC_PHASES_02_03_PARSER_PARSER_H_INCLUDED
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
#line 25 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"

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

#line 199 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (Program** program);

#endif /* !YY_YY_HOME_PROMETHEUS_DOCUMENTS_BRIGHT_FOLDER_SEMESTER_4_COMPILERBAU_MYTEST_CC_SRC_PHASES_02_03_PARSER_PARSER_H_INCLUDED  */



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
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  132

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
      89,    92,    93,    95,    99,   102,   103,   106,   107,   109,
     110,   122,   125,   126,   128,   130,   131,   133,   134,   138,
     139,   142,   143,   145,   146,   147,   148,   149,   152,   153,
     155,   156,   159,   160,   162,   165,   166,   169,   170,   172,
     175,   178,   181,   184,   187,   190,   194,   197,   200,   201,
     204,   207,   210,   213,   216,   219,   223,   227
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
  "ArrayDef", "ProcDef", "ProcDefParamList", "SubProcDefParamList",
  "ProcDefParam", "ProcDefParamContent", "VariableDeclList",
  "VariableDecl", "VariableDeclContent", "StatementList", "Statement",
  "IfElseStatement", "IfElseBalanced", "IfElseUnBalanced",
  "BlockStatement", "EmptyStatement", "AssignStatement", "WhileStatement",
  "PocCallStatement", "PocCallParamList", "LogicalExpression",
  "ArithExpression", "ArithTherm", "ArithFactor", "Variable", YY_NULLPTR
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
      44,    -9,    -2,    18,   -90,    44,   -90,   -90,    54,    32,
     -90,   -90,    14,     0,    40,    61,    81,    73,   -90,    96,
      87,    88,   -90,     1,    95,    14,   -90,    83,   -90,   -90,
     -90,   -90,   -90,    47,    73,   102,   106,    89,   107,    38,
     -90,   -90,   108,    51,   112,   109,    15,   -90,   -90,   -90,
     -90,   -90,   -90,   -90,   -90,     5,   -90,   117,    -5,    99,
      -5,   -90,   110,    68,   -90,   111,   -90,   -90,   -90,    -5,
      -5,     9,    -5,    -5,   -90,   -90,   116,    84,   -14,   -90,
     118,     1,   120,   -90,    98,   121,    64,   -90,    60,   103,
     -90,   -90,    56,   -90,    15,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,   104,    15,   -90,   113,    -5,
     -90,   -90,   -90,   -90,   131,    48,    48,    48,    48,    48,
      48,   -14,   -14,   -90,   -90,   -90,   -90,   -90,   -90,    55,
     -90,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     2,     4,     5,     6,     0,     0,
       1,     3,    15,     0,     0,     0,     0,    17,    19,     0,
       0,     0,    20,     0,     0,     0,    16,     0,     7,     8,
      25,    26,    21,     0,    17,     0,     0,     0,     0,     0,
      11,    42,    66,     0,    22,     0,    27,    29,    31,    32,
      36,    33,    34,    30,    35,     0,    18,     0,     0,     0,
       0,    40,     0,     0,    12,     0,    23,    14,    28,     0,
       0,     0,     0,     0,    66,    63,     0,    55,    58,    61,
      64,     0,     0,    41,     0,     0,    47,    13,     0,     0,
       9,    10,     0,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
      67,    43,    65,    38,    31,    49,    50,    51,    52,    53,
      54,    56,    57,    59,    60,    24,    44,    46,    48,     0,
      37,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -90,   -90,   132,   -90,   -90,   -12,   -90,   -90,   105,   119,
     122,    94,   -90,    62,    52,   -85,   -90,   -89,    12,   -90,
     -90,   -90,   -90,   -90,    33,   -45,   -61,     7,   -59,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    31,     7,    16,    26,    17,
      18,    43,    44,    32,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    85,    76,    77,    78,    79,    80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      55,    21,    86,    19,    19,   114,    55,    72,    88,   113,
      55,    92,    19,    55,    93,    82,   103,   104,    10,    69,
      36,   126,    14,     8,    73,    89,    38,    74,    75,    70,
       9,    39,    20,    30,   115,   116,   117,   118,   119,   120,
     130,    90,    41,    36,   123,   124,    15,    42,    86,    38,
      13,     1,    36,     2,    39,    61,    36,    37,    38,    91,
      36,    55,    38,    39,    40,    41,    12,    39,    64,   112,
      42,    39,    15,    55,    41,   110,   101,   102,    41,    42,
      72,    84,    41,    42,   101,   102,    23,    42,   101,   102,
     109,    62,   101,   102,    24,    65,    55,    73,    68,    25,
      74,    75,    95,    96,    97,    98,    99,   100,   121,   122,
      27,    33,   101,   102,    28,    29,    35,    57,    58,    60,
      63,    59,    37,    71,    81,   107,    67,    83,    87,    94,
     111,   125,    69,   106,   108,   129,    22,    11,    66,    56,
     127,   131,   128,   105,    34
};

static const yytype_uint8 yycheck[] =
{
      33,    13,    63,     3,     3,    94,    39,    12,    69,    94,
      43,    72,     3,    46,    73,    60,    30,    31,     0,    14,
       5,   106,     8,    32,    29,    70,    11,    32,    33,    24,
      32,    16,    32,    32,    95,    96,    97,    98,    99,   100,
     129,    32,    27,     5,   103,   104,    32,    32,   109,    11,
      18,     7,     5,     9,    16,    17,     5,    10,    11,    71,
       5,    94,    11,    16,    17,    27,    12,    16,    17,    13,
      32,    16,    32,   106,    27,    15,    28,    29,    27,    32,
      12,    13,    27,    32,    28,    29,    25,    32,    28,    29,
      26,    39,    28,    29,    13,    43,   129,    29,    46,    26,
      32,    33,    18,    19,    20,    21,    22,    23,   101,   102,
      14,    16,    28,    29,    27,    27,    33,    15,    12,    12,
      12,    32,    10,     6,    25,    27,    17,    17,    17,    13,
      27,    27,    14,    13,    13,     4,    14,     5,    44,    34,
      27,   129,   109,    81,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     9,    35,    36,    37,    38,    40,    32,    32,
       0,    36,    12,    18,     8,    32,    41,    43,    44,     3,
      32,    39,    44,    25,    13,    26,    42,    14,    27,    27,
      32,    39,    47,    16,    43,    33,     5,    10,    11,    16,
      17,    27,    32,    45,    46,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    63,    42,    15,    12,    32,
      12,    17,    48,    12,    17,    48,    45,    17,    48,    14,
      24,     6,    12,    29,    32,    33,    59,    60,    61,    62,
      63,    25,    59,    17,    13,    58,    60,    17,    60,    59,
      32,    39,    60,    62,    13,    18,    19,    20,    21,    22,
      23,    28,    29,    30,    31,    47,    13,    27,    13,    26,
      15,    27,    13,    49,    51,    60,    60,    60,    60,    60,
      60,    61,    61,    62,    62,    27,    49,    27,    58,     4,
      51,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    38,    39,
      39,    40,    40,    40,    40,    41,    41,    42,    42,    43,
      43,    44,    45,    45,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    51,    51,    51,    52,    52,
      53,    53,    54,    55,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    60,    61,
      61,    61,    62,    62,    62,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     5,     5,     6,
       6,     7,     8,     9,     8,     0,     2,     0,     3,     1,
       2,     3,     1,     2,     5,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     7,     5,     7,
       2,     3,     1,     4,     5,     4,     5,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     2,     1,     1,     3,     1,     4
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
#line 77 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                          { *program = ((yyvsp[0].globalDeclarationList)); }
#line 1468 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 3:
#line 79 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                 {(yyval.globalDeclarationList) = newGlobalDeclarationList((yyvsp[-1].globalDeclaration), (yyvsp[0].globalDeclarationList));}
#line 1474 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 4:
#line 80 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                  {(yyval.globalDeclarationList) = emptyGlobalDeclarationList();}
#line 1480 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 5:
#line 82 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                             { (yyval.globalDeclaration) = (yyvsp[0].globalDeclaration); }
#line 1486 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 6:
#line 83 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                             { (yyval.globalDeclaration) = (yyvsp[0].globalDeclaration); }
#line 1492 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 7:
#line 85 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                               { (yyval.globalDeclaration) = newTypeDeclaration((yyvsp[-4].noVal).line, newIdentifier((yyvsp[-3].stringVal).val), newNamedTypeExpression((yyvsp[-4].noVal).line, newIdentifier((yyvsp[-1].stringVal).val)));}
#line 1498 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 8:
#line 86 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                  {(yyval.globalDeclaration) = newTypeDeclaration((yyvsp[-4].noVal).line, newIdentifier((yyvsp[-3].stringVal).val), (yyvsp[-1].typeExpression));}
#line 1504 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 9:
#line 88 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                         { (yyval.typeExpression) = newArrayTypeExpression((yyvsp[-5].noVal).line, newNamedTypeExpression((yyvsp[-5].noVal).line,newIdentifier((yyvsp[0].stringVal).val)), (yyvsp[-3].intVal).val); }
#line 1510 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 10:
#line 89 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                            { (yyval.typeExpression) = newArrayTypeExpression((yyvsp[-5].noVal).line, (yyvsp[0].typeExpression) ,(yyvsp[-3].intVal).val);}
#line 1516 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 11:
#line 92 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                           {(yyval.globalDeclaration) = newProcedureDeclaration((yyvsp[-6].noVal).line, newIdentifier((yyvsp[-5].stringVal).val), (yyvsp[-3].parameterList), emptyVariableList(), emptyStatementList());}
#line 1522 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 12:
#line 93 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                                             {
                            (yyval.globalDeclaration) = newProcedureDeclaration((yyvsp[-7].noVal).line, newIdentifier((yyvsp[-6].stringVal).val), (yyvsp[-4].parameterList), (yyvsp[-1].variableList), emptyStatementList());}
#line 1529 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 13:
#line 95 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                                                          {

                            (yyval.globalDeclaration) = newProcedureDeclaration((yyvsp[-8].noVal).line, newIdentifier((yyvsp[-7].stringVal).val), (yyvsp[-5].parameterList), (yyvsp[-2].variableList), (yyvsp[-1].statementList));
                            }
#line 1538 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 14:
#line 99 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                                         { (yyval.globalDeclaration) = newProcedureDeclaration((yyvsp[-7].noVal).line, newIdentifier((yyvsp[-6].stringVal).val), (yyvsp[-4].parameterList), emptyVariableList(), (yyvsp[-1].statementList));}
#line 1544 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 15:
#line 102 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                   { (yyval.parameterList) = emptyParameterList(); }
#line 1550 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 16:
#line 103 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                          { (yyval.parameterList) = newParameterList((yyvsp[-1].parameterDeclaration), (yyvsp[0].parameterList)); }
#line 1556 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 17:
#line 106 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                         { (yyval.parameterList) = emptyParameterList(); }
#line 1562 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 18:
#line 107 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                              { (yyval.parameterList) = newParameterList((yyvsp[-1].parameterDeclaration), (yyvsp[0].parameterList));}
#line 1568 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 19:
#line 109 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                         { (yyval.parameterDeclaration) = (yyvsp[0].parameterDeclaration);}
#line 1574 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 20:
#line 110 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                  {
                        (yyvsp[0].parameterDeclaration)->isReference = true;
                        (yyval.parameterDeclaration) = (yyvsp[0].parameterDeclaration);
                   }
#line 1583 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 21:
#line 122 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                      {(yyval.parameterDeclaration) = newParameterDeclaration((yyvsp[-2].stringVal).line, newIdentifier((yyvsp[-2].stringVal).val), (yyvsp[0].typeExpression), false); }
#line 1589 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 22:
#line 125 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                  { (yyval.variableList) = newVariableList((yyvsp[0].variableDeclaration), emptyVariableList());}
#line 1595 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 23:
#line 126 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                   { (yyval.variableList) = newVariableList((yyvsp[-1].variableDeclaration), (yyvsp[0].variableList));}
#line 1601 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 24:
#line 128 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                               { (yyval.variableDeclaration) = newVariableDeclaration((yyvsp[-4].noVal).line, newIdentifier((yyvsp[-3].stringVal).val)
, (yyvsp[-1].typeExpression));}
#line 1608 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 25:
#line 130 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                            { (yyval.typeExpression) = newNamedTypeExpression((yyvsp[0].stringVal).line, newIdentifier((yyvsp[0].stringVal).val));}
#line 1614 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 26:
#line 131 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                               { (yyval.typeExpression) = (yyvsp[0].typeExpression); }
#line 1620 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 27:
#line 133 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                               { (yyval.statementList) = newStatementList((yyvsp[0].statement), emptyStatementList());}
#line 1626 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 28:
#line 134 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                            {
                        (yyval.statementList) = newStatementList((yyvsp[-1].statement), (yyvsp[0].statementList));
                   }
#line 1634 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 29:
#line 138 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                     { (yyval.statement) = (yyvsp[0].statement);}
#line 1640 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 30:
#line 139 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                    { (yyval.statement) = (yyvsp[0].statement);}
#line 1646 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 31:
#line 142 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                    { (yyval.statement) = (yyvsp[0].statement);}
#line 1652 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 32:
#line 143 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                      { (yyval.statement) = (yyvsp[0].statement);}
#line 1658 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 33:
#line 145 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                    { (yyval.statement) = (yyvsp[0].statement);}
#line 1664 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 34:
#line 146 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                     { (yyval.statement) = (yyvsp[0].statement);}
#line 1670 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 35:
#line 147 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                      { (yyval.statement) = (yyvsp[0].statement);}
#line 1676 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 36:
#line 148 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                    { (yyval.statement) = (yyvsp[0].statement);}
#line 1682 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 37:
#line 149 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                                           { (yyval.statement) = newIfStatement((yyvsp[-6].noVal).line, (yyvsp[-4].expression), (yyvsp[-2].statement), (yyvsp[0].statement));}
#line 1688 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 38:
#line 152 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                  { (yyval.statement) = newIfStatement((yyvsp[-4].noVal).line, (yyvsp[-2].expression), (yyvsp[0].statement), newEmptyStatement((yyvsp[-4].noVal).line));}
#line 1694 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 39:
#line 153 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                                             { (yyval.statement) = newIfStatement((yyvsp[-6].noVal).line, (yyvsp[-4].expression), (yyvsp[-2].statement), (yyvsp[0].statement));}
#line 1700 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 40:
#line 155 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                   { (yyval.statement) = newCompoundStatement((yyvsp[-1].noVal).line, emptyStatementList());}
#line 1706 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 41:
#line 156 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                { (yyval.statement) = newCompoundStatement((yyvsp[-2].noVal).line, (yyvsp[-1].statementList));}
#line 1712 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 42:
#line 159 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                           {(yyval.statement) = newEmptyStatement((yyvsp[0].noVal).line); }
#line 1718 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 43:
#line 160 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                           { (yyval.statement) = newAssignStatement((yyvsp[-3].variable)->line, (yyvsp[-3].variable), (yyvsp[-1].expression));}
#line 1724 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 44:
#line 162 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                     { (yyval.statement) = newWhileStatement((yyvsp[-4].noVal).line, (yyvsp[-2].expression), (yyvsp[0].statement));}
#line 1730 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 45:
#line 165 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                               { (yyval.statement) = newCallStatement((yyvsp[-3].stringVal).line, newIdentifier((yyvsp[-3].stringVal).val) , emptyExpressionList());}
#line 1736 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 46:
#line 166 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                                { (yyval.statement) = newCallStatement((yyvsp[-4].stringVal).line, newIdentifier((yyvsp[-4].stringVal).val) , (yyvsp[-2].expressionList));}
#line 1742 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 47:
#line 169 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                     { (yyval.expressionList) = newExpressionList((yyvsp[0].expression), emptyExpressionList());}
#line 1748 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 48:
#line 170 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                            { (yyval.expressionList) = newExpressionList((yyvsp[-2].expression), (yyvsp[0].expressionList));}
#line 1754 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 49:
#line 172 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                       {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_EQU , (yyvsp[-2].expression) , (yyvsp[0].expression));
                        }
#line 1762 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 50:
#line 175 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                       {
                         (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_NEQ , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1770 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 51:
#line 178 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                       {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_LST , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1778 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 52:
#line 181 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                       {
                         (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_LSE , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1786 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 53:
#line 184 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                       {
                          (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_GRT , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1794 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 54:
#line 187 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                       {
                          (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_GRE , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1802 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 55:
#line 190 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                     { (yyval.expression) = (yyvsp[0].expression);}
#line 1808 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 56:
#line 194 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                     {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_ADD , (yyvsp[-2].expression) , (yyvsp[0].expression));
                    }
#line 1816 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 57:
#line 197 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                      {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_SUB , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1824 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 59:
#line 201 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_MUL , (yyvsp[-2].expression) , (yyvsp[0].expression));
                    }
#line 1832 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 60:
#line 204 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                  {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_DIV , (yyvsp[-2].expression) , (yyvsp[0].expression));
                   }
#line 1840 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 61:
#line 207 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                 {
                        (yyval.expression) = (yyvsp[0].expression);
                   }
#line 1848 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 62:
#line 210 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                      {
                        (yyval.expression) = newBinaryExpression((yyvsp[-1].noVal).line, ABSYN_OP_SUB , newIntLiteral ((yyvsp[-1].noVal).line, 0) , (yyvsp[0].expression));
                    }
#line 1856 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 63:
#line 213 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                            {
                        (yyval.expression) = newIntLiteral ((yyvsp[0].intVal).line, (yyvsp[0].intVal).val);
                   }
#line 1864 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 64:
#line 216 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                              {
                        (yyval.expression) = newVariableExpression((yyvsp[0].variable)->line, (yyvsp[0].variable));
                   }
#line 1872 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 65:
#line 219 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                                                   {
                        (yyval.expression) = (yyvsp[-1].expression);
                   }
#line 1880 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 66:
#line 223 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                           {
                        (yyval.variable) = newNamedVariable((yyvsp[0].stringVal).line, newIdentifier((yyvsp[0].stringVal).val) );

                         }
#line 1889 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;

  case 67:
#line 228 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"
                           {
                                 (yyval.variable) = newArrayAccess((yyvsp[-2].noVal).line, (yyvsp[-3].variable), (yyvsp[-1].expression));
                           }
#line 1897 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"
    break;


#line 1901 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.c"

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
#line 233 "/home/prometheus/Documents/Bright folder/Semester 4/CompilerBau/mytest/cc/src/phases/_02_03_parser/parser.y"


void yyerror(Program** program, char *msg) {
    // The first parameter is needed because of '%parse-param {Program** program}'.
    // However, it is unused and gcc emits a warning for it. The following line "uses" the parameter,
    // but does nothing. It is used to silence the warning.
    (void)program;
    syntaxError(yylval.noVal.line, msg);
}
