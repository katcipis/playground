3RDPARTY_CFLAGS=`pkg-config --cflags gstreamer-1.0` 
3RDPARTY_LIBS=`pkg-config --libs gstreamer-1.0`

CC = gcc
CFLAGS = -g -Wall -I$(PREFIX)/include $(3RDPARTY_CFLAGS)
LIBS = $(3RDPARTY_LIBS) 

all: ogg-seek-test

check: clean all

ogg-seek-test: $(OBJECTS)
	$(CC) -o ogg-seek-test $(CFLAGS) ogg-seek-test.c $(LIBS)

clean:
	rm -f *.o ogg-seek-test

.PHONY: all
.PHONY: count
.PHONY: clean
