/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_INT = 258,
     TOK_CHAR = 259,
     TOK_LONG = 260,
     TOK_UNSIGNED = 261,
     TOK_FLOAT = 262,
     TOK_DOUBLE = 263,
     TOK_SIGNED = 264,
     TOK_SHORT = 265,
     TOK_CONST = 266,
     TOK_WHILE = 267,
     TOK_IF = 268,
     TOK_GOTO = 269,
     TOK_TYPEDEF = 270,
     TOK_ENUM = 271,
     TOK_UNION = 272,
     TOK_STRUCT = 273,
     TOK_STATIC = 274,
     TOK_REGISTER = 275,
     TOK_AUTO = 276,
     TOK_SWITCH = 277,
     TOK_CASE = 278,
     TOK_BREAK = 279,
     TOK_CONTINUE = 280,
     TOK_DEFAULT = 281,
     TOK_RETURN = 282,
     TOK_EXTERN = 283,
     TOK_VOID = 284,
     TOK_ELSE = 285,
     TOK_IDENT = 286,
     TOK_FPNUM = 287,
     TOK_INTNUM = 288,
     TOK_UINTNUM = 289,
     TOK_STRING = 290,
     TOK_CHARVAL = 291,
     TOK_EQ = 292,
     TOK_GE = 293,
     TOK_MINUSEQ = 294,
     TOK_MINMIN = 295,
     TOK_LAND = 296,
     TOK_LOR = 297,
     TOK_PLUSEQ = 298,
     TOK_MULTEQ = 299,
     TOK_DIVEQ = 300,
     TOK_LSHIFT = 301,
     TOK_RSHIFT = 302,
     TOK_ARROW = 303,
     TOK_LISHIFTEQ = 304,
     TOK_XOREQ = 305,
     TOK_LE = 306,
     TOK_PLUSPLUS = 307,
     TOK_OREQ = 308,
     TOK_ANDEQ = 309,
     TOK_ELLIPSIS = 310,
     TOK_FOR = 311,
     TOK_NE = 312,
     TOK_LSHIFTEQ = 313,
     TOK_VOLATILE = 314,
     TOK_MODEQ = 315,
     TOK_RSHIFTEQ = 316,
     TOK_DO = 317,
     TOK_SIZEOF = 318,
     TYPE_NAME = 319
   };
#endif
/* Tokens.  */
#define TOK_INT 258
#define TOK_CHAR 259
#define TOK_LONG 260
#define TOK_UNSIGNED 261
#define TOK_FLOAT 262
#define TOK_DOUBLE 263
#define TOK_SIGNED 264
#define TOK_SHORT 265
#define TOK_CONST 266
#define TOK_WHILE 267
#define TOK_IF 268
#define TOK_GOTO 269
#define TOK_TYPEDEF 270
#define TOK_ENUM 271
#define TOK_UNION 272
#define TOK_STRUCT 273
#define TOK_STATIC 274
#define TOK_REGISTER 275
#define TOK_AUTO 276
#define TOK_SWITCH 277
#define TOK_CASE 278
#define TOK_BREAK 279
#define TOK_CONTINUE 280
#define TOK_DEFAULT 281
#define TOK_RETURN 282
#define TOK_EXTERN 283
#define TOK_VOID 284
#define TOK_ELSE 285
#define TOK_IDENT 286
#define TOK_FPNUM 287
#define TOK_INTNUM 288
#define TOK_UINTNUM 289
#define TOK_STRING 290
#define TOK_CHARVAL 291
#define TOK_EQ 292
#define TOK_GE 293
#define TOK_MINUSEQ 294
#define TOK_MINMIN 295
#define TOK_LAND 296
#define TOK_LOR 297
#define TOK_PLUSEQ 298
#define TOK_MULTEQ 299
#define TOK_DIVEQ 300
#define TOK_LSHIFT 301
#define TOK_RSHIFT 302
#define TOK_ARROW 303
#define TOK_LISHIFTEQ 304
#define TOK_XOREQ 305
#define TOK_LE 306
#define TOK_PLUSPLUS 307
#define TOK_OREQ 308
#define TOK_ANDEQ 309
#define TOK_ELLIPSIS 310
#define TOK_FOR 311
#define TOK_NE 312
#define TOK_LSHIFTEQ 313
#define TOK_VOLATILE 314
#define TOK_MODEQ 315
#define TOK_RSHIFTEQ 316
#define TOK_DO 317
#define TOK_SIZEOF 318
#define TYPE_NAME 319




/* Copy the first part of user declarations.  */
#line 1 "csynan.yxx"

