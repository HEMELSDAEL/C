/* ------------------------------
   output.c
   Écriture de données
   ------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "commun.h"
#define NB_NOMS = 11

int main(void) {
  int i;
  int num_etu;
  char noms[][LONG_MAX] = {"HEMELSDAEL", "DUPOND", "EZLZLZ", "AZERTY", "DELATTRE", "DELOTTRE", "MBAPPE", "JUIEEFK", "FKEKFEKGS", "FKRKGRG", "FJEFEZMA"};
  char prenoms[][LONG_MAX] = {"Alexandre", "Robert", "Apeofe" , "Qwerty", "Flavien", "Patrick", "Kylian", "Pierre", "Franck", "Alphonse"};
  union bloc_u mon_union;
  int nb_etudiants = (rand() % (NB_ETU)) + 1;

  for (num_etu = 1; num_etu <= nb_etudiants; num_etu++){
    mon_union.classe.etudiants[(num_etu-1)].numero = num_etu;
    mon_union.classe.etudiants[(num_etu-1)].moyenne = rand()%21;
    strcpy(mon_union.classe.etudiants[(num_etu-1)].nom, noms[rand() % (NB_NOMS)]);
    strcpy(mon_union.classe.etudiants[(num_etu-1)].prenom, prenoms[rand() % (NB_NOMS)]);
    /*printf(" %s ", mon_union.classe[num_etu-1].prenom);*/
  }
  mon_union.classe.effectif = nb_etudiants;

  for(i=0; i < sizeof(union bloc_u); i++){
    putchar(mon_union.data[i]);
  }
  return 0;
}
