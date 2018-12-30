#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Carramba library], [0.0.1], [starywandal@onet.pl])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AM_PROG_AR
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC

LT_INIT(disable-static)

AC_CANONICAL_BUILD

# Checks for libraries.
AC_LANG(C)
AC_CHECK_LIB([gmp],[main],[HAVE_GMP=1, GMP_LIBS="$GMP_LIBS -lgmp"], [gmp not instaled!])
AC_SUBST(BUILD_CPU)
AC_DEFINE_UNQUOTED([BUILD_CPU],[$build_cpu],[build cpu])
AC_SUBST(BUILD_VENDOR)
AC_DEFINE_UNQUOTED([BUILD_VENDOR],[$build_vendor],[build vendor])
AC_SUBST(BUILD_OS)
AC_DEFINE_UNQUOTED([BUILD_OS],[$build_os],[build os])

# Checks for header files.
AC_CHECK_HEADERS([locale.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
