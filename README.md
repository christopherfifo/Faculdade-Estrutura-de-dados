tags:: #c #memoria
[[Banco de dados (mysql)]] [[Banco de dados (mongoDB)]]

 - - - 
# <span style="color:rgb(173, 73, 225)">aula 2 - programação modular</span>

## ponteiros

toda vez que passamos alguma variável como argumento para uma função, ela faz uma cópia dessa variável, o que pode causar problemas no quesito alocação de memória, além de que quando alteramos o valor desse argumento dentro da função não alteramos de fato o valor original dele, mas sim de uma copia dentro dela (tornando obrigatório retornar esse valor). Ao invés disso podemos passar o endereço de memória onde aquele variável está alocada por meio de um ponteiro (que como o nome sugere, é um tipo de variável que aponta para o endereço de outra variável ) . 

### sintaxe

o primeiro passo para criarmos um ponteiro é definir o tipo do valor dele, ou seja, se ele vai ser **`float, int, char etc...`** , após isso criamos os ponteiros usando o caractere **`*`**  antes o nome de variável.
Agora temos que fazer esse ponteiro apontar para alguma variável, ou seja, temos que passar um endereço de memória a ser apontado, para isso declaramos o nome dele (sem o **`*`** ) e depois atribuímos a variável com o caractere **`&`** antes do nome dela.

```C
int main(){

int number = 8;
int *ponteiro;

ponteiro = &number; //agora a variavel ponteiro vai apontar para number
}
```

De forma visual ficaria mais ou menos assim: a variável **ponteiro** aponta para o endereço de memoria de variável **x (A20203B)**  que por sua vez esta **armazenando** o valor de dessa variável que é **8**.
#### Alterando o valor da variável

Para alterarmos o valor de variável que esta sendo apontada por um ponteiro, temos que chamar o ponteiro da mesma forma que ele foi declarado (com o caractere **`*`** antes do nome) e atribuir um novo valor contido no endereço da memória .

```C
int main(){

int number = 8;
int *ponteiro;

ponteiro = &number; //agora a variavel ponteiro vai apontar para number

*ponteiro = 10;

printf("%d", number);// vai exibir 10
}
```

#### Ponteiro e vetores

Em C, você não precisa passar explicitamente o endereço de memória de um vetor para um ponteiro porque o nome de um vetor já é, por definição, um ponteiro para o primeiro elemento do vetor. Ou seja, o próprio nome do vetor atua como um ponteiro para o endereço da sua primeira posição.

```C
int arr[5] = {1, 2, 3, 4, 5};
int *p;

p = arr; // 'arr' já é o endereço do primeiro elemento do vetor
```

Neste exemplo, `arr` atua como o endereço de `arr[0]`, então não precisamos usar o operador `&` para passar seu endereço.

##### Alterando os valores dentro de um vetor

Para alterar o valor de um vetor por meio de um ponteiro, você pode acessar e modificar os elementos diretamente usando o ponteiro, como se estivesse acessando o vetor por índices. Isso é feito tanto por notação de índices quanto por aritmética de ponteiros.

```C
int arr[5] = {1, 2, 3, 4, 5};
int *p;

p = arr; // 'p' agora aponta para o primeiro elemento de 'arr'

// Alterando os valores usando o ponteiro
*p = 10;      // Altera o primeiro elemento (arr[0])
*(p + 1) = 20; // Altera o segundo elemento (arr[1])
p[2] = 30;     // Outra forma de alterar o terceiro elemento (arr[2])

// Resultado: arr = {10, 20, 30, 4, 5}
```

Aqui, `*p` acessa o primeiro elemento, `*(p + 1)` o segundo, e `p[2]` o terceiro. Assim, você pode modificar os valores diretamente.

### Passagem por referência

podemos passar o endereço de memoria para alguma função e criar um ponteiro nele para alterar o valor da variável ao invés de criar um ponteiro especifico para cada  variável. Vamos destrinchar esse exemplo:

```C
#include <stdio.h>  

void calculoVantagens(float numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho, float *salarioBruto, float *salarioFamilia, float *vantagens);

void calculoDeducoes(float salarioBruto, float taxaIR, float *INSS, float *IRPF, float *Deducoes);


int main(){

    float numeroHoras, salarioHora, valorPorFilho, taxaIR;

    int numeroFilhos;

    float salarioBruto, salarioFamilia, vantagens, INSS, IRPF, Deducoes;

  

    printf("Digite o numero de horas trabalhadas: ");

    scanf(" %f", &numeroHoras);

    printf("Digite o salario por hora: ");

    scanf(" %f", &salarioHora);

    printf("Digite o numero de filhos: ");

    scanf(" %d", &numeroFilhos);

    printf("Digite o valor por filho: ");

    scanf(" %f", &valorPorFilho);

    printf("Digite a taxa de IR: ");

    scanf(" %f", &taxaIR);

  

    calculoVantagens(numeroHoras, salarioHora, numeroFilhos, valorPorFilho, &salarioBruto, &salarioFamilia, &vantagens);

    calculoDeducoes(salarioBruto, taxaIR, &INSS, &IRPF, &Deducoes);

  

    printf("\n\nSalario Bruto: %.2f\n", salarioBruto);

    printf("Salario Familia: %.2f\n", salarioFamilia);

    printf("Vantagens: %.2f\n", vantagens);

    printf("INSS: %.2f\n", INSS);

    printf("IRPF: %.2f\n", IRPF);

    printf("Deducoes: %.2f\n", Deducoes);

  

    return 0;

}

  

void calculoVantagens(float numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho, float *salarioBruto, float *salarioFamilia, float *vantagens){

    *salarioBruto = numeroHoras * salarioHora;

    *salarioFamilia = numeroFilhos * valorPorFilho;

    *vantagens = *salarioBruto + *salarioFamilia;

}

  

void calculoDeducoes(float salarioBruto, float taxaIR, float *INSS, float *IRPF, float *Deducoes){

    *INSS = salarioBruto * 0.08;

    *IRPF = salarioBruto * taxaIR;

    *Deducoes = *INSS + *IRPF;

}
```

Aqui temos um conjunto de dados de múltiplos funcionários que devem ser alterados , ao invés de altera os dados manualmente de cada funcionário podemos criar funções e passar somente o endereço de memoria das variáveis que queremos alterar.

#### Passando as variáveis 

Após coletarmos os dados podemos passar os endereços dessas variáveis utilizando o caractere **`&`** antes do nome delas.

```C
    calculoVantagens(numeroHoras, salarioHora, numeroFilhos, valorPorFilho, &salarioBruto, &salarioFamilia, &vantagens);

    calculoDeducoes(salarioBruto, taxaIR, &INSS, &IRPF, &Deducoes);
```

#### Recebendo e utilizando os endereços

Na hora da função receber os argumentos temos de declarar os tipos deles como ponteiros , pois estamos recendo apenas o endereço de memória e precisamos manipular o valor contido nas variáveis, então criamos um ponteiro que vai apontar para elas. 

**Observação: no momento que declaramos o argumento da função como tipo ponteiro e passamos um endereço de memória para ele, na hora que criarmos ele dentro da função, o mesmo estará apontado para o endereço fornecido.**

