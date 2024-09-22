#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct funcionario{
    int id;
    char nome[100];
    int idade;
    float salario;
};

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(){
    int quantidade;
    setlocale(LC_ALL, "Portuguese");

    printf("Digite a quantidade de funcionários: ");
    scanf("%d", &quantidade);

    struct funcionario func[quantidade];

    for(int i=0; i<quantidade; i++){

        clear_screen();

        printf("\n\nDigite o id do %dº funcionário: ", i+1);
        scanf("%d", &func[i].id);
        printf("Digite o nome do %dº funcionário: ", i+1);
        getchar();
        fgets(func[i].nome, sizeof(func[i].nome), stdin);
        func[i].nome[strlen(func[i].nome)-1] = '\0';
        printf("Digite a idade do %dº funcionário: ", i+1);;
        scanf("%d", &func[i].idade);
        printf("Digite o salário do %dº funcionário: ", i+1);
        scanf("%f", &func[i].salario);
    }

    printf("\n\nFuncionários cadastrados:\n\n");

    for(int i=0; i<quantidade; i++){
        printf("\n\nID: %d\n", func[i].id);
        printf("Nome: %s\n", func[i].nome);
        printf("Idade: %d\n", func[i].idade);
        printf("Salário: %.f\n", func[i].salario);
    }

    printf("\n\n");
    system("pause");
    return 0;
}