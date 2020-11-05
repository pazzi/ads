/*2. Construa um programa em linguagem C que imprima na tela a quantidade de bytes
ocupados na memória por cada uma das variáveis a seguir:
char a ;
int b ;
float c ;
double d ;
*/
#include <stdio.h>

int main()
{
	char a;
	int b;
	float c;
	double d;
	printf("Quantidade de bytes em memória ocupados por variáveis:\n");
	printf("Variáveis char  - %ld bytes\n",sizeof(a));
	printf("Variáveis int   - %ld bytes \n",sizeof(b));
	printf("Variáveis float - %ld bytes\n",sizeof(c));
	printf("Variáveis double- %ld bytes\n",sizeof(d));
	return 0;
}