/*
Copyright (c) 1997-2007, Václav Haisman

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <iostream>

#define YYPARSE_PARAM ptr 
#define YYERROR_VERBOSE 1
#define YYDEBUG 1

char* filename = "";
extern int yylex (void);
void yyerror (char *s);

#include "ast.hxx"
#include "defines.hxx"
#include "lexan.hxx"


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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 276 "csynan.cxx"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1448

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  216
/* YYNRULES -- Number of states.  */
#define YYNSTATES  354

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    76,     2,     2,     2,    78,    71,     2,
      65,    66,    72,    73,    70,    74,    69,    77,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,    86,
      79,    85,    80,    83,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    67,     2,    68,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    87,    82,    88,    75,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    17,    19,
      21,    23,    28,    32,    37,    41,    45,    48,    51,    53,
      57,    59,    62,    65,    68,    71,    76,    78,    80,    82,
      84,    86,    88,    90,    95,    97,   101,   105,   109,   111,
     115,   119,   121,   125,   129,   131,   135,   139,   143,   147,
     149,   153,   157,   159,   163,   165,   169,   171,   175,   177,
     181,   183,   187,   189,   195,   197,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   219,   221,   223,   225,   229,
     231,   234,   238,   240,   243,   245,   248,   250,   253,   255,
     259,   261,   265,   267,   269,   271,   273,   275,   277,   279,
     281,   283,   285,   287,   289,   291,   293,   295,   297,   299,
     305,   310,   313,   315,   317,   319,   322,   326,   329,   331,
     334,   336,   338,   342,   344,   347,   351,   356,   362,   365,
     367,   371,   373,   377,   379,   381,   384,   386,   388,   392,
     397,   401,   406,   411,   415,   417,   420,   423,   427,   429,
     432,   434,   438,   440,   444,   447,   450,   452,   454,   458,
     460,   463,   465,   467,   470,   474,   477,   481,   485,   490,
     493,   497,   501,   506,   508,   512,   517,   519,   523,   525,
     527,   529,   531,   533,   535,   539,   544,   548,   551,   555,
     559,   564,   566,   569,   571,   574,   576,   579,   585,   593,
     599,   605,   613,   620,   628,   632,   635,   638,   641,   645,
     647,   650,   652,   654,   659,   663,   667
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     151,     0,    -1,    31,    -1,    91,    -1,    35,    -1,    65,
     110,    66,    -1,    32,    -1,    33,    -1,    34,    -1,    36,
      -1,    90,    -1,    92,    67,   110,    68,    -1,    92,    65,
      66,    -1,    92,    65,    93,    66,    -1,    92,    69,    31,
      -1,    92,    48,    31,    -1,    92,    52,    -1,    92,    40,
      -1,   108,    -1,    93,    70,   108,    -1,    92,    -1,    52,
      94,    -1,    40,    94,    -1,    95,    96,    -1,    63,    94,
      -1,    63,    65,   137,    66,    -1,    71,    -1,    72,    -1,
      73,    -1,    74,    -1,    75,    -1,    76,    -1,    94,    -1,
      65,   137,    66,    96,    -1,    96,    -1,    97,    72,    96,
      -1,    97,    77,    96,    -1,    97,    78,    96,    -1,    97,
      -1,    98,    73,    97,    -1,    98,    74,    97,    -1,    98,
      -1,    99,    46,    98,    -1,    99,    47,    98,    -1,    99,
      -1,   100,    79,    99,    -1,   100,    80,    99,    -1,   100,
      51,    99,    -1,   100,    38,    99,    -1,   100,    -1,   101,
      37,   100,    -1,   101,    57,   100,    -1,   101,    -1,   102,
      71,   101,    -1,   102,    -1,   103,    81,   102,    -1,   103,
      -1,   104,    82,   103,    -1,   104,    -1,   105,    41,   104,
      -1,   105,    -1,   106,    42,   105,    -1,   106,    -1,   106,
      83,   110,    84,   107,    -1,   107,    -1,    94,   109,   108,
      -1,    85,    -1,    44,    -1,    45,    -1,    60,    -1,    43,
      -1,    39,    -1,    58,    -1,    61,    -1,    54,    -1,    50,
      -1,    53,    -1,   108,    -1,   110,    70,   108,    -1,   107,
      -1,   113,    86,    -1,   113,   114,    86,    -1,   116,    -1,
     116,   113,    -1,   117,    -1,   117,   113,    -1,   128,    -1,
     128,   113,    -1,   115,    -1,   115,    70,   114,    -1,   129,
      -1,   129,    85,   140,    -1,    15,    -1,    28,    -1,    19,
      -1,    21,    -1,    20,    -1,    29,    -1,     4,    -1,    10,
      -1,     3,    -1,     5,    -1,     7,    -1,     8,    -1,     9,
      -1,     6,    -1,   118,    -1,   125,    -1,    64,    -1,   119,
      31,    87,   120,    88,    -1,   119,    87,   120,    88,    -1,
     119,    31,    -1,    18,    -1,    17,    -1,   121,    -1,   120,
     121,    -1,   122,   123,    86,    -1,   117,   122,    -1,   117,
      -1,   128,   122,    -1,   128,    -1,   124,    -1,   123,    70,
     124,    -1,   129,    -1,    84,   111,    -1,   129,    84,   111,
      -1,    16,    87,   126,    88,    -1,    16,    31,    87,   126,
      88,    -1,    16,    31,    -1,   127,    -1,   126,    70,   127,
      -1,    31,    -1,    31,    85,   111,    -1,    11,    -1,    59,
      -1,   131,   130,    -1,   130,    -1,    31,    -1,    65,   129,
      66,    -1,   130,    67,   111,    68,    -1,   130,    67,    68,
      -1,   130,    65,   133,    66,    -1,   130,    65,   136,    66,
      -1,   130,    65,    66,    -1,    72,    -1,    72,   132,    -1,
      72,   131,    -1,    72,   132,   131,    -1,   128,    -1,   132,
     128,    -1,   134,    -1,   134,    70,    55,    -1,   135,    -1,
     134,    70,   135,    -1,   113,   129,    -1,   113,   138,    -1,
     113,    -1,    31,    -1,   136,    70,    31,    -1,   122,    -1,
     122,   138,    -1,   131,    -1,   139,    -1,   131,   139,    -1,
      65,   138,    66,    -1,    67,    68,    -1,    67,   111,    68,
      -1,   139,    67,    68,    -1,   139,    67,   111,    68,    -1,
      65,    66,    -1,    65,   133,    66,    -1,   139,    65,    66,
      -1,   139,    65,   133,    66,    -1,   108,    -1,    87,   141,
      88,    -1,    87,   141,    70,    88,    -1,   140,    -1,   141,
      70,   140,    -1,   143,    -1,   144,    -1,   147,    -1,   148,
      -1,   149,    -1,   150,    -1,    31,    84,   142,    -1,    23,
     111,    84,   142,    -1,    26,    84,   142,    -1,    87,    88,
      -1,    87,   146,    88,    -1,    87,   145,    88,    -1,    87,
     145,   146,    88,    -1,   112,    -1,   112,   145,    -1,   142,
      -1,   142,   146,    -1,    86,    -1,   110,    86,    -1,    13,
      65,   110,    66,   142,    -1,    13,    65,   110,    66,   142,
      30,   142,    -1,    22,    65,   110,    66,   142,    -1,    12,
      65,   110,    66,   142,    -1,    62,   142,    12,    65,   110,
      66,    86,    -1,    56,    65,   147,   147,    66,   142,    -1,
      56,    65,   147,   147,   110,    66,   142,    -1,    14,    31,
      86,    -1,    25,    86,    -1,    24,    86,    -1,    27,    86,
      -1,    27,   110,    86,    -1,   152,    -1,   151,   152,    -1,
     153,    -1,   112,    -1,   113,   129,   145,   144,    -1,   113,
     129,   144,    -1,   129,   145,   144,    -1,   129,   144,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    63,    68,    73,    80,    85,    90,    95,
     102,   107,   112,   117,   122,   127,   132,   137,   144,   149,
     156,   161,   166,   171,   176,   181,   188,   193,   198,   203,
     208,   213,   220,   225,   230,   235,   240,   245,   252,   257,
     262,   269,   274,   279,   286,   291,   296,   301,   306,   313,
     318,   323,   330,   335,   342,   347,   354,   359,   366,   371,
     378,   383,   390,   395,   402,   407,   418,   423,   428,   433,
     438,   443,   448,   453,   458,   463,   468,   475,   480,   487,
     494,   499,   506,   511,   516,   521,   526,   531,   538,   544,
     552,   557,   564,   565,   566,   567,   568,   572,   577,   582,
     587,   592,   597,   602,   607,   612,   617,   622,   627,   634,
     639,   644,   651,   652,   656,   657,   661,   665,   666,   667,
     668,   672,   673,   677,   678,   679,   683,   684,   685,   689,
     690,   694,   695,   699,   700,   704,   709,   716,   721,   726,
     731,   736,   742,   748,   755,   756,   757,   758,   762,   763,
     767,   768,   772,   773,   777,   778,   779,   783,   784,   788,
     789,   793,   798,   803,   810,   811,   812,   813,   814,   815,
     816,   817,   818,   822,   827,   832,   839,   840,   844,   849,
     854,   859,   864,   869,   876,   881,   887,   895,   901,   906,
     911,   919,   925,   934,   940,   949,   954,   961,   966,   971,
     979,   985,   990,   995,  1002,  1007,  1012,  1017,  1022,  1030,
    1031,  1035,  1040,  1047,  1052,  1057,  1062
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_INT", "TOK_CHAR", "TOK_LONG",
  "TOK_UNSIGNED", "TOK_FLOAT", "TOK_DOUBLE", "TOK_SIGNED", "TOK_SHORT",
  "TOK_CONST", "TOK_WHILE", "TOK_IF", "TOK_GOTO", "TOK_TYPEDEF",
  "TOK_ENUM", "TOK_UNION", "TOK_STRUCT", "TOK_STATIC", "TOK_REGISTER",
  "TOK_AUTO", "TOK_SWITCH", "TOK_CASE", "TOK_BREAK", "TOK_CONTINUE",
  "TOK_DEFAULT", "TOK_RETURN", "TOK_EXTERN", "TOK_VOID", "TOK_ELSE",
  "TOK_IDENT", "TOK_FPNUM", "TOK_INTNUM", "TOK_UINTNUM", "TOK_STRING",
  "TOK_CHARVAL", "TOK_EQ", "TOK_GE", "TOK_MINUSEQ", "TOK_MINMIN",
  "TOK_LAND", "TOK_LOR", "TOK_PLUSEQ", "TOK_MULTEQ", "TOK_DIVEQ",
  "TOK_LSHIFT", "TOK_RSHIFT", "TOK_ARROW", "TOK_LISHIFTEQ", "TOK_XOREQ",
  "TOK_LE", "TOK_PLUSPLUS", "TOK_OREQ", "TOK_ANDEQ", "TOK_ELLIPSIS",
  "TOK_FOR", "TOK_NE", "TOK_LSHIFTEQ", "TOK_VOLATILE", "TOK_MODEQ",
  "TOK_RSHIFTEQ", "TOK_DO", "TOK_SIZEOF", "TYPE_NAME", "'('", "')'", "'['",
  "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'",
  "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'",
  "'}'", "$accept", "primary_expression", "constant", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,    40,    41,    91,    93,    46,
      44,    38,    42,    43,    45,   126,    33,    47,    37,    60,
      62,    94,   124,    63,    58,    61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    90,    90,    90,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      95,    95,    96,    96,    97,    97,    97,    97,    98,    98,
      98,    99,    99,    99,   100,   100,   100,   100,   100,   101,
     101,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   110,   110,   111,
     112,   112,   113,   113,   113,   113,   113,   113,   114,   114,
     115,   115,   116,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     118,   118,   119,   119,   120,   120,   121,   122,   122,   122,
     122,   123,   123,   124,   124,   124,   125,   125,   125,   126,
     126,   127,   127,   128,   128,   129,   129,   130,   130,   130,
     130,   130,   130,   130,   131,   131,   131,   131,   132,   132,
     133,   133,   134,   134,   135,   135,   135,   136,   136,   137,
     137,   138,   138,   138,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   140,   140,   140,   141,   141,   142,   142,
     142,   142,   142,   142,   143,   143,   143,   144,   144,   144,
     144,   145,   145,   146,   146,   147,   147,   148,   148,   148,
     149,   149,   149,   149,   150,   150,   150,   150,   150,   151,
     151,   152,   152,   153,   153,   153,   153
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     4,     3,     4,     3,     3,     2,     2,     1,     3,
       1,     2,     2,     2,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     3,     1,     2,     1,     2,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       4,     2,     1,     1,     1,     2,     3,     2,     1,     2,
       1,     1,     3,     1,     2,     3,     4,     5,     2,     1,
       3,     1,     3,     1,     1,     2,     1,     1,     3,     4,
       3,     4,     4,     3,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     2,     2,     1,     1,     3,     1,
       2,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     3,     4,     1,     3,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     3,     3,
       4,     1,     2,     1,     2,     1,     2,     5,     7,     5,
       5,     7,     6,     7,     3,     2,     2,     2,     3,     1,
       2,     1,     1,     4,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   100,    98,   101,   105,   102,   103,   104,    99,   133,
      92,     0,   113,   112,    94,    96,    95,    93,    97,   137,
     134,   108,     0,   144,   212,     0,    82,    84,   106,     0,
     107,    86,     0,   136,     0,     0,   209,   211,   128,     0,
       0,   148,   146,   145,    80,     0,    88,    90,    83,    85,
     111,     0,    87,     0,   191,     0,   216,     0,     0,     0,
     135,     1,   210,     0,   131,     0,   129,   138,   149,   147,
      81,     0,     0,   214,     0,     0,   118,     0,   114,     0,
     120,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     6,     7,     8,     4,     9,     0,     0,     0,     0,
       0,     0,    26,    27,    28,    29,    30,    31,   195,   187,
      10,     3,    20,    32,     0,    34,    38,    41,    44,    49,
      52,    54,    56,    58,    60,    62,    64,    77,     0,   193,
     178,   179,     0,     0,   180,   181,   182,   183,   192,    90,
     215,   157,   143,   156,     0,   150,   152,     0,     2,   140,
      32,    79,     0,     0,     0,     0,   126,    89,     0,   173,
      91,   213,     0,   117,   110,   115,     0,     0,   121,   123,
     119,     0,     0,     0,     0,     0,   206,   205,     0,   207,
       0,     0,     0,    22,    21,     0,     0,     0,    24,     0,
     159,     0,    17,     0,    16,     0,     0,     0,    71,    70,
      67,    68,    75,    76,    74,    72,    69,    73,    66,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,   194,   189,     0,   188,     0,     0,   154,   161,
     155,   162,   141,     0,   142,     0,   139,   127,   132,   130,
     176,     0,   109,   124,     0,   116,     0,     0,     0,   204,
       0,     0,   186,   208,   184,     0,     0,     0,     5,     0,
     161,   160,     0,    15,    12,     0,    18,     0,    14,    65,
      35,    36,    37,    39,    40,    42,    43,    48,    47,    45,
      46,    50,    51,    53,    55,    57,    59,    61,     0,    78,
     190,   169,     0,     0,   165,     0,   163,     0,     0,   151,
     153,   158,     0,   174,   122,   125,     0,     0,     0,   185,
       0,     0,    25,    33,    13,     0,    11,     0,   170,   164,
     166,   171,     0,   167,     0,   175,   177,   200,   197,   199,
       0,     0,     0,    19,    63,   172,   168,     0,   202,     0,
       0,   198,   203,   201
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   110,   111,   112,   275,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     209,   128,   152,    54,   143,    45,    46,    26,    27,    28,
      29,    77,    78,    79,   167,   168,    30,    65,    66,    31,
      32,    33,    34,    43,   302,   145,   146,   147,   191,   303,
     241,   160,   251,   129,   130,   131,    57,   133,   134,   135,
     136,   137,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -210
