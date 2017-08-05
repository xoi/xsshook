#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([xsshook], [0.1.1])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([xsshook.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES(XSSHOOK, x11 xscrnsaver)

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_PID_T

# Checks for library functions.
AC_FUNC_FORK

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
