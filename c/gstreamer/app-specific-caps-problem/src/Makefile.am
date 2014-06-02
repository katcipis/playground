AM_CFLAGS =\
	 -Wall\
	 -Wextra\
	 -Werror\
	 -g

plugin_LTLIBRARIES = libgstappspecificcaps.la

libgstappspecificcaps_la_SOURCES = gstappspecificcaps.c
libgstappspecificcaps_la_CFLAGS = $(GST_CFLAGS) $(AM_CFLAGS)
libgstappspecificcaps_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)
libgstappspecificcaps_la_LIBADD = $(GST_LIBS)
libgstappspecificcaps_la_LIBTOOLFLAGS = --tag=disable-static

noinst_HEADERS = gstappspecificcaps.h
