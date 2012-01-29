AM_CPPFLAGS=-I$(top_srcdir)/include
AM_LDFLAGS= -static-libgcc

noinst_LTLIBRARIES= \
        libPermission.la

libPermission_la_SOURCES =     \
        $(top_srcdir)/include/Permission.hpp \
        Permission.cpp

if ENABLE_UNIX_BUILD
libPermission_la_SOURCES +=     \
        Unix.hpp        \
        Unix.cpp
endif

if ENABLE_WINDOWS_BUILD
libPermission_la_SOURCES +=     \
        Windows.hpp \
        Windows.cpp
endif
