#include <list>
#include <algorithm>
#include <cctype>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "astprint.hxx"

static std::list<int> blocklist;

std::map<std::string, ASTInfo *> pidents;
std::list<const CDecl *> decls;
int blocks;
std::list<int> blockstack;
std::list<const CBinOp *> initlist;
//std::list<std::string, IdentInfo *> allidents;

IdentInfo::IdentInfo (CTypeSpec * td, const std::string & n)
    : tspec(td), name(n)
{
}

ASTInfo::ASTInfo(const ASTInfo * p, int b, const CStatement * s)
    : parent((ASTInfo *)p), block(b), astmt((CStatement *)s)
{
    idents = new std::map<std::string, IdentInfo *>();
}

ASTInfo::ASTInfo(const CStatement * s, const ASTInfo * ai)
    : parent((ASTInfo *)ai->parent), block(ai->block), 
      idents(ai->idents), astmt((CStatement *)s)
{
}

static inline char mytolower (char ch)
{
    return (char)std::tolower(ch);
}

inline std::string strtolower (const std::string & s)
{
    std::string ls(s.size(), ' ');
    std::transform(s.begin(), s.end(), ls.begin(), mytolower);
    return ls;
}

/*inline std::string escident (const std::string & s)
{
    std::ostringstream es;
    
    for (std::string::const_iterator i = s.begin();
         i != s.end();
         ++i) {
        if (std::isupper(*i) || *i == '_')
            es << '_';
        es << *i;
    }
    return es.str();
}*/

std::pair<std::string, ASTInfo *>
findident (const std::string & id, const ASTInfo * ai, bool clrlist = true)
{
    if (clrlist)
	blocklist.clear();
    if (ai->block != 0)
	blocklist.push_back(ai->block);
    std::map<std::string, IdentInfo *>::const_iterator i 
	= ai->idents->find(id);
    if (i != ai->idents->end())
	//return make_pair(i->second->name, const_cast<ASTInfo *>(ai));
	return make_pair(i->second->name, const_cast<ASTInfo *>(ai));
    else {
	if (ai->parent != NULL)
	    return findident(id, ai->parent, false);
	else 
	    return make_pair(std::string(""), (ASTInfo *)NULL);
    }
	
}

ASTInfo * findpident (const std::string & pid)
{
    std::map<std::string, ASTInfo *>::const_iterator i = pidents.find(pid);
    if (i != pidents.end())
	return i->second;
    else 
	return NULL;
}

/** 
    Z C identifikatoru a seznamu bloku odspoda nahoru vytvori Pascalsky 
    identifikator.
*/
inline std::string mangleident (const std::string & s, 
				const std::list<int> & l)
{
    if (l.empty())
        return s;
    std::ostringstream str;
    str << "_";
    for (std::list<int>::const_reverse_iterator i = l.rbegin();
         i != l.rend();
         ++i) {
        str << *i << "_";
    }
    str << s;
    return str.str();
}

std::pair<std::string, ASTInfo *> 
insertident (const std::string id, const CTypeSpec * ts, ASTInfo * ai)
{
    std::pair<std::string, ASTInfo *> rec = findident(id, ai);
    std::string mident(mangleident(id, blockstack));

    if (rec.second != NULL && rec.second->block != ai->block) {
	/* C identifikator nalezen, ale v nadrazenem bloku */
	std::string lmident(strtolower(mident));
	ASTInfo * pai = findpident(lmident);
	if (pai) {
	    /* Nalezli jsme kolidujici pascalske jmeno */
	    throw std::string("Error: Collision of Pascal identifiers '")
		+ lmident + std::string("'");
	}
	/* Muzeme vlozit zaznam o identifikatoru. */
	ai->idents->insert(
	    make_pair(id, new IdentInfo(new CTypeSpec(*ts), lmident)));
				
	pidents.insert(make_pair(lmident, ai));
	return make_pair(lmident, ai);
    }
    
    if (rec.second != NULL && rec.second->block == ai->block) {
	/* C identifikator nalezen v aktualnim bloku */
	return make_pair(rec.first, ai);
    }
    
    if (rec.second == NULL) {
	/* Zadny takovy C identifikator nenalezen */
	std::string lident(strtolower(id));
	ASTInfo * pid = findpident(lident);
	if (pid) {
	    /* Uz takovy pascalsky identifikator mame, zkus upravit jmeno */
	    std::string lmident(strtolower(mident));
	    pid = findpident(lmident);
	    if (pid) {
		throw std::string("Error: Collision of Pascal identifiers '")
		    + lmident + std::string("'");
	    }
	    lident = lmident;
	}
	ai->idents->insert(
	    make_pair(id, new IdentInfo(new CTypeSpec(*ts), lident)));
	pidents.insert(make_pair(lident, ai));
	return make_pair(lident, ai);
    }
    else {
	throw std::string("Pro odstraneni warningu");
    }
}

