#ifndef LISTASEQUENCIAL_H_INCLUDED

#define MAX 100

struct aluno{
int matricula;
float n1 , n2, n3;
};

typedef struct lista Lista;

Lista *cria_Lista();

void libera_lista(Lista *li);

int tamanho_lista(Lista *li);

int lista_cheia(Lista *li);

int lista_vazia(Lista *li);

int insere_lista_final(Lista *li, struct aluno al);

#endif // LISTASEQUENCIAL_H_INCLUDED
