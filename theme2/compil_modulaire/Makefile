
CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic
all : numbers_test
numbers_test : put_numbers.o numbers_test.o 
	$(CC) $(CFLAGS) $^ -o $@
%.o : %.c put_numbers.h
	$(CC) $(CFLAGS)-c $<
clean : rm -f *.o numbers_test
.PHONY : all clean
