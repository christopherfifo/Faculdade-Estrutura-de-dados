typedef struct armazena resu;

resu* criaOperacao();

float soma(resu *p, float x, float y);

float subtracao(resu *p, float x, float y);

float multiplicacao(resu *p, float x, float y);

float divisao(resu *p, float x, float y);

float ultimoResultado(resu *p);

void liberaOperacao(resu *p);
