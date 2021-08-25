#include <stdio.h>

int posMenorEl(int v[], int tam, int inicio){

	int i, posMenor;
	posMenor = -1;
	if((inicio >=0) && (inicio <tam)){
		posMenor = inicio;
		for(i=inicio+1; i<tam; i++)
		{
			if(v[i] < v[posMenor]) posMenor = i;
		}
	}
	return(posMenor);
}

void selecao(int v[], int tam){
	int i, posMenor, aux;
	for (i = 0; i<tam-1; i++)
	{
		posMenor=posMenorEl(v,tam,i);
		aux = v[i];
		v[i] = v[posMenor];
		v[posMenor] = aux;
	}
}

int main(){

	int i;
	int v[] = {55, 0, -78, -4, 32, 200, 52, 63, 69, 125};
	selecao(v,10);
	for(i=0;i<10;i++)
	{
		printf("%i ",v[i]);
	}
	printf("\n");

	return 0;
}
