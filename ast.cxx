#include "ast.hxx"


/* ASTBase */
ASTBase::ASTBase (ASTBase::Type t)
    : astt(t)
{
}

ASTBase::ASTBase (ASTBase const & b)
  : RefCounted (), astt (b.astt)
{
}

ASTBase::Type ASTBase::type () const
{
    return astt;
}

/* CExpr */
CExpr::CExpr (CExpr::Type t)
    : ASTBase(ASTBase::Expr), et(t)
{
}

CExpr * CExpr::simplify () const
{
    return (CExpr *)clone();
}


CExpr::Type CExpr::expr_type () const
{
    return et;
}

/* CConstExpr */
CConstExpr::CConstExpr (CConstExpr::Type t, AllTypes v)
    : CExpr(CExpr::Const), tp(t), val(v)
{
}

CConstExpr::Type CConstExpr::const_type () const
{
    return tp;
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

CFloatExpr * CFloatExpr::clone () const
{
    return new CFloatExpr(*this);
}

/* CIntExpr */
CIntExpr::CIntExpr (long long int v)
    : CConstExpr(Int, v)
{
}

CIntExpr * CIntExpr::clone () const
{
    return new CIntExpr(*this);
}

/* CUIntExpr */
CUIntExpr::CUIntExpr (unsigned long long int v)
    : CConstExpr(UInt, v)
{
}

CUIntExpr * CUIntExpr::clone () const
{
    return new CUIntExpr(*this);
}

/* CIdentExpr */
CIdentExpr::CIdentExpr(const CIdent * i)
    : CExpr(CExpr::Ident), id(i)
{
    if (! i)
	throw std::string("CIdentExpr(NULL) not allowed");
}
    
CIdentExpr::CIdentExpr(const CIdentExpr & x)
    : CExpr(x)
{
    if (x.ident()) 
	id = (CIdent *)x.ident()->clone();
    else
	throw std::string("CIdentExpr(NULL) not allowed");
}

CIdentExpr::~CIdentExpr ()
{
    delete id;
}

CIdentExpr * CIdentExpr::clone () const
{
    return new CIdentExpr(*this);
}
    
const CIdent * CIdentExpr::ident () const
{
    return id;
}

/* COp */
COp::COp (Type tp)
    : CExpr(CExpr::Op), t(tp)
{
}

COp::Type COp::op_type () const
{
    return t;
}

/* CBinOp */
CBinOp::CBinOp (CBinOp::Type tp, const CExpr * l, const CExpr * r)
    : COp(COp::Binary), left(l), right(r), binopt(tp)
{
}

CBinOp::CBinOp (const CBinOp & bop)
    : COp(COp::Binary), left((CExpr *)bop.leftArg()->clone()),
      right((CExpr *)bop.rightArg()->clone()), binopt(bop.binop_type())
{
}

CBinOp::~CBinOp ()
{
    delete left;
    delete right;
}

const CExpr * CBinOp::leftArg () const
{
    return left;
}

const CExpr * CBinOp::rightArg () const
{
    return right;
}

CBinOp::Type CBinOp::binop_type () const 
{
    return binopt;
}

CBinOp * CBinOp::clone () const
{
    return new CBinOp(*this);
}

/* CUnOp */
CUnOp::CUnOp (CUnOp::Type t, const CExpr * x)
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

const CExpr * CUnOp::arg () const
{
    return a;
}

CUnOp * CUnOp::clone () const
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

CIdent * CIdent::clone () const
{
    return new CIdent(*this);
}

/* CTypeSpec */
CTypeSpec::CTypeSpec (CTypeSpec::Type t, const CDeclSpec * n)
    : CDeclSpec(CDeclSpec::TypeSpec, n), tstp(t)
{
    if (t == Struct || t == Union || t == Enum || t == TypeName)
        throw std::string("Unsupported typespec.");
}

CTypeSpec::Type CTypeSpec::typespec_type () const
{
    return tstp;
}

//ASTBase * CTypeSpec::clone () const
CTypeSpec * CTypeSpec::clone () const
{
    return new CTypeSpec(*this);
}

/* CDecl */
CDecl::CDecl (const CDeclSpec * d, const CInitDecl * i, const CDecl * n)
    : ASTBase(ASTBase::Decl), ASTList<CDecl>(n), dsp(d), id(i)
{
    if (! d)
	throw std::string("declspec musi byt != NULL");
    /*if (! i)
      throw std::string("initdecl musi byt != NULL");*/
}

CDecl::CDecl (const CDecl & x)
    : ASTBase(x), ASTList<CDecl>(x), 
      dsp(x.declspec() ? (CDeclSpec *)x.declspec()->clone() : NULL),
      id(x.initdecl() ? (CInitDecl *)x.initdecl()->clone() : NULL)
{
}

CDecl::~CDecl ()
{
    delete dsp;
    delete id;
}
    
CDecl * CDecl::clone () const
{
    return new CDecl(*this);
}

const CDeclSpec * CDecl::declspec () const
{
    return dsp;
}
    
const CInitDecl * CDecl::initdecl () const
{
    return id;
}

/* CDeclSpec */
CDeclSpec::CDeclSpec (CDeclSpec::Type t, const CDeclSpec * n)
    : ASTBase(ASTBase::DeclSpec), ASTList<CDeclSpec>(n), dstp(t)
{
}

CDeclSpec * CDeclSpec::clone () const
{
    return new CDeclSpec(*this);
}
 
CDeclSpec::Type CDeclSpec::declspec_type () const
{
    return dstp;
}

/* CInitDecl */
CInitDecl::CInitDecl (const CDeclarator * d, const CExpr * i, 
		      const CInitDecl * n)
    : ASTBase(ASTBase::InitDecl), ASTList<CInitDecl>(n), dc(d), in(i)
{
}

CInitDecl::CInitDecl (const CInitDecl & x)
    : ASTBase(x), ASTList<CInitDecl>(x),
      dc(x.declarator() ? (CDeclarator *)x.declarator()->clone() : NULL),
      in(x.initializer() ? (CExpr *)x.initializer()->clone() : NULL)
{
}

CInitDecl::~CInitDecl ()
{
    delete dc;
    delete in;
}

const CDeclarator * CInitDecl::declarator () const
{
    return dc;
}

const CExpr * CInitDecl::initializer () const
{
    return in;
}

CInitDecl * CInitDecl::clone () const
{
    return new CInitDecl(*this);
}

/* CDeclarator */
CDeclarator::CDeclarator (CDeclarator::Type t, const CIdent * i)
    : ASTBase(ASTBase::Declarator), dct(t), id(i)
{
    if (t != DirectDecl)
        throw std::string("Pointer declarator not supported.");
}

CDeclarator::CDeclarator (const CDeclarator & x)
    : ASTBase(x), dct(x.declarator_type()),
      id(x.ident() ? (CIdent *)x.ident()->clone() : NULL)
{
}

CDeclarator::~CDeclarator ()
{
    delete id;
}

CDeclarator * CDeclarator::clone () const
{
    return new CDeclarator(*this);
}
    
CDeclarator::Type CDeclarator::declarator_type () const
{
    return dct;
}

const CIdent * CDeclarator::ident () const
{
    return id;
}

/* CStatement */
CStatement::CStatement (CStatement::Type t, const CStatement * n)
  : ASTBase(ASTBase::Statement), ASTList<CStatement>(n), stmtt(t)
{
}

CStatement::Type CStatement::stmt_type () const
{
    return stmtt;
}

CStatement * CStatement::clone () const
{
    return new CStatement(*this);
}

/* CExprStatement */
CExprStatement::CExprStatement (const CExpr * e, const CStatement * n)
    : CStatement(CStatement::Expr, n), ex(e)
{
}

CExprStatement::CExprStatement (const CExprStatement & x)
    : CStatement(x), ex(x.expr() ? (const CExpr *)x.expr()->clone() : NULL)
{
}

CExprStatement::~CExprStatement ()
{
    delete ex;
}

const CExpr * CExprStatement::expr () const
{
    return ex;
}

CExprStatement * CExprStatement::clone () const
{
    return new CExprStatement(*this);
}



/* CCompoundStatement */
CCompoundStatement::CCompoundStatement (const CDecl * d, const CStatement * s,
					const CStatement * n)
    : CStatement(CStatement::Compound, n), dcls(d), stmts(s)
{
}

CCompoundStatement::CCompoundStatement (const CCompoundStatement & x)
    : CStatement(x),
      dcls(x.declarations() ? (CDecl *)x.declarations()->clone() : NULL),
      stmts(x.statements() 
	    ? (CStatement *)x.statements()->clone() : NULL)
{
}

CCompoundStatement::~CCompoundStatement ()
{
    delete dcls;
    delete stmts;
}

CCompoundStatement * CCompoundStatement::clone () const
{
    return new CCompoundStatement(*this);
}

const CDecl * CCompoundStatement::declarations () const
{
    return dcls;
}

const CStatement * CCompoundStatement::statements () const
{
    return stmts;
}

/* CSelectionStatement */
CSelectionStatement::CSelectionStatement 
    (Type t, const CExpr * e, const CStatement * a, const CStatement * b, 
     const CStatement * n)
    : CStatement(CStatement::Selection, n), sstp(t), ex(e), s1(a), s2(b)
{
}

CSelectionStatement::CSelectionStatement (const CSelectionStatement & x)
    : CStatement(x), sstp(x.selectionstmt_type()),
      ex(x.expr() ? (CExpr *)x.expr()->clone() : NULL),
      s1(x.statement1() ? (CStatement *)x.statement1()->clone() : NULL),
      s2(x.statement2() ? (CStatement *)x.statement2()->clone() : NULL)
{
}

CSelectionStatement::~CSelectionStatement ()
{
    delete ex;
    delete s1;
    delete s2;
}

CSelectionStatement * CSelectionStatement::clone () const
{
    return new CSelectionStatement(*this);
}

CSelectionStatement::Type CSelectionStatement::selectionstmt_type () const
{
    return sstp;
}

const CExpr * CSelectionStatement::expr () const
{
    return ex;
}

const CStatement * CSelectionStatement::statement1 () const
{
    return s1;
}

const CStatement * CSelectionStatement::statement2 () const
{
    return s2;
}

/* CLabeledStatement */
CLabeledStatement::CLabeledStatement 
    (Type t, const CConstExpr * e, const CStatement * s, const CStatement * n)
    : CStatement(CStatement::Labeled, n), lstp(t), st(s), ex(e)
{
}

CLabeledStatement::CLabeledStatement (const CLabeledStatement & x)
    : CStatement(x), lstp(x.labeledstmt_type()),
      st(x.statement() ? (CStatement *)x.statement()->clone() : NULL),
      ex(x.expr() ? (CConstExpr *)x.expr()->clone() : NULL)
{
}

CLabeledStatement::~CLabeledStatement ()
{
    delete st;
    delete ex;
}

CLabeledStatement * CLabeledStatement::clone () const
{
    return new CLabeledStatement(*this);
}

CLabeledStatement::Type CLabeledStatement::labeledstmt_type () const
{
    return lstp;
}

const CStatement * CLabeledStatement::statement () const
{
    return st;
}

const CConstExpr * CLabeledStatement::expr() const
{
    return ex;
}

/* CJumpStatement */
CJumpStatement::CJumpStatement (Type t, const CExpr * e, const CStatement * n)
    : CStatement(CStatement::Jump, n), jstp(t), ex(e)
{
    if (t == Goto)
        throw std::string("Goto jump statement not supported.");
}

CJumpStatement::CJumpStatement (const CJumpStatement & x)
  : CStatement(x), jstp(x.jstp), 
    ex(x.expr() ? (CExpr *)x.expr()->clone() : NULL)
{
}

CJumpStatement::~CJumpStatement ()
{
    delete ex;
}

CJumpStatement * CJumpStatement::clone () const
{
    return new CJumpStatement(*this);
}

CJumpStatement::Type CJumpStatement::jumpstmt_type () const
{
    return jstp;
}

const CExpr * CJumpStatement::expr () const
{
    return ex;
}

/* CIterationStatement */
CIterationStatement::CIterationStatement 
    (CIterationStatement::Type t, const CExpr * c, const CStatement * s, 
     const CStatement * n)
    : CStatement(CStatement::Iteration, n), istp(t), ex(c), st(s)
{
    if (t == For)
        throw std::string("Use the other constructor for 'For' statement.");
}
    
CIterationStatement::CIterationStatement
    (const CExpr * i, const CExpr * c, const CExpr * a, const CStatement * s, 
     const CStatement * n)
    : CStatement(CStatement::Iteration, n), istp(CIterationStatement::For), 
      in(i), cnd(c), ac(a), st(s)
{
}

CIterationStatement::CIterationStatement (const CIterationStatement & x)
    : CStatement(x), istp(x.iterationstmt_type()),
      st(x.statement() ? (CStatement *)x.statement()->clone() : NULL)  
{
    switch (istp) {
    case While:
    case Do:
        ex = (CExpr *)x.cond()->clone();
        break;
    case For:
        in = x.init() ? (CExpr *)x.init()->clone() : NULL;
        cnd = x.cond() ? (CExpr *)x.cond()->clone() : NULL;
        ac = x.action() ? (CExpr *)x.action()->clone() : NULL;
    }   
}

CIterationStatement::~CIterationStatement ()
{
    switch (istp) {
    case While:
    case Do:
        delete ex;
        break;
    case For:
        delete in;
        delete cnd;
        delete ac;
    }
    delete st;
}

CIterationStatement::Type CIterationStatement::iterationstmt_type () const
{
    return istp;
}

CIterationStatement * CIterationStatement::clone () const
{
    return new CIterationStatement(*this);
}

const CExpr * CIterationStatement::cond () const
{
    return istp == For ? cnd : ex;
}

const CExpr * CIterationStatement::init () const
{
    if (istp != For)
        throw std::string("Only 'For' statement has initialization.");
    return in;
}

const CExpr * CIterationStatement::action () const
{
    if (istp != For)
        throw std::string("Only 'For' statement has action.");
    return ac;
}

const CStatement * CIterationStatement::statement () const
{
    return st;
}

