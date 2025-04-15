#include <stdio.h>
#include <stdlib.h>
#include "mcu_fatal.h"

int readl(char line[]) {
    int i;
    int c;
    i = 0;

    while ((c = getchar()) != EOF && c != '\n' && i < (MAXLINE)-1) {
      line[i++] = c;
    }
    line[i] = 0;
    if(c == EOF){
      return c;
    }
    else if (c == '\n'){
      return i;
    }
    fatal(0, "Cette ligne a plus de 80 caractères", 2);
    return (LINETOOLONG);
}