static const yytype_int16 yypact[] =
{
     803,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,   -24,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,     5,    -6,  -210,   -14,   994,   994,  -210,   -16,
    -210,   994,   449,   -17,    16,   677,  -210,  -210,   -65,    -2,
     -50,  -210,  -210,    -6,  -210,   -51,    42,   376,  -210,  -210,
     -33,   640,  -210,   270,   994,   -14,  -210,    58,   873,  1145,
     -17,  -210,  -210,    -2,    65,   -46,  -210,  -210,  -210,  -210,
    -210,     5,  1046,  -210,    58,   640,   640,   344,  -210,    -8,
     640,   108,   111,    93,   119,  1312,   114,   125,   121,  1072,
     133,  -210,  -210,  -210,  -210,  -210,  1326,  1326,   157,   526,
    1372,   600,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,   137,   811,  1312,  -210,    59,    13,   147,    -5,
       2,   162,   176,   166,   218,   -10,  -210,  -210,    27,   526,
    -210,  -210,   459,   175,  -210,  -210,  -210,  -210,  -210,   181,
    -210,  -210,  -210,    62,   198,   197,  -210,    51,  -210,  -210,
    -210,  -210,   202,   -45,  1312,    -2,  -210,  -210,  1046,  -210,
    -210,  -210,   360,  -210,  -210,  -210,  1312,    32,  -210,   216,
    -210,  1312,  1312,   221,  1312,   224,  -210,  -210,   526,  -210,
      40,   526,  1312,  -210,  -210,  1119,   297,   600,  -210,   116,
      74,   245,  -210,   281,  -210,  1191,  1312,   282,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  1312,
    -210,  1312,  1312,  1312,  1312,  1312,  1312,  1312,  1312,  1312,
    1312,  1312,  1312,  1312,  1312,  1312,  1312,  1312,  1312,  1312,
    1312,  -210,  -210,  -210,   226,  -210,   706,  1206,  -210,    36,
    -210,   167,  -210,   966,  -210,   284,  -210,  -210,  -210,  -210,
    -210,   -39,  -210,  -210,    -8,  -210,  1312,   126,   129,  -210,
     142,   526,  -210,  -210,  -210,  1119,   251,   252,  -210,   776,
     179,  -210,  1312,  -210,  -210,   153,  -210,   177,  -210,  -210,
    -210,  -210,  -210,    59,    59,    13,    13,   147,   147,   147,
     147,    -5,    -5,     2,   162,   176,   166,   218,    15,  -210,
    -210,  -210,   253,   254,  -210,   249,   167,   902,  1252,  -210,
    -210,  -210,  1000,  -210,  -210,  -210,   526,   526,   526,  -210,
    1266,  1312,  -210,  -210,  -210,  1312,  -210,  1312,  -210,  -210,
    -210,  -210,   255,  -210,   256,  -210,  -210,  -210,   293,  -210,
     526,   154,   165,  -210,  -210,  -210,  -210,   526,  -210,   526,
     239,  -210,  -210,  -210
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,  -210,  -210,  -210,  -210,   -59,  -210,   -69,  -136,    45,
      20,    33,   103,   105,   102,   104,   109,  -210,   -58,   -60,
    -210,   -49,   -66,    21,   183,   265,  -210,  -210,    29,  -210,
    -210,   263,   -71,   -67,  -210,    85,  -210,   277,   204,    39,
     -11,   -32,   -15,  -210,   -54,  -210,   131,  -210,   185,  -125,
    -209,  -138,  -210,   -89,  -210,    37,   134,    19,  -182,  -210,
    -210,  -210,  -210,   340,  -210
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     150,   151,    60,   265,   144,     9,   165,    38,    42,   163,
     186,    40,   159,   170,    47,    50,    67,    19,   240,   175,
     250,    24,    63,    19,   155,   155,   150,   151,    69,    64,
     306,   312,   228,   218,   190,    70,    19,   183,   184,   222,
     180,   188,   156,   247,   139,   210,   219,    19,    58,   313,
      59,    22,   189,    20,    75,   150,    24,    22,    23,   223,
     139,   306,    41,    39,    23,   271,    23,    19,   169,    56,
      22,    51,    44,   229,   220,   221,   166,    23,   283,   284,
      76,    22,    68,   320,    73,   230,   214,   215,   248,   262,
      80,   165,   264,    19,   140,   150,   151,   230,   159,   327,
     253,   236,   254,   237,    76,    76,    76,   150,   151,    76,
     230,   161,    71,   231,    80,    80,    80,   244,   255,    80,
     190,   245,   257,   258,   173,   260,   263,   236,   239,   237,
      76,   211,   238,   189,    23,   276,   212,   213,   189,   269,
      80,   237,   280,   281,   282,    53,    23,   277,   232,   279,
     154,   234,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     299,   305,   319,   171,   336,   270,   172,   192,   150,   151,
     298,    74,   268,    25,   174,   193,   230,   132,   138,   194,
     315,    76,   316,   216,   217,   317,   230,   150,   151,   230,
     176,    80,   195,   323,   196,   178,   197,    60,   318,    48,
      49,   177,   230,   150,    52,    55,    76,   181,    25,   324,
     349,   239,   185,   325,   230,    40,    80,   337,   338,   339,
      55,   350,   307,   224,   308,   230,    55,    55,   287,   288,
     289,   290,   334,   169,   269,   326,   237,   230,   226,   150,
     151,   348,   159,   332,   270,   291,   292,   225,   351,   227,
     352,   285,   286,   235,   242,   343,    72,   243,   150,   344,
     246,   341,   342,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    81,    82,    83,    10,    11,    12,    13,    14,
      15,    16,    84,    85,    86,    87,    88,    89,    17,    18,
     256,    90,    91,    92,    93,    94,    95,   259,   261,   266,
      96,   272,   273,   278,   300,   311,   321,   330,   322,   328,
     329,   345,    97,   347,   346,   353,    98,   293,   295,    20,
     294,   296,    99,   100,    21,   101,   157,   297,   162,   314,
     153,   102,   103,   104,   105,   106,   107,     1,     2,     3,
       4,     5,     6,     7,     8,     9,   108,    53,   109,   249,
      11,    12,    13,     1,     2,     3,     4,     5,     6,     7,
       8,     9,   267,    18,   310,    62,    11,    12,    13,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,    18,
       0,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,    20,    17,    18,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,   164,     0,     0,    20,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    72,     0,    53,    10,    11,    12,    13,    14,    15,
      16,    81,    82,    83,     0,     0,     0,    17,    18,     0,
       0,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
       0,    97,     0,    21,     0,    98,     0,     0,     0,     0,
       0,    99,   100,     0,   101,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,    53,     0,    81,    82,
      83,     0,     0,     0,     0,   108,    53,   233,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,    91,    92,
      93,    94,    95,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,    98,     0,     0,     0,     0,     0,    99,   100,
       0,   101,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,     1,     2,     3,     4,     5,     6,     7,
       8,     9,   108,    53,     0,     0,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,   148,    91,    92,    93,    94,    95,     0,     0,     0,
      96,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    97,     0,     0,     0,    11,    12,    13,    20,
       0,     0,     0,   100,    21,   101,     0,     0,     0,    18,
       0,   102,   103,   104,   105,   106,   107,    61,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     9,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    20,
       0,     0,     0,     0,    21,    17,    18,     0,    19,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,    17,    18,    20,    19,     0,     0,
       0,    21,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
      21,   236,   301,   237,     0,     0,     0,     0,    23,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,    17,    18,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,     0,
       0,    17,    18,     0,    19,    20,     0,     0,     0,     0,
      21,   269,   301,   237,     0,     0,     0,     0,    23,     0,
     198,     0,     0,     0,   199,   200,   201,     0,     0,     0,
       0,   202,    20,     0,   203,   204,     0,    21,    22,   205,
       0,   206,   207,     0,     0,    23,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,     0,   208,     0,     0,     0,
       0,    17,    18,     0,   141,     1,     2,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,    10,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,     0,     0,
      17,    18,    20,     0,     0,     0,     0,    21,     0,   142,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    21,     0,   331,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,    10,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,    17,    18,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
       0,   309,    17,    18,     0,    20,     0,     0,     0,     0,
      21,   148,    91,    92,    93,    94,    95,     0,     0,     0,
      96,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    20,     0,     0,     0,     0,    21,     0,
       0,     0,     0,   100,     0,   101,     0,     0,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   148,    91,    92,
      93,    94,    95,     0,     0,     0,    96,   158,   335,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,   148,    91,    92,    93,    94,    95,   100,
       0,   101,    96,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,   158,     0,   100,     0,   101,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,     0,
     148,    91,    92,    93,    94,    95,     0,     0,   179,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,   148,    91,    92,    93,
      94,    95,   100,     0,   101,    96,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,     0,    97,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,   100,     0,
     101,     0,     0,   149,     0,     0,   102,   103,   104,   105,
     106,   107,   148,    91,    92,    93,    94,    95,     0,     0,
       0,    96,     0,     0,     0,     0,     0,   148,    91,    92,
      93,    94,    95,    97,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,   100,     0,   101,   274,    97,     0,
       0,     0,   102,   103,   104,   105,   106,   107,     0,   100,
       0,   101,     0,     0,   304,     0,     0,   102,   103,   104,
     105,   106,   107,   148,    91,    92,    93,    94,    95,     0,
       0,     0,    96,     0,     0,     0,     0,   148,    91,    92,
      93,    94,    95,     0,    97,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,   101,    97,     0,
     333,     0,     0,   102,   103,   104,   105,   106,   107,   100,
       0,   101,   340,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   148,    91,    92,    93,    94,    95,     0,
       0,     0,    96,     0,     0,     0,     0,   148,    91,    92,
      93,    94,    95,     0,    97,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,   101,    97,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107,   100,
       0,   182,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,   148,    91,    92,    93,    94,    95,     0,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,   187,     0,     0,
       0,     0,     0,   102,   103,   104,   105,   106,   107
};

