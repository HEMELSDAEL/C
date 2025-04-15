#include<stdio.h>

int longchar(int c){
  #ifdef NOLOG
     return 0;
  #else
     return putchar(c);
  #endif
}

int main() {
    int i=1;
    i=3*i;
    longchar('0'+i);
    return i;
}
