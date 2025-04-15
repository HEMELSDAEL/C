#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "ififo.h"
#include "gfifo.h"
#include "tri_file.h"

ififo_t ififo_merge(ififo_t f1, ififo_t f2) {
    assert(f1 != NULL && f2 != NULL);

    ififo_t result = ififo_new();
    if (result == NULL) {
        return NULL;
    }

    while (ififo_head(f1) != -1 && ififo_head(f2) != -1) {
        if (ififo_head(f1) < ififo_head(f2)) {
            ififo_enqueue(result, ififo_head(f1));
            int dummy;
            ififo_dequeue(f1, &dummy);
        } else {
            ififo_enqueue(result, ififo_head(f2));
            int dummy;
            ififo_dequeue(f2, &dummy);
        }
    }

    while (ififo_head(f1) != -1) {
        ififo_enqueue(result, ififo_head(f1));
        int dummy;
        ififo_dequeue(f1, &dummy);
    }

    while (ififo_head(f2) != -1) {
        ififo_enqueue(result, ififo_head(f2));
        int dummy;
        ififo_dequeue(f2, &dummy);
    }

    return result;
}

ififo_t tri_file(ififo_t fifo) {
    assert(fifo != NULL);

    if (ififo_is_empty(fifo) || ififo_head(fifo) == -1) {
        return fifo;
    }

    while (ififo_head(fifo) != -1) {
        ififo_t f1 = ififo_dequeue(fifo, NULL);
        ififo_t f2 = ififo_dequeue(fifo, NULL);
        ififo_t merged = ififo_merge(f1, f2);
        if (merged == NULL) {
            return NULL;
        }
        ififo_enqueue(fifo, ififo_head(merged));
        ififo_del(merged);
    }

    return fifo;
}
