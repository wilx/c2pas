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
#include <list>
#include <algorithm>
#include <cctype>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "astprint.hxx"
#include "join.hxx"
#include "switch.hxx"


static std::list<int> blocklist;
static int blocks;
static std::list<int> blockstack;

std::map<std::string, ASTInfo *> pidents;
std::list<const CDecl *> decls;
std::list<const CBinOp *> initlist;
//std::list<std::string, IdentInfo *> allidents;
std::list<std::string> labels;


IdentInfo::IdentInfo (CTypeSpec * td, const std::string & n)
  : tspec(td), name(n)
{ }


ASTInfo::ASTInfo(const ASTInfo * p, int b, const CStatement * s)
  : parent((ASTInfo *)p), block(b), astmt((CStatement *)s)
{
  idents = new std::map<std::string, IdentInfo *>();
}

ASTInfo::ASTInfo(const CStatement * s, const ASTInfo * ai)
  : parent((ASTInfo *)ai->parent), block(ai->block),
    idents(ai->idents), astmt((CStatement *)s)
{ }

LabelInfo::LabelInfo (const CStatement * s, const std::string & n)
  : stmt(s), name(n)
{ }


static inline
char
mytolower (char ch)
{
  return std::tolower(ch);
}

std::string
strtolower (const std::string & s)
{
  std::string ls(s.size(), ' ');
  std::transform(s.begin(), s.end(), ls.begin(), mytolower);
  return ls;
}

/*std::string escident (const std::string & s)
  {
  std::ostringstream es;

  for (std::string::const_iterator i = s.begin();
  i != s.end();
  ++i) {
  if (std::isupper(*i) || *i == '_')
  es << '_';
  es << *i;
  }
  return es.str();
  }*/

std::pair<std::string, ASTInfo *>
findident (const std::string & id, const ASTInfo * ai, bool clrlist = true)
{
  if (clrlist)
    blocklist.clear();
  if (ai->block != 0)
    blocklist.push_back(ai->block);
  std::map<std::string, IdentInfo *>::const_iterator i
    = ai->idents->find(id);
  if (i != ai->idents->end())
    //return make_pair(i->second->name, const_cast<ASTInfo *>(ai));
    return make_pair(i->second->name, const_cast<ASTInfo *>(ai));
  else
    {
      if (ai->parent != NULL)
	return findident(id, ai->parent, false);
      else
	return make_pair(std::string(""), (ASTInfo *)NULL);
    }

}

ASTInfo *
findpident (const std::string & pid)
{
  std::map<std::string, ASTInfo *>::const_iterator i = pidents.find(pid);
  if (i != pidents.end())
    return i->second;
  else
    return NULL;
}

/**
   Z C identifikatoru a seznamu bloku odspoda nahoru vytvori Pascalsky
   identifikator.
*/
std::string
mangleident (const std::string & s,
	     const std::list<int> & l)
{
  if (l.empty())
    return s;
  std::ostringstream str;
  str << "_";
  for (std::list<int>::const_reverse_iterator i = l.rbegin();
       i != l.rend();
       ++i)
    {
      str << *i << "_";
    }
  str << s;
  return str.str();
}

