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
