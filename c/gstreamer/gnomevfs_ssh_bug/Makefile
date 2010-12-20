all: gnomevfs_ssh

GSTREAMER_CFLAGS=`pkg-config --cflags gstreamer-0.10`
GSTREAMER_LFLAGS=`pkg-config --libs gstreamer-0.10`

CFLAGS=-O2 -Wall $(GSTREAMER_CFLAGS)
LDFLAGS=-L. $(GSTREAMER_LFLAGS)

alaw_decoder_test: gnomevfs_ssh.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

clean:
	rm -rf gnomevfs_ssh *.o

