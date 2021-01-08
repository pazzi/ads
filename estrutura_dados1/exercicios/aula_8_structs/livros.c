#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
struct lista{
	char titulo[30];
	char autor[30];
	int regnum;
	double preco;
};

struct lista livro[50];
int n=0;
int main()
{
	system("clear");
	char ch;
	while(1)
	{
		printf("\nDigite 'e' para adicionar um livro");
		printf("\n'l' para listar todos os livros: ");
		scanf("%c",&ch);
		if (ch =='e')
		{
			printf("Novonome");
		}
		else if(ch == 'l')
		{
			printf("Listar");
		}
		else
		{
			puts("\nDigite somente opcoes validas");
		}
	}
return 0;
}
