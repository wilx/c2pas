#ifndef LEXAN_HXX
#define LEXAN_HXX

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "defines.hxx"
#include "csynan.hxx"

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

extern std::istream * lexan_input;

extern Token lexan (void);
extern void lexan_init(std::istream &);

#endif // LEXAN_HXX
