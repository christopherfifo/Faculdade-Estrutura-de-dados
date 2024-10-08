#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"  // Inclusão da biblioteca criada

int main() {
    int n;
    printf("Entre com um numero inteiro: ");
    scanf("%d", &n);

    printf("Versao iterativa:\n");
    funcao_iterativa(n);  // Chamada da função iterativa
    printf("\n\n");

    printf("Versao recursiva:\n");
    funcao_recursiva(n);  // Chamada da função recursiva
    printf("\n\n\n");

    system("pause");  // Pausa para visualizar o resultado
    return 0;
}
