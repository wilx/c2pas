/*
Copyright (c) 1997-2007, Václav Haisman

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef _AST_HXX_
#define _AST_HXX_

#include <string>
#include <cstdio>
#include "alltypes.hxx"

class ASTBase
{
public:
  enum Type {Expr, Statement, Ident, TypeSpec, Decl, DeclSpec, InitDecl,
	     Declarator, Initializer};
protected:
  const Type astt;
public:
  ASTBase (Type);
  virtual ~ASTBase ();
  virtual ASTBase * clone () const = 0;
  Type type () const;
};

/*
  Vyrazy
*/
class CExpr
  : public ASTBase
{
public:
  enum Type {Const, Op, Ident};
protected:
  const Type et;
public:
  CExpr (Type);
  virtual CExpr * simplify () const;
  Type expr_type () const;
};

//
class CConstExpr
  : public CExpr
{
public:
  enum Type {Char, Float, Int, UInt, Bool, String};
private:
  const Type tp;
protected:
  const AllTypes val;
public:
  CConstExpr (Type, AllTypes);
  Type const_type () const;
  AllTypes value () const;
};

//
class CFloatExpr
  : public CConstExpr
{
public:
  CFloatExpr (long double);
  virtual CFloatExpr * clone () const;
};

//
class CIntExpr
  : public CConstExpr
{
public:
  CIntExpr (long long int);
  virtual CIntExpr * clone () const;
};

//
class CUIntExpr
  : public CConstExpr
{
public:
  CUIntExpr (unsigned long long int);
  virtual CUIntExpr * clone () const;
};

//
class CIdent;
class CIdentExpr
  : public CExpr
{
protected:
  const CIdent * id;
public:
  CIdentExpr(const CIdent *);
  CIdentExpr(const CIdentExpr &);
  virtual ~CIdentExpr ();
  virtual CIdentExpr * clone () const;
  const CIdent * ident () const;
};

//
class COp
  : public CExpr
{
public:
  enum Type {Unary, Binary, Ternary};
protected:
  const Type t;
public:
  COp (Type);
  Type op_type () const;
};

//
class CBinOp
  : public COp
{
public:
  enum Type {Plus, Minus, Mult, Div, Mod, LShift, RShift, BAnd, BOr, LAnd,
	     LOr,
	     Eq, NEq, LEq, GEq, Lt, Gt, Xor,
	     Assign, MultAss, DivAss, ModAss, PlusAss, MinusAss, LShiftAss,
	     RShiftAss, BAndAss, BOrAss, XorAss};
protected:
  const CExpr * const left, * const right;
  const Type binopt;
public:
  CBinOp (CBinOp::Type, const CExpr *, const CExpr *);
  CBinOp (const CBinOp &);
  virtual ~CBinOp ();
  const CExpr * leftArg () const;
  const CExpr * rightArg () const;
  Type binop_type () const;
  virtual CBinOp * clone () const;
};

//
class CUnOp
  : public COp
{
public:
  enum Type {Star, Tilde, Excl, And, Plus, Minus, PreInc, PreDec, PostInc,
	     PostDec};
protected:
  const CExpr * const a;
  const Type unopt;
public:
  CUnOp (Type, const CExpr *);
  CUnOp (const CUnOp &);
  virtual ~CUnOp ();
  const CExpr * arg () const;
  Type unop_type () const;
  virtual CUnOp * clone () const;
};

/*
  Statements
*/

//
template <typename Elem>
class ASTList
{
protected:
  Elem * nxt;
public:
  explicit ASTList (const Elem * n)
    : nxt (const_cast<Elem *>(n))
  { }

  ASTList (const ASTList & l)
    : nxt (l.next () ? l.next ()->clone () : 0)
  { }

  virtual ~ASTList ()
  {
    delete nxt;
  }

  Elem *
  next ()
  {
    return nxt;
  }

  Elem const *
  next () const
  {
    return nxt;
  }

  Elem *
  set_next (const Elem * n)
  {
    Elem * old = nxt;
    nxt = const_cast<Elem *>(n);
    return old;
  }
};

//
class CIdent
  : public ASTBase
{
protected:
  const std::string nm;
public:
  CIdent (const std::string &);
  CIdent (const char *);
  virtual ~CIdent ();
  std::string name () const;
  virtual CIdent * clone () const;
};

//
class CDeclSpec;
class CInitDecl;
class CDecl
  : public ASTBase, public ASTList<CDecl>
{
protected:
  const CDeclSpec * const dsp;
  const CInitDecl * const id;
public:
  CDecl (const CDeclSpec *, const CInitDecl *,
	 const CDecl *);
  CDecl (const CDecl &);
  virtual ~CDecl ();
  virtual CDecl * clone () const;
  const CDeclSpec * declspec () const;
  const CInitDecl * initdecl () const;
};

//
class CDeclSpec
  : public ASTBase, public ASTList<CDeclSpec>
{
public:
  enum Type {TypeSpec, TypeQual, StorClassSpec};
protected:
  const Type dstp;
public:
  CDeclSpec (Type, const CDeclSpec *);
  virtual CDeclSpec * clone () const;
  Type declspec_type () const;
};

