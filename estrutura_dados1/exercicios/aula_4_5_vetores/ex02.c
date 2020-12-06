#include <stdio.h>
#include <stdlib.h>

int main(){
	system("clear");
	int mtx[8];
	int i;
	for (i=0; i < 8; i++)
	{
		if(i == 0)
		{
			printf("\nInforme o valor inicial da matriz: ");
			scanf(" %i",&mtx[i]);
		}
		else{
			mtx[i] = mtx[i-1] * i;
		}
	}
	for (i=0; i < 8; i++)
	{
		printf("\n A matriz na posicao %i é :%i",  i, mtx[i]);
	}
printf("\n\n");
}
