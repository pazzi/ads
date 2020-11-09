/*3. Execute o programa a seguir e proponha uma breve explicação do porquê a comparação
( x==y ) retorna verdadeiro, se os valores de x e y são diferentes.
#include <stdio.h>
main()
{
float x = 10.1234567;
float y = 10.1234568;
printf("\nx = %f\ty = %f", x, y);
printf("\nsao %s", x==y ? "IGUAIS" : "dIfErEnTeS");
}
*/
#include <stdio.h>
int main()
{
float x = 10.1234567;
float y = 10.1234568;
printf("\nx = %f\ty = %f", x, y);
printf("\nsao %s", x==y ? "IGUAIS" : "dIfErEnTeS");
printf("*************************************************");
printf("Variáveis float - %ld bytes\n",sizeof(x));

}

/*COMENTÁRIOS:
 * Haverá uma tuncagem no carater 6 (após o ponto) com o arredondamento 67 = 7 e 68 = 7
