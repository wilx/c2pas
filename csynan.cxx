/* A Bison parser, made by GNU Bison 1.875b.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

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
     TOK_STRUCT = 270,
     TOK_TYPEDEF = 271,
     TOK_ENUM = 272,
     TOK_UNION = 273,
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
#define TOK_STRUCT 270
#define TOK_TYPEDEF 271
#define TOK_ENUM 272
#define TOK_UNION 273
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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 231 "csynan.cxx"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1405

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  65
/* YYNRULES -- Number of rules. */
#define YYNRULES  216
/* YYNRULES -- Number of states. */
#define YYNSTATES  354

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   319

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
static const unsigned short yyprhs[] =
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

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
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
      -1,   129,    85,   140,    -1,    16,    -1,    28,    -1,    19,
      -1,    21,    -1,    20,    -1,    29,    -1,     4,    -1,    10,
      -1,     3,    -1,     5,    -1,     7,    -1,     8,    -1,     9,
      -1,     6,    -1,   118,    -1,   125,    -1,    64,    -1,   119,
      31,    87,   120,    88,    -1,   119,    87,   120,    88,    -1,
     119,    31,    -1,    15,    -1,    18,    -1,   121,    -1,   120,
     121,    -1,   122,   123,    86,    -1,   117,   122,    -1,   117,
      -1,   128,   122,    -1,   128,    -1,   124,    -1,   123,    70,
     124,    -1,   129,    -1,    84,   111,    -1,   129,    84,   111,
      -1,    17,    87,   126,    88,    -1,    17,    31,    87,   126,
      88,    -1,    17,    31,    -1,   127,    -1,   126,    70,   127,
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
static const unsigned short yyrline[] =
{
       0,    32,    32,    37,    42,    47,    54,    59,    64,    69,
      76,    81,    86,    91,    96,   101,   106,   111,   118,   123,
     130,   135,   140,   145,   150,   155,   162,   167,   172,   177,
     182,   187,   194,   199,   204,   209,   214,   219,   226,   231,
     236,   243,   248,   253,   260,   265,   270,   275,   280,   287,
     292,   297,   304,   309,   316,   321,   328,   333,   340,   345,
     352,   357,   364,   369,   376,   381,   392,   397,   402,   407,
     412,   417,   422,   427,   432,   437,   442,   449,   454,   461,
     468,   473,   480,   485,   490,   495,   500,   505,   512,   518,
     526,   531,   538,   539,   540,   541,   542,   546,   551,   556,
     561,   566,   571,   576,   581,   586,   591,   596,   601,   608,
     613,   618,   625,   626,   630,   631,   635,   639,   640,   641,
     642,   646,   647,   651,   652,   653,   657,   658,   659,   663,
     664,   668,   669,   673,   674,   678,   683,   690,   695,   700,
     705,   710,   716,   722,   729,   730,   731,   732,   736,   737,
     741,   742,   746,   747,   751,   752,   753,   757,   758,   762,
     763,   767,   772,   777,   784,   785,   786,   787,   788,   789,
     790,   791,   792,   796,   801,   806,   813,   814,   818,   823,
     828,   833,   838,   843,   850,   855,   861,   869,   875,   880,
     885,   893,   899,   908,   914,   923,   928,   935,   940,   945,
     953,   959,   964,   969,   976,   981,   986,   991,   996,  1004,
    1005,  1009,  1014,  1021,  1026,  1031,  1036
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_INT", "TOK_CHAR", "TOK_LONG", 
  "TOK_UNSIGNED", "TOK_FLOAT", "TOK_DOUBLE", "TOK_SIGNED", "TOK_SHORT", 
  "TOK_CONST", "TOK_WHILE", "TOK_IF", "TOK_GOTO", "TOK_STRUCT", 
  "TOK_TYPEDEF", "TOK_ENUM", "TOK_UNION", "TOK_STATIC", "TOK_REGISTER", 
  "TOK_AUTO", "TOK_SWITCH", "TOK_CASE", "TOK_BREAK", "TOK_CONTINUE", 
  "TOK_DEFAULT", "TOK_RETURN", "TOK_EXTERN", "TOK_VOID", "TOK_ELSE", 
  "TOK_IDENT", "TOK_FPNUM", "TOK_INTNUM", "TOK_UINTNUM", "TOK_STRING", 
  "TOK_CHARVAL", "TOK_EQ", "TOK_GE", "TOK_MINUSEQ", "TOK_MINMIN", 
  "TOK_LAND", "TOK_LOR", "TOK_PLUSEQ", "TOK_MULTEQ", "TOK_DIVEQ", 
  "TOK_LSHIFT", "TOK_RSHIFT", "TOK_ARROW", "TOK_LISHIFTEQ", "TOK_XOREQ", 
  "TOK_LE", "TOK_PLUSPLUS", "TOK_OREQ", "TOK_ANDEQ", "TOK_ELLIPSIS", 
  "TOK_FOR", "TOK_NE", "TOK_LSHIFTEQ", "TOK_VOLATILE", "TOK_MODEQ", 
  "TOK_RSHIFTEQ", "TOK_DO", "TOK_SIZEOF", "TYPE_NAME", "'('", "')'", 
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", 
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'", 
  "'{'", "'}'", "$accept", "primary_expression", "constant", 
  "postfix_expression", "argument_expression_list", "unary_expression", 
  "unary_operator", "cast_expression", "multiplicative_expression", 
  "additive_expression", "shift_expression", "relational_expression", 
  "equality_expression", "and_expression", "exclusive_or_expression", 
  "inclusive_or_expression", "logical_and_expression", 
  "logical_or_expression", "conditional_expression", 
  "assignment_expression", "assignment_operator", "expression", 
  "constant_expression", "declaration", "declaration_specifiers", 
  "init_declarator_list", "init_declarator", "storage_class_specifier", 
  "type_specifier", "struct_or_union_specifier", "struct_or_union", 
  "struct_declaration_list", "struct_declaration", 
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
static const unsigned short yytoknum[] =
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
static const unsigned char yyr1[] =
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
static const unsigned char yyr2[] =
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
static const unsigned char yydefact[] =
{
       0,   100,    98,   101,   105,   102,   103,   104,    99,   133,
     112,    92,     0,   113,    94,    96,    95,    93,    97,   137,
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

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
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
static const short yypact[] =
{
     760,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,   -24,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,     5,    -6,  -210,   -14,   951,   951,  -210,   -16,
    -210,   951,   406,   -17,    16,   634,  -210,  -210,   -65,    -2,
     -50,  -210,  -210,    -6,  -210,   -51,    42,   372,  -210,  -210,
     -33,   523,  -210,   270,   951,   -14,  -210,    58,   830,  1102,
     -17,  -210,  -210,    -2,    65,   -46,  -210,  -210,  -210,  -210,
    -210,     5,  1003,  -210,    58,   523,   523,   310,  -210,    -8,
     523,   108,   111,    93,   119,  1269,   114,   125,   121,  1029,
     133,  -210,  -210,  -210,  -210,  -210,  1283,  1283,   157,   483,
    1329,   557,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,   137,   768,  1269,  -210,    59,    13,   147,    -5,
       2,   162,   176,   166,   218,   -10,  -210,  -210,    27,   483,
    -210,  -210,   416,   175,  -210,  -210,  -210,  -210,  -210,   181,
    -210,  -210,  -210,    62,   198,   197,  -210,    51,  -210,  -210,
    -210,  -210,   202,   -45,  1269,    -2,  -210,  -210,  1003,  -210,
    -210,  -210,   344,  -210,  -210,  -210,  1269,    32,  -210,   216,
    -210,  1269,  1269,   221,  1269,   224,  -210,  -210,   483,  -210,
      40,   483,  1269,  -210,  -210,  1076,   297,   557,  -210,   116,
      74,   245,  -210,   281,  -210,  1148,  1269,   292,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  1269,
    -210,  1269,  1269,  1269,  1269,  1269,  1269,  1269,  1269,  1269,
    1269,  1269,  1269,  1269,  1269,  1269,  1269,  1269,  1269,  1269,
    1269,  -210,  -210,  -210,   236,  -210,   663,  1163,  -210,    36,
    -210,   167,  -210,   923,  -210,   299,  -210,  -210,  -210,  -210,
    -210,   -39,  -210,  -210,    -8,  -210,  1269,   126,   129,  -210,
     142,   483,  -210,  -210,  -210,  1076,   266,   271,  -210,   733,
     179,  -210,  1269,  -210,  -210,   153,  -210,   177,  -210,  -210,
    -210,  -210,  -210,    59,    59,    13,    13,   147,   147,   147,
     147,    -5,    -5,     2,   162,   176,   166,   218,    15,  -210,
    -210,  -210,   272,   274,  -210,   268,   167,   859,  1209,  -210,
    -210,  -210,   957,  -210,  -210,  -210,   483,   483,   483,  -210,
    1223,  1269,  -210,  -210,  -210,  1269,  -210,  1269,  -210,  -210,
    -210,  -210,   294,  -210,   295,  -210,  -210,  -210,   334,  -210,
     483,   154,   165,  -210,  -210,  -210,  -210,   483,  -210,   483,
     279,  -210,  -210,  -210
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -210,  -210,  -210,  -210,  -210,   -59,  -210,   -69,  -136,    45,
      20,    33,   143,   141,   144,   145,   140,  -210,   -58,   -60,
    -210,   -49,   -66,    21,   183,   300,  -210,  -210,    29,  -210,
    -210,   309,   -71,   -67,  -210,   131,  -210,   323,   239,    39,
     -11,   -32,   -15,  -210,   -54,  -210,   152,  -210,   209,  -125,
    -209,  -138,  -210,   -89,  -210,    37,   134,    19,  -182,  -210,
    -210,  -210,  -210,   362,  -210
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short yytable[] =
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
      96,   272,   273,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    97,   278,   300,    10,    98,    12,    13,    20,
     311,   321,    99,   100,    21,   101,   330,   322,   328,    18,
     329,   102,   103,   104,   105,   106,   107,     1,     2,     3,
       4,     5,     6,     7,     8,     9,   108,    53,   109,    10,
     345,    12,    13,   346,   347,   353,   294,   293,   297,    20,
     295,   157,   296,    18,    21,     1,     2,     3,     4,     5,
       6,     7,     8,     9,   162,   314,   153,    10,    11,    12,
      13,    14,    15,    16,   249,   310,   267,    62,   164,     0,
      17,    18,     0,    20,     0,     0,     0,     0,    21,     1,
       2,     3,     4,     5,     6,     7,     8,     9,     0,     0,
       0,    10,    11,    12,    13,    14,    15,    16,    81,    82,
      83,    20,   252,     0,    17,    18,    21,     0,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,    91,    92,
      93,    94,    95,     0,     0,     0,    96,    72,     0,    53,
       0,     0,     0,     0,     0,    20,     0,     0,    97,     0,
      21,     0,    98,     0,     0,     0,     0,     0,    99,   100,
       0,   101,     0,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,    53,     0,    81,    82,    83,     0,     0,
       0,     0,   108,    53,   233,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    90,    91,    92,    93,    94,    95,
       0,     0,     0,    96,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    97,     0,     0,    10,    98,
      12,    13,     0,     0,     0,    99,   100,     0,   101,     0,
       0,     0,    18,     0,   102,   103,   104,   105,   106,   107,
       1,     2,     3,     4,     5,     6,     7,     8,     9,   108,
      53,     0,    10,     0,    12,    13,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    18,    21,   148,    91,
      92,    93,    94,    95,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,     0,     0,     0,    20,     0,     0,     0,
     100,    21,   101,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,    61,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
       0,     0,    17,    18,     0,    19,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,     0,
       0,    17,    18,    20,    19,     0,     0,     0,    21,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,    21,   236,   301,
     237,     0,     0,     0,     0,    23,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,     0,
       0,    17,    18,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,     0,     0,     0,     0,     0,     0,    17,    18,
       0,    19,    20,     0,     0,     0,     0,    21,   269,   301,
     237,     0,     0,     0,     0,    23,     0,   198,     0,     0,
       0,   199,   200,   201,     0,     0,     0,     0,   202,    20,
       0,   203,   204,     0,    21,    22,   205,     0,   206,   207,
       0,     0,    23,     1,     2,     3,     4,     5,     6,     7,
       8,     9,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,     0,   208,     0,     0,     0,     0,    17,    18,
       0,   141,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,     0,    10,    11,    12,    13,    14,    15,
      16,     0,     0,     0,     0,     0,     0,    17,    18,    20,
       0,     0,     0,     0,    21,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
       0,     0,     0,    21,     0,   331,     1,     2,     3,     4,
       5,     6,     7,     8,     9,     0,     0,     0,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,     0,
       0,    17,    18,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,     0,     0,     0,    10,    11,    12,    13,
      14,    15,    16,     0,     0,     0,     0,     0,   309,    17,
      18,     0,    20,     0,     0,     0,     0,    21,   148,    91,
      92,    93,    94,    95,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
      20,     0,     0,     0,     0,    21,     0,     0,     0,     0,
     100,     0,   101,     0,     0,     0,     0,     0,   102,   103,
     104,   105,   106,   107,   148,    91,    92,    93,    94,    95,
       0,     0,     0,    96,   158,   335,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,     0,
     148,    91,    92,    93,    94,    95,   100,     0,   101,    96,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
     158,     0,   100,     0,   101,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,     0,   148,    91,    92,
      93,    94,    95,     0,     0,   179,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,   148,    91,    92,    93,    94,    95,   100,
       0,   101,    96,     0,     0,     0,     0,   102,   103,   104,
     105,   106,   107,     0,    97,     0,     0,     0,     0,     0,
       0,     0,   108,     0,     0,   100,     0,   101,     0,     0,
     149,     0,     0,   102,   103,   104,   105,   106,   107,   148,
      91,    92,    93,    94,    95,     0,     0,     0,    96,     0,
       0,     0,     0,     0,   148,    91,    92,    93,    94,    95,
      97,     0,     0,    96,     0,     0,     0,     0,     0,     0,
       0,   100,     0,   101,   274,    97,     0,     0,     0,   102,
     103,   104,   105,   106,   107,     0,   100,     0,   101,     0,
       0,   304,     0,     0,   102,   103,   104,   105,   106,   107,
     148,    91,    92,    93,    94,    95,     0,     0,     0,    96,
       0,     0,     0,     0,   148,    91,    92,    93,    94,    95,
       0,    97,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,   101,    97,     0,   333,     0,     0,
     102,   103,   104,   105,   106,   107,   100,     0,   101,   340,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     148,    91,    92,    93,    94,    95,     0,     0,     0,    96,
       0,     0,     0,     0,   148,    91,    92,    93,    94,    95,
       0,    97,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,   101,    97,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107,   100,     0,   182,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,   107,
     148,    91,    92,    93,    94,    95,     0,     0,     0,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,     0,   187,     0,     0,     0,     0,     0,
     102,   103,   104,   105,   106,   107
};

static const short yycheck[] =
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
      40,    66,    31,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    52,    31,    88,    15,    56,    17,    18,    59,
      31,    65,    62,    63,    64,    65,    68,    66,    66,    29,
      66,    71,    72,    73,    74,    75,    76,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    86,    87,    88,    15,
      66,    17,    18,    68,    30,    86,   225,   224,   228,    59,
     226,    71,   227,    29,    64,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    75,   254,    63,    15,    16,    17,
      18,    19,    20,    21,   155,   243,   187,    35,    88,    -1,
      28,    29,    -1,    59,    -1,    -1,    -1,    -1,    64,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    12,    13,
      14,    59,    88,    -1,    28,    29,    64,    -1,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    40,    85,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    52,    -1,
      64,    -1,    56,    -1,    -1,    -1,    -1,    -1,    62,    63,
      -1,    65,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    87,    -1,    12,    13,    14,    -1,    -1,
      -1,    -1,    86,    87,    88,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    52,    -1,    -1,    15,    56,
      17,    18,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,
      -1,    -1,    29,    -1,    71,    72,    73,    74,    75,    76,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    86,
      87,    -1,    15,    -1,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    29,    64,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    -1,    -1,
      63,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,     0,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    29,    -1,    31,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    59,    31,    -1,    -1,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    59,    -1,    -1,    -1,    -1,    64,    65,    66,
      67,    -1,    -1,    -1,    -1,    72,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,
      -1,    31,    59,    -1,    -1,    -1,    -1,    64,    65,    66,
      67,    -1,    -1,    -1,    -1,    72,    -1,    39,    -1,    -1,
      -1,    43,    44,    45,    -1,    -1,    -1,    -1,    50,    59,
      -1,    53,    54,    -1,    64,    65,    58,    -1,    60,    61,
      -1,    -1,    72,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    85,    -1,    -1,    -1,    -1,    28,    29,
      -1,    31,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    59,
      -1,    -1,    -1,    -1,    64,    -1,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,
      -1,    -1,    -1,    64,    -1,    66,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,    -1,    55,    28,
      29,    -1,    59,    -1,    -1,    -1,    -1,    64,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      59,    -1,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,
      63,    -1,    65,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    40,    87,    88,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    63,    -1,    65,    40,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    63,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    -1,    31,    32,    33,
      34,    35,    36,    -1,    -1,    86,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    63,
      -1,    65,    40,    -1,    -1,    -1,    -1,    71,    72,    73,
      74,    75,    76,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    63,    -1,    65,    -1,    -1,
      68,    -1,    -1,    71,    72,    73,    74,    75,    76,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      52,    -1,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    -1,    65,    66,    52,    -1,    -1,    -1,    71,
      72,    73,    74,    75,    76,    -1,    63,    -1,    65,    -1,
      -1,    68,    -1,    -1,    71,    72,    73,    74,    75,    76,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    52,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    65,    52,    -1,    68,    -1,    -1,
      71,    72,    73,    74,    75,    76,    63,    -1,    65,    66,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    52,    -1,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    65,    52,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76,    63,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    75,    76,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    -1,    65,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    74,    75,    76
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
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

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1


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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 33 "csynan.yxx"
    {
            yyval.ast = new CIdentExpr(new CIdent(*yyvsp[0].str));
        }
    break;

  case 3:
#line 38 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 4:
#line 43 "csynan.yxx"
    {
            throw std::string("String literal not supported.");
        }
    break;

  case 5:
#line 48 "csynan.yxx"
    {
            yyval.ast = yyvsp[-1].ast;
        }
    break;

  case 6:
#line 55 "csynan.yxx"
    {
            yyval.ast = new CFloatExpr(yyvsp[0].fpval);
        }
    break;

  case 7:
#line 60 "csynan.yxx"
    {
            yyval.ast = new CIntExpr(yyvsp[0].intval);
        }
    break;

  case 8:
#line 65 "csynan.yxx"
    {
            yyval.ast = new CUIntExpr(yyvsp[0].uintval);
        }
    break;

  case 9:
#line 70 "csynan.yxx"
    {
            throw std::string("Character constant not supported.");
        }
    break;

  case 10:
#line 77 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 11:
#line 82 "csynan.yxx"
    {
            throw std::string("Arrays not supported.");
        }
    break;

  case 12:
#line 87 "csynan.yxx"
    {
            throw std::string("Functions not supported.");
        }
    break;

  case 13:
#line 92 "csynan.yxx"
    {
            throw std::string("Functions not supported.");
        }
    break;

  case 14:
#line 97 "csynan.yxx"
    {
            throw std::string("Structured types not supported.");
        }
    break;

  case 15:
#line 102 "csynan.yxx"
    {
            throw std::string("Structured types not supported.");
        }
    break;

  case 16:
#line 107 "csynan.yxx"
    {
            yyval.ast = new CUnOp(CUnOp::PostInc, (CExpr *)yyvsp[-1].ast);
        }
    break;

  case 17:
#line 112 "csynan.yxx"
    {
            yyval.ast = new CUnOp(CUnOp::PostDec, (CExpr *)yyvsp[-1].ast);
        }
    break;

  case 18:
#line 119 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 19:
#line 124 "csynan.yxx"
    {
            throw std::string("Argument lists not supported.");
        }
    break;

  case 20:
#line 131 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 21:
#line 136 "csynan.yxx"
    {
            yyval.ast = new CUnOp(CUnOp::PreInc, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 22:
#line 141 "csynan.yxx"
    {
            yyval.ast = new CUnOp(CUnOp::PreDec, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 23:
#line 146 "csynan.yxx"
    {
            yyval.ast = new CUnOp(yyvsp[-1].unopt, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 24:
#line 151 "csynan.yxx"
    {
            throw std::string("sizeof not supported.");
        }
    break;

  case 25:
#line 156 "csynan.yxx"
    {
            throw std::string("sizeof not supported.");
        }
    break;

  case 26:
#line 163 "csynan.yxx"
    {
            yyval.unopt = CUnOp::And;
        }
    break;

  case 27:
#line 168 "csynan.yxx"
    {
            yyval.unopt = CUnOp::Star;
        }
    break;

  case 28:
#line 173 "csynan.yxx"
    {
            yyval.unopt = CUnOp::Plus;
        }
    break;

  case 29:
#line 178 "csynan.yxx"
    {
            yyval.unopt = CUnOp::Minus;
        }
    break;

  case 30:
#line 183 "csynan.yxx"
    {
            yyval.unopt = CUnOp::Tilde;
        }
    break;

  case 31:
#line 188 "csynan.yxx"
    {
            yyval.unopt = CUnOp::Excl;
        }
    break;

  case 32:
#line 195 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 34:
#line 205 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 35:
#line 210 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::Mult, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 36:
#line 215 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::Div, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 37:
#line 220 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::Mod, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 38:
#line 227 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 39:
#line 232 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::Plus, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 40:
#line 237 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::Minus, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 41:
#line 244 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 42:
#line 249 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::LShift, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 43:
#line 254 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::RShift, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 44:
#line 261 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 45:
#line 266 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::Lt, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 46:
#line 271 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::Gt, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 47:
#line 276 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::LEq, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 48:
#line 281 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::GEq, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 49:
#line 288 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 50:
#line 293 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::Eq, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 51:
#line 298 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::NEq, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 52:
#line 305 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 53:
#line 310 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::BAnd, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 54:
#line 317 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 55:
#line 322 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::Xor, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 56:
#line 329 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 57:
#line 334 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::BOr, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 58:
#line 341 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 59:
#line 346 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::LAnd, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 60:
#line 353 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 61:
#line 358 "csynan.yxx"
    {
            yyval.ast = new CBinOp(CBinOp::LOr, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 62:
#line 365 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 63:
#line 370 "csynan.yxx"
    {
            throw std::string("Ternary operator not supported.");
        }
    break;

  case 64:
#line 377 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 65:
#line 382 "csynan.yxx"
    {
            /*if ($2.binopt != CBinOp::Assign)
	      throw ("Only simple assignment operator supported.");
	      else
	      $$.ast = new CBinOp(CBinOp::Assign, (CExpr *)$1.ast, (CExpr *)$3.ast);*/
	    yyval.ast = new CBinOp(yyvsp[-1].binopt, (CExpr *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast);
        }
    break;

  case 66:
#line 393 "csynan.yxx"
    {
            yyval.binopt = CBinOp::Assign;
        }
    break;

  case 67:
#line 398 "csynan.yxx"
    {
            yyval.binopt = CBinOp::MultAss;
        }
    break;

  case 68:
#line 403 "csynan.yxx"
    {
            yyval.binopt = CBinOp::DivAss;
        }
    break;

  case 69:
#line 408 "csynan.yxx"
    {
            yyval.binopt = CBinOp::ModAss;
        }
    break;

  case 70:
#line 413 "csynan.yxx"
    {
            yyval.binopt = CBinOp::PlusAss;
        }
    break;

  case 71:
#line 418 "csynan.yxx"
    {
            yyval.binopt = CBinOp::MinusAss;
        }
    break;

  case 72:
#line 423 "csynan.yxx"
    {
            yyval.binopt = CBinOp::LShiftAss;
        }
    break;

  case 73:
#line 428 "csynan.yxx"
    {
            yyval.binopt = CBinOp::RShiftAss;
        }
    break;

  case 74:
#line 433 "csynan.yxx"
    {
            yyval.binopt = CBinOp::BAndAss;
        }
    break;

  case 75:
#line 438 "csynan.yxx"
    {
            yyval.binopt = CBinOp::XorAss;
        }
    break;

  case 76:
#line 443 "csynan.yxx"
    {
            yyval.binopt = CBinOp::BOrAss;
        }
    break;

  case 77:
#line 450 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 78:
#line 455 "csynan.yxx"
    {
            throw std::string("Operator comma not supported.");
        }
    break;

  case 79:
#line 462 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 80:
#line 469 "csynan.yxx"
    {
            yyval.ast = new CDecl((CDeclSpec *)yyvsp[-1].ast, NULL, NULL);
        }
    break;

  case 81:
#line 474 "csynan.yxx"
    {
            yyval.ast = new CDecl((CDeclSpec *)yyvsp[-2].ast, (CInitDecl *)yyvsp[-1].ast, NULL);
        }
    break;

  case 82:
#line 481 "csynan.yxx"
    {
            throw std::string("storage_class_specifier not supported");
        }
    break;

  case 83:
#line 486 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 84:
#line 491 "csynan.yxx"
    {
            yyval.ast = new CTypeSpec(yyvsp[0].tstp, NULL); 
        }
    break;

  case 85:
#line 496 "csynan.yxx"
    {
            yyval.ast = new CTypeSpec(yyvsp[-1].tstp, (CDeclSpec *)yyvsp[0].ast);
        }
    break;

  case 86:
#line 501 "csynan.yxx"
    {
            throw std::string("type_qualifier not supported.");
        }
    break;

  case 87:
#line 506 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 88:
#line 513 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 89:
#line 519 "csynan.yxx"
    {
            ((CInitDecl *)(yyvsp[-2].ast))->setNext((CInitDecl *)yyvsp[0].ast);
            yyval.ast = yyvsp[-2].ast;
        }
    break;

  case 90:
#line 527 "csynan.yxx"
    {
            yyval.ast = new CInitDecl((CDeclarator *)yyvsp[0].ast, NULL, NULL);
        }
    break;

  case 91:
#line 532 "csynan.yxx"
    {
            yyval.ast = new CInitDecl((CDeclarator *)yyvsp[-2].ast, (CExpr *)yyvsp[0].ast, NULL);
        }
    break;

  case 97:
#line 547 "csynan.yxx"
    {
            yyval.tstp = CTypeSpec::Void;
        }
    break;

  case 98:
#line 552 "csynan.yxx"
    {
            yyval.tstp = CTypeSpec::Char;
        }
    break;

  case 99:
#line 557 "csynan.yxx"
    {
            yyval.tstp = CTypeSpec::Short;
        }
    break;

  case 100:
#line 562 "csynan.yxx"
    {
            yyval.tstp = CTypeSpec::Int;
        }
    break;

  case 101:
#line 567 "csynan.yxx"
    {
            yyval.tstp = CTypeSpec::Long;
        }
    break;

  case 102:
#line 572 "csynan.yxx"
    {
            yyval.tstp = CTypeSpec::Float;
        }
    break;

  case 103:
#line 577 "csynan.yxx"
    {
            yyval.tstp = CTypeSpec::Double;
        }
    break;

  case 104:
#line 582 "csynan.yxx"
    {
            yyval.tstp = CTypeSpec::Signed;
        }
    break;

  case 105:
#line 587 "csynan.yxx"
    {
            yyval.tstp = CTypeSpec::Unsigned;
        }
    break;

  case 106:
#line 592 "csynan.yxx"
    {
            throw std::string("struct_or_union_specifier not supported.");
        }
    break;

  case 107:
#line 597 "csynan.yxx"
    {
            throw std::string("enum_specifier not supported.");
        }
    break;

  case 108:
#line 602 "csynan.yxx"
    {
            throw std::string("TYPE_NAME not supported.");
        }
    break;

  case 109:
#line 609 "csynan.yxx"
    {
            throw std::string("struct_or_union_specifier not supported.");
        }
    break;

  case 110:
#line 614 "csynan.yxx"
    {
            throw std::string("struct_or_union_specifier not supported.");
        }
    break;

  case 111:
#line 619 "csynan.yxx"
    {
            throw std::string("struct_or_union_specifier not supported.");
        }
    break;

  case 135:
#line 679 "csynan.yxx"
    {
            throw std::string("Pointers not supported.");
        }
    break;

  case 136:
#line 684 "csynan.yxx"
    {
            yyval.ast = new CDeclarator(CDeclarator::DirectDecl, (CIdent *)yyvsp[0].ast);
        }
    break;

  case 137:
#line 691 "csynan.yxx"
    {
            yyval.ast = new CIdent(*yyvsp[0].str);
        }
    break;

  case 138:
#line 696 "csynan.yxx"
    {
            yyval.ast = yyvsp[-1].ast;
        }
    break;

  case 139:
#line 701 "csynan.yxx"
    {
            throw std::string("Arrays not supported.");
        }
    break;

  case 140:
#line 706 "csynan.yxx"
    {
            throw std::string("Arrays not supported.");
        }
    break;

  case 141:
#line 711 "csynan.yxx"
    {
            throw std::string("direct_declarator '(' parameter_type_list ')' "
                              "not supported.");
        }
    break;

  case 142:
#line 717 "csynan.yxx"
    {
            throw std::string("direct_declarator '(' identifier_list ')' "
                              "not supported.");
        }
    break;

  case 143:
#line 723 "csynan.yxx"
    {
            /* !!! doplnit !!! */
        }
    break;

  case 161:
#line 768 "csynan.yxx"
    {
            throw std::string("abstract_declarator not supported.");
        }
    break;

  case 162:
#line 773 "csynan.yxx"
    {
            throw std::string("abstract_declarator not supported.");
        }
    break;

  case 163:
#line 778 "csynan.yxx"
    {
            throw std::string("abstract_declarator not supported.");
        }
    break;

  case 173:
#line 797 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 174:
#line 802 "csynan.yxx"
    {
            throw std::string("Initializers of structured types not supported.");
        }
    break;

  case 175:
#line 807 "csynan.yxx"
    {
            throw std::string("Initializers of structured types not supported.");
        }
    break;

  case 178:
#line 819 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 179:
#line 824 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 180:
#line 829 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 181:
#line 834 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 182:
#line 839 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 183:
#line 844 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 184:
#line 851 "csynan.yxx"
    {
            throw std::string("Labels not supported.");
        }
    break;

  case 185:
#line 856 "csynan.yxx"
    {
            yyval.ast = new CLabeledStatement(CLabeledStatement::Case, 
                (CConstExpr *)yyvsp[-2].ast, (CStatement *)yyvsp[0].ast, NULL);
        }
    break;

  case 186:
#line 862 "csynan.yxx"
    {
            yyval.ast = new CLabeledStatement(CLabeledStatement::Default, NULL, 
                (CStatement *)yyvsp[0].ast, NULL);
        }
    break;

  case 187:
#line 870 "csynan.yxx"
    {
            //$$.ast = NULL; // ???
            yyval.ast = new CCompoundStatement(NULL, NULL, NULL);
        }
    break;

  case 188:
#line 876 "csynan.yxx"
    {
            yyval.ast = new CCompoundStatement(NULL, (CStatement *)yyvsp[-1].ast, NULL);
        }
    break;

  case 189:
#line 881 "csynan.yxx"
    {
            yyval.ast = new CCompoundStatement((CDecl *)yyvsp[-1].ast, NULL, NULL);
        }
    break;

  case 190:
#line 886 "csynan.yxx"
    {
            yyval.ast = new CCompoundStatement((CDecl *)yyvsp[-2].ast, (CStatement *)yyvsp[-1].ast, 
                NULL);
        }
    break;

  case 191:
#line 894 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 192:
#line 900 "csynan.yxx"
    {
          (dynamic_cast<CDecl *>(yyvsp[-1].ast))->setNext
            (dynamic_cast<CDecl *>(yyvsp[0].ast));
            yyval.ast = yyvsp[-1].ast;
        }
    break;

  case 193:
#line 909 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 194:
#line 915 "csynan.yxx"
    {
          (dynamic_cast<CStatement *>(yyvsp[-1].ast))->setNext
            (dynamic_cast<CStatement *>(yyvsp[0].ast));
            yyval.ast = yyvsp[-1].ast;
        }
    break;

  case 195:
#line 924 "csynan.yxx"
    {
            yyval.ast = new CExprStatement(NULL, NULL);
        }
    break;

  case 196:
#line 929 "csynan.yxx"
    {
            yyval.ast = new CExprStatement((CExpr *)yyvsp[-1].ast, NULL);
        }
    break;

  case 197:
#line 936 "csynan.yxx"
    {
            throw std::string("'If' statement not supported.");
        }
    break;

  case 198:
#line 941 "csynan.yxx"
    {
            throw std::string("'If' statement not supported.");
        }
    break;

  case 199:
#line 946 "csynan.yxx"
    {
            yyval.ast = new CSelectionStatement(CSelectionStatement::Switch, 
                (CExpr *)yyvsp[-2].ast, (CStatement *)yyvsp[0].ast, NULL, NULL);
        }
    break;

  case 200:
#line 954 "csynan.yxx"
    {
            yyval.ast = new CIterationStatement(CIterationStatement::While, 
                (CExpr *)yyvsp[-2].ast, (CStatement *)yyvsp[0].ast, NULL);
        }
    break;

  case 201:
#line 960 "csynan.yxx"
    {
            throw std::string("'Do' statement not supported.");
        }
    break;

  case 202:
#line 965 "csynan.yxx"
    {
            throw std::string("'For' statement not supported.");
        }
    break;

  case 203:
#line 970 "csynan.yxx"
    {
            throw std::string("'For' statement not supported.");
        }
    break;

  case 204:
#line 977 "csynan.yxx"
    {
            throw std::string("'Goto' statement not supported.");
        }
    break;

  case 205:
#line 982 "csynan.yxx"
    {
            yyval.ast = new CJumpStatement(CJumpStatement::Continue, NULL, NULL);
        }
    break;

  case 206:
#line 987 "csynan.yxx"
    {
            yyval.ast = new CJumpStatement(CJumpStatement::Break, NULL, NULL);
        }
    break;

  case 207:
#line 992 "csynan.yxx"
    {
            yyval.ast = new CJumpStatement(CJumpStatement::Return, NULL, NULL);
        }
    break;

  case 208:
#line 997 "csynan.yxx"
    {
            yyval.ast = new CJumpStatement(CJumpStatement::Return, (CExpr *)yyvsp[-1].ast, 
                NULL);
        }
    break;

  case 211:
#line 1010 "csynan.yxx"
    {
            *((CCompoundStatement **)YYPARSE_PARAM) = (CCompoundStatement *)yyvsp[0].ast;
        }
    break;

  case 212:
#line 1015 "csynan.yxx"
    {
            throw std::string("External declaration not supported.");
        }
    break;

  case 213:
#line 1022 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 214:
#line 1027 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 215:
#line 1032 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;

  case 216:
#line 1037 "csynan.yxx"
    {
            yyval.ast = yyvsp[0].ast;
        }
    break;


    }

/* Line 999 of yacc.c.  */
#line 2799 "csynan.cxx"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1042 "csynan.yxx"


void yyerror (char *s)
{		
    std::cerr << filename << ": " << s << std::endl;
}
 
 

