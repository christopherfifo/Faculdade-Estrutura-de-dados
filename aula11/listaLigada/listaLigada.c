#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"


struct elemento
{
    ALUNO dados;
    struct elemento *prox;
}; // struct Lista

typedef struct elemento ELEM;

Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

void abortaPrograma(){
    printf("ERRO! Lista nao foi alocado, ");
    printf("programa sera encerrado....\n\n\n");
    system("pause");
    exit(1);
}

int tamanhoLista(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    int acum = 0;
    ELEM *no = *li;
    while(no != NULL){
        acum++;
        no = no->prox;
    }
    return acum;
}

int listaCheia(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    return 0;
}

void apagaLista(Lista *li){
    if(li != NULL){
        ELEM *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox; // anda para a proxima estrutura sozinho
            free(no);
        }
        free(li);
    }
}