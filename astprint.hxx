#idndef _ASTPRINT_HXX_
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

std::map<std::string, ASTInfo *> pidents;
std::list<CDecl *> decls;
std::ostream * outs;

std::pair<std::string, ASTInfo *> findname(const std::string &, ASTInfo &);
std::string insertname(const std::string &, ASTInfo &);

void astprint (CCompoundStatement *, ASTInfo &);

#endif // _ASTPRINT_HXX_
