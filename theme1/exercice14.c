#include <stdio.h>

int main(void){
  long int A = 256;
  char B = 'A';

  printf("test B+1 : %c \n", B+1);
  B = 'A';
  printf("test B=65 : %c \n", B = 65);
  B = 'A';
  printf("test B++ : %c \n", B++);
  B = 'A';
  printf("test B+'1' : %c \n", B+'1');
  B = 'A';
  printf("test B==65 : %d \n", B == 65);
  B = 'A';
  printf("test ++B : %c \n", ++B);
  B = 'A';
  printf("test B+A : %ld \n", B+A);
  B = 'A';
  printf("test B=256 : %c \n", B = 256);
  B = 'A';
  printf("test B=255 : %c \n", B = 255);
  B = 'A';
