
#include "ast.hxx"

/* CConstExpr */
CConstExpr::CConstExpr (CConstExpr::Type t)
    : type(t)
{
}

CConstExpr::Type CConstExpr::type ()
{
    return type;
}

bool CConstExpr::isconst ()
{
    return true;
}

/* CBinOp */
CBinOp::CBinOp (char o, CExpr * l, CExpr * r)
    : op(o), left(l), right(r)
{
}

CExpr * CBinOp::value ()
{
    return new CBinOp(op, left->clone(), right->clone());
}

CExpr * CBinOp::clone ()
{
    return new CBinOp(op, left->clone(), right->clone());
}

bool CBinOp::isconst ()
{
    return false;
}
