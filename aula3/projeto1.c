#include <stdio.h>

int main() {
    char nome[50];
    int idade;
    float salario;

    printf("Digite o nome do trabalhador: ");
    fgets(nome, 50, stdin);

    printf("Digite a idade do trabalhador: ");
    scanf("%d", &idade);

    printf("Digite o salário do trabalhador: ");
    scanf("%f", &salario);

    printf("Nome: %sIdade: %d\nSalário: %.2f\n", nome, idade, salario);
    return 0;
}
