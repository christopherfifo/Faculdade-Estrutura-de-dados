#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "PTcart.h"


int main() {
    float d = 0, retornaX, retornaY;
    PTcart *p = NULL, *q = NULL;

    // Cria��o dos pontos cartesianos
    p = criaPTcart(10, 21);
    q = criaPTcart(7, 25);

    // C�lculo da dist�ncia entre os pontos
    d = distanciaPTcart(p, q);
    printf("Distancia entre os pontos cartesianos: %f\n", d);

    // Atribui��o de novos valores ao ponto q
    atribuiPTcart(q, 15, -2);

    // Nova dist�ncia entre os pontos
    d = distanciaPTcart(p, q);
    printf("Nova distancia entre os pontos cartesianos: %f\n", d);

    // Acessando as coordenadas de p
    acessaPTcart(p, &retornaX, &retornaY);
    printf("Valores armazenados em p: X = %.2f e Y = %.2f\n", retornaX, retornaY);

    // Acessando as coordenadas de q
    acessaPTcart(q, &retornaX, &retornaY);
    printf("Valores armazenados em q: X = %.2f e Y = %.2f\n", retornaX, retornaY);

    // Liberando mem�ria alocada
    liberaPTcart(p);
    liberaPTcart(q);

    system("PAUSE");
    return 0;
}
