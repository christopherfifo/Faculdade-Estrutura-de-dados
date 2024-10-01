#include <stdio.h>
#include <ctype.h>

void strupr_custom(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void strlwr_custom(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char string[100];
    int i;

    printf("Digite uma string: ");
    fgets(string, 100, stdin);


    for (i = 0; string[i] != '\0'; i++) {
        if (islower(string[i])) {
            string[i] = toupper(string[i]);
        } else if (isupper(string[i])) {
            string[i] = tolower(string[i]);
        }
    }

    printf("String com caixa invertida: %s\n", string);


    strupr_custom(string);
    printf("String em maiúsculas: %s\n", string);

    strlwr_custom(string);
    printf("String em minúsculas: %s\n", string);

    return 0;
}
