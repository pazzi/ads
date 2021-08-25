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





struct pilha
{
  Coisa itens[MAX];
  int topo; ///�ndice do array para inser��o
};
typedef struct pilha Pilha;

void inicializa(Pilha *umaPilha)
{
  (*umaPilha).topo = -1;
}

int push(Pilha *umaPilha, Coisa novaCoisa)
{
  int deuCerto = 1;
  if((*umaPilha).topo == MAX-1)
  {
    deuCerto = 0;
  }
  else
  {
    (*umaPilha).topo++;
    (*umaPilha).itens[(*umaPilha).topo] = novaCoisa;
  }
  return(deuCerto);
}

int pop(Pilha *umaPilha, Coisa *novaCoisa)
{
  int deuCerto = 1;
  if((*umaPilha).topo == -1)
  {
    deuCerto = 0;
  }
  else
  {
    *novaCoisa = (*umaPilha).itens[(*umaPilha).topo];
    (*umaPilha).topo--;
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

