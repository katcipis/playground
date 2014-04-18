CFLAGS=`pkg-config --cflags gstreamer-1.0 gio-2.0`
LIBS=`pkg-config --libs gstreamer-1.0 gio-2.0`
all:
	$(CC) $(CFLAGS) -Wall -Werror streamer.c -o streamer $(LIBS)

check: all

clean:
	rm -f streamer
