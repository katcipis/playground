
noinst_PROGRAMS = $(TEST_PROGS)

tests_includes = -I$(top_builddir)/src -I$(top_builddir)/tests 
libfoo_lib      = $(top_builddir)/src/libfoo.la
libbar_lib      = $(top_builddir)/src/libbar.la

AM_CPPFLAGS =\
    $(tests_includes)

AM_CFLAGS = -g\
    -Wall\
    -Werror\
    $(LIBFOOBAR_CFLAGS)

AM_LDFLAGS = -z muldefs


TEST_PROGS           = libfoo_test
libfoo_test_SOURCES  = \
	libfoo-test.c \
    libfoo-stub.c

libfoo_test_LDADD = \
    $(libfoo_lib)

TEST_PROGS          += libbar_test
libbar_test_SOURCES  = \
	libbar-test.c \
    libfoo-stub.c

libbar_test_LDADD = \
    $(libbar_lib)

check_PROGRAMS = $(TEST_PROGS)

TESTS = $(TEST_PROGS)
