#include <stdio.h>
#include <stdlib.h>

int main() {
    int escolha;

    printf("Escolha uma opcao:\n\n 1- primeira opcao\n 2- segunda opcao\n 3- terceira opcao\n 4- quarta opcao\n\n");
    scanf(" %d", &escolha);

    if (escolha == 1) {
        printf("\nVoce escolheu a primeira opcao: A");
    } else if (escolha == 2) {
        printf("\nVoce escolheu a segunda opcao: B");
    } else if (escolha == 3) {
        printf("\nVoce escolheu a terceira opcao: C");
    } else if (escolha == 4) {
        printf("\nVoce escolheu a quarta opcao: D ");
    } else {
        printf("\nOpcao invalida");
    }

    printf("\n\n");
    system("pause");
    return 0;
    }