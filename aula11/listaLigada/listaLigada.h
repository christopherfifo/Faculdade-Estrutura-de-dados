typedef struct aluno{
    int matricula;
    float n1,n2,n3;    
}ALUNO;

typedef struct elemento* Lista;

Lista *criaLista();

void abortaPrograma();

void apagaLista(Lista *li);

int tamanhoLista(Lista *li);

int listaCheia(Lista *li);

int listaVazia(Lista *li);

int insereInicio(Lista *li, ALUNO al);

int insereFinal(Lista *li, ALUNO al);