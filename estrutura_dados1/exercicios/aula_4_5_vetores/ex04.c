#include <stdio.h>
#include <stdlib.h>

int main(){
	system("clear");
	int mtx1[10];
	int mtx2[10];
	int mtx3[10];
	int i, vl;
	for (i=0; i < 10; i++)
	{
		printf("\nInforme o valor %i de 10 para o array 1: ",i+1);
		scanf(" %i",&mtx1[i]);
	}

printf("\n\n");

	for (i=0; i < 10; i++)
	{
		printf("\nInforme o valor %i de 10 para o array 2: ",i+1);
		scanf(" %i",&mtx2[i]);
	}
	for (i=0; i <= 9; i++)
	{
		if (mtx1[i] > mtx2[i])
		{
			mtx3[i] = mtx1[i];
		}else {
			mtx3[i] = mtx2[i];
		}
	}

printf("\n\n");

	for (i=0; i < 10; i++)
	{
		printf("\n O valor do array 3[%i] é :%i ",  i, mtx3[i]);
	}
printf("\n\n");
}
