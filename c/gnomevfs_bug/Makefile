all: ok_mutex_test ok_test crash_test

GNOMEVFS_CFLAGS=`pkg-config --cflags gnome-vfs-2.0`
GNOMEVFS_LFLAGS=`pkg-config --libs gnome-vfs-2.0`

CFLAGS=-O2 -Wall $(GNOMEVFS_CFLAGS)
LDFLAGS=-L. $(GNOMEVFS_LFLAGS)

ok_mutex_test: ok_mutex_test.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

ok_test: ok_test.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

crash_test: crash_test.c
	$(CC) $(CFLAGS) $(LDFLAGS) $? -o $@

clean:
	rm -rf ok_test ok_mutex_test crash_test *.o
