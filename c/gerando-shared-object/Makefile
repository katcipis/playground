all: libexemplo

CFLAGS=-O2 -Wall -shared 

libexemplo: exemplo.c
	$(CC) $(CFLAGS) $? -o libexemplo.so

clean:
	rm -rf libexemplo *.o
	rm -rf libexemplo *.so

