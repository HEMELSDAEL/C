/* ------------------------------
   commun.h
   Définition des types
   ------------------------------------------------------------
*/
#ifndef COMMUN
#define COMMUN
#define NB_ETU = 30
#define LONG_MAX = 11

struct etudiant_s {
  unsigned int numero;
  float moyenne;
  char nom[LONG_MAX];
  char prenom[LONG_MAX];
  
};

struct classe_s {
  int effectif;
  struct etudiant_s etudiants[(NB_ETU)];
};

union bloc_u {
    struct classe_s classe;
  char data[(NB_ETU) * sizeof(struct etudiant_s)];
};
#endif
