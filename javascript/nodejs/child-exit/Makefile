CC = gcc
CFLAGS = -g -Wall 

all: seg-fault-proc

check: clean all

seg-fault-proc: $(OBJECTS)
	$(CC) -o seg-fault-proc $(CFLAGS) seg-fault-proc.c

clean:
	rm -f *.o seg-fault-proc

.PHONY: all
.PHONY: count
.PHONY: clean