std::pair<std::string, ASTInfo *>
insertident (const std::string id, const CTypeSpec * ts, ASTInfo * ai)
{
  std::pair<std::string, ASTInfo *> rec = findident(id, ai);
  std::string mident(mangleident(id, blockstack));

  if (rec.second && rec.second->block != ai->block)
    {
      /* C identifikator nalezen, ale v nadrazenem bloku */
      std::string lmident(strtolower(mident));
      ASTInfo * pai = findpident(lmident);
      if (pai)
	{
	  /* Nalezli jsme kolidujici pascalske jmeno */
	  throw std::string("Error: Collision of Pascal identifiers '")
	    + lmident + std::string("'");
	}
      /* Muzeme vlozit zaznam o identifikatoru. */
      ai->idents->insert(
			 make_pair(id, new IdentInfo(new CTypeSpec(*ts), lmident)));

      pidents.insert(make_pair(lmident, ai));
      return make_pair(lmident, ai);
    }

  if (rec.second != NULL && rec.second->block == ai->block)
    {
      /* C identifikator nalezen v aktualnim bloku */
      return make_pair(rec.first, ai);
    }

  if (rec.second == NULL)
    {
      /* Zadny takovy C identifikator nenalezen */
      std::string lident(strtolower(id));
      ASTInfo * pid = findpident(lident);
      if (pid)
	{
	  /* Uz takovy pascalsky identifikator mame, zkus upravit jmeno */
	  std::string lmident(strtolower(mident));
	  pid = findpident(lmident);
	  if (pid)
	    {
	      throw std::string("Error: Collision of Pascal identifiers '")
		+ lmident + std::string("'");
	    }
	  lident = lmident;
	}
      ai->idents->insert(
			 make_pair(id, new IdentInfo(new CTypeSpec(*ts), lident)));
      pidents.insert(make_pair(lident, ai));
      return make_pair(lident, ai);
    }
  else
    {
      throw std::string("Pro odstraneni warningu");
    }
}

CDecl *
gentmpdecl (const CTypeSpec * ts)
{
  static int tmpcount = 0;
  std::ostringstream str;

  str << "__c2pas_tmpvar_" << (++tmpcount);
  return new CDecl(ts, new CInitDecl(new CDeclarator(CDeclarator::DirectDecl,
						     new CIdent(str.str())),
				     NULL, NULL),
		   NULL);
}

/**
   Pri generovani vystupu tela funkce zaznamena deklarace pro pozdejsi vystup.
*/
void
recordidents (const CDecl * dcl, ASTInfo * ai)
{
  const CInitDecl * idcl = dcl->initdecl();
  while (idcl)
    {
      /* vloz identifikator do prekladove tabulky identifikatoru */
      std::pair<std::string, ASTInfo *> p;
      p = insertident(idcl->declarator()->ident()->name(),
		      (CTypeSpec *)dcl->declspec()->clone(),
		      ai);
      /* zarad deklaraci s prelozenym identifikatorem pro pozdejsi pouziti */
      if (! (CTypeSpec *)dcl->declspec())
	throw std::string("declspec == NULL");
      //CExpr * init = idcl->
      decls.push_back(
		      new CDecl((CTypeSpec *)dcl->declspec(),
				new CInitDecl(new CDeclarator(CDeclarator::DirectDecl,
							      new CIdent(p.first)),
					      idcl && idcl->initializer()
					      ? (CExpr *)idcl->initializer()->clone()
					      : NULL,
					      NULL),
				NULL));
      /* pokracuj dalsim CInitDecl */
      idcl = dynamic_cast<const CInitDecl *>(idcl->next());
    }
}

CTypeSpec::Type getexprtype (const CExpr *, const ASTInfo *);

CTypeSpec::Type
getexprtype (const COp * o, const ASTInfo * ai)
{
  switch (o->op_type())
    {
    case COp::Unary:
      return getexprtype(static_cast<const CUnOp *>(o)->arg(), ai);
    case COp::Binary: {
      const CBinOp * bo = static_cast<const CBinOp *>(o);
      const CTypeSpec::Type lt = getexprtype(bo->leftArg(), ai),
	rt = getexprtype(bo->rightArg(), ai);
      if (lt == rt)
	return lt;
      else if ((lt == CTypeSpec::Float && (rt == CTypeSpec::Int
					   || rt == CTypeSpec::Unsigned))
	       || (rt == CTypeSpec::Float && (lt == CTypeSpec::Int
					      || lt == CTypeSpec::Unsigned)))
	return CTypeSpec::Float;
      else
	throw std::string("Unsupported combination of types "
			  "in getexprtype()");
    }
    default:
      throw std::string("'Ternary' operation not supported");
    }
}

