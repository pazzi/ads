#include <stdio.h>
#include <stdlib.h>

int main(){
	system("clear");
	int mtx[10];
	int i, vl;
	for (i=0; i <= 9; i++)
	{
		if(i == 0)
		{
			printf("\nInforme o valor inicial positivo da matriz: ");
			scanf(" %i",&vl);
			mtx[i]=vl;
		}
		else{
			if (i % 2 == 0)
			{
				mtx[i] = vl;
			}else{
				mtx[i] = -vl;
			}
		}
	}
	for (i=0; i <= 9; i++)
	{
		printf("\n A matriz na posicao %i é :%i",  i, mtx[i]);
	}
printf("\n\n");
}
