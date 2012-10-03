
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include "header.h"

extern FILE *yyin;
extern int count;
extern char* yytext;

extern struct token entity[1000];


/* Line 189 of yacc.c  */
#line 84 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CMP = 258,
     AND = 259,
     BEGINSYM = 260,
     FORWARD = 261,
     DIV = 262,
     DO = 263,
     ELSE = 264,
     END = 265,
     FOR = 266,
     FUNCTION = 267,
     IF = 268,
     ARRAY = 269,
     MOD = 270,
     NOT = 271,
     OF = 272,
     OR = 273,
     PROCEDURE = 274,
     PROGRAM = 275,
     RECORD = 276,
     THEN = 277,
     TO = 278,
     TYPE = 279,
     VAR = 280,
     WHILE = 281,
     ID = 282,
     NUMBER = 283,
     STRING = 284,
     UNREC = 285
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 11 "parser.y"

  struct ids* idtype;
  int num;
  char* strtype;



/* Line 214 of yacc.c  */
#line 158 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 170 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,    40,    38,    41,    39,    32,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    31,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    16,    24,    33,    36,    39,    43,
      46,    49,    53,    55,    57,    60,    63,    66,    69,    73,
      77,    85,    93,   103,   113,   114,   116,   120,   126,   129,
     131,   135,   137,   141,   143,   145,   146,   148,   150,   154,
     159,   161,   166,   173,   178,   187,   189,   198,   202,   204,
     205,   207,   211,   217,   220,   222,   224,   228,   230,   233,
     235,   237,   241,   243,   245,   247,   249,   253,   255,   257,
     259,   261,   263,   265,   267,   269,   272,   276,   281,   284,
     285,   289,   294,   295,   297,   299,   303,   305,   309,   311
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    20,    27,    31,    58,    32,    -1,    20,
      27,    31,    44,    58,    32,    -1,    20,    27,    31,    44,
      46,    58,    32,    -1,    20,    27,    31,    44,    46,    48,
      58,    32,    -1,    24,    45,    -1,    51,    31,    -1,    51,
      31,    45,    -1,    25,    47,    -1,    52,    31,    -1,    52,
      31,    47,    -1,    49,    -1,    50,    -1,    53,    31,    -1,
      49,    48,    -1,    54,    31,    -1,    50,    48,    -1,    27,
       3,    65,    -1,    83,    33,    65,    -1,    19,    27,    34,
      55,    35,    31,    57,    -1,    19,    27,    34,    55,    35,
      31,     6,    -1,    12,    27,    34,    55,    35,    33,    66,
      31,    57,    -1,    12,    27,    34,    55,    35,    33,    66,
      31,     6,    -1,    -1,    56,    -1,    83,    33,    65,    -1,
      83,    33,    65,    31,    56,    -1,    46,    58,    -1,    58,
      -1,     5,    59,    10,    -1,    60,    -1,    60,    31,    59,
      -1,    61,    -1,    64,    -1,    -1,    62,    -1,    63,    -1,
      79,    33,    70,    -1,    27,    34,    81,    35,    -1,    58,
      -1,    13,    70,    22,    60,    -1,    13,    70,    22,    60,
       9,    60,    -1,    26,    70,     8,    60,    -1,    11,    27,
      33,    70,    23,    70,     8,    60,    -1,    27,    -1,    14,
      36,    69,    32,    69,    37,    17,    65,    -1,    21,    67,
      10,    -1,    27,    -1,    -1,    68,    -1,    83,    33,    65,
      -1,    83,    33,    65,    31,    68,    -1,    84,    28,    -1,
      28,    -1,    72,    -1,    72,    71,    72,    -1,     3,    -1,
      84,    73,    -1,    73,    -1,    75,    -1,    75,    74,    73,
      -1,    38,    -1,    39,    -1,    18,    -1,    77,    -1,    77,
      76,    75,    -1,    40,    -1,     7,    -1,    15,    -1,     4,
      -1,    28,    -1,    29,    -1,    79,    -1,    78,    -1,    16,
      77,    -1,    34,    70,    35,    -1,    27,    34,    81,    35,
      -1,    27,    80,    -1,    -1,    32,    27,    80,    -1,    36,
      70,    37,    80,    -1,    -1,    82,    -1,    70,    -1,    70,
      41,    82,    -1,    27,    -1,    27,    41,    83,    -1,    38,
      -1,    39,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    51,    52,    53,    56,    59,    60,    63,
      66,    67,    70,    71,    74,    75,    78,    79,    82,    85,
      88,    90,    94,    96,   100,   101,   104,   105,   108,   109,
     112,   115,   116,   119,   120,   123,   124,   125,   128,   131,
     134,   135,   136,   137,   138,   141,   142,   143,   146,   149,
     150,   153,   154,   157,   158,   161,   162,   165,   168,   169,
     172,   173,   176,   177,   178,   181,   182,   185,   186,   187,
     188,   191,   192,   193,   194,   195,   196,   199,   202,   205,
     206,   207,   210,   211,   214,   215,   218,   219,   222,   223
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CMP", "AND", "BEGINSYM", "FORWARD",
  "DIV", "DO", "ELSE", "END", "FOR", "FUNCTION", "IF", "ARRAY", "MOD",
  "NOT", "OF", "OR", "PROCEDURE", "PROGRAM", "RECORD", "THEN", "TO",
  "TYPE", "VAR", "WHILE", "ID", "NUMBER", "STRING", "UNREC", "';'", "'.'",
  "':'", "'('", "')'", "'['", "']'", "'+'", "'-'", "'*'", "','", "$accept",
  "Program", "TypeDefinitions", "TypeDefinitionSub",
  "VariableDeclarations", "VariableDeclarationSub",
  "SubprogramDeclarations", "ProcedureDeclarationSub",
  "FunctionDeclarationSub", "TypeDefinition", "VariableDeclaration",
  "ProcedureDeclaration", "FunctionDeclaration", "FormalParameterList",
  "FormalParameterListSub", "Block", "CompoundStatement",
  "StatementSequence", "Statement", "SimpleStatement",
  "AssignmentStatement", "ProcedureStatement", "StructuredStatement",
  "Type", "ResultType", "Fieldlist", "FieldlistSub", "Constant",
  "Expression", "RelationalOp", "SimpleExpression", "SimpleExpressionSub",
  "AddOp", "Term", "MulOp", "Factor", "FunctionReference", "Variable",
  "ComponentSelection", "ActualParameterList", "ActualParameterListSub",
  "Identifierlist", "Sign", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    59,    46,    58,    40,    41,    91,    93,    43,    45,
      42,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    44,    45,    45,    46,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    59,    59,    60,    60,    61,    61,    61,    62,    63,
      64,    64,    64,    64,    64,    65,    65,    65,    66,    67,
      67,    68,    68,    69,    69,    70,    70,    71,    72,    72,
      73,    73,    74,    74,    74,    75,    75,    76,    76,    76,
      76,    77,    77,    77,    77,    77,    77,    78,    79,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     7,     8,     2,     2,     3,     2,
       2,     3,     1,     1,     2,     2,     2,     2,     3,     3,
       7,     7,     9,     9,     0,     1,     3,     5,     2,     1,
       3,     1,     3,     1,     1,     0,     1,     1,     3,     4,
       1,     4,     6,     4,     8,     1,     8,     3,     1,     0,
       1,     3,     5,     2,     1,     1,     3,     1,     2,     1,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     2,     0,
       3,     4,     0,     1,     1,     3,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,    35,     0,     0,     0,
       0,     0,     0,    79,    40,     0,    31,    33,    36,    37,
      34,     0,     0,     6,     0,     0,     0,     0,     2,     0,
       0,    79,    71,    72,     0,    88,    89,     0,    55,    59,
      60,    65,    74,    73,     0,     0,     0,    82,     0,    78,
      30,    35,     0,     0,     7,    86,     9,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,     3,     0,    75,
      82,     0,    35,    57,     0,    64,    62,    63,     0,    70,
      68,    69,    67,     0,    58,    35,    79,    84,     0,    83,
       0,    32,    38,     0,    49,    45,    18,     8,     0,    10,
       0,     0,     0,     0,    15,    17,    14,    16,     4,     0,
       0,    76,    41,    56,    61,    66,    43,    80,     0,    39,
      79,     0,     0,    50,     0,    87,    11,    19,    24,    24,
       5,     0,    77,    35,    85,    81,    54,     0,     0,    47,
       0,     0,    25,     0,     0,     0,    42,     0,    53,    51,
       0,     0,     0,    35,     0,     0,     0,    26,     0,    44,
       0,    52,    48,     0,     0,    21,     0,    20,    29,     0,
       0,    27,    28,    46,    23,    22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    23,   166,    56,    61,    62,    63,    24,
      57,    64,    65,   141,   142,   167,    14,    15,    16,    17,
      18,    19,    20,    96,   163,   122,   123,   137,    87,    74,
      38,    39,    78,    40,    83,    41,    42,    43,    49,    88,
      89,   143,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int8 yypact[] =
{
      -9,    -1,    23,   -11,  -113,    12,    11,    15,    39,    33,
      30,    24,    24,    60,  -113,    56,    49,  -113,  -113,  -113,
    -113,    50,    82,  -113,    57,    59,    20,    67,  -113,    68,
      44,    61,  -113,  -113,    24,  -113,  -113,    78,   100,  -113,
      16,     3,  -113,  -113,    44,    96,    79,    24,    24,  -113,
    -113,    11,    24,    55,    15,    64,  -113,    76,    75,    83,
      84,   104,    72,    72,    81,    85,    86,  -113,    24,  -113,
      24,    80,    11,  -113,    24,  -113,  -113,  -113,    44,  -113,
    -113,  -113,  -113,    44,  -113,    11,    66,    73,    87,  -113,
      88,  -113,  -113,    77,    59,  -113,  -113,  -113,    59,    59,
      55,    89,    92,    95,  -113,  -113,  -113,  -113,  -113,    94,
      93,  -113,   110,  -113,  -113,  -113,  -113,  -113,    24,  -113,
      66,    51,   111,  -113,    97,  -113,  -113,  -113,    59,    59,
    -113,    24,  -113,    11,  -113,  -113,  -113,   101,   106,  -113,
      55,   102,  -113,    99,   103,   112,  -113,    51,  -113,   105,
     107,    55,   108,    11,    98,    59,   114,   113,     8,  -113,
     125,  -113,  -113,   115,    59,  -113,   104,  -113,  -113,    55,
      25,  -113,  -113,  -113,  -113,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,    91,   135,    48,   -34,  -113,  -113,  -113,
    -113,  -113,  -113,    19,   -14,   -19,    -5,   109,   -66,  -113,
    -113,  -113,  -113,   -92,  -113,  -113,    -3,     7,    -7,  -113,
      90,   -32,  -113,    74,  -113,   126,  -113,    -4,   -71,   116,
      37,   -24,  -112
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       9,    58,    21,    27,    37,    45,   112,    79,   127,   138,
      80,     1,    84,     6,   165,   117,     6,     6,    81,   116,
       5,    66,    10,     4,    11,     6,     3,    71,   104,   105,
       6,   174,    59,    25,    75,   138,     7,    12,    13,    60,
      30,    90,    22,    82,     6,    92,   114,    21,   149,   135,
      25,    31,    32,    33,    76,    77,   103,    29,    34,   157,
      30,   109,    35,    36,    25,    28,    50,   146,    21,    93,
     124,    31,    32,    33,   125,    58,    94,   173,    34,   136,
      51,    21,    95,    52,    59,    53,    55,   159,    54,    35,
      36,    60,    46,    46,    47,    70,    48,    48,    46,    67,
      72,    68,    48,    73,    85,    98,    86,    99,   100,     6,
     101,   102,   106,   121,   118,   111,   107,   131,   108,   133,
     153,   139,   119,   128,   145,   120,   129,   130,   132,    21,
     140,   124,   151,   147,   148,   160,   155,   150,   152,   158,
     156,   162,   169,    26,   164,    97,   170,   126,   144,    21,
     171,   175,   161,   168,   154,   134,    69,   115,     0,     0,
      91,   172,     0,     0,   113,   168,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110
};