CTypeSpec::Type
getexprtype (const CExpr * e, const ASTInfo * ai)
{
  switch (e->expr_type())
    {
    case CExpr::Ident:
      {
	const std::string id
          = static_cast<CIdentExpr const*>(e)->ident()->name();
	std::pair<std::string, ASTInfo *> ainfo
	  = findident(id, ai);
	if (! ainfo.second)
	  throw std::string("Identifier not found");
	return ainfo.second->idents->operator[](id)->tspec->typespec_type();
      }
    case CExpr::Op:
      return getexprtype(static_cast<COp const *>(e), ai);
    case CExpr::Const: {
      switch (static_cast<CConstExpr const *>(e)->const_type())
	{
	case CConstExpr::Int:
	  return CTypeSpec::Int;
	case CConstExpr::UInt:
	  return CTypeSpec::Unsigned;
	case CConstExpr::Float:
	  return CTypeSpec::Float;
	default:
	  throw std::string("Unsupported type in getexprtype()");
	}
    }
    default:
      throw std::string("Unknown CExpr type!");
    }
}

void astprint_comp_statement (const CCompoundStatement * cs, ASTInfo * ai,
                              std::ostream & out);
void astprint_sel_statement (const CSelectionStatement * cs, ASTInfo * ai,
                             std::ostream & out);
void astprint_expr_statement (const CExprStatement *, ASTInfo *,
                              std::ostream &);
void astprint_iter_statement (const CIterationStatement *, ASTInfo *,
                              std::ostream &);
void astprint_jump_statement (const CJumpStatement *, ASTInfo *,
                              std::ostream &);
void astprint_expr (const CExpr *, ASTInfo *, std::ostream &);
void astprint_op (const COp *, ASTInfo *, std::ostream &);
void astprint_const_expr (const CConstExpr *, ASTInfo *, std::ostream &);
void astprint_unop (const CUnOp *, ASTInfo *, std::ostream &);
void astprint_binop (const CBinOp *, ASTInfo *, std::ostream &);


void
astprint_statement (const CStatement * s, ASTInfo * ai,
                    std::ostream & out)
{
  if (! s)
    return;
  CStatement const * stmt = s;
  while (stmt)
    {
      switch (stmt->stmt_type())
        {
        case CStatement::Labeled:
          throw std::string("'Labeled' statement handled within 'Selection' "
                            "statement only");
        case CStatement::Compound:
          astprint_comp_statement
            (static_cast<const CCompoundStatement *>(stmt),
             new ASTInfo(ai, ++blocks, stmt), out);
          break;
        case CStatement::Expr:
          astprint_expr_statement(static_cast<const CExprStatement *>(stmt),
                                  new ASTInfo(stmt, ai), out);
          break;
        case CStatement::Iteration:
          astprint_iter_statement
            (static_cast<const CIterationStatement *>(stmt),
             new ASTInfo(stmt, ai), out);
          break;
        case CStatement::Jump:
          astprint_jump_statement(static_cast<const CJumpStatement *>(stmt),
                                  new ASTInfo(stmt, ai), out);
          break;
        case CStatement::Selection:
          astprint_sel_statement
            (static_cast<const CSelectionStatement *>(stmt),
             new ASTInfo(stmt, ai), out);
        }
      // pokracuj na dalsi CStatement v seznamu
      stmt = stmt->next ();
    }
}

void
astprint_expr_statement (const CExprStatement * es, ASTInfo * ai,
                         std::ostream & out)
{
  out << ";" << std::endl;
  if (! es)
    return;
  astprint_expr(es->expr(), ai, out);
}

void
astprint_iter_statement (const CIterationStatement * is, ASTInfo * ai,
                         std::ostream & out)
{
  out << ";" << std::endl;
  if (! is)
    return;

  if (is->iterationstmt_type() != CIterationStatement::While)
    throw std::string("Only 'While' iteration statement supported");
  out << "while ";
  astprint_expr(is->cond(), ai, out);
  out << " do begin ";
  astprint_statement(is->statement(), ai, out);
  out << ";" << std::endl << "end";
}