inline CDecl * gentmpdecl (const CTypeSpec * ts)
{
    static int tmpcount = 0;
    std::ostringstream str;

    str << "__c2pas_tmpvar_" << (++tmpcount);
    return new CDecl(ts, new CInitDecl(new CDeclarator(CDeclarator::DirectDecl,
						       new CIdent(str.str())),
				       NULL, NULL),
		     NULL);
}

inline void recordidents (const CDecl * dcl, ASTInfo * ai)
{
    const CInitDecl * idcl = (CInitDecl *)dcl->initdecl();
    while (idcl != NULL) {
	/* vloz identifikator do prekladove tabulky identifikatoru */
	std::pair<std::string, ASTInfo *> p;
	p = insertident(idcl->declarator()->ident()->name(),
			(CTypeSpec *)dcl->declspec()->clone(),
			ai);
	/* zarad deklaraci s prelozenym identifikatorem pro pozdejsi pouziti */
	if (! (CTypeSpec *)dcl->declspec())
	    throw std::string("declspec == NULL");
	//CExpr * init = idcl->
	decls.push_back(
	    new CDecl((CTypeSpec *)dcl->declspec(),
		      new CInitDecl(new CDeclarator(CDeclarator::DirectDecl,
						    new CIdent(p.first)),
				    idcl && idcl->initializer()
				    ? (CExpr *)idcl->initializer()->clone()
				    : NULL,
				    NULL),
		      NULL));
	/* pokracuj dalsim CInitDecl */
	idcl = (CInitDecl *)idcl->next();
    }
}

inline CTypeSpec::Type getexprtype (const CExpr *, const ASTInfo *);
inline CTypeSpec::Type getexprtype (const COp * o, const ASTInfo * ai)
{
    switch (o->op_type()) {
    case COp::Unary:
	return getexprtype(((const CUnOp *)o)->arg(), ai);
    case COp::Binary: {
	const CBinOp * bo = (const CBinOp *)o;
	const CTypeSpec::Type lt = getexprtype(bo->leftArg(), ai), 
	    rt = getexprtype(bo->rightArg(), ai);
	if (lt == rt)
	    return lt;
	else if ((lt == CTypeSpec::Float && (rt == CTypeSpec::Int 
					     || rt == CTypeSpec::Unsigned))
		 || (rt == CTypeSpec::Float && (lt == CTypeSpec::Int
						|| lt == CTypeSpec::Unsigned)))
	    return CTypeSpec::Float;
	else
	    throw std::string("Unsupported combination of types "
			      "in getexprtype()");
    }
    default:
	throw std::string("'Ternary' operation not supported");
    }
}

inline CTypeSpec::Type getexprtype (const CExpr * e, const ASTInfo * ai)
{
    switch (e->expr_type()) {
    case CExpr::Ident: {
	const std::string id = ((const CIdentExpr *)e)->ident()->name();
	std::pair<std::string, ASTInfo *> ainfo 
	    = findident(id, ai);
	if (! ainfo.second)
	    throw std::string("Identifier not found");
	return ainfo.second->idents->operator[](id)->tspec->typespec_type();
    }
    case CExpr::Op:
	return getexprtype((const COp *)e, ai);
    case CExpr::Const: {
	switch (((const CConstExpr *)e)->const_type()) {
	case CConstExpr::Int:
	    return CTypeSpec::Int;
	case CConstExpr::UInt:
	    return CTypeSpec::Unsigned;
	case CConstExpr::Float:
	    return CTypeSpec::Float;
	default:
	    throw std::string("Unsupported type in getexprtype()");
	}
    }
    }
    throw std::string("Pro uspokojeni warningu od kompilatoru");
}

