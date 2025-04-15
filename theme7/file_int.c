#include <stdio.h>
#include <stdlib.h>

struct ififo_node_s{
  int value;
  struct ififo_node_s *next;
};

struct ififo_s{
  struct ififo_node_s *first;
  struct ififo_nodes_s *last;
}


struct ififo_s ififo_new(){
  struct ififo_s *f = malloc(sizeof(struct ififo_s));
  if(f==NULL){
    return NULL;
  }
  f->first = NULL;
  f->last = NULL;
  return f;
}
  
