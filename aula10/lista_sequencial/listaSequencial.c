#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listaSequencial.h"

struct lista{

int qtd;
struct aluno dados[MAX]
};

Lista *cria_Lista(){
Lista *li;
li = (Lista*) malloc(sizeof(struct lista));

if(li != NULL){
    li->qtd = 0;
}
return li;
}

int tamanho_lista(Lista *li){

if(li != NULL){
    return -1;
} else{
return li->qtd;
}
}

int lista_cheia(Lista *li){
if(li != NULL){
    return -1;
} else{
return (li->qtd == MAX);
}
}

int lista_vazia(Lista *li){
if(li != NULL){
    return -1;
} else{
return (li->qtd == 0);
}
}

int insere_lista_final(Lista *li, struct aluno al){

if(li !=NULL){
    return 0;
}
if(lista_cheia(li)){
    return 0;
}
li->dados[li->qtd] = al;
li->qtd++;
return 1;
}

void libera_lista(Lista *li){
free(li);
}
