/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



