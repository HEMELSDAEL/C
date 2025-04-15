#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *mstrdup(const char *str){
  char *newstr = NULL;
  int length = strlen(str) + 1;
  newstr = malloc(length);
  if(newstr != NULL){
    memcpy(newstr, str, length);
  }
  else{
    return NULL;
  }
  return newstr;
}
