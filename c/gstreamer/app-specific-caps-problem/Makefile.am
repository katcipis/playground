## Process this file with automake to produce Makefile.in
## Created by Anjuta

ACLOCAL_AMFLAGS = -I m4macros

SUBDIRS = src 

gstdocdir = ${prefix}/doc/gst
gstdoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(gstdoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(gstdocdir)
