// Declaração dos protótipos das funções
void funcao_iterativa(int n);
int funcao_recursiva(int n);

// Implementação da função iterativa
void funcao_iterativa(int n) {
    while (n >= 0) {
        printf("\t %d \n", n);
        n--;  // Decrementa o valor de n
    }
}

// Implementação da função recursiva
int funcao_recursiva(int n) {
    printf("\t %d \n", n);
    if (n == 0) {
        return 0;  // Condição de parada da recursão
    }
    return funcao_recursiva(n - 1);  // Chama a função recursivamente
}
