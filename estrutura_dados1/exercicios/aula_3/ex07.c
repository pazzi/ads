/*EXERCÍCIOS PARA REVISAR COMANDOS DE SELEÇÃO
7. O restaurante LeChiqué contratou um barista para avaliar o café que é servido aos
clientes. A tarefa do barista é aprovar (ou não) o café com base em 2 critérios:
 Amargor: reprovado se for intenso (código ‘I’), aprovado em caso contrário.
 Aroma: aprovado se assemelhar-se a amêndoas (código ‘A’), nozes (código
‘N’) ou castanhas (código ‘C’), reprovado em caso contrário.
Construa um programa em linguagem C que auxilie a tarefa do barista. Deverão ser
lidos do teclado o Amargor e o Aroma de uma amostra de café e impresso na tela se
ela foi aprovada ou não.
*/
#include <stdio.h>

int main()
{
	char amargor;
	char aroma;
	while (1) 
	{
	printf("\nInforme o amargor do café [I-Intenso N-Não Intenso]: ");
	scanf("%c",&amargor);
	if ( amargor == 'N' || amargor == 'I')
		break;
	printf("\nInforme o Aroma do café [A-Amendoas N-Nozes C-Castanhas: ");
	scanf("%c",&amargor);
	}

	printf("\nRESULTADO: ");
}