static const yytype_int16 yycheck[] =
{
      59,    59,    34,   185,    58,    11,    77,    31,    23,    76,
      99,    22,    72,    80,    25,    31,    66,    31,   143,    85,
     158,     0,    87,    31,    70,    70,    85,    85,    43,    31,
     239,    70,    42,    38,   101,    86,    31,    96,    97,    37,
      89,   100,    88,    88,    55,   114,    51,    31,    65,    88,
      67,    65,   101,    59,    87,   114,    35,    65,    72,    57,
      71,   270,    23,    87,    72,   190,    72,    31,    79,    32,
      65,    87,    86,    83,    79,    80,    84,    72,   214,   215,
      51,    65,    43,   265,    47,    70,    73,    74,   154,   178,
      51,   162,   181,    31,    57,   154,   154,    70,   158,    84,
     166,    65,    70,    67,    75,    76,    77,   166,   166,    80,
      70,    74,    70,    86,    75,    76,    77,    66,    86,    80,
     187,    70,   171,   172,    31,   174,    86,    65,   143,    67,
     101,    72,   143,   182,    72,   195,    77,    78,   187,    65,
     101,    67,   211,   212,   213,    87,    72,   196,   129,   209,
      85,   132,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     230,   237,   261,    65,   312,   190,    65,    40,   237,   237,
     229,    47,    66,     0,    65,    48,    70,    53,    54,    52,
     256,   162,    66,    46,    47,    66,    70,   256,   256,    70,
      86,   162,    65,   272,    67,    84,    69,   239,    66,    26,
      27,    86,    70,   272,    31,    32,   187,    84,    35,    66,
      66,   236,    65,    70,    70,   236,   187,   316,   317,   318,
      47,    66,    65,    71,    67,    70,    53,    54,   218,   219,
     220,   221,   308,   254,    65,    68,    67,    70,    82,   308,
     308,   340,   312,   307,   269,   222,   223,    81,   347,    41,
     349,   216,   217,    88,    66,   325,    85,    70,   327,   327,
      68,   320,   321,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      84,    31,    32,    33,    34,    35,    36,    86,    84,    12,
      40,    66,    31,    31,    88,    31,    65,    68,    66,    66,
      66,    66,    52,    30,    68,    86,    56,   224,   226,    59,
     225,   227,    62,    63,    64,    65,    71,   228,    75,   254,
      63,    71,    72,    73,    74,    75,    76,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    86,    87,    88,   155,
      16,    17,    18,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   187,    29,   243,    35,    16,    17,    18,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    29,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    59,    28,    29,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,
      -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    85,    -1,    87,    15,    16,    17,    18,    19,    20,
      21,    12,    13,    14,    -1,    -1,    -1,    28,    29,    -1,
      -1,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    52,    -1,    64,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    87,    -1,    12,    13,
      14,    -1,    -1,    -1,    -1,    86,    87,    88,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    86,    87,    -1,    -1,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      -1,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    52,    -1,    -1,    -1,    16,    17,    18,    59,
      -1,    -1,    -1,    63,    64,    65,    -1,    -1,    -1,    29,
      -1,    71,    72,    73,    74,    75,    76,     0,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    59,
      -1,    -1,    -1,    -1,    64,    28,    29,    -1,    31,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    59,    31,    -1,    -1,
      -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    72,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    31,    59,    -1,    -1,    -1,    -1,
      64,    65,    66,    67,    -1,    -1,    -1,    -1,    72,    -1,
      39,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,    -1,
      -1,    50,    59,    -1,    53,    54,    -1,    64,    65,    58,
      -1,    60,    61,    -1,    -1,    72,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    85,    -1,    -1,    -1,
      -1,    28,    29,    -1,    31,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    29,    59,    -1,    -1,    -1,    -1,    64,    -1,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    64,    -1,    66,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    55,    28,    29,    -1,    59,    -1,    -1,    -1,    -1,
      64,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    59,    -1,    -1,    -1,    -1,    64,    -1,
      -1,    -1,    -1,    63,    -1,    65,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    87,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    63,
      -1,    65,    40,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    63,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    -1,
      31,    32,    33,    34,    35,    36,    -1,    -1,    86,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    63,    -1,    65,    40,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    63,    -1,
      65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,    74,
      75,    76,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    52,    -1,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    65,    66,    52,    -1,
      -1,    -1,    71,    72,    73,    74,    75,    76,    -1,    63,
      -1,    65,    -1,    -1,    68,    -1,    -1,    71,    72,    73,
      74,    75,    76,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    52,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    52,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    75,    76,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    52,    -1,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    52,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    63,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    65,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      15,    16,    17,    18,    19,    20,    21,    28,    29,    31,
      59,    64,    65,    72,   112,   113,   116,   117,   118,   119,
     125,   128,   129,   130,   131,   151,   152,   153,    31,    87,
     129,   128,   131,   132,    86,   114,   115,   129,   113,   113,
      31,    87,   113,    87,   112,   113,   144,   145,    65,    67,
     130,     0,   152,    87,    31,   126,   127,    66,   128,   131,
      86,    70,    85,   144,   145,    87,   117,   120,   121,   122,
     128,    12,    13,    14,    22,    23,    24,    25,    26,    27,
      31,    32,    33,    34,    35,    36,    40,    52,    56,    62,
      63,    65,    71,    72,    73,    74,    75,    76,    86,    88,
      90,    91,    92,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   110,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   145,   129,
     144,    31,    66,   113,   133,   134,   135,   136,    31,    68,
      94,   107,   111,   126,    85,    70,    88,   114,    87,   108,
     140,   144,   120,   122,    88,   121,    84,   123,   124,   129,
     122,    65,    65,    31,    65,   111,    86,    86,    84,    86,
     110,    84,    65,    94,    94,    65,   142,    65,    94,   110,
     122,   137,    40,    48,    52,    65,    67,    69,    39,    43,
      44,    45,    50,    53,    54,    58,    60,    61,    85,   109,
      96,    72,    77,    78,    73,    74,    46,    47,    38,    51,
      79,    80,    37,    57,    71,    81,    82,    41,    42,    83,
      70,    86,   146,    88,   146,    88,    65,    67,   129,   131,
     138,   139,    66,    70,    66,    70,    68,    88,   111,   127,
     140,   141,    88,   111,    70,    86,    84,   110,   110,    86,
     110,    84,   142,    86,   142,   147,    12,   137,    66,    65,
     131,   138,    66,    31,    66,    93,   108,   110,    31,   108,
      96,    96,    96,    97,    97,    98,    98,    99,    99,    99,
      99,   100,   100,   101,   102,   103,   104,   105,   110,   108,
      88,    66,   133,   138,    68,   111,   139,    65,    67,    55,
     135,    31,    70,    88,   124,   111,    66,    66,    66,   142,
     147,    65,    66,    96,    66,    70,    68,    84,    66,    66,
      68,    66,   133,    68,   111,    88,   140,   142,   142,   142,
      66,   110,   110,   108,   107,    66,    68,    30,   142,    66,
      66,   142,   142,    86
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 59 "csynan.yxx"
    {
            (yyval).ast = new CIdentExpr(new CIdent(*(yyvsp[(1) - (1)]).str));
        }
    break;

  case 3:
#line 64 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 4:
#line 69 "csynan.yxx"
    {
            throw std::string("String literal not supported.");
        }
    break;

  case 5:
#line 74 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(2) - (3)]).ast;
        }
    break;

  case 6:
