
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
#line 1 "s4.y"

#include "header.h"

 extern FILE *yyin;
 extern char* yytext;

/*Symbol Table*/
 struct symtable* top;

 struct id* new_id(char* lexeme, struct id* next);
 char* strconn(char* s1, char* s2);

/*Function declaration*/
 void set_id_type(struct id*,char*);
 char* get_id_type(struct id* id);
 char* get_type_from_symtab(char*);
 char* get_array_type(int a,int b,char* type);
 char* get_record_type(struct id* ids, char* type);
 int to_num(char sign,char* value);
 void check_type_equal(char* v1, char* v2, char* l1);

 void set_new_scope();
 void release_scope();

 void check_undeclared_var(struct id* id);
 int check_multi_def(struct id* id);

 int install_id_lexeme(char* idstr);
 void install_id(struct id* id);
 void install_ids(struct id* ids, char* type);
 void install_func(struct id*,char*);


/* Line 189 of yacc.c  */
#line 107 "s4.tab.c"

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
     LT = 258,
     EQ = 259,
     NE = 260,
     GT = 261,
     GE = 262,
     LE = 263,
     RELOP = 264,
     PLUS = 265,
     MINUS = 266,
     MULTI = 267,
     ARIOP = 268,
     DOT = 269,
     COMMA = 270,
     COLON = 271,
     SEMICOLON = 272,
     ASSIGN = 273,
     DDOT = 274,
     L_BRACE = 275,
     R_BRACE = 276,
     L_BRACKET = 277,
     R_BRACKET = 278,
     OTHEROP = 279,
     ANDSYM = 280,
     BEGINSYM = 281,
     FORWARDSYM = 282,
     DIVSYM = 283,
     DOSYM = 284,
     ELSESYM = 285,
     ENDSYM = 286,
     FORSYM = 287,
     FUNCTIONSYM = 288,
     IFSYM = 289,
     ARRAYSYM = 290,
     MODSYM = 291,
     NOTSYM = 292,
     OFSYM = 293,
     ORSYM = 294,
     PROCEDURESYM = 295,
     PROGRAMSYM = 296,
     RECORDSYM = 297,
     THENSYM = 298,
     TOSYM = 299,
     TYPESYM = 300,
     VARSYM = 301,
     WHILESYM = 302,
     ID = 303,
     NUMBER = 304,
     STRING = 305,
     UNREC = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 34 "s4.y"

  struct id* idtype;
  int num;
  char* strtype;