//
class CDeclarator;
class CInitializer;
class CInitDecl
  : public ASTBase, public ASTList<CInitDecl>
{
private:
  const CDeclarator * const dc;
  const CExpr * const in;
public:
  CInitDecl (const CDeclarator *, const CExpr *,
	     const CInitDecl *);
  CInitDecl (const CInitDecl &);
  virtual ~CInitDecl ();
  const CDeclarator * declarator () const;
  const CExpr * initializer () const;
  virtual CInitDecl * clone () const;
};

//
class CTypeSpec
  : public CDeclSpec
{
public:
  enum Type {Void, Char, Short, Int, Long, Float, Double, Signed, Unsigned,
	     Struct, Union, Enum, TypeName};
protected:
  const Type tstp;
public:
  CTypeSpec (CTypeSpec::Type, const CDeclSpec *);
  Type typespec_type () const;

  virtual CTypeSpec * clone () const;
};

//
class CDeclarator
  : public ASTBase
{
public:
  enum Type {Pointer, DirectDecl};
protected:
  const Type dct;
  const CIdent * const id;
public:
  CDeclarator (Type, const CIdent *);
  CDeclarator (const CDeclarator &);
  virtual ~CDeclarator ();
  virtual CDeclarator * clone () const;
  Type declarator_type () const;
  const CIdent * ident () const;
};

//
class CStatement
  : public ASTBase, public ASTList<CStatement>
{
public:
  enum Type {Labeled, Compound, Expr, Selection, Iteration, Jump};
protected:
  const Type stmtt;
public:
  CStatement (Type, const CStatement *);
  Type stmt_type () const;
  virtual CStatement * clone () const;
};

//
class CExprStatement
  : public CStatement
{
protected:
  const CExpr * const ex;
public:
  CExprStatement (const CExpr *, const CStatement *);
  CExprStatement (const CExprStatement &);
  virtual ~CExprStatement ();
  const CExpr * expr () const;
  virtual CExprStatement * clone () const;
};

//
class CCompoundStatement
  : public CStatement
{
protected:
  const CDecl * const dcls;
  const CStatement * const stmts;
public:
  CCompoundStatement (const CDecl *, const CStatement *, const CStatement *);
  CCompoundStatement (const CCompoundStatement &);
  virtual ~CCompoundStatement ();
  virtual CCompoundStatement * clone () const;
  const CDecl * declarations () const;
  const CStatement * statements () const;
};

//
class CSelectionStatement
  : public CStatement
{
public:
  enum Type {If, Switch};
private:
  const Type sstp;
  const CExpr * const ex;
  const CStatement * const s1, * const s2;
public:
  CSelectionStatement (Type, const CExpr *, const CStatement *,
		       const CStatement *, const CStatement *);
  CSelectionStatement (const CSelectionStatement &);
  virtual ~CSelectionStatement ();
  virtual CSelectionStatement * clone () const;
  Type selectionstmt_type () const;
  const CExpr * expr () const;
  const CStatement * statement1 () const;
  const CStatement * statement2 () const;
};

//
class CLabeledStatement
  : public CStatement
{
public:
  enum Type {Label, Case, Default};
protected:
  const Type lstp;
  const CStatement * const st;
  const CConstExpr * const ex;
public:
  CLabeledStatement (Type, const CConstExpr *, const CStatement *,
		     const CStatement *);
  CLabeledStatement (const CLabeledStatement &);
  virtual ~CLabeledStatement ();
  virtual CLabeledStatement * clone () const;
  Type labeledstmt_type () const;
  const CStatement * statement () const;
  const CConstExpr * expr () const;
};

//
class CJumpStatement
  : public CStatement
{
public:
  enum Type {Goto, Continue, Break, Return};
protected:
  const Type jstp;
  const CExpr * const ex; // pro return
public:
  CJumpStatement (Type, const CExpr *, const CStatement *);
  CJumpStatement (const CJumpStatement &);
  virtual ~CJumpStatement ();
  virtual CJumpStatement * clone () const;
  Type jumpstmt_type () const;
  const CExpr * expr () const;
};

class CIterationStatement
  : public CStatement
{
public:
  enum Type {While, Do, For};
protected:
  const Type istp;
  union {
    struct {
      const CExpr * ex;
    };
    struct {
      const CExpr * in, * cnd, * ac;
    };
  };
  const CStatement * const st;
public:
  CIterationStatement (Type, const CExpr *, const CStatement *,
		       const CStatement *);
  CIterationStatement (const CExpr *, const CExpr *, const CExpr *,
		       const CStatement *, const CStatement *);
  CIterationStatement (const CIterationStatement &);
  virtual ~CIterationStatement ();
  virtual CIterationStatement * clone () const;
  Type iterationstmt_type () const;
  const CExpr * cond () const;
  const CExpr * init () const;
  const CExpr * action () const;
  const CStatement * statement () const;
};


#endif // _AST_HXX_
