all: programa1 programa2

CFLAGS=-O2 -Wall 

programa1: programa1.c
	$(CC) $(CFLAGS) $? -o $@

programa2: programa2.c
	$(CC) $(CFLAGS) $? -o $@

clean:
	rm -rf programa1 programa2 *.o
