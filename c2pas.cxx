
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
	astprint(tree, new ASTInfo(NULL, 1, tree), body);
	
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
