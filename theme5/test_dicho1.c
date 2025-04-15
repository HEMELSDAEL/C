#include <stdio.h>

float * search_interval(float v, float *tab, float *end) {
    // Si le tableau est vide ou si la valeur se situe en dehors de l'intervalle
    if (tab > end || v < *tab || v > *end)
        return NULL;

    // Calcul de la taille du tableau
    size_t size = end - tab + 1;

    // Si le tableau contient un seul élément et que cet élément est différent de la valeur recherchée
    if (size == 1 && *tab != v)
        return NULL;

    // Calcul de l'indice central
    size_t mid_index = size / 2;
    float *mid_value = tab + mid_index;

    // Si la valeur recherchée est la valeur du milieu du tableau
    if (v == *mid_value)
        return mid_value;
    // Si la valeur recherchée est dans la partie de gauche du tableau
    else if (v < *mid_value)
        return search_interval(v, tab, mid_value - 1); // Recherche dans la première moitié
    // Si la valeur recherchée est dans la partie de droite du tableau
    else
        return search_interval(v, mid_value + 1, end); // Recherche dans la deuxième moitié
}

// Le même main que la semaine dernière
int main() {
    float tab[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    int size = sizeof(tab) / sizeof(tab[0]);
    float value = 7.0;

    float *result = search_interval(value, tab, tab + size - 1); // Passing end pointer correctly

    if (result != NULL) {
        printf("La valeur %.1f a été trouvée à l'adresse %p dans le tableau.\n", value, (void*)result);
    } else {
        printf("La valeur %.1f n'a pas été trouvée dans le tableau.\n", value);
    }

    return 0;
}
