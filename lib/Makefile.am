AUTOMAKE_OPTIONS= \
  foreign \
  subdir-objects
  
INCLUDES=-I../include
  
lib_LTLIBRARIES=libmixmemtrace.la 
libmixmemtrace_la_SOURCES= \
  mem_trace/MemInfoContainer.cpp \
  mem_trace/MemInfoContainer.h \
  mem_trace/mem-record.cpp
libmixmemtrace_la_CXXFLAGS=-D_DEBUG

mixmemtracedir=$(includedir)/mem_trace
mixmemtrace_HEADERS=../include/mem_trace/mem-debug.h \
  ../include/mem_trace/mem-record.h
