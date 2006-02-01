AUTOMAKE_OPTIONS=foreign dist-bzip2
AM_YFLAGS=-d #build header
BUILT_SOURCES=csynan.hxx csynan.cxx
AM_CXXFLAGS = @CXXFLAGS@ -W -Wall -fverbose-asm -save-temps
bin_PROGRAMS = c2pas
c2pas_SOURCES = c2pas.cxx lexan.cxx lexan.hxx csynan.yxx ast.hxx ast.cxx
c2pas_SOURCES += defines.hxx astprint.hxx astprint.cxx alltypes.hxx join.hxx
c2pas_SOURCES += switch.hxx switch.cxx
EXTRA_DIST = Doxyfile test.c
EXTRA_DIST += COPYING config.sub config.guess depcomp aclocal.m4 config.h.in
EXTRA_DIST += docs

csynan.cxx : csynan.yxx
	@YACC@ -d -o$@ $<

csynan.hxx : csynan.cxx
