all: bug_appsink_block

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-app-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-app-0.10`

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

bug_appsink_block: bug_appsink_block.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

clean:
	rm -rf bug_appsink_block *.o
