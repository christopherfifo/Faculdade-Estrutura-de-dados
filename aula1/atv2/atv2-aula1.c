#include <stdio.h>
#include <stdlib.h>

int main() {
    int escolha;

    printf("Escolha uma opcao:\n\n 1- primeira opcao\n 2- segunda opcao\n 3- terceira opcao\n 4- quarta opcao\n\n");
    scanf(" %d", &escolha);

    switch (escolha) {
        case 1:
            printf("\nVoce escolheu a primeira opcao: A ");
            break;
        case 2:
            printf("\nVoce escolheu a segunda opcao: B ");
            break;
        case 3:
            printf("\nVoce escolheu a terceira opcao: C ");
            break;
        case 4:
            printf("\nVoce escolheu a quarta opcao: D ");
            break;
        default:
            printf("\nOpcao invalida");
            break;
    }  

    printf("\n\n");
    system("pause");
    return 0;
}