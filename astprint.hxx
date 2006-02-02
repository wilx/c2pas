#ifndef _ASTPRINT_HXX_
#define _ASTPRINT_HXX_

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <list>
#include "ast.hxx"


struct IdentInfo
{
  CTypeSpec * const tspec;
  const std::string name;

  IdentInfo (CTypeSpec *, const std::string &);
};


struct LabelInfo
{
  const CStatement * const stmt;
  const std::string name;

  LabelInfo (const CStatement *, const std::string &);
};


struct ASTInfo
{
  /** Ukazatel na rodicovsky jmenny prostor */
  ASTInfo * const parent;
  /** Hloubka vnoreni bloku */
  const int block;
  /** Mapa prekladajici C identifikatory na Pascalske identifikatory */
  std::map<std::string, IdentInfo *> * idents;
  /** Ukazatel na aktualni statement */
  CStatement * const astmt;

  ASTInfo (const ASTInfo *, int, const CStatement *);
  ASTInfo (const CStatement *, const ASTInfo *);
};


extern std::list<std::string> labels;
extern std::list<const CDecl *> decls;
extern std::list<const CBinOp *> initlist;

extern void astprint_comp_statement (const CCompoundStatement *, ASTInfo *, 
                                     std::ostream &);
extern void declsprint (std::list<const CDecl *> &, std::ostream &);
extern void labelsprint (std::list<std::string> const &, std::ostream &);

#endif // _ASTPRINT_HXX_