#line 81 "csynan.yxx"
    {
            (yyval).ast = new CFloatExpr((yyvsp[(1) - (1)]).fpval);
        }
    break;

  case 7:
#line 86 "csynan.yxx"
    {
            (yyval).ast = new CIntExpr((yyvsp[(1) - (1)]).intval);
        }
    break;

  case 8:
#line 91 "csynan.yxx"
    {
            (yyval).ast = new CUIntExpr((yyvsp[(1) - (1)]).uintval);
        }
    break;

  case 9:
#line 96 "csynan.yxx"
    {
            throw std::string("Character constant not supported.");
        }
    break;

  case 10:
#line 103 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 11:
#line 108 "csynan.yxx"
    {
            throw std::string("Arrays not supported.");
        }
    break;

  case 12:
#line 113 "csynan.yxx"
    {
            throw std::string("Functions not supported.");
        }
    break;

  case 13:
#line 118 "csynan.yxx"
    {
            throw std::string("Functions not supported.");
        }
    break;

  case 14:
#line 123 "csynan.yxx"
    {
            throw std::string("Structured types not supported.");
        }
    break;

  case 15:
#line 128 "csynan.yxx"
    {
            throw std::string("Structured types not supported.");
        }
    break;

  case 16:
#line 133 "csynan.yxx"
    {
            (yyval).ast = new CUnOp(CUnOp::PostInc, (CExpr *)(yyvsp[(1) - (2)]).ast);
        }
    break;

  case 17:
