/*
Construa uma fun��o em linguagem C que receba tr�s par�metros: um ponteiro
inicio1 (por refer�ncia) para uma LLSE de valores inteiros, um ponteiro inicio2
(por refer�ncia) para uma LLSE de valores inteiros e um ponteiro inicio3 (por
refer�ncia) que aponta para uma LLSE vazia. A fun��o dever� mover todos os n�s
armazenados nas listas apontadas por inicio1 e inicio2 para a lista apontada
por inicio3 de maneira intercalada, ou seja, o primeiro n� da lista de inicio1
ser� o primeiro n� da lista de inicio3, o primeiro n� da lista de inicio2 ser� o
segundo n� da lista de inicio3, o segundo n� da lista de inicio1 ser� o terceiro
n� da lista de inicio3, o segundo n� da lista de inicio2 ser� o quarto n� da lista
de inicio3 e assim por diante. Assumir que as listas apontadas por inicio1 e
inicio2 t�m exatamente a mesma quantidade de n�s armazenados. No
encerramento da fun��o as listas apontadas por inicio1 e inicio2 dever�o estar
vazias. */

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

///fun��o que resolve a quest�o 4 do trabalho para as f�rias
void questao4(No **inicio1, No **inicio2, No **inicio3)
{
  No *aux1L1, *aux2L1, *aux1L2, *aux2L2;

  aux1L1 = *inicio1;
  aux2L1 =(*inicio1)->prox;
  aux1L2 = *inicio2;
  aux2L2 =(*inicio2)->prox;
  while(aux1L2 != NULL && aux2L2 != NULL)
  {
    aux1L1->prox = aux1L2;
    aux1L2->prox = aux2L1;

    aux1L1 = aux2L1;
    aux2L1 = aux2L1->prox;
    aux1L2 = aux2L2;
    aux2L2 = aux2L2->prox;
  }
  *inicio3 = *inicio1;
  *inicio1 = *inicio2 = NULL;
}

main()
{
  srand(time(NULL));
  int i, tamanho, numero;
  No *novo, *inicio1 = NULL, *inicio2 = NULL, *inicio3 = NULL;
  for(i = 0; i < 20; i+=2)
  {
    novo = devolveNo(i);
    insereNoFinal(&inicio1, novo);
  }

  for(i = 1; i < 21; i+=2)
  {
    novo = devolveNo(i);
    insereNoFinal(&inicio2, novo);
  }
  printf("\nLista 1\n");
  imprime(inicio1);
  printf("\nLista 2\n");
  imprime(inicio2);

  ///chamada da fun��o que resolve a quest�o 4
  questao4(&inicio1, &inicio2, &inicio3);

  printf("\nLista 3\n");
  imprime(inicio3);
}

