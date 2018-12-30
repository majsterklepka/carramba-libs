prefix=@prefix@
PACKAGE = @PACKAGE@
VERSION = @VERSION@
exec_prefix=${prefix}
bindir=@bindir@
libdir=@libdir@
includedir=@includedir@
datadir=@datadir@
mandir=@mandir@
infodir=@infodir@
docdir=${datadir}/doc/${PACKAGE}
ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libcarramba.la
libcarramba_la_SOURCES = carramba-libs.h main.c src/nip.c src/pesel.c src/regon.c src/iban.c
libcarramba_la_LDFLAGS = $(GMP_LIBS) -version-info 1:0:0
include_HEADERS = carramba-libs.h
