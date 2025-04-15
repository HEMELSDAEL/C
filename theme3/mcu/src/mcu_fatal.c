#include <stdio.h>
#include <stdlib.h>

void fatal(int assert, const char message[], int status) {
  int i;
  if (assert == 0){
    for(i=0; message[i] != '\0'; i++){
      putchar(message[i]);
    }
  }
  else{
    for(i = 0; message[i] != '\0'; i++){
      putchar(message[i]);
      exit(status);
      }
  }
}
  
   
