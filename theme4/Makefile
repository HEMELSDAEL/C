CC = gcc
CFLAGS = -Werror -Wall -ansi -pedantic

all : swap division args_main strip_spaces_tst main_swap_ptr dicho

swap : swap.o
	$(CC) $(CFLAGS) $^ -o $@

swap.o : swap.c
	$(CC) $(CFLAGS) -c swap.c -o swap.o

division : division.o
	$(CC) $(CFLAGS) $^ -o $@

division.o : division.c
	$(CC) $(CFLAGS) -c division.c -o division.o

args_main : args_main.o
	$(CC) $(CFLAGS) $^ -o $@

args_main.o : args_main.c
	$(CC) $(CFLAGS) -c args_main.c -o args_main.o

strip_spaces_tst : strip_spaces_tst.o 
	$(CC) $(CFLAGS) $^ -o $@

strip_spaces_tst.o : skip_spaces.c
	$(CC) $(CFLAGS) -c skip_spaces.c -o strip_spaces_tst.o

skip_spaces : skip_spaces.o
	$(CC) $(CFLAGS) $^ -o $@

skip_spaces.o : skip_spaces.c
	$(CC) $(CFLAGS) -c skip_spaces.c -o skip_spaces.o

swap_ptr : swap_ptr.o
	$(CC) $(CFLAGS) $^ -o $@

swap_ptr.o : swap_ptr.c
	$(CC) $(CFLAGS) -c swap_ptr.c -o swap_ptr.o

dicho : dicho.o
	$(CC) $(CFLAGS) -o $@ $^

dicho.o : dicho.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f *.o

