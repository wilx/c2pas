#include "ast.hxx"

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
    : CConstExpr(FloatExpr, v)
{
}

/* CIntExpr */
CIntExpr::CIntExpr (long long int v)
    : CConstExpr(IntExpr, v)
{
}

/* CUIntExpr */
CUIntExpr::CUIntExpr (unsigned long long int v)
    : CConstExpr(UIntExpr, v)
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
CBinOp::CBinOp (Type tp, CExpr * l, CExpr * r)
    : COp(BinaryOp), left(l), right(r), binopt(tp)
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
    : COp(UnaryOp), arg(x), unopt(t)
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

