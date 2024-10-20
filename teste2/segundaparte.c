#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>


typedef struct criafunc{
    char nome[100];
    char telefone[15];
    char email[100];
} TRABALHADORES;

int main(){

setlocale(LC_ALL, "Portuguese");

FILE *arquivo = fopen("funcionarios.bin", "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    TRABALHADORES terceiroFuncionario;

fseek(arquivo, 2 * sizeof(TRABALHADORES), SEEK_SET);
fread(&terceiroFuncionario, sizeof(TRABALHADORES), 1, arquivo);

fclose(arquivo);

printf("Terceiro Funcionário:\n");
printf("Nome: %s\n", terceiroFuncionario.nome);
printf("Telefone: %s\n", terceiroFuncionario.telefone);
printf("Email: %s\n", terceiroFuncionario.email);

    return 0; 
}