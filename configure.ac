# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.61])
AC_INIT([fuma-lib-permission],[0.0.1],[jamal.natour@fumasoftware.com])
AM_INIT_AUTOMAKE([1.9 no-define foreign])

AC_CONFIG_SRCDIR([src/Permission.cpp])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
m4_include([m4/programs/toolchain.m4])

m4_include([m4/options/compiler.m4])

# common funcs across windows and unix
AC_CHECK_HEADERS([stdlib.h])
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

AS_IF([test "x$windows_build" = "xtrue"],[
    m4_include([m4/windows.m4])
])

AS_IF([test "x$unix_build" = "xtrue"],[
    m4_include([m4/unix.m4])
])

AC_OUTPUT

dnl  Compile banner
m4_include([m4/programs/banner.m4])
