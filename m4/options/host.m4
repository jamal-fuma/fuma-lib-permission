dnl OS detection
AC_CANONICAL_HOST
case "${host}" in
  *-*-darwin*)
        unix_build=true ; windows_build=false;
        ;;
  *-*-linux*)
        unix_build=true ; windows_build=false;
        ;;
  *-*-win32*)
        unix_build=false ; windows_build=true;
        # add the cross library stuff here
        ;;
  *)
        AC_MSG_RESULT([Unsupported operating system: ${host}])
        ;;
esac

dnl enable the unix specific portions of the makefile
AM_CONDITIONAL([ENABLE_UNIX_BUILD],
        [test "x$unix_build" = "xtrue"])

dnl enable the windows specific portions of the makefile
AM_CONDITIONAL([ENABLE_WINDOWS_BUILD],
        [test "x$windows_build" = "xtrue"])
