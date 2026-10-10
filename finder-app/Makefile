CC := $(if $(CROSS_COMPILE),$(CROSS_COMPILE)gcc,gcc)
CFLAGS ?= -Wall -Werror -g

all: writer

writer: writer.o
	$(CC) $(CFLAGS) writer.o -o writer

writer.o: writer.c
	$(CC) $(CFLAGS) -c writer.c -o writer.o

clean:
	rm -f writer *.o

.PHONY: all clean
