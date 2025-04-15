#include "abs.h"
#ifndef __ABS_H__
#define __ABS_H__
static int abs(int x){return x>0?x:-x;}
#endif /*__ABS_H__H*/
#include "minmax.h"
#ifndef __MINMAX_H__
#define __MINMAX_H__
#include "abs.h"
static int max(int a, int b){return a>b?a:b;}
#endif /*__MINMAX_H__*/


int putchar(int c);

int main() {
    putchar('0' + min(3, 4));
    putchar('0' + max(3, 4));
    putchar('0' + abs(-2));
    return 0;
}
