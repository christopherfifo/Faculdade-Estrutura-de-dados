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

void criarFuncionario(TRABALHADORES *funcionarios, int tamanho);
void gravarVetor(TRABALHADORES *funcionarios, int tamanho);

int main(){

setlocale(LC_ALL, "Portuguese");
int numeroFuncionarios;

printf("Digite o número de funcionários: ");
scanf(" %d", &numeroFuncionarios);
getchar();

TRABALHADORES funcionarios[numeroFuncionarios];

printf("\nVamos criar o cadastro dos funcionários");

criarFuncionario(funcionarios, numeroFuncionarios);

    return 0;
}

void criarFuncionario(TRABALHADORES *funcionarios, int tamanho){

    setlocale(LC_ALL, "Portuguese");

    for(int i = 0; i < tamanho; i++){

        printf("\n\nDigite o nome do funcionário %d: ", i + 1);
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);
        strtok(funcionarios[i].nome, "\n");

        printf("\nDigite o telefone do funcionário %d: ", i + 1);
        fgets(funcionarios[i].telefone, sizeof(funcionarios[i].telefone), stdin);
        strtok(funcionarios[i].telefone, "\n");

        printf("\nDigite o email do funcionário %d: ", i + 1);
        fgets(funcionarios[i].email, sizeof(funcionarios[i].email), stdin);
        strtok(funcionarios[i].email, "\n");

} 

gravarVetor(funcionarios, tamanho);
}

void gravarVetor(TRABALHADORES *funcionarios, int tamanho){
FILE *arquivo = fopen("funcionarios.bin", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    fwrite(funcionarios, sizeof(TRABALHADORES), tamanho, arquivo);

    fclose(arquivo);
}