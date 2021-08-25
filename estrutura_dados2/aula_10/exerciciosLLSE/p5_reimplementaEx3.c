/*
Construa uma função em linguagem C que receba dois parâmetros: um ponteiro
inicio (por valor) para uma LLDE de valores inteiros e um ponteiro novo (por
valor), que aponta para um nó que será inserido na LLDE apontada por inicio. A
função deverá inserir o novo nó exatamente na posição equivalente à metade da
quantidade de nós armazenada na LLDE. Assumir que a LLDE não está vazia e é par
a quantidade de nós que ela armazena*/

#include <stdio.h>
#include <stdlib.h>

struct no
{
  int valor;
  struct no *prox;
  struct no *anterior;
};

typedef struct no No;

void insereNoInicio(No **inicio, No *novo)
{
  novo->prox = *inicio;
  if(*inicio != NULL)
  {
    (*inicio)->anterior = novo; ///LLDE
  }
  *inicio = novo;
}

void insereNoFinal(No **inicio, No *novo)
{
  No *aux;
  if(*inicio == NULL)
  {
    insereNoInicio(&*inicio, novo);
  }
  else
  {
    aux = *inicio;
    while(aux->prox != NULL)
    {
      aux = aux->prox;
    }
    aux->prox = novo;
    novo->anterior = aux; ///LLDE
  }
}


void imprime(No *inicio)
{
  int i = 1;
  while(inicio != NULL)
  {
    printf("%2i: %i \n", i++, (*inicio).valor);
    inicio = (*inicio).prox;
  }
}

No *devolveNo(int valor)
{
  No *novo;
  novo = (No *) malloc(sizeof(No));
  if(novo != NULL)
  {
    novo->valor = valor;
    novo->prox = novo->anterior = NULL; ///LLDE
  }
  else
  {
    puts("\n E R R O   C A T A S T R O F I C O !!");
  }
  return(novo);
}

int devolveNumero(int limite)
{
  int numero;
  numero = rand()%limite;
  return(numero);
}

///função que resolve a questão 5_3 do trabalho para as férias
void p5_reimplementaEx3(No *inicio, No *novo)
{
  int i, contador = 1;
  No *p1, *p2;
  p1 = inicio;
  while(p1 != NULL)
  {
    contador++;
    p1 = p1->prox;
  }
  p1 = inicio;
  p2 = inicio->prox;
  for(i = 1; i < contador/2; i++)
  {
    p1 = p2;
    p2 = p2->prox;
  }
  p1->prox = novo;
  novo->anterior = p1; ///LLDE
  novo->prox = p2;
  if(p2 != NULL) ///LLDE
  {
    p2->anterior = novo; ///LLDE
  }
}

main()
{
  srand(time(NULL));
  int i, tamanho, numero;
  No *novo, *inicio = NULL;
  for(i = 0; i < 10; i++)
  {
    novo = devolveNo(i);
    insereNoFinal(&inicio, novo);
  }
  printf("\nLista\n");
  imprime(inicio);

  ///chamada da função que resolve a questão 3
  novo = devolveNo(999);
  p5_reimplementaEx3(inicio, novo);

  printf("\nLista\n");
  imprime(inicio);
}

