/*5. Um algoritmo bastante comum é o que troca os valores entre duas variáveis como, por
exemplo, o que está apresentado a seguir:
#include <stdio.h>
main()
{
int umValor = 10, outroValor = 20;
int auxiliar;
auxiliar = umValor;
umValor = outroValor;
outroValor = auxiliar;
}
No entanto, existe um método que possibilita a troca sem a utilização de uma variável auxiliar
(apenas as variáveis umValor e outroValor são necessárias). Pesquise, descubra qual é este
método e construa um programa em linguagem C para demonstrar o seu funcionamento.
*/

#include <stdio.h>
int main()
{
//	int umValor = 10, outroValor = 20;
	int umValor, outroValor ;
	printf("\n Informe umValor: ");
	scanf("%d", &umValor);
	printf("\n Informe outroValor: ");
	scanf("%d", &outroValor);
	printf("\nValores antes - umValor = %d e outroValor = %d\n", umValor, outroValor); 
	umValor = umValor + outroValor;
	outroValor = umValor - outroValor;
	umValor = umValor - outroValor;
	printf("\nValores depois das operações - umValor = %d e outroValor = %d\n", umValor, outroValor); 
}

