#ifndef _AST_HXX_
#define _AST_HXX_

class ASTBase {
public:
    virtual ASTBase * clone () const = 0;
};

//
class CExpr : public ASTBase {
public:
    virtual CExpr * simplify ();
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
    enum Type {CharExpr, FloatExpr, IntExpr, UIntExpr, BoolExpr, StringExpr};
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
    enum Type {UnaryOp, BinaryOp, TernaryOp};
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
    enum Type {PlusBOp, MinusBOp, MultBOp, DivBOp, ModBOp, LShiftBOp, RShiftBOp,
               BAndBOp, BOrBOp, LAndBOp, LOrBOp, EqBOp, NEqBOp, LEqBOp, GEqBOp,
               LeBOp, GtBOp, XorBOp};
protected:
    CExpr * left, * right;
    Type binopt;
public:
    CBinOp (Type, CExpr *, CExpr *);
    virtual ~CBinOp ();
    
    CExpr * leftArg () const;
    CExpr * rightArg () const;
    Type binop_type () const;
    virtual CExpr * clone () const;
};

//
class CUnOp : public COp {
public:
    enum Type {StarUOp, TildeUOp, ExclUOp, AndUOp, PlusUOp, MinusUOp, PreIncUOp,
               PreDecUOp, PostIncUOp, PostDecUOp, NotUOp};
protected:
    CExpr * arg;
    Type unopt;
public:
    CUnOp (Type, CExpr *);
    virtual ~CUnOp ();

    Type unop_type () const;
    virtual CExpr * clone () const;
};

#endif // _AST_HXX_
