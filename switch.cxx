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
		std::list<const CLabeledStatement *> & lstmts,
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
	    const CLabeledStatement * lstmt 
	      = static_cast<const CLabeledStatement *>(stmt);
	    switch (lstmt->labeledstmt_type ())
	      {
	      case CLabeledStatement::Case:
		labels.push_back (gen_label_name ());
		lstmts.push_back (lstmt);
		break;

	      case CLabeledStatement::Default:
		default_label = gen_label_name ();
		labels.push_back (default_label);
		lstmts.push_back (lstmt);
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
