all: message_post_ex

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-0.10`

CFLAGS=-O2 -fPIC --shared -Wall -I./ $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

message_post_ex: ./gsttestmessage.c 
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o libgstmessage_post_ex.so

clean:
	rm -rf message_post_ex *.o

