AUTOMAKE_OPTIONS=foreign dist-bzip2
AM_CXXFLAGS = @CXXFLAGS@ -W -Wall -fverbose-asm -save-temps
bin_PROGRAMS = c2pas
c2pas_SOURCES = c2pas.cxx lexan.cxx lexan.hxx csynan.cxx csynan.hxx ast.hxx ast.cxx
c2pas_SOURCES += defines.hxx astprint.hxx astprint.cxx
EXTRA_DIST = csynan.y Doxyfile test.c
EXTRA_DIST += COPYING config.sub config.guess depcomp aclocal.m4 config.h.in
EXTRA_DIST += docs

csynan.cxx : csynan.y
	@YACC@ -d -t -v -o$@ $<

csynan.hxx : csynan.cxx

