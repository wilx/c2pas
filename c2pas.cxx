
#include <iostream>
#include "lexan.hxx"
#include "csynan.hxx"
#include "ast.hxx"

extern int yyparse (void *);

int main (void)
{
    extern int yydebug;
    yydebug = 1;
    try {
        lexan_init(std::cin);
        CCompoundStatement * tree;
        yyparse(&tree);
        std::cerr << "after yyparse()" << std::endl;
        delete tree;
    }
    catch (...) {
        std::cerr << "exception caught" << std::endl;
    }
}
