#include <stdio.h>

float *search_dicho_rec(float v, float *tab, int size){
  if(size <=0){
    return NULL;
  }
  int mid = size/2;
  if(v == tab[mid]){
    return &tab[mid];
  }else if (v < tab[mid]){
    return search_dicho_rec(v, tab, mid);
  }else{
    float *res = search_dicho_rec(v, &tab[mid + 1], size - mid -1);
    if(res != NULL){
      return res;
    }else{
      return NULL;
    }
  }
}
  

float *search_dicho_imp(float v, float *tab, int size){
  int start = 0;
  int end = size - 1;
  while(start <= end){
    int mid = start + (end - start)/2;
    if(v==tab[mid]){
      return &tab[mid];
    }else if(v < tab[mid]){
      end = mid - 1;
    }else{
      start = mid + 1;
    }
  }
  return NULL;
}
  
int main(){
  float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  int size = sizeof(arr) / sizeof(arr[0]);
  float value = 3.3;
  printf("Recherche de la valeur %.1f dans le table  \n",value);
  float *res = search_dicho_imp(value, arr, size);
  if(res!=NULL){
    printf("La valeur %.1f a été trouvée à l'adresse mémoire %p (recherche impérative)\n", value, res);
  }else{
    printf("La valeur %.1f n'a pas été trouvée dans le tableau (recherche impérative).\n", value);
  }
  float *res_rec = search_dicho_rec(value, arr, size);
  if (res_rec != NULL) {
        printf("La valeur %.1f a été trouvée à l'adresse mémoire %p (recherche récursive)\n", value, res_rec);
    } else {
        printf("La valeur %.1f n'a pas été trouvée dans le tableau (recherche récursive).\n", value);
    }
    
    return 0;
}
