prefix=@prefix@
PACKAGE = @PACKAGE@
VERSION = @VERSION@
PACKAGE_VERSION_MAJOR = @PACKAGE_VERSION_MAJOR@
PACKAGE_VERSION_MINOR = @PACKAGE_VERSION_MINOR@
PACKAGE_VERSION_MICRO = @PACKAGE_VERSION_MICRO@
exec_prefix=${prefix}
bindir=@bindir@
libdir=@libdir@
includedir=@includedir@
datadir=@datadir@
pkgconfigdir = ${libdir}/pkgconfig
mandir=@mandir@
infodir=@infodir@
docdir=${datadir}/doc/${PACKAGE}
ACLOCAL_AMFLAGS = -I m4

SUBDIRS = doc 

pkglib_LTLIBRARIES = libcarramba.la
libcarramba_la_SOURCES = carramba-libs.h main.c src/nip.c src/pesel.c src/regon.c src/iban.c
libcarramba_la_LDFLAGS = $(GMP_LIBS) -version-info $(PACKAGE_VERSION_MAJOR):$(PACKAGE_VERSION_MICRO):$(PACKAGE_VERSION_MINOR)
pkginclude_HEADERS = carramba-libs.h
pkgconfig_DATA = carramba-libs.pc

CLEANFILES = carramba-libs.pc
