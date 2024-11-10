#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaSequencial.h"

int main() {
    int x, mat, posicao, escolha, quantidade;
    struct aluno al, al2, al3, dados_aluno, inserir;
    Lista *li;

    li = cria_Lista();

    // Dados para o primeiro aluno
    al.matricula = 1;
    al.n1 = 5.3;
    al.n2 = 6.9;
    al.n3 = 7.4;

    // Dados para o segundo aluno
    al2.matricula = 2;
    al2.n1 = 4.0;
    al2.n2 = 2.9;
    al2.n3 = 8.4;

    // Dados para o terceiro aluno
    al3.matricula = 3;
    al3.n1 = 1.3;
    al3.n2 = 2.9;
    al3.n3 = 3.4;

    // Inserir os alunos na lista
    insere_lista_final(li, al);
    insere_lista_final(li, al2);
    insere_lista_final(li, al3);

    do {
        printf("\n\n Escolha uma opcao: \n\n");
        printf("1 - Inserir novos alunos\n");
        printf("2 - Tamanho da lista\n");
        printf("3 - Remover do final da lista\n");
        printf("4 - Remover do inicio da lista\n");
        printf("5 - Remover aluno da lista\n");
        printf("6 - Consultar aluno pela posicao\n");
        printf("7 - Consultar aluno pela matricula\n");
        printf("8 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("\n\nDigite a quantidade de alunos a serem inseridos:");
                scanf("%d", &quantidade);

                for (int i = 0; i < quantidade; i++) {
                    inserir = inserir_novos_alunos();
                    x = insere_lista_ordenada(li, inserir);
                    if (x) {
                        printf("\n aluno inserido com sucesso:");
                    } else {
                        printf("\n erro ao inserir o aluno");
                    }
                }
                break;

            case 2:
                x = tamanho_lista(li);
                printf("tamanho da lista: %d", x);
                break;

            case 3:
                x = remove_lista_final(li);
                if (x) {
                    printf("\n aluno removido com sucesso:");
                } else {
                    printf("\n erro ao remover o aluno");
                }
                break;

            case 4:
                x = remove_lista_inicio(li);
                if (x) {
                    printf("\n aluno removido com sucesso:");
                } else {
                    printf("\n erro ao remover o aluno");
                }
                break;

            case 5:
                printf("\n\ndigite a matricula do aluno a ser removido:");
                scanf("%d", &mat);

                x = remove_lista(li, mat);
                if (x) {
                    printf("\n aluno removido com sucesso:");
                } else {
                    printf("\n erro ao remover o aluno");
                }
                break;

            case 6:
                printf("\n\ndigite a posicao do aluno a ser consultado:");
                scanf("%d", &posicao);

                x = consulta_lista_pos(li, posicao, &dados_aluno);
                if (x) {
                    printf("\n aluno encontrado com sucesso:");
                    printf("\n matricula: %d", dados_aluno.matricula);
                    printf("\n nota 1: %.2f", dados_aluno.n1);
                    printf("\n nota 2: %.2f", dados_aluno.n2);
                    printf("\n nota 3: %.2f", dados_aluno.n3);
                } else {
                    printf("\n erro ao encontrar o aluno");
                }
                break;

            case 7:
                printf("\n\ndigite a matricula do aluno a ser consultado:");
                scanf("%d", &mat);

                x = consulta_lista_mat(li, mat, &dados_aluno);
                if (x) {
                    printf("\n aluno encontrado com sucesso:");
                    printf("\n matricula: %d", dados_aluno.matricula);
                    printf("\n nota 1: %.2f", dados_aluno.n1);
                    printf("\n nota 2: %.2f", dados_aluno.n2);
                    printf("\n nota 3: %.2f", dados_aluno.n3);
                } else {
                    printf("\n erro ao encontrar o aluno");
                }
                break;

            case 8:
                printf("\nSaindo...\n");
                break;

            default:
                printf("opcao invalida");
                break;
        }
    } while (escolha != 8);

    free(li);

    printf("\n\n");
    system("pause");
    return 0;
}