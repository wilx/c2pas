#ifndef _DEFINES_HXX_
#define _DEFINES_HXX_

#include "ast.hxx"

union yystype {
    CUnOp::Type unopt;
    CBinOp::Type binopt;
    CDeclSpec::Type dstp;
    CTypeSpec::Type tstp;
    ASTBase * ast;
    std::string * str;
    long double fpval;
    long long int intval;
    unsigned long long int uintval;
    char charval;
    bool boolval;
};
#define YYSTYPE yystype

#endif // _DEFINES_HXX_
