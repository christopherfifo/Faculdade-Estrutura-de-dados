#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    float vetorFloat[10];
    double vetorDouble[10];


    printf("Endereços do vetor de float:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posição %d: %p\n", i, &vetorFloat[i]);
    }

    printf("\nEndereços do vetor de double:\n");
    for (int i = 0; i < 10; i++) {
        printf("Posição %d: %p\n", i, &vetorDouble[i]);
    }

    system("pause");
    return 0;
}
