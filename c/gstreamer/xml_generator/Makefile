all: xml_generator

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-0.10`

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

xml_generator: xml_generator.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

clean:
	rm -rf xml_generator *.o