```C
void calculoVantagens(float numeroHoras, float salarioHora, int numeroFilhos, float valorPorFilho, float *salarioBruto, float *salarioFamilia, float *vantagens){

    *salarioBruto = numeroHoras * salarioHora;

    *salarioFamilia = numeroFilhos * valorPorFilho;

    *vantagens = *salarioBruto + *salarioFamilia;

}

  

void calculoDeducoes(float salarioBruto, float taxaIR, float *INSS, float *IRPF, float *Deducoes){

    *INSS = salarioBruto * 0.08;

    *IRPF = salarioBruto * taxaIR;

    *Deducoes = *INSS + *IRPF;

}
```

Aqui declaramos o ponteiro dentro da função e alteramos a valor de dentro da variável que ele aponta.

- - -
# <span style="color:rgb(173, 73, 225)">aula 3 - string </span>

## setLocale()

uma função da lib <locale.h> que formata os caracteres para o padrão de escrita, sintaxe `setlocale(LC_ALL, “Portuguese”);`  (colocar dentro do main, no topo)

```C
#include <stdio.h>
#include <locale.h>

int main() {
    // Definir a localidade para português do Brasil
    setlocale(LC_ALL, "pt_BR.UTF-8");

    // Definir um buffer para armazenar a string
    char buffer[50];

    // Solicitar ao usuário que digite algo
    printf("Digite uma frase (até 49 caracteres): ");
    
    // Usar fgets para ler no máximo 49 caracteres (o último espaço é para o caractere nulo)
    fgets(buffer, sizeof(buffer), stdin);

    // Exibir a string digitada
    printf("Você digitou: %s", buffer);

    return 0;
}

```

## <span style="color:rgb(139, 233, 253)">Trabalhando com strings</span>

O mais importante ao trabalhar com strings em C é lembrar que elas não têm o mesmo comportamento que em outras linguagens, pois o C não oferece suporte nativo a strings como tipos de dados complexos. No C, strings são, na verdade, **arrays de caracteres** (`char`), e por isso o tratamento é mais manual.

### Como funcionam as strings em C:

Ao manipular strings em C, usamos arrays de `char`, onde a sequência de caracteres é armazenada. A particularidade é que, em C, toda string deve ser **terminada pelo caractere nulo** (`'\0'`), que indica o fim da sequência. Isso quer dizer que, mesmo que o array tenha espaço para mais caracteres, o compilador considera que a string termina quando encontra o `'\0'`.

O caractere de **nova linha** (`'\n'`) não é usado para delimitar o fim de uma string, mas para indicar uma quebra de linha no texto. Já o **caractere nulo** (`'\0'`) é o marcador real que sinaliza o fim de uma string em C. Se não houver esse caractere nulo ao final de uma string, o programa pode continuar lendo "lixo de memória" (dados não usados) até encontrar um `'\0'` acidentalmente.

#### Funções para manipulação de strings em C:

Em C, temos funções para **capturar dados** do teclado, como:

- **`scanf`**: Lê dados formatados, mas pode parar de ler strings no primeiro espaço (encontrar o /n do enter).
- **`fgets`**: Lê strings de maneira mais segura, incluindo espaços e limitando o número de caracteres (ele pega o /n do enter).
- **`getchar`**: Lê um único caractere do teclado.

Para **exibir dados na tela**, temos:

- **`printf`**: Imprime texto formatado.
- **`putchar`**: Imprime um único caractere.
- **`puts`**: Imprime uma string e adiciona uma nova linha automaticamente.

#### Caracteres especiais em C:

Ao ler e exibir dados, alguns **caracteres especiais** podem ser manipulados, como:

- **`'\n'`**: Indica uma nova linha (equivalente ao Enter).
- **`'\0'`**: Indica o fim de uma string.

Esses caracteres são lidos pelo programa e podem ser exibidos, ou usados internamente para controle, como o `'\0'`. No entanto, o **`'\0'`** não é impresso, pois é apenas um marcador para o compilador saber onde a string termina. Se não cuidarmos desses detalhes, podemos encontrar comportamentos inesperados, como o **uso incorreto de `scanf`**, que pode deixar o caractere de nova linha (`'\n'`) no buffer de entrada, ou strings que exibem caracteres aleatórios (lixo de memória) se o `'\0'` não estiver presente no final.

### Quebra de linhas indesejadas 

Ao usar a função **`fgets()`**, ela inclui o caractere de nova linha (`'\n'`) na string sempre que o Enter é pressionado, caso haja espaço suficiente no buffer. Isso pode causar uma **quebra de linha extra** na hora de exibir os resultados.

Esse comportamento é normal, pois o **`fgets()`** captura o caractere de nova linha que foi inserido quando o usuário pressionou Enter para finalizar a entrada. Se não for tratado, esse `'\n'` pode aparecer na saída e causar quebras de linha indesejadas.

Se você quiser **remover o caractere de nova linha (`'\n'`)** após a leitura, pode fazer uma verificação simples para substituí-lo pelo caractere nulo (`'\0'`), que marca o fim da string.

## **getchar() e putchar()**

- **getchar()**: Lê um único caractere do teclado e retorna seu valor.
- **putchar()**: Exibe um caractere na tela.

```C
#include <stdio.h>

int main() {
    char c;
    printf("Digite um caractere: ");
    c = getchar();  // Lê um caractere
    printf("Você digitou: ");
    putchar(c);     // Exibe o caractere
    return 0;
}
```

#### saída:

```less
Digite um caractere: A
Você digitou: A
```

## **gets()**

A função **`gets()`** era usada para **ler uma string** do teclado (entrada padrão) até que fosse encontrado o caractere de nova linha (`\n`) **(diferente do fgets ele não incorpora o /n)**. Ao contrário de **`fgets()`**, que permite limitar o número de caracteres lidos para evitar estouro de buffer, **`gets()`** não faz essa verificação. Isso significa que **`gets()`** não impede a leitura de uma quantidade de caracteres maior do que o espaço disponível na memória, o que pode causar problemas graves de segurança.

```C
#include <stdio.h>

int main() {
    char buffer[20];  // Buffer de 20 caracteres
    printf("Digite uma string: ");
    gets(buffer);  // Função insegura
    printf("Você digitou: %s\n", buffer);
    return 0;
}
```

###  Por que **`gets()`** foi descontinuada?

**`gets()`** foi removida do padrão da linguagem C a partir do C11 porque **não é segura**. Ela pode causar **overflow de buffer** (quando mais dados são lidos do que o buffer pode armazenar), permitindo a escrita acidental de dados em áreas de memória que não deveriam ser modificadas. Isso abre brechas para ataques como **buffer overflow**, comuns em software vulnerável.

## **fgets()**

**fgets()** é uma função usada para ler strings a partir de um arquivo ou do teclado, pertencente à biblioteca `<stdio.h>`. Diferente de **gets()**, ela é considerada mais segura porque permite limitar o número de caracteres que podem ser lidos, evitando o estouro de buffer.

Ela recebe três argumentos:

