/*A CFPL planeja instalar postes de iluminação em toda a extensão da Av. Ênio Pires de Camargo espaçados 60 metros entre si e, por isso, contratou um topógrafo
  para fazer as medições e fincar estacas exatamente nos locais onde os postes deverão ser instalados. Todos os postes serão equipados com lâmpadas de vapor 
  sódio e, a cada 12 postes, um deles também será equipado com um transformador de energia. Construa um programa em linguagem C para auxiliar o trabalho do 
  topógrafo a estabelecer onde os postes e os transformadores serão instalados. O programa deverá ler do teclado o comprimento total (em metros) da avenida e
  imprimir na tela a localização exata (também em metros) de todos os postes e transformadores. Ao final também deverá ser impressa na tela a quantidade total
  de postes e de transformadores que deverá ser comprada.
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("clear");
	int i, distancia;
	fflush(stdin);
	printf("Informe o comprimento do local em metros: ");
	scanf(" %d", &distancia);
	for(i=60; i <= distancia; i+=60)
		{
			printf("\nPoste a %dm  do marco 0", i);
			if (i%720==0)
				printf(".......Neste local deverá ser instalado um transformador");
		}
	printf("\n\nR E S U M O:");
	printf("\nLocalidade com %dm de distancia", distancia);
	printf("\nSerão necessários %d postes", abs(distancia/60));
	printf("\nSerão necessários %d transformadores\n\n", abs(distancia/720));

}
