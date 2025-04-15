CC = gcc
CFLAGS = -W -Wall -ansi -pedantic

mcu_uniq : mcu_uniq.o mcu_readl.o mcu_fatal.o mcu_wl.o
	$(CC) $(CFLAGS) -o build/mcu_uniq src/mcu_uniq.o src/mcu_readl.o src/mcu_fatal.o src/mcu_wl.o

mcu_rev : mcu_rev.o mcu_readl.o mcu__fatal.o mcu_wl.o
	$(CC) $(CFLAGS) -o build/mcu_rev src mcu_rev.o src/mcu_readl.o src/mcu_fatal.o src/mcu_wl.o

mcu_wc: mcu_wc.o
	$(CC) $(CFLAGS) -o build/mcu_wc src/mcu_wl.o

mcu_wl : mcu_wl.o
	$(CC) $(CFLAGS) -o build/mcu_wl src/mcu_wl.o src/mcu_wl.o

mcu_test: mcu_test.o
	$(CC) $(CFLAGS) -o build.mcu_test src/mcu_test.o src/mcu_readl.o src/mcu_fatal.o src/mcu_putint.o

mcu_test.o : mcu_readl.o mcu_fatal.o mcu_putint.o
	$(CC) $(CFLAGS) -c src/mcu_test.c -o src/mcu_test.o

mcu_readl.o : src/mcu_readl.c
	$(CC) $(CFLAGS) -c src/mcu_readl.c -o src/mcu_readl.o

mcu_fatal.o : src/mcu_fatal.c
	$(CC) $(CFLAGS) -c src/mcu_fatal.c -o src/mcu_fatal.o

mcu_putint.o : src/mcu_putint.c
	$(CC) $(CFLAGS) -c src/mcu_putint.c -o src/mcu_putint.o

mcu_wc.o : src/mcu_wc.c
	$(CC) $(CFLAGS) -c src/mcu_wc.c -o src/mcu_wc.o

mcu_wl.o : src/mcu_wl.o
	$(CC) $(CFLAGS) -c src/mcu_wl.c -o src/mcu_wl.o

mcu_testwl.o : mcu_wl.o
	$(CC) $(CFLAGS) -c src/mcu_wl.c -o src/mcu_testwl.o

mcu_rev.o : src/mcu_rev.o
	$(CC) $(CFLAGS) -c src/mcu_rev.c -o src/mcu_rev.o

mcu_uniq.o : src/mcu_uniq.o
	$(CC) $(CFLAGS) -c src/mcu_uniq.c -o src/mcu_uniq.o

clean :
	rm -f src/*.o
	rm -f build/*
