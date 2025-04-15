#include "dicho1.h"

float *search_interval(float v, float *tab, float *end){
  if(end<tab){
    return NULL;
  }
  if(end == tab){
    if(*end == v){
      return end;
    }else{
      return NULL;
    }
  }
  float *mid = tab + (end - tab)/2;

  if(*mid == v){
    return mid;
  }
  if(v < *mid){
    return search_interval(v, tab, mid - 1);
  }
  return search_interval(v, mid + 1, end);
}
