
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 75 "s4.y"

  struct id* idtype;
  int num;
  char* strtype;
  struct condition* condition;



/* Line 1676 of yacc.c  */
#line 112 "s4.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


