dnl add a #define to the config.h
AC_DEFINE([ENABLE_WINDOWS_BUILD],[1], [Define if we are building for windows])

dnl username / file attributes on windows
m4_include([m4/windows/username.m4])
m4_include([m4/windows/file_attributes.m4])
