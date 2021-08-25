#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>

#define MUSICAS 
#define LISTAS 
int i, quantidade;
double produto;

struct musica
{
	char titulo[50];
	char artista[50];
	float duracao;
};

struct musica
{
	char titulo[40];
	char artista[50];
	float duracao;
};

struct listaReproducao
{
	char nome[100];
	int quantidade;
	//int codigo;
};


int main(void)
{
	int opcao;
	void myflush( FILE *in );
	void mypause();
	void cadastraMusica(struct musica musicas[MUSICAS]);
	double obtemProduto(struct estoque lista[MAXESTOQUE]);
	int obtemQuantidade(void);
	void acertaEstoque(struct estoque lista[MAXESTOQUE],int descr, int quant);
	void listaEstoque(struct estoque lista[MAXESTOQUE]);

	struct musica musicas[MUSICAS];
	struct lista listas[LISTAS];

	do
	{
		system("clear");
		printf("\n\t\t\t\t ME N U  D E  O P C O E S\n\n");
		printf("\n\n\t\t\t\tI - Inserir música");
		printf("\n\n\t\t\t\tL - Criar Lista de Música");
		printf("\n\n\t\t\t\tR - Listar listas");
		printf("\n\n\t\t\t\tS - S A I R");
		printf("\n\n\t\t\t\t\tOpção==> ");
		scanf("\n%i", &opcao);
		switch (toupper(opcao))
		{
			case 1:
				{
					cadastraMusica(musicas);
					break;
				}
			case 2:
				{
					produto=obtemProduto(arrEstoque);
					produto= (int) produto;
					if (produto == -1)
					{
						printf("\n\nProduto não localizado no cadastro");
					} else
						{
							quantidade=obtemQuantidade();
							acertaEstoque(arrEstoque, produto, quantidade);
						}
					break;
				}
			case 3:
				{
					listaEstoque(arrEstoque);
					break;
				}
			case 0:
				{
					puts("\nSaindo.....");
					break;
				}
			default:
				{
					puts("\nOpção inválida");
					break;
				}
		}
	myflush(stdin);
	mypause();
	}while (opcao != 'S');
	return 0;
}


void cadastraMusica(struct musica musicas[MUSICAS])
{
	puts("\nCadastramento de musicas\n\n");
	for(i=0; i < MUSICAS; ++i)
	{
		printf("\nInforme o nome da música: ");
		scanf("%s",musica[i].titulo);
		setbuf(stdin,NULL);
		printf("\nInforme o artista: ");
		scanf("%s", &musica[i].artista);
		printf("\nInforme a duração: ");
		scanf("%f", &musica[i].duracao);
	}
}

double obtemProduto(struct estoque lista[MAXESTOQUE])
{
	char descricao[50];
	double ret=0;
	printf("\n\nInforme o produto que irá retirar: ");
	scanf("%s", descricao);
	setbuf(stdin, NULL);
	for(i = 0; i < MAXESTOQUE; i++)
 	{
 		if(strcmp(lista[i].descricao, descricao) == 0)
			{
				ret=(double)i;
				break;
			}
		else
		{
			ret=-1;
		}
	}
	return(ret);
}

int obtemQuantidade()
{
	int quant=0;
	do
	{
		printf("\n\nInforme a quantidade que irá retirar: ");
		scanf("%i", &quant);
		setbuf(stdin, NULL);
	} while (quant <=0);
	return(quant);
}

void acertaEstoque(struct estoque lista[MAXESTOQUE],int descr, int quant)
{
	if(quant <= lista[i].quantidade)
	{
		lista[i].quantidade-=quant;
		printf("\n\nA quantidade de %d unidades foi removida do produto %s", quant, lista[i].descricao); 
	}
	else
	{
		printf("\n\nNão foi possível remover %d unidades do produto %s - haviam %d unidades no estoque", quant, lista[i].descricao, lista[i].quantidade);
	}
}

void listaEstoque(struct estoque lista[MAXESTOQUE])
{
	system("clear");
	float valorTotal;
	printf("Descrição \t\tQuantidade \t\tPreco\n");
	for( i=0; i < MAXESTOQUE; ++i)
	{
		printf("%s  \t\t%i  \t\t\t%.2f \n", lista[i].descricao, lista[i].quantidade, lista[i].preco);
		valorTotal += lista[i].preco * lista[i].quantidade;
	}
	printf("\n-----------------------------------------------------");
	printf("\n\nValor total do estoque R$ %.2f\n\n", valorTotal);
}

void myflush(FILE *in)
{
  int ch;

  do
	ch = fgetc(in);
  while (ch != EOF && ch != '\n');

  clearerr(in);
}

void mypause(void)
{
  printf ("Aperte [Enter] para continuar . . .");
  fflush (stdout);
  getchar();
} 

