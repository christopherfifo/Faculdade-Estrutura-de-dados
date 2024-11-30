#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "acme.h"


struct elemento
{
    CLIENTE dados;
    struct elemento *prox;
}; // struct Lista

typedef struct elemento ELEM;

Lista *criaLista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

FILE* abriArquivo(Lista *li){
    FILE *arquivo = fopen("clientes.bin", "rb");

    if (arquivo == NULL) {
        printf("Arquivo inexistente, criando o arquivo...\n");

        arquivo = fopen("clientes.bin", "wb");
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }

        return arquivo;
    }

    CLIENTE cliente;
    while (fread(&cliente, sizeof(CLIENTE), 1, arquivo) == 1) {
        insereOrdenado(li, cliente);
    }

    return arquivo;
}

void abortaPrograma(){
    printf("ERRO! Lista nao foi alocado, ");
    printf("programa sera encerrado....\n\n\n");
    system("pause");
    exit(1);
}


int listaCheia(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    return 0;
}

int listaVazia(Lista *li){
    if(li == NULL){
        abortaPrograma();
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}



int insereOrdenado(Lista *li, CLIENTE al){
    if(li == NULL){
        abortaPrograma();
    }
    ELEM *no = (ELEM*) malloc(sizeof(ELEM));
    if(no == NULL){
        return 0;
    }
    no->dados = al;
    if(listaVazia(li)){
        no->prox = (*li);
        *li = no;
        return al.identificador;
    }else{
        ELEM *ant, *atual = *li;
        while(atual != NULL && atual->dados.identificador < al.identificador){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return al.identificador;
    }
}



int removeOrdenado(Lista *li, int id){
    if(li == NULL){
        abortaPrograma();
    }
    if(listaVazia(li)){
        return 0;
    }

    int identificador;
    ELEM *ant, *no = *li;
    while(no != NULL && no->dados.identificador != id){
        ant = no;
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no == *li){
        *li = no->prox;
    }else{
        ant->prox = no->prox;
    }
    identificador = no->dados.identificador;
    free(no);
    return identificador;
}


int consultaIdentificador(Lista *li, int id, CLIENTE *al){
    if(li == NULL){
        abortaPrograma();
    }
    if(listaVazia(li)){
        return 0;
    }

    ELEM *no = *li;
    while(no != NULL && no->dados.identificador != id){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    *al = no->dados;
    return 1;
}

void consultaNome(Lista *li, char nome[]){
    if(li == NULL){
        abortaPrograma();
    }
    if(listaVazia(li)){
        return;
    }
    if(nome == NULL){
        return;
    }

    nome = converteNome(nome);

    ELEM *no = *li;
    int tamanho = 0;
    char nomePesquisa[80];

    while(no != NULL){

        strcpy(nomePesquisa, no->dados.nome);

        if(strcmp(converteNome(nomePesquisa), nome) == 0){ 

            tamanho++;

            printf("\n\nCliente %d\n\n", tamanho);

            relatorio(&no->dados);
            
        }
        no = no->prox;
    }
    
    if(tamanho == 0){
        printf("\n\nNenhum cliente encontrado com o nome %s\n\n", nome);
    }else{
        printf("\n\nTotal de clientes encontrados: %d\n\n", tamanho);
    }
}

struct cliente coletadados(Lista *li) {

struct cliente al1;
int verificador = 0;

while(verificador == 0){
    printf("\nDigite o identificador (id) do cliente:");
    scanf("%d", &al1.identificador);
    getchar(); 

    verificador = confereDupllicidade(li, al1.identificador);
    if(verificador == 0){
        printf("\n\nIdentificador ja existente, digite outro identificador.\n\n");
    }
} 

printf("\nDigite o nome do cliente:");
fgets(al1.nome, sizeof(al1.nome), stdin);
al1.nome[strcspn(al1.nome, "\n")] = '\0'; 

printf("\nDigite a empresa do cliente:");
fgets(al1.empresa, sizeof(al1.empresa), stdin);
al1.empresa[strcspn(al1.empresa, "\n")] = '\0'; 

printf("\nDigite o departamento do cliente:");
fgets(al1.departamento, sizeof(al1.departamento), stdin);
al1.departamento[strcspn(al1.departamento, "\n")] = '\0'; 

printf("\nDigite o telefone do cliente:");
fgets(al1.telefone, sizeof(al1.telefone), stdin);
al1.telefone[strcspn(al1.telefone, "\n")] = '\0'; 

printf("\nDigite o celular do cliente:");
fgets(al1.celular, sizeof(al1.celular), stdin);
al1.celular[strcspn(al1.celular, "\n")] = '\0'; 

printf("\nDigite o email do cliente:");
fgets(al1.email, sizeof(al1.email), stdin);
al1.email[strcspn(al1.email, "\n")] = '\0'; 

    return al1;
}


char converteNome(char nome[]){
    for(int i = 0; i < strlen(nome); i++){
        nome[i] = tolower(nome[i]);
    }
    return nome;
}

void relatorio(CLIENTE *al){
    printf("\n\nIdentificador: %d", al->identificador);
    printf("\nNome: %s", al->nome);
    printf("\nEmpresa: %s", al->empresa);
    printf("\nDepartamento: %s", al->departamento);
    printf("\nTelefone: %s", al->telefone);
    printf("\nCelular: %s", al->celular);
    printf("\nEmail: %s", al->email);
}

int confereDupllicidade(Lista *li, int id){
    if(li == NULL){
        abortaPrograma();
    }
    if(listaVazia(li)){
        return 0;
    }

    ELEM *no = *li;
    while(no != NULL){
        if (no->dados.identificador == id) {
            return 0;
        }
        no = no->prox;
    }

    return 1;
}

void apagaLista(Lista *li){
    if(li != NULL){
        ELEM *no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox; // anda para a proxima estrutura sozinho
            free(no);
        }
        free(li);
    }
}
