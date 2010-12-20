all: echofilter

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-0.10`

CFLAGS=-O2 --shared -Wall -I./include $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

echofilter: ./src/gstechofilter.c ./src/gstechoplugin.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o libgstechofilter.so

clean:
	rm -rf echofilter *.o