1. **str**: Um vetor (array) de caracteres que armazenará a string lida.
2. **tamanho**: O número máximo de caracteres a serem lidos (tamanho do buffer - 1, pois o último espaço é reservado para o caractere nulo `\0`).
3. **fp**: O local de onde a string será lida, que pode ser um arquivo ou o teclado (usando `stdin`).

Ao contrário de **gets()**, **fgets()** inclui o caractere de nova linha (`\n`) na string lida, a menos que o buffer seja pequeno demais para comportá-lo. Isso é importante, pois permite que a função leia entradas maiores com mais controle sobre a quantidade de dados que pode ser processada.

Uma boa prática é sempre colocar o numero de caracteres menor do que o máximo do vetor, podemos também  usar o **`sizeof`** que pega o tamanho do vetor - 1 de forma automática 

```C
#include <stdio.h>

int main() {
    char str[50];
    
    printf("Digite uma string: ");
    fgets(str, 49, stdin);  /* Lê até 49 caracteres (50-1) + \n, mas é recomendado 
    colocar a menos do que o maximo*/
    
	printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);  // faz de forma automatica
    
    printf("Você digitou: %s", str);
    
    return 0;
}
```

#### saída:
```less
Digite uma string: Olá!
Você digitou: Olá!
```
## puts()

A função puts() escreve seu argumento string na tela, seguido por uma nova linha, ou seja, um  
‘ \n ‘. Uma chamada a puts() requer bem menos tempo do que a mesma chamada a printf() porque  
puts() pode escrever apenas strings de caractere, não podendo escrever números ou efetuar  
conversões de formato.

```C
#include <stdio.h>

int main() {
    char str[] = "Olá, mundo!";
    puts(str);  // Equivalente a printf("%s\n", str);
    return 0;
}
```

#### saída:

```less
Olá, mundo!
```


## **<span style="color:rgb(80, 250, 123)">Funções da biblioteca  string.h</span>**

### **strlen()**

Calcula o número de caracteres em uma string, sem contar o caractere nulo (`\0`), que indica o fim da string.

```C
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Olá, mundo!";
    printf("O tamanho da string é: %lu\n", strlen(str));
    return 0;
}
```

#### Saída:

```less
O tamanho da string é: 11
```

### **strcpy()**

Copia o conteúdo de uma string (fonte) para outra string (destino), ou seja, o primeiro argumento é quem vai receber a string e o segundo é da onde vai ser retirado.

```C
#include <stdio.h>
#include <string.h>

int main() {
    char origem[] = "Olá, mundo!";
    char destino[20];
    
    strcpy(destino, origem);
    printf("String copiada: %s\n", destino);
    
    return 0;
}
```

#### Saída:

```less
String copiada: Olá, mundo!
```

### **strcat()**

strcat() copia a sequência de caracteres contida em origem para o final da string destino, e retorna a string destino, o primeiro caractere da string origem, sobrescreve o caractere ‘ \0 ‘ de destino. o primeiro argumento é quem recebe e o segundo é a fonte.

```C
#include <stdio.h>
#include <string.h>

int main() {
    char destino[30] = "christopher";
    char origem[] = " ";
    char sobrenome[] = "willians"
    
    strcat(destino, origem);
    strcat(destino, sobrenome);
    printf("String concatenada: %s\n", destino);
    
    return 0;
}
```

#### Saída:

```less
String concatenada: christopher willians
```

### **strcmp()**

Compara duas strings lexicograficamente (ordem alfabética). Retorna:

    - `0` se as strings forem iguais;
    - Um valor negativo se a primeira for "menor" que a segunda;
    - Um valor positivo se a primeira for "maior" que a segunda.

```C
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "abc";
    char str2[] = "abcd";
    
    int resultado = strcmp(str1, str2);
    
    if (resultado == 0) {
        printf("As strings são iguais.\n");
    } else if (resultado < 0) {
        printf("str1 é menor que str2.\n");
    } else {
        printf("str1 é maior que str2.\n");
    }
    
    return 0;
}
```

#### Saída:

```less
str1 é menor que str2.
```

### **strchr()**

Busca dentro de string – A função strchr() devolve a localização (endereço de memória), ou ponteiro, para a primeira ocorrência do caractere buscado (ch) dentro da string alvo. Se não encontrada, strchr() devolve um valor nulo, que é igual a zero.

```C
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Olá, mundo!";
    char *pos = strchr(str, 'm');
    
    if (pos != NULL) {
        printf("Caractere encontrado na posição: %ld\n", pos - str);
    } else {
        printf("Caractere não encontrado.\n");
    }
    
    return 0;
}
```

#### Saída:

```less
Caractere encontrado na posição: 6
```

### strstr()

Busca dentro de string – A função strstr() devolve a localização (endereço de memória), ou ponteiro, para a primeira ocorrência da string buscada dentro da string alvo. Se não encontrada, strstr() devolve um valor nulo, que é igual a zero.

```C
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Olá, mundo!";
    char *pos = strstr(str, "mundo");
    
    if (pos != NULL) {
        printf("Substring encontrada na posição: %ld\n", pos - str);
    } else {
        printf("Substring não encontrada.\n");
    }
    
    return 0;
}
```

#### Saída:

```less
Substring encontrada na posição: 5
```
## *<span style="color:rgb(255, 85, 85)">funções da biblioteca  ctype.h </span>*

### *islower(), isupper()*, toupper() e tolower()

- **`islower()`**:
    
    - Verifica se um caractere é **minúsculo** (a-z).
    - Retorna um valor diferente de zero (verdadeiro) se o caractere for minúsculo, e zero (falso) se não for.
- **`toupper()`**:
    
    - Converte um caractere **minúsculo** em **maiúsculo**.
    - Se o caractere for minúsculo, retorna sua versão maiúscula. Caso contrário, retorna o caractere sem alterações.
- **`tolower()`**:
    
    - Converte um caractere **maiúsculo** em **minúsculo**.
    - Se o caractere for maiúsculo, retorna sua versão minúscula. Caso contrário, retorna o caractere sem alterações.
- **`isupper()`**:
    
    - Verifica se um caractere é **maiúsculo** (A-Z).
    - Retorna um valor diferente de zero (verdadeiro) se o caractere for maiúsculo, e zero (falso) se não for.

```C
#include <stdio.h>
#include <ctype.h>

int main() {
    char c;

    // Entrada do usuário
    printf("Digite um caractere: ");
    scanf("%c", &c);

    // Verificar se o caractere é minúsculo
    if (islower(c)) {
        printf("%c é um caractere minúsculo\n", c);
    }

    // Verificar se o caractere é maiúsculo
    if (isupper(c)) {
        printf("%c é um caractere maiúsculo\n", c);
    }

    // Converter minúsculo para maiúsculo
    printf("Maiúsculo: %c\n", toupper(c));

    // Converter maiúsculo para minúsculo
    printf("Minúsculo: %c\n", tolower(c));

    return 0;
}
```

##### Saída esperada:

Se o usuário digitar o caractere **`a`**:
```less
Digite um caractere: a
a é um caractere minúsculo
Maiúsculo: A
Minúsculo: a
```