#line 138 "csynan.yxx"
    {
            (yyval).ast = new CUnOp(CUnOp::PostDec, (CExpr *)(yyvsp[(1) - (2)]).ast);
        }
    break;

  case 18:
#line 145 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 19:
#line 150 "csynan.yxx"
    {
            throw std::string("Argument lists not supported.");
        }
    break;

  case 20:
#line 157 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 21:
#line 162 "csynan.yxx"
    {
            (yyval).ast = new CUnOp(CUnOp::PreInc, (CExpr *)(yyvsp[(2) - (2)]).ast);
        }
    break;

  case 22:
#line 167 "csynan.yxx"
    {
            (yyval).ast = new CUnOp(CUnOp::PreDec, (CExpr *)(yyvsp[(2) - (2)]).ast);
        }
    break;

  case 23:
#line 172 "csynan.yxx"
    {
            (yyval).ast = new CUnOp((yyvsp[(1) - (2)]).unopt, (CExpr *)(yyvsp[(2) - (2)]).ast);
        }
    break;

  case 24:
#line 177 "csynan.yxx"
    {
            throw std::string("sizeof not supported.");
        }
    break;

  case 25:
#line 182 "csynan.yxx"
    {
            throw std::string("sizeof not supported.");
        }
    break;

  case 26:
#line 189 "csynan.yxx"
    {
            (yyval).unopt = CUnOp::And;
        }
    break;

  case 27:
#line 194 "csynan.yxx"
    {
            (yyval).unopt = CUnOp::Star;
        }
    break;

  case 28:
#line 199 "csynan.yxx"
    {
            (yyval).unopt = CUnOp::Plus;
        }
    break;

  case 29:
#line 204 "csynan.yxx"
    {
            (yyval).unopt = CUnOp::Minus;
        }
    break;

  case 30:
#line 209 "csynan.yxx"
    {
            (yyval).unopt = CUnOp::Tilde;
        }
    break;

  case 31:
#line 214 "csynan.yxx"
    {
            (yyval).unopt = CUnOp::Excl;
        }
    break;

  case 32:
