#include <stdio.h>
#include "mcu_macros.h"
#include "mcu_readl.h"
#include "mcu_wl.h"


/* Fonction qui compare deux chaînes de caractères */
int comparer(char chaine1[], char chaine2[]) {
    int i = 0;
    while (chaine1[i] != '\0' && chaine2[i] != '\0') {
        if (chaine1[i] != chaine2[i]) {
	  return 1; /* Les chaînes sont différentes*/
        }
        i++;
    }
    /*Vérifier si les deux chaînes ont la même longueur*/
    if (chaine1[i] != chaine2[i]) {
      return 1; /* Les chaînes sont différentes*/
    }
    return 0; /* Les chaînes sont identiques*/
}

void copier(char cible[], char source[]){
  int i = 0;
  while(source[i] != '\0'){
    cible[i] = source[i];
    i++;
  }
  cible[i] = '\0';
}

int main(void){
  char former_line[(MAXLINE)]="";
  char current_line[(MAXLINE)];
  int i;
  while(readl(current_line) != EOF){
    if(comparer(former_line, current_line)){
      copier(former_line, current_line);

      i = 0;
      while(current_line[i]){
	putchar(current_line[i++]);
      }
    }
  }
}