Se o usuário digitar o caractere **`A`**:
```less
Digite um caractere: A
A é um caractere maiúsculo
Maiúsculo: A
Minúsculo: a

```



- - - 

- - -
# **<span style="color:rgb(173, 73, 225)">aula 4 - Estruturas Heterogêneas: struct</span>**

## O que são Estruturas (Structs) em C?

Em C, uma `struct` é uma coleção de variáveis que podem ser de diferentes tipos, agrupadas sob um mesmo nome. Elas permitem organizar e manipular dados heterogêneos de maneira conveniente.

### Sintaxe Básica

```c
struct NomeDaEstrutura {
    tipo_dado1 campo1;
    tipo_dado2 campo2;
    // Outros campos
};
```

### Exemplo de Declaração

```c
struct Funcionario {
    char nome[50];
    int idade;
    float salario;
};
```

Aqui, a estrutura `Funcionario` contém três campos: nome, idade e salário. Cada um desses campos pode ser acessado separadamente.

### Atribuição de Valores

```c
struct Funcionario func1;
func1.idade = 30;
```

Os campos de uma estrutura são acessados com o operador `.`. Neste exemplo, o campo `idade` de `func1` é atribuído o valor 30.

### Matrizes de Registros

É possível declarar matrizes de estruturas para armazenar múltiplos registros:

```c
struct Funcionario funcionarios[5];
```

### Passagem de Estruturas para Funções

Podemos passar uma estrutura inteira ou um de seus campos como parâmetro para uma função. Para modificar os valores diretamente, é possível usar ponteiros:

```c
void atualizarIdade(struct Funcionario *f, int novaIdade) {
    f->idade = novaIdade;
}
```

No exemplo acima, a função recebe um ponteiro para a estrutura e atualiza o campo `idade`.

---

# **<span style="color:rgb(173, 73, 225)">aula 5 - Ponteiros</span>**

## O que são Ponteiros?

Ponteiros são variáveis que armazenam o endereço de outras variáveis na memória. Eles são úteis para acessar e manipular diretamente os valores armazenados nos endereços de memória.

### Declaração de Ponteiros

A sintaxe básica para declarar um ponteiro é:

```c
tipo_dado *nome_ponteiro;
```

Exemplo:

```c
int *p;
```

Aqui, `p` é um ponteiro para um `int`.

### Operador `&` e Operador `*`

- O operador `&` retorna o endereço de uma variável.
- O operador `*` acessa o valor armazenado no endereço apontado pelo ponteiro.

### Exemplo:

```c
int valor = 10;
int *p = &valor;
printf("%d", *p);  // Imprime 10
```

Neste exemplo, `p` armazena o endereço de `valor` e `*p` acessa o valor 10.

### Ponteiro para Ponteiro

Um ponteiro pode apontar para outro ponteiro, criando múltiplos níveis de indireção:

```c
int **p2;
```

Aqui, `p2` é um ponteiro para outro ponteiro que, por sua vez, aponta para um `int`.

### Uso com Arrays

Ponteiros podem ser usados para manipular arrays de forma eficiente, pois um array é essencialmente um ponteiro para seu primeiro elemento.

```c
int vet[5] = {1, 2, 3, 4, 5};
int *p = vet;
```

Aqui, `p` aponta para o primeiro elemento de `vet`. Podemos acessar os elementos do array usando aritmética de ponteiros.

### Funções e Ponteiros

Ponteiros são frequentemente usados para passar variáveis para funções de modo que as modificações feitas dentro da função reflitam fora dela.

```c
void incrementar(int *p) {
    (*p)++;
}
```

No exemplo acima, a função `incrementar` altera diretamente o valor da variável apontada pelo ponteiro.

--- 
# **<span style="color:rgb(173, 73, 225)">aula 6 - Manipulação de Arquivos em C</span>**

## Ponteiro `FILE`
O ponteiro `FILE` é uma estrutura especial usada pela linguagem C para manipular arquivos. Ele armazena informações como a posição do cursor e o estado do arquivo (leitura, escrita, etc.).

### Exemplo:
```c
FILE *arquivo;
```

Esse ponteiro é necessário para operações como leitura e escrita de arquivos.

## Tipos de arquivos e modos de leitura

Temos duas extensões de arquivo o `.txt e o .bin` (arquivo de texto e binário respectivamente ), e para ambos temos diferentes modos de abertura para a execução de diferentes ações

### Extensão txt

- modo **`r`** - serve somente para a leitura do texto, se faz necessário que já tenha um arquivo de texto.
- modo **`w`** - serve para escrita, ele cria o arquivo se não existir e substitui se houver um.
- modo **`a`** - serve para adicionar coisas no final do arquivo, se faz necessário que já tenha um arquivo de texto.

### Extensão bin

- modo **`rb`** - serve somente para a leitura do texto, se faz necessário que já tenha um arquivo de binário.
- modo **`wb`** - serve para escrita, ele cria o arquivo se não existir e substitui se houver um.
- modo **`ab`** - serve para adicionar coisas no final do arquivo, se faz necessário que já tenha um arquivo binário.

## Funções de Manipulação de Arquivos

### arquivo de texto

```C
#include <stdio.h>

#include <stdlib.h>

#include <ctype.h>

#include <locale.h>

#include <string.h>


void salvarTexto(char texto[]);

void salvarTextoMaiusculo(char texto[]);

void imprimirArquivo(char nomeArquivo[]);

  

int main() {

    setlocale(LC_ALL, "Portuguese");
    

    char texto[1000];

    printf("Digite um pequeno texto: ");

    fgets(texto, sizeof(texto), stdin);
  

    salvarTexto(texto);
  

    salvarTextoMaiusculo(texto);
  

    printf("\nConteúdo de arq1.txt:\n");

    imprimirArquivo("arq1.txt");

    printf("\nConteúdo de arq2.txt:\n");

    imprimirArquivo("arq2.txt");

    return 0;

}

void salvarTexto(char texto[]) {

    FILE *arquivo = fopen("arq1.txt", "w");

    if (arquivo == NULL) {

        printf("Erro ao abrir o arquivo %s\n", "arq1.txt");

        exit(1);

    }

    for(int i = 0; i < strlen(texto); i++) {

        fputc(texto[i], arquivo);

    }

    fclose(arquivo);

}

void salvarTextoMaiusculo(char texto[]) {

    FILE *arquivo = fopen("arq2.txt", "w");

    if (arquivo == NULL) {

        printf("Erro ao abrir o arquivo %s\n", "arq2.txt");

        exit(1);

    }

    for(int i = 0; i < strlen(texto); i++) {

        fputc(toupper(texto[i]), arquivo);

    }

    fclose(arquivo);

}

  

void imprimirArquivo(char nomeArquivo[]) {

    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {

        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);

        exit(1);

    }

    char c= fgetc(arquivo);

    while(c != EOF) {

        printf("%c", c);

        c = fgetc(arquivo);

    }

    fclose(arquivo);

}
```

