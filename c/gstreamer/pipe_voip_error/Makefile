all: pipe_voip

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-0.10`

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

pipe_voip: pipe_voip.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

clean:
	rm -rf pipe_voip *.o


