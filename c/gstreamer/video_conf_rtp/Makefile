all: simple samplerate

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-0.10`

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS) -I$(PREFIX)/include
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

simple: simple.c
	$(CC) $? -o $@ $(CFLAGS) $(LDFLAGS)

samplerate: samplerate.c
	$(CC) $? -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf simple *.o samplerate *.o
