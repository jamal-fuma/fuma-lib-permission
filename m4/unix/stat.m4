dnl file attributes on unix use the st_mode member of struct stat which is mode_t
AC_TYPE_MODE_T
AC_CHECK_HEADERS([sys/types.h sys/stat.h])

dnl we need stat(2) and chmod(2) for permissions checks
AC_FUNC_STAT
AC_FUNC_CHMOD

dnl we need stuct stat.st_mode for permissions checks
AC_CHECK_MEMBER(
        [struct stat.st_mode],
        [AC_DEFINE(HAVE_STAT_ST_MODE,, Define if stat.st_mode )],
        [AC_MSG_ERROR(['We need stat.st_mode'])],
        [
#include <sys/types.h>
#include <sys/stat.h>
        ])
