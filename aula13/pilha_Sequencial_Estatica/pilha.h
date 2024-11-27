#define MAX 100

    typedef struct aluno{
        int matricula;
        float n1, n2, n3;
    }ALUNO;

    typedef struct pilha PILHA;

    PILHA *criaPilha();

    void liberaPilha(PILHA *pi);

    int tamanhoPilha(PILHA *pi);

    int pilhaCheia(PILHA *pi);

    int pilhaVazia(PILHA *pi);

    int inserePilha(PILHA *pi, ALUNO al);

    int removePilha(PILHA *pi);

    int acessaTopoPilha(PILHA *pi, ALUNO *al);
