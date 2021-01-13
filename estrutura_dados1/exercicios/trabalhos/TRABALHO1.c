#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
	void imprimeCNPJ(char str[], int i);
        char cnpj[19];
        int x;

	system("clear");
        printf("Informe o CNPJ formato[xx.xxx.xxx/000Y-ZZ]: ");
        fgets(cnpj,19,stdin);
        setbuf(stdin,NULL);

	if (strlen(cnpj) == 18)
		{
			if (cnpj[2] != '.') 
			{
				printf("\n ERRO - Um ponto devera vir após digitar ");
				imprimeCNPJ(cnpj,1);

			}else
			{
				if(cnpj[6] != '.')
				{
					printf("\nERRO - Um ponto deverá vir após digitar xx.xxx");
					imprimeCNPJ(cnpj,5);
				}
				else{
					if(cnpj[10] != '/')
					{
						printf("\nERRO - uma / deverá vir após a entrada xx.xxx.xx");
						imprimeCNPJ(cnpj,9);
					}else
					{
						if (cnpj[15] != '-')
						{
							printf("\nERRO - um - deverá vir após a entrada xx.xxx.xxx/xxxx");
						}
						else
							if( (cnpj[11] !='0') || (cnpj[12] !='0') || (cnpj[13] !='0') )
							{
								printf("\nERRO: Os 3 dígitos após a barra deverão ser 0");
								imprimeCNPJ(cnpj,9);
							}
							else	
								{
									printf("\nDigitação correta para o CNPJ ");
									imprimeCNPJ(cnpj,18);
							}

						}

					}
				}
			}
		else	
		{
			printf("\n CNPJ digitado deverá ter 18 caracteres");
		}

	printf("\n\n\n ---------------------------------------------------------\n\n");

        return 0;
}

void imprimeCNPJ(char str[], int i){
	int j=0;
	for (j=0; j <= i; j++)
	{
		printf("%c", str[j]);
	}
}

