#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    printf("Informe dois numeros: \n");
    scanf(" %d", &a);

    b = (a > 10)? 1 : 0;

    printf("O valor de b e: %d \n\n\n", b);

    system("pause");
    return 0;
}