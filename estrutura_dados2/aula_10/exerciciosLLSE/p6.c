/*
6. Construa uma função que receba um ponteiro inicio (por referência) para uma LLDE (Lista Linear Duplamente Encadeada)
   de valores inteiros. Ela deverá encontrar o nó que armazena o maior valor dentro da lista e copiá-lo para o início da
   lista. Assume-se que existe somente um nó que contém o maior valor.
*/


#include <stdio.h>
#include <stdlib.h>

struct no
{
  int valor;
  struct no *prox;
  struct no *anterior; ///LLDE
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

No *removeDoInicio(No **inicio)
{
  No *aux = NULL;
  if(*inicio != NULL)
  {
    aux = *inicio;
    *inicio = (*inicio)->prox;
    aux->prox = NULL;
    if(*inicio != NULL)
    {
      (*inicio)->anterior = NULL;
    }
  }
  return(aux);
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


///função que resolve a questão 6 da lista de férias
void questao6(No **inicio)
{
  No *aux, *novo;
  int maior;
  aux = *inicio;
  if(aux != NULL)
  {
    maior = aux->valor;
    while(aux != NULL)
    {
      if(aux->valor > maior)
      {
        maior = aux->valor;
      }
      aux = aux->prox;
    }
  }
  novo = devolveNo(maior);
  insereNoInicio(&*inicio, novo);
}

main()
{
  srand(time(NULL));
  int i, tamanho, numero;
  No *novo, *inicio = NULL;
  for(i = 0; i < 10; i++)
  {
    numero = devolveNumero(100);
    novo = devolveNo(numero);
    insereNoFinal(&inicio, novo);
  }
  imprime(inicio);

  ///chamada da função que resolve a questão 6
  questao6(&inicio);

  printf("\n");
  imprime(inicio);
}

