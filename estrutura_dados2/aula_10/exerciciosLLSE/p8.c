/*
8. Construa e apresente uma função em linguagem C que execute as seguintes funcionalidades:
a) Receber dois parâmetros: um ponteiro inicio (por referência) para uma LLDE e um ponteiro novo (por valor)
   apontando para um nó que contém um número inteiro.
b) Fazer a inserção do nó apontado por novo na LLDE usando o seguinte raciocínio: caso o número seja menor que
   zero ele deverá ser inserido no início da lista; caso seja maior que zero deverá ser inserido no final da lista.
c) Caso o número seja 0 (zero), ele deverá ser inserido no meio da lista, entre os números menores e maiores do
   que ele.
Observações:
• O número 0 (zero) poderá ser inserido somente uma vez na LLDE.
• A função pode se utilizar de outras funções prontas para manipulação de LLDE que executem operações como,
  por exemplo, inserção de nós no início e final da lista.
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
  if(rand()%2 == 1) ///50% de chance da condição do if voltar verdadeira,
                    ///ou seja, mais ou mneos metade dos numeros serão negativos
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
    else /// o valor é zero (0)
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

