#include <stdio.h>
#include <stdlib.h>

int main(){
	system("clear");
	int mtx[10];
	int i, vl;
	for (i=0; i < 10; i++)
	{
		if(i == 0)
		{
			printf("\nInforme o valor inicial positivo da matriz: ");
			scanf(" %i",&mtx[i]);
			mtx[i]=vl;
		}
		else{
			if (i % 2 == 0)
			{
				mtx[i] = mtx[0];
			}else{
				mtx[i] = -mtx[0];
			}
		}
	}
	for (i=0; i < 10; i++)
	{
		printf("\n A matriz na posicao %i é :%i",  i, mtx[i]);
	}
printf("\n\n");
}
