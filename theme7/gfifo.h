#ifndef __GFIFO_H__
#define __GFIFO_H__

struct gfifo_s;
typedef struct gfifo_s *gfifo_t;
typedef void (gfunc_t)(void *, void *);

gfifo_t gfifo_new();
int gfifo_is_empty(gfifo_t);
int gfifo_enqueue(gfifo_t, void *);
int gfifo_dequeue(gfifo_t, void **);
void gfifo_apply(gfifo_t, gfunc_t *);
void gfifo_del(gfifo_t);

#endif /*__GFIFO_H__ */