void astprint (const CCompoundStatement * cs, ASTInfo * ai, 
	       std::ostream & out);
void astprint (const CSelectionStatement * cs, ASTInfo * ai, 
	       std::ostream & out);
void astprint (const CExprStatement *, ASTInfo *, std::ostream &);
void astprint (const CIterationStatement *, ASTInfo *, std::ostream &);
void astprint (const CJumpStatement *, ASTInfo *, std::ostream &);
void astprint (const CExpr *, ASTInfo *, std::ostream &);
void astprint (const COp *, ASTInfo *, std::ostream &);
void astprint (const CConstExpr *, ASTInfo *, std::ostream &);
void astprint (const CUnOp *, ASTInfo *, std::ostream &);
void astprint (const CBinOp *, ASTInfo *, std::ostream &);


void astprint (const CStatement * s, ASTInfo * ai,
	       std::ostream & out)
{
    if (! s)
	return;

    switch (s->stmt_type()) {
    case CStatement::Labeled:
	throw std::string("'Labeled' statement handled within 'Selection' "
			  "statement only");
    case CStatement::Compound:
	astprint((CCompoundStatement *)s, new ASTInfo(ai, ++blocks, s), 
		 out);
	break;
    case CStatement::Expr:
	astprint((CExprStatement *)s, new ASTInfo(s, ai), out);
	break;
    case CStatement::Iteration:
	astprint((CIterationStatement *)s, new ASTInfo(s, ai), out);
	break;
    case CStatement::Jump:
	astprint((CJumpStatement *)s, new ASTInfo(s, ai), out);
	break;
    case CStatement::Selection:
	astprint((CSelectionStatement *)s, new ASTInfo(s, ai), out);
    }
    /* pokracuj na dalsi CStatement v seznamu */
    astprint((CStatement *)s->next(), ai, out);
}

void astprint (const CExprStatement * es, ASTInfo * ai, std::ostream & out)
{
    out << ";" << std::endl;
    if (! es)
	return;
    astprint(es->expr(), ai, out);
}

void astprint (const CIterationStatement * is, ASTInfo * ai, 
	       std::ostream & out)
{
    out << ";" << std::endl;
    if (! is)
	return;
    
    if (is->iterationstmt_type() != CIterationStatement::While)
	throw std::string("Only 'While' iteration statement supported");
    out << "while ";
    astprint(is->cond(), ai, out);
    out << " do begin ";
    astprint(is->statement(), ai, out);
    out << ";" << std::endl << "end";
}

void astprint (const CJumpStatement * js, ASTInfo *, std::ostream & out)
{
    out << ";" << std::endl;
    if (! js)
	return;
    switch(js->jumpstmt_type()) {
    case CJumpStatement::Break:
	out << "break";
	break;
    case CJumpStatement::Continue:
	out << "continue";
	break;
    case CJumpStatement::Return:
	out << "exit(1)";
	break;
    default:
	throw std::string("'Goto' jump statement not supported");
    }
}

void astprint (const CCompoundStatement * cs, ASTInfo * ai, 
	       std::ostream & out)
{
    out << ";" << std::endl;
    if (cs == NULL)
        return;

    /* vloz cislo bloku na vrchol zasobniku */
    blockstack.push_back(ai->block); 

    /* projdi deklarace a uloz je pro pozdejsi pouziti */
    const CDecl * dcl = (CDecl *)cs->declarations();
    while (dcl != NULL) {
	recordidents(dcl, ai);
	dcl = (CDecl *)dcl->next();
    }
    
    /* vystup bloku */
    out << "begin" << std::endl;
    const CStatement * const stmt = (CStatement *)cs->statements();
    astprint(stmt, ai, out);
    /*while (stmt != NULL) {
	out << ";" << std::endl;
	astprint(stmt, ai, out);
	stmt = (CStatement *)stmt->next();
	}*/
    out << ";" << std::endl << "end";

    if (! blockstack.empty()) 
	/* odstran cislo bloku z vrcholu zasobniku */
	blockstack.erase(--blockstack.end()); 
}

