#include <stdio.h>
#include <stdlib.h>

int main(){
	system("clear");
	int mtx1[12];
	int mtx[3][4];
	int i,j,k,l=0;
	for (i=0; i <= 11; i++)
	{
		printf("\nInforme o valor %i de 12 posição %i do array de doze: ",i+1, i);
		scanf(" %i",&mtx1[i]);
	}

printf("\n\n");

	for (j=0; j < 3; j++)
	{
		l=j;
		for (k=0; k < 4; k++ )
		{
			mtx[j][k]=mtx1[l];
			l+=3;
		}
	}

printf("\n\n");

	for (i=0; i < 3; i++)
	{
		printf("\n Os valores do array %i sao :",  i+1);
		for ( j=0; j < 4; j++ )
		{
			printf("%i ", mtx[i][j]);
		}
	printf("\n");
	}
printf("\n\n");
}
