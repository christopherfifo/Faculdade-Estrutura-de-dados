#include <stdio.h>
#include <string.h>

int main()
{
    char nome[50], sobrenome[50];
    char *p;


    printf("digite o seu um nome: ");
    fgets(nome, sizeof(nome), stdin);
    
    printf("\ndigite o seu outro nome: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    
    strtok(nome, "\n");
    strtok(sobrenome, "\n");
    
    if(strstr(nome, sobrenome) != NULL){
        p = strstr(nome, sobrenome);
        printf("\numa string esta contida na outra, local de memoria: %p", &p);
    } else{
        printf("\na primeira string não ta contida na segunda");
    }
    
    system("pause");
    return 0;
}
