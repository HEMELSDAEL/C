#include <stdio.h>
#include <stdlib.h>


int copyTab(int tsrc[], int tdest[], int taille){
  int i;
  for (i=0; i<taille; i++){
    tdest[i] = tsrc[i];
  }
  return i;
}
