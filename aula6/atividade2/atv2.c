#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

typedef struct Criafuncionario{
    char nome[100];
    char telefone[15];
    char email[100];
} Funcionario;

void gravarVetor(Funcionario *funcionarios, int tamanho);

int main (){

    setlocale(LC_ALL, "Portuguese");

    Funcionario funcionarios[5];

    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do funcionário %d: ", i + 1);
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0'; // Remove o \n

        printf("Digite o telefone do funcionário %d: ", i + 1);
        fgets(funcionarios[i].telefone, sizeof(funcionarios[i].telefone), stdin);
        funcionarios[i].telefone[strcspn(funcionarios[i].telefone, "\n")] = '\0'; // Remove o \n

        printf("Digite o email do funcionário %d: ", i + 1);
        fgets(funcionarios[i].email, sizeof(funcionarios[i].email), stdin);
        funcionarios[i].email[strcspn(funcionarios[i].email, "\n")] = '\0'; // Remove o \n
    }

    gravarVetor(funcionarios, 5);
}

void gravarVetor(Funcionario *funcionarios, int tamanho) {
    FILE *arquivo = fopen("funcionarios.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    fwrite(funcionarios, sizeof(Funcionario), tamanho, arquivo);

    fclose(arquivo);
}