#include <stdio.h>

void bolha(int v[], int tam){
	int ult, i, aux;
	for (ult = tam-1; ult>0; ult--)
	{
		for(i=0; i<ult; i++)
		{
			if (v[i] > v[i+1])
			{
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;

			}
		}
	}
}

int main(){

	int i;
	int v[] = {55, 0, -78, -4, 32, 200, 52, 63, 69, 125};
	bolha(v,10);
	for(i=0;i<10;i++)
	{
		printf("%i ",v[i]);
	}
	printf("\n");

	return 0;
}
