#include "ast.hxx"
#include <cstdio>

/* ASTBase */

ASTBase::ASTBase (ASTBase::Type t)
    : astt(t)
{
}

ASTBase::Type ASTBase::type () const
{
    return astt;
}

/* CExpr */
CExpr::CExpr ()
    : ASTBase(ASTBase::Expr)
{
}

/* CConstExpr */
CConstExpr::CConstExpr (CConstExpr::Type t, AllTypes v)
    : tp(t), val(v)
{
}

CConstExpr::Type CConstExpr::const_type () const
{
    return tp;
}

bool CConstExpr::isconst () const
{
    return true;
}

AllTypes CConstExpr::value () const
{
    return val;
}

/* CFloatExpr */
CFloatExpr::CFloatExpr (long double v)
    : CConstExpr(Float, v)
{
}

/* CIntExpr */
CIntExpr::CIntExpr (long long int v)
    : CConstExpr(Int, v)
{
}

/* CUIntExpr */
CUIntExpr::CUIntExpr (unsigned long long int v)
    : CConstExpr(UInt, v)
{
}

/* COp */
COp::COp (Type tp)
    : t(tp)
{
}

bool COp::isconst () const
{
    return false;
}

COp::Type COp::type () const
{
    return t;
}

/* CBinOp */
CBinOp::CBinOp (CBinOp::Type tp, CExpr * l, CExpr * r)
    : COp(COp::Binary), left(l), right(r), binopt(tp)
{
}

CBinOp::~CBinOp ()
{
    delete left;
    delete right;
}

CExpr * CBinOp::leftArg () const
{
    return left;
}

CExpr * CBinOp::rightArg () const
{
    return right;
}

CBinOp::Type CBinOp::binop_type () const 
{
    return binopt;
}

CExpr * CBinOp::clone () const
{
    return new CBinOp(binopt, (CExpr *)left->clone(), (CExpr *)right->clone());
}

/* CUnOp */
CUnOp::~CUnOp ()
{
    delete arg;
}

CUnOp::CUnOp (CUnOp::Type t, CExpr * x)
    : COp(COp::Unary), arg(x), unopt(t)
{
}

CExpr * CUnOp::clone () const
{
    return new CUnOp(unopt, (CExpr *)arg->clone());
}

CUnOp::Type CUnOp::unop_type () const
{
    return unopt;
}

/*
  Statements
*/

/* ASTList */
ASTList::ASTList (ASTBase * n)
    : nxt(n)
{
}

ASTList::ASTList (const ASTList & l)
    : nxt(l.next() ? l.next()->clone() : NULL)
{
}

ASTBase * ASTList::next () const
{
    return nxt;
}

ASTBase * ASTList::setNext (ASTBase * n)
{
    ASTBase * old = nxt;
    nxt = n;
    return old;
}

/*ASTBase * ASTList::clone () const
{
    return new ASTList(nxt ? nxt->clone() : NULL);
}*/

/* CStatement */
CStatement::CStatement (CStatement::Type t, CStatement * n = NULL)
    : ASTBase(ASTBase::Statement), ASTList(n), stmtt(t)
{
}

CStatement::Type CStatement::stmt_type () const
{
    return stmtt;
}

ASTBase * CStatement::clone () const
{
    return new CStatement(stmtt, (CStatement *)(nxt ? nxt->clone() : NULL));
}

/* CIdent */
CIdent::CIdent (const std::string & n)
    : ASTBase(ASTBase::Ident), nm(n)
{
}

CIdent::CIdent (const char * cstr)
    : ASTBase(ASTBase::Ident), nm(cstr)
{
}

CIdent::~CIdent ()
{
}

std::string CIdent::name () const
{
    return nm;
}

/* CTypeSpec */
CTypeSpec::CTypeSpec (CTypeSpec::Type t, CTypeSpec * n = NULL)
    : ASTBase(ASTBase::TypeSpec), ASTList(n), tstp(t)
{
}

CTypeSpec::Type CTypeSpec::typespec_type () const
{
    return tstp;
}

ASTBase * CTypeSpec::clone () const
{
    return new CTypeSpec(tstp);
}

/* CExprStatement */
CExprStatement::CExprStatement (CExpr * e)
    : CStatement(CStatement::Expr), expr(e)
{
}

CExprStatement::~CExprStatement ()
{
    delete expr;
}

CExpr * CExprStatement::getExpr () const
{
    return expr;
}

ASTBase * CExprStatement::clone () const
{
    return new CExprStatement((CExpr *)expr->clone());
}
