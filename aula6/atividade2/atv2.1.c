#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    char telefone[15];
    char email[100];
} Funcionario;

int main() {
    FILE *arquivo = fopen("funcionarios.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    Funcionario terceiroFuncionario;

    fseek(arquivo, 2 * sizeof(Funcionario), SEEK_SET);

    fread(&terceiroFuncionario, sizeof(Funcionario), 1, arquivo);
    fclose(arquivo);

    printf("Terceiro Funcionário:\n");
    printf("Nome: %s\n", terceiroFuncionario.nome);
    printf("Telefone: %s\n", terceiroFuncionario.telefone);
    printf("Email: %s\n", terceiroFuncionario.email);

    return 0;
}