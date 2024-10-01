#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(int linhas, int colunas);
void lerMatriz(int** matriz, int linhas, int colunas);
int** somarMatrizes(int** matriz1, int** matriz2, int linhas, int colunas);
void imprimirMatriz(int** matriz, int linhas, int colunas);
void liberarMatriz(int** matriz, int linhas);

int main() {
    int linhas, colunas, i;
    int **matriz1, **matriz2, **matrizSoma;

    printf("\nDigite o numero de linhas: ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);

    matriz1 = alocarMatriz(linhas, colunas);
    printf("\nDigite os valores da primeira matriz:\n");
    lerMatriz(matriz1, linhas, colunas);

    matriz2 = alocarMatriz(linhas, colunas);
    printf("Digite os valores da segunda matriz:\n");
    lerMatriz(matriz2, linhas, colunas);

    matrizSoma = somarMatrizes(matriz1, matriz2, linhas, colunas);

    printf("\nMatriz soma:\n");
    imprimirMatriz(matrizSoma, linhas, colunas);

    liberarMatriz(matriz1, linhas);
    liberarMatriz(matriz2, linhas);
    liberarMatriz(matrizSoma, linhas);

    system("pause");

    return 0;
}

int** alocarMatriz(int linhas, int colunas) {
    int **matriz = (int**) malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
    }
    return matriz;
}

void lerMatriz(int** matriz, int linhas, int colunas) {
    printf("\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("\n");
}

int** somarMatrizes(int** matriz1, int** matriz2, int linhas, int colunas) {
    int **matrizSoma = alocarMatriz(linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizSoma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return matrizSoma;
}

void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void liberarMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
