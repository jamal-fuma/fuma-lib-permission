AM_CPPFLAGS=-I$(top_srcdir)/include
AM_LDFLAGS= -static-libgcc

noinst_LTLIBRARIES= \
        libPermission.la

if UNIX
PLATFORM_SOURCES= \
        Unix.cpp
endif

if WINDOWS
PLATFORM_SOURCES= \
        Windows.cpp
endif

libPermission_la_SOURCES =     \
        $(top_srcdir)/include/Permission.hpp \
        Permission.cpp \
        $(PLATFORM_SOURCES)