void
astprint_jump_statement (const CJumpStatement * js, ASTInfo *,
                         std::ostream & out)
{
  out << ";" << std::endl;
  if (! js)
    return;
  switch(js->jumpstmt_type())
    {
    case CJumpStatement::Break:
      out << "break";
      break;
    case CJumpStatement::Continue:
      out << "continue";
      break;
    case CJumpStatement::Return:
      out << "exit(1)";
      break;
    default:
      throw std::string("'Goto' jump statement not supported");
    }
}

void
astprint_comp_statement (const CCompoundStatement * cs, ASTInfo * ai,
                         std::ostream & out)
{
  out << ";" << std::endl;
  if (cs == NULL)
    return;

  /* vloz cislo bloku na vrchol zasobniku */
  blockstack.push_back(ai->block);

  /* projdi deklarace a uloz je pro pozdejsi pouziti */
  const CDecl * dcl = cs->declarations();
  while (dcl != NULL) {
    recordidents(dcl, ai);
    dcl = (CDecl *)dcl->next();
  }

  /* vystup bloku */
  out << "begin" << std::endl;
  const CStatement * const stmt = cs->statements();
  astprint_statement(stmt, ai, out);
  /*while (stmt != NULL) {
    out << ";" << std::endl;
    astprint(stmt, ai, out);
    stmt = (CStatement *)stmt->next();
    }*/
  out << ";" << std::endl << "end";

  if (! blockstack.empty())
    /* odstran cislo bloku z vrcholu zasobniku */
    blockstack.erase(--blockstack.end());
}

void
astprint_sel_statement (const CSelectionStatement * ss, ASTInfo * ai,
                        std::ostream & out)
{
  out << ";" << std::endl;
  if (! ss)
    return;
  if (ss->selectionstmt_type() != CSelectionStatement::Switch)
    throw std::string("'If' statement not supported");
  const CIdentExpr * swexpr;
  if (ss->expr()->expr_type() != CExpr::Ident)
    {
      /* Vytvor docasnou promennou a prirazeni pokud je argument switche
	 slozitejsi nez pouhy identifikator aby jsme ho nevyhodnocovali
	 vicekrat */
      CDecl * const tmpdecl =
	gentmpdecl(new CTypeSpec(CTypeSpec::Long, NULL));
      decls.push_back(tmpdecl);
      const CIdent * const tmpident =
	(CIdent *)tmpdecl->initdecl()->declarator()->ident();
      const CIdentExpr * const idexpr =
	new CIdentExpr(new CIdent(*tmpident));
      const CBinOp * const tmpass =
	new CBinOp(CBinOp::Assign, idexpr, ss->expr());
      const CExprStatement * const estmt =
	new CExprStatement(new CBinOp(*tmpass), NULL);
      astprint_expr_statement(estmt, ai, out);
      swexpr = idexpr;
    }
  else
    {
      swexpr = dynamic_cast<const CIdentExpr *>(ss->expr());
    }

  if (ss->statement1()->stmt_type() != CStatement::Compound)
    throw std::string("Only 'Compound' statement can follow 'switch'");
  CCompoundStatement const * swstmt
    = dynamic_cast<const CCompoundStatement *>(ss->statement1());
  CLabeledStatement const * lstmt;
  const CStatement * stmt = swstmt->statements();

  std::list<std::string> labels2;
  std::list<const CLabeledStatement *> lstmts;
  std::string default_label;
  scan_for_cases (stmt, labels2, lstmts, default_label);
  labels.insert (labels.end (), labels2.begin(), labels2.end ());

  // Rozskok.
  std::list<std::string>::const_iterator label_it = labels2.begin ();
  std::list<const CLabeledStatement *>::const_iterator stmt_it
    = lstmts.begin ();

  //std::cerr << "lstmts.size ()" << lstmts.size () << std::endl;

  for (; label_it != labels2.end () && stmt_it != lstmts.end ();
       ++label_it, ++stmt_it)
    {
      if (*label_it == default_label)
	{
	  out << "goto " << default_label << ";" << std::endl;
	}
      else
	{
          //std::cerr << "*stmt_it: " << (void *)(*stmt_it) << std::endl;
	  const CBinOp * const tmp = new CBinOp(CBinOp::Eq, swexpr,
						(*stmt_it)->expr ());
	  out << "if ";
	  astprint_binop (tmp, ai, out);
	  out << " then goto " << *label_it << ";" << std::endl;
	}
    }

  label_it = labels2.begin ();
  stmt_it = lstmts.begin ();
  stmt = swstmt->statements();
  while (stmt)
    {
      switch (stmt->stmt_type())
	{
	case CStatement::Labeled:
	  lstmt = static_cast<const CLabeledStatement *>(stmt);
	  if (lstmt->labeledstmt_type() == CLabeledStatement::Case)
	    {
	      out << ";" << std::endl;
              out << *label_it << ": begin" << std::endl;
	      astprint_statement(lstmt->statement(), ai, out);
	      out << std::endl << "end";
	    }
	  else if (lstmt->labeledstmt_type() == CLabeledStatement::Default)
	    {
              out << ";" << std::endl;
	      out << default_label << ": begin" << std::endl;
	      astprint_statement(lstmt->statement(), ai, out);
	      out << std::endl << "end";
	    }
	  else
	    throw std::string("Only 'Case' and 'Default' labeled statement"
			      " within 'switch' supported");
	  //out << ";" << std::endl;
	  break;
	default:
	  throw std::string("Only 'Labeled' statement within 'switch' "
			    "supported");
	}
      stmt = static_cast<CStatement const *>(stmt->next());
      ++label_it;
      ++stmt_it;
    }
}

