#ifndef _AST_HXX_
#define _AST_HXX_

//
class CExpr {
public:
    virtual CExpr * simplify () const = 0;
    virtual CExpr * clone () const = 0;
    virtual const bool isconst () const = 0;
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
    enum Type {CharExpr, FloatExpr, IntExpr, UIntExpr, BoolExpr};
private:
    Type tp;
protected:
    AllTypes val;
public:    
    CConstExpr (Type, AllTypes);

    virtual CExpr * simplify () const;
    virtual const bool isconst () const;
    const Type type () const;
    const AllTypes value () const;
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
protected:
    char op;
public:
    COp (char);

    virtual const bool isconst () const;
    const char type () const;
};

//
class CBinOp : public COp {
protected:
    CExpr * left, * right;
public:
    CBinOp (char, CExpr *, CExpr *);
    virtual ~CBinOp ();
    
    CExpr * leftArg () const;
    CExpr * rightArg () const;
    virtual CExpr * clone () const;
    virtual CExpr * simplify () const;
};

//
class CArithBinOp : public CBinOp {
public:
    CArithBinOp (char, CExpr *, CExpr *);
    
    virtual CExpr * simplify () const;
};

//
class CUnOp : public COp {
protected:
    CExpr * arg;
public:
    CUnOp (char, CExpr *);
    virtual ~CUnOp ();

    virtual CExpr * clone () const;
    virtual CExpr * simplify () const;
};

#endif // _AST_HXX_
