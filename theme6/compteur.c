#include <stdio.h>

int compteur(){
  static int cpt = 0;
  return cpt++;
}
