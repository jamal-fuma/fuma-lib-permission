dnl Add the --enable-debug arg
AC_ARG_ENABLE([debug],
                AS_HELP_STRING([--enable-debug], [Turn on debugging]),
                [enable_debug=true],
                [enable_debug=false])

dnl set an automake variable controlled by --enable-debug arg
AM_CONDITIONAL([ENABLE_DEBUG],[test "x$enable_debug" = "xtrue"])

dnl add a #define to the config.h
AS_IF([test "x$enable_debug" = "xtrue"],[
    AC_DEFINE(ENABLE_DEBUG,[1], [Define if building debug code is enabled])
])

dnl non-gcc users will have to set CFLAGS manually at with CFLAGS="" ./configure for their compiler to adjust optimizations levels
if `test "x$GCC" = "xyes"` ; then
    if `test "x$debug" = "xtrue"` ;
    then
dnl as a convenience to gcc users only interfere with the debug builds to disable optizations
         CFLAGS=`echo $CFLAGS | sed -e 's/-O2/-O0/'`;
    else
dnl as a convenience to gcc users only disable debug symbols on non-debug builds
         CFLAGS=`echo $CFLAGS | sed -e 's/-g//'`;
    fi
fi
