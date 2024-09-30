#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct funcionario{
    int id;
    char nome[100];
    int idade;
    float salario;
}FUNCIONARIO;

FUNCIONARIO coletaDados();
void imprimeDados(FUNCIONARIO func[], int quantidade);
void reajusteSalario(float *salario);
void realSalario(FUNCIONARIO func[], int quantidade);

int main(){
    int quantidade;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite a quantidade de funcionários: ");
    scanf(" %d", &quantidade);
    printf("\n");

    FUNCIONARIO func[quantidade];

    for (int i = 0; i < quantidade; i++){
        func[i] = coletaDados();
    }

    imprimeDados(func, quantidade);

    for (int i = 0; i < quantidade; i++){
        reajusteSalario(&func[i].salario);
    }

    realSalario(func, quantidade);

    printf("\n\n");
    system("pause");
    return 0;
}

FUNCIONARIO coletaDados(){
    FUNCIONARIO nario;
    printf("Digite o ID do funcionário: ");
    scanf("%d", &nario.id);
    printf("Digite o nome do funcionário: ");
    getchar();
    fgets(nario.nome, sizeof(nario.nome), stdin);
    nario.nome[strlen(nario.nome)-1] = '\0';
    printf("Digite a idade do funcionário: ");
    scanf("%d", &nario.idade);
    printf("Digite o salário do funcionário: ");
    scanf("%f", &nario.salario);
    printf("\n");

    return nario;
}

void imprimeDados(FUNCIONARIO func[], int quantidade){
    for (int i = 0; i < quantidade; i++){
        printf("Funcionário %d\n", i+1);
        printf("\n");
        printf("ID: %d\n", func[i].id);
        printf("Nome: %s\n", func[i].nome);
        printf("Idade: %d\n", func[i].idade);
        printf("Salário: %.2f\n", func[i].salario);
        printf("\n");
    }
}

void reajusteSalario(float *salario){
    *salario *= 1.10;
}

void realSalario(FUNCIONARIO func[], int quantidade){
    printf("Salários reajustados:\n\n");
    for (int i = 0; i < quantidade; i++){
        printf("Nome: %s\n", func[i].nome);
        printf("Salário: %.2f\n", func[i].salario);
        printf("\n");
    }
}
