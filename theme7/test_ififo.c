#include <stdlib.h>
#include <stdio.h>
#include "ififo.h"

int print_int(int i) {
    printf("%d←", i);
    return i;
}

int main() {
    ififo_t fifo;
    int i;

    fifo = ififo_new();

    ififo_enqueue(fifo, 12);   /* → 12 → */
    ififo_enqueue(fifo, 13);   /* → 13 → 12 → */

    ififo_apply(fifo, print_int); putchar('\n');

    ififo_enqueue(fifo, 14);   /* → 14 → 13 → 12 → */
    ififo_dequeue(fifo, &i);   /* 12 & → 14 → 13 → */

    printf("%d \n", i);
    ififo_apply(fifo, print_int); putchar('\n');

    ififo_dequeue(fifo, &i);   /* 13 & → 14 → */
    ififo_dequeue(fifo, &i);   /* 14 & → → */
    ififo_apply(fifo, print_int); putchar('\n');

    ififo_del(fifo);
    return 0;
}
