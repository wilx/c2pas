#ifndef _ASTPRINT_HXX_
#define _ASTPRINT_HXX_

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <list>
#include "ast.hxx"

struct ASTInfo {
    /** Ukazatel na rodicovsky jmenny prostor */
    ASTInfo * parent;
    /** Hloubka vnoreni bloku */
    int block;
    /** Mapa prekladajici C identifikatory na Pascalske identifikatory */
    std::map<std::string, std::string> idents;
    

    ASTInfo(ASTInfo *, int);
};

extern std::map<std::string, ASTInfo *> pidents;
extern std::list<CDecl *> decls;
extern int blocks;
extern std::ostream * outs;


#endif // _ASTPRINT_HXX_
