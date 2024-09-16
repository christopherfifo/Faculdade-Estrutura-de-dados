#include <stdio.h>
#include <string.h>

int main() {
    char nome[30], sobrenome1[30], sobrenome2[30], nome_completo[90];

    printf("Digite o nome: ");
    scanf("%s", nome);

    printf("Digite o primeiro sobrenome: ");
    scanf("%s", sobrenome1);

    printf("Digite o segundo sobrenome: ");
    scanf("%s", sobrenome2);

    // Concatena as strings
    strcpy(nome_completo, nome);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenome1);
    strcat(nome_completo, " ");
    strcat(nome_completo, sobrenome2);

    printf("Nome completo: %s\n", nome_completo);
    return 0;
}
