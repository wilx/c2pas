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

CExpr * CExpr::simplify () const
{
    return (CExpr *)clone();
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

CBinOp::CBinOp (const CBinOp & bop)
    : COp(COp::Binary), binopt(bop.binop_type())
{
    left = (CExpr *)bop.leftArg()->clone();
    right = (CExpr *)bop.rightArg()->clone();
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
    return new CBinOp(*this);
}

/* CUnOp */
CUnOp::CUnOp (CUnOp::Type t, CExpr * x)
    : COp(COp::Unary), a(x), unopt(t)
{
}

CUnOp::CUnOp (const CUnOp & x)
    : COp(COp::Unary), a((CExpr *)x.arg()->clone()), unopt(x.unop_type())
{
}

CUnOp::~CUnOp ()
{
    delete a;
}

CExpr * CUnOp::arg () const
{
    return a;
}

CExpr * CUnOp::clone () const
{
    return new CUnOp(*this);
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

ASTList::~ASTList ()
{
    delete nxt;
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

/* CStatement */
CStatement::CStatement (CStatement::Type t, CStatement * n = NULL)
    : ASTBase(ASTBase::Statement), ASTList(n), stmtt(t)
{
    if (t == Labeled || t == Jump)
        throw std::string("Unsupported statement.");
}

CStatement::Type CStatement::stmt_type () const
{
    return stmtt;
}

ASTBase * CStatement::clone () const
{
    return new CStatement(*this);
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

ASTBase * CIdent::clone () const
{
    return new CIdent(*this);
}

/* CTypeSpec */
CTypeSpec::CTypeSpec (CTypeSpec::Type t, CTypeSpec * n = NULL)
    : CDeclSpec(CDeclSpec::TypeSpec, n), tstp(t)
{
    if (t == Struct || t == Union || t == Enum || t == TypeName)
        throw std::string("Unsupported typespec.");
}

CTypeSpec::Type CTypeSpec::typespec_type () const
{
    return tstp;
}

ASTBase * CTypeSpec::clone () const
{
    return new CTypeSpec(*this);
}

/* CExprStatement */
CExprStatement::CExprStatement (CExpr * e)
    : CStatement(CStatement::Expr), ex(e)
{
}

CExprStatement::CExprStatement (const CExprStatement & x)
    : CStatement(x), ex(x.expr() ? (CExpr *)x.expr()->clone() : NULL)
{
}

CExprStatement::~CExprStatement ()
{
    delete ex;
}

CExpr * CExprStatement::expr () const
{
    return ex;
}

ASTBase * CExprStatement::clone () const
{
    return new CExprStatement(*this);
}

/* CDecl */
CDecl::CDecl (CDeclSpec * d, CInitDecl * i)
    : ASTBase(ASTBase::Decl), dsp(d), id(i)
{
}

CDecl::CDecl (const CDecl & x)
    : ASTBase(x)
{
        dsp = x.declspec() ? (CDeclSpec *)x.declspec()->clone() : NULL;
        id = x.initdecl() ? (CInitDecl *)x.initdecl()->clone() : NULL;
}

CDecl::~CDecl ()
{
    delete dsp;
    delete id;
}
    
ASTBase * CDecl::clone () const
{
    return new CDecl(*this);
}

CDeclSpec * CDecl::declspec () const
{
    return dsp;
}
    
CInitDecl * CDecl::initdecl () const
{
    return id;
}

/* CDeclSpec */
CDeclSpec::CDeclSpec (CDeclSpec::Type t, CDeclSpec * n)
    : ASTBase(ASTBase::DeclSpec), ASTList(n), dstp(t)
{
}

ASTBase * CDeclSpec::clone () const
{
    return new CDeclSpec(*this);
}
 
CDeclSpec::Type CDeclSpec::declspec_type () const
{
    return dstp;
}

/* CInitDecl */
CInitDecl::CInitDecl (CDeclarator * d, CExpr * i, CInitDecl * n)
    : ASTBase(ASTBase::InitDecl), ASTList(n), dc(d), in(i)
{
}

CInitDecl::CInitDecl (const CInitDecl & x)
    : ASTBase(x), ASTList(x)
{
    dc = x.declarator() ? (CDeclarator *)x.declarator()->clone() : NULL;
    in = x.initializer() ? (CExpr *)x.initializer()->clone() : NULL;
}

CInitDecl::~CInitDecl ()
{
    delete dc;
    delete in;
}

CDeclarator * CInitDecl::declarator () const
{
    return dc;
}

CExpr * CInitDecl::initializer () const
{
    return in;
}

ASTBase * CInitDecl::clone () const
{
    return new CInitDecl(*this);
}

/* CDeclarator */
CDeclarator::CDeclarator (CDeclarator::Type t)
    : ASTBase(ASTBase::Declarator), dct(t)
{
    if (t != DirectDec)
        throw std::string("Pointer declarator not supported.");
}

ASTBase * CDeclarator::clone () const
{
    return new CDeclarator(*this);
}
    
CDeclarator::Type CDeclarator::declarator_type () const
{
    return dct;
}
