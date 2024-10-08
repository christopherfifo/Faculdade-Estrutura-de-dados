#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PTcart.h"

// definição de tipos de dados
struct pontoCartesiano{
float x;
float y;
};

//aloca e retona um ptcart com coordenadas x e y
/*
criamos uma função que retorna um ponteiro do tipo ptcart, dentro dela criamos um ponteiro do tipo ptcart que aponta para um
endereço de memoria de um struct que crimaos com malloc, se a criação foi bem sucedida a gente entra nessa struct, acessa as
varivaies e altera o valor, depois retornamos o ponteiro, ou seja, o enderço da memoria da struct
*/
PTcart *criaPTcart(float x, float y){
PTcart *p = (PTcart*) malloc(sizeof(PTcart));

    if(p!=NULL){
        p->x = x;
        p->y = y;
    }
return p;
}

void liberaPTcart(PTcart *p){
free(p);
}

void acessaPTcart(PTcart *p, float *x, float *y){
*x = p->x;
*y = p->y;
}

void atribuiPTcart(PTcart *p, float x, float y){
p->x = x;
p->y = y;
}

float distanciaPTcart(PTcart *p1, PTcart *p2){
float dx = p1->x - p2->x;
float dy = p1->y - p2->y;
return sqrt(dx * dx + dy * dy);
}
