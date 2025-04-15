CC = gcc
CFLAGS = -Werror -Wall -ansi -pedantic -std=c99

all : test_env test_dicho1 test_mmemcpy

test_env : test_env.o env.o
	$(CC) $(CFLAGS) $^ -o $@

test_env.o : test_env.c env.h
	$(CC) $(CFLAGS) -c $<

env.o : env.c env.h
	$(CC) $(CFLAGS) -c $<

test_dicho1 : test_dicho1.o 
	$(CC) $(CFLAGS) $^ -o $@

test_dicho1.o : test_dicho1.c dicho1.c
	$(CC) $(CFLAGS) -c $<

dicho1.o : dicho1.c dicho1.h
	$(CC) $(CFLAGS) -c $<

test_mmemcpy : test_mmemcpy.o mmemcpy.o
	$(CC) $(CFLAGS) $^ -o $@

test_mmemcpy.o : test_mmemcpy.c mmemcpy.h
	$(CC) $(CFLAGS) -c $<

mmemcpy.o : mmemcpy.c mmemcpy.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o 

