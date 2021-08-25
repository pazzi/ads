#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <ncurses.h>

struct no
{
  char nome[30];
  struct no *proximo;
};

struct no *devolveNo()
{
  struct no *novo;
  novo = (struct no *) malloc(sizeof(struct no));
  printf("\nDigite um nome: ");
  fgets(novo->nome,30,stdin);
  novo->proximo = NULL;
  return(novo);
}

void insereNoInicio(struct no **inicio, struct no *novo)
{
  novo->proximo = *inicio;
  *inicio = novo;
}

void imprimeLista(struct no *inicio)
{
  struct no *aux;

  aux = inicio;
  while(aux != NULL)
  {
    printf("Nome: %s, Endere�o: %p, aponta para:%p\n", aux->nome, aux, aux->proximo);
    aux = aux->proximo;
  }
}

void insereNoFinal(struct no **inicio, struct no *novo)
{
  if(*inicio == NULL) ///est� vazia
  {
    insereNoInicio(&*inicio ,novo);
    ///*inicio = novo;
  }
  else
  {
    struct no *aux = (*inicio)->proximo;

    while(aux->proximo != NULL)
    {
      aux = aux->proximo;
    }
    aux->proximo = novo;
  }
}

 void insereNaSegundaPosicao(struct no **inicio, struct no *novo)
{
	if(*inicio == NULL) ///est� vazia
	{
           printf("N�o e possivel inserir na segunda posicao por que a lista est� vazia");
	}else {
		struct no *aux = (*inicio)->proximo;
		if(aux->proximo == NULL)
		{
			insereNoFinal(&*inicio, novo);
		}else{
			novo->proximo = (*inicio)->proximo;
			(*inicio)->proximo = novo;

		}

	}
}

void removeOPrimeiro(struct no **inicio){
	if(*inicio == NULL)
	{
		printf("A lista est� vazia");
	}
	else{
		struct no *aux = *inicio;
		*inicio=aux->proximo;
	}


}


int main()
{
  struct no *inicio;
  inicio = NULL; ///lista encadeada come�a vazia (zero n�s dentro dela)

  ///preparar o novo n�
  struct no *novo = NULL;

  ///inserir o novo n� dentro da lista
  novo = devolveNo();
  insereNoInicio(&inicio, novo);

  novo = devolveNo();
  insereNoInicio(&inicio, novo);

  novo = devolveNo();
  insereNoInicio(&inicio, novo);

  imprimeLista(inicio);

///  inser��o no final ???????????

  novo = devolveNo();
  insereNoFinal(&inicio, novo);

  novo = devolveNo();
  insereNoFinal(&inicio, novo);

  novo = devolveNo();
  insereNoFinal(&inicio, novo);

  imprimeLista(inicio);

///li��o de casa para 28/05

  novo = devolveNo();
  //tarefa 1
  insereNaSegundaPosicao(&inicio, novo);

  imprimeLista(inicio);

  //tarefa 2
  removeOPrimeiro(&inicio);
  printf("----------------------------------------------------\n");
  imprimeLista(inicio);
  ///free();

  return 0;

}
