all: bus_poll_test

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-0.10`

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

bus_poll_test: bus_poll_test.c
	$(CC) $? -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf bus_poll_test *.o

