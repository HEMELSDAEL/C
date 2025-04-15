#include <stdlib.h>        /*pour rand()*/
#include <string.h>        /*pour memcpm()*/
#include <assert.h>        /*pour assert()*/
#include <stdio.h>
#include "mmemcpy.h"

#define SIZE 1021

void test_mmemcpy(){
  char tc_orig[SIZE], tc_dest[SIZE];
  long int ti_orig[SIZE], ti_dest[SIZE];
  int i;

  /*initialisation*/
  for(i=0; i<SIZE; i++){
    tc_orig[i] = rand()%256;
    tc_dest[i] = rand()%256;
    ti_orig[i] = rand();
    ti_dest[i] = rand();
  }

  /*copie*/
  memcpy(tc_dest, tc_orig, SIZE);
  memcpy(ti_dest, ti_orig, SIZE * sizeof(long int));

  /*vérification*/
  assert(memcmp(tc_orig, tc_dest, SIZE) == 0);
  assert(memcmp(ti_orig, ti_dest, SIZE * sizeof(long int)) == 0);
}

int main() {
    test_mmemcpy();
    printf("Tests passed successfully!\n");
    return 0;
}
