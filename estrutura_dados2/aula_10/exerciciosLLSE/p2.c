/*
Construa uma fun��o em linguagem C que receba tr�s par�metros: um ponteiro
inicio1 (por refer�ncia) para uma LLSE de valores inteiros, um ponteiro inicio2
(por refer�ncia) para uma LLSE de valores inteiros e um ponteiro inicio3 (por
refer�ncia) que aponta para uma LLSE vazia. A fun��o dever� mover todos os n�s
das LLSE apontadas por inicio1 e inicio2 (nessa ordem) para a LLSE apontada
por inicio3. Ao t�rmino da execu��o da fun��o, tanto inicio1 quanto inicio2
dever�o apontar para NULL.*/

#include <stdio.h>
#include <stdlib.h>

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

///fun��o que resolve a quest�o 2 do Trabalho para as F�rias
void questao2(No **inicio1, No **inicio2, No **inicio3)
{
  No *aux;
  aux = *inicio1;
  while(aux->prox != NULL)
  {
    aux = aux->prox;
  }
  aux->prox = *inicio2;
  *inicio3 = *inicio1;
  *inicio1 = *inicio2 = NULL;
}

main()
{
  srand(time(NULL));
  int i, tamanho, numero;
  No *novo, *inicio1 = NULL, *inicio2 = NULL, *inicio3 = NULL;
  for(i = 0; i < 10; i++)
  {
    novo = devolveNo(i);
    insereNoFinal(&inicio1, novo);

    novo = devolveNo(i+10);
    insereNoFinal(&inicio2, novo);
  }
  printf("\nLista 1\n");
  imprime(inicio1);
  printf("\nLista 2\n");
  imprime(inicio2);

  ///chamada da fun��o que resolve a quest�o 2
  questao2(&inicio1, &inicio2, &inicio3);

  printf("\nLista 3\n");
  imprime(inicio3);
}

