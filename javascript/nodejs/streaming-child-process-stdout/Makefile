CC = gcc
CFLAGS = -g -Wall 

all: streamer

check: clean all

streamer: $(OBJECTS)
	$(CC) -o streamer $(CFLAGS) streamer.c

clean:
	rm -f *.o streamer

.PHONY: all
.PHONY: count
.PHONY: clean
