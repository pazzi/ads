#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>


struct no
{
  int item;
  struct no *esq, *dir;
};

// prototipo das funcoes
void insere(struct no **raiz, struct no *novo);
void consultar(struct no *raiz, int numero);
void preordem(struct no *raiz);
void emordem(struct no *raiz);
void posordem(struct no *raiz);
void imprimirDeLado(struct no *raiz, int espaco);
void procurarUmParaExcluir(struct no **raiz, int numero, int *achou);
void excluir(struct no **raiz);
int devolveAltura (struct no *raiz);

int main()
{
  struct no *raiz, *novo;
  char opcao;
  int achou;
  raiz = NULL;
  //clrscr();
  /*
  system("clear");
  do
  {
    system("clear");
    printf("\nOperacoes em Arvores Binarias de Busca");
    printf("\n1 - Incluir novo item");
    printf("\n2 - Consultar novo item");
    printf("\n3 - Imprimir em preordem");
    printf("\n4 - Imprimir emordem");
    printf("\n5 - Imprimir em posordem");
    printf("\n6 - Imprimir bonitinho");
    printf("\n7 - Excluir um item");
    printf("\n8 - Destruir a arvore");
    printf("\n9 - Imprime a altura da arvore");
    printf("\nS - Sair do programa");
    printf("\nDigite sua opcao: ");
    //flushall();
    scanf("%c", &opcao);
    switch(toupper(opcao))
    {
      case '1': // incluir novo item
      {
      */
        //int numero[16]={2,45,33,11,4,6,7,11,23,9,76,45,15,26,30};
        //int numero[3]={2,1,3};
	int numero[6]={7,10,13,15,8,6};
        //printf("\nDigite um numero: ");
        //scanf("%i", &numero);
	for(int i=0; i<6; i++)
	{
        	novo = (struct no *) malloc(sizeof(struct no));
        	novo->item = numero[i];
        	novo->esq = NULL;
        	novo->dir = NULL;
        	insere(&raiz, novo);
	}

        printf("\n-----------------\n ");
        int num=11;
        consultar(raiz, num);

        printf("\nImprimindo em preordem\n ");
        preordem(raiz);

        printf("\nImprimindo emordem\n ");
        emordem(raiz);

        printf("\nImprimindo em posordem\n ");
        posordem(raiz);

        printf("\nImprimindo bonitinho\n ");
        imprimirDeLado(raiz, 1);

	/*
      case '7':
      {
        if (raiz == NULL)
        {
          printf("\nImpossivel remover numero de uma Arvore VAZIA");
        }
        else
        {
          printf("\nDigite um numero: ");
          scanf("%i", &numero);
          achou = 0;
          printf("\nValor de raiz antes.: %p\n", raiz);
          procurarUmParaExcluir(&raiz, numero, &achou);
          printf("\nValor de raiz depois: %p\n", raiz);
          if(achou)
          {
            printf("\nO numero %d foi removido da arvore", numero);
          }
          else
          {
            printf("\nO numero %d NAO existe na arvore", numero);
          }
        }
        break;
      }
      case '8':
      {
        printf("\nDestruindo a arvore inteira: ");
        if (raiz == NULL)
        {
          printf("\nImpossivel destruir. Arvore VAZIA");
        }
        else
        {
          while(raiz != NULL)
	        {
	          excluir(&raiz);
          }
        }
        break;
      }
      */

        printf("\nAltura da Arvore:  ");
        printf("%i", devolveAltura(raiz));

  return 0;
} //  main

int devolveAltura (struct no *raiz)
{
   if (raiz == NULL)
      return 0; // altura de arvore vazia
   else
   {
      int he = devolveAltura(raiz->esq);
      int hd = devolveAltura(raiz->dir);
      if (he < hd)
        return hd + 1;
      else
        return he + 1;
   }
}

void insere(struct no **raiz, struct no *novo)
{
  if (*raiz == NULL)
  {
    *raiz = novo;
  }
  else
  {
    if(novo->item <= (*raiz)->item)
    {
      insere(&(*raiz)->esq, novo);
    }
    else
    {
      insere(&(*raiz)->dir, novo);
    }
  }
}

void consultar(struct no *raiz, int numero)
{
  if(raiz == NULL)
  {
    printf("\nO numero %d NAO existe na arvore", numero);
  }
  else
  {
    if(raiz->item == numero)
    {
      printf("\nO numero %d EXISTE na arvore", numero);
    }
    else
    {
      if(numero < raiz->item)
      {
        consultar(raiz->esq, numero);
      }
      else
      {
        consultar(raiz->dir, numero);
      }
    }
  }
}

void preordem(struct no *raiz)
{
  if (raiz != NULL)
  {
    printf("%d ", raiz->item);
    preordem(raiz->esq);
    preordem(raiz->dir);
  }
}

void emordem(struct no *raiz)
{
  if (raiz != NULL)
  {
    emordem(raiz->esq);
    printf("%d ", raiz->item);
    emordem(raiz->dir);
  }
}

void posordem(struct no *raiz)
{
  if (raiz != NULL)
  {
    posordem(raiz->esq);
    posordem(raiz->dir);
    printf("%d ", raiz->item);
  }
}


void imprimirDeLado(struct no *raiz, int espaco)
{
  int i;
  if (raiz != NULL)
  {
    imprimirDeLado(raiz->dir, (espaco+1));
    for(i = 0; i < espaco; i++)
    {
      printf("   ");
    }
    printf("%3d\n", raiz->item);
    imprimirDeLado(raiz->esq, (espaco+1));
  }
}

void procurarUmParaExcluir(struct no **raiz, int numero, int *achou)
{
  if((*raiz != NULL) && (*achou != 1))
  {
    if((*raiz)->item == numero)
    {
      *achou = 1;
      excluir (&(*raiz));
    }
    else
    {
      if (numero < (*raiz)->item)
      {
        procurarUmParaExcluir(&(*raiz)->esq,numero,&(*achou));
      }
      else
      {
        procurarUmParaExcluir(&(*raiz)->dir,numero,&(*achou));
      }
    }
  }
}

void excluir(struct no **raiz)
{
  struct no *aux;
  if((*raiz)->dir == NULL)
  {
    aux = *raiz;
    *raiz = (*raiz)->esq;
    free(aux);
  }
  else
  {
    if((*raiz)->esq == NULL)
    {
      aux = *raiz;
      *raiz = (*raiz)->dir;
      free(aux);
    }
    else // ambas as subarvores vazias
    {
      aux = (*raiz)->dir;
      while(aux->esq != NULL)
      {
        aux = aux->esq;
      }
      aux->esq = (*raiz)->esq;
      aux = *raiz;
      *raiz = (*raiz)->dir;
      free(aux);
    }
  }
}
