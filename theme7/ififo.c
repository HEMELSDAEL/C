#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ififo.h"

struct ififo_node_s {
  int value;
  struct ififo_node_s *next;

};

struct ififo_s {
  struct ififo_node_s *first;
  struct ififo_node_s *last;

};

ififo_t ififo_new() {
  ififo_t f =(ififo_t)malloc(sizeof(struct ififo_s));
  if(f==NULL){
    return NULL;
  }
  f->first = NULL;
  f->last = NULL;
  return f;

}

int ififo_is_empty(ififo_t fifo) {
    assert(fifo != NULL);
    return (fifo->first == NULL && fifo->last == NULL);
    
}

int ififo_enqueue(ififo_t fifo, int valeur) {
  assert(fifo!=NULL);
  struct ififo_node_s *new_node = (struct ififo_node_s*)malloc(sizeof(struct ififo_node_s));
  if(new_node==NULL){
    return -1;
  }
  new_node->value = valeur;
  new_node->next = NULL;
  if(fifo->last == NULL){
    fifo->first = new_node;
    fifo->last = new_node;
  }else{
    fifo->last->next = new_node;
    fifo->last = new_node;
  }
  return 0;

}

int ififo_dequeue(ififo_t fifo, int *valeur) {
  assert(fifo!=NULL && valeur != NULL);
  if (fifo == NULL || fifo->first == NULL || valeur == NULL) {
        return -1;
  }
  *valeur = fifo->first->value;
  struct ififo_node_s *temp = fifo->first;
  fifo->first = fifo->first->next;
  if(fifo->first == NULL){
    fifo->last = NULL;
  }
  free(temp);
  return 0;

}


int ififo_head(const ififo_t fifo) {
    assert(!ififo_is_empty(fifo));
    return fifo->first->value;

}

typedef int(func_t)(int);

void ififo_apply(ififo_t fifo, func_t *fonction) {
    assert(fifo != NULL);
    struct ififo_node_s *current_node = fifo->first;
    while(current_node != NULL){
      current_node->value = fonction(current_node->value);
      current_node = current_node->next;
    }
}

void ififo_del(ififo_t fifo) {
    assert(fifo != NULL);
    while(fifo->first != NULL){
      struct ififo_node_s *temp = fifo->first;
      fifo->first = fifo->first->next;
      free(temp);
    }
    free(fifo);

}
