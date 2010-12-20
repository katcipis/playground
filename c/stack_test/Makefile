all: stack_test stack_test_assembly

CFLAGS=-O2 -Wall 

stack_test: stack_test.c
	$(CC) $? -o $@ $(CFLAGS)

stack_test_assembly: stack_test.c
	$(CC) $? -S $(CFLAGS)

clean:
	rm -rf stack_test *.o *.s