/* Line 214 of yacc.c  */
#line 202 "s4.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 214 "s4.tab.c"

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
#define YYLAST   193

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNRULES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    16,    23,    30,    38,    46,    54,
      63,    66,    69,    73,    77,    80,    83,    87,    91,    92,
      95,    96,    99,   102,   105,   108,   111,   112,   121,   122,
     131,   132,   143,   144,   155,   156,   158,   162,   168,   171,
     173,   177,   179,   183,   185,   187,   188,   190,   192,   196,
     201,   203,   208,   215,   220,   221,   231,   233,   242,   246,
     248,   249,   251,   255,   261,   264,   266,   268,   272,   274,
     276,   278,   280,   282,   284,   287,   289,   291,   295,   297,
     299,   301,   303,   307,   309,   311,   313,   315,   317,   319,
     321,   323,   326,   330,   335,   336,   340,   341,   342,   347,
     352,   353,   355,   357,   361,   363,   367,   369
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    41,    48,    17,    74,    14,    -1,    41,
      48,    17,    54,    74,    14,    -1,    41,    48,    17,    57,
      74,    14,    -1,    41,    48,    17,    60,    74,    14,    -1,
      41,    48,    17,    54,    57,    74,    14,    -1,    41,    48,
      17,    57,    60,    74,    14,    -1,    41,    48,    17,    54,
      60,    74,    14,    -1,    41,    48,    17,    54,    57,    60,
      74,    14,    -1,    45,    55,    -1,    56,    17,    -1,    56,
      17,    55,    -1,    48,     4,    82,    -1,    46,    58,    -1,
      59,    17,    -1,    59,    17,    58,    -1,   102,    16,    82,
      -1,    -1,    61,    63,    -1,    -1,    62,    64,    -1,    65,
      17,    -1,    63,    60,    -1,    68,    17,    -1,    64,    60,
      -1,    -1,    40,    48,    20,    71,    21,    17,    66,    73,
      -1,    -1,    40,    48,    20,    71,    21,    17,    67,    27,
      -1,    -1,    33,    48,    20,    71,    21,    16,    83,    17,
      69,    73,    -1,    -1,    33,    48,    20,    71,    21,    16,
      83,    17,    70,    27,    -1,    -1,    72,    -1,   102,    16,
      82,    -1,   102,    16,    82,    17,    72,    -1,    57,    74,
      -1,    74,    -1,    26,    75,    31,    -1,    76,    -1,    76,
      17,    75,    -1,    77,    -1,    80,    -1,    -1,    78,    -1,
      79,    -1,    96,    18,    87,    -1,    48,    20,   100,    21,
      -1,    74,    -1,    34,    87,    43,    76,    -1,    34,    87,
      43,    76,    30,    76,    -1,    47,    87,    29,    76,    -1,
      -1,    32,    48,    81,    18,    87,    44,    87,    29,    76,
      -1,    48,    -1,    35,    22,    86,    19,    86,    23,    38,
      82,    -1,    42,    84,    31,    -1,    48,    -1,    -1,    85,
      -1,   102,    16,    82,    -1,   102,    16,    82,    17,    85,
      -1,   103,    49,    -1,    49,    -1,    89,    -1,    89,    88,
      89,    -1,     3,    -1,     8,    -1,     6,    -1,     7,    -1,
       5,    -1,     4,    -1,   103,    90,    -1,    90,    -1,    92,
      -1,    92,    91,    90,    -1,    10,    -1,    11,    -1,    39,
      -1,    94,    -1,    94,    93,    92,    -1,    12,    -1,    28,
      -1,    36,    -1,    25,    -1,    49,    -1,    50,    -1,    96,
      -1,    95,    -1,    37,    94,    -1,    20,    87,    21,    -1,
      48,    20,   100,    21,    -1,    -1,    48,    97,    98,    -1,
      -1,    -1,    14,    48,    99,    98,    -1,    22,    87,    23,
      98,    -1,    -1,   101,    -1,    87,    -1,    87,    15,   101,
      -1,    48,    -1,    48,    15,   102,    -1,    10,    -1,    11,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,    97,    98,    99,   100,   101,   102,   103,
     106,   109,   110,   113,   116,   119,   120,   123,   126,   126,
     127,   127,   130,   131,   134,   135,   138,   138,   139,   139,
     142,   142,   143,   143,   146,   147,   150,   151,   154,   155,
     158,   161,   162,   165,   166,   169,   170,   171,   174,   177,
     180,   181,   182,   183,   184,   184,   187,   188,   189,   192,
     195,   196,   199,   200,   203,   204,   207,   208,   211,   212,
     213,   214,   215,   216,   219,   220,   223,   224,   227,   228,
     229,   232,   233,   236,   237,   238,   239,   242,   243,   244,
     245,   246,   247,   250,   253,   253,   256,   257,   257,   258,
     261,   262,   265,   266,   269,   270,   273,   274
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LT", "EQ", "NE", "GT", "GE", "LE",
  "RELOP", "PLUS", "MINUS", "MULTI", "ARIOP", "DOT", "COMMA", "COLON",
  "SEMICOLON", "ASSIGN", "DDOT", "L_BRACE", "R_BRACE", "L_BRACKET",
  "R_BRACKET", "OTHEROP", "ANDSYM", "BEGINSYM", "FORWARDSYM", "DIVSYM",
  "DOSYM", "ELSESYM", "ENDSYM", "FORSYM", "FUNCTIONSYM", "IFSYM",
  "ARRAYSYM", "MODSYM", "NOTSYM", "OFSYM", "ORSYM", "PROCEDURESYM",
  "PROGRAMSYM", "RECORDSYM", "THENSYM", "TOSYM", "TYPESYM", "VARSYM",
  "WHILESYM", "ID", "NUMBER", "STRING", "UNREC", "$accept", "Program",
  "TypeDefinitions", "TypeDefinitionSub", "TypeDefinition",
  "VariableDeclarations", "VariableDeclarationSub", "VariableDeclaration",
  "SubprogramDeclarations", "$@1", "$@2", "ProcedureDeclarationSub",
  "FunctionDeclarationSub", "ProcedureDeclaration", "$@3", "$@4",
  "FunctionDeclaration", "$@5", "$@6", "FormalParameterList",
  "FormalParameterListSub", "Block", "CompoundStatement",
  "StatementSequence", "Statement", "SimpleStatement",
  "AssignmentStatement", "ProcedureStatement", "StructuredStatement",
  "$@7", "Type", "ResultType", "Fieldlist", "FieldlistSub", "Constant",
  "Expression", "RelationalOp", "SimpleExpression", "SimpleExpressionSub",
  "AddOp", "Term", "MulOp", "Factor", "FunctionReference", "Variable",
  "$@8", "ComponentSelection", "$@9", "ActualParameterList",
  "ActualParameterListSub", "Identifierlist", "Sign", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    55,    55,    56,    57,    58,    58,    59,    61,    60,
      62,    60,    63,    63,    64,    64,    66,    65,    67,    65,
      69,    68,    70,    68,    71,    71,    72,    72,    73,    73,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    79,
      80,    80,    80,    80,    81,    80,    82,    82,    82,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      91,    92,    92,    93,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    95,    97,    96,    98,    99,    98,    98,
     100,   100,   101,   101,   102,   102,   103,   103
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     6,     6,     7,     7,     7,     8,
       2,     2,     3,     3,     2,     2,     3,     3,     0,     2,
       0,     2,     2,     2,     2,     2,     0,     8,     0,     8,
       0,    10,     0,    10,     0,     1,     3,     5,     2,     1,
       3,     1,     3,     1,     1,     0,     1,     1,     3,     4,
       1,     4,     6,     4,     0,     9,     1,     8,     3,     1,
       0,     1,     3,     5,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     0,     3,     0,     0,     4,     4,
       0,     1,     1,     3,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    18,    45,     0,     0,    18,
      18,     0,     0,     0,     0,     0,     0,     0,    94,    50,
       0,    41,    43,    46,    47,    44,     0,     0,    10,     0,
     104,    14,     0,     0,    18,     0,     0,     0,     0,     0,
       0,    19,     0,     0,    18,     0,     2,    54,   106,   107,
       0,     0,    94,    87,    88,     0,    66,    75,    76,    81,
      90,    89,     0,     0,   100,    96,    40,    45,     0,     0,
      11,     0,    15,     0,     0,     0,     0,     3,     0,     4,
       5,     0,    23,    22,     0,    25,    24,     0,     0,    91,
     100,    45,    68,    73,    72,    70,    71,    69,     0,    78,
      79,    80,     0,    83,    86,    84,    85,     0,    74,    45,
     102,     0,   101,     0,     0,    95,    42,    48,     0,    60,
      56,    13,    12,   105,    16,    17,     0,     6,     8,     7,
      34,    34,     0,    92,     0,    51,    67,    77,    82,    53,
       0,    49,    97,     0,     0,     0,    61,     0,     9,     0,
      35,     0,     0,     0,    93,    45,   103,    96,    96,    65,
       0,     0,    58,     0,     0,     0,     0,     0,    52,    98,
      99,     0,    64,    62,    26,    36,     0,     0,     0,     0,
       0,     0,     0,    59,     0,    45,     0,    63,     0,    27,
      39,    29,    37,    30,    55,     0,    38,     0,     0,    57,
      31,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     9,    28,    29,   188,    31,    32,    11,    12,
      13,    41,    44,    42,   180,   181,    45,   197,   198,   149,
     150,   189,    19,    20,    21,    22,    23,    24,    25,    87,
     121,   184,   145,   146,   160,   110,    98,    56,    57,   102,
      58,   107,    59,    60,    61,    65,   115,   157,   111,   112,
     151,    62
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -132
static const yytype_int16 yypact[] =
{
     -23,   -22,    33,    24,  -132,    -2,    49,    26,    36,    46,
      25,    35,    38,    52,    68,    40,     0,     0,    66,  -132,
      58,    73,  -132,  -132,  -132,  -132,    76,    87,  -132,    81,
      84,  -132,    83,    86,    25,    35,    89,    35,    90,    93,
      60,    69,    94,    62,    47,   102,  -132,  -132,  -132,  -132,
       0,    18,   100,  -132,  -132,    78,   110,  -132,     6,    34,
    -132,  -132,    18,    97,     0,     5,  -132,    49,     0,   -14,
      26,    36,    36,   -14,    35,   108,   109,  -132,   113,  -132,
    -132,   111,  -132,  -132,   112,  -132,  -132,   115,   107,  -132,
       0,    49,  -132,  -132,  -132,  -132,  -132,  -132,     0,  -132,
    -132,  -132,    18,  -132,  -132,  -132,  -132,    18,  -132,    49,
     114,   116,  -132,    82,     0,  -132,  -132,  -132,   117,    36,
    -132,  -132,  -132,  -132,  -132,  -132,   120,  -132,  -132,  -132,
      36,    36,     0,  -132,   119,   105,  -132,  -132,  -132,  -132,
       0,  -132,  -132,   118,     4,   121,  -132,   122,  -132,   123,
    -132,   126,   124,    92,  -132,    49,  -132,     5,     5,  -132,
     127,    98,  -132,   -14,   131,   -14,   133,     0,  -132,  -132,
    -132,     4,  -132,   136,   128,   137,    95,   129,   134,    36,
      10,   135,    36,  -132,   139,    49,   125,  -132,    35,  -132,
    -132,  -132,  -132,   138,  -132,   -14,  -132,    10,   140,  -132,
    -132,  -132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,    80,  -132,    30,    88,  -132,    13,  -132,
    -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,  -132,    37,
     -21,   -33,    -5,    99,   -84,  -132,  -132,  -132,  -132,  -132,
     -70,  -132,  -132,   -10,    -1,    -8,  -132,    75,   -50,  -132,
      64,  -132,   142,  -132,    -4,  -132,   -81,  -132,    96,    39,
      -7,  -131
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -33
static const yytype_int16 yytable[] =
{
      14,    33,    26,   125,    36,    38,    39,   135,    55,    63,
      48,    49,   108,   161,    48,    49,    99,   100,     1,   113,
      50,   118,    35,    37,     6,   139,     3,   114,   119,    75,
      76,   -20,    78,     4,   120,    10,     6,    51,    50,    34,
     161,     5,    88,     7,     8,   101,   103,    74,    52,    53,
      54,     6,   137,   159,    82,    51,     8,    85,   -20,   104,
     117,     6,   105,    26,   123,    33,    52,    53,    54,   126,
     106,   168,     6,   -21,    27,     6,   169,   170,    40,   -20,
     -20,    15,    46,    16,    30,    43,    64,    26,    47,    66,
      67,    69,     8,   173,    68,   175,    17,    18,    70,    71,
      72,   194,    73,    77,    79,    26,   143,    80,    81,   -18,
      84,    83,   147,    92,    93,    94,    95,    96,    97,    86,
      90,    91,   127,   128,   153,   199,   109,   129,   133,   140,
     142,   130,   131,   132,   148,   155,   167,   141,   163,   144,
     154,   158,   165,   183,   164,   166,   171,   172,   174,   176,
     122,    26,   162,   179,   182,   -28,   193,   186,   185,   177,
     124,   192,   191,   195,   200,   -32,   116,   201,   152,   187,
     178,   138,   147,   136,     0,   190,     0,     0,     0,   156,
       0,    26,     0,   196,     0,     0,   134,     0,     0,     0,
       0,     0,   190,    89
};

static const yytype_int16 yycheck[] =
{
       5,     8,     6,    73,     9,    10,    11,    91,    16,    17,
      10,    11,    62,   144,    10,    11,    10,    11,    41,    14,
      20,    35,     9,    10,    26,   109,    48,    22,    42,    34,
      35,    33,    37,     0,    48,     5,    26,    37,    20,     9,
     171,    17,    50,    45,    46,    39,    12,    34,    48,    49,
      50,    26,   102,    49,    41,    37,    46,    44,    33,    25,
      68,    26,    28,    67,    71,    72,    48,    49,    50,    74,
      36,   155,    26,    26,    48,    26,   157,   158,    40,    33,
      33,    32,    14,    34,    48,    33,    20,    91,    48,    31,
      17,     4,    46,   163,    18,   165,    47,    48,    17,    15,
      17,   185,    16,    14,    14,   109,   114,    14,    48,    40,
      48,    17,   119,     3,     4,     5,     6,     7,     8,    17,
      20,    43,    14,    14,   132,   195,    29,    14,    21,    15,
      48,    20,    20,    18,    14,    30,    44,    21,    16,    22,
      21,    23,    16,    48,    21,    21,    19,    49,    17,    16,
      70,   155,    31,    17,    17,    27,    17,    23,    29,   167,
      72,   182,    27,    38,   197,    27,    67,    27,   131,   179,
     171,   107,   179,    98,    -1,   180,    -1,    -1,    -1,   140,
      -1,   185,    -1,   188,    -1,    -1,    90,    -1,    -1,    -1,
      -1,    -1,   197,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    53,    48,     0,    17,    26,    45,    46,    54,
      57,    60,    61,    62,    74,    32,    34,    47,    48,    74,
      75,    76,    77,    78,    79,    80,    96,    48,    55,    56,
      48,    58,    59,   102,    57,    60,    74,    60,    74,    74,
      40,    63,    65,    33,    64,    68,    14,    48,    10,    11,
      20,    37,    48,    49,    50,    87,    89,    90,    92,    94,
      95,    96,   103,    87,    20,    97,    31,    17,    18,     4,
      17,    15,    17,    16,    60,    74,    74,    14,    74,    14,
      14,    48,    60,    17,    48,    60,    17,    81,    87,    94,
      20,    43,     3,     4,     5,     6,     7,     8,    88,    10,
      11,    39,    91,    12,    25,    28,    36,    93,    90,    29,
      87,   100,   101,    14,    22,    98,    75,    87,    35,    42,
      48,    82,    55,   102,    58,    82,    74,    14,    14,    14,
      20,    20,    18,    21,   100,    76,    89,    90,    92,    76,
      15,    21,    48,    87,    22,    84,    85,   102,    14,    71,
      72,   102,    71,    87,    21,    30,   101,    99,    23,    49,
      86,   103,    31,    16,    21,    16,    21,    44,    76,    98,
      98,    19,    49,    82,    17,    82,    16,    87,    86,    17,
      66,    67,    17,    48,    83,    29,    23,    85,    57,    73,
      74,    27,    72,    17,    76,    38,    74,    69,    70,    82,
      73,    27
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
#line 96 "s4.y"
    {install_id((yyvsp[(2) - (5)].idtype));set_id_type((yyvsp[(2) - (5)].idtype),"program"); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 97 "s4.y"
    {install_id((yyvsp[(2) - (6)].idtype)); set_id_type((yyvsp[(2) - (6)].idtype),"program");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 98 "s4.y"
    {install_id((yyvsp[(2) - (6)].idtype)); set_id_type((yyvsp[(2) - (6)].idtype),"program");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 99 "s4.y"
    {install_id((yyvsp[(2) - (6)].idtype));set_id_type((yyvsp[(2) - (6)].idtype),"program"); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 100 "s4.y"
    {install_id((yyvsp[(2) - (7)].idtype)); set_id_type((yyvsp[(2) - (7)].idtype),"program");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 101 "s4.y"
    {install_id((yyvsp[(2) - (7)].idtype));set_id_type((yyvsp[(2) - (7)].idtype),"program"); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 102 "s4.y"
    {install_id((yyvsp[(2) - (7)].idtype)); set_id_type((yyvsp[(2) - (7)].idtype),"program");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 103 "s4.y"
    {install_id((yyvsp[(2) - (8)].idtype));set_id_type((yyvsp[(2) - (8)].idtype),"program"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 113 "s4.y"
    {check_multi_def((yyvsp[(1) - (3)].idtype)); install_id((yyvsp[(1) - (3)].idtype)); set_id_type((yyvsp[(1) - (3)].idtype),(yyvsp[(3) - (3)].strtype));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 123 "s4.y"
    {install_ids((yyvsp[(1) - (3)].idtype),(yyvsp[(3) - (3)].strtype));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 126 "s4.y"
    {set_new_scope(top);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 126 "s4.y"
    {release_scope();;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 127 "s4.y"
    {set_new_scope(top);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 127 "s4.y"
    {release_scope();;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 138 "s4.y"
    {install_func((yyvsp[(2) - (6)].idtype),"procedure");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 139 "s4.y"
    {install_func((yyvsp[(2) - (6)].idtype),"procedure");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 142 "s4.y"
    {install_func((yyvsp[(2) - (8)].idtype),(yyvsp[(7) - (8)].idtype)->lexeme);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 143 "s4.y"
    {install_func((yyvsp[(2) - (8)].idtype),(yyvsp[(7) - (8)].idtype)->lexeme);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 146 "s4.y"
    {;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 150 "s4.y"
    { install_ids((yyvsp[(1) - (3)].idtype),(yyvsp[(3) - (3)].strtype));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 151 "s4.y"
    { install_ids((yyvsp[(1) - (5)].idtype),(yyvsp[(3) - (5)].strtype)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 174 "s4.y"
    {char* type = get_id_type((yyvsp[(1) - (3)].idtype)); check_type_equal(type,(yyvsp[(3) - (3)].strtype),(yyvsp[(1) - (3)].idtype)->lexeme);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 177 "s4.y"
    {install_id((yyvsp[(1) - (4)].idtype));;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 184 "s4.y"
    {check_undeclared_var((yyvsp[(2) - (2)].idtype));}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 184 "s4.y"
    {char* type = get_id_type((yyvsp[(2) - (9)].idtype)); check_type_equal(type,(yyvsp[(5) - (9)].strtype),(yyvsp[(2) - (9)].idtype)->lexeme);check_type_equal(type,(yyvsp[(7) - (9)].strtype),(yyvsp[(2) - (9)].idtype)->lexeme);;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 187 "s4.y"
    {check_undeclared_var((yyvsp[(1) - (1)].idtype)); (yyval.strtype) = (yyvsp[(1) - (1)].idtype)->lexeme;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 188 "s4.y"
    { (yyval.strtype) = get_array_type((yyvsp[(3) - (8)].num),(yyvsp[(5) - (8)].num),(yyvsp[(8) - (8)].strtype));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 189 "s4.y"
    { (yyval.strtype) = strconn("record",(yyvsp[(2) - (3)].strtype)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 192 "s4.y"
    {check_undeclared_var((yyvsp[(1) - (1)].idtype));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 195 "s4.y"
    {(yyval.strtype)=NULL;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 199 "s4.y"
    {(yyval.strtype) = get_record_type((yyvsp[(1) - (3)].idtype),(yyvsp[(3) - (3)].strtype));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 200 "s4.y"
    {(yyval.strtype) = strconn(get_record_type((yyvsp[(1) - (5)].idtype),(yyvsp[(3) - (5)].strtype)),(yyvsp[(5) - (5)].strtype));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 203 "s4.y"
    {(yyval.num) = to_num((yyvsp[(1) - (2)].num),(yyvsp[(2) - (2)].strtype));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 204 "s4.y"
    {(yyval.num) = to_num('+',(yyvsp[(1) - (1)].strtype));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 219 "s4.y"
    {(yyval.strtype) = (yyvsp[(2) - (2)].strtype);}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 242 "s4.y"
    {(yyval.strtype) = "integer";;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 243 "s4.y"
    {(yyval.strtype) = "string";;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 244 "s4.y"
    {(yyval.strtype) = get_id_type((yyvsp[(1) - (1)].idtype));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 245 "s4.y"
    {(yyval.strtype) = get_id_type((yyvsp[(1) - (1)].idtype));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 246 "s4.y"
    {(yyval.strtype) = (yyvsp[(2) - (2)].strtype);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 247 "s4.y"
    {(yyval.strtype) = (yyvsp[(2) - (3)].strtype);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 250 "s4.y"
    {;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 253 "s4.y"
    {check_undeclared_var((yyvsp[(1) - (1)].idtype));;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 257 "s4.y"
    {check_undeclared_var((yyvsp[(2) - (2)].idtype));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 270 "s4.y"
    {(yyval.idtype) = new_id((yyvsp[(1) - (3)].idtype)->lexeme , (yyvsp[(3) - (3)].idtype)); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 273 "s4.y"
    {(yyval.num) = '+';;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 274 "s4.y"
    {(yyval.num) = '-';;}
    break;



/* Line 1455 of yacc.c  */
#line 1934 "s4.tab.c"
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
#line 276 "s4.y"

int main(int argc, char *argv[])
{
    ++argv, --argc;    /* skip argv[0] */
    if (argc > 0) {
        yyin = fopen(argv[0], "r");
    } else {
        yyin = stdin;
    }
    printf("\n\nStart parsing...:\n\n");
    //initialize top symbol table
    set_new_scope(NULL);
    yyparse();
    release_scope();
    return 0;
};

yyerror(char *s)
{
  fprintf(stderr, "error: %s\n", s);
};

void install_func(struct id* func, char* lexeme){
  char* type = get_type_from_symtab(lexeme);
  struct symtable* scp = top;
  while(top != NULL){
    install_id(func);
    set_id_type(func,type);
    top = top->parent;
  }
  top = scp;
}

struct id* new_id(char* lexeme, struct id* next){
  struct id* i = malloc(sizeof(struct id));
  i->lexeme = lexeme;
  i->next = next;
  return i;
}

void install_ids(struct id* ids, char* type){
  struct id* tmpid = ids;
  while(tmpid != NULL){
    int success = check_multi_def(tmpid);
    if(success){
      install_id(tmpid);
      set_id_type(tmpid,type);
    }
    tmpid = tmpid->next;
  }
}

void install_id(struct id* id){
  struct id* tmpid = id;
  if(tmpid!=NULL){
    int index = install_id_lexeme(tmpid->lexeme);
    tmpid->index = index;
  }
}

int install_id_lexeme(char* idstr){
int i;
 for(i=0;i<(top->count);i++){
  if(!strcmp(top->entity[i].value,idstr)){
   //already exists in symbol table
   return i;
  }
 }
 int index = (top->count);
 top->entity[index].value = idstr;
 top->entity[index].property = "ID";
 (top->count)++;
 return index;
}

void set_id_type(struct id* id, char* type){
  char* realType = get_type_from_symtab(type);
  top->entity[id->index].type = realType;
  id->type = realType;
}

char* get_id_type(struct id* id){
 struct symtable* scp = top;
 while(scp != NULL){
	  int i;
	  for(i=0;i<(scp->count);i++){
		if(!strcmp(scp->entity[i].value,id->lexeme)){
		    return scp->entity[i].type;
		}
	  }
	scp = scp->parent;
 }
 return NULL;
}

char* get_type_from_symtab(char* type){
 struct symtable* scp = top;
 while(scp != NULL){
	  int i;
	  for(i=0;i<(scp->count);i++){
		if(!strcmp(scp->entity[i].value,type)){
		  if(scp->entity[i].type == NULL){
		    return type;
		  } else{
		    return get_type_from_symtab(scp->entity[i].type);
		  }
		}
	  }
	scp = scp->parent;
 }
 return type;
}

void set_new_scope(struct symtable* parent){
  //printf("Enter new scope\n");
 struct symtable* newscope = malloc(sizeof(struct symtable));
 newscope->parent = parent;
 newscope->count = 0;
 top = newscope;
 //predefine type
 install_id_lexeme("integer");
 install_id_lexeme("string");
 install_id_lexeme("boolean");
 install_id_lexeme("array");
 install_id_lexeme("record");
 install_id_lexeme("true");
 install_id_lexeme("false");
}

void release_scope(){
  // printf("Exit new scope\n");
  /*
    printf("\n\nSymbol Table:\n");
    int i;
    for(i=0;i<top->count;i++){
      printf("entry: %3d, symbol: %12s, property: %3s, type: %4s \n",i,top->entity[i].value,top->entity[i].property,top->entity[i].type);
    }
  */
 top = top->parent;
}

void check_undeclared_var(struct id* id){
  char* idstr =  id->lexeme;
 //check if declared already
 struct symtable* scp = top;
 while(scp != NULL){
	  int i;
	  for(i=0;i<(scp->count);i++){
		if(!strcmp(scp->entity[i].value,idstr)){
		   //already exists in symbol table
		   return;
		}
	  }
	scp = scp->parent;
 }
 printf("Error: Variable '%s': undeclared variable\n",idstr);
}

int check_multi_def(struct id* id){
 int i;
 for(i=0;i<(top->count);i++){
  if(!strcmp(top->entity[i].value,id->lexeme)){
   //already exists in symbol table
   printf("Error: Variable '%s': multiple declaration\n",id->lexeme);
   return false;
  }
 }
 return true;
}

char* get_array_type(int a,int b,char* type) {
    char buf[256];
    snprintf(buf, sizeof buf, "%s%d%s%d", "array", a, get_type_from_symtab(type), b);
    return strdup(buf);
}

char* get_record_type(struct id* ids, char* type){
    struct id* tmpid = ids;
    char* res = "";
    while(tmpid != NULL){
      res = strconn(res,tmpid->lexeme);
      res = strconn(res,get_type_from_symtab(type));
      tmpid = tmpid->next;
    }
    return strdup(res);
}

int to_num(char sign,char* value){
    if('-' == sign){
      return 0 - atoi(value);
    } else {
      return atoi(value);
    }
}

void check_type_equal(char* v1, char* v2, char* l1){
  //  printf("%s%s\n",v1,v2);
  if(v1!=NULL&&v2!=NULL&&strcmp(v1,v2)){
    printf("Error: unequivalent types: %s is of type %s, cannot be assigned to type %s\n",l1, v1,v2);
  }
}

char* strconn(char* s1, char* s2){
    char buf[9999];
    snprintf(buf, sizeof buf, "%s%s", s1,s2);
    return strdup(buf);
}

