/*
 9. Construa um programa em linguagem, C que declare 1 array com 10 posições do tipo int
denominado oArray, o qual deverá ser preenchido com informações lidas do teclado. Em
seguida as suas informações deverão ser rearranjadas segundo a seguinte lógica: o valor
armazenado na posição 0 troca de lugar com o valor armazenado na posição 1, o valor
armazenado na posição 2 troca de lugar com o valor armazenado na posição 3, o valor
armazenado na posição 4 troca de lugar com o valor armazenado na posição 5, e assim por diante.
Ao final ele deverá ser impresso na tela.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
int oArray[10];
int i, valor;

	for (i=0; i < 10; i++)
	{
		printf("\nInforme o valor %i de 10 posição %i do array de dez: ",i+1, i);
		scanf(" %i",&oArray[i]);
	}

for (i=0; i < 10; i+=2)
{
	valor = oArray[i+1];
	oArray[i+1]=oArray[i];
	oArray[i] = valor;
}


for (i=0; i < 10; i++)
{
printf("\n\noArray[%i]=%i", i, oArray[i]);
}

}