void astprint (const CSelectionStatement * ss, ASTInfo * ai, 
	       std::ostream & out)
{
    out << ";" << std::endl;
    if (! ss)
	return;
    if (ss->selectionstmt_type() != CSelectionStatement::Switch)
	throw std::string("'If' statement not supported");
    const CIdentExpr * swexpr;
    if (ss->expr()->expr_type() != CExpr::Ident) {
	/* Vytvor docasnou promennou a prirazeni pokud je argument switche
	   slozitejsi nez pouhy identifikator aby jsme ho nevyhodnocovali 
	   vicekrat */
	CDecl * const tmpdecl = 
	    gentmpdecl(new CTypeSpec(CTypeSpec::Long, NULL));
	decls.push_back(tmpdecl);
	const CIdent * const tmpident = 
	    (CIdent *)tmpdecl->initdecl()->declarator()->ident();
	const CIdentExpr * const idexpr = 
	    new CIdentExpr(new CIdent(*tmpident));
	const CBinOp * const tmpass = 
	    new CBinOp(CBinOp::Assign, idexpr, ss->expr());
	const CExprStatement * const estmt = 
	    new CExprStatement(new CBinOp(*tmpass), NULL);
	astprint(estmt, ai, out);
	swexpr = idexpr;
    }
    else {
	swexpr = (CIdentExpr *)ss->expr();
    }
    
    if (ss->statement1()->stmt_type() != CStatement::Compound)
	throw std::string("Only 'Compound' statement can follow 'switch'");
    CCompoundStatement * swstmt = (CCompoundStatement *)ss->statement1();
    CLabeledStatement * lstmt;
    const CStatement * stmt = swstmt->statements();;
    while (stmt != NULL) {
	switch (stmt->stmt_type()) {
	case CStatement::Labeled:
	    lstmt = (CLabeledStatement *)stmt;
	    if (lstmt->labeledstmt_type() == CLabeledStatement::Case) {
		out << ";" << std::endl;
		out << "if (";
		astprint(swexpr, ai, out);
		out << " = ";
		astprint(lstmt->expr(), ai, out);
		out << ") then begin" << std::endl;
		astprint(lstmt->statement(), ai, out);
		out << std::endl << "end";
	    }
	    else if (lstmt->labeledstmt_type() == CLabeledStatement::Default) {
		out << std::endl << " else begin" << std::endl;
		astprint(lstmt->statement(), ai, out);
		out << std::endl << "end";
	    }
	    else
		throw std::string("Only 'Case' and 'Default' labeled statement"
				  " within 'switch' supported");
	    //out << ";" << std::endl;
	    break;
	default:
	    throw std::string("Only 'Labeled' statement within 'switch' "
			      "supported");
	}
	stmt = (CStatement *)stmt->next();
    }
}

inline bool iskindofassign (const CExpr * o)
{
    if (o->expr_type() != CExpr::Op)
	return false;
    if (((const COp *)o)->op_type() != COp::Binary)
	return false;
    switch (((CBinOp *)o)->binop_type()) {
    case CBinOp::Assign:
    case CBinOp::MultAss:
    case CBinOp::DivAss:
    case CBinOp::ModAss:
    case CBinOp::PlusAss:
    case CBinOp::MinusAss:
    case CBinOp::LShiftAss:
    case CBinOp::RShift:
    case CBinOp::BAndAss:
    case CBinOp::BOrAss:
    case CBinOp::XorAss:
	return true;
    default:
	return false;
    }
}

void astprint (const CExpr * e, ASTInfo * ai, std::ostream & out)
{
    switch (e->expr_type()) {
    case CExpr::Ident: {
	std::string id = ((const CIdentExpr *)e)->ident()->name(); 
	std::pair<std::string, ASTInfo *> ainf = findident(id, ai);
	if (! ainf.second) {
	    throw std::string("Identifier '") 
		+ id + std::string("' not declared ?!");
	}
	out << ainf.first;
	break;
    }
    case CExpr::Op:
	/*if (((COp *)e)->op_type() == COp::Binary
	    && ((CBinOp *)e)->binop_type() == CBinOp::Assign) {
	    astprint((CBinOp *)e, ai, out);
	    }*/
	if (iskindofassign(e))
	    astprint((CBinOp *)e, ai, out);
	else {
	    out << "(";
	    astprint((COp *)e, ai, out);
	    out << ")";
	}
	break;
    case CExpr::Const:
	astprint((const CConstExpr *)e, ai, out);
	break;
    }
}

