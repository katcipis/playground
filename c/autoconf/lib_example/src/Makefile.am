lib_LTLIBRARIES = libexample.la 

# ----------------------------------------------------
# CFLAGS goes here
# ----------------------------------------------------
libexample_la_CFLAGS = -Wall -I../include


# ----------------------------------------------------
# LDFLAGS goes here
# ----------------------------------------------------
# libexample_la_LDFLAGS = -L@libdir@ 

libexample_la_SOURCES = example.c 

# make install hook command goes here, lets copy the lib to the current dir only
# libexample.so and libexample.a will be on the .libs directory on the src folder
# do not install it or you will have a dummy library on your system :-). 
install-exec-hook:
	ln -s -f @libdir@/libexample.so ./
	