#line 221 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 34:
#line 231 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 35:
#line 236 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::Mult, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 36:
#line 241 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::Div, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 37:
#line 246 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::Mod, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 38:
#line 253 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 39:
#line 258 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::Plus, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 40:
#line 263 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::Minus, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 41:
#line 270 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 42:
#line 275 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::LShift, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 43:
#line 280 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::RShift, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 44:
#line 287 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 45:
#line 292 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::Lt, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 46:
#line 297 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::Gt, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 47:
#line 302 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::LEq, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 48:
#line 307 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::GEq, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 49:
#line 314 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 50:
#line 319 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::Eq, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 51:
#line 324 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::NEq, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 52:
#line 331 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 53:
#line 336 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::BAnd, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 54:
#line 343 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 55:
#line 348 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::Xor, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 56:
#line 355 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 57:
#line 360 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::BOr, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 58:
#line 367 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 59:
#line 372 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::LAnd, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 60:
#line 379 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 61:
#line 384 "csynan.yxx"
    {
            (yyval).ast = new CBinOp(CBinOp::LOr, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 62:
#line 391 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 63:
#line 396 "csynan.yxx"
    {
            throw std::string("Ternary operator not supported.");
        }
    break;

  case 64:
#line 403 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 65:
#line 408 "csynan.yxx"
    {
            /*if ($2.binopt != CBinOp::Assign)
	      throw ("Only simple assignment operator supported.");
	      else
	      $$.ast = new CBinOp(CBinOp::Assign, (CExpr *)$1.ast, (CExpr *)$3.ast);*/
	    (yyval).ast = new CBinOp((yyvsp[(2) - (3)]).binopt, (CExpr *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast);
        }
    break;

  case 66:
#line 419 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::Assign;
        }
    break;

  case 67:
#line 424 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::MultAss;
        }
    break;

  case 68:
#line 429 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::DivAss;
        }
    break;

  case 69:
#line 434 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::ModAss;
        }
    break;

  case 70:
#line 439 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::PlusAss;
        }
    break;

  case 71:
#line 444 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::MinusAss;
        }
    break;

  case 72:
#line 449 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::LShiftAss;
        }
    break;

  case 73:
#line 454 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::RShiftAss;
        }
    break;

  case 74:
#line 459 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::BAndAss;
        }
    break;

  case 75:
#line 464 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::XorAss;
        }
    break;

  case 76:
#line 469 "csynan.yxx"
    {
            (yyval).binopt = CBinOp::BOrAss;
        }
    break;

  case 77:
#line 476 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 78:
#line 481 "csynan.yxx"
    {
            throw std::string("Operator comma not supported.");
        }
    break;

  case 79:
#line 488 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 80:
#line 495 "csynan.yxx"
    {
            (yyval).ast = new CDecl((CDeclSpec *)(yyvsp[(1) - (2)]).ast, NULL, NULL);
        }
    break;

  case 81:
#line 500 "csynan.yxx"
    {
            (yyval).ast = new CDecl((CDeclSpec *)(yyvsp[(1) - (3)]).ast, (CInitDecl *)(yyvsp[(2) - (3)]).ast, NULL);
        }
    break;

  case 82:
#line 507 "csynan.yxx"
    {
            throw std::string("storage_class_specifier not supported");
        }
    break;

  case 83:
#line 512 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(2) - (2)]).ast;
        }
    break;

  case 84:
#line 517 "csynan.yxx"
    {
            (yyval).ast = new CTypeSpec((yyvsp[(1) - (1)]).tstp, NULL); 
        }
    break;

  case 85:
#line 522 "csynan.yxx"
    {
            (yyval).ast = new CTypeSpec((yyvsp[(1) - (2)]).tstp, (CDeclSpec *)(yyvsp[(2) - (2)]).ast);
        }
    break;

  case 86:
#line 527 "csynan.yxx"
    {
            throw std::string("type_qualifier not supported.");
        }
    break;

  case 87:
#line 532 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(2) - (2)]).ast;
        }
    break;

  case 88:
#line 539 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 89:
#line 545 "csynan.yxx"
    {
            ((CInitDecl *)((yyvsp[(1) - (3)]).ast))->set_next((CInitDecl *)(yyvsp[(3) - (3)]).ast);
            (yyval).ast = (yyvsp[(1) - (3)]).ast;
        }
    break;

  case 90:
#line 553 "csynan.yxx"
    {
            (yyval).ast = new CInitDecl((CDeclarator *)(yyvsp[(1) - (1)]).ast, NULL, NULL);
        }
    break;

  case 91:
#line 558 "csynan.yxx"
    {
            (yyval).ast = new CInitDecl((CDeclarator *)(yyvsp[(1) - (3)]).ast, (CExpr *)(yyvsp[(3) - (3)]).ast, NULL);
        }
    break;

  case 97:
#line 573 "csynan.yxx"
    {
            (yyval).tstp = CTypeSpec::Void;
        }
    break;

  case 98:
#line 578 "csynan.yxx"
    {
            (yyval).tstp = CTypeSpec::Char;
        }
    break;

  case 99:
#line 583 "csynan.yxx"
    {
            (yyval).tstp = CTypeSpec::Short;
        }
    break;

  case 100:
#line 588 "csynan.yxx"
    {
            (yyval).tstp = CTypeSpec::Int;
        }
    break;

  case 101:
#line 593 "csynan.yxx"
    {
            (yyval).tstp = CTypeSpec::Long;
        }
    break;

  case 102:
#line 598 "csynan.yxx"
    {
            (yyval).tstp = CTypeSpec::Float;
        }
    break;

  case 103:
#line 603 "csynan.yxx"
    {
            (yyval).tstp = CTypeSpec::Double;
        }
    break;

  case 104:
#line 608 "csynan.yxx"
    {
            (yyval).tstp = CTypeSpec::Signed;
        }
    break;

  case 105:
#line 613 "csynan.yxx"
    {
            (yyval).tstp = CTypeSpec::Unsigned;
        }
    break;

  case 106:
#line 618 "csynan.yxx"
    {
            throw std::string("struct_or_union_specifier not supported.");
        }
    break;

  case 107:
#line 623 "csynan.yxx"
    {
            throw std::string("enum_specifier not supported.");
        }
    break;

  case 108:
#line 628 "csynan.yxx"
    {
            throw std::string("TYPE_NAME not supported.");
        }
    break;

  case 109:
#line 635 "csynan.yxx"
    {
            throw std::string("struct_or_union_specifier not supported.");
        }
    break;

  case 110:
#line 640 "csynan.yxx"
    {
            throw std::string("struct_or_union_specifier not supported.");
        }
    break;

  case 111:
#line 645 "csynan.yxx"
    {
            throw std::string("struct_or_union_specifier not supported.");
        }
    break;

  case 135:
#line 705 "csynan.yxx"
    {
            throw std::string("Pointers not supported.");
        }
    break;

  case 136:
#line 710 "csynan.yxx"
    {
            (yyval).ast = new CDeclarator(CDeclarator::DirectDecl, (CIdent *)(yyvsp[(1) - (1)]).ast);
        }
    break;

  case 137:
#line 717 "csynan.yxx"
    {
            (yyval).ast = new CIdent(*(yyvsp[(1) - (1)]).str);
        }
    break;

  case 138:
#line 722 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(2) - (3)]).ast;
        }
    break;

  case 139:
#line 727 "csynan.yxx"
    {
            throw std::string("Arrays not supported.");
        }
    break;

  case 140:
#line 732 "csynan.yxx"
    {
            throw std::string("Arrays not supported.");
        }
    break;

  case 141:
