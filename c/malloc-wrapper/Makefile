all:
	$(CC) -o libcallmalloc.so -shared call-malloc.c -fPIC
	$(CC) -g -Wl,--wrap=malloc -o malloc-wrapper malloc-wrapper.c -L. -lcallmalloc 

