#include "ast.hxx"

/* CConstExpr */
CConstExpr::CConstExpr (CConstExpr::Type t, AllTypes v)
    : tp(t), val(v)
{
}

CExpr * CConstExpr::simplify () const
{
    return clone();
}

const CConstExpr::Type CConstExpr::type () const
{
    return tp;
}

const bool CConstExpr::isconst () const
{
    return true;
}

const AllTypes CConstExpr::value () const
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
COp::COp (char o)
    : op(o)
{
}

const bool COp::isconst () const
{
    return false;
}

const char COp::type () const
{
    return op;
}

/* CBinOp */
CBinOp::CBinOp (char o, CExpr * l, CExpr * r)
    : COp(o), left(l), right(r)
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

CExpr * CBinOp::clone () const
{
    return new CBinOp(op, left->clone(), right->clone());
}

CExpr * CBinOp::simplify () const
{
    return clone();
}

/* CArithBinOp */
CExpr * CArithBinOp::simplify () const
{
    /*if (left->isconst() && right->isconst()) {
	switch (op) {
	case '+': return new C
	}
    }
    else*/ 
    return clone();
	
}

/* CUnOp */
CExpr * CUnOp::clone () const
{
    return new CUnOp(op, arg->clone());
}

CUnOp::~CUnOp ()
{
    delete arg;
}

CExpr * CUnOp::simplify () const
{
    return clone();
}
