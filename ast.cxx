#include "ast.hxx"
#include <cstdio>

/* CExpr */
bool CExpr::isexpr () const
{
    return true;
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

/* CStatement */
CStatement::CStatement (CStatement::Type t)
    : stmtt(t)
{
}

bool CStatement::isexpr () const
{
    return false;
}

CStatement::Type CStatement::stmt_type () const
{
    return stmtt;
}

/* ASTList */
ASTList::ASTList (ASTBase * n)
    : nxt(n)
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

bool ASTList::isexpr () const
{
    return false;
}

ASTBase * ASTList::clone () const
{
    return new ASTList(nxt ? nxt->clone() : NULL);
}

/* CExprStatement */
CExprStatement::CExprStatement (CExpr * e)
    : CStatement(CStatement::Expr), expr(e)
{
}

CExpr * CExprStatement::getExpr () const
{
    return expr;
}

ASTBase * CExprStatement::clone () const
{
    return new CExprStatement((CExpr *)expr->clone());
}
