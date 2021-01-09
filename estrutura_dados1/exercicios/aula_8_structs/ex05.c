#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curses.h>

#define MAX 4
struct produto
{
  char descricao[50];
  float preco;
  int quantidade;
};

int main()
{
 void limparBuffer(void);
  struct produto estoque[MAX] = {
                                   "Batata", 12.0, 23,
                                   "Cenoura", 34.0, 56,
                                   "Alho porroh", 78.0, 90,
                                   "Catuaba", 112.0, 34
                                };
  char ch;
  char umaDescricao[50];
  int umaQuantidade;
  int opcao, i;
 do
  {
    system("clear");
    printf("\nControlinho de Estoque\n");
    printf("\n1. Inserir os %i produtos", MAX);
    printf("\n2. Retirada de produto");
    printf("\n3. Impressao do estoque");
    printf("\n0. Sair");
    printf("\n\nDigite sua opcao: ");
    scanf("%i", &opcao);
    limparBuffer();
    switch(opcao)
    {
      case 1: /* inserir os produtos */
      {
        puts("\nInsercao dos produtos");

        for(i = 0; i < MAX; i++)
       {
         getchar();
          printf("\nDigite a descricao do produto %i: ", i);
          gets(estoque[i].descricao);
          printf("\nDigite o preco do produto %i: ", i);
          scanf("%f", &estoque[i].preco);
          printf("\nDigite a quantidade do produto %i: ", i);
          scanf("%i", &estoque[i].quantidade);
        }
        break;
      }
      case 2: /* retirada de produto*/
      {
        char umaDescricao[50]="";
        int umaQuantidade;
        int existe, suficiente;
        printf("\nRetirada dos produtos");
        printf("\nDigite a descricao do produto a ser retirado: ");
        fgets(umaDescricao,50, stdin);
	strtok(umaDescricao, "\n");
//	limparBuffer();
/*	
	if(strlen(umaDescricao) == 49)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
	}
	*/

        do
        {
          printf("\nDigite a quantidade a ser retirada do produto: ");
          scanf(" %i", &umaQuantidade);
        }
        while(umaQuantidade <= 0);

        existe = 0; /* falso que existe*/
        suficiente = 0;  /*falso que eh suficiente*/
        for(i = 0; i < MAX && !existe; i++)
        {
          if(strcmp(estoque[i].descricao, umaDescricao) == 0) /* achou a descircao do produto no estoque*/
          {
            existe = 1; /* verdadeiro que existe */
            if(umaQuantidade <= estoque[i].quantidade)
            {
              suficiente = 1; /* verdadeiro que a quantidade eh suficiente para retirada */
              estoque[i].quantidade-=umaQuantidade;
            }
          }
        } /* for */

	limparBuffer(); 
        if(!existe)
        {
          printf("\nO produto %s nao existe no estoque!", umaDescricao);
        }
        else
        {
          if(!suficiente)
          {
            printf("\nA quantidade do produto %s nao eh suficiente para permitir a retirada de %i itens!", umaDescricao, umaQuantidade);
          }
          else
          {
            printf("\nA retirada de %i itens do produto %s foi realizada com sucesso.", umaQuantidade, umaDescricao);
          }
        }
	getchar();
        break;
      }

      case 3:
      {
        float valorTotal = 0;
        printf("\nImpressao do estoque");
        for(i = 0; i < MAX; i++)
        {
          printf("\n\nDescricao do produto: %s", estoque[i].descricao);
          printf("\nPreco do produto: R$ %.2f", estoque[i].preco);
          printf("\nQuantidade do produto : %i itens", estoque[i].quantidade);
          valorTotal += (estoque[i].preco * estoque[i].quantidade);
        }
        printf("\n\nValor total do estoque: R$ %.2f\n", valorTotal);
	getchar();
        break;
      }

      case 0:
      {
        puts("\nSaindo...");
        break;
      }
      default:
      {
        puts("\nOpcao i n v a l i d a!\n");
      }
    } /* switch */
    printf("\n");
    
  }
  while(opcao != 0);
   
return 0;
}

void limparBuffer(void)
{
	char caracter;
	while ((caracter = getchar()) != '\n' && caracter != EOF);

}
