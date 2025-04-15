#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mstrdup.h"

int main(int argc, char *argv[]){
  int i;
  char *copy;
  for(i=1; i < argc; i++){
    copy = mstrdup(argv[i]);
    if(copy != NULL){
      printf("%s\n", copy);
      free(copy);
    }
  }
  return 0;
}
