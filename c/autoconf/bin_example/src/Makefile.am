bin_PROGRAMS = example 

# ----------------------------------------------------
# CFLAGS goes here
# ----------------------------------------------------
# example_CFLAGS = -Wall 


# ----------------------------------------------------
# LDFLAGS goes here
# ----------------------------------------------------
# example_LDFLAGS = -L@libdir@ 

example_SOURCES = example.c 

# make install hook command goes here.
# do not install it or you will have a dummy exec on your system :-). 
install-exec-hook:
	ln -s -f @bindir@/example ./
	
