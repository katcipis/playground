WRAP_FLAGS=-Wl,--wrap=malloc

all:
	$(CC) -Wall -Werror -g -o libcallmalloc.so -shared call-malloc.c -fPIC
	$(CC) -Wall -Werror -g $(WRAP_FLAGS) -o libcallmallocwrapped.so -shared call-malloc.c -fPIC
	$(CC) -Wall -Werror -g -c -o callmallocstatic.o call-malloc.c 
	$(AR) rcs libcallmallocstatic.a callmallocstatic.o 
	$(CC) -Wall -Werror -g $(WRAP_FLAGS) -o malloc-wrapper-with-static-lib malloc-wrapper.c -L. -lcallmallocstatic
	$(CC) -Wall -Werror -g $(WRAP_FLAGS) -o malloc-wrapper-with-shared-lib malloc-wrapper.c -L. -lcallmalloc 
	$(CC) -Wall -Werror -g $(WRAP_FLAGS) -o malloc-wrapper-with-wrapped-shared-lib malloc-wrapper.c -L. -lcallmallocwrapped

clean:
	rm *.so
	rm *.o
	rm *.a
	rm malloc-wrapper-with-shared-lib
	rm malloc-wrapper-with-wrapped-shared-lib
	rm malloc-wrapper-with-static-lib

