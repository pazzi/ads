/*
1) Apresente os fragmentos de código fonte que declarem as seguintes estruturas:
a) um array unidimensional de inteiros;
b) um array tridimensional de reais;
c) um array de strings;
d) um registro com 5 campos de tipos distintos;
e) um array bidimensional de registro com 5 campos distintos.
*/
#include <stdio.h>

int main(){
	int array1[10];
	float array2[3][4][5];
	char lista[10][50];
	struct registro
	{
		int campo1;
		float campo2;
		char campo3;
		char campo4[20];
		double campo5;
	};

	struct registro array[3][5];
}

