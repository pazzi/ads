/*1. Construa uma função em linguagem C que receba três parâmetros: um
ponteiro inicio1 (por valor) para uma LLSE de valores inteiros, um ponteiro
inicio2 (por valor) para uma LLSE de valores inteiros e um ponteiro inicio3
(por referência) que aponta para uma LLSE vazia. A função deverá executar a
operação de UNIÃO (como definida na teoria dos conjuntos) entre as listas
apontadas por inicio1 e inicio2, guardando o resultado na lista apontada
por inicio3. Para recordar, a união de conjuntos corresponde a junção dos
elementos dos conjuntos dados, ou seja, é o conjunto formado pelos elementos
de um conjunto mais os elementos dos outros conjuntos. */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>

struct no
{
  int valor;
  struct no *proximo;
};

typedef struct no No;


void insereNoInicio(No **inicio, No *novo)
{
  novo->proximo = *inicio;
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
    while(aux->proximo != NULL)
    {
      aux = aux->proximo;
    }
    aux->proximo = novo;
  }
}

void imprime(No *inicio)
{
  int i = 1;
  while(inicio != NULL)
  {
    printf(" [%i] ", (*inicio).valor);
    inicio = (*inicio).proximo;
  }
}

long int contaLista( struct no *inicio ) {
  long int count = 0;

  while( inicio != NULL ) {
         count++;
         inicio = inicio->proximo;
  }
  return count;
}

void ordenar(No **inicio)
{
  No *aux1, *aux2, *qualSaiu, *inicioAuxiliar = NULL;
  if(*inicio != NULL)
  {
    if((*inicio)->proximo == NULL)
    {
      printf("\nImpossivel ordenar. A lista tem somente um elemento.");
    }
    else
    {
      while(*inicio != NULL)
      {
        qualSaiu = *inicio;
        *inicio = (*inicio)->proximo;
        qualSaiu->proximo = NULL;
        if(inicioAuxiliar == NULL)
        {
          inicioAuxiliar = qualSaiu;
        }
        else
        {
          if(inicioAuxiliar->valor >  qualSaiu->valor) ///insere no inicio de inicioAuxiliar
          {
            qualSaiu->proximo = inicioAuxiliar;
            inicioAuxiliar = qualSaiu;
          }
          else
          {
            aux1 = inicioAuxiliar;
            aux2 = inicioAuxiliar->proximo;
            while((aux2 != NULL) && (qualSaiu->valor > aux2->valor))
            {
              aux1 = aux2;
              aux2 = aux2->proximo;
            }
            aux1->proximo = qualSaiu;
            qualSaiu->proximo = aux2;
          }
        }
      }
      *inicio = inicioAuxiliar;
    }
  }
  else
  {
    printf("\nImpossivel ordenar. Lista vazia.");
  }
}

No *devolveNo(int valor)
{
  No *novo;
  novo = (No *) malloc(sizeof(No));
  if(novo != NULL)
  {
    novo->valor = valor;
    novo->proximo = NULL;
  }
  else
  {
    puts("\n E R R O   C A T A S T R O F I C O !!");
  }
  return(novo);
}

void inverterAListaProfissional(No **inicio)
{
  No *p1, *p2, *p3;
  if((*inicio != NULL) && ((*inicio)->proximo != NULL))
  {
    p1 = NULL;
    p2 = *inicio;
    p3 = (*inicio)->proximo;
    while(p2 != NULL)
    {
      p2->proximo = p1;
      p1 = p2;
      p2 = p3;
      if(p3 != NULL)
      {
        p3 = p3->proximo;
      }
    }
    *inicio = p1;
  }
}

struct no* proximoElemento( No *inicio, long int pos ) {
   long int count = 0;
 
   while( count < pos ) {
         inicio = inicio->proximo;
         count++;
   }

   return inicio;
}

void quickSort( No *inicio, long int tam ) {
     long int posesq = 0;
     long int posdir = tam - 1;
     long int pivo = proximoElemento( inicio, tam / 2 )->valor;

     do{
          while( proximoElemento( inicio, posesq )->valor < pivo ) posesq++;
          while( proximoElemento( inicio, posdir )->valor > pivo ) posdir--;

          if( posdir >= posesq ) {
               long int aux = proximoElemento( inicio, posesq )->valor;
               proximoElemento( inicio, posesq )->valor  = proximoElemento( inicio, posdir )->valor;
               proximoElemento( inicio, posdir )->valor = aux;
               posdir--;
               posesq++;
          }
     }while( posdir >= posesq );

     if( posdir ) {
          quickSort( inicio, posdir + 1 );
     }

     if( posesq < tam - 1 ) {
          quickSort( proximoElemento( inicio, posesq ), tam - posesq );
     }
}

