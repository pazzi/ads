#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>

int main()
{
	bool verificaSenha(char senha[9]);
	char senha[9];
	printf("\nInforme a senha: ");
	/*scanf("%s", senha);*/
	fgets(senha,9,stdin);
        setbuf(stdin,NULL);
	printf("%s", senha);
	if(verificaSenha(senha))
	{
		printf("\nSenha Válida");
	}
	else
	{

		printf("\nSenha inválida");
	}

	return 0;
}

bool verificaSenha(char senha[9])
{
/*Maiuscula 65 até 90 pelo menos 1
Numeros 48 a 57 - pelo menos 2*/
int contaNumero=0;
int contaMaiuscula=0;
int x=0;
for(x=0; x<strlen(senha); x++)
	{
		/* Somente os caracteres cujo valor ASCII represente um digito numerico */
		if(senha[x] >= 48 && senha[x] <= 57)
		{
			contaNumero++;
		}
		/* Somente os caracteres cujo valor ASCII represente um caracter Maiusculo */
		if(senha[x] >= 65 && senha[x] <=90)
		{
			contaMaiuscula++;
		}
	}
if (x <= 8 && contaNumero >=2 && contaMaiuscula >=1)
{
	return true;
}
else{
	return false;
}
}
