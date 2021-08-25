include <stdlib.h>
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

struct pilha
{
  No *topo; ///eh o ponteiro inicio
};
typedef struct pilha Pilha;

void inicializa(Pilha *umaPilha)
{
   umaPilha->topo = NULL;
}

///inser��o no in�cio
int push(Pilha *umaPilha, Coisa novaCoisa)
{
  int deuCerto = 1;
  No *novo = devolveNo(novaCoisa);
  if(novo == NULL)
  {
    deuCerto = 0;
  }
  else
  {
    novo->prox = umaPilha->topo;
    umaPilha->topo = novo;
  }
  return(deuCerto);
}

///remo��o do in�cio
int pop(Pilha *umaPilha, Coisa *novaCoisa)
{
  int deuCerto = 1;
  No *aux;
  if(umaPilha->topo == NULL)
  {
    deuCerto = 0;
  }
  else
  {
    *novaCoisa = umaPilha->topo->umaCoisa;
    aux = umaPilha->topo;
    umaPilha->topo = umaPilha->topo->prox;
    free(aux);
  }
  return(deuCerto);
}

main()
{
  Pilha umaPilha;
  inicializa(&umaPilha);
  int i;
  Coisa novaCoisa;
  int deuCerto;
  printf("\nPUSH (insercao no topo da pilha)");
  for(i = 0; i < 5; i++)
  {
    novaCoisa = devolveCoisa();
    deuCerto = push(&umaPilha, novaCoisa);
    if(deuCerto)
    {
      puts("\nInserido com sucesso.");
    }
    else
    {
      puts("\nERRO. Overflow da pilha.");
    }
  }

  printf("\nPOP (remocao do topo da pilha)");
  for(i = 0; i < 6; i++)
  {
     deuCerto = pop(&umaPilha, &novaCoisa);
     if(deuCerto)
     {
       imprimeCoisa(novaCoisa);
     }
     else
     {
       puts("\nERRO. Underflow da pilha.");
     }
  }
}