#### `fopen()`
Abre um arquivo em um modo específico (leitura, escrita, etc.). Retorna um ponteiro do tipo `FILE`, ou `NULL` em caso de erro.
```c
FILE *fp = fopen("arquivo.txt", "r");
if (fp == NULL) {
    printf("Erro ao abrir o arquivo\n");
}
```

#### `fclose()`
Fecha um arquivo aberto. Garante que os dados no buffer sejam gravados e libera o arquivo.
```c
fclose(fp);
```

#### `fputc()`
Escreve um caractere no arquivo, devemos colocar como primeiro argumento o que vai ser escrito e como segundo argumento o arquivo que vai ser alocado. Retorna o caractere escrito ou `EOF` em caso de erro.
```c
fputc('A', fp);
```

#### `fgetc()`
Lê um caractere do arquivo, toda vez que ele é chamado ele passa para o caractere do lado. Retorna o caractere lido ou `EOF` quando o fim do arquivo é atingido.
```c
char ch = fgetc(fp);
printf("Caractere lido: %c\n", ch);
```

#### `fputs()`
Escreve uma string no arquivo, devemos colocar como primeiro argumento o que vai ser escrito e como segundo argumento o arquivo que vai ser alocado. Não adiciona automaticamente uma nova linha no final da string.
```c
fputs("Olá, mundo\n", fp);
```

#### `fgets()`
Lê uma string do arquivo até encontrar uma nova linha ou o final do arquivo. O primeiro argumento é onde será armazenado o conteúdo lido, o segundo é o tamanho de onde é armazenado e o terceiro é da onde estamos pegando.
```c
char buffer[100];
fgets(buffer, 100, fp);
printf("String lida: %s\n", buffer);
```

#### `fprintf()`
A função **`fprintf()`** é usada para **escrever dados em um arquivo**, de forma formatada, como fazemos com `printf()` para escrever na tela. Ela permite que você escreva diferentes tipos de dados (números, strings, etc.) no arquivo, mas **em formato de texto**.
```c
FILE *fp = fopen("arquivo.txt", "w");  // Abre o arquivo para escrita
if (fp != NULL) {
    int idade = 25;
    fprintf(fp, "Idade: %d\n", idade);  // Escreve "Idade: 25" no arquivo
    fclose(fp);  // Fecha o arquivo
}

```

**O que acontece?**

- O número `25` (inteiro) é **convertido para texto** e escrito no arquivo como `"Idade: 25\n"`.
- O arquivo de texto conterá a string **"Idade: 25"**, legível por qualquer editor de texto.

#### `fscanf()`
A função **`fscanf()`** é usada para **ler dados de um arquivo**, também de forma formatada, semelhante a `scanf()` que lê da entrada do teclado. Ela lê dados como strings e números a partir de um arquivo de **texto** e converte esses dados de volta para variáveis.
```c
FILE *fp = fopen("arquivo.txt", "r");  // Abre o arquivo para leitura
if (fp != NULL) {
    int idade;
    fscanf(fp, "Idade: %d", &idade);  // Lê o texto e converte o número para a variável 'idade'
    printf("Idade lida: %d\n", idade);  // Exibe a idade lida do arquivo
    fclose(fp);  // Fecha o arquivo
}
```

**O que acontece?**

- O `fscanf()` lê o texto `"Idade: 25"` do arquivo.
- Ele converte o valor `25` para um **número inteiro** e o armazena na variável `idade`.
- A leitura só acontece porque o dado no arquivo está formatado corretamente, de acordo com o que foi esperado pelo `fscanf()`.

##### Como o `fscanf()` consegue ler as varivaeis?

Quando você lê um arquivo de texto usando fscanf(), a função depende do formato dos dados no arquivo para saber como interpretar cada valor e armazená-lo nas variáveis corretas. A forma como você especifica o formato na string de formato de fscanf() é essencial para que ele saiba qual variável deve guardar qual valor.

A string de formato que você passa para fscanf() deve corresponder à estrutura e ao conteúdo dos dados no arquivo. Vamos explicar isso com mais detalhes.

**Exemplo Simples: Lendo dados formatados**

Imagine que você tem um arquivo de texto com o seguinte conteúdo:
```makefeile
Nome: João
Idade: 30
Altura: 1.75
```

Agora, você quer ler essas informações e armazená-las nas variáveis corretas: uma string para o nome, um inteiro para a idade e um float para a altura.

##### Passo 1: Formato dos dados

Você sabe que o arquivo de texto tem o seguinte formato:

- A palavra "Nome:" seguida por um nome.
- A palavra "Idade:" seguida por um número inteiro.
- A palavra "Altura:" seguida por um número decimal (float).

##### Passo 2: `fscanf()` com string de formato

Para ler os dados corretamente, você usaria `fscanf()` com uma string de formato que reflete a estrutura do arquivo. Aqui está um exemplo de como fazer isso:

```C
#include <stdio.h>

int main() {
    FILE *fp = fopen("dados.txt", "r");  // Abrindo o arquivo para leitura
    if (fp != NULL) {
        char nome[100];
        int idade;
        float altura;
        
        // Lendo os dados do arquivo e armazenando nas variáveis corretas
        fscanf(fp, "Nome: %s\n", nome);         // Lê o nome e armazena na variável 'nome'
        fscanf(fp, "Idade: %d\n", &idade);      // Lê a idade e armazena na variável 'idade'
        fscanf(fp, "Altura: %f\n", &altura);    // Lê a altura e armazena na variável 'altura'

        // Exibindo os valores lidos
        printf("Nome: %s\n", nome);
        printf("Idade: %d\n", idade);
        printf("Altura: %.2f\n", altura);

        fclose(fp);  // Fechando o arquivo
    } else {
        printf("Erro ao abrir o arquivo\n");
    }

    return 0;
}
```

### Como `fscanf()` sabe qual variável usar:

- A string de formato `"Nome: %s\n"` indica que o primeiro valor esperado é uma **string** (`%s`). O `fscanf()` vai procurar um valor de texto após a palavra "Nome:" e armazená-lo na variável `nome`.
- A string `"Idade: %d\n"` indica que o próximo valor é um **inteiro** (`%d`). `fscanf()` vai procurar um número após "Idade:" e armazená-lo na variável `idade`.
- A string `"Altura: %f\n"` indica que o último valor esperado é um **float** (`%f`). `fscanf()` vai procurar um número decimal após "Altura:" e armazená-lo na variável `altura`.

### Importante:

- **Ordem dos dados**: O `fscanf()` lê os dados na ordem em que eles estão no arquivo. Se os dados no arquivo não estiverem no formato ou ordem esperada, o `fscanf()` pode falhar ou armazenar valores incorretos.
- **Correspondência exata**: A string de formato passada para `fscanf()` deve **corresponder exatamente** ao formato dos dados no arquivo. Por exemplo, se o arquivo contiver `"Idade:"` e a string de formato espera `"Age:"`, a leitura falhará.

### Exemplo de Arquivo:

Se o arquivo `dados.txt` contiver:

```makefile
Nome: João
Idade: 30
Altura: 1.75
```

Esse código armazenará:

- `"João"` na variável `nome`
- `30` na variável `idade`
- `1.75` na variável `altura`

```makefile
João 30 1.75
```

