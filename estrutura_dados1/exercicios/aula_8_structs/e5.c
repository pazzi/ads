#include <stdlib.h>
#include <stdio.h>
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
	struct produto estoque[MAX] = {
		"Batata", 12.0, 23,
		"Cenoura", 34.0, 56,
		"Alho poroh", 78.0, 90,
		"Catuaba", 112.0, 34};
char opcao;
char umaDescricao[50];
int umaQuantidade;
int i;
do
{
    system("clear");
    puts("Controlinho de Estoque\n");
    printf("1. Inserir os %i produtos\n", MAX);
    puts("2. Retirada de produto");
    puts("3. Impressao do estoque");
    puts("X. Sair");
    puts("Digite sua opcao: ");
    scanf(" %c", &opcao);
    switch(toupper(opcao))
    {
      case '1': // inserir os produtos
	      {
	    	printf("\nInserção de produtos:");
		for (i = 0; i < MAX; i++)
		{
			getchar();
			printf("\nDigite a descricao do produto %i: ", i);
			gets(estoque[i].descricao);
			printf("\nDigite o preco do produto %i: ", i);
			gets(estoque[i].preco);
			printf("\nDigite a quantidade do produto %i: ", i);
			gets(estoque[i].quantidade);
		}
       		 break;
	      }
      case '2': // retirada de produto
	      {
    		printf("opcao2");
        	break;
	      }
      case '3': // impressao do estoque
	      {
	      	printf("Cheguei");
        	break;
	      }
      case 'X':
	      {
        	printf("\nSaindo...");
        	break;
	      }
      default:
	      {
	      	printf("Opcao invalida");
        	break;
	      }
    } 
}
while(toupper(opcao) != 'X');
getchar();
    return 0;
}
