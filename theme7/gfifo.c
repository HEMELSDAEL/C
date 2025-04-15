#include "gfifo.h"
#include <stdlib.h>

struct gfifo_node_s{
  void *data;
  struct gfifo_node_s *next;
};

struct gfifo_s{
  struct gfifo_node_s *first;
  struct gfifo_node_s *last;
};

struct gfifo_s *gfifo_new(){
  struct gfifo_s *f = (struct gfifo_s *)malloc(sizeof(struct gfifo_s));
  if(f==NULL){
    return NULL;
  }
  f->first = NULL;
  f->last = NULL;
  return f;
}

int gfifo_del(struct gfifo_s *f){
  if(f==NULL){
    return -1;
  }
  while(f->first != NULL){
    struct gfifo_node_s *temp = f->first;
    f->first = f->first->next;
    free(temp->data);
    free(temp);
  }
  free(f);
  return 0;
}

int gfifo_size(struct gfifo_s *f){
  int size = 0;
  struct gfifo_node_s *current_node = f->first;
  while(current_node != NULL){
    size++;
    current_node = current_node->next;
  }
  return size;
}

int gfifo_enqueue(struct gfifo_s *f, void *p){
  if(f == NULL){
    return -1;
  }
  struct gfifo_node_s *new_node = (struct gfifo_node_s *)malloc(sizeof(struct gfifo_node_s));
  if(new_node == NULL){
    return -1;
  }
  new_node->data = p;
  new_node->next = NULL;

  if(f->last == NULL){
    f->first = new_node;
    f->last = new_node;
  }else{
    f->last->next = new_node;
    f->last = new_node;
  }
  return 0;
}

int gfifo_dequeue(struct gfifo_s *f, void **){
  if(f == NULL || f->first == NULL || p == NULL){
    return -1;
  }

  *p = f->first->data;
  struct gfifo_node_s *temp = f->first;
  f->first = f->first->next;
  if(f->first == NULL){
    f->last = NULL;
  }
  free(tmp);
  return 0;
}

typedef void (gfunc_t)(void *);
void gfifo_apply(struct gfifo_s *f, gfunc_t *fn){
  if(f == NULL `|| fn == NULL){
    return;
  }
  struct gfifo_node_s *current_node = f->first;
  while(current_node != NULL){
    fn(current_node -> data);
    current_node = current_node->next;
  }
}