Você pode usar o seguinte código para ler esses valores de uma vez:

```C
fscanf(fp, "%s %d %f", nome, &idade, &altura);
```

Isso vai ler:

- O nome "João" para a variável `nome` (string).
- A idade "30" para a variável `idade` (inteiro).
- A altura "1.75" para a variável `altura` (float).

### Conclusão:

O **`fscanf()`** sabe qual variável deve armazenar os valores com base no **formato que você especifica** na string de formato. Ele lê o arquivo de acordo com a estrutura que você define na string de formato (`%s`, `%d`, `%f`, etc.), e é responsabilidade do programador garantir que o arquivo esteja formatado corretamente para que a leitura funcione como esperado.

Se o arquivo não estiver formatado conforme o que o `fscanf()` espera, ele não conseguirá interpretar corretamente os dados.

### Outros exemplos:

#### Lendo múltiplos valores em uma linha:

Se o arquivo tiver múltiplos valores em uma única linha, como:
### Arquivo binário 

```C
#include <stdio.h>

#include <stdlib.h>

#include <ctype.h>

#include <locale.h>

#include <string.h>
  

typedef struct Criafuncionario{

    char nome[100];

    char telefone[15];

    char email[100];

} Funcionario;

  

void gravarVetor(Funcionario *funcionarios, int tamanho);


int main (){


    setlocale(LC_ALL, "Portuguese");

  
    Funcionario funcionarios[5];


    for (int i = 0; i < 5; i++) {

        printf("Digite o nome do funcionário %d: ", i + 1);

        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), stdin);

        funcionarios[i].nome[strcspn(funcionarios[i].nome, "\n")] = '\0'; // Remove o \n
  
        printf("Digite o telefone do funcionário %d: ", i + 1);

        fgets(funcionarios[i].telefone, sizeof(funcionarios[i].telefone), stdin);

        funcionarios[i].telefone[strcspn(funcionarios[i].telefone, "\n")] = '\0'; // Remove o \n

        printf("Digite o email do funcionário %d: ", i + 1);

        fgets(funcionarios[i].email, sizeof(funcionarios[i].email), stdin);

        funcionarios[i].email[strcspn(funcionarios[i].email, "\n")] = '\0'; // Remove o \n

    }


    gravarVetor(funcionarios, 5);

}

  

void gravarVetor(Funcionario *funcionarios, int tamanho) {

    FILE *arquivo = fopen("funcionarios.bin", "wb");

    if (arquivo == NULL) {

        printf("Erro ao abrir o arquivo\n");

        exit(1);

    }

    fwrite(funcionarios, sizeof(Funcionario), tamanho, arquivo);


    fclose(arquivo);

}
```

##### arquivo 2

```C
#include <stdio.h>

#include <stdlib.h>


typedef struct {

    char nome[100];

    char telefone[15];

    char email[100];

} Funcionario;

  

int main() {

    FILE *arquivo = fopen("funcionarios.bin", "rb");

    if (arquivo == NULL) {

        printf("Erro ao abrir o arquivo\n");

        return 1;

    }

  
    Funcionario terceiroFuncionario;


    fseek(arquivo, 2 * sizeof(Funcionario), SEEK_SET);


    fread(&terceiroFuncionario, sizeof(Funcionario), 1, arquivo);

    fclose(arquivo);

  
    printf("Terceiro Funcionário:\n");

    printf("Nome: %s\n", terceiroFuncionario.nome);

    printf("Telefone: %s\n", terceiroFuncionario.telefone);

    printf("Email: %s\n", terceiroFuncionario.email);


    return 0;

}
```
#### `fwrite()`
Escreve blocos de bytes em um arquivo, como primeiro argumento passamos o que vai ser escrito (necessita ser um ponteiro a variável, caso ao contrario devemos passar o endereço de memória dela), como segundo argumento passamos o tamanho padrão da estrutura que estamos lendo, como terceiro argumento passamos a quantidade dessa estrutura que vamos alocar (exemplo, se tivermos um array de 3 struct, podemos alocar apenas duas ) e como quarto argumento passamos onde ele vai ser escrito. Utilizada com arquivos binários para gravar inteiros, floats, structs, etc.
```c
int num = 12345;
fwrite(&num, sizeof(int), 1, fp);
```

#### `fread()`
Lê blocos de bytes de um arquivo, ideal para arquivos binários, , como primeiro argumento passamos o que vai ser lida (necessita ser um ponteiro a variável, caso ao contrario devemos passar o endereço de memória dela), como segundo argumento passamos o tamanho padrão da estrutura que estamos lendo, como terceiro argumento passamos a quantidade dessa estrutura que vamos ler (exemplo, se tivermos um array de 3 struct, podemos ler apenas duas ) e como quarto argumento passamos onde ele vai ser lida.
```c
int num;
fread(&num, sizeof(int), 1, fp);
printf("Número lido: %d\n", num);
```

#### `fseek()`
Move o ponteiro do arquivo para uma posição específica, permitindo leitura e escrita não sequenciais. De maneira geral, passamos como seu primeiro argumento o arquivo que vai ser lido, como o segundo argumento passamos o tamanho da linha que vamos avançar (exemplo, se tivermos varias strings, uma em cada linha, podemos usar o tamanho delas para pular) e o terceiro argumento é de onde vamos partir. **Temos 3 modos :**

- **`SEEK_SET`**, ele começa do inicio do arquivo, temos que passar como o segundo argumento o tamanho de bytes que vamos avançar. 
- **`SEEK_CUR`**, ele começa do ponto atual do arquivo, temos que passar como o segundo argumento o tamanho de bytes que vamos avançar. 
- **`SEEK_END`**, ele começa do fim do arquivo, temos que passar como o segundo argumento o tamanho de bytes que vamos avançar. 

<img src="./pictures/Pasted image 20241019204752.png">

```c
fseek(fp, 0, SEEK_END);  // Move o ponteiro para o fim do arquivo

typedef struct {

    char nome[100];

    char telefone[15];

    char email[100];

} Funcionario;

fseek(arquivo, 2 * sizeof(Funcionario), SEEK_SET);/* pula duas vezes o tamanho
da struct funcionario e parti do começo do arquivo, assim Move o ponteiro para o 3º funcionário*/
```

#### `rewind()`
Move o ponteiro do arquivo para o início.
```c
rewind(fp);
```

#### `feof()`
Verifica se o final do arquivo foi atingido, ele veio como solução para verificar o E0F que indica o fim do arquivo.
```c
while (!feof(fp)) {
    char ch = fgetc(fp);
    printf("%c", ch);
}
```


- - - 
# **<span style="color:rgb(173, 73, 225)">aula 7 - Alocação de memoria</span>**


A linguagem C permite alocar (reservar) dinamicamente (em tempo de execução) blocos de memória utilizando ponteiros. A esse processo dá-se o nome alocação dinâmica. A alocação dinâmica permite ao programador “criar” vetores ou arrays em tempo de execução, ou seja, alocar memória para novos arrays quando o programa está sendo executado, e não apenas quando se está escrevendo o programa. 

