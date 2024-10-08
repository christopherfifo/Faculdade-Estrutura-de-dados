
#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"


void funcao_iterativa(int n) {
    while (n >= 0) {
        printf("\t %d \n", n);
        n--;
    }
}


int funcao_recursiva(int n) {
    printf("\t %d \n", n);
    if (n == 0) {
        return 0;
    }
    return funcao_recursiva(n - 1);
}
