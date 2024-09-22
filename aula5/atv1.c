#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void salario(float *salario);

int main() {
    float *salario1, *salario2, *salario3;
    float valor1, valor2, valor3;
    setlocale(LC_ALL, "Portuguese");

    printf("\nDigite o valor do primeiro salário: ");
    scanf("%f", &valor1);
    salario1 = &valor1;
    printf("\nDigite o valor do segundo salário: ");
    scanf("%f", &valor2);
    salario2 = &valor2;
    printf("\nDigite o valor do terceiro salário: ");
    scanf("%f", &valor3);
    salario3 = &valor3;

    salario(salario1);
    salario(salario2);
    salario(salario3);

    printf("\nSalário 1: %.2f", *salario1);
    printf("\nSalário 2: %.2f", *salario2);
    printf("\nSalário 3: %.2f", *salario3);

    printf("\n\n");
    system("pause");
    return 0;
}

void salario(float *salario) {
    *salario += 100;
}