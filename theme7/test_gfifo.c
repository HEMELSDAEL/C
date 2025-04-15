#include <stdlib.h>
#include <stdio.h>
#include "gfifo.h"

void print_string(void *data) {
    printf("%s←", (char *)data);
}

int main() {

    struct gfifo_s *fifo = gfifo_new();
    if (fifo == NULL) {
        fprintf(stderr, "Erreur lors de la création de la file générique\n");
        return EXIT_FAILURE;
    }


    gfifo_enqueue(fifo, "Premier");
    gfifo_enqueue(fifo, "Deuxième");
    gfifo_enqueue(fifo, "Troisième");


    printf("Contenu de la file : ");
    gfifo_apply(fifo, print_string);
    putchar('\n');


    void *removed_data;
    gfifo_dequeue(fifo, &removed_data);
    gfifo_dequeue(fifo, &removed_data);

 
    printf("Contenu de la file après suppression : ");
    gfifo_apply(fifo, print_string);
    putchar('\n');


    gfifo_del(fifo);

    return EXIT_SUCCESS;
}
