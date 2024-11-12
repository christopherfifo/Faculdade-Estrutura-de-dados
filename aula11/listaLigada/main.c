#include <stdio.h>
#include <stdlib.h>
#include "listaLigada.h"

int main()
{
    Lista *li = NULL;
    int x = 0;

    if((li = criaLista()) == NULL){
        abortaPrograma();
    }

    x = tamanhoLista(li);
    printf("o tamanho da lista e: %d", x);

    if(listaCheia(li)){
        printf("\nLista esta cheia!");
    }else{
        printf("\nLista nao esta cheia.");
    }

    apagaLista(li);
    return 0;
}
