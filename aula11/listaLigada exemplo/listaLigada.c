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

int listaVazia(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int insereInicio(Lista *li, ALUNO al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = (*li);
    *li = no;

    return al.matricula;
}

int insereFinal(Lista *li, ALUNO al){
        if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }else{
        ELEM *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return al.matricula;
}

int insereOrdenado(Lista *li, ALUNO al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return al.matricula;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return al.matricula;
    }
}

int removeInicio(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    if(listaVazia(li)){
        return 0;
    }

    int matricula;
    ELEM *no = *li;
    matricula = no->dados.matricula;
    *li = no->prox;
    free(no);
    return matricula;
}

int removeFinal(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    if(listaVazia(li)){
        return 0;
    }

    int matricula;
    ELEM *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    if(no == (*li)){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    matricula = no->dados.matricula;
    free(no);
    return matricula;
}

int removeOrdenado(Lista *li, int mat){
    if(li == NULL){
        abortaPrograma();
    }
    if(listaVazia(li)){
        return 0;
    }

    int matricula;
    ELEM *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    matricula = no->dados.matricula;
    free(no);
    return matricula;
}

int consultaPosicao(Lista *li, int posicao, ALUNO *al){
    if(li == NULL){
        abortaPrograma();
    }
    if(listaVazia(li)){
        return 0;
    }
    if(posicao <= 0){
        return 0;
    }

    ELEM *no = *li;
    int i = 1;
    while(no != NULL && i < posicao){
        no = no->prox;
        i++;
    }
    if(no == NULL){
        return 0;
    }
    *al = no->dados;
    return 1;
}

int consultaMatricula(Lista *li, int mat, ALUNO *al){
    if(li == NULL){
        abortaPrograma();
    }
    if(listaVazia(li)){
        return 0;
    }

    ELEM *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    *al = no->dados;
    return 1;
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