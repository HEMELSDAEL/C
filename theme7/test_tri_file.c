#include <stdio.h>
#include "tri_file.h"

int print_int(int i) {
    printf("%d←", i);
    return i;
}

int main() {
    ififo_t file;
    ififo_t file_triee;
    int nb;

    file = ififo_new();
    while (scanf("%d\n", &nb) == 1) ififo_enqueue(file, nb);
    ififo_apply(file, print_int);
    putchar('\n');
    
    file_triee = tri_file(file);
    ififo_del(file);
    ififo_apply(file_triee, print_int);
    putchar('\n');
    ififo_del(file_triee);

    return 0;
}
