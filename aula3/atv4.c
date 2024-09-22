#include <stdio.h>
#include <string.h>

int main() {
    char string1[100], string2[100];

    printf("Digite a primeira string: ");
    fgets(string1, 100, stdin);

    printf("Digite a segunda string: ");
    fgets(string2, 100, stdin);

    if (strstr(string1, string2) != NULL) {
        printf("A segunda string está contida na primeira.\n");
    } else {
        printf("A segunda string NÃO está contida na primeira.\n");
    }
    return 0;
}