bool
iskindofassign (const CExpr * o)
{
  if (o->expr_type() != CExpr::Op)
    return false;
  if (static_cast<const COp *>(o)->op_type() != COp::Binary)
    return false;
  switch (static_cast<const CBinOp *>(o)->binop_type())
    {
    case CBinOp::Assign:
    case CBinOp::MultAss:
    case CBinOp::DivAss:
    case CBinOp::ModAss:
    case CBinOp::PlusAss:
    case CBinOp::MinusAss:
    case CBinOp::LShiftAss:
    case CBinOp::RShift:
    case CBinOp::BAndAss:
    case CBinOp::BOrAss:
    case CBinOp::XorAss:
      return true;
    default:
      return false;
    }
}

void
astprint_expr (const CExpr * e, ASTInfo * ai, std::ostream & out)
{
  switch (e->expr_type())
    {
    case CExpr::Ident:
      {
	const std::string id
	  = static_cast<const CIdentExpr *>(e)->ident()->name();
	const std::pair<std::string, ASTInfo *> ainf = findident(id, ai);
	if (! ainf.second)
	  {
	    throw std::string("Identifier '")
	      + id + std::string("' not declared ?!");
	  }
	out << ainf.first;
	break;
      }
    case CExpr::Op:
      /*if (((COp *)e)->op_type() == COp::Binary
	&& ((CBinOp *)e)->binop_type() == CBinOp::Assign) {
	astprint((CBinOp *)e, ai, out);
	}*/
      if (iskindofassign(e))
	astprint_binop(static_cast<const CBinOp *>(e), ai, out);
      else
	{
	  out << "(";
	  astprint_op(static_cast<const COp *>(e), ai, out);
	  out << ")";
	}
      break;
    case CExpr::Const:
      astprint_const_expr (static_cast<const CConstExpr *>(e), ai, out);
      break;
    }
}

void
astprint_op (const COp * o, ASTInfo * ai, std::ostream & out)
{
  switch (o->op_type())
    {
    case COp::Unary:
      astprint_unop(static_cast<const CUnOp *>(o), ai, out);
      break;
    case COp::Binary:
      astprint_binop(static_cast<const CBinOp *>(o), ai, out);
      break;
    case COp::Ternary:
      throw std::string("'Ternary' operation not supported");
    }
}

void
astprint_const_expr (const CConstExpr * x, ASTInfo *, std::ostream & out)
{
  switch (x->const_type())
    {
    case CConstExpr::Float:
      out << (long double)x->value();
      break;
    case CConstExpr::Int:
      out << (long long int)x->value();
      break;
    case CConstExpr::UInt:
      out << (unsigned long long int)x->value();
      break;
    default:
      throw std::string("'Char', 'Bool' and 'String' constants "
			"not supported.");
    }
}

