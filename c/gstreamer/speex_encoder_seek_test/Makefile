all: speex_encoder_seek

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-app-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-app-0.10`

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

speex_encoder_seek: speex_encoder_seek.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

clean:
	rm -rf speex_encoder_seek *.o

