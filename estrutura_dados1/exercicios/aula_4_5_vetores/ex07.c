#include <stdio.h>
#include <stdlib.h>

int main(){
	system("clear");
	int mtx1[12], mtx2[12], mtx3[12];
	int i,indicePositivo, indiceNegativo=0;
	for (i=0; i < 12; i++)
	{
		printf("\nInforme o valor %i de 12 posição %i do array de doze: ",i+1, i);
		scanf(" %i",&mtx1[i]);
	}

printf("\n\n");

	for (i=0; i < 12; i++)
	{
		if (mtx1[j] >= 0)
		{
			mtx2[indicePositivo]=mtx1[j];
			indicePositivo++;

		}else{
			mtx3[indiceNegativo]=mtx1[j];
			indiceNegativo++;
		}
	}

printf("\n\n");
printf("O array 1 terá %i valores: ", m);

	for (i=0; i < indicePositivo; i++)
	{
		if (mtx2[i] != 0)
			printf("%i ",  mtx2[i]);
	}
printf("\n\n");
printf("O array 2 terá %i valores: ", n);
	for (i=0; i < indiceNegativo; i++)
	{
		if (mtx3[i] != 0)
			printf("%i ",  mtx3[i]);
	}
printf("\n\n");
}