Essa estratégia é utilizada quando não se sabe ao certo quanto de memória será necessário para armazenar os dados com que se quer trabalhar. Desse modo, pode-se definir o tamanho do vetor ou array em tempo de execução, evitando assim o desperdício de memória.

**Então a alocação dinâmica de memória:** 

 - Reserva um bloco consecutivo de bytes na memória e retorna o endereço inicial deste bloco;
 - Permite escrever programas mais flexíveis; 
 - Poupa memória ao evitar a alocação de grandes espaços de memória que só serão liberados quando o programa terminar.

### Tamanho dos tipos de dados: 

- Tipos diferentes, podem ter tamanhos diferentes na memória, portanto, alocar memória do tipo int é diferente de alocar memória do tipo char, ou mesmo o tipo de dado struct que você criou:

<img src="./pictures/Pasted image 20241019235030.png">

## função malloc()


A função `malloc()` aloca dinamicamente um bloco de memória durante a execução do programa. Ela faz o pedido de memória ao sistema operacional e retorna um ponteiro genérico com o endereço do início do espaço de memória alocado.

### Tipos de Ponteiros

Os ponteiros são variáveis que armazenam o endereço de outras variáveis na memória. Dependendo do nível de referência, podemos ter diferentes tipos de ponteiros:

#### 1. **Ponteiro para variável**

- **Sintaxe:** `int *p;`

 Um **ponteiro de nível 1** armazena o endereço de uma variável do tipo `int`. Ele aponta diretamente para um local na memória onde um valor inteiro é armazenado.

**Exemplo:**
```C
int valor = 10;
int *p = &valor; // 'p' aponta para o endereço de 'valor'
```

Aqui, `p` é um ponteiro que armazena o endereço da variável `valor` e, através de `*p`, podemos acessar o valor 10.
#### 2. **Ponteiro para ponteiro**

- **Sintaxe:** `int **p;`

Um **ponteiro de nível 2** armazena o endereço de outro ponteiro, que, por sua vez, aponta para uma variável. Esse tipo de ponteiro é usado quando queremos manipular indiretamente o valor de um ponteiro.

**Exemplo:**
```C
int valor = 10;
int *p1 = &valor;   // 'p1' aponta para 'valor'
int **p2 = &p1;     // 'p2' aponta para 'p1'
```

Aqui, `p2` armazena o endereço de `p1`, que aponta para a variável `valor`. Podemos acessar o valor de `valor` usando `**p2`.


#### 3. **Ponteiro para ponteiro para ponteiro**

- **Sintaxe:** `int ***p;`

Um **ponteiro de nível 3** armazena o endereço de um ponteiro de nível 2, que, por sua vez, armazena o endereço de um ponteiro de nível 1, o qual finalmente aponta para uma variável. Esse nível de indireção raramente é necessário, mas pode ser útil em casos complexos, como estruturas de dados e algoritmos recursivos.

**Exemplo:**
```C
int valor = 10;
int *p1 = &valor;   // 'p1' aponta para 'valor'
int **p2 = &p1;     // 'p2' aponta para 'p1'
int ***p3 = &p2;    // 'p3' aponta para 'p2'
```

 Nesse exemplo, `p3` armazena o endereço de `p2`, que armazena o endereço de `p1`, que por sua vez armazena o endereço de `valor`. Podemos acessar o valor de `valor` usando `***p3`.

#### Resumo:

- `int *p;` → Ponteiro que aponta diretamente para um endereço de memória onde um valor `int` está armazenado.
- `int **p;` → Ponteiro que aponta para outro ponteiro, que por sua vez aponta para um valor `int`.
- `int ***p;` → Ponteiro que aponta para um ponteiro de ponteiro, que por sua vez aponta para um valor `int`.
### Sintaxe:

Para utilizar a função `malloc()`, ela deve ser atribuída a um ponteiro. A função retorna um ponteiro genérico do tipo `void *`, que precisa ser convertido para o tipo de dado desejado. Isso significa que devemos transformar esse ponteiro genérico para o tipo de dado que queremos manipular. Por exemplo, se quisermos criar um vetor de inteiros, o ponteiro que recebe a atribuição deve ser do tipo `int *`.

#### exemplo:

```c
int *vet = (int*) malloc(3 * sizeof(int));
```

Nesse exemplo, estamos alocando dinamicamente memória suficiente para armazenar 3 inteiros, e o ponteiro `vet` apontará para o início desse bloco de memória.

##### Explicação detalhada:

- **Conversão do ponteiro genérico:** O ponteiro retornado por `malloc()` é do tipo `void *` (um ponteiro genérico). Para usá-lo como um ponteiro para inteiros, fazemos um _casting_ para o tipo desejado, neste caso `(int *)`.
- **Tamanho da memória alocada:** A função `malloc()` recebe como argumento o número de bytes a serem alocados. No exemplo, calculamos esse valor multiplicando a quantidade de elementos (3) pelo tamanho de cada elemento (`sizeof(int)`), o que garante que o tamanho da memória seja apropriado para armazenar 3 inteiros.

### Criando matrizes com malloc()


Para criar uma matriz usando a função malloc(), precisamos alocar memória dinamicamente para as linhas e colunas. Isso envolve a criação de um ponteiro para ponteiro, ou seja, um ponteiro que aponta para outros ponteiros, que por sua vez apontam para as colunas da matriz. A ideia é criar um vetor de ponteiros (para as linhas) e, em seguida, alocar memória para cada linha (as colunas da matriz).

#### Passos:

1. **Criar um ponteiro de ponteiros**: Começamos criando um ponteiro do tipo `int **` para armazenar o endereço das linhas da matriz.
2. **Alocar memória para as linhas**: Usamos `malloc()` para alocar memória para o vetor de ponteiros (linhas da matriz).
3. **Alocar memória para as colunas**: Em seguida, para cada linha, alocamos um vetor de inteiros (as colunas) usando outro `malloc()`.

**Exemplo de código:**

```C
int **matriz;

// Alocando memória para 5 ponteiros (linhas)
matriz = (int**) malloc(5 * sizeof(int*));

for (int i = 0; i < 5; i++) {
    // Para cada linha, alocamos memória para 5 inteiros (colunas)
    matriz[i] = (int*) malloc(5 * sizeof(int));
}
```

##### Explicação detalhada

**Declaração de `matriz`:**

```C
int **matriz;
```

Aqui, `matriz` é um ponteiro que apontará para outros ponteiros, ou seja, um "vetor de ponteiros".

**Alocação de memória para as linhas:**

```C
matriz = (int**) malloc(5 * sizeof(int*));
```

Estamos alocando memória para 5 ponteiros, cada um representando uma linha da matriz. O `sizeof(int*)` garante que estamos alocando o espaço adequado para armazenar o endereço de um ponteiro para inteiro.

**Alocação de memória para as colunas:**

```C
for (int i = 0; i < 5; i++) {
    matriz[i] = (int*) malloc(5 * sizeof(int));
}
```

Aqui, percorremos cada linha da matriz (`matriz[i]`) e alocamos memória suficiente para 5 inteiros em cada uma delas. Cada linha da matriz pode ser vista como um vetor de inteiros.

