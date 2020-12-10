/*
1. Construa um programa em linguagem C que execute as seguintes funcionalidades:
a) declare 3 matrizes de inteiros, cada uma com 3 linhas e 4 colunas, denominadas matriz1, matriz2
e matriz3.
b) armazene valores inteiros digitados pelo usuário em cada uma das células da matriz1.
c) armazene valores inteiros digitados pelo usuário em cada uma das células da matriz2.
d) a seguir multiplique cada uma das células da matriz1 pela célula correspondente da matriz2,
armazenando o resultado na célula correspondente da matriz3.
O esquema a seguir auxilia na compreensão das funcionalidades esperadas:
*/
#include <stdio.h>
#define LINHA 3
#define COLUNA 4

int main(){
int matriz1[LINHA][COLUNA];
int matriz2[LINHA][COLUNA];
int matriz3[LINHA][COLUNA];
int i,j;
for (i=0; i<LINHA; i++)
{
	for (j=0; j<COLUNA; j++)
	{
		printf("\nInsira um valor para a matriz1[%i][%i]", i,j);
		scanf("%i", &matriz1[i][j]);
		printf("\nInsira um valor para a matriz2[%i][%i]", i,j);
		scanf("%i", &matriz2[i][j]);
	}
}
for (i=0; i<LINHA; i++)
{
	for (j=0; j<COLUNA; j++)
	{
		matriz3[i][j] = matriz1[i][j] * matriz2[i][j];
	}
}
	printf("\nOs valores em matriz3 são:\n\n");
	for (i=0; i<LINHA; i++)
	{
		for (j=0; j<COLUNA; j++)
		{
			printf("%3i\t", matriz3[i][j]);
		}
		printf("\n");
	}

}

