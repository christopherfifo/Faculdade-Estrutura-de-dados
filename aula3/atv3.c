#include <stdio.h>
#include <string.h>

int main() {
    char string[100], consoante;
    int i, cont_vogais = 0;

    printf("Digite uma string: ");
    fgets(string, 100, stdin);

    printf("Digite uma consoante: ");
    scanf(" %c", &consoante);

    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || 
            string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || 
            string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || 
            string[i] == 'U') {
            cont_vogais++;
            string[i] = consoante; 
        }
    }

    printf("Número total de vogais: %d\n", cont_vogais);
    printf("Nova string: %s\n", string);
    return 0;
}
