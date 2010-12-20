all: calc_bind

LUA_CFLAGS=`pkg-config --cflags lua5.1`
LUA_LFLAGS=`pkg-config --libs lua5.1`

CFLAGS=-O2 -Wall $(LUA_CFLAGS) -I./
LDFLAGS=-L. $(LUA_LFLAGS)

calc_bind: calc_bind.c calc_main.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o main

clean:
	rm -rf main *.o 

