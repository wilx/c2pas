#ifndef LEXAN_HXX
#define LEXAN_HXX

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

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

#define GETCHAR() lexan_input->get()
#define UNGETCH() lexan_input->unget()
#define ERROR() _ERROR()
#define _ERROR() { \
    std::ostringstream oss; \
    oss << __FILE__ << ":" << __LINE__ << ":" << __PRETTY_FUNCTION__; \
    throw std::string(oss.str()); \
}


const short POCETSTAVU = 50;

enum Token {
/* specialni tokeny */
    TOK_EOF = -2,
    TOK_ERROR = -1,
/* oddelovace a operatory */
    TOK_NOT = 256,
    TOK_QUOTMARK = 257,
    TOK_MOD = 258,
    TOK_BAND = 259,
    TOK_APOSTROPHE = 260,
    TOK_LRBRACKET = 261,
    TOK_RRBRACKET = 262,
    TOK_MULT = 263,
    TOK_PLUS = 264,
    TOK_COMMA = 265,
    TOK_MINUS = 266,
    TOK_DOT = 267,
    TOL_DIV = 268,
    TOK_COLON = 269,
    TOK_SEMICOLON = 270,
    TOK_LT = 271,
    TOK_EQSIGN = 272,
    TOK_GT = 273,
    TOK_QUESMARK = 274,
    TOK_LSBRACKET = 275,
    TOK_RSBRACKET = 276,
    TOK_XOR = 277,
    TOK_LBRACE = 278,
    TOK_BOR = 279,
    TOK_RBRACE = 280,
    TOK_TILDE = 281,
    TOK_NE = 282,
    TOK_MODEQ = 283,
    TOK_LAND = 284,
    TOK_ANDEQ = 285,
    TOK_MULTEQ = 286,
    TOK_PLUSPLUS = 287,
    TOK_PLUSEQ = 288,
    TOK_MINMIN = 289,
    TOK_MINUSEQ = 290,
    TOK_ARROW = 291,
    TOK_DIVEQ = 292,
    TOK_LSHIFT = 293,
    TOK_LE = 294,
    TOK_EQ = 295,
    TOK_GE = 296,
    TOK_RSHIFT = 297,
    TOK_XOREQ = 298,
    TOK_OREQ = 299,
    TOK_LOR = 300,
    TOK_ELIPSE = 301,
    TOK_LSHIFTEQ = 302,
    TOK_RSHIFTEQ = 303,
/* klicova slova */
    TOK_INT = 304,
    TOK_CHAR = 305,
    TOK_LONG = 306,
    TOK_UNSIGNED = 307,
    TOK_FLOAT = 308,
    TOK_DOUBLE = 309,
    TOK_CONST = 310,
    TOK_WHILE = 311,
    TOK_IF = 312,
    TOK_GOTO = 313,
    TOK_STRUCT = 314,
    TOK_TYPEDEF = 315,
    TOK_ENUM = 316,
    TOK_UNION = 317,
    TOK_DO = 318,
/* ostatni tokeny */
    TOK_IDENT = 319,
    TOK_FPNUM = 320,
    TOK_INTNUM = 321,
    TOK_UINTNUM = 322,
    TOK_CHARVAL = 323,
    TOK_STRING = 324
};

extern std::istream * lexan_input;
extern LEXANVAL lexan_val;

extern Token lexan (void);
extern void lexan_init(std::istream &);

#endif // LEXAN_HXX
