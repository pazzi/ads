#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>

//RESOLUCAO DO EXERCICIO -> FUNCAO INVERSAO NA LINHA 112

struct no
{
  int valor;
  struct no *proximo;
};

typedef struct no No;

No* devolveNo(int valor);
void insereNoInicio(No **inicio, No *novo);
void insereNoFinal(No **inicio, No *novo);
void imprime(No *inicio);
void inversao(No **inicio);

int main()
{
  int long tam;
  int i, numero;
  No *novo, *inicio1 = NULL, *inicio2 = NULL, *inicio3 = NULL;

  int lista1[8] ={2,4,5,8,7,1,9,3};

  for(i = 0; i < 8; i++)
  {
    novo = devolveNo(lista1[i]);
    insereNoFinal(&inicio1, novo);
  }

  system("clear");
 
  printf("--------------------------------------------------------------------------\n");
  printf("           Avaliação - Inversao\n");
  printf("--------------------------------------------------------------------------\n");

  printf("\nLista 1 \n");
  imprime(inicio1);

inversao(&inicio1);
printf("\n\n\nImpressao após a inversao\n\n");

  imprime(inicio1);
  free(inicio1);
  free(inicio3);
  inicio1 = NULL;

  printf("\n\n\n");
  return 0;
}


void insereNoInicio(No **inicio, No *novo)
{
  novo->proximo = *inicio;
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
    while(aux->proximo != NULL)
    {
      aux = aux->proximo;
    }
    aux->proximo = novo;
  }
}

void imprime(No *inicio)
{
  int i = 1;
  while(inicio != NULL)
  {
    printf(" [%i] ", (*inicio).valor);
    inicio = (*inicio).proximo;
  }
}

No *devolveNo(int valor)
{
  No *novo;
  novo = (No *) malloc(sizeof(No));
  if(novo != NULL)
  {
    novo->valor = valor;
    novo->proximo = NULL;
  }
  else
  {
    puts("\n E R R O   C A T A S T R O F I C O !!");
  }
  return(novo);
}
//
//RESOLUCAO DA QUESTAO:
//
void inversao(No **inicio)
{
  No *l1, *l2, *l3;
  if((*inicio != NULL) && ((*inicio)->proximo != NULL))
  {
    l1 = NULL;
    l2 = *inicio;
    l3 = (*inicio)->proximo;
    while(l2 != NULL)
    {
      l2->proximo = l1;
      l1 = l2;
      l2 = l3;
      if(l3 != NULL)
      {
        l3 = l3->proximo;
      }
    }
    *inicio = l1;
  }
}

