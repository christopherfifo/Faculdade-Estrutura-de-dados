#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "acme.h"

int main()
{
    Lista *li = NULL;
    int x, identificador,escolha, quantidade;
    char nome[80];

    CLIENTE al_consulta, al;


    if((li = criaLista()) == NULL){
        abortaPrograma();
    }

    FILE *arquivo = NULL;
    
    arquivo = abriArquivo(li);

while(escolha != 7){
    printf("\nEscolha uma das opcoes:\n\n");
    printf("1 - Incluir um novo contato\n");
    printf("2 - Relatorio de todos os contatos\n");
    printf("3 - Buscar contato pelo identificador\n");
    printf("4 - Buscar contatos pelo nome\n");
    printf("5 - Editar as informacoes de um contato\n");
    printf("6 - Excluir um contato com base no identificador\n");
    printf("7 - Sair\n\n");
    printf("Digite a sua escolha: ");
    scanf("%d", &escolha);

    printf("\n\n");

    switch(escolha){

        case 1:
            printf("\nDigite a quantidade de contatos que deseja inserir: ");
            scanf(" %d", &quantidade);

            for(int i = 0; i < quantidade; i++){
                printf("\n");
                al = coletadados(li);
                x = insereOrdenado(li, al);
                if(x){
                    printf("\nAluno %d inserido ordenado com sucesso!", x);
                }else{
                    printf("\nnao foi possivel inserir ordenado");
                }
            }
        break;

        case 2:

        break;

        case 3:
            printf("\n\n");

            printf("Digite a identificador do aluno que deseja buscar: ");
            scanf("%d", &identificador);

            x = consultaIdentificador(li, identificador, &al_consulta);
            if(x){
                printf("\n\n");
                relatorio(&al_consulta);
            }else{
                printf("\nidentificador %d nao existe.", 110);
            }
        break;

        case 4:
            printf("\n\n");

            printf("Digite o nome do aluno que deseja buscar: ");
            fgets(nome, sizeof(nome), stdin);

            if (strlen(nome) > 0 && nome[strlen(nome) - 1] == '\n') {
                nome[strlen(nome) - 1] = '\0';
            }

            consultaNome(li, nome);

        break;

        case 5:

        break;

        case 6:
             printf("\nDigite a identificador do aluno que deseja excluir: ");
            scanf("%d", &identificador);

            x = removeOrdenado(li, identificador);
            if(x){
                printf("\nAluno %d removido ordenado com sucesso!", x);
            }else{
                printf("\nnao foi possivel remover ordenado");
            }
        break;

        case 7:
            printf("\n\n");
            printf("Fim do programa");
        break;

        default:
            printf("\n\n");
            printf("Opcao invalida");
        break;
    }

}

    printf("\n\n");

    apagaLista(li);
    system("pause");
    printf("\n\n\n");
    return 0;
}
