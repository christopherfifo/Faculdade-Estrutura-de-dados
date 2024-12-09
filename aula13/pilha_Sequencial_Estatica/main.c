#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    int x; 


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

    PILHA *pi = NULL;

    pi = criaPilha();

    x = tamanhoPilha(pi);
    printf("\n\tO tamanho da pilha e: %d\n", x);

    x = pilhaCheia(pi);
    if(x){
        printf("\n\tA Pilha esta cheia! \n");
    }else{
        printf("\n\tA Pilha nao esta cheia. \n");
    }

    x = pilhaVazia(pi);
    if(x){
        printf("\n\tA Pilha esta vazia! \n");
    }else{
        printf("\n\tA Pilha nao esta vazia. \n");
    }
    x = inserePilha(pi, al1);
    if(x){
        printf("\n\tElemento %d inserido com sucesso!", x);
    }else{
        printf("\n\tERRO, elemento nao inserido");
    }

    x = inserePilha(pi, al2);
    if(x){
        printf("\n\tElemento %d inserido com sucesso!", x);
    }else{
        printf("\n\tERRO, elemento nao inserido");
    }

    x = inserePilha(pi, al3);
    if(x){
        printf("\n\tElemento %d inserido com sucesso!", x);
    }else{
        printf("\n\tERRO, elemento nao inserido");
    }

    x = tamanhoPilha(pi);
    printf("\n\n\tO tamanho da pilha e: %d", x);

    x = acessaTopoPilha(pi, &al_consulta);
    if(x){
        printf("\n\n\tConsulta realizada com sucesso:");
        printf("\n\tMatricula: %d", al_consulta.matricula);
        printf("\n\tNota 1: %.2f", al_consulta.n1);
        printf("\n\tNota 2: %.2f", al_consulta.n2);
        printf("\n\tNota 3: %.2f", al_consulta.n3);
    }else{
        printf("\n\tERRO, consulta nao realizada");
    }

    x = removePilha(pi);
    if(x){
        printf("\n\n\tElemento %d removido com sucesso!", x);
    }else{
        printf("\n\tERRO, elemento nao removido");
    }

    x = acessaTopoPilha(pi, &al_consulta);
    if(x){
        printf("\n\n\tConsulta realizada com sucesso:");
        printf("\n\tMatricula: %d", al_consulta.matricula);
        printf("\n\tNota 1: %.2f", al_consulta.n1);
        printf("\n\tNota 2: %.2f", al_consulta.n2);
        printf("\n\tNota 3: %.2f", al_consulta.n3);
    }else{
        printf("\n\tERRO, consulta nao realizada");
    }


    liberaPilha(pi);
}
