# Classe d'allocation, portée

## Compteur

L'objectif est de proposer une une fonction de prototype `int
compteur()` qui renvoie 0 la première fois qu'elle est appelée, puis
ensuite 1, ensuite 2, et ainsi de suite. 

1. Donnez une définition de la fonction `compteur()`

1. Réalisez une fonction `main()` qui teste la fonction `compteur()`,
   par exemple en l'appelant 10 fois dans une boucle, et en affichant
   la valeur renvoyée.

# Allocation dynamique
----------------------

## Dupliquer une chaîne — _exercice de TP_ ##

Soit la fonction de prototype:

```c
char *mstrdup(const char *str);
```

qui renvoie une copie allouée dynamiquement de la chaîne de caractères
`str`. 

1. Donnez une définition de cette fonction `mstrdup()`. Que renvoie cette
   fonction en cas de problème ? 

1. Réalisez un `main()` pour tester votre fonction `mstrdup()`. Par
   exemple copiez une à une les chaînes de caractères de `argv` et
   affichez-les. Pensez à libérer avec `free()` la mémoire allouée.

## Tableaux grandissants

Les tableaux en C sont de taille fixe. L'objet de cet exercice est de
développer une structure de données _tableaux grandissants_ qui
autorise :

* la mémorisation d'une séquence d'éléments (ici de type `int`), 
* des accès indexés à partir de zéro à ces éléments, à la fois en
  lecture – obtenir la valeur de l'élément –, et en écriture
  – modifier la valeur de l'élément –, 
* l'allocation automatique de la mémoire nécessaire, au fur et
  à mesure que des écritures d'éléments sont réalisés.

L'interface de cette structure de données est la suivante :

```c
int ga_set(struct ga_s *ga, unsigned int index, int val);
int ga_get(struct ga_s *ga, unsigned int index, int *val);
int ga_new(struct ga_s *ga); 
int ga_del(struct ga_s *ga); 
```

* les fonctions `ga_new()` et `ga_del()` permettent de créer,
  respectivement désallouer, un tableau grandissant,
* les fonctions `ga_set()` et `ga_get()` permettent d'accéder en
  écriture, respectivement en lecture, à un élément du tableau. 

Ces fonctions retournent une valeur non nulle en cas d'erreur.

L'implantation d'une telle structure de données peut reposer sur un
tableau de valeurs entières dont on conserve la taille. La mémoire
associée au tableau est allouée dynamiquement, réallouée si nécessaire
en fonction des accès en écriture au delà de la taille actuelle.

Dans un premier temps, on pourra utiliser une structure comme

```c
struct ga_s {
    unsigned int ga_size;             /* nombre d'éléments alloués */
    int *ga_elements;                 /* les éléments */
}; 
```

1. Proposez une définition des quatre fonctions.

    Vous travaillerez dans les fichiers `libga.h` et `libga.c` du
    répertoire `tableaux_grandissants/` de votre dépôt git. 

1. Testez votre proposition à l'aide du programme de test se trouvant
   dans le dossier `tableaux_grandissants/` de votre dépôt git,
   à l'aide de la cible `test` du Makefile fourni.

<!-- 
Un mot sur une progression géométrique, par exemple de raison 2, de la
taille de la zone mémoire allouée ? Et aussi de distinguer taille du
ga (max des index écrits) et taille de la zone mémoire ? 
-->

<!-- eof --> 
