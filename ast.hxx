#ifndef _AST_HXX_
#define _AST_HXX_

class ASTBase {
public:
    virtual bool isexpr () const = 0; 
    virtual ASTBase * clone () const = 0;
};

/*
  Vyrazy
*/
class CExpr : public ASTBase {
public: 
    virtual CExpr * simplify ();
    virtual bool isconst () const = 0;
    virtual bool isexpr () const;
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
    COp (COp::Type);
    
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
    CExpr * arg;
    Type unopt;
public:
    CUnOp (CUnOp::Type, CExpr *);
    virtual ~CUnOp ();

    Type unop_type () const;
    virtual CExpr * clone () const;
};

/*
  Statements
*/

class CStatement : public ASTBase {
public:
    enum Type {Labeled, Compound, Expr, Selection, Iteration, Jump};
protected:
    Type stmtt;
public:
    CStatement (Type);
    Type stmt_type () const;
    bool isexpr () const;
};

//
class CExprStatement : public CStatement {
protected:
    CExpr * expr;
public:
    CExprStatement (CExpr *);
    CExpr * getExpr () const;
    virtual ASTBase * clone () const;
};

//
class ASTList : public ASTBase {
private:
    ASTBase * nxt;
public:
    ASTList (ASTBase *);
    ASTBase * next () const;
    ASTBase * setNext (ASTBase *);
    virtual bool isexpr () const;
    virtual ASTBase * clone () const;
};

//
/*class CCompoundStatement : public CStatement {
protected:
    
};*/
#endif // _AST_HXX_
