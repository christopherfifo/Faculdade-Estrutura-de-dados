#include <stdio.h>
#include <stdlib.h>

int main() {
    int j = 8;

    if (j == 8) {
        j++;
        goto imprime;
    }

    j = 3267;

    imprime:
    printf("Valor de j: %d", j);

    printf("\n\n");
    system("pause");
    return 0;
}