void astprint (const COp * o, ASTInfo * ai, std::ostream & out)
{
    switch (o->op_type()) {
    case COp::Unary:
	astprint((CUnOp *)o, ai, out);
	break;
    case COp::Binary:
	astprint((CBinOp *)o, ai, out);
	break;
    case COp::Ternary:
	throw std::string("'Ternary' operation not supported");
    }
}

void astprint (const CConstExpr * x, ASTInfo *, std::ostream & out)
{
    switch (x->const_type()) {
    case CConstExpr::Float:
	out << (long double)x->value();
	break;
    case CConstExpr::Int:
	out << (long long int)x->value();
	break;
    case CConstExpr::UInt:
	out << (unsigned long long int)x->value();
	break;
    default:
	throw std::string("'Char', 'Bool' and 'String' constants "
			  "not supported.");
    }
}

void astprint (const CUnOp * o, ASTInfo * ai, std::ostream & out)
{
    switch (o->unop_type()) {
    case CUnOp::Tilde:
	out << "not(";
	astprint(o->arg(), ai, out);
	out << ")";
	break;
    case CUnOp::Excl:
	out << "not(boolean(";
	astprint(o->arg(), ai, out);
	out << "))";
	break;
    case CUnOp::Plus:
	if (o->arg()->expr_type() == CExpr::Op) {
	    out << "(";
	    astprint(o->arg(), ai, out);
	    out << ")";
	}
	else {
	    astprint(o->arg(), ai, out);
	}
	break;
    case CUnOp::Minus:
	if (o->arg()->expr_type() == CExpr::Op) {
	    out << "-(";
	    astprint(o->arg(), ai, out);
	    out << ")";
	}
	else {
	    out << "-";
	    astprint(o->arg(), ai, out);
	}
	break;
    case CUnOp::PostInc: {
	if (o->arg()->expr_type() != CExpr::Ident)
	    throw std::string("Cannot post increment non-identifier");
	/* Vytvoreni prirazeni ktere se zaradi za aktualni statement
	   a tak castecne simuluje postinkrement. */
 	const CBinOp * const tmpass 
	    = new CBinOp(CBinOp::Assign, 
			 new CIdentExpr(*(const CIdentExpr *)o->arg()),
			 new CBinOp(CBinOp::Plus,
				    new CIdentExpr(
					*(const CIdentExpr *)o->arg()),
				    new CUIntExpr(1)));
	CExprStatement * const estmt = 
	    new CExprStatement(new CBinOp(*tmpass), 
			       NULL);
	const CStatement * const old = (const CStatement *)ai->astmt->next();
	ai->astmt->setNext(estmt);
	estmt->setNext(old);
	astprint(o->arg(), ai, out);
	break;
    }
	
    case CUnOp::PostDec: {
	if (o->arg()->expr_type() != CExpr::Ident)
	    throw std::string("Cannot post increment non-identifier");
	/* Vytbvoreni prirazeni ktere se zaradi za aktualni statement
	   a tak castecne simuluje postdekrement. */
 	CBinOp * tmpass 
	    = new CBinOp(CBinOp::Assign, 
			 new CIdentExpr(*(const CIdentExpr *)o->arg()),
			 new CBinOp(CBinOp::Minus,
				    new CIdentExpr(
				        *(const CIdentExpr *)o->arg()),
				    new CUIntExpr(1)));
	CExprStatement * estmt = new CExprStatement(new CBinOp(*tmpass), NULL);
	CStatement * old = (CStatement *)ai->astmt->next();
	ai->astmt->setNext(estmt);
	estmt->setNext(old);
	astprint(o->arg(), ai, out);
	break;
    }
    case CUnOp::PreInc:
    case CUnOp::PreDec:
    case CUnOp::Star:
    case CUnOp::And:
	throw std::string("Unsupported unary operation");
    }

}

