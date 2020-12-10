/*
 2. Faça um programa que calcule a média dos elementos da diagonal principal e da diagonal
secundária de uma matriz 5 x 5 de números inteiros (são 5 linhas e 5 colunas)
*/
#include <stdio.h>
#define VALOR 5
int main(){

int matriz[VALOR][VALOR];
int i,j;
double principal,secundaria;

for(i=0; i<VALOR; i++)
{

	for(j=0; j<VALOR; j++)
	{
		printf("\nInforme o valor para a posição [%i][%i]",i,j);
		scanf("%i",&matriz[i][j]);
	}
}

for(i=0; i<VALOR; i++)
{

	for(j=0; j<VALOR; j++)
	{
		if(i==j)
		{
			principal+=matriz[i][j];
		}
		if(i+j==4)
		{
			secundaria +=matriz[i][j];
		}
	}
}
printf("\nA média da diagonal principal é %.2f", principal/VALOR);
printf("\nA média da diagonal secundária é %.2f", secundaria/VALOR);
}
