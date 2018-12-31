#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# Release version
m4_define([package_version_major],[0])
m4_define([package_version_minor],[0])
m4_define([package_version_micro],[1])

# API version
m4_define([api_version],[1])

AC_PREREQ([2.69])
AC_INIT([Carramba Libs], [package_version_major.package_version_minor.package_version_micro], [starywandal@onet.pl])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AM_PROG_AR
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC

# Dependencies
PKG_PROG_PKG_CONFIG
PKG_INSTALLDIR


AC_SUBST([PACKAGE_VERSION_MAJOR],package_version_major)
AC_SUBST([PACKAGE_VERSION_MINOR],package_version_minor)
AC_SUBST([PACKAGE_VERSION_MICRO],package_version_micro)
AC_SUBST([API_VERSION],api_version)

LT_INIT(disable-static)

AC_CANONICAL_BUILD

# Checks for libraries.
AC_LANG(C)
AC_CHECK_LIB([gmp],[main],[HAVE_GMP=1, GMP_LIBS="$GMP_LIBS -lgmp"], [gmp not instaled!])
AC_DEFINE_UNQUOTED([BUILDER],["$USER"],[builder])
AC_DEFINE_UNQUOTED([BUILD_CPU],["$build_cpu"],[build cpu])
AC_DEFINE_UNQUOTED([BUILD_VENDOR],["$build_vendor"],[build vendor])
AC_DEFINE_UNQUOTED([BUILD_OS],["$build_os"],[build os])

# Checks for header files.
AC_CHECK_HEADERS([locale.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([carramba-$API_VERSION.pc:carramba.pc.in],[API_VERSION='$API_VERSION'])

AC_OUTPUT
