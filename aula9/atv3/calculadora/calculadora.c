#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculadora.h"

struct armazena{
float resultadoFinal;
};

resu* criaOperacao(){
 resu *p = (resu*) malloc(sizeof(resu));
 if(p!= NULL){
    p->resultadoFinal = 0;
 }
 return p;
}

float soma (resu *p, float a, float b){
p->resultadoFinal = a + b;
return p->resultadoFinal;
}

float subtracao (resu *p, float a, float b){
p->resultadoFinal = a - b;
return p->resultadoFinal;
}

float multiplicacao (resu *p, float a, float b){
p->resultadoFinal = a * b;
return p->resultadoFinal;
}

float divisao (resu *p, float a, float b){
p->resultadoFinal = a / b;
return p->resultadoFinal;
}

float ultimoResultado(resu *p){
return p->resultadoFinal;
}

void liberaOperacao(resu *p){
free(p);
}
