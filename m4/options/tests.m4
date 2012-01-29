dnl Add the --enable-tests arg
AC_ARG_ENABLE([tests],
                AS_HELP_STRING([--enable-tests], [Turn on tests]),
                [enable_tests=true],
                [enable_tests=false])

dnl set an automake variable controlled by --enable-tests arg
AM_CONDITIONAL([ENABLE_TESTS],[test "x$enable_tests" = "xtrue"])

dnl add a #define to the config.h
AS_IF([test "x$enable_tests" = "xtrue"],[
    AC_DEFINE(ENABLE_TESTS,[1], [Define if tests are enabled])
])
