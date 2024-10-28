#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Funções
void criaMatriz(int ***matriz, int linhas, int colunas);
void exibeMatriz(int **matriz, int linhas, int colunas);
void somaMatriz(int **matriz1, int **matriz2, int **matrizSoma, int linhas, int colunas);
void limpaMatriz(int **matriz, int linhas);

int main() {
    setlocale(LC_ALL, "Portuguese");

    int **matriz, **matriz2, **matrizSoma, linhas, colunas;

    printf("\nSeja bem-vindo ao programa de soma de matrizes\n");

    printf("Digite o número de linhas da primeira matriz: ");
    scanf("%d", &linhas);

    printf("\nDigite o número de colunas da primeira matriz: ");
    scanf("%d", &colunas);

    // Criando as matrizes
    criaMatriz(&matriz, linhas, colunas);
    criaMatriz(&matriz2, linhas, colunas);
    criaMatriz(&matrizSoma, linhas, colunas);

    // Preenchendo a primeira matriz
    printf("\nDigite os valores da primeira matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Preenchendo a segunda matriz
    printf("\nDigite os valores da segunda matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }

    // Exibindo a primeira matriz
    printf("\nMatriz 1:\n");
    exibeMatriz(matriz, linhas, colunas);

    // Exibindo a segunda matriz
    printf("\nMatriz 2:\n");
    exibeMatriz(matriz2, linhas, colunas);

    // Somando as matrizes
    somaMatriz(matriz, matriz2, matrizSoma, linhas, colunas);

    // Exibindo a matriz soma
    printf("\nMatriz Soma:\n");
    exibeMatriz(matrizSoma, linhas, colunas);

    // Liberando a memória
    limpaMatriz(matriz, linhas);
    limpaMatriz(matriz2, linhas);
    limpaMatriz(matrizSoma, linhas);

    return 0;
}

// Função para criar a matriz (usando ponteiro para ponteiro)
void criaMatriz(int ***matriz, int linhas, int colunas) {
    *matriz = (int **)malloc(linhas * sizeof(int *));  // Aloca as linhas
    for (int i = 0; i < linhas; i++) {
        (*matriz)[i] = (int *)malloc(colunas * sizeof(int));  // Aloca as colunas
    }
}

// Função para exibir a matriz
void exibeMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para somar as matrizes
void somaMatriz(int **matriz1, int **matriz2, int **matrizSoma, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizSoma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

// Função para liberar a memória da matriz
void limpaMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);  // Libera cada linha
    }
    free(matriz);  // Libera o array de ponteiros
}
