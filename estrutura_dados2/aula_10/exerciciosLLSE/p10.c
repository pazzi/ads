/*
10. Implemente uma função que receba três parâmetros: um ponteiro inicio (por referência) para uma
    LLDE, um ponteiro novo (por valor) para um novo nó que vai ser inserido na LLDE e um inteiro n
    (por valor) que indica em qual posição da lista o novo nó será inserido (o novo nó deverá ser
    inserido na n-ésima posição da LLDE). A função deverá retornar 1 (verdadeiro), caso a inserção
    seja bem sucedida e 0 (falso), caso contrário. A inserção não será bem sucedida caso o valor de
    n seja negativo ou ainda, caso seu valor seja superior ao tamanho da LLDE (quantidade de
    elementos já armazenados).
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

int questao10(No **inicio, No *novo, int n)
{
  int i, retorno = 1;
  No *p1, *p2;
  if(n == 1)///insere no Início
  {
    insereNoInicio(&*inicio, novo);
  }
  else
  {
    p1 = *inicio;
    if(p1 != NULL)
    {
      p2 = p1->prox;
    }
    i = 2;
    while(i < n && p2 != NULL)
    {
      i++;
      p1 = p2;
      p2 = p2->prox;
    }
    if(i == n) ///achou uma posição ainda dentro da lista
    {
      p1->prox = novo;
      novo->anterior = p1; ///LLDE
      novo->prox = p2;
      p2->anterior = novo; ///LLDE
    }
    else
    {
      retorno = 0;
    }
  }
  return(retorno);
}

main()
{
  srand(time(NULL));
  int deuCerto, posicao, i;
  No *novo, *inicio = NULL;
  for(i = 0; i < 10; i++)
  {
    novo = devolveNo(rand()%100);
    insereNoInicio(&inicio, novo);
  }
  imprime(inicio);

  posicao = 10;
  novo = devolveNo(99999);
  deuCerto = questao10(&inicio, novo, posicao);
  if(deuCerto == 0)
  {
    printf("\nErro na insercao. Nao existe a posicao %i\n", posicao);
  }
  else
  {
    printf("\n");
    imprime(inicio);
    printf("Novo noh inserido com sucesso na posicao %i\n", posicao);
  }
}
