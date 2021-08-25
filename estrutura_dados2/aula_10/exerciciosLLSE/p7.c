/*7. Construa uma função que receba um ponteiro inicio (por referência) para uma LLDE (Lista Linear Duplamente Encadeada)
     de valores inteiros. Ela deverá encontrar o nó que armazena o menor valor dentro da lista e movê-lo para o final da
     lista. Assume-se que existe somente um nó que contém o menor valor.*/
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


///função que resolve a questão 7 da lista de férias
void questao7(No **inicio)
{
  No *aux, *menor, *p1, *p2;

  if(*inicio != NULL)
  {
    ///achar o endereco do noh com o menor valor
    aux = menor = *inicio;
    while(aux != NULL)
    {
      if(aux->valor < menor->valor)
      {
        menor = aux;
      }
      aux = aux->prox;
    }

    if(menor != *inicio)
    {
      p1 = *inicio;
      p2 = (*inicio)->prox;
      while(p2 != menor)
      {
        p1 = p2;
        p2 = p2->prox;
      }
      p1->prox = p2->prox;///retira o menor da lista
      p2->prox->anterior = p1; ///LLDE
    }
    else
    {
      *inicio = (*inicio)->prox; ///retira o menor da lista se ele for o primeiro noh
      (*inicio)->anterior = NULL; ///LLDE
    }
    ///insere o menor no final
    menor->prox = NULL; ///ponteiro prox do noh final sempre aponta para NULL (fim da lista)
    menor->anterior = NULL; ///LLDE
    insereNoFinal(&*inicio, menor);
  }
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

  ///chamada da função que resolve a questão 7
  questao7(&inicio);

  printf("\n");
  imprime(inicio);
}

