#include <stdio.h>

#include <stdlib.h>

#include <ctype.h>

#include <locale.h>

#include <string.h>

void salvatexto(char texto[]);
void textoM(char texto[]);
void textoMostrar(char nomeArquivo[], char modo[]);
void textoMostrarMaisculo (char nomeArquivo[], char modo[]);

int main(){

    setlocale(LC_ALL, "Portuguese");
    char texto[100];

    printf("escreva alguma coisa:");
    fgets(texto, sizeof(texto), stdin);

    salvatexto(texto);
    textoM(texto);
    textoMostrar("arquivo1.txt","r");
    textoMostrarMaisculo ("arquivo2.txt","r");
}

void salvatexto(char texto[]){
FILE *arquivo = fopen("arquivo1.txt", "w");

if(arquivo == NULL){

    printf("erro");
    exit(1);
}

fputs(texto, arquivo);
fclose(arquivo);
}

void textoM(char texto[]){
FILE *arquivo2 = fopen("arquivo2.txt", "w");

if(arquivo2 == NULL){

    printf("erro");
    exit(1);
}

for(int i = 0; i < strlen(texto); i++ ){

    fputc(toupper(texto[i]), arquivo2);
}

fclose(arquivo2);

}

void textoMostrar(char nomeArquivo[], char modo[]){
    setlocale(LC_ALL, "Portuguese");

FILE *arquivoGenerico = fopen(nomeArquivo, modo);

if(arquivoGenerico == NULL){

    printf("erro");
    exit(1);
}

char memoria[100];

fgets(memoria, sizeof(memoria), arquivoGenerico);

printf("\nconteudo do arquivo: \n %s", memoria);

fclose(arquivoGenerico);

}

void textoMostrarMaisculo (char nomeArquivo[], char modo[]){
    setlocale(LC_ALL, "Portuguese");

FILE *arquivoGenerico = fopen(nomeArquivo, modo);

if(arquivoGenerico == NULL){

    printf("erro");
    exit(1);
}
char c  = fgetc(arquivoGenerico);

while(!feof(arquivoGenerico)){
    printf("%c", c);
     c  = fgetc(arquivoGenerico);
}

fclose(arquivoGenerico);

}
