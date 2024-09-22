//todo --------------------------------- NÃO USEI GPT, MAS USEI ELE PARA COMENTAR O CÓDIGO ------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// ! Estrutura FUNCIONARIO para armazenar informações do funcionário
typedef struct funcionario{
    int id;             // ! Identificador único do funcionário
    char nome[100];     // ! Nome do funcionário
    int idade;          // ! Idade do funcionário
    float salario;      // ! Salário do funcionário
}FUNCIONARIO;


// * Função para coletar dados de um funcionário
FUNCIONARIO coletaDados();
// * Função para imprimir os dados dos funcionários
void imprimeDados(FUNCIONARIO func[], int quantidade);
// * Função para reajustar o salário do funcionário em 10%
void reajusteSalario(float *salario);
// * Função para imprimir os salários reajustados dos funcionários
void realSalario(FUNCIONARIO func[], int quantidade);

int main(){
    int quantidade;     // ! Quantidade de funcionários
    setlocale(LC_ALL, "Portuguese");   // ! Configura o uso de acentos

    printf("Digite a quantidade de funcionários: ");
    scanf(" %d", &quantidade);    // * Captura a quantidade de funcionários
    printf("\n");

    FUNCIONARIO func[quantidade]; // ! Array de structs para armazenar os funcionários

    // ! Loop para coletar dados de todos os funcionários
    for (int i = 0; i < quantidade; i++){
        func[i] = coletaDados(); // * Coleta os dados de cada funcionário
    }

    imprimeDados(func, quantidade);   // * Imprime os dados dos funcionários

    // ! Loop para reajustar o salário de todos os funcionários
    for (int i = 0; i < quantidade; i++){
        reajusteSalario(&func[i].salario);   // * Reajusta o salário do funcionário, usamos o & para passar o endereço da variável já que ela não é um ponteiro
    }

    realSalario(func, quantidade);   // * Exibe os salários reajustados

    printf("\n\n");
    system("pause");   // * Pausa o sistema antes de encerrar o programa
    return 0;
}

// * Função que coleta os dados de um funcionário
FUNCIONARIO coletaDados(){
    FUNCIONARIO nario;     // ! Variável temporária para armazenar os dados do funcionário
    printf("Digite o ID do funcionário: ");
    scanf("%d", &nario.id);    // * Captura o ID do funcionário
    printf("Digite o nome do funcionário: ");
    getchar();    // * Limpa o buffer do teclado
    fgets(nario.nome, sizeof(nario.nome), stdin);   // * Captura o nome do funcionário
    nario.nome[strlen(nario.nome)-1] = '\0';   // * Remove o caractere de nova linha
    printf("Digite a idade do funcionário: ");
    scanf("%d", &nario.idade);  // * Captura a idade do funcionário
    printf("Digite o salário do funcionário: ");
    scanf("%f", &nario.salario);   // * Captura o salário do funcionário
    printf("\n");

    return nario;   // * Retorna os dados coletados
}

// * Função que imprime os dados de todos os funcionários
void imprimeDados(FUNCIONARIO func[], int quantidade){

    // ! Loop para imprimir os dados de cada funcionário
    for (int i = 0; i < quantidade; i++){
        printf("Funcionário %d\n", i+1);    // ! Exibe o índice do funcionário
        printf("\n");
        printf("ID: %d\n", func[i].id);     // * Exibe o ID do funcionário
        printf("Nome: %s\n", func[i].nome); // * Exibe o nome do funcionário
        printf("Idade: %d\n", func[i].idade);   // * Exibe a idade do funcionário
        printf("Salário: %.2f\n", func[i].salario);   // * Exibe o salário do funcionário
        printf("\n");
    }
}

// * Função que reajusta o salário do funcionário em 10%
void reajusteSalario(float *salario){
    *salario *= 1.10;   // ! Aumenta o salário em 10%
}

// * Função que imprime os salários reajustados
void realSalario(FUNCIONARIO func[], int quantidade){
    printf("Salários reajustados:\n\n");

    // ! Loop para imprimir os salários reajustados de cada funcionário
    for (int i = 0; i < quantidade; i++){
        printf("Nome: %s\n", func[i].nome);   // * Exibe o nome do funcionário
        printf("Salário: %.2f\n", func[i].salario);   // * Exibe o salário reajustado
        printf("\n");
    }
}
