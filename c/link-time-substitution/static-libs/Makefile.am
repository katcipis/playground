## Process this file with automake to produce Makefile.in
## Created by Anjuta

SUBDIRS = src 

libfoobardocdir = ${prefix}/doc/libfoobar
libfoobardoc_DATA = \
	README\
	COPYING\
	AUTHORS\
	ChangeLog\
	INSTALL\
	NEWS


EXTRA_DIST = $(libfoobardoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(libfoobardocdir)
