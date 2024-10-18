#include <stdio.h>
#include <string.h>

int main()
{
    char nome[50], sobrenome[50], espaco[10] = {" "};


    printf("digite o seu primeiro nome: ");
    fgets(nome, sizeof(nome), stdin);
    
    printf("digite o seu sobrenome: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    
     strtok(nome, "\n");
      strtok(sobrenome, "\n");
    
    strcat(nome, espaco);
    strcat(nome, sobrenome);
    
    printf(" seu nome e: %s", nome);
    
    printf("\n\n");
    system("pause");
    
    return 0;
}
