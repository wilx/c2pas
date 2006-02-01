#ifndef SWITCH_HXX
#define SWITCH_HXX

#include <list>
#include <string>
#include "ast.hxx"


extern void scan_for_cases (CStatement const *, 
			    std::list<std::string> & labels,
			    std::list<const CLabeledStatement *> lstmts,
			    std::string & default_label);


#endif // SWITCH_HXX
