#include "ast.hxx"

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

ASTBase * CFloatExpr::clone () const
{
    return new CFloatExpr(*this);
}

/* CIntExpr */
CIntExpr::CIntExpr (long long int v)
    : CConstExpr(Int, v)
{
}

ASTBase * CIntExpr::clone () const
{
    return new CIntExpr(*this);
}

/* CUIntExpr */
CUIntExpr::CUIntExpr (unsigned long long int v)
    : CConstExpr(UInt, v)
{
}

ASTBase * CUIntExpr::clone () const
{
    return new CUIntExpr(*this);
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
CDeclarator::CDeclarator (CDeclarator::Type t, CIdent * i)
    : ASTBase(ASTBase::Declarator), dct(t), id(i)
{
    if (t != DirectDecl)
        throw std::string("Pointer declarator not supported.");
}

CDeclarator::CDeclarator (const CDeclarator & x)
    : ASTBase(x), dct(x.declarator_type())
{
    id = x.ident() ? (CIdent *)x.ident()->clone() : NULL;
}

CDeclarator::~CDeclarator ()
{
    delete id;
}

ASTBase * CDeclarator::clone () const
{
    return new CDeclarator(*this);
}
    
CDeclarator::Type CDeclarator::declarator_type () const
{
    return dct;
}

CIdent * CDeclarator::ident () const
{
    return id;
}

/* CCompoundStatement */
CCompoundStatement::CCompoundStatement (CDecl * d, CStatement * s, CStatement * n)
    : CStatement(CStatement::Compound, n), dcls(d), stmts(s)
{
}

CCompoundStatement::CCompoundStatement (const CCompoundStatement & x)
    : CStatement(x)
{
    dcls = x.declarations() ? (CDecl *)x.declarations()->clone() : NULL;
    stmts = x.statements() ? (CStatement *)x.statements()->clone() : NULL;
}

CCompoundStatement::~CCompoundStatement ()
{
    delete dcls;
    delete stmts;
}

ASTBase * CCompoundStatement::clone () const
{
    return new CCompoundStatement(*this);
}

CDecl * CCompoundStatement::declarations () const
{
    return dcls;
}

CStatement * CCompoundStatement::statements () const
{
    return stmts;
}

/* CSelectionStatement */
CSelectionStatement::CSelectionStatement 
    (Type t, CExpr * e, CStatement * a, CStatement * b, CStatement * n)
    : CStatement(CStatement::Selection, n), sstp(t), ex(e), s1(a), s2(b)
{
}

CSelectionStatement::CSelectionStatement (const CSelectionStatement & x)
    : CStatement(x), sstp(x.selectionstmt_type())
{
    ex = x.expr() ? (CExpr *)x.expr()->clone() : NULL;
    s1 = x.statement1() ? (CStatement *)x.statement1()->clone() : NULL;
    s2 = x.statement2() ? (CStatement *)x.statement2()->clone() : NULL;
}

CSelectionStatement::~CSelectionStatement ()
{
    delete ex;
    delete s1;
    delete s2;
}

ASTBase * CSelectionStatement::clone () const
{
    return new CSelectionStatement(*this);
}

CSelectionStatement::Type CSelectionStatement::selectionstmt_type () const
{
    return sstp;
}

CExpr * CSelectionStatement::expr () const
{
    return ex;
}

CStatement * CSelectionStatement::statement1 () const
{
    return s1;
}

CStatement * CSelectionStatement::statement2 () const
{
    return s2;
}

/* CLabeledStatement */
CLabeledStatement::CLabeledStatement (Type t, CStatement * s, CStatement * n)
    : CStatement(CStatement::Labeled, n), lstp(t), st(s)
{
}

CLabeledStatement::CLabeledStatement (const CLabeledStatement & x)
    : CStatement(x), lstp(x.labeledstmt_type())
{
    st = x.statement() ? (CStatement *)x.statement()->clone() : NULL;
}

CLabeledStatement::~CLabeledStatement ()
{
    delete st;
}

ASTBase * CLabeledStatement::clone () const
{
    return new CLabeledStatement(*this);
}

CLabeledStatement::Type CLabeledStatement::labeledstmt_type () const
{
    return lstp;
}

CStatement * CLabeledStatement::statement () const
{
    return st;
}

/* CJumpStatement */
CJumpStatement::CJumpStatement (Type t, CExpr * e, CStatement * n)
    : CStatement(CStatement::Jump, n), jstp(t), ex(e)
{
    if (t == Goto)
        throw std::string("Goto jump statement not supported.");
}

CJumpStatement::CJumpStatement (const CJumpStatement & x)
    : CStatement(x)
{
    ex = x.expr() ? (CExpr *)x.expr()->clone() : NULL;
}

CJumpStatement::~CJumpStatement ()
{
    delete ex;
}

ASTBase * CJumpStatement::clone () const
{
    return new CJumpStatement(*this);
}

CJumpStatement::Type CJumpStatement::jumpstmt_type () const
{
    return jstp;
}

CExpr * CJumpStatement::expr () const
{
    return ex;
}