void insert(struct no **inicio, int valorNovo)
{
    No *novoNo;
    novoNo = (No *) malloc(sizeof(No));
    novoNo->valor = valorNovo;
    novoNo->proximo = (*inicio);
    (*inicio) = novoNo;
}

void faz_Uniao(struct no *inicio1, struct no *inicio2, struct no **inicio3 )
{
    No *t1 = inicio1, *t2 = inicio2;

    while (t1 != NULL && t2 != NULL)
    {

        if (t1->valor < t2->valor)
        {
            insert(&*inicio3, t1->valor);
            t1 = t1->proximo;
        }

        else if (t1->valor > t2->valor)
        {
            insert(&*inicio3, t2->valor);
            t2 = t2->proximo;
        }
        else
        {
            insert(&*inicio3, t2->valor);
            t1 = t1->proximo;
            t2 = t2->proximo;
        }
	
    }

    while (t1 != NULL)
    {
        insert(&*inicio3, t1->valor);
        t1 = t1->proximo;
    }

    while (t2 != NULL)
    {
        insert(&*inicio3, t2->valor);
        t2 = t2->proximo;
    }
}

void remove_duplicados(No **inicio){
    No *anterior, *corrente, *seguinte;

    for(corrente = *inicio; corrente != NULL; corrente = corrente -> proximo ){
        anterior = NULL;

        for(seguinte = corrente -> proximo; seguinte != NULL; ){
            if(corrente -> valor == seguinte -> valor){
                if(anterior == NULL)
                    corrente -> proximo = seguinte -> proximo;
                else
                    anterior -> proximo = seguinte -> proximo;

                No *remover = seguinte;
                seguinte = seguinte -> proximo;
                free(remover);
            }
            else {
                anterior = seguinte;
                seguinte = seguinte->proximo;
            }
        }
    }
}

int main()
{
  int long tam;
  int i, numero;
  No *novo, *inicio1 = NULL, *inicio2 = NULL, *inicio3 = NULL;

  int lista1[8] ={3,4,5,8,7,1,9,3};
  int lista2[6] ={9,2,6,7,13,15};

  for(i = 0; i < 8; i++)
  {
    novo = devolveNo(lista1[i]);
    insereNoFinal(&inicio1, novo);
  }

  for(i = 0; i < 6; i++)
  {
    novo = devolveNo(lista2[i]);
    insereNoFinal(&inicio2, novo);
  }
  system("clear");
  printf("--------------------------------------------------------------------------\n");
  printf("           Questao 1 - Uniao de 2 conjuntos\n");
  printf("--------------------------------------------------------------------------\n");

 
  tam=contaLista(inicio1);
  printf("\nLista 1 \n");
  imprime(inicio1);

  quickSort(inicio1,tam );
  printf("\n\nLista1 apos o quicksort\n");
  imprime(inicio1);
  printf("\n\nItens na lista1: %ld\n",contaLista(inicio1));

  printf("\n\n\nLista 2 \n");
  imprime(inicio2);

  tam=contaLista(inicio2);
  quickSort(inicio2,tam );
  printf("\n\nLista2 apos quicksort\n");
  imprime(inicio2);
  printf("\n\nItens na lista2: %ld\n",contaLista(inicio2));

  printf("\n\n\nInpressao pos uniao\n");
  faz_Uniao( inicio1, inicio2, &inicio3);
  ordenar(&inicio3);
  imprime(inicio3);
  printf("\n\nItens na lista3: %ld\n",contaLista(inicio3));
  printf("\n\n\nResultado da Uniao apos remocao dos duplicados da Lista3\n\n");
  remove_duplicados(&inicio3);
  imprime(inicio3);
  printf("\n\nTotal de elementos apos eliminar duplicados: %ld\n",contaLista(inicio3));
  printf("\n\n\n --------------------------------F I M-------------------------------------------\n\n");

  free(inicio1);
  free(inicio2);
  free(inicio3);

  inicio1=NULL;
  inicio2=NULL;
  inicio3=NULL;
  return 0;
}
