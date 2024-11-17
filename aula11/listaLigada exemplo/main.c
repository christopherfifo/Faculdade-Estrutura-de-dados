#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

int main()
{
    Lista *li = NULL;
    int x = 0, matricula = 120, posicao = 1;

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

    x = insereOrdenado(li, al3);
    if(x){
        printf("\nAluno %d inserido ordenado com sucesso!", x);
    }else{
        printf("\nnao foi possivel inserir ordenado");
    }

    x = removeInicio(li);
    if(x){
        printf("\nAluno %d removido do inicio com sucesso!", x);
    }else{
        printf("\nnao foi possivel remover do inicio");
    }

    x = removeFinal(li);
    if(x){
        printf("\nAluno %d removido do final com sucesso!", x);
    }else{
        printf("\nnao foi possivel remover do final");
    }

    x = removeOrdenado(li, matricula);
    if(x){
        printf("\nAluno %d removido ordenado com sucesso!", x);
    }else{
        printf("\nnao foi possivel remover ordenado");
    }

    /* ################################################# */
    x = insereInicio(li, al1);
    if(x){
        printf("\nAluno %d inserido no inicio com sucesso!", x);
    }else{
        printf("\nnao foi possivel inserir no inicio");
    }
    /* ################################################# */

    printf("\n\n");

    x = tamanhoLista(li);
    printf("o tamanho da lista e: %d", x);

    printf("\n\n");

    x = consultaPosicao(li, posicao, &al_consulta);
    if(x){
        printf("\nAluno %d consultado na posicao %d :", x, posicao);
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1: %.2f", al_consulta.n1);
        printf("\nNota 2: %.2f", al_consulta.n2);
        printf("\nNota 3: %.2f", al_consulta.n3);
    }else{
        printf("\nPosicao %d nao existe.", posicao);
    }

    printf("\n\n");

     /* ################################################# */
    x = consultaPosicao(li, 4, &al_consulta);
    if(x){
        printf("\nAluno %d consultado na posicao %d :", x, posicao);
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1: %.2f", al_consulta.n1);
        printf("\nNota 2: %.2f", al_consulta.n2);
        printf("\nNota 3: %.2f", al_consulta.n3);
    }else{
        printf("\nPosicao %d nao existe.", posicao);
    }
    /* ################################################# */

    printf("\n\n");

    x = consultaMatricula(li, 110, &al_consulta);
    if(x){
        printf("\nAluno %d consultado pela matricula 110 :", x);
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1: %.2f", al_consulta.n1);
        printf("\nNota 2: %.2f", al_consulta.n2);
        printf("\nNota 3: %.2f", al_consulta.n3);
    }else{
        printf("\nMatricula %d nao existe.", 110);
    }

    printf("\n\n");

     /* ################################################# */
    x = consultaMatricula(li, 120, &al_consulta);
    if(x){
        printf("\nAluno %d consultado pela matricula 110 :", x);
        printf("\nMatricula: %d", al_consulta.matricula);
        printf("\nNota 1: %.2f", al_consulta.n1);
        printf("\nNota 2: %.2f", al_consulta.n2);
        printf("\nNota 3: %.2f", al_consulta.n3);
    }else{
        printf("\nMatricula %d nao existe.", 110);
    }
    /* ################################################# */

    printf("\n\n");

    apagaLista(li);
    system("pause");
    printf("\n\n\n");
    return 0;
}
