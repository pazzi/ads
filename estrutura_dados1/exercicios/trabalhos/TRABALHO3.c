#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>

#define MAXESTOQUE 2
int i, quantidade;
double produto;

struct estoque
{
	char descricao[50];
	float preco;
	int quantidade;
};

int main(void)
{
	int opcao;
	void myflush( FILE *in );
	void mypause();
	void cadastraEstoque(struct estoque lista[MAXESTOQUE]);
	double obtemProduto(struct estoque lista[MAXESTOQUE]);
	int obtemQuantidade(void);
	void acertaEstoque(struct estoque lista[MAXESTOQUE],int descr, int quant);
	void listaEstoque(struct estoque lista[MAXESTOQUE]);

	struct estoque arrEstoque[MAXESTOQUE];

	do
	{
		system("clear");
		printf("\n\t\t\t\tE S T O Q U E   D E  M A N T I M E N T O S\n\n");
		printf("\n\t\t\t\t--------A d m i n i s t r a ç ã o --------\n");
		printf("\n\n\t\t\t\t1 - Adicionar items ao estoque");
		printf("\n\n\t\t\t\t2 - Remover items do estoque");
		printf("\n\n\t\t\t\t3 - Listar o  estoque");
		printf("\n\n\t\t\t\t0 - S A I R");
		printf("\n\n\t\t\t\t\tOpção==> ");
		scanf("\n%i", &opcao);
		switch (opcao)
		{
			case 1:
				{
					cadastraEstoque(arrEstoque);
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
	}while (opcao != 0);
	return 0;
}


void cadastraEstoque(struct estoque lista[MAXESTOQUE])
{
	puts("\nCadastramento de produtos no estoque\n\n");
	for(i=0; i < MAXESTOQUE; ++i)
	{
		printf("\nInforme a descrição do produto: ");
		scanf("%s",lista[i].descricao);
		setbuf(stdin,NULL);
		printf("\nInforme o preço do produto: ");
		scanf("%f", &lista[i].preco);
		printf("\nInforme a quantidade do produto: ");
		scanf("%i", &lista[i].quantidade);
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

