dnl Add the --enable-debug arg
AC_ARG_ENABLE([debug],
                AS_HELP_STRING([--enable-debug], [Turn on debugging]),
                [debug=true],
                [debug=false])

AM_CONDITIONAL([DEBUG], [test "x$debug" = "xtrue"])
if `test "x$debug" = "xtrue"` ;
then
     CPPFLAGS="$CPPFLAGS -DDEBUG=1";
     CFLAGS=`echo $CFLAGS | sed -e 's/-O2/-O0/'`;
else
     CFLAGS=`echo $CFLAGS | sed -e 's/-g//'`;
fi
