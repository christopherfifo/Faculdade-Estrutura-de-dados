#include <stdio.h>>
#include <stdlib.h>

float salarioBruto, salarioFamilia, vantagens, INSS, IRPF, deducoes;

void calculoVantegens(float, float, int, float);
void calculoDeducoes(float);

int main(){

float salarioHora, numeroHoras ,valorPorFilho,  taxaIR;
int numeroFilhos;

printf("\nDigite o numero de horas que voce trabalha: ");
 scanf(" %f", &numeroHoras);

printf("\nDigite o valor da sua hora trabalhada: ");
 scanf(" %f", &salarioHora);

printf("\nDigite o numero de filhos que voce tem: ");
 scanf(" %d", &numeroFilhos);

printf("\nDigite o valor por filho: ");
 scanf(" %f", &valorPorFilho);

 calculoVantegens( numeroHoras, salarioHora, numeroFilhos, valorPorFilho);

 printf("\nDigite a sua taxa de imposto de renda: ");
 scanf(" %f", &taxaIR);

 calculoDeducoes(taxaIR);

 printf("\nO seu salario bruto e: %f", salarioBruto);
 printf("\nO seu salario familia e: %f", salarioFamilia);
 printf("\nSuas vantagens sao: %f", vantagens);
 printf("\nO valor do seu INSS e: %f", INSS);
 printf("\nO valor do seu IRPF e: %f", IRPF);
 printf("\nSua deducao e: %f", deducoes);
return 0;
}

void calculoVantegens(float numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho){
salarioBruto = numeroHoras * salarioHora;
salarioFamilia = numeroFilhos * valorPorFilho;
vantagens = salarioBruto + salarioFamilia;
}

void calculoDeducoes(float taxaIR){
INSS = salarioBruto * 0.08;
IRPF = salarioBruto * taxaIR;
deducoes = INSS + IRPF;
}