#line 737 "csynan.yxx"
    {
            throw std::string("direct_declarator '(' parameter_type_list ')' "
                              "not supported.");
        }
    break;

  case 142:
#line 743 "csynan.yxx"
    {
            throw std::string("direct_declarator '(' identifier_list ')' "
                              "not supported.");
        }
    break;

  case 143:
#line 749 "csynan.yxx"
    {
            /* !!! doplnit !!! */
        }
    break;

  case 161:
#line 794 "csynan.yxx"
    {
            throw std::string("abstract_declarator not supported.");
        }
    break;

  case 162:
#line 799 "csynan.yxx"
    {
            throw std::string("abstract_declarator not supported.");
        }
    break;

  case 163:
#line 804 "csynan.yxx"
    {
            throw std::string("abstract_declarator not supported.");
        }
    break;

  case 173:
#line 823 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 174:
#line 828 "csynan.yxx"
    {
            throw std::string("Initializers of structured types not supported.");
        }
    break;

  case 175:
#line 833 "csynan.yxx"
    {
            throw std::string("Initializers of structured types not supported.");
        }
    break;

  case 178:
#line 845 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 179:
#line 850 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 180:
#line 855 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 181:
#line 860 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 182:
#line 865 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 183:
#line 870 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 184:
#line 877 "csynan.yxx"
    {
            throw std::string("Labels not supported.");
        }
    break;

  case 185:
#line 882 "csynan.yxx"
    {
            (yyval).ast = new CLabeledStatement(CLabeledStatement::Case, 
                (CConstExpr *)(yyvsp[(2) - (4)]).ast, (CStatement *)(yyvsp[(4) - (4)]).ast, NULL);
        }
    break;

  case 186:
#line 888 "csynan.yxx"
    {
            (yyval).ast = new CLabeledStatement(CLabeledStatement::Default, NULL, 
                (CStatement *)(yyvsp[(3) - (3)]).ast, NULL);
        }
    break;

  case 187:
#line 896 "csynan.yxx"
    {
            //$$.ast = NULL; // ???
            (yyval).ast = new CCompoundStatement(NULL, NULL, NULL);
        }
    break;

  case 188:
#line 902 "csynan.yxx"
    {
            (yyval).ast = new CCompoundStatement(NULL, (CStatement *)(yyvsp[(2) - (3)]).ast, NULL);
        }
    break;

  case 189:
#line 907 "csynan.yxx"
    {
            (yyval).ast = new CCompoundStatement((CDecl *)(yyvsp[(2) - (3)]).ast, NULL, NULL);
        }
    break;

  case 190:
#line 912 "csynan.yxx"
    {
            (yyval).ast = new CCompoundStatement((CDecl *)(yyvsp[(2) - (4)]).ast, (CStatement *)(yyvsp[(3) - (4)]).ast, 
                NULL);
        }
    break;

  case 191:
#line 920 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 192:
#line 926 "csynan.yxx"
    {
          (dynamic_cast<CDecl *>((yyvsp[(1) - (2)]).ast))->set_next
            (dynamic_cast<CDecl *>((yyvsp[(2) - (2)]).ast));
            (yyval).ast = (yyvsp[(1) - (2)]).ast;
        }
    break;

  case 193:
#line 935 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(1) - (1)]).ast;
        }
    break;

  case 194:
#line 941 "csynan.yxx"
    {
          (dynamic_cast<CStatement *>((yyvsp[(1) - (2)]).ast))->set_next
            (dynamic_cast<CStatement *>((yyvsp[(2) - (2)]).ast));
            (yyval).ast = (yyvsp[(1) - (2)]).ast;
        }
    break;

  case 195:
#line 950 "csynan.yxx"
    {
            (yyval).ast = new CExprStatement(NULL, NULL);
        }
    break;

  case 196:
#line 955 "csynan.yxx"
    {
            (yyval).ast = new CExprStatement((CExpr *)(yyvsp[(1) - (2)]).ast, NULL);
        }
    break;

  case 197:
#line 962 "csynan.yxx"
    {
            throw std::string("'If' statement not supported.");
        }
    break;

  case 198:
#line 967 "csynan.yxx"
    {
            throw std::string("'If' statement not supported.");
        }
    break;

  case 199:
#line 972 "csynan.yxx"
    {
            (yyval).ast = new CSelectionStatement(CSelectionStatement::Switch, 
                (CExpr *)(yyvsp[(3) - (5)]).ast, (CStatement *)(yyvsp[(5) - (5)]).ast, NULL, NULL);
        }
    break;

  case 200:
#line 980 "csynan.yxx"
    {
            (yyval).ast = new CIterationStatement(CIterationStatement::While, 
                (CExpr *)(yyvsp[(3) - (5)]).ast, (CStatement *)(yyvsp[(5) - (5)]).ast, NULL);
        }
    break;

  case 201:
#line 986 "csynan.yxx"
    {
            throw std::string("'Do' statement not supported.");
        }
    break;

  case 202:
#line 991 "csynan.yxx"
    {
            throw std::string("'For' statement not supported.");
        }
    break;

  case 203:
#line 996 "csynan.yxx"
    {
            throw std::string("'For' statement not supported.");
        }
    break;

  case 204:
#line 1003 "csynan.yxx"
    {
            throw std::string("'Goto' statement not supported.");
        }
    break;

  case 205:
#line 1008 "csynan.yxx"
    {
            (yyval).ast = new CJumpStatement(CJumpStatement::Continue, NULL, NULL);
        }
    break;

  case 206:
#line 1013 "csynan.yxx"
    {
            (yyval).ast = new CJumpStatement(CJumpStatement::Break, NULL, NULL);
        }
    break;

  case 207:
#line 1018 "csynan.yxx"
    {
            (yyval).ast = new CJumpStatement(CJumpStatement::Return, NULL, NULL);
        }
    break;

  case 208:
#line 1023 "csynan.yxx"
    {
            (yyval).ast = new CJumpStatement(CJumpStatement::Return, (CExpr *)(yyvsp[(2) - (3)]).ast, 
                NULL);
        }
    break;

  case 211:
#line 1036 "csynan.yxx"
    {
            *((CCompoundStatement **)YYPARSE_PARAM) = (CCompoundStatement *)(yyvsp[(1) - (1)]).ast;
        }
    break;

  case 212:
#line 1041 "csynan.yxx"
    {
            throw std::string("External declaration not supported.");
        }
    break;

  case 213:
#line 1048 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(4) - (4)]).ast;
        }
    break;

  case 214:
#line 1053 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(3) - (3)]).ast;
        }
    break;

  case 215:
#line 1058 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(3) - (3)]).ast;
        }
    break;

  case 216:
#line 1063 "csynan.yxx"
    {
            (yyval).ast = (yyvsp[(2) - (2)]).ast;
        }
    break;


/* Line 1267 of yacc.c.  */
#line 3169 "csynan.cxx"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 1068 "csynan.yxx"


void yyerror (char *s)
{		
    std::cerr << filename << ": " << s << std::endl;
}
 
 

