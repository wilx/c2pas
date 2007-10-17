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
#include <sstream>
#include "lexan.hxx"
#include "csynan.hxx"
#include "ast.hxx"
#include "astprint.hxx"

extern int yyparse (void *);

int main (void)
{
    extern int yydebug;
    yydebug = 0;
    try {
        lexan_init(std::cin);
        CCompoundStatement * tree;
        yyparse(&tree);
        std::cerr << "after yyparse()" << std::endl;
	/* prvni vystup tela funkce do docasneho streamu */
	std::ostringstream body;
	astprint_comp_statement (tree, new ASTInfo(NULL, 1, tree), body);
	
	/* vystup hlavni funkce */
	std::cout << "procedure main;" << std::endl;
	{
            /* vystup labelu */
            labelsprint (labels, std::cout);
	    /* vystup deklaraci */
	    std::cout << "var" << std::endl;
	    declsprint(decls, std::cout);
	    
	    /* vystup tela */
	    std::cout << "begin" << std::endl;
	    std::cout << body.str();
	    std::cout << ";" << std::endl << "end;" << std::endl;
	}
	std::cout << "begin" << std::endl 
		  << "main;" << std::endl
		  << "end." << std::endl;

        delete tree;
    }
    catch (std::string & e) {
	std::cerr << e << std::endl;
    }
    catch (...) {
	std::cerr << "exception caught" << std::endl;
	throw;
    }
}
