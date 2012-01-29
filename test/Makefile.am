AM_LDFLAGS= -static-libgcc

AM_CPPFLAGS= \
        -I$(top_srcdir)/include

check_PROGRAMS= \
        TestPermission$(EXEEXT)

TESTS= \
        $(check_PROGRAMS)

TestPermission_SOURCES=\
        $(top_srcdir)/include/Test.hpp \
        \
        $(top_srcdir)/include/Permission.hpp \
        TestPermission.cpp

if ENABLE_UNIX_BUILD
TestPermission_SOURCES += \
        TestUnixPermission.cpp
endif

if ENABLE_WINDOWS_BUILD
TestPermission_SOURCES += \
        TestWindowsPermission.cpp
endif

TestPermission_LDADD= \
        $(top_builddir)/src/libPermission.la
