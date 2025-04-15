_thème 4_ — Références et pointeurs
=================================

> [Université de Lille](https://www.univ-lille.fr/)  
> [Licence d'informatique, 2e année](https://portail.fil.univ-lille.fr/ls2)  
> [Module de MPC — Maîtrise de la Programmation en C](https://portail.fil.univ-lille.fr/ls2/mpc)  
> Équipe pédagogique de MPC, d'après un document CC BY-SA de Gilles
    Grimaud Philippe Marquet, 2018-2020.  
> mars 2024
> [CC BY-SA](https://creativecommons.org/licenses/by-sa/4.0/)


Le thème 4 traite des références et pointeurs en C, des opérateurs
de référence `&`, et `*` de déréférencement. (L'arithmétique des
pointeurs n'est pas abordée ici, elle fera l'objet de futurs thèmes).

Vous **devez** écrire un fichier `Makefile` pour créer les exécutables
demandés.

### Échanger deux variables

À faire dans `swap.c`.

1. Réalisez une fonction `swap_int()` pour échanger les valeurs de
   deux variables entières. 

2. Réalisez un programme principal qui
   * lit deux valeurs entières à l'aide d'appels à la fonction
     `scanf()` de la bibliothèque C standard, dans deux variables
     entières, 
   * échange les valeurs de ces variables,
   * affiche les nouvelles valeurs des variables avec `printf()`

    On consultera éventuellement la page de manuel de la fonction
    `scanf()` : `man scanf`.

3. Soumettez  avec `git` ce fichier `swap.c` et le fichier `Makefile`.

### Division

À faire dans `division.c`.

Une fonction C ne permet de renvoyer qu'une unique valeur via le `return`.  
Une fonction peut néanmoins accepter des paramètres qui soient des
références et ainsi "renvoyer" plusieurs valeurs résultats. 

4. Réalisez une fonction `division()` qui prend en argument un
   diviseur et un dividende (entiers), qui calcule le quotient et le reste.

    Cette fonction `division()` recevra également des références sur
    des entiers  qui recueilleront le quotient et le
    reste. 

5. Réalisez un programme principal qui appelle cette fonction avec les
   valeurs de votre choix, et testez ses résultats avec `putdec()` ou `printf()`.

6. Soumettez `division.c` et les modifications de `Makefile`.

### Arguments de `main()`

À faire dans un fichier `args_main.c` **qui n'est pas à rendre**.

Le prototype de la fonction `main()` d'un programme C est le suivant :

```c
int main (int argc, char *argv[]);
```

Les paramètres `argc` et `argv` permettent de récupérer les arguments
de la ligne de commande.

* `argc` correspond au nombre d'arguments +1
* `argv[0]` est une chaîne de caractères correspondant au nom de la
  commande. Autrement dit, c'est une référence sur le 1er caractère de
  cette chaîne de caractères. 
* de manière plus générale, `char *argv[]` est un tableau de références
  vers des caractères. Autrement dit, un tableau de chaînes de
  caractères.

  Chacune de ces chaînes de caractères correspond à un argument de la
  ligne de commande. 

7. Expliquez, compilez et exécutez le programme suivant :

    ```c
    /* Ma commande echo */
    
    #include <stdio.h>
    #include <stdlib.h>
    
    int
    main (int argc, char *argv[])
    {
        int i; 
    
        for(i = 1; i < argc ; i++) {
            printf("%s ", argv[i]); 
        } 
        putchar('\n');
    
        exit(EXIT_SUCCESS); 
    }
    ```
#### Explication de la question 7:
Le programme va parcourir tout le tableau entré par l'utilisateur à partir de argv[1] car argv[0] est le nom de la commande afin de l'afficher et une fois le tableau fini on sort du programme

### Sauter les espaces

À faire dans `skip_spaces.c` et `README.md`

8. Réalisez une fonction `skip_spaces()` qui accepte une chaîne de
   caractères `s`, et qui renvoie une référence sur le premier élement
   du tableau qui n'est pas une espace (si la chaîne est entièrement
   constituée d'espaces, on renverra un pointeur sur le caractère zéro
   terminal). 

Soit le programme principal suivant utilisant cette fonction
`skip_spaces()` compilé en un exécutable `strip_spaces_tst` : 

```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int
main(int argc, char *argv[])
{
    char * strip;
    int i; 
    assert(argc == 2);

    printf("argv  : %s\n", argv[1]);
    strip = skip_spaces(argv[1]);
    printf("strip : %s\n", strip);

    for (i=0 ; strip[i]; i++)
        strip[i] = toupper(strip[i]);

    printf("strip : %s\n", strip);
    printf("argv  : %s\n", argv[1]);
    
    exit(EXIT_SUCCESS);
}
```

9. Quels sont les résultats attendus des exécutions suivantes du
   programme : 

    ```console
    % ./strip_spaces_tst "FOO BAR"
    % ./strip_spaces_tst "       FOO BAR"
    % ./strip_spaces_tst "Foo Bar"
    % ./strip_spaces_tst "       Foo Bar"
    ```

    Expliquez ces résultats.

    ### Explications des résultats : 
    * 1- "FOO BAR" : Comme il n'y a pas d'espaces dans la chaine la sortie sera également "FOO BAR". On convertit chaque caractère de la la chaine en majuscule donc ça donnera toujours "FOO BAR"
    * 2- "       FOO BAR" : La chaine commence par des espaces donc les espaces seront supprimés et c'est tout car toutes les lettres sont déjà en majuscules.
    * 3- "Foo Bar" : La chaine ne commence pas par des espaces donc ça ne changera rien là dessus par contre les lettres minuscules seront transformées en lettres majuscules
    * 4- "       Foo Bar" : La chaine commence par des espaces donc ils seront supprimés et les lettres minuscules seront transformées en majuscules

10. Soumettez `skip_spaces.c` et les modifications de `README.md`

### Échanger deux pointeurs

À faire dans `swap_ptr.h` (question 11) et `swap_ptr.c`.

11. Quel est le prototype d'une fonction qui réalise l'échange de
   valeurs de deux pointeurs de type `int *` ?

12. Réaliser une fonction `swap_ptr()` qui échange les valeurs de deux
   pointeurs de type `int*`. 

13. Vous pourrez utiliser le code suivant pour tester votre fonction :

    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #include "swap_ptr.h"
    
    int
    main_swap_ptr() {
        
        int a, b;
        int *p = &a;
        int *q = &b;
        
        swap_ptr(&p, &q);
        
        if ((p == &b) && (q == &a)) {
            printf("OK ;)\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("KO ;(\n");
            exit(EXIT_FAILURE);
        }
    }
    ```

14. Soumettez les fichiers `swap_ptr.h`, `swap_ptr.c` et les modifications
    du `Makefile`

### Recherche dichotomique

À faire dans `dicho.c`.

15. Proposez une fonction récursive qui recherche par dichotomie une
  valeur `v` dans un tableau trié `tab` de `size` éléments : 

    ```c
    float * search_dicho_rec(float v, float *tab, int size);
    ```

16. Proposez une fonction impérative qui recherche par dichotomie
    une valeur `c` dans un tableau trié `tab` de `size` éléments :

    ```c
    float * search_dicho_imp(float v, float *tab, int size);
    ```

17. Proposez une fonction `main()` pour tester ces fonctions
    de recherche dichotomique.

18. Soumettez `dicho.c` et les modifications du `Makefile`.

<!-- eof --> 