#### Observação:

Se você quiser uma matriz de tamanho diferente (por exemplo, 5 linhas e 3 colunas), basta modificar o valor no `malloc()` que aloca as colunas:

```C
matriz[i] = (int*) malloc(3 * sizeof(int));
```

## Funções `free`, `calloc` e `realloc` em C

No C, quando alocamos memória dinamicamente usando funções como `malloc()`, precisamos gerenciar essa memória corretamente. As funções `free()`, `calloc()` e `realloc()` desempenham papéis importantes nesse gerenciamento. Vamos entender como e por que usá-las.


### `free()`

A função `free()` é usada para liberar a memória alocada dinamicamente. Quando usamos `malloc()`, `calloc()` ou `realloc()`, o sistema operacional reserva um espaço na memória, mas precisamos liberar esse espaço após o uso para evitar vazamento de memória.

#### **Por que usar `free()`?**

- Libera a memória que não será mais usada, evitando desperdício de recursos.
- Ajuda a prevenir "memory leaks" (vazamento de memória), que ocorrem quando a memória é alocada, mas nunca liberada.

#### **Sintaxe:**

```c
free(ptr);
```

Aqui, `ptr` é o ponteiro que aponta para o bloco de memória que foi alocado dinamicamente.

#### **Exemplo simples:**

```c
int *p = (int*) malloc(5 * sizeof(int));

// ... uso do ponteiro 'p'

free(p); // libera a memória alocada
```

#### **Exemplo com matriz:**

Ao liberar a memória de uma matriz alocada dinamicamente, precisamos liberar cada linha da matriz antes de liberar o ponteiro que aponta para as linhas.

```c
int **matriz;

// Alocação da matriz 5x5
matriz = (int**) malloc(5 * sizeof(int*));
for (int i = 0; i < 5; i++) {
    matriz[i] = (int*) malloc(5 * sizeof(int));
}

// ... uso da matriz

// Liberação da memória
for (int i = 0; i < 5; i++) {
    free(matriz[i]); // libera cada linha
}
free(matriz); // libera o ponteiro das linhas
```


### `calloc()`

A função `calloc()` também é usada para alocar memória dinamicamente, mas diferente de `malloc()`, ela inicializa todos os bits da memória alocada com zero. Isso é útil quando você precisa garantir que a memória alocada seja inicializada.

#### **Por que usar `calloc()`?**

- Garante que toda a memória alocada seja zerada.
- Pode evitar erros causados por lixo de memória.

#### **Sintaxe:**

```c
ptr = (tipo_dado*) calloc(n, sizeof(tipo_dado));
```

Aqui, `n` é o número de elementos, e `tipo_dado` é o tipo de dado que será armazenado.

#### **Exemplo simples:**

```c
int *p = (int*) calloc(5, sizeof(int));

// ... uso do ponteiro 'p'

free(p); // libera a memória alocada
```



### `realloc()`

A função `realloc()` é usada para redimensionar um bloco de memória alocado dinamicamente. Se você precisar aumentar ou diminuir o tamanho de um bloco de memória, `realloc()` será útil.

#### **Por que usar `realloc()`?**

- Permite expandir ou reduzir a memória alocada sem perder os dados atuais.
- Evita a necessidade de alocar um novo bloco e copiar manualmente os dados.

#### **Sintaxe:**

```c
ptr = realloc(ptr, novo_tamanho);
```

Aqui, `novo_tamanho` é o novo tamanho que você deseja alocar.

#### **Exemplo simples:**

```c
int *p = (int*) malloc(5 * sizeof(int));

// Redimensiona a memória para armazenar 10 inteiros
p = (int*) realloc(p, 10 * sizeof(int));

// ... uso do ponteiro 'p'

free(p); // libera a memória alocada
```


Essas três funções — `free()`, `calloc()` e `realloc()` — são essenciais para o gerenciamento de memória em C, permitindo que o programa aloque, redimensione e libere memória conforme necessário.

- -  -
# **<span style="color:rgb(173, 73, 225)">aula 8 - Recursividade</span>**

## O que é Recursividade?

Recursividade é uma técnica onde uma função chama a si mesma para resolver um problema. O problema é dividido em subproblemas menores até que se atinja um caso base, onde o processo recursivo termina. Esse processo é frequentemente usado para resolver problemas que podem ser naturalmente decompostos, como a função fatorial e o jogo das Torres de Hanói.

### Exemplo Simples: Cálculo de Fatorial

A fórmula para calcular o fatorial de um número é:

\[
n! = n 	imes (n-1)!
\]

Em termos recursivos, o fatorial de um número pode ser definido como:

```c
int fatorial(int n) {
    if (n == 0)
        return 1;  // Caso base
    else
        return n * fatorial(n - 1);  // Chamada recursiva
}
```

Neste exemplo, a função `fatorial` chama a si mesma para calcular o fatorial de `n-1` até que `n` seja 0, o caso base, onde a função para de se chamar.

### Condição de Parada

Uma função recursiva deve sempre ter uma **condição de parada**. Sem essa condição, a função continuaria chamando a si mesma indefinidamente, o que resultaria em um erro de execução por falta de memória.

---

## Torres de Hanói

Um exemplo clássico de recursividade é o problema das **Torres de Hanói**. O objetivo é mover uma pilha de discos de um pino para outro, respeitando as seguintes regras:

1. Apenas um disco pode ser movido por vez.
2. Um disco maior nunca pode ser colocado sobre um disco menor.

A solução recursiva do problema envolve mover os `n-1` discos para um pino intermediário, mover o maior disco diretamente para o destino e, finalmente, mover os `n-1` discos do pino intermediário para o destino.

### Exemplo de Código

```c
void torresHanoi(int n, char origem, char destino, char trabalho) {
    if (n == 1) {
        printf("Mova o disco 1 da origem %c para o destino %c\n", origem, destino);
    } else {
        torresHanoi(n-1, origem, trabalho, destino);
        printf("Mova o disco %d da origem %c para o destino %c\n", n, origem, destino);
        torresHanoi(n-1, trabalho, destino, origem);
    }
}
```

---

## Tipos de Recursão

Existem dois tipos principais de recursão:

- **Recursão direta**: A função chama a si mesma diretamente.
- **Recursão indireta**: A função chama outra função, que eventualmente chama a função original.

### Recursão Direta

Um exemplo de recursão direta é o cálculo do fatorial.

### Recursão Indireta

No caso de recursão indireta, a função A chama a função B, que chama novamente a função A. Essa técnica é menos comum, mas pode ser útil em certos contextos.

---

## Vantagens e Desvantagens da Recursividade

### Vantagens

- **Simplicidade**: A solução recursiva pode ser mais intuitiva e fácil de entender.
- **Elegância**: Soluções recursivas são geralmente mais elegantes e concisas do que suas contrapartes iterativas.

### Desvantagens

- **Desempenho**: Recursividade pode ser mais lenta devido ao tempo necessário para salvar o estado de cada chamada de função.
- **Uso de Memória**: Grandes recursões podem consumir muita memória, pois cada chamada de função ocupa espaço na pilha de execução.

---
