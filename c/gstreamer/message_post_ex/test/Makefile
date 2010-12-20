all: test_message_app

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-app-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-app-0.10`

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

test_message_app: test_message_app.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

clean:
	rm -rf test_message_app *.o
