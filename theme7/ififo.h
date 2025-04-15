#ifndef __IFIFO_H__
#define __IFIFO_H__

struct ififo_s;
typedef struct ififo_s *ififo_t;
typedef int (func_t)(int);

ififo_t ififo_new();
int ififo_is_empty(ififo_t);
int ififo_enqueue(ififo_t, int);
int ififo_dequeue(ififo_t, int *);
int ififo_head(const ififo_t);
void ififo_apply(ififo_t, func_t *);
void ififo_del(ififo_t);

#endif /*__IFIFO_H__ */
