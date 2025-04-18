#include <stdio.h>
#include "mcu_macros.h"
#include "mcu_fatal.h"
#include "mcu_readl.h"
#include "mcu_putint.h"

int main (void)
{
    char line[MAXLINE];
    int i,j;
    /* on affiche une ligne de l'entrée standard */
    i = readl(line);
    for (j=0; j<i; j++)
        putchar(line[j]);
    putchar('\n') ;
    /* on fait un affichage */
    putdec(i) ;
    putchar('\n') ;
    /* on termine par un problème */
    fatal(0==0, "0==0 is true \n", 2) ;
    return 0;
}
