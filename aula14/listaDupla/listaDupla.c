#include <stdio.h>
#include <stdlib.h>
#include "listaDupla.h"


struct elemento {
    struct elemento *ant;
    struct aluno dados;
    struct elemento *prox;
};

typedef struct elemento ELEM;

Lista* criar_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL){
        *li = NULL;
    }
    return li;
}

void apagaLista(Lista* li) {
    if (li != NULL) {
        ELEM *no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

void abortaPrograma() {
    printf("Erro! Lista não foi alocada, ");
    printf("programa será encerrado....\n\n\n");
    system("pause");
    exit(1);
}

int tamanhoLista(Lista* li) {
    if (li == NULL) {
        abortaPrograma();
    }
    int acum = 0;
    ELEM* no = *li;
    while (no != NULL) {
        acum++;
        no = no->prox;
    }
    return acum;
}

int listaCheia(Lista* li) {
    return 0;
}

int listaVazia(Lista* li) {
    if (li == NULL) {
        abortaPrograma();
    }
    if (*li == NULL) {
        return 1;
    }
    return 0;
}

int insereInicio(Lista* li, ALUNO al) {
    if (li == NULL) {
        abortaPrograma();
    }
    ELEM* no = (ELEM*) malloc(sizeof(ELEM));
    if (no == NULL) {
        return 0;
    }
    no->dados = al;
    no->prox = (*li);
    no->ant = NULL;
    if (*li != NULL) {
        (*li)->ant = no;
    }
    *li = no;
    return al.matricula;
}

int insereFinal(Lista* li, ALUNO al) {
    if (li == NULL) {
        abortaPrograma();
    }
    ELEM* no = (ELEM*) malloc(sizeof(ELEM));
    if (no == NULL) {
        return 0;
    }
    no->dados = al;
    no->prox = NULL;
    if ((*li) == NULL) {
        no->ant = NULL;
        *li = no;
    } else {
        ELEM* aux = *li;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return al.matricula;
}

int insereOrdenado(Lista* li, ALUNO al) {
    if (li == NULL) {
        abortaPrograma();
    }
    ELEM* no = (ELEM*) malloc(sizeof(ELEM));
    if (no == NULL) {
        return 0;
    }
    no->dados = al;
    if (listaVazia(li)) {
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    } else {
        ELEM *anterior, *atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula) {
            anterior = atual;
            atual = atual->prox;
        }
        if (atual == *li) {
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if (atual != NULL) {
                atual->ant = no;
            }
        }
    }
    return al.matricula;
}

int removeInicio(Lista* li) {
    int matricula;
    if (li == NULL) {
        abortaPrograma();
    }
    if (!listaVazia(li)) {
        return 0;
    }
    ELEM* no = *li;
    *li = no->prox;
    if (no->prox != NULL) {
        no->prox->ant = NULL;
    }
    matricula = no->dados.matricula;
    free(no);
    return matricula;
}

int removeFinal(Lista* li) {
    int matricula;
    if (li == NULL) {
        abortaPrograma();
    }
    if (!listaVazia(li)) {
        return 0;
    }
    ELEM* no = *li;
    while (no->prox != NULL) {
        no = no->prox;
    }
    if (no->ant == NULL) {
        *li = no->prox;
    } else {
        no->ant->prox = NULL;
    }
    matricula = no->dados.matricula;
    free(no);
    return matricula;
}

int removeOrdenado(Lista* li, int mat) {
    int matricula;
    if (li == NULL) {
        abortaPrograma();
    }
    ELEM *no = *li;
    while (no != NULL && no->dados.matricula != mat) {
        no = no->prox;
    }
    if (no == NULL) {
        return 0;
    }
    if (no->ant == NULL) {
        *li = no->prox;
    } else {
        no->ant->prox = no->prox;
    }
    if (no->prox != NULL) {
        no->prox->ant = no->ant;
    }
    matricula = no->dados.matricula;
    free(no);
    return matricula;
}

int consultaPosicao(Lista* li, int pos, ALUNO* al) {
    if (li == NULL) {
        abortaPrograma();
    }
    ELEM* no = *li;
    int i = 1;
    while (no != NULL && i < pos) {
        no = no->prox;
        i++;
    }
    if (no == NULL) {
        return 0;
    }else{
    *al = no->dados;
    return 1;
    }
}

int consultaMatricula(Lista* li, int mat, ALUNO* al) {
    if (li == NULL) {
        abortaPrograma();
    }
    ELEM* no = *li;
    while (no != NULL && no->dados.matricula != mat) {
        no = no->prox;
    }
    if (no == NULL) {
        return 0;
    } else {
        *al = no->dados;
        return 1;
    }
}