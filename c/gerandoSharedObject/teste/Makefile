all: teste

CFLAGS=-O2 -Wall -I../
LDFLAGS=-L../ -lexemplo 

teste: teste.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

clean:
	rm -rf teste *.o

