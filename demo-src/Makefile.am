AUTOMAKE_OPTIONS= \
  foreign \
  subdir-objects
  
INCLUDES=-I../include

bin_PROGRAMS=memdebug_demo
	
memdebug_demo_SOURCES= \
  memdebug_demo.cpp
memdebug_demo_LDADD=../lib/libmixmemtrace.la
memdebug_demo_CXXFLAGS=-D_DEBUG

