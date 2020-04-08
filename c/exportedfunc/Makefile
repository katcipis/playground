all:
	$(CC) -Wall -Werror -g -o libfunc.so -shared func.c -fPIC
	$(CC) -Wall -Werror -g -o caller caller.c -L. -lfunc

clean:
	rm *.so
	rm caller
