#include <stdio.h>

int main(){
int ante, anteAnte,numero,i;
anteAnte=0;
ante=1;
	for(i=1; i<=25; i++)
	{
		printf("\n %i",anteAnte);
		numero=ante+anteAnte;
		anteAnte=ante;
		ante=numero;
	}
}
