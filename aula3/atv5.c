#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main() {
    char str[100];
    int i = 0;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite uma string: ");
    fgets(str, 100, stdin);


    while (str[i] != '\0') {

        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;  
        }
        i++;
    }

    printf("String convertida: %s\n", str);

    return 0;
}
