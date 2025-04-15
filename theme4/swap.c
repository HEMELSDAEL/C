#include <stdio.h>

void swap_int(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){
  int num1, num2;

  printf("Entrez deux valeurs entières :");
  scanf("%d %d", &num1, &num2);
  printf("Avant l'échange : num1 = %d, num2 = %d\n", num1, num2);
  swap_int(&num1, &num2);
  printf("Après l'échange : num1 = %d, num2 = %d\n", num1, num2);
  return 0;
}

  
