ACLOCAL_AMFLAGS = -I m4 --install

bin_PROGRAMS=romasm
romasm_SOURCES=\
src/main.cpp \
src/error.cpp

romasm_CPPFLAGS=-DDEBUG_BUILD
romasm_CXXFLAGS=-DDEBUG_BUILD -I./include

EXTRA_DIST = m4/NOTES
