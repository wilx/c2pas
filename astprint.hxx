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
