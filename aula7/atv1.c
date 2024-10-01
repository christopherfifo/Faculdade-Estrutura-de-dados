#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    int number, *vetor, i;

    printf("Digite quantos números deseja alocar: ");
    scanf("%d", &number);

    vetor = (int*) malloc(number * sizeof(int));
    if (vetor == NULL) {
        perror("Erro ao alocar memória");
        return 1;
    }

    for (i = 0; i < number; i++) {
        do {
            printf("Digite o %dº número: ", i + 1);
            scanf("%d", &vetor[i]);
            if (vetor[i] % 2 == 0) {
                printf("O número digitado não é ímpar. Por favor, digite um número ímpar.\n");
            }
        } while (vetor[i] % 2 == 0 && vetor[i] != 0); 
    }

   
    printf("Números ímpares digitados: ");
    for (i = 0; i < number; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    system("pause");

    return 0;
}