#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"

int main() {

    int x, matricula = 100, pos = 3;

    ALUNO al_consulta, al1, al2, al3;

    al1.matricula = 100;
    al1.n1 = 8.3;
    al1.n2 = 8.4;
    al1.n3 = 8.5;

    al2.matricula = 110;
    al2.n1 = 7.3;
    al2.n2 = 7.4;
    al2.n3 = 7.5;

    al3.matricula = 120;
    al3.n1 = 6.3;
    al3.n2 = 6.4;
    al3.n3 = 6.5;

    Lista* li;

    li = criar_lista();

    x = tamanhoLista(li);
    printf("Tamanho da lista: %d\n\n", x);

    x = listaCheia(li);
    if (x){
        printf("Lista cheia\n\n");
    } else {
        printf("Lista nao esta cheia\n\n");
    }

    x = listaVazia(li);
    if (x){
        printf("Lista vazia\n\n");
    } else {
        printf("Lista nao esta vazia\n\n");
    }

    x = insereInicio(li, al1);
    if (x){
        printf("Insercao no inicio do aluno %d realizada com sucesso\n\n", x);
    } else {
        printf("Insercao no inicio nao realizada\n\n");
    }

    x = insereFinal(li, al3);
    if (x){
        printf("Insercao no final do aluno %d realizada com sucesso\n\n", x);
    } else {
        printf("Insercao no final nao realizada\n\n");
    }

    x = insereOrdenado(li, al2);
    if (x){
        printf("Insercao ordenada do aluno %d realizada com sucesso\n\n", x);
    } else {
        printf("Insercao ordenada nao realizada\n\n");
    }

    x = removeInicio(li);
    if (x){
        printf("Remocao do inicio do aluno %d realizada com sucesso\n\n", x);
    } else {
        printf("Remocao do inicio nao realizada\n\n");
    }

    x = removeFinal(li);
    if (x){
        printf("Remocao do final do aluno %d realizada com sucesso\n\n", x);
    } else {
        printf("Remocao do final nao realizada\n\n");
    }

                x = insereInicio(li, al1);
                if (x){
                    printf("Insercao no inicio do aluno %d realizada com sucesso\n\n", x);
                } else {
                    printf("Insercao no inicio nao realizada\n\n");
                }

                x = insereFinal(li, al3);
                if (x){
                    printf("Insercao no final do aluno %d realizada com sucesso\n\n", x);
                } else {
                    printf("Insercao no final nao realizada\n\n");
                }

                x = insereOrdenado(li, al2);
                if (x){
                    printf("Insercao ordenada do aluno %d realizada com sucesso\n\n", x);
                } else {
                    printf("Insercao ordenada nao realizada\n\n");
                }

    x = removeOrdenado(li, matricula);
    if (x){
        printf("Remocao ordenada do aluno %d realizada com sucesso\n\n", x);
    } else {
        printf("Remocao ordenada nao realizada\n\n");
    }

                x = insereOrdenado(li, al1);
                if (x){
                    printf("Insercao ordenada do aluno %d realizada com sucesso\n\n", x);
                } else {
                    printf("Insercao ordenada nao realizada\n\n");
                }

    x = consultaPosicao(li, pos, &al_consulta);
    if (x){
        printf("Consulta na posicao %d realizada com sucesso\n", pos);
        printf("Matricula: %d\n", al_consulta.matricula);
        printf("Nota 1: %.2f\n", al_consulta.n1);
        printf("Nota 2: %.2f\n", al_consulta.n2);
        printf("Nota 3: %.2f\n", al_consulta.n3);
    } else {
        printf("Consulta na posicao %d nao realizada\n\n", pos);
    }

    printf("\n");

    x = consultaMatricula(li, matricula, &al_consulta);
    if (x){
        printf("Consulta da matricula %d realizada com sucesso\n", matricula);
        printf("Nota 1: %.2f\n", al_consulta.n1);
        printf("Nota 2: %.2f\n", al_consulta.n2);
        printf("Nota 3: %.2f\n", al_consulta.n3);
    } else {
        printf("Consulta da matricula %d nao realizada\n\n", matricula);
    }
    
    apagaLista(li);
    printf("\n\n");
    system("pause");
    return 0;
}
