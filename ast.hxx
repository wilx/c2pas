#ifndef _AST_HXX_
#define _AST_HXX_

//
class CExpr {
public:
    virtual CExpr * value () = 0;
    virtual CExpr * clone () = 0;
    virtual bool isconst () = 0;
};

//
class CConstExpr : public CExpr {
public:
    enum Type {CharExpr, FloatExpr, IntExpr, UIntExpr, BoolExpr};

private:
    Type type;

public:    
    CConstExpr (Type);

    virtual bool isconst ();
    virtual Type type () = 0;
};

//
class CFloatExpr : public CConstExpr {
    
};

//
class CBinOp : public CExpr {
    char op;
    CExpr * left, * right;
public:
    CBinOp (char, CExpr *, CExpr *);
    
    virtual CExpr * value ();
    virtual CExpr * clone ();
    virtual bool isconst ();
};

class CArithmBinOp : public CBinOp {
    
};

#endif // _AST_HXX_
