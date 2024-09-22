#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>



int main() {
    setlocale(LC_ALL, "Portuguese");
    int pont1;
    int pont2;

    printf("Digite a primeira pontuacao: ");
    scanf(" %d", &pont1);
    printf("Digite a segunda pontuacao: ");
    scanf(" %d", &pont2);

    if(&pont1 > &pont2) {
        printf("endereco de pont1: %p\n", &pont1);
        printf("valor de pont1: %d\n", pont1);
    } else {
        printf("endereco de pont2: %p\n", &pont2);
        printf("valor de pont2: %d\n", pont2);
    }

    system("pause");
    return 0;
}

