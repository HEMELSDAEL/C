#include <stdio.h>
#include <stdlib.h>

int put_digit(int digit){
  if (digit > 9 || digit < 0){
    return -1;
  }
  else{
    putchar(digit+48);
    return 0;
  }
}

int putdec(int d){
  int i = 1000000000;
  if(d == 0){
    return put_digit(0);
  }
  if (d < 0){
    putchar('-');
  }
  while((d/i)==0){
    i/=10;
  }
  while(i!=0){
    int n = (d/i)%10;
    if(n<0){
      n = -n;
    }
    put_digit(n);
    i/=10;
  }

  return 0;
}
