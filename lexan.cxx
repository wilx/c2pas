#include <lexan.hxx>
#include <map>
#include <utility>
#include <ios>
#include <cmath>

std::istream * lexan_input;
LEXANVAL lexan_val;

static std::map<std::string, Token> kslova;

static const char * const kstavyjmena[POCETSTAVU] =
{
    /* 0 */ NULL,
    /* 1 */ "TOK_NOT",
    /* 2 */ "TOK_QUOTMARK",
    /* 3 */ "TOK_MOD",
    /* 4 */ "TOK_BAND",
    /* 5 */ "TOK_APOSTROPHE",
    /* 6 */ "TOK_LRBRACKET",
    /* 7 */ "TOK_RRBRACKET",
    /* 8 */ "TOK_MULT",
    /* 9 */ "TOK_PLUS",
    /* 10 */ "TOK_COMMA",
    /* 11 */ "TOK_MINUS",
    /* 12 */ "TOK_DOT",
    /* 13 */ "TOL_DIV",
    /* 14 */ "TOK_COLON",
    /* 15 */ "TOK_SEMICOLON",
    /* 16 */ "TOK_LT",
    /* 17 */ "TOK_EQSIGN",
    /* 18 */ "TOK_GT",
    /* 19 */ "TOK_QUESMARK",
    /* 20 */ "TOK_LSBRACKET",
    /* 21 */ "TOK_RSBRACKET",
    /* 22 */ "TOK_XOR",
    /* 23 */ "TOK_LBRACE",
    /* 24 */ "TOK_BOR",
    /* 25 */ "TOK_RBRACE",
    /* 26 */ "TOK_TILDE",
    /* 27 */ "TOK_NE",
    /* 28 */ "TOK_MODEQ",
    /* 29 */ "TOK_LAND",
    /* 30 */ "TOK_ANDEQ",
    /* 31 */ "TOK_MULTEQ",
    /* 32 */ "TOK_PLUSPLUS",
    /* 33 */ "TOK_PLUSEQ",
    /* 34 */ "TOK_MINMIN",
    /* 35 */ "TOK_MINUSEQ",
    /* 36 */ "TOK_ARROW",
    /* 37 */ NULL,
    /* 38 */ "TOK_DIVEQ",
    /* 39 */ "TOK_LSHIFT",
    /* 40 */ "TOK_LE",
    /* 41 */ "TOK_EQ",
    /* 42 */ "TOK_GE",
    /* 43 */ "TOK_RSHIFT",
    /* 44 */ "TOK_XOREQ",
    /* 45 */ "TOK_OREQ",
    /* 46 */ "TOK_LOR",
    /* 47 */ "TOK_ELIPSE",
    /* 48 */ "TOK_LSHIFTEQ",
    /* 49 */ "TOK_RSHIFTEQ",
};

static const char kstavy[POCETSTAVU] =
{
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
};

static Token lexan_cislo (char, bool);
static Token lexan_mozna_cislo (char);
static Token lexan_kslovo_nebo_ident (char);

