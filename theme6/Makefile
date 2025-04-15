CC = gcc
CFLAGS = -Werror -Wall -ansi -pedantic

all : test_compteur test_mstrdup

test_compteur : test_compteur.o compteur.o

test_compteur.o : test_compteur.c compteur.h
	$(CC) $(CFLAGS) -c $<

compteur.o : compteur.c compteur.h
	$(CC) $(CFLAGS) -c $<

test_mstrdup : test_mstrdup.o mstrdup.o

test_mstrdup.o : test_mstrdup.c mstrdup.h
	$(CC) $(CFLAGS) -c $<

mstrdup.o : mstrdup.c mstrdup.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f *.o
