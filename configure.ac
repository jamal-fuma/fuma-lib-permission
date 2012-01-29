# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.61])
AC_INIT([fuma-lib-permission],[0.0.1],[jamal.natour@fumasoftware.com])
AM_INIT_AUTOMAKE([1.9 no-define foreign])

AC_CONFIG_SRCDIR([src/Permission.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_MINGW32
AC_PROG_CXX
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

# common funcs across windows and unix
AC_CHECK_FUNCS([getenv setenv])

# Use the latest short output macro if available
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_CONFIG_FILES([Makefile
                 include/Makefile
                 src/Makefile
                 scripts/Makefile
                 m4/Makefile
                 test/Makefile])

# I like maintainer mode
AM_MAINTAINER_MODE

dnl add the --debug option
m4_include([m4/options/debug.m4])

dnl add the --tests option
m4_include([m4/options/tests.m4])

dnl set $unix / $windows appropriately
m4_include([m4/options/host.m4])

dnl enable the unix specific portions of the makefile
dnl configure username / file attributes on unix
if test "x$unix" = "xtrue" ; then
    m4_include([m4/unix/username.m4]) ;
    m4_include([m4/unix/stat.m4]) ;
    AM_CONDITIONAL([UNIX],   [test "x$unix" = "xtrue"]) ;
fi

dnl username / file attributes on windows
if test "x$windows" = "xtrue" ; then
        m4_include([m4/windows/username.m4]) ;
        m4_include([m4/windows/file_attributes.m4]) ;
        AM_CONDITIONAL([WINDOWS],[test "x$windows" = "xtrue"]) ;
fi

AC_OUTPUT

dnl  Compile banner
echo \
"-------------------------------------------------
${PACKAGE_NAME} Version ${PACKAGE_VERSION}

Host:     '${host}'.
Prefix:   '${prefix}'.
Compiler: '${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS}'

Linker:             ${LDFLAGS}
CFlags:             ${CFLAGS}
CPPFlags:           ${CPPFLAGS}

Package features:
Debug:              ${debug}
Tests:              ${tests}

Unix:               '${unix}'.
Windows:            '${windows}'.
-------------------------------------------------"
