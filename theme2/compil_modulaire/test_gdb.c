#include <stdio.h>
void foo(int s){
  printf("foo() appelle avec : %d\n", s);
}

void bar(int s){
  printf("bar() appelle avec %d\n", s);
}

int main(){
  int tab[10] = {1, 5, 8, 3, 1, 9, 10, 25, 32, 42};
  int i;
  int sum = 0;
  for(i = 0; i<=10; i++){
    sum = sum + tab[i];
  }
  foo(sum);
  bar(sum);
  return 0;
}

/*Condition de la boucle for incorrecte ça devrait être i<10*/
/*Exercice 26 : On observe que i = 11 car 1 + 10 = 11. Ce qui en fait un indice du tableau non valide */
