#ifndef _AST_HXX_
#define _AST_HXX_

#include <string>

class ASTBase {
public:
    enum Type {Expr, Statement, Ident, TypeSpec, Decl, DeclSpec, InitDecl, 
               Declarator, Initializer};
protected:
    Type astt;
public: 
    ASTBase (Type);
    virtual ASTBase * clone () const = 0;
    Type type () const;
};

/*
  Vyrazy
*/
class CExpr : public ASTBase {
protected:
    CExpr ();
public: 
    virtual CExpr * simplify () const;
    virtual bool isconst () const = 0;
};

//
union AllTypes {
    long double fpval;
    long long int intval;
    unsigned long long int uintval;
    char charval;
    bool boolval;

    AllTypes (long double x) : fpval(x) {}
    AllTypes (long long int x) : intval(x) {}
    AllTypes (unsigned long long int x) : uintval(x) {}
    AllTypes (char x) : charval(x) {}
    AllTypes (bool x) : boolval(x) {}

    operator long double () {
	return fpval;
    }
    
    operator long long int () {
	return intval;
    }

    operator unsigned long long int () {
	return uintval;
    }

    operator char () {
	return charval;
    }
    
    operator bool () {
	return boolval;
    }
    
    operator int () {
	return intval;
    }

    operator unsigned () {
	return uintval;
    }
};

//
class CConstExpr : public CExpr {
public:
    enum Type {Char, Float, Int, UInt, Bool, String};
private:
    Type tp;
protected:
    AllTypes val;
public:    
    CConstExpr (Type, AllTypes);

    virtual bool isconst () const;
    Type const_type () const;
    AllTypes value () const;
};

//
class CFloatExpr : public CConstExpr {
    long double val;
public:
    CFloatExpr (long double);
};

//
class CIntExpr : public CConstExpr {
public:
    CIntExpr (long long int);
};

//
class CUIntExpr : public CConstExpr {
    unsigned long long int val;
public:
    CUIntExpr (unsigned long long int);
};

//
class COp : public CExpr {
public:
    enum Type {Unary, Binary, Ternary};
protected:
    Type t;
public:
    COp (Type);
    
    virtual bool isconst () const;
    Type type () const;
};

//
class CBinOp : public COp {
public:
    enum Type {Plus, Minus, Mult, Div, Mod, LShift, RShift, BAnd, BOr, LAnd, LOr, 
               Eq, NEq, LEq, GEq, Le, Gt, Xor};
protected:
    CExpr * left, * right;
    Type binopt;
public:
    CBinOp (CBinOp::Type, CExpr *, CExpr *);
    CBinOp (const CBinOp &);
    virtual ~CBinOp ();
    
    CExpr * leftArg () const;
    CExpr * rightArg () const;
    Type binop_type () const;
    virtual CExpr * clone () const;
};

//
class CUnOp : public COp {
public:
    enum Type {Star, Tilde, Excl, And, Plus, Minus, PreInc, PreDec, PostInc, PostDec};
protected:
    CExpr * a;
    Type unopt;
public:
    CUnOp (Type, CExpr *);
    CUnOp (const CUnOp &);
    virtual ~CUnOp ();

    CExpr * arg () const;
    Type unop_type () const;
    virtual CExpr * clone () const;
};

/*
  Statements
*/

//
class ASTList {
protected:
    ASTBase * nxt;
public:
    ASTList (ASTBase *);
    ASTList (const ASTList &);
    virtual ~ASTList ();
    ASTBase * next () const;
    ASTBase * setNext (ASTBase *);
};

//
class CStatement : public ASTBase, public ASTList {
public:
    enum Type {Labeled, Compound, Expr, Selection, Iteration, Jump};
protected:
    Type stmtt;
public:
    CStatement (Type, CStatement *);
    Type stmt_type () const;
    virtual ASTBase * clone () const;
};

//
class CExprStatement : public CStatement {
protected:
    CExpr * ex;
public:
    CExprStatement (CExpr *);
    CExprStatement (const CExprStatement &);
    virtual ~CExprStatement ();
    CExpr * expr () const;
    virtual ASTBase * clone () const;
};

//
class CIdent : public ASTBase {
protected:
    std::string nm;
public:
    CIdent (const std::string &);
    CIdent (const char *);
    virtual ~CIdent ();
    std::string name () const;
    virtual ASTBase * clone () const;
};

//
class CDeclSpec;
class CInitDecl;
class CDecl : public ASTBase {
protected:
    CDeclSpec * dsp;
    CInitDecl * id;
public:
    CDecl (CDeclSpec *, CInitDecl *);
    CDecl (const CDecl &);
    virtual ~CDecl ();
    virtual ASTBase * clone () const;
    CDeclSpec * declspec () const;
    CInitDecl * initdecl () const;
};

//
class CDeclSpec : public ASTBase, public ASTList {
public:
    enum Type {TypeSpec, TypeQual, StorClassSpec};
protected:
    Type dstp;
public:
    CDeclSpec (Type, CDeclSpec *);
    virtual ASTBase * clone () const;
    Type declspec_type () const;
};

//
class CDeclarator;
class CInitializer;
class CInitDecl : public ASTBase, public ASTList {
private:
    CDeclarator * dc;
    CExpr * in;
public:
    CInitDecl (CDeclarator *, CExpr *, CInitDecl *);
    CInitDecl (const CInitDecl &);
    virtual ~CInitDecl ();
    CDeclarator * declarator () const;
    CExpr * initializer () const;
    virtual ASTBase * clone () const;
};

//
class CTypeSpec : public CDeclSpec {
public:
    enum Type {Void, Char, Short, Int, Long, Float, Double, Signed, Unsigned,
               Struct, Union, Enum, TypeName};
protected:
    Type tstp;
public:
    CTypeSpec (CTypeSpec::Type, CTypeSpec *); 
    Type typespec_type () const;
    virtual ASTBase * clone () const;
};

//
class CDeclarator : public ASTBase {
public:
    enum Type {Pointer, DirectDec};
protected:
    Type dct;
public:
    CDeclarator (Type);
    virtual ASTBase * clone () const;
    Type declarator_type () const;
};


//
/*class CCompoundStatement : public CStatement {
protected:
    
};*/
#endif // _AST_HXX_
