#include <stdio.h>
#include "env.h"

int main() {
    const char *vars_to_print[] = {"SHELL", "PWD", "USER", NULL};
    int num_vars = nvar();
    printf("Nombre de variables d'environnement : %d\n", num_vars);

    printf("\nToutes les variables d'environnement :\n");
    mprintenv(NULL);

    printf("\nVariables spécifiques d'environnement :\n");
    mprintenv(vars_to_print);

    return 0;
}
