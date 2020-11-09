/*4. A equação ax 2 + bx + c = 0 é resolvida pelo método de Báskara que calcula x’ e x’’ a partir
dos valores de a , b e c . Construa um programa em linguagem C que leia do teclado os
valores para a , b , e c , depois calcule e imprima na tela os valores de x’ e x’’ .
*/
#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, delta ;
	printf("\nInforme o valor do termo a: ");
	scanf("%f", &a);
	printf("\nInforme o valor do termo b: ");
	scanf("%f", &b);
	printf("\nInforme o valor do termo c: ");
	scanf("%f", &c);
	delta=pow(b,2) - 4 * a * c;
	if (delta > 0)
	{
		printf("\nO valor de x' é %f: ", ((-b + sqrt(delta))/2 * a) );
		printf("\nO valor de x'' é %f: ", ((-b - sqrt(delta))/2 * a) );
	}
	if (delta = 0)
	{
		printf("\nO valor de x'' é %f: ", -b /2 * a);
	} else{
		printf("\nNão existem raízes reais para a equação");
	}

}