static const yytype_int16 yycheck[] =
{
       5,    25,     6,     8,    11,    12,    72,     4,   100,   121,
       7,    20,    44,     5,     6,    86,     5,     5,    15,    85,
      31,    26,    11,     0,    13,     5,    27,    34,    62,    63,
       5,     6,    12,    25,    18,   147,    24,    26,    27,    19,
      16,    48,    27,    40,     5,    52,    78,    51,   140,   120,
      25,    27,    28,    29,    38,    39,    61,    27,    34,   151,
      16,    68,    38,    39,    25,    32,    10,   133,    72,    14,
      94,    27,    28,    29,    98,    99,    21,   169,    34,    28,
      31,    85,    27,    33,    12,     3,    27,   153,    31,    38,
      39,    19,    32,    32,    34,    34,    36,    36,    32,    32,
      22,    33,    36,     3,     8,    41,    27,    31,    33,     5,
      27,    27,    31,    36,    41,    35,    31,    23,    32,     9,
       8,    10,    35,    34,   131,    37,    34,    32,    35,   133,
      33,   155,    33,    32,    28,    37,    31,    35,    35,    31,
      33,    27,    17,     8,    31,    54,    31,    99,   129,   153,
     164,   170,   155,   158,   147,   118,    30,    83,    -1,    -1,
      51,   166,    -1,    -1,    74,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    70
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    43,    27,     0,    31,     5,    24,    44,    58,
      11,    13,    26,    27,    58,    59,    60,    61,    62,    63,
      64,    79,    27,    45,    51,    25,    46,    58,    32,    27,
      16,    27,    28,    29,    34,    38,    39,    70,    72,    73,
      75,    77,    78,    79,    84,    70,    32,    34,    36,    80,
      10,    31,    33,     3,    31,    27,    47,    52,    83,    12,
      19,    48,    49,    50,    53,    54,    58,    32,    33,    77,
      34,    70,    22,     3,    71,    18,    38,    39,    74,     4,
       7,    15,    40,    76,    73,     8,    27,    70,    81,    82,
      70,    59,    70,    14,    21,    27,    65,    45,    41,    31,
      33,    27,    27,    58,    48,    48,    31,    31,    32,    70,
      81,    35,    60,    72,    73,    75,    60,    80,    41,    35,
      37,    36,    67,    68,    83,    83,    47,    65,    34,    34,
      32,    23,    35,     9,    82,    80,    28,    69,    84,    10,
      33,    55,    56,    83,    55,    70,    60,    32,    28,    65,
      35,    33,    35,     8,    69,    31,    33,    65,    31,    60,
      37,    68,    27,    66,    31,     6,    46,    57,    58,    17,
      31,    56,    58,    65,     6,    57
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 50 "parser.y"
    {printf("Program\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 51 "parser.y"
    {printf("Program\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 52 "parser.y"
    {printf("Program\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 53 "parser.y"
    {printf("Program\n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 56 "parser.y"
    {printf("TypeDefinitions\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 63 "parser.y"
    {printf("VariableDeclaration\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    {printf("SubprogramDeclarations\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    {printf("SubprogramDeclarations\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {printf("TypeDefinition\n");updateID((yyvsp[(1) - (3)].num),(yyvsp[(3) - (3)].strtype));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    {printf("VariableDeclaration\n");updateVars((yyvsp[(1) - (3)].idtype),(yyvsp[(3) - (3)].strtype));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {printf("ProcedureDeclaration\n");updateFunc((yyvsp[(2) - (7)].num), (yyvsp[(4) - (7)].idtype));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {printf("ProcedureDeclaration\n");updateFunc((yyvsp[(2) - (7)].num), (yyvsp[(4) - (7)].idtype));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {printf("FunctionDeclaration\n");updateFunc((yyvsp[(2) - (9)].num), (yyvsp[(4) - (9)].idtype));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {printf("FunctionDeclaration\n");updateFunc((yyvsp[(2) - (9)].num), (yyvsp[(4) - (9)].idtype));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {printf("FormalParameterList\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {printf("FormalParameterList\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    { (yyval.idtype)->depth = (yyvsp[(1) - (3)].idtype)->depth; ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    { (yyval.idtype)->depth = (yyvsp[(1) - (5)].idtype)->depth + (yyvsp[(5) - (5)].idtype)->depth; ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {printf("Block\n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    {printf("Block");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 112 "parser.y"
    {printf("CompoundStatement\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 115 "parser.y"
    {printf("StatementSequence\n");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {printf("StatementSequence\n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {printf("Statement\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {printf("Statement\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {printf("SimpleStatement\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {printf("SimpleStatement\n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {printf("SimpleStatement\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {printf("AssignmentStatement\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {printf("ProcedureStatement\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {printf("StructuredStatement\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {printf("StructuredStatement\n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {printf("StructuredStatement\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {printf("StructuredStatement\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {printf("StructuredStatement\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {printf("Type\n"); (yyval.strtype) = toStr((yyvsp[(1) - (1)].num));;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {printf("Type\n"); (yyval.strtype) = "array";;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {printf("Type\n"); (yyval.strtype) ="record";;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    {printf("ResultType\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {printf("Fieldlist\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {printf("Fieldlist\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {updateVars((yyvsp[(1) - (3)].idtype),(yyvsp[(3) - (3)].strtype));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {updateVars((yyvsp[(1) - (5)].idtype),(yyvsp[(3) - (5)].strtype));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {printf("Constant\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {printf("Constant\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {printf("Expression\n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {printf("Expression\n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {printf("RelationalOp\n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {printf("SimpleExpression\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {printf("SimpleExpression\n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    {printf("AddOp\n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 177 "parser.y"
    {printf("AddOp\n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {printf("AddOp\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    {printf("Factor\n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {printf("Factor\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    {printf("MulOp\n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 186 "parser.y"
    {printf("MulOp\n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 187 "parser.y"
    {printf("MulOp\n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {printf("MulOp\n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {printf("Factor\n");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {printf("Factor\n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {printf("Factor\n");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {printf("Factor\n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {printf("Factor\n");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    {printf("Factor\n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {printf("FunctionReference\n");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {printf("Variable\n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {printf("ComponentSelection\n");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {printf("ComponentSelection\n");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {printf("ComponentSelection\n");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {printf("ActualParameterList\n");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {printf("ActualParameterList\n");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    { (yyval.idtype) = idList((yyvsp[(1) - (1)].num),NULL); printf("Identifierlist\n");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    { (yyval.idtype) = idList((yyvsp[(1) - (3)].num),(yyvsp[(3) - (3)].idtype)); printf("Identifierlist\n");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {printf("Sign\n");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {printf("Sign\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2060 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 225 "parser.y"

int main(int argc, char *argv[])
{
    ++argv, --argc;    /* skip argv[0] */
    yyin = fopen(argv[0], "r");
    printf("\n\nFINISH.\n\n");
    freopen("rule.out","w",stdout);
    yyparse();

    freopen("symtable.out","w",stdout);
    int i;
    for(i=0;i<count;i++){
      printf("index: %2d, lexeme: %10s, property: %3s, type: %4s \n",i,entity[i].value,entity[i].property,entity[i].type);
    }
    return 0;
};

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
};

void updateID(int id, char* type){
  entity[id].type = strdup(type);
}

void updateFunc(int id, struct ids* idptr){
  char buffer[10];
  sprintf(buffer,"%d",idptr->depth);
  entity[id].type = strdup(buffer);
}

void updateVars(struct ids* ids,char* type){
  while(ids != NULL){
    entity[ids->index].type = strdup(type);
    ids = ids->next;
  }
}

struct ids* idList(int id,struct ids* next){
  struct ids* i = malloc(sizeof(struct ids));
  i->index = id;
  i->next = next;
  if(next == NULL){
    i->depth = 1;
  }else{
    i->depth = 1 + (next->depth);
  }
  return i;
}

char* toStr(int id){
  return entity[id].value;
}

