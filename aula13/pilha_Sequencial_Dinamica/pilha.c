#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{
    ALUNO dados;
    struct pilha *prox;
};

typedef struct pilha ELEM;


PILHA *criaPilha(){
    PILHA *pi = (PILHA*) malloc(sizeof(PILHA));
    if(pi != NULL){
        *pi = NULL;
    }
    return pi;
}

void liberaPilha(PILHA *pi){
    if(pi != NULL){
        ELEM *no;
        while ((*pi) != NULL){
            no = *pi;
            free(no);
        }
        free(pi);
    }
}

void abortaPrograma(){
    printf("ERRO! Pilha nao foi alocada, ");
    printf("programa sera encerrado... \n\n\n");
    system("pause");
    exit(1);
}

int tamanhoPilha(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
    }
    int acum = 0;
    ELEM *no = *pi;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}

int pilhaCheia(PILHA *pi){
    return 0;
}

int pilhaVazia(PILHA *pi){
    if(pi == NULL){
        abortaPrograma();
    }
    if(*pi == NULL){
        return 1;
    }
    return 0;
}

int inserePilha(PILHA *pi, ALUNO al){
    if(pi == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return al.matricula;
}

int removePilha(PILHA *pi){
    int matricula;
    if(pi == NULL){
        abortaPrograma();
    }
    if((*pi) == NULL){
        return 0;
    }
    ELEM *no = *pi;
    *pi = no->prox;
    matricula = (*no).dados.matricula;
    free(no);
    return matricula;
}

int acessaTopoPilha(PILHA *pi, ALUNO *al){
    if(pi == NULL){
        abortaPrograma();
    }
    if((*pi) == NULL){
        return 0;
    }
    *al = (*pi)->dados;
    return 1;
}
