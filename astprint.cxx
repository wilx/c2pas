#include <list>
#include <algorithm>
#include <cctype>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include "astprint.hxx"

static std::list<int> blocklist;

std::map<std::string, ASTInfo *> pidents;
std::list<CDecl *> decls;
int blocks;
std::ostream * outs;

ASTInfo::ASTInfo(ASTInfo * p, int b)
    : parent(p), block(b)
{
}

inline std::string strtolower (const std::string & s)
{
    std::string ls(s.size(), ' ');
    //std::transform(s.begin(), s.end(), ls.begin(), &std::tolower);
    return ls;
}

inline std::string escident (const std::string & s)
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
}

std::pair<std::string, ASTInfo *>
findident (const std::string & id, const ASTInfo * ai, bool clrlist = true)
{
    if (clrlist)
	blocklist.clear();
    if (ai->block != 0)
	blocklist.push_back(ai->block);
    std::map<std::string, std::string>::const_iterator i = ai->idents.find(id);
    if (i != ai->idents.end())
	return make_pair(i->second, const_cast<ASTInfo *>(ai));
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
    return str.str();
}

std::pair<std::string, ASTInfo *> 
insertident (const std::string & id, ASTInfo * ai)
{
     
    std::pair<std::string, ASTInfo *> rec = findident(id, ai);
    std::string mident(mangleident(id, blocklist));

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
	ai->idents.insert(make_pair(id, lmident));
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
	ai->idents.insert(make_pair(id, lident));
	pidents.insert(make_pair(lident, ai));
	return make_pair(lident, ai);
    }
    else {
	throw std::string("Pro odstraneni warningu");
    }
}

CDecl * gentmpdecl (CTypeSpec * ts)
{
    static int tmpcount = 0;
    std::ostringstream str;

    str << "__c2pas_tmpvar_" << (++tmpcount);
    return new CDecl(ts, new CInitDecl(new CDeclarator(CDeclarator::DirectDecl,
						       new CIdent(str.str())),
				       NULL, NULL),
		     NULL);
}

void astprint (CCompoundStatement * cs, ASTInfo * ai, 
	       std::ostream & out);
void astprint (CLabeledStatement * cs, CSelectionStatement * sw, ASTInfo * ai, 
	       std::ostream & out);
void astprint (CSelectionStatement * cs, ASTInfo * ai, 
	       std::ostream & out);
void astprint (CExpr *, ASTInfo *, std::ostream &);

void astprint (CStatement * s, ASTInfo * ai,
	       std::ostream & out)
{
    switch (s->stmt_type()) {
    case CStatement::Labeled:
	throw std::string("'Labeled' statement handled within 'Selection' "
			  "statement only");
    case CStatement::Compound:
	astprint((CCompoundStatement *)s, new ASTInfo(ai, ++blocks), out);
	break;
    case CStatement::Expr:
	astprint((CExprStatement *)s, ai, out);
	break;
    case CStatement::Iteration:
	astprint((CIterationStatement *)s, ai, out);
	break;
    case CStatement::Jump:
	astprint((CJumpStatement *)s, ai, out);
	break;
    case CStatement::Selection:
	astprint((CSelectionStatement *)s, ai, out);
    }
}

void astprint (CCompoundStatement * cs, ASTInfo * ai, 
	       std::ostream & out)
{
    if (cs == NULL)
        return;

    /* projdi deklarace a uloz je pro pozdejsi pouziti */
    CDecl * dcl = cs->declarations();
    while (dcl != NULL) {
	decls.push_back(dcl);
	dcl = (CDecl *)dcl->next();
    }
    
    /* vystup bloku */
    out << "begin" << std::endl;
    CStatement * stmt = cs->statements();
    while (stmt != NULL) {
	out << ";" << std::endl;
	astprint(stmt, ai, out);
	stmt = (CStatement *)stmt->next();
    }
    out << "end";

    /* pokracuj na dalsi CStatement v seznamu */
    astprint((CStatement *)cs->next(), ai, out);
}

/*void astprint (CLabeledStatement * cs, CIdentExpr * swe, ASTInfo * ai, 
	       std::ostream & out = *outs)
{
    switch(cs->labeledstmt_type()) {
    case CLabeledStatement::Case: {
	out << "if (";
	out << 
	break;
    }
    case CLabeledStatement::Default:
	astprint((CLabeledStatement *)cs, ai, out);
	break;
    }
}*/

void astprint (CSelectionStatement * ss, ASTInfo * ai, 
	       std::ostream & out)
{
    if (ss->selectionstmt_type() != CSelectionStatement::Switch)
	throw std::string("'If' statement not supported");
    CIdentExpr * swexpr;
    if (ss->expr()->expr_type() != CExpr::Ident) {
	/* Vytvor docasnou promennou a prirazeni pokud je argument switche
	   slozitejsi nez pouhy identifikator aby jsme ho nevyhodnocovali 
	   vicekrat */
	CDecl * tmpdecl = gentmpdecl(new CTypeSpec(CTypeSpec::Long, NULL));
	decls.push_back(tmpdecl);
	CIdent * tmpident = tmpdecl->initdecl()->declarator()->ident();
	CIdentExpr * idexpr = new CIdentExpr(new CIdent(*tmpident));
	CBinOp * tmpass = new CBinOp(CBinOp::Assign, idexpr, ss->expr());
	CExprStatement * estmt = new CExprStatement(new CBinOp(*tmpass), NULL);
	astprint(estmt, ai, out);
	swexpr = idexpr;
    }
    else {
	swexpr = (CIdentExpr *)ss->expr();
    }
    
    if (ss->statement1()->stmt_type() != CStatement::Compound)
	throw std::string("Olny 'Compound' statement can follow 'switch'");
    CCompoundStatement * swstmt = (CCompoundStatement *)ss->statement1();
    CLabeledStatement * lstmt;
    CStatement * stmt = swstmt->statements();;
    while (stmt != NULL) {
	switch (stmt->stmt_type()) {
	case CStatement::Labeled:
	    lstmt = (CLabeledStatement *)stmt;
	    if (lstmt->labeledstmt_type() == CLabeledStatement::Case) {
		out << "if (";
		astprint(swexpr, ai, out);
		out << " = ";
		astprint(lstmt->expr(), ai, out);
		out << ") then begin" << std::endl;
		astprint(lstmt->statement(), ai, out);
		out << std::endl << "end";
	    }
	    else if (lstmt->labeledstmt_type() == CLabeledStatement::Default) {
		out << "else begin" << std::endl;
		astprint(lstmt->statement(), ai, out);
		out << std::endl << "end";
	    }
	    else
		throw std::string("Only 'Case' and 'Default' labeled statement"
				  " within 'switch' supported");
	    out << ";" << std::endl;
	    break;
	default:
	    throw std::string("Only 'Labeled' statement within 'switch' "
			      "supported");
	}
	stmt = (CStatement *)stmt->next();
    }
    
    /* pokracovani na dalsi statement */
    astprint((CStatement *)ss->next(), ai, out);
}

void astprint (CExpr * e, ASTInfo * ai, std::ostream & out)
{
}
