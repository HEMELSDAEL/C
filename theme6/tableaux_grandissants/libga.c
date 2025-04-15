#include <stdlib.h>
#include <string.h>
#include "libga.h"

#define GA_INITIAL_SIZE 10

int
ga_set(struct ga_s *ga, unsigned int index, int val)
{
  if(index >= ga->ga_size){
    unsigned int new_size = index + 1;
    int *new_elements = (int *)realloc(ga->ga_elements, new_size * sizeof(int));
    if(new_elements == NULL){
      return -1;
    }
    memset(new_elements + ga->ga_size, 0, (new_size - ga->ga_size)*sizeof(int));
    ga->ga_elements = new_elements;
    ga->ga_size = new_size;
  }
  ga->ga_elements[index] = val;
  return 0;
}

int
ga_get(struct ga_s *ga, unsigned int index, int *val)
{
  if(index >= ga->ga_size){
    return -1;
  }
  *val = ga->ga_elements[index];
  return 0;
}

int 
ga_new(struct ga_s *ga)
{
  ga->ga_size = GA_INITIAL_SIZE;
  ga->ga_elements = (int *)malloc(ga->ga_size * sizeof(int));
  if(ga->ga_elements == NULL){
    return -1;
  }
  return 0; 
}

int
ga_del(struct ga_s *ga)
{
  free(ga->ga_elements);
  ga->ga_elements = NULL;
  ga->ga_size = 0;
  return 0;
}

