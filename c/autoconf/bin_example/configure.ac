## Process this file with autoconf to produce a configure script.
AC_INIT([Example], [0.1], [tiagokatcipis@gmail.com])

AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_AUX_DIR(build-aux)

AM_INIT_AUTOMAKE

AC_CONFIG_SRCDIR([src])

# Checks for programs
# ----------------------------------------------------------------------------
AC_LANG([C])
AC_PROG_CC
AC_PROG_LN_S
AC_PROG_LIBTOOL
AC_PROG_INSTALL

# ----------------------------------------------------------------------------
# If you want to check for PKG_CONFIG (very useful)
# PKG_PROG_PKG_CONFIG

# --------------------------------------------------------------------------------
# If you want to check for a library you can use PKG_CONFIG MACRO
# See: http://linux.die.net/man/1/pkg-config
# --------------------------------------------------------------------------------
# PKG_CHECK_MODULES(LIBRARY_NAME, library_name_on_pkg_config >= version_required)
# AC_SUBST(LIBRARY_NAME_LIBS)
# AC_SUBST(LIBRARY_NAME_CFLAGS)
# AC_SUBST(LIBRARY_NAME_VERSION)
# --------------------------------------------------------------------------------

# Create files
# ----------------------------------------------------------------------------
AC_CONFIG_FILES([Makefile])
AC_CONFIG_FILES([src/Makefile])

AC_OUTPUT
	
