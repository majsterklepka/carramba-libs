#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# Release version
m4_define([package_version_major],[0])
m4_define([package_version_minor],[0])
m4_define([package_version_micro],[1])

AC_PREREQ([2.69])
AC_INIT([Carramba Libs], [package_version_major.package_version_minor.package_version_micro], [starywandal@onet.pl], [], [])
AC_CONFIG_AUX_DIR([doc])
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
AC_CANONICAL_BUILD

#defining library version
AC_SUBST([LIB_VERSION], [package_version_major:package_version_micro:package_version_minor])

LT_INIT(disable-static)


# Checks for libraries.
AC_LANG(C)
AC_CHECK_LIB([gmp],[main],[HAVE_GMP=1, LDLIBS="$LDLIBS -lgmp"], [gmp not instaled!])
AC_DEFINE_UNQUOTED([BUILDER],["$USER"],[maintainer/builder])
AC_DEFINE_UNQUOTED([BUILD],["$build"],[build])

LDFLAGS="-L/usr/lib"
LDFLAGS="$LDFLAGS -Wl,-rpath -Wl,${libdir}/$PACKAGE"
LIBS="$LDLIBS"
CFLAGS="-I${includedir}/$PACKAGE"

PACKAGE_LIBS="-lcarramba"
PACKAGE_SUMMARY="$PACKAGE_NAME - library for validate IBAN, NIP, REGON, PESEL"
PACKAGE_CFLAGS=$CFLAGS
PACKAGE_LDFLAGS=$LDFLAGS
PACKAGE_NAME="carramba-libs"

AX_CREATE_PKGCONFIG_INFO 


# Checks for header files.
AC_CHECK_HEADERS([locale.h stdlib.h string.h error.h errno.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([doc/Makefile])


AC_OUTPUT

