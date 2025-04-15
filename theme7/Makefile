CC ?= 		cc
CFLAGS ?=	-O0 -g -Wall -Werror -std=c89 -pedantic

all: arbre test_ififo

clean:
	rm -f *.o test_ififo test_gfifo test_tri_file arbre

arbre : tree.o
	$(CC) $(CFLAGS) $^ -o $@

test_tri_file:	test_tri_file.o ififo.o gfifo.o tri_file.o
	$(CC) $(CFLAGS) $^ -o $@

test_tri_file.o:	test_tri_file.c ififo.h tri_file.h
	$(CC) $(CFLAGS) -c $<

tri_file.o:	tri_file.c ififo.h gfifo.h tri_file.h
	$(CC) $(CFLAGS) -c $<

test_%.o:	test_%.c %.h
	$(CC) $(CFLAGS) -c $<

%.o:	%.c %.h
	$(CC) $(CFLAGS) -c $<

test_%:	test_%.o %.o %.h
	$(CC) $(CFLAGS) $^ -o $@


.PHONY:	all clean
