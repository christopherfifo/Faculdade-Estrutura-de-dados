#include <stdio.h>
#include <stdlib.h>

int main() {
    int numAlunos, i;
    float *notas, soma = 0, media;


    printf("Digite o numero de alunos: ");
    scanf("%d", &numAlunos);


    notas = (float*) malloc(numAlunos * sizeof(float));

    if (notas == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < numAlunos; i++) {
        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &notas[i]);
        soma += notas[i];
    }

    media = soma / numAlunos;

    printf("\nNotas dos alunos:\n");
    for (i = 0; i < numAlunos; i++) {
        printf("Aluno %d: %.2f\n", i + 1, notas[i]);
    }
    printf("\nMedia da turma: %.2f\n", media);

    free(notas);

    return 0;
}
