#include "commun.h"
#include <stdio.h>

void affiche_etudiant(struc etudiant_s etudiant){
  printf("Le numéro de cet étudiant est : %d\nLa moyenne de cet étudiant est : %.2f\nIl s'appelle : %s %s\n", etudiant.numero, etudiant.moyenne, etudiant.nom, etudiant.prenom);
}

