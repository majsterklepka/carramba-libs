prefix=@prefix@

exec_prefix=${prefix}

bindir=@bindir@
libdir=@libdir@
includedir=@includedir@
datadir=@datadir@
pkgconfigdir = ${datadir}/pkgconfig

mandir=@mandir@
infodir=@infodir@

docdir=${datadir}/doc/@PACKAGE@

ACLOCAL_AMFLAGS = -I m4 --install

SUBDIRS = doc 

pkglib_LTLIBRARIES = libcarramba.la
libcarramba_la_SOURCES = carramba-libs.h main.c src/nip.c src/pesel.c src/regon.c src/iban.c

libcarramba_la_LDFLAGS = -version-info @LIB_VERSION@
 

pkginclude_HEADERS = carramba-libs.h
pkgconfig_DATA = carramba-libs.pc carramba-libs-uninstalled.pc carramba-libs-uninstalled.sh

CLEANFILES = carramba-libs.pc carramba-libs.pc.in carramba-libs-uninstalled.pc carramba-libs-uninstalled.sh
