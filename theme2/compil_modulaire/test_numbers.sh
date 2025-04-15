gcc -c put_numbers.c -lm
gcc -c numbers_test.c -lm
gcc put_numbers.o numbers_test.o -o numbertest -lm
