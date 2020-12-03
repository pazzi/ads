#include <stdio.h>
#include <stdlib.h>

int main(){
	system("clear");
	int mtx1[12];
	int mtx2[12];
	int mtx3[12];
	int vl,i,j,m,n=0;
	for (i=0; i <= 11; i++)
	{
		printf("\nInforme o valor %i de 12 posição %i do array de doze: ",i+1, i);
		scanf(" %i",&vl);
		mtx1[i]=vl;
	}

printf("\n\n");

	for (j=0; j <= 11; j++)
	{
		if (mtx1[j] > 0)
		{
			mtx2[j]=mtx1[j];
			mtx3[j]=0;
			m++;

		}else{
			mtx3[j]=mtx1[j];
			mtx2[j]=0;
			n++;
		}

	}

printf("\n\n");
printf("O array 1 terá %i valores: ", m);

	for (i=0; i <= 11; i++)
	{
		if (mtx2[i] != 0)
			printf("%i ",  mtx2[i]);
	}
printf("\n\n");
printf("O array 2 terá %i valores: ", n);
	for (i=0; i <= 11; i++)
	{
		if (mtx3[i] != 0)
			printf("%i ",  mtx3[i]);
	}
printf("\n\n");
}