void
astprint_unop (const CUnOp * o, ASTInfo * ai, std::ostream & out)
{
  switch (o->unop_type())
    {
    case CUnOp::Tilde:
      out << "not(";
      astprint_expr(o->arg(), ai, out);
      out << ")";
      break;
    case CUnOp::Excl:
      out << "not(boolean(";
      astprint_expr(o->arg(), ai, out);
      out << "))";
      break;
    case CUnOp::Plus:
      if (o->arg()->expr_type() == CExpr::Op)
	{
	  out << "(";
	  astprint_expr(o->arg(), ai, out);
	  out << ")";
	}
      else
	{
	  astprint_expr(o->arg(), ai, out);
	}
      break;
    case CUnOp::Minus:
      if (o->arg()->expr_type() == CExpr::Op)
	{
	  out << "-(";
	  astprint_expr(o->arg(), ai, out);
	  out << ")";
	}
      else
	{
	  out << "-";
	  astprint_expr(o->arg(), ai, out);
	}
      break;
    case CUnOp::PostInc:
      {
	if (o->arg()->expr_type() != CExpr::Ident)
	  throw std::string("Cannot post increment non-identifier");
	/* Vytvoreni prirazeni ktere se zaradi za aktualni statement
	   a tak castecne simuluje postinkrement. */
	const CBinOp * const tmpass
	  = new CBinOp(CBinOp::Assign,
		       new CIdentExpr(*(CIdentExpr *)o->arg()),
		       new CBinOp(CBinOp::Plus,
				  new CIdentExpr(
						 *(CIdentExpr *)o->arg()),
				  new CUIntExpr(1)));
	CExprStatement * const estmt =
	  new CExprStatement(new CBinOp(*tmpass),
			     NULL);
	const CStatement * const old = (CStatement *)ai->astmt->next();
	ai->astmt->set_next(estmt);
	estmt->set_next(old);
	astprint_expr(o->arg(), ai, out);
	break;
      }

    case CUnOp::PostDec:
      {
	if (o->arg()->expr_type() != CExpr::Ident)
	  throw std::string("Cannot post increment non-identifier");
	/* Vytbvoreni prirazeni ktere se zaradi za aktualni statement
	   a tak castecne simuluje postdekrement. */
	CBinOp * tmpass
	  = new CBinOp(CBinOp::Assign,
		       new CIdentExpr(*(const CIdentExpr *)o->arg()),
		       new CBinOp(CBinOp::Minus,
				  new CIdentExpr(
						 *(const CIdentExpr *)o->arg()),
				  new CUIntExpr(1)));
	CExprStatement * estmt = new CExprStatement(new CBinOp(*tmpass), NULL);
	CStatement * old = (CStatement *)ai->astmt->next();
	ai->astmt->set_next(estmt);
	estmt->set_next(old);
	astprint_expr(o->arg(), ai, out);
	break;
      }
    case CUnOp::PreInc:
    case CUnOp::PreDec:
    case CUnOp::Star:
    case CUnOp::And:
      throw std::string("Unsupported unary operation");
    }
}

CBinOp::Type
getassignoptype (const CBinOp * o)
{
  switch (o->binop_type())
    {
    case CBinOp::MultAss:
      return CBinOp::Mult;
    case CBinOp::DivAss:
      return CBinOp::Div;
    case CBinOp::ModAss:
      return CBinOp::Mod;
    case CBinOp::PlusAss:
      return CBinOp::Plus;
    case CBinOp::MinusAss:
      return CBinOp::Minus;
    case CBinOp::LShiftAss:
      return CBinOp::LShift;
    case CBinOp::RShift:
      return CBinOp::RShift;
    case CBinOp::BAndAss:
      return CBinOp::BAnd;
    case CBinOp::BOrAss:
      return CBinOp::BOr;
    case CBinOp::XorAss:
      return CBinOp::Xor;
    default:
      throw std::string("Use of getassignoptype() with CBinOp of bad type.");
    }
}


