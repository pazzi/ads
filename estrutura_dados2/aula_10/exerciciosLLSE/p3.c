/*
Construa uma fun��o em linguagem C que receba dois par�metros: um ponteiro
inicio (por valor) para uma LLSE de valores inteiros e um ponteiro novo (por
valor), que aponta para um n� que ser� inserido na LLSE apontada por inicio. A
fun��o dever� inserir o novo n� exatamente na posi��o equivalente � metade da
quantidade de n�s armazenada na LLSE. Assumir que a LLSE n�o est� vazia e � par
a quantidade de n�s que ela armazena*/

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

///fun��o que resolve a quest�o 3 do trabalho para as f�rias
void questao3(No *inicio, No *novo)
{
  int i, contador = 1;
  No *p1, *p2;
  p1 = inicio;
  while(p1 != NULL)
  {
    contador++;
    p1 = p1->prox;
  }
  p1 = inicio;
  p2 = inicio->prox;
  for(i = 1; i < contador/2; i++)
  {
    p1 = p2;
    p2 = p2->prox;
  }
  p1->prox = novo;
  novo->prox = p2;
}

main()
{
  srand(time(NULL));
  int i, tamanho, numero;
  No *novo, *inicio = NULL;
  for(i = 0; i < 10; i++)
  {
    novo = devolveNo(i);
    insereNoFinal(&inicio, novo);
  }
  printf("\nLista\n");
  imprime(inicio);

  ///chamada da fun��o que resolve a quest�o 3
  novo = devolveNo(999);
  questao3(inicio, novo);

  printf("\nLista\n");
  imprime(inicio);
}

