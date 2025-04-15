#include <stdio.h>
#include "mcu_macros.h"
#include "mcu_readl.h"
#include "mcu_wl.h"

void rev(char tab[]) {
  int compteur = 0;
  int i = 0;
  int j = 0;
  int check = 0;
  char c;
  while(check == 0){
    if (tab[j] != '\n'){
      compteur++;
      j++;
    }
    else{
      check = 1;
    }
  }
  for (i = 0; i<compteur/2; i++){
    c = tab[i];
    tab[i] = tab[compteur - 1 - i];
    tab[compteur - 1 - i] = c;
  }
}

int main() {
    char line[MAXLINE];
    // Lire chaque ligne et inverser son contenu
    int i;
    while (readl(line) != EOF) {
      i = 0;
       while (line[i]){
	  putchar(line[i++]);
       }
       putchar('\n');
    }
    return 0;
}
