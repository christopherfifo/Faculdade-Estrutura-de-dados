#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "calculadora.h"

void exibeMenu() {
    setlocale(LC_ALL,"Portuguese");
    printf("\n=== MENU ===\n");
    printf("1. Soma\n");
    printf("2. Subtra��o\n");
    printf("3. Multiplica��o\n");
    printf("4. Divis�o\n");
    printf("5. Ver �ltimo resultado\n");
    printf("6. Sair\n");
    printf("\n Escolha uma op��o: ");
}

int main() {
    setlocale(LC_ALL,"Portuguese");
    resu *p = criaOperacao(); // Cria o TAD
    int opcao;
    float a, b, resultado;

    do {
        exibeMenu();
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: // Soma
                printf("Digite dois n�meros: \n");
                scanf("%f %f", &a, &b);
                resultado = soma(p, a, b);
                printf("\n Resultado: %.2f\n", resultado);
                break;
            case 2: // Subtra��o
                printf("Digite dois n�meros:\n ");
                scanf("%f %f", &a, &b);
                resultado = subtracao(p, a, b);
                printf("\n Resultado: %.2f\n", resultado);
                break;
            case 3: // Multiplica��o
                printf("Digite dois n�meros: \n");
                scanf("%f %f", &a, &b);
                resultado = multiplicacao(p, a, b);
                printf("\n Resultado: %.2f\n", resultado);
                break;
            case 4: // Divis�o
                printf("Digite dois n�meros: \n");
                scanf("%f %f", &a, &b);
                resultado = divisao(p, a, b);
                printf("\n Resultado: %.2f\n", resultado);
                break;
            case 5: // Ver �ltimo resultado
                printf("\n �ltimo resultado: %.2f\n", ultimoResultado(p));
                break;
            case 6: // Sair
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOp��o inv�lida!\n");
        }
    } while(opcao != 6);

    liberaOperacao(p); // Libera a mem�ria
    return 0;
}
