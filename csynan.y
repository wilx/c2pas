%{
#include <iostream>
%}

%token TOK_INT TOK_CHAR TOK_LONG TOK_UNSIGNED TOK_FLOAT TOK_DOUBLE
%token TOK_CONST TOK_WHILE TOK_IF TOK_GOTO TOK_STRUCT TOK_TYPEDEF TOK_ENUM
%token TOK_UNION

%start start

%%

start: 
;

%%

void yyerror (char *s)
{		
    std::cerr << filename << ":" << yylineno << " " << s << std::endl;
}
