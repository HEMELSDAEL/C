CC = gcc
CFLAGS=-ansi -Wall -pedantic

all: input output exo8

input: input.o
	$(CC) $(CFLAGS) -o $@ $^

output: output.o
	$(CC) $(CFLAGS) -o $@ $^

input.o: input.c commun.h affiche.h
	$(CC) $(CFLAGS) -c input.c

output.o: output.c commun.h
	$(CC) $(CFLAGS) -c output.c

affiche.o : affiche.c commun.h
	$(CC) $(CFLAGS) -c affiche.c

test: input output
	./output > data.bin
	./input < data.bin
	hexdump ./data.bin

test-exo10 : input
	./input < data.bin

test-exo9 : output
	./output > data.bin
	hexdump ./data.bin

test-exo8 : exo8
	./exo8
	./exo8 > data.bin
	hexdump ./data.bin

exo8 : prog.o
	$(CC) $(CFLAGS) -o $@ $^

prog.o : prog.c commun.h
	$(CC) $(CFLAGS) -c prog.c

clean:
	rm -f *.o output input data.bin exo8

.PHONY: all clean

