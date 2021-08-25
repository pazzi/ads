/*
9. Construa e apresente uma função em linguagem C que execute as seguintes funcionalidades:
a) Receber três parâmetros: um ponteiro inicio (por valor) para uma LLDE que armazena inteiros, um
   ponteiro inicioNegativo (por referência) que aponta para uma LLDE vazia que pode armazenar inteiros
   e um último ponteiro inicioPositivo (por referência) que também aponta para uma LLDE vazia que
   pode armazenar inteiros.
b) Copiar todos os nós apontados por inicio que armazenam números negativos para a lista apontada
   por inicioNegativo.
c) Copiar todos os nós apontados por inicio que armazenam números positivos para a lista apontada
   por inicioPositivo.
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

void questao9(No *inicio, No **inicioNegativo, No **inicioPositivo)
{
  No *aux, *novo;
  aux = inicio;
  while(aux != NULL)
  {
    novo = devolveNo(aux->valor);
    if(aux->valor < 0)
    {
      insereNoFinal(&*inicioNegativo, novo);
    }
    else
    {
      insereNoFinal(&*inicioPositivo, novo);
    }
    aux = aux->prox;
  }
}

main()
{
  srand(time(NULL));
  int i, numero;
  No *novo, *inicio = NULL, *inicioNegativo = NULL, *inicioPositivo = NULL;
  for(i = 0; i < 20; i++)
  {
    numero = devolveNumero(100);
    novo = devolveNo(numero);
    insereNoFinal(&inicio, novo);
  }

  questao9(inicio, &inicioNegativo, &inicioPositivo);

  puts("\nLista Total");
  imprime(inicio);
  getch();

  puts("\nLista dos Valores Negativos");
  imprime(inicioNegativo);
  getch();

  puts("\nLista dos Valores Positivos");
  imprime(inicioPositivo);
  getch();
}

