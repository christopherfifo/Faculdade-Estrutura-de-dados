#include <stdio.h>


void contagemRegressivaIterativa(int n);


void contagemRegressivaRecursiva(int n);

int main() {
    int n;
    
    printf("Digite um valor para a contagem regressiva: ");
    scanf("%d", &n);
    
    contagemRegressivaIterativa(n);
    
    printf("Contagem Regressiva Recursiva:\n");
    contagemRegressivaRecursiva(n);
    printf("\n");

    return 0;
}

void contagemRegressivaRecursiva(int n) {
    if (n < 0) {
        return;
    }
    printf("%d ", n);
    contagemRegressivaRecursiva(n - 1);
}
void contagemRegressivaIterativa(int n) {
    printf("Contagem Regressiva Iterativa:\n");
    for (int i = n; i >= 0; i--) {
        printf("%d ", i);
    }
    printf("\n");
}