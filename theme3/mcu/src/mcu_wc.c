#include <stdio.h>

int wc(){
  int cpt = 0;
  int c= getchar();
  while(c != EOF){
    cpt = cpt + 1;
    c = getchar();
  }
  cpt = cpt + 1;
  return cpt;
}

int main(void){
  printf("%d", wc());
  return 0;
}
