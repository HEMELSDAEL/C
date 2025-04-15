#include <stdio.h>
#include <string.h>
#include "env.h"

extern char **environ;

int nvar(){
  int count = 0;
  char **env_ptr = environ;
  while(*env_ptr != NULL){
    count++;
    env_ptr++;
  }
  return count;
}

void mprintenv(const char *vars[]){
  char **env_ptr = environ;
  while(*env_ptr !=NULL){
    if(vars == NULL){
      printf("%s\n", *env_ptr);
    }else{
      for(int i =0; vars[i] != NULL; i++){
	if(strcmp(vars[i], *env_ptr) == 0){
	  printf("%s\n", *env_ptr);
	  break;
	}
      }
    }
    env_ptr++;
    
}
}
