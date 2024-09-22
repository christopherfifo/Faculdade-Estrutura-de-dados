#include <stdio.h>
#include <stdlib.h>

int main() {
    int i;

    for (i = 0; i < 12; i++) {
        if(i == 6){
            printf("\n\n\t\t captura de i em: %d \n\n", i);
            break;
            printf("Observe que este printf nao sera executado!!\n");
        }
        printf("Valor de i: %d \n", i);
    }   

    printf("\n\n");
    system("pause");
    return 0;
}