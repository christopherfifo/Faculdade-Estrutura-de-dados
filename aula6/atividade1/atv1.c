#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

void salvarTexto(char texto[]);
void salvarTextoMaiusculo(char texto[]);
void imprimirArquivo(char nomeArquivo[]);

int main() {
    setlocale(LC_ALL, "Portuguese");

    char texto[1000];
    printf("Digite um pequeno texto: ");
    fgets(texto, sizeof(texto), stdin);

    salvarTexto(texto);

    salvarTextoMaiusculo(texto);


    printf("\nConteúdo de arq1.txt:\n");
    imprimirArquivo("arq1.txt");


    printf("\nConteúdo de arq2.txt:\n");
    imprimirArquivo("arq2.txt");

    return 0;
}

void salvarTexto(char texto[]) {
    FILE *arquivo = fopen("arq1.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", "arq1.txt");
        exit(1);
    }
    for(int i = 0; i < strlen(texto); i++) {
        fputc(texto[i], arquivo);
    }
    
    fclose(arquivo);
}

void salvarTextoMaiusculo(char texto[]) {
    FILE *arquivo = fopen("arq2.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", "arq2.txt");
        exit(1);
    }
    for(int i = 0; i < strlen(texto); i++) {
        fputc(toupper(texto[i]), arquivo);
    }
    
    fclose(arquivo);
}

void imprimirArquivo(char nomeArquivo[]) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }
    char c= fgetc(arquivo);
    while(c != EOF) {
        printf("%c", c);
        c = fgetc(arquivo);
    }
    fclose(arquivo);
}