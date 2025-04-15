#include <stdio.h>

void division(int dividende, int diviseur, int *quotient, int *reste){
  *quotient = dividende / diviseur;
  *reste = dividende % diviseur;
}

int main(){
  int dividende, diviseur, quotient, reste;
  printf("Entrez le dividende: ");
  scanf("%d", &dividende);
  printf("Entrez le diviseur : ");
  scanf("%d", &diviseur);
  division(dividende, diviseur, &quotient, &reste);
  printf("Le quotient de %d par %d est : %d\n", dividende, diviseur, quotient);
  printf("Le reste de la division est : %d\n", reste);
  return 0;
}
    
  
