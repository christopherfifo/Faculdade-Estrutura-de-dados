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
