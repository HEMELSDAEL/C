#include <stdio.h>
#include <math.h>

float square(float nombre){
  return nombre*nombre;
}

int is_within_distance(float x1, float y1, float x2, float y2, float dist){
  float distance = sqrt(square(x2-x1) + square(y2-y1));
  if(distance>dist){
    return 0;
  }
  else{
    return 1;
  }
}

int main(void){
  printf("\n%f\n", square(3));
  printf("\n");
  printf("Distance entre les deux points de coordonnées (2,2) et (10, 10) : 11.3137084989848\n");
  printf("Test1 (dist=10) : %d\n", is_within_distance(2, 2, 10, 10, 10));
  printf("Test2 (dist=12) : %d\n", is_within_distance(2, 2, 10, 10, 12));
}
