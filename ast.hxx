#ifndef _AST_HXX_
#define _AST_HXX_

#include <string>
#include <cstdio>

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
public:
    enum Type {Const, Op, Ident};
protected:
    Type et;
public: 
    CExpr (Type);
    virtual CExpr * simplify () const;
    Type expr_type () const;
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
    Type const_type () const;
    AllTypes value () const;
};

//
class CFloatExpr : public CConstExpr {
public:
    CFloatExpr (long double);
    virtual ASTBase * clone () const;
};

//
class CIntExpr : public CConstExpr {
public:
    CIntExpr (long long int);
    virtual ASTBase * clone () const;
};

//
class CUIntExpr : public CConstExpr {
public:
    CUIntExpr (unsigned long long int);
    virtual ASTBase * clone () const;
};

//
class CIdent;
class CIdentExpr : public CExpr {
protected:
    CIdent * id;
public:
    CIdentExpr(CIdent *);
    CIdentExpr(const CIdentExpr &);
    virtual ~CIdentExpr ();
    virtual ASTBase * clone () const;
    CIdent * ident () const;
};

//
class COp : public CExpr {
public:
    enum Type {Unary, Binary, Ternary};
protected:
    Type t;
public:
    COp (Type);
    Type type () const;
};

//
class CBinOp : public COp {
public:
    enum Type {Plus, Minus, Mult, Div, Mod, LShift, RShift, BAnd, BOr, LAnd, LOr, 
               Eq, NEq, LEq, GEq, Lt, Gt, Xor, 
               Assign, MultAss, DivAss, ModAss, PlusAss, MinusAss, LShiftAss,
               RShiftAss, BAndAss, BOrAss, XorAss};
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
class CDecl : public ASTBase, public ASTList {
protected:
    CDeclSpec * dsp;
    CInitDecl * id;
public:
    CDecl (CDeclSpec *, CInitDecl *, CDecl *);
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
    CTypeSpec (CTypeSpec::Type, CDeclSpec *); 
    Type typespec_type () const;
    virtual ASTBase * clone () const;
};

//
class CDeclarator : public ASTBase {
public:
    enum Type {Pointer, DirectDecl};
protected:
    Type dct;
    CIdent * id;
public:
    CDeclarator (Type, CIdent *);
    CDeclarator (const CDeclarator &);
    virtual ~CDeclarator ();
    virtual ASTBase * clone () const;
    Type declarator_type () const;
    CIdent * ident () const;
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
    CExprStatement (CExpr *, CStatement *);
    CExprStatement (const CExprStatement &);
    virtual ~CExprStatement ();
    CExpr * expr () const;
    virtual ASTBase * clone () const;
};

//
class CCompoundStatement : public CStatement {
protected:
    CDecl * dcls;
    CStatement * stmts;
public:
    CCompoundStatement (CDecl *, CStatement *, CStatement *);
    CCompoundStatement (const CCompoundStatement &);
    virtual ~CCompoundStatement ();
    virtual ASTBase * clone () const;
    CDecl * declarations () const;
    CStatement * statements () const;
};

//
class CSelectionStatement : public CStatement {
public:
    enum Type {If, Switch};
private:
    Type sstp;
    CExpr * ex;
    CStatement * s1, * s2;
public:
    CSelectionStatement (Type, CExpr *, CStatement *, CStatement *, CStatement *);
    CSelectionStatement (const CSelectionStatement &);
    virtual ~CSelectionStatement ();
    virtual ASTBase * clone () const;
    Type selectionstmt_type () const;
    CExpr * expr () const;
    CStatement * statement1 () const;
    CStatement * statement2 () const;
};

//
class CLabeledStatement : public CStatement {
public:
    enum Type {Label, Case, Default};
protected:
    Type lstp;
    CStatement * st;
    CConstExpr * ex;
public:
    CLabeledStatement (Type, CConstExpr *, CStatement *, CStatement *);
    CLabeledStatement (const CLabeledStatement &);
    virtual ~CLabeledStatement ();
    virtual ASTBase * clone () const;
    Type labeledstmt_type () const;
    CStatement * statement () const;
    CConstExpr * expr () const;
};

//
class CJumpStatement : public CStatement {
public:
    enum Type {Goto, Continue, Break, Return};
protected:
    Type jstp;
    CExpr * ex; // pro return
public:
    CJumpStatement (Type, CExpr *, CStatement *);
    CJumpStatement (const CJumpStatement &);
    virtual ~CJumpStatement ();
    virtual ASTBase * clone () const;
    Type jumpstmt_type () const;
    CExpr * expr () const;
};

class CIterationStatement : public CStatement {
public:
    enum Type {While, Do, For};
protected:
    Type istp;
    union {
        struct {
            CExpr * ex;
        };
        struct {
            CExpr * in, * cnd, * ac;
        };
    };
    CStatement * st;
public:
    CIterationStatement (Type, CExpr *, CStatement *, CStatement *);
    CIterationStatement (CExpr *, CExpr *, CExpr *, CStatement *, CStatement *);
    CIterationStatement (const CIterationStatement &);
    virtual ~CIterationStatement ();
    virtual ASTBase * clone () const;
    Type iterationstmt_type () const;
    CExpr * cond () const;
    CExpr * init () const;
    CExpr * action () const;
    CStatement * statement () const;
};
#endif // _AST_HXX_
