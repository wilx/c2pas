#ifndef LEXAN_HXX
#define LEXAN_HXX

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <csynan.hxx>

struct LexanVal { 
    std::string str;
    union {
	char chval;
	long double fpval;
	long long int intval;
	unsigned long long int uintval;
    };
};

#define LEXANVAL LexanVal
#define YYSVAL LEXANVAL

#define GETCHAR() lexan_input->get()
#define UNGETCH() lexan_input->unget()
#define ERROR() _ERROR()
#define _ERROR() { \
    std::ostringstream oss; \
    oss << __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__; \
    throw std::string(oss.str()); \
}

typedef short Token;
/* specialni tokeny */
#define TOK_EOF  0
#define TOK_ERROR  -1
/* oddelovace a operatory */
/*
#define TOK_NOT  256
#define TOK_QUOTMARK  257
#define TOK_MOD  258
#define TOK_BAND  259
#define TOK_APOSTROPHE  260
#define TOK_LRBRACKET  261
#define TOK_RRBRACKET  262
#define TOK_MULT  263
#define TOK_PLUS  264
#define TOK_COMMA  265
#define TOK_MINUS  266
#define TOK_DOT  267
#define TOK_DIV  268
#define TOK_COLON  269
#define TOK_SEMICOLON  270
#define TOK_LT  271
#define TOK_EQSIGN  272
#define TOK_GT  273
#define TOK_QUESMARK  274
#define TOK_LSBRACKET  275
#define TOK_RSBRACKET  276
#define TOK_XOR  277
#define TOK_LBRACE  278
#define TOK_BOR  279
#define TOK_RBRACE  280
#define TOK_TILDE  281
#define TOK_NE  282
#define TOK_MODEQ  283
#define TOK_LAND  284
#define TOK_ANDEQ  285
#define TOK_MULTEQ  286
#define TOK_PLUSPLUS  287
#define TOK_PLUSEQ  288
#define TOK_MINMIN  289
#define TOK_MINUSEQ  290
#define TOK_ARROW  291
#define TOK_DIVEQ  292
#define TOK_LSHIFT  293
#define TOK_LE  294
#define TOK_EQ  295
#define TOK_GE  296
#define TOK_RSHIFT  297
#define TOK_XOREQ  298
#define TOK_OREQ  299
#define TOK_LOR  300
#define TOK_ELLIPSIS  301
#define TOK_LSHIFTEQ  302
#define TOK_RSHIFTEQ  303*/
/* klicova slova */
/*#define TOK_INT  304
#define TOK_CHAR  305
#define TOK_LONG  306
#define TOK_UNSIGNED  307
#define TOK_FLOAT  308
#define TOK_DOUBLE  309
#define TOK_CONST  310
#define TOK_WHILE  311
#define TOK_IF  312
#define TOK_GOTO  313
#define TOK_STRUCT  314
#define TOK_TYPEDEF  315
#define TOK_ENUM  316
#define TOK_UNION  317
#define TOK_DO  318*/
/* ostatni tokeny */
/*#define TOK_IDENT  319
#define TOK_FPNUM  320
#define TOK_INTNUM  321
#define TOK_UINTNUM  322
#define TOK_CHARVAL  323
#define TOK_STRING  324*/
/* tokeny doplnene pozdeji */
/*#define TOK_VOLATILE 325
#define TOK_SIZEOF 326
#define TOK_EXTERN 327
#define TOK_STATIC 328
#define TOK_AUTO 329
#define TOK_REGISTER 330
#define TOK_SWITCH 331
#define TOK_CASE 332
#define TOK_DEFAULT 333
#define TOK_CONTINUE 334
#define TOK_BREAK 335
#define TOK_RETURN 336*/

extern std::istream * lexan_input;
extern LEXANVAL lexan_val;

extern Token lexan (void);
extern void lexan_init(std::istream &);

#endif // LEXAN_HXX
