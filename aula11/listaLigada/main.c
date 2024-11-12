#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

int main()
{
    Lista *li = NULL;
    int x = 0, matricula = 120, posicao = 2;

    ALUNO al_consulta, al1,al2,al3;

        // Dados para o primeiro aluno
    al1.matricula = 110;
    al1.n1 = 5.3;
    al1.n2 = 6.9;
    al1.n3 = 7.4;

    // Dados para o segundo aluno
    al2.matricula = 120;
    al2.n1 = 4.0;
    al2.n2 = 2.9;
    al2.n3 = 8.4;

    // Dados para o terceiro aluno
    al3.matricula = 130;
    al3.n1 = 1.3;
    al3.n2 = 2.9;
    al3.n3 = 3.4;

    if((li = criaLista()) == NULL){
        abortaPrograma();
    }

    x = tamanhoLista(li);
    printf("o tamanho da lista e: %d", x);

    if(listaCheia(li)){
        printf("\nLista esta cheia!");
    }else{
        printf("\nLista nao esta cheia.");
    }

    if(listaVazia(li)){
        printf("\nLista esta vazia!");
    }else{
        printf("\nLista nao esta vazia.");
    }

    x = insereInicio(li, al1);
    if(x){
        printf("\nAluno %d inserido no inicio com sucesso!", x);
    }else{
        printf("\nnao foi possivel inserir no inicio");
    }

    x = insereFinal(li, al2);
    if(x){
        printf("\nAluno %d inserido no final com sucesso!", x);
    }else{
        printf("\nnao foi possivel inserir no final");
    }

    apagaLista(li);
    return 0;
}
