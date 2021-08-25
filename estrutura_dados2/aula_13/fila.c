#include <stdlib.h>
#include <stdio.h>

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

struct no
{
  Coisa umaCoisa;
  struct no *prox;
};
typedef struct no No;

No *devolveNo(Coisa umaCoisa)
{
  No *novo = NULL;
  novo = (No *) malloc(sizeof(No));
  if(novo == NULL)
  {
    puts("\nERRO CATASTROFICO. Acabou a memoria.");
  }
  else
  {
    novo->umaCoisa = umaCoisa;
    novo->prox = NULL;
  }
  return(novo);
}

struct fila
{
  No *inicio, *fim;
};

typedef struct fila Fila;

void inicializar(Fila *umaFila)
{
  umaFila->inicio = NULL;
  umaFila->fim = NULL;
}

int inserir(Fila *umaFila, Coisa umaCoisa)
{
  int deuCerto = 1;
  No *novo = devolveNo(umaCoisa);
  if(novo == NULL)
  {
    deuCerto = 0;
  }
  else
  {
    if(umaFila->fim == NULL)
    {
      umaFila->inicio = umaFila->fim = novo;
    }
    else
    {
      umaFila->fim->prox = novo;
      umaFila->fim = novo;
    }
  }
  return(deuCerto);
}

int remover(Fila *umaFila, Coisa *umaCoisa)
{
  int deuCerto = 1;
  if(umaFila->inicio == NULL)
  {
    deuCerto = 0;
  }
  else
  {
    *umaCoisa = umaFila->inicio->umaCoisa;
    No *aux = umaFila->inicio;
    umaFila->inicio = umaFila->inicio->prox;
    if(umaFila->inicio == NULL)  //fila estah vazia
    {
      umaFila->fim = NULL;
    }
    free(aux);
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
