#include "stdio.h"

int totalDeTrocas;
int totalDeComparacoes;

// Troca de valores entre duas posicoes
void trocaValores(int *var1, int *var2)
{
	int temp;
	temp = *var1;
	*var1 = *var2;
	*var2 = temp;

	totalDeTrocas++;
}

// Exibicao da matriz
void exibeVetor(int vetor[], int numeroDeElementos)
{
	int x;

//	printf("\n ");
	for(x=0; x<numeroDeElementos; x++)
	{
		printf("%d ", vetor[x]);
	}
}

void quickSort(int vetor[], int esquerda, int direita)
{
	int x, y, meio;

	x = esquerda;
	y = direita;

	meio = vetor[(esquerda+direita)/2];

	do
	{
		while(vetor[x] < meio && x<direita)
		{
			x++;
			printf("\nDireita -> ");
			exibeVetor(vetor, 10);
		}

		while(meio<vetor[y] && y>esquerda)
		{
			y--;
			printf("\nEsquerda -> ");
			exibeVetor(vetor, 10);
		}

		totalDeComparacoes++;
		if(x<=y)
		{
			printf("\nTroca -> ");
			trocaValores(&vetor[x], &vetor[y]);
			exibeVetor(vetor, 10);

			x++;
			y--;
		}

	} while(x<=y);

	if(esquerda<y)
	{
		quickSort(vetor, esquerda, y);
	//	exibeVetor(vetor, 10);
	}

	if(x<direita)
	{
		quickSort(vetor, x, direita);
	//	exibeVetor(vetor, 10);
	}

}

int main()
{
	char *c;
	
	int vetorB[10] = {32,40,15,6,10,95,13,21,33,50};
	int numeroDeElementos = 10;
	int buscarPor;
	int posicao;

	// Quicksort
	totalDeTrocas = 0;
	totalDeComparacoes = 0;
	exibeVetor(vetorB, numeroDeElementos);
	quickSort(vetorB, 0, numeroDeElementos-1);
//	exibeVetor(vetorB, numeroDeElementos);
	printf("\n %d comparacoes, %d trocas, %d operacoes", totalDeComparacoes, totalDeTrocas, totalDeComparacoes+totalDeTrocas);

	return 0;
}


