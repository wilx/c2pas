CXXFLAGS = @CXXFLAGS@ -W -Wall -pedantic
bin_PROGRAMS = c2pas
c2pas_SOURCES = c2pas.cxx lexan.cxx lexan.hxx csynan.cxx csynan.hxx
EXTRA_DIST = csynan.y 
EXTRA_DIST += COPYING reconf config.sub config.guess

csynan.cxx : csynan.y
	@YACC@ -d -o$@ $<

csynan.hxx : csynan.cxx

lexan.hxx : csynan.hxx

