CXXFLAGS = @CXXFLAGS@ -W -Wall -pedantic
bin_PROGRAMS = c2pas
c2pas_SOURCES = c2pas.cxx lexan.cxx lexan.hxx csynan.cxx
EXTRA_DIST = csynan.y
EXTRA_DIST += COPYING reconf config.sub config.guess

csynan.cxx : csynan.y lexan.hxx
	@YACC@ -o$@ $<

