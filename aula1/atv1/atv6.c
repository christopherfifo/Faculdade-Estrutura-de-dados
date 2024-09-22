#include <stdio.h>
#include <stdlib.h>

int main() {
    char escolha;
    printf("Quer continuar? [sim - s / nao - n] \n");
    scanf(" %c", &escolha);

    switch (escolha) {
        case 's':
            printf("Voce quer continuar! \n");
            break;
        case 'n':
            printf("Voce quer parar! \n");
            break;
        default:
            printf("Opcao invalida! \n");
            break;
    }

    printf("\n\n\n");
    system("pause");
    return 0;
}