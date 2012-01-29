dnl OS detection
AC_CANONICAL_HOST
case "${host}" in
  *-*-darwin*)
        unix=true ; windows=false;
        CPPFLAGS="$CPPFLAGS -DUNIX=1" ;
        ;;
  *-*-linux*)
        unix=true ; windows=false;
        CPPFLAGS="$CPPFLAGS -DUNIX=1";
        ;;
  *-*-win32*)
        unix=false ; windows=true;
        CPPFLAGS="$CPPFLAGS -DWINDOWS=1";
        # add the cross library stuff here
        ;;
  *)
        AC_MSG_RESULT([Unsupported operating system: ${host}])
        ;;
esac
