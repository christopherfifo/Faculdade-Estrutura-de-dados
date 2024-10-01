#include <stdio.h>
#include <locale.h>

int fatorialRecursivo(int n);

int fatorialIterativo(int n);

int main() {
    int n, escolha, resultado;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite um valor: ");
    scanf("%d", &n);

    printf("Escolha o método:\n1 - Fatorial Recursivo\n2 - Fatorial Iterativo\n");
    scanf("%d", &escolha);

    switch (escolha) {
    case 1: 
        resultado = fatorialRecursivo(n);
        printf("Resultado usando o fatorial recursivo: %d\n", resultado);
        break;
    case 2:
        resultado = fatorialIterativo(n);
        printf("Resultado usando o fatorial iterativo: %d\n", resultado);
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }

    return 0;
}

int fatorialIterativo(int n) {
    int fatorial = 1;
    for (int i = 1; i <= n; i++) {
        fatorial *= i; 
    }
    return fatorial;
}

int fatorialRecursivo(int n) {
    if (n == 0) {
        return 1; 
    } else {
        return n * fatorialRecursivo(n - 1); 
    }
}