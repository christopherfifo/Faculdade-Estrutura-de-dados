#include <stdio.h>
#include <ctype.h>
#include <string.h>

void invert_words(char *str) {
    char temp[100];
    int j = 0, len = strlen(str);

   
    for (int i = len - 1; i >= 0; i--) {
        if (str[i] == ' ' || str[i] == '\n') {
            temp[j++] = str[i];
        } else {
            int start = i;
            while (i >= 0 && str[i] != ' ' && str[i] != '\n') {
                i--;
            }
            for (int k = start; k > i; k--) {
                temp[j++] = str[k];
            }
        }
    }
    temp[j] = '\0';
    strcpy(str, temp);
}

int main() {
    char string[100];

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

   
    strupr(string);
    printf("String em maiúsculas: %s", string);

 
    invert_words(string);
    printf("String com palavras invertidas: %s", string);

   
    strlwr(string);
    printf("String em minúsculas: %s", string);

    return 0;
}


/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nome[50], outro[50];
    int n = 0;

    printf("Digite o seu nome: ");
    fgets(nome, sizeof(nome), stdin);

    // Remover a nova linha que o fgets adiciona
    strtok(nome, "\n");

    // Inverter as letras: maiúsculas para minúsculas e vice-versa
    while (nome[n] != '\0') {
        if (islower(nome[n])) {
            outro[n] = toupper(nome[n]);
        } else {
            outro[n] = tolower(nome[n]);
        }
        n++;
    }
    outro[n] = '\0';  // Finalizar a string invertida

    // Exibir a string com letras invertidas
    printf("\nSua palavra com as letras invertidas: %s", outro);

    // Converter a string original para minúsculas
    for (n = 0; nome[n] != '\0'; n++) {
        nome[n] = tolower(nome[n]);
    }
    printf("\nSua palavra em minúsculas: %s", nome);

    // Converter a string original para maiúsculas
    for (n = 0; nome[n] != '\0'; n++) {
        nome[n] = toupper(nome[n]);
    }
    printf("\nSua palavra em maiúsculas: %s", nome);

    return 0;
}

 */