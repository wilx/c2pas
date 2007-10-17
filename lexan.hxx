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
