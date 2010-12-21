all: gio_block_test

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-0.10`

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

gio_block_test: gio_block_test.c
	$(CC) $? -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf gio_block_test *.o

