#include "switch.hxx"
#include <sstream>

static unsigned label_count = 0;


static
std::string
gen_label_name ()
{
  std::ostringstream oss;
  oss << "__c2pas_label_" << ++label_count;
  return oss.str ();
}


void 
scan_for_cases (CStatement const * stmt, 
		std::list<std::string> & labels,
		std::list<const CLabeledStatement *> lstmts,
		std::string & default_label)
{
  if (! stmt)
    throw std::string ("NULL selection statement?");

  default_label.clear ();
  while (stmt)
    {
      switch (stmt->stmt_type ())
	{
	case CStatement::Labeled:
	  {
	    switch (static_cast<const CLabeledStatement *>(stmt)->type ())
	      {
	      case CLabeledStatement::Case:
		labels.push_back (gen_label_name ());
		lstmts.push_back (static_cast<const CLabeledStatement *>(stmt));
		break;

	      case CLabeledStatement::Default:
		default_label = gen_label_name ();
		labels.push_back (default_label);
		lstmts.push_back (static_cast<const CLabeledStatement *>(stmt));
		break;

	      default:
		throw std::string ("goto statement is not supported");
	      }
	  }
	  break;

	default:
	  ;
	}
      stmt = stmt->next ();
    }
}
