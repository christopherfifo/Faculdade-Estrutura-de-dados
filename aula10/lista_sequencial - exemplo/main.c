#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaSequencial.h"

int main()
{
    int x, mat = 110, posicao = 1;

    struct aluno al, al2,al3, dados_aluno;

    Lista *li;

    li = cria_Lista();


// Dados para o primeiro aluno
al.matricula = 100;
al.n1 = 5.3;
al.n2 = 6.9;
al.n3 = 7.4;

// Dados para o segundo aluno
al2.matricula = 120;
al2.n1 = 4.0;
al2.n2 = 2.9;
al2.n3 = 8.4;

// Dados para o terceiro aluno
al3.matricula = 110;
al3.n1 = 1.3;
al3.n2 = 2.9;
al3.n3 = 3.4;


    x = tamanho_lista(li);

    printf("tamanho da lista: %d", x);

    x = lista_cheia(li);

    if(x){
        printf("lista esta cheia");
    }else{
    printf("lista nao ta cheia");
    }


    x = lista_vazia(li);

    if(x){
        printf("lista esta vazia");
    }else{
    printf("lista nao ta vazia");
    }

    x = insere_lista_final(li, al2);

    if(x) {
        printf("\n aluno inserido com sucesso:");
    } else {
    printf("\n erro ao inserir o aluno");
    }

    x = insere_lista_inicio(li, al3);
    if(x) {
        printf("\n aluno inserido com sucesso:");
    } else {
    printf("\n erro ao inserir o aluno");
    }

    x = insere_lista_ordenada(li, al);
    if(x) {
        printf("\n aluno inserido com sucesso:");
    } else {
    printf("\n erro ao inserir o aluno");
    }

    x = remove_lista_final(li);
    if(x) {
        printf("\n aluno removido com sucesso:");
    } else {
    printf("\n erro ao remover o aluno");
    }

    x = remove_lista_inicio(li);
    if(x) {
        printf("\n aluno removido com sucesso:");
    } else {
    printf("\n erro ao remover o aluno");
    }

    x = remove_lista(li, mat);
    if(x) {
        printf("\n aluno removido com sucesso:");
    } else {
    printf("\n erro ao remover o aluno");
    }


    x = insere_lista_final(li, al3);

    if(x) {
        printf("\n aluno inserido com sucesso:");
    } else {
    printf("\n erro ao inserir o aluno");
    }


    x = consulta_lista_pos(li, posicao, &dados_aluno);
    if(x) {
        printf("\n aluno encontrado com sucesso:");
        printf("\n matricula: %d", dados_aluno.matricula);
        printf("\n nota 1: %.2f", dados_aluno.n1);
        printf("\n nota 2: %.2f", dados_aluno.n2);
        printf("\n nota 3: %.2f", dados_aluno.n3);
    } else {
    printf("\n erro ao encontrar o aluno");
    }

    x = consulta_lista_mat(li, mat, &dados_aluno);
    if(x) {
        printf("\n aluno encontrado com sucesso:");
        printf("\n matricula: %d", dados_aluno.matricula);
        printf("\n nota 1: %.2f", dados_aluno.n1);
        printf("\n nota 2: %.2f", dados_aluno.n2);
        printf("\n nota 3: %.2f", dados_aluno.n3);
    } else {
    printf("\n erro ao encontrar o aluno");
    }

    libera_lista(li);
    return 0;
}
