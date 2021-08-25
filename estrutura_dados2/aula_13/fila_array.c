#include <stdlib.h>
#include <stdio.h>

#define MAX 100

struct coisa
{
  int codigo;
};

typedef struct coisa Coisa;

void imprimeCoisa(Coisa umaCoisa)
{
  printf("\nCodigo: %i", umaCoisa.codigo);
}

Coisa devolveCoisa()
{
  Coisa umaCoisa;
  fflush(stdin);
  printf("\nDigite o codigo: ");
  scanf("%i", &umaCoisa.codigo);
  return(umaCoisa);
}

int comparaCoisas(Coisa umaCoisa, Coisa outraCoisa)
{
  int saoIguais = 1;
  if(umaCoisa.codigo != outraCoisa.codigo)
  {
    saoIguais = 0;
  }
  return(saoIguais);
}

int ehMaiorACoisa(Coisa umaCoisa, Coisa outraCoisa)
{
  int ehMaior = 0;
  if(umaCoisa.codigo > outraCoisa.codigo)
  {
    ehMaior = 1;
  }
  return(ehMaior);
}

struct fila
{
  Coisa itens[MAX];
  int inicio, fim, quantos;
};
typedef struct fila Fila;

void inicializar(Fila *umaFila)
{
  (*umaFila).quantos = 0;
  (*umaFila).inicio = 0;
  (*umaFila).fim = -1;
}

int inserir(Fila *umaFila, Coisa umaCoisa)
{
  int deuCerto = 1;
  if((*umaFila).quantos == MAX)
  {
    deuCerto = 0;
  }
  else
  {
    if((*umaFila).fim == MAX-1)
    {
      (*umaFila).fim = 0;
    }
    else
    {
      (*umaFila).fim++;
    }
    (*umaFila).itens[(*umaFila).fim] = umaCoisa;
    (*umaFila).quantos++;
  }
  return(deuCerto);
}

int remover(Fila *umaFila, Coisa *umaCoisa)
{
  int deuCerto = 1;
  if((*umaFila).quantos == 0)
  {
    deuCerto = 0;
  }
  else
  {
    *umaCoisa = (*umaFila).itens[(*umaFila).inicio];
    (*umaFila).quantos--;
    if((*umaFila).inicio == MAX-1)
    {
      (*umaFila).inicio = 0;
    }
    else
    {
      (*umaFila).inicio++;
    }
  }
  return(deuCerto);
}

main()
{
  Fila umaFila;
  inicializar(&umaFila);
  int i;
  Coisa novaCoisa;
  int deuCerto;
  printf("\nInserecao (insercao no final da fila)");
  for(i = 0; i < 5; i++)
  {
    novaCoisa = devolveCoisa();
    deuCerto = inserir(&umaFila, novaCoisa);
    if(deuCerto)
    {
      puts("\nInserido com sucesso.");
    }
    else
    {
      puts("\nERRO. A fila esah cheia.");
    }
  }

  printf("\nRemover (remocao do inicio da fila)");
  for(i = 0; i < 6; i++)
  {
     deuCerto = remover(&umaFila, &novaCoisa);
     if(deuCerto)
     {
       imprimeCoisa(novaCoisa);
     }
     else
     {
       puts("\nERRO. A fila estah vazia.");
     }
  }
}