Token lexan (void)
{
    short poslednikstav = -1;
    Token token = TOK_ERROR;
    int ch;

    try {
	{
	  /* prefix: "" */
	  ch = GETCHAR();
	  switch (ch) {
	  case '!': {
	      goto stav_1;
	  }
	  case '"': {
	      goto stav_2;
	  }
	  case '%': {
	      goto stav_3;
	  }
	  case '&': {
	      goto stav_4;
	  }
	  case '\'': {
	      goto stav_5;
	  }
	  case '(': {
	      goto stav_6;
	  }
	  case ')': {
	      goto stav_7;
	  }
	  case '*': {
	      goto stav_8;
	  }
	  case '+': {
	      goto stav_9;
	  }
	  case ',': {
	      goto stav_10;
	  }
	  case '-': {
	      goto stav_11;
	  }
	  case '.': {
	      goto stav_12;
	  }
	  case '/': {
	      goto stav_13;
	  }
	  case ':': {
	      goto stav_14;
	  }
	  case ';': {
	      goto stav_15;
	  }
	  case '<': {
	      goto stav_16;
	  }
	  case '=': {
	      goto stav_17;
	  }
	  case '>': {
	      goto stav_18;
	  }
	  case '?': {
	      goto stav_19;
	  }
	  case '[': {
	      goto stav_20;
	  }
	  case ']': {
	      goto stav_21;
	  }
	  case '^': {
	      goto stav_22;
	  }
	  case '{': {
	      goto stav_23;
	  }
	  case '|': {
	      goto stav_24;
	  }
	  case '}': {
	      goto stav_25;
	  }
	  case '~': {
	      goto stav_26;
	  }
	  default: {
	      if (isalpha(ch))
		  return lexan_kslovo_nebo_ident(ch);
	      if (isdigit(ch))
		  return lexan_mozna_cislo(ch);
	      goto lexan_error;
	  }
	  }
      }

      stav_1: {
	  /* prefix: "!" */
	  /* konecny stav */
	  token = TOK_NOT;
	  poslednikstav = 1;
	  ch = GETCHAR();
	  switch (ch) {
	  case '=': {
	      goto stav_27;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_2: {
	  /* prefix: """ */
	  /* konecny stav */
	  token = TOK_QUOTMARK;
	  poslednikstav = 2;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_3: {
	  /* prefix: "%" */
	  /* konecny stav */
	  token = TOK_MOD;
	  poslednikstav = 3;
	  ch = GETCHAR();
	  switch (ch) {
	  case '=': {
	      goto stav_28;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_4: {
	  /* prefix: "&" */
	  /* konecny stav */
	  token = TOK_BAND;
	  poslednikstav = 4;
	  ch = GETCHAR();
	  switch (ch) {
	  case '&': {
	      goto stav_29;
	  }
	  case '=': {
	      goto stav_30;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_5: {
	  /* prefix: "'" */
	  /* konecny stav */
	  token = TOK_APOSTROPHE;
	  poslednikstav = 5;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_6: {
	  /* prefix: "(" */
	  /* konecny stav */
	  token = TOK_LRBRACKET;
	  poslednikstav = 6;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_7: {
	  /* prefix: ")" */
	  /* konecny stav */
	  token = TOK_RRBRACKET;
	  poslednikstav = 7;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_8: {
	  /* prefix: "*" */
	  /* konecny stav */
	  token = TOK_MULT;
	  poslednikstav = 8;
	  ch = GETCHAR();
	  switch (ch) {
	  case '=': {
	      goto stav_31;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_9: {
	  /* prefix: "+" */
	  /* konecny stav */
	  token = TOK_PLUS;
	  poslednikstav = 9;
	  ch = GETCHAR();
	  switch (ch) {
	  case '+': {
	      goto stav_32;
	  }
	  case '=': {
	      goto stav_33;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_10: {
	  /* prefix: "," */
	  /* konecny stav */
	  token = TOK_COMMA;
	  poslednikstav = 10;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_11: {
	  /* prefix: "-" */
	  /* konecny stav */
	  token = TOK_MINUS;
	  poslednikstav = 11;
	  ch = GETCHAR();
	  switch (ch) {
	  case '-': {
	      goto stav_34;
	  }
	  case '=': {
	      goto stav_35;
	  }
	  case '>': {
	      goto stav_36;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_12: {
	  /* prefix: "." */
	  /* konecny stav */
	  token = TOK_DOT;
	  poslednikstav = 12;
	  ch = GETCHAR();
	  switch (ch) {
	  case '.': {
	      goto stav_37;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_13: {
	  /* prefix: "/" */
	  /* konecny stav */
	  token = TOL_DIV;
	  poslednikstav = 13;
	  ch = GETCHAR();
	  switch (ch) {
	  case '=': {
	      goto stav_38;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_14: {
	  /* prefix: ":" */
	  /* konecny stav */
	  token = TOK_COLON;
	  poslednikstav = 14;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_15: {
	  /* prefix: ";" */
	  /* konecny stav */
	  token = TOK_SEMICOLON;
	  poslednikstav = 15;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_16: {
	  /* prefix: "<" */
	  /* konecny stav */
	  token = TOK_LT;
	  poslednikstav = 16;
	  ch = GETCHAR();
	  switch (ch) {
	  case '<': {
	      goto stav_39;
	  }
	  case '=': {
	      goto stav_40;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_17: {
	  /* prefix: "=" */
	  /* konecny stav */
	  token = TOK_EQSIGN;
	  poslednikstav = 17;
	  ch = GETCHAR();
	  switch (ch) {
	  case '=': {
	      goto stav_41;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_18: {
	  /* prefix: ">" */
	  /* konecny stav */
	  token = TOK_GT;
	  poslednikstav = 18;
	  ch = GETCHAR();
	  switch (ch) {
	  case '=': {
	      goto stav_42;
	  }
	  case '>': {
	      goto stav_43;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_19: {
	  /* prefix: "?" */
	  /* konecny stav */
	  token = TOK_QUESMARK;
	  poslednikstav = 19;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_20: {
	  /* prefix: "[" */
	  /* konecny stav */
	  token = TOK_LSBRACKET;
	  poslednikstav = 20;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_21: {
	  /* prefix: "]" */
	  /* konecny stav */
	  token = TOK_RSBRACKET;
	  poslednikstav = 21;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_22: {
	  /* prefix: "^" */
	  /* konecny stav */
	  token = TOK_XOR;
	  poslednikstav = 22;
	  ch = GETCHAR();
	  switch (ch) {
	  case '=': {
	      goto stav_44;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_23: {
	  /* prefix: "{" */
	  /* konecny stav */
	  token = TOK_LBRACE;
	  poslednikstav = 23;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_24: {
	  /* prefix: "|" */
	  /* konecny stav */
	  token = TOK_BOR;
	  poslednikstav = 24;
	  ch = GETCHAR();
	  switch (ch) {
	  case '=': {
	      goto stav_45;
	  }
	  case '|': {
	      goto stav_46;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_25: {
	  /* prefix: "}" */
	  /* konecny stav */
	  token = TOK_RBRACE;
	  poslednikstav = 25;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_26: {
	  /* prefix: "~" */
	  /* konecny stav */
	  token = TOK_TILDE;
	  poslednikstav = 26;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_27: {
	  /* prefix: "!=" */
	  /* konecny stav */
	  token = TOK_NE;
	  poslednikstav = 27;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_28: {
	  /* prefix: "%=" */
	  /* konecny stav */
	  token = TOK_MODEQ;
	  poslednikstav = 28;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_29: {
	  /* prefix: "&&" */
	  /* konecny stav */
	  token = TOK_LAND;
	  poslednikstav = 29;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_30: {
	  /* prefix: "&=" */
	  /* konecny stav */
	  token = TOK_ANDEQ;
	  poslednikstav = 30;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_31: {
	  /* prefix: "*=" */
	  /* konecny stav */
	  token = TOK_MULTEQ;
	  poslednikstav = 31;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_32: {
	  /* prefix: "++" */
	  /* konecny stav */
	  token = TOK_PLUSPLUS;
	  poslednikstav = 32;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_33: {
	  /* prefix: "+=" */
	  /* konecny stav */
	  token = TOK_PLUSEQ;
	  poslednikstav = 33;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_34: {
	  /* prefix: "--" */
	  /* konecny stav */
	  token = TOK_MINMIN;
	  poslednikstav = 34;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_35: {
	  /* prefix: "-=" */
	  /* konecny stav */
	  token = TOK_MINUSEQ;
	  poslednikstav = 35;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_36: {
	  /* prefix: "->" */
	  /* konecny stav */
	  token = TOK_ARROW;
	  poslednikstav = 36;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_37: {
	  /* prefix: ".." */
	  ch = GETCHAR();
	  switch (ch) {
	  case '.': {
	      goto stav_47;
	  }
	  default: {
	      goto lexan_error;
	  }
	  }
      }

      stav_38: {
	  /* prefix: "/=" */
	  /* konecny stav */
	  token = TOK_DIVEQ;
	  poslednikstav = 38;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_39: {
	  /* prefix: "<<" */
	  /* konecny stav */
	  token = TOK_LSHIFT;
	  poslednikstav = 39;
	  ch = GETCHAR();
	  switch (ch) {
	  case '=': {
	      goto stav_48;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_40: {
	  /* prefix: "<=" */
	  /* konecny stav */
	  token = TOK_LE;
	  poslednikstav = 40;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_41: {
	  /* prefix: "==" */
	  /* konecny stav */
	  token = TOK_EQ;
	  poslednikstav = 41;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_42: {
	  /* prefix: ">=" */
	  /* konecny stav */
	  token = TOK_GE;
	  poslednikstav = 42;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_43: {
	  /* prefix: ">>" */
	  /* konecny stav */
	  token = TOK_RSHIFT;
	  poslednikstav = 43;
	  ch = GETCHAR();
	  switch (ch) {
	  case '=': {
	      goto stav_49;
	  }
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_44: {
	  /* prefix: "^=" */
	  /* konecny stav */
	  token = TOK_XOREQ;
	  poslednikstav = 44;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_45: {
	  /* prefix: "|=" */
	  /* konecny stav */
	  token = TOK_OREQ;
	  poslednikstav = 45;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_46: {
	  /* prefix: "||" */
	  /* konecny stav */
	  token = TOK_LOR;
	  poslednikstav = 46;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_47: {
	  /* prefix: "..." */
	  /* konecny stav */
	  token = TOK_ELIPSE;
	  poslednikstav = 47;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_48: {
	  /* prefix: "<<=" */
	  /* konecny stav */
	  token = TOK_LSHIFTEQ;
	  poslednikstav = 48;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }

      stav_49: {
	  /* prefix: ">>=" */
	  /* konecny stav */
	  token = TOK_RSHIFTEQ;
	  poslednikstav = 49;
	  ch = GETCHAR();
	  switch (ch) {
	  default: {
	      UNGETCH();
	      goto lexan_konec;
	  }
	  }
      }
    }
    catch (std::istream::failure& e) {
	std::cerr << "Chycena vyjimka v " << __PRETTY_FUNCTION__ << ": "
		  << __FILE__ << ":" << __LINE__ << ":"
		  << e.what() << std::endl;
	if (! lexan_input->eof()) 
	    std::cerr << "Neni to EOF. Vazna chyba!!" << std::endl;
    }
  lexan_error:
    return TOK_ERROR;

  lexan_konec:
    return token;
}

void lexan_init(std::istream & input)
{
    lexan_input = &input;
    lexan_input->exceptions(std::ios::failbit | std::ios::badbit);
    
    kslova.insert(std::make_pair(std::string("int"), TOK_INT));
    kslova.insert(std::make_pair(std::string("char"), TOK_CHAR));
    kslova.insert(std::make_pair(std::string("unsigned"), TOK_UNSIGNED));
    kslova.insert(std::make_pair(std::string("float"), TOK_FLOAT));
    kslova.insert(std::make_pair(std::string("double"), TOK_DOUBLE));
    kslova.insert(std::make_pair(std::string("const"), TOK_CONST));
    kslova.insert(std::make_pair(std::string("while"), TOK_WHILE));
    kslova.insert(std::make_pair(std::string("do"), TOK_DO));
    kslova.insert(std::make_pair(std::string("if"), TOK_IF));
    kslova.insert(std::make_pair(std::string("goto"), TOK_GOTO));
    kslova.insert(std::make_pair(std::string("struct"), TOK_STRUCT));
    kslova.insert(std::make_pair(std::string("typedef"), TOK_TYPEDEF));
    kslova.insert(std::make_pair(std::string("enum"), TOK_ENUM));
    kslova.insert(std::make_pair(std::string("union"), TOK_UNION));
}

static Token lexan_kslovo_nebo_ident (char ch)
{
    std::string str;
    
    do {
	str.push_back(ch);
	ch = GETCHAR();
    } while (isalnum(ch) || ch == '_');
    UNGETCH();
    
    std::map<std::string, Token>::const_iterator i;
    if ((i = kslova.find(str)) != kslova.end())
	return i->second;
    else {
	lexan_val.str = str;
	return TOK_IDENT;
    }
    
}

/* Lexikalni analyza cisla.
   Parametr ch je bud cislice nebo '.' */
static Token lexan_mozna_cislo (char ch)
{
    if (isdigit(ch))
	return lexan_cislo(ch, false);
    else {
	ch = GETCHAR();
	if (isdigit(ch))
	    return lexan_cislo(ch, true);
	return TOK_DOT;
    }
}

static Token lexan_cislo (char ch, bool fp)
{
    long double x = 0;
    int exp = 0, eexp = 0, esign = +1;
    
    if (fp) 
	goto fraction_part;
	    
    if (isdigit(ch)) {
	/* cislice pred desetinou teckou */
	do {
	    x = x*10 + ch - '0';
	    ch = GETCHAR(); 
	} while (isdigit(ch));
	if (ch == 'e' || ch == 'E')
	    goto exponent_part;
    }

  fraction_part:
    if (ch == '.') {
	fp = true;
	ch = GETCHAR();
	while (isdigit(ch)) {
	    --exp;
	    x = x*10 + ch - '0';
	    ch = GETCHAR();
	}
	if (ch == 'e' || ch == 'E')
	    goto exponent_part;
	goto konec;
    }
    
    /* cele cislo */
    if (! fp) {
	UNGETCH();
	if (x > 0) {
	    lexan_val.uintval = (unsigned long long int)x;
	    return TOK_UINTNUM;
	}
	else {
	    lexan_val.intval = (long long int)x;
	    return TOK_INTNUM;
	}
    }
    
  exponent_part:
    /* exponent */
    ch = GETCHAR();
    if (ch == '-') {
	esign = -1;
	ch = GETCHAR();
	goto exponent_digits;
    }
    if (ch == '+') {
	ch = GETCHAR();
	goto exponent_digits;
    }
    if (isdigit(ch))
	goto exponent_digits;
    else 
	ERROR();

  exponent_digits:
    if (! isdigit(ch))
	ERROR();
    while (isdigit(ch)) {
	eexp = eexp*10 + ch - '0';
	ch = GETCHAR();
    }

  konec:
    UNGETCH();
    lexan_val.fpval = x * pow(10, exp + esign*eexp);
    return TOK_FPNUM;
}
