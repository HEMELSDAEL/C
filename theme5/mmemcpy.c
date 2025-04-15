#include "mmemcpy.h"

void mmemcpy(void *to, const void *from, unsigned int size){
  char *dest = (char *)to;
  const char *src = (const char *)from;

  for(unsigned int i=0; i< size; i++){
    dest[i] = src[i];
  }
}
