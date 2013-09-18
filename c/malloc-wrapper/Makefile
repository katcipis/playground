WRAP_FLAGS=-Wl,--wrap=malloc

all:
	$(CC) -g -o libcallmalloc.so -shared call-malloc.c -fPIC
	$(CC) -g $(WRAP_FLAGS) -o malloc-wrapper malloc-wrapper.c -L. -lcallmalloc 
	$(CC) -g $(WRAP_FLAGS) -o libcallmallocwrapped.so -shared call-malloc.c -fPIC
	$(CC) -g $(WRAP_FLAGS) -o malloc-wrapper-with-wrapped-lib malloc-wrapper.c -L. -lcallmallocwrapped

clean:
	rm *.so
	rm malloc-wrapper

