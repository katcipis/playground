all: static_meta

CFLAGS=-O2 -Wall 

static_meta: static_meta.cpp
	g++ $(CFLAGS) $? -o $@

clean:
	rm -rf static_meta *.o