inline CBinOp::Type getassignoptype (const CBinOp * o)
{
    switch (o->binop_type()) {
    case CBinOp::MultAss:
	return CBinOp::Mult;
    case CBinOp::DivAss:
	return CBinOp::Div;
    case CBinOp::ModAss:
	return CBinOp::Mod;
    case CBinOp::PlusAss:
	return CBinOp::Plus;
    case CBinOp::MinusAss:
	return CBinOp::Minus;
    case CBinOp::LShiftAss:
	return CBinOp::LShift;
    case CBinOp::RShift:
	return CBinOp::RShift;
    case CBinOp::BAndAss:
	return CBinOp::BAnd;
    case CBinOp::BOrAss:
	return CBinOp::BOr;
    case CBinOp::XorAss:
	return CBinOp::Xor;
    default:
	throw std::string("Use of getassignoptype() with CBinOp of bad type.");
    }
}


void astprint (const CBinOp * o, ASTInfo * ai, std::ostream & out)
{
    switch (o->binop_type()) {
    case CBinOp::Plus:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ")+(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::Minus:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ")-(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::Mult:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ")*(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::Div:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ")";
	if (getexprtype(o->leftArg(), ai) == CTypeSpec::Float
	    || getexprtype(o->rightArg(), ai) == CTypeSpec::Float)
	    out << "/";
	else 
	    out << " div ";
	out << "(";    
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::Mod:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ") mod (";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::LShift:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ") lsh (";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::RShift:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ") rsh (";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::BAnd:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ") and (";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::BOr:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ") or (";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::LAnd:
	out << "boolean(";
	astprint(o->leftArg(), ai, out);
	out << ") and boolean(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::LOr:
	out << "boolean(";
	astprint(o->leftArg(), ai, out);
	out << ") and boolean(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::Eq:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ")=(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::NEq:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ")<>(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::LEq:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ")<=(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::GEq:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ")>=(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::Lt:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ")<(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::Gt:
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ")>(";
	astprint(o->rightArg(), ai, out);
	out << ")";
	break;
    case CBinOp::Xor:
	out << "((";
	out << "(";
	astprint(o->leftArg(), ai, out);
	out << ") and not(";
	astprint(o->rightArg(), ai, out);
	out << ")) or (not(";
	astprint(o->leftArg(), ai, out);
	out << ") and (";
	astprint(o->rightArg(), ai, out);
	out << ")))";
	break;
    case CBinOp::Assign:
	astprint(o->leftArg(), ai, out);
	out << ":=";
	astprint(o->rightArg(), ai, out);
	break;
    case CBinOp::MultAss:
    case CBinOp::DivAss:
    case CBinOp::ModAss:
    case CBinOp::PlusAss:
    case CBinOp::MinusAss:
    case CBinOp::LShiftAss:
    case CBinOp::RShiftAss:
    case CBinOp::BAndAss:
    case CBinOp::BOrAss:
    case CBinOp::XorAss: {
	const CBinOp * const tmpex = 
	  new CBinOp(CBinOp::Assign,
		     (const CExpr *)o->leftArg()->clone(),
		     new CBinOp(getassignoptype(o), 
				(const CExpr *)o->leftArg()->clone(),
				(const CExpr *)o->rightArg()->clone()));
	astprint(tmpex, ai, out);
    }
	
    }
}

void declsprint (std::list<const CDecl *> & dcls, std::ostream & out)
{
    for (std::list<const CDecl *>::iterator idecl = dcls.begin();
	 idecl != dcls.end();
	 ++idecl) {
	const CTypeSpec * const ts = (const CTypeSpec *)(*idecl)->declspec();
	const CInitDecl * const indcl = (*idecl)->initdecl();
	out << indcl->declarator()->ident()->name() << " : ";
	switch (ts->typespec_type()) {
	case CTypeSpec::Int:
	    out << "longint";
	    break;
	case CTypeSpec::Unsigned:
	    out << "cardinal";
	    break;
	case CTypeSpec::Float:
	    out << "double";
	    break;
	default:
	    throw std::string("Unsupported type in declsprint()");
	}
	out << ";" << std::endl;
	if (indcl && indcl->declarator()
	    && indcl->initializer())
	    initlist.push_back(
		new CBinOp(CBinOp::Assign,
			   new CIdentExpr(
			       (CIdent *)
			       indcl->declarator()->ident()->clone()),
			   (CExpr *)indcl->initializer()->clone()));
    }
}

/*
void initsprint (std::list<CBinOp *> & il, std::ostream & out)
{
    throw std::string("Inicializacne nepodporovana :(");
    for (std::list<CBinOp *> ibo = il.begin();
	 ibo != il.end();
	 ++ibo) {
	astprint( 
	}
}
*/
