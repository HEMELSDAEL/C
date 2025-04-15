/* mcu_wl.c*/
#include <stdio.h>
#include "mcu_macros.h"
#include "mcu_wl.h"

int wl(){
  int cpt = 0;
  int c = getchar();
  while(c != EOF){
    c = getchar();
    if (c == '\n'){
      cpt = cpt + 1;
    }
  }
  return cpt;
}


