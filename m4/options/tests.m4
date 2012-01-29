dnl Add the --enable-tests arg
AC_ARG_ENABLE([tests],
                AS_HELP_STRING([--enable-tests], [Turn on tests]),
                [enable_tests=true],
                [enable_tests=false])

dnl set an automake variable controlled by --enable-tests arg
AM_CONDITIONAL([ENABLE_TESTS], [test "x$enable_tests" = "xtrue"])

dnl add a #define to the code controlled by --enable-tests arg
if test "x$enable_tests" = "xtrue" ; then
     CPPFLAGS="$CPPFLAGS -DENABLE_TESTS=1";
fi
