## Process this file with automake to produce Makefile.in
## Created by Anjuta

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	$(LIBFOOBAR_CFLAGS)

AM_CFLAGS =\
	 -Wall\
	 -g

noinst_LTLIBRARIES = \
	libfoo.la \
	libbar.la

libbar_la_SOURCES = \
	libbar.c

libbar_la_LDFLAGS = \
	-static

libbar_la_LIBADD = \
	$(LIBFOOBAR_LIBS) \
	./libfoo.la

libfoo_la_SOURCES = \
	libfoo.c

libfoo_la_LDFLAGS = \
	-static

libfoo_la_LIBADD = $(LIBFOOBAR_LIBS)

