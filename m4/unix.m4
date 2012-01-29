dnl add a #define to the config.h
AC_DEFINE([ENABLE_UNIX_BUILD],[1], [Define if we are building for unix])

dnl configure username / file attributes on unix
m4_include([m4/unix/username.m4])
m4_include([m4/unix/stat.m4])
