/*
Construa uma função em linguagem C que receba dois parâmetros: um ponteiro
inicio1 (por valor) para uma LLSE de valores inteiros e um ponteiro inicio2 (por
valor) para uma LLSE de valores inteiros. A função deverá retornar 1 (verdadeiro)
caso ambas as LLSE sejam exatamente iguais ou 0 (falso), caso contrário. Por
exatamente iguais entenda-se que as duas LLSE armazenam a mesma quantidade de
nós e todos os nós armazenados em posições equivalentes de ambas as listas têm o
mesmo conteúdo*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no
{
  int valor;
  struct no *prox;
};

typedef struct no No;

void insereNoInicio(No **inicio, No *novo)
{
  novo->prox = *inicio;
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
    novo->prox = NULL;
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

///função que resolve a questão 1 do Trabalho para as Férias
int questao1(No *inicio1, No *inicio2)
{
  int saoIguais = 1;
  No *aux1, *aux2;
  aux1 = inicio1;
  aux2 = inicio2;

  while(aux1 != NULL && aux2 != NULL)
  {
    if(aux1->valor != aux2->valor)
    {
      saoIguais = 0;
    }
    aux1 = aux1->prox;
    aux2 = aux2->prox;
  }

  //são dois endereços diferentes - que apontam para listas diferentes?
  if(aux1 != aux2)
  {
    saoIguais = 0;
  }


  return(saoIguais);
}

int main()
{
  //srand(time(NULL));
  int i, numero;
  No *novo, *inicio1 = NULL, *inicio2 = NULL;
  for(i = 0; i < 10; i++)
  {
    novo = devolveNo(i);
    insereNoFinal(&inicio1, novo);
  }
  for(i = 0; i < 10; i++)
  {
    novo = devolveNo(i+3);
    insereNoFinal(&inicio2, novo);
  }
  printf("\nLista 1 \n");
  imprime(inicio1);

  printf("\nLista 2 \n");
  imprime(inicio2);

  ///chamada da função que resolve a questão 1

  if(questao1(inicio1, inicio2))
  {
    puts("\nLista 1 e Lista 2 sao IGUAIS");
  }
  else
  {
    puts("\nLista 1 e Lista 2 NAO sao iguais");
  }
  return 0;
}

