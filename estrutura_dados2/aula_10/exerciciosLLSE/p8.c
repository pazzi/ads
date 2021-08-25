/*
8. Construa e apresente uma fun��o em linguagem C que execute as seguintes funcionalidades:
a) Receber dois par�metros: um ponteiro inicio (por refer�ncia) para uma LLDE e um ponteiro novo (por valor)
   apontando para um n� que cont�m um n�mero inteiro.
b) Fazer a inser��o do n� apontado por novo na LLDE usando o seguinte racioc�nio: caso o n�mero seja menor que
   zero ele dever� ser inserido no in�cio da lista; caso seja maior que zero dever� ser inserido no final da lista.
c) Caso o n�mero seja 0 (zero), ele dever� ser inserido no meio da lista, entre os n�meros menores e maiores do
   que ele.
Observa��es:
� O n�mero 0 (zero) poder� ser inserido somente uma vez na LLDE.
� A fun��o pode se utilizar de outras fun��es prontas para manipula��o de LLDE que executem opera��es como,
  por exemplo, inser��o de n�s no in�cio e final da lista.
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

int pesquisa(No *inicio, int valor)
{
  int achou = 0;
  No *aux;
  aux = inicio;
  while((aux != NULL) && (!achou))
  {
    if(aux->valor == valor)
    {
      achou = 1;
    }
    else
    {
      aux = aux->prox;
    }
  }
  return(achou);
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
  if(rand()%2 == 1) ///50% de chance da condi��o do if voltar verdadeira,
                    ///ou seja, mais ou mneos metade dos numeros ser�o negativos
  {
    numero *= -1; ///inverte o sinal do numero
  }
  return(numero);
}

void questao8(No **inicio, No *novo)
{
  No *p1, *p2;
  if(novo->valor > 0)
  {
    insereNoFinal(&*inicio, novo);
  }
  else
  {
    if(novo->valor < 0)
    {
      insereNoInicio(&*inicio, novo);
    }
    else /// o valor � zero (0)
    {
      int existe = pesquisa(*inicio, novo->valor);
      if(existe)
      {
        puts("\nERRO. O valor zero (0) pode ser inserido uma unica vez.");
      }
      else
      {
        if(*inicio == NULL)
        {
          insereNoInicio(&*inicio, novo);
        }
        else
        {
          p1 = *inicio;
          p2 = (*inicio)->prox;
          while(p2 != NULL && p2->valor <= 0)
          {
            p1 = p2;
            p2 = p2->prox;
          }
          p1->prox = novo;
          novo->anterior = p1; ///LLDE
          novo->prox = p2;
          p2->anterior = novo; ///LLDE
        }
      }
    }
  }
}

main()
{
  srand(time(NULL));
  int i, tamanho, numero;
  No *enderecoDoMeio = NULL, *novo, *inicio = NULL;
  for(i = 0; i < 20; i++)
  {
    numero = devolveNumero(10);
    novo = devolveNo(numero);
    questao8(&inicio, novo);
  }
  imprime(inicio);
}

