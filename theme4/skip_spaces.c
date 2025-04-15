#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

char* skip_spaces(char* s){
  while(*s && isspace(*s)){
    s++;
  }
  return s;

}
int main(int argc, char *argv[]){
  char *strip;
  int i;
  assert(argc == 2);
  printf("argv : %s\n", argv[1]);
  strip = skip_spaces(argv[1]);
  printf("strip : %s\n", strip);

  for(i=0; strip[i]; i++){
    strip[i] = toupper(strip[i]);
  }
  printf("strip : %s\n", strip);
  printf("argv : %s\n", argv[1]);

  exit(EXIT_SUCCESS);
}
