all: block_on_set_state_test

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-0.10`

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

block_on_set_state_test: block_on_set_state_test.c
	$(CC) $? -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf block_on_set_state_test *.o

