CXXFLAGS = @CXXFLAGS@ -W -Wall -fverbose-asm -save-temps
bin_PROGRAMS = c2pas
c2pas_SOURCES = c2pas.cxx lexan.cxx lexan.hxx csynan.cxx csynan.hxx ast.hxx ast.cxx
EXTRA_DIST = csynan.y 
EXTRA_DIST += COPYING config.sub config.guess depcomp aclocal.m4 config.h.in

csynan.cxx : csynan.y
	@YACC@ -d -o$@ $<

csynan.hxx : csynan.cxx

lexan.hxx : csynan.hxx

