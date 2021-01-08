//Apresente o código fonte (somente as structs e o array) que implementaria o array meusPedidos representado no desenho abaixo.

#include <stdio.h>

int main()
{

	struct produto
	{
	  char codigo[4];
	  char descricao[40];
	  int quantidade;
	};

	struct pedido
	{
	  int numero;
	  char dia[3], mes[3], ano[5];
	  struct produto produtos[3];
	};

	struct pedido meusPedidos[4];
	return(0);
}