void
astprint_binop (const CBinOp * o, ASTInfo * ai, std::ostream & out)
{
  switch (o->binop_type())
    {
    case CBinOp::Plus:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ")+(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::Minus:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ")-(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::Mult:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ")*(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::Div:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ")";
      if (getexprtype(o->leftArg(), ai) == CTypeSpec::Float
	  || getexprtype(o->rightArg(), ai) == CTypeSpec::Float)
	out << "/";
      else
	out << " div ";
      out << "(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::Mod:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ") mod (";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::LShift:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ") lsh (";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::RShift:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ") rsh (";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::BAnd:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ") and (";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::BOr:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ") or (";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::LAnd:
      out << "boolean(";
      astprint_expr(o->leftArg(), ai, out);
      out << ") and boolean(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::LOr:
      out << "boolean(";
      astprint_expr(o->leftArg(), ai, out);
      out << ") and boolean(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::Eq:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ")=(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::NEq:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ")<>(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::LEq:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ")<=(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::GEq:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ")>=(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::Lt:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ")<(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::Gt:
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ")>(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")";
      break;
    case CBinOp::Xor:
      out << "((";
      out << "(";
      astprint_expr(o->leftArg(), ai, out);
      out << ") and not(";
      astprint_expr(o->rightArg(), ai, out);
      out << ")) or (not(";
      astprint_expr(o->leftArg(), ai, out);
      out << ") and (";
      astprint_expr(o->rightArg(), ai, out);
      out << ")))";
      break;
    case CBinOp::Assign:
      astprint_expr(o->leftArg(), ai, out);
      out << ":=";
      astprint_expr(o->rightArg(), ai, out);
      break;
    case CBinOp::MultAss:
    case CBinOp::DivAss:
    case CBinOp::ModAss:
    case CBinOp::PlusAss:
    case CBinOp::MinusAss:
    case CBinOp::LShiftAss:
    case CBinOp::RShiftAss:
    case CBinOp::BAndAss:
    case CBinOp::BOrAss:
    case CBinOp::XorAss:
      {
	const CBinOp * const tmpex =
	  new CBinOp(CBinOp::Assign,
		     (const CExpr *)o->leftArg()->clone(),
		     new CBinOp(getassignoptype(o),
				(const CExpr *)o->leftArg()->clone(),
				(const CExpr *)o->rightArg()->clone()));
	astprint_expr(tmpex, ai, out);
      }

    }
}

void
declsprint (std::list<const CDecl *> & dcls, std::ostream & out)
{
  for (std::list<const CDecl *>::iterator idecl = dcls.begin();
       idecl != dcls.end();
       ++idecl)
    {
      const CTypeSpec * const ts = (CTypeSpec *)(*idecl)->declspec();
      const CInitDecl * const indcl = (*idecl)->initdecl();
      out << indcl->declarator()->ident()->name() << " : ";
      switch (ts->typespec_type())
	{
	case CTypeSpec::Int:
	  out << "longint";
	  break;
	case CTypeSpec::Unsigned:
	  out << "cardinal";
	  break;
	case CTypeSpec::Float:
	  out << "double";
	  break;
	default:
	  throw std::string("Unsupported type in declsprint()");
	}
      out << ";" << std::endl;
      if (indcl && indcl->declarator()
	  && indcl->initializer())
	initlist.push_back
	  (new CBinOp(CBinOp::Assign,
		      new CIdentExpr(
				     (CIdent *)
				     indcl->declarator()->ident()->clone()),
		      (CExpr *)indcl->initializer()->clone()));
    }
}


void
labelsprint (std::list<std::string> const & labels, std::ostream & out)
{
  out << "label " << join_into_stream (labels, ", ") << ";" << std::endl;
}

/*
  void initsprint (std::list<CBinOp *> & il, std::ostream & out)
  {
  throw std::string("Inicializacne nepodporovana :(");
  for (std::list<CBinOp *> ibo = il.begin();
  ibo != il.end();
  ++ibo) {
  astprint(
  }
  }
*/
