#include <list>
#include <algorithm>
#include <ctype>
#include <stdlib.h>
#include "astprint.hxx"

static std::list<int> blocklist;

ASTInfo::ASTInfo(ASTInfo * p, int b)
    : parent(p), block(b)
{
}

inline std::string strtolower (const std:string & s)
{
    std::string ls(s.size());
    std::transform(s.begin(), s.end(), ls.begin(), std::tolower);
    return ls;
}

inline std::string escident (const std::string & s)
{
    std::string es;
    
    for (std::string::const_iterator i = s.begin();
         i != s.end();
         ++i) {
        if (std::isupper(*i) || *i = '_')
            es.push_back('_');
        es.push_back(*i);
    }
}

std::pair<std::string, ASTInfo *>
findident (const std::string & id, const ASTInfo * ai, bool clrlist = true)
{
    if (clrlist)
	blocklist.clear();
    if (ai->block != 0)
	blocklist.push_back(ai->block);
    std::map<std::string, std::string>::iterator i = ai->idents.find(id);
    if (i != ai->idents.end())
	return make_pair(i->second, ai);
    else {
	if (ai->parent != NULL)
	    return findident(id, ai->parent, false);
	else 
	    return make_pair(std::string(""), NULL);
    }
	
}

ASTInfo * findpident (const std::string & pid)
{
    std::set<std::string>::const_iterator i = pidents.find(pid);
    if (i != pidents.end())
	return i->second;
    else 
	return NULL;
}

/** 
    Z C identifikatoru a seznamu bloku odspoda nahoru vytvori Pascalsky 
    identifikator.
*/
inline std::string mangleident (const std::string & s, std::list<int> & l)
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
     
    std::pair<std::string, ASTInfo *> rec = findname(id, ai);
    std::string mident(mangleident(id, blocklist));

    if (rec.second != NULL && rec.second->block != ai->block) {
	/* C identifikator nalezen, ale v nadrazenem bloku */
	std::string lmident(strtolower(mident));
	ASTInfo * pai = findpident(lmident);
	if (pai) {
	    /* Nalezli jsme kolidujici pascalske jmeno */
	    std::cerr << "Error: Collision of Pascal identifiers" << std::endl;
	    abort();
	}
	/* Muzeme vlozit zaznam o identifikatoru. */
	ai->idents.insert(make_pair(id, lmident));
	pidents.insert(make_pair(lmident, ai));
	return make_pair(lmident, ai);
    }
    
    if (rec.second != NULL && rec.second->block == ai->block) {
	/* C identifikator nalezen v aktualnim bloku */
	return make_pair(rec.second, ai);
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
		std::cerr << "Error: Collision of Pascal identifiers" 
			  << std::endl;
		abort();
	    }
	    lident = lmident;
	}
	ai->idents.insert(make_pair(id, lident));
	pidents.insert(make_pair(lident, ai));
	return make_pair(lident, ai);
    }
}


void astprint (CCompoundStatement * cs, ASTInfo & ai)
{
    if (cs == NULL)
        return;
    
    *outs << "begin" << std::endl;
    CStatement * stmt = (CStatement *)cs->statements();
}


