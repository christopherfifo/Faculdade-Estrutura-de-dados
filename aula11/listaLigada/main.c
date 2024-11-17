#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

int main()
{
    Lista *li = NULL;
    int x, matricula,escolha, quantidade;

    ALUNO al_consulta, al;


    if((li = criaLista()) == NULL){
        abortaPrograma();
    }
while(escolha != 5){
    printf("\nEscolha uma das opcoes:\n\n");
    printf("1 - Ver tamanho da lista\n");
    printf("2 - Incluir um elemento de forma ordenada\n");
    printf("3 - Excluir um elemento de forma ordenada\n");
    printf("4 - Buscar um elemento por conteúdo (matricula)\n");
    printf("5 - Encerrar o programa\n\n");
    printf("Digite a sua escolha: ");
    scanf("%d", &escolha);

    printf("\n\n");

    switch(escolha){

        case 1:
            x = tamanhoLista(li);
            printf("\no tamanho da lista e: %d", x);
        break;

        case 2:
            printf("\nDigite a quantidade de alunos que deseja inserir: ");
            scanf(" %d", &quantidade);

            for(int i = 0; i < quantidade; i++){
                printf("\n");
                al = coletadados();
                x = insereOrdenado(li, al);
                if(x){
                    printf("\nAluno %d inserido ordenado com sucesso!", x);
                }else{
                    printf("\nnao foi possivel inserir ordenado");
                }
            }
        break;

        case 3:
            printf("\nDigite a matricula do aluno que deseja excluir: ");
            scanf("%d", &matricula);

            x = removeOrdenado(li, matricula);
            if(x){
                printf("\nAluno %d removido ordenado com sucesso!", x);
            }else{
                printf("\nnao foi possivel remover ordenado");
            }
        break;

        case 4:
            printf("\n\n");

            printf("Digite a matricula do aluno que deseja buscar: ");
            scanf("%d", &matricula);

            x = consultaMatricula(li, matricula, &al_consulta);
            if(x){
                printf("\nAluno %d consultado pela matricula 110 :", x);
                printf("\nMatricula: %d", al_consulta.matricula);
                printf("\nNota 1: %.2f", al_consulta.n1);
                printf("\nNota 2: %.2f", al_consulta.n2);
                printf("\nNota 3: %.2f", al_consulta.n3);
            }else{
                printf("\nMatricula %d nao existe.", 110);
            }
        break;

        case 5:
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
