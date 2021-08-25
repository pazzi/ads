#include <stdio.h>
#include <stdlib.h>
int main()

{
	char opcao; //opcao escolhida pelo usuario
	do
	{
		system("clear");
		printf("\nMenu de Opcoes");
		printf("\nI. Inserir música");
		printf("\nL. Criar lista de reproducao");
		printf("\nR. Imprime relatório de músicas");
		printf("\S. Sair");
		fflush(stdin);
		printf("\nDigite sua opcao: ");
		opcao = getchar();

	} while( toupper(opcao) != 'S');


	return 1;
}
