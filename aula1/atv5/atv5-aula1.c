#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrx[5][5], v[10];
    int i = 0,j = 0, soma = 0;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("Digite os valores da matriz nas posicao: %d e %d ", i, j);
            scanf(" %d", &matrx[i][j]);
        }
    }

    printf("\n\nTotal por linha da matriz:\n\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            soma = soma + matrx[i][j];
        }
        printf("\nLinha %d : soma = %d\n", i +1, soma);
        v[i] = soma;
        soma = 0;
    }

    soma = 0;

    printf("\n\nTotal por coluna da matriz:\n\n");
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 5; i++) {
            soma = soma + matrx[i][j];
        }
        printf("\nColuna %d : soma = %d\n", j +1, soma);
        v[j + 5] = soma;
        soma = 0;
    }

    printf("\n\nVetor com as somas das linhas e colunas:\n\n");
    for (i = 0; i < 5; i++) {
        printf("\nOs valores da soma da linha %d sao: %d\n",  i + 1, v[i]);
        printf("\nOs valores da soma da coluna %d sao: %d\n",  i + 1, v[i + 5]);
    }

    printf("\n\nMatriz:\n\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf(" %d ", matrx[i][j]);
        }
        printf("\n");
    }

    printf("\nVetor:\n\n");
    for( i = 0; i < 10; i++){
        printf("%d ", v[i]);
    }

    printf("\n\n");
    system("pause");
    return 0;
    }//t