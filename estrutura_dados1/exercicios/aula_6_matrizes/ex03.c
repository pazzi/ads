/*
3. Construa um programa em linguagem C que execute as seguintes funcionalidades:
a) Declare uma matriz quadrada de inteiros de N linhas e N colunas.
b) Preencha essa matriz com dados lidos do teclado.
c) Imprima na tela a matriz obtida.
d) Inverta os dados armazenados na matriz segundo a regra: os dados acima e abaixo da
diagonal principal deverão trocar de lugar com seus respectivos correspondentes; os dados
armazenados na diagonal principal não deverão ser alterados.
e) Imprima na tela a matriz resultante. 
 * */
#include <stdio.h>
int main()
{
int i,j,n;
printf("\nInforme a dimensão da matriz quadrada: ");
scanf("%i", &n);
int matriz[n][n];
int matriz_inv[n][n];

for(i=0; i < n; i++)
{
	for(j=0; j<n; j++)
	{
		printf("\n Informe o valor para [%i][%i]", i,j);
		scanf("%i",&matriz[i][j]);

	}

}

for(i=0; i < n; i++)
{
	for(j=0; j<n; j++)
	{
		if(i == j)
		{
			matriz_inv[i][j]=matriz[i][j];
		}	
		else
		{
			matriz_inv[j][i]=matriz[i][j];
		}
	}
}


printf("\nOs valores eram:\n\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%3i\t", matriz[i][j]);
		}
		printf("\n");
	}

printf("\nOs valores ficaram:\n\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%3i\t", matriz_inv[i][j]);
		}
		printf("\n");
	}


}
