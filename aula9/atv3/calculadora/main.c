#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include "calculadora.h"

void exibeMenu() {
    setlocale(LC_ALL,"Portuguese");
    printf("\n=== MENU ===\n");
    printf("1. Soma\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Ver último resultado\n");
    printf("6. Sair\n");
    printf("\n Escolha uma opção: ");
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
                printf("Digite dois números: \n");
                scanf("%f %f", &a, &b);
                resultado = soma(p, a, b);
                printf("\n Resultado: %.2f\n", resultado);
                break;
            case 2: // Subtração
                printf("Digite dois números:\n ");
                scanf("%f %f", &a, &b);
                resultado = subtracao(p, a, b);
                printf("\n Resultado: %.2f\n", resultado);
                break;
            case 3: // Multiplicação
                printf("Digite dois números: \n");
                scanf("%f %f", &a, &b);
                resultado = multiplicacao(p, a, b);
                printf("\n Resultado: %.2f\n", resultado);
                break;
            case 4: // Divisão
                printf("Digite dois números: \n");
                scanf("%f %f", &a, &b);
                resultado = divisao(p, a, b);
                printf("\n Resultado: %.2f\n", resultado);
                break;
            case 5: // Ver último resultado
                printf("\n Último resultado: %.2f\n", ultimoResultado(p));
                break;
            case 6: // Sair
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
        }
    } while(opcao != 6);

    liberaOperacao(p); // Libera a memória
    return 0;
}
