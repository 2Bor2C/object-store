CC=gcc
CFLAGS=-I.

DEPS=object-store.h stack.h
OBJ=object-store.o stack.o test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f ./*.o test 
