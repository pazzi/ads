/*1. Construa um programa em linguagem C que imprima na tela o caractere ‘A’ . Em seguida
imprima o número da tabela ASCII que corresponde ao ‘A’ e depois o valor hexadecimal
que que equivale ao ‘A’ . Faz a mesma coisa para o caractere ‘a’ .
*/

#include <stdio.h>
void mostra_caracter(char letra)
{
	printf("Impressões do caracter %c\n\n", letra);
	printf("O caracter pp dito:%c\n",letra);
	printf("O correspondente decimal:%d\n",letra);
	printf("O correspondente em octal:%o\n",letra);
	printf("O correspondente em hexadecimal:%X\n\n",letra);
}
int main()
{
	char valor;
	valor='A';
	mostra_caracter(valor);
	valor='a';
	mostra_caracter(valor);
}

