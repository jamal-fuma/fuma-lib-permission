AM_CPPFLAGS= \
        -I$(top_srcdir)/include

AM_LDADD= \
        $(top_builddir)/src/libPermission.la

AM_LDFLAGS= -static-libgcc

if ENABLE_TESTS
TESTS= \
        $(check_PROGRAMS)
endif

CHECK_PROGRAMS= \
        TestPermission$(EXEEXT)

if UNIX
PLATFORM_SOURCES= \
        TestUnixPermission.cpp
endif

if WINDOWS
PLATFORM_SOURCES= \
        TestWindowsPermission.cpp
endif

TestPermission_SOURCES=\
        $(top_srcdir)/include/Test.hpp \
        \
        $(top_srcdir)/include/Permission.hpp \
        TestPermission.cpp \
        \
        $(PLATFORM_SOURCES)
