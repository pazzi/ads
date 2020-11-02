/*EXERCÍCIOS PARA REVISAR COMANDOS DE REPETIÇÃO
10. Execute o programa a seguir e ache a carinha diferente. Sabendo que o problema consiste
em resolver uma equação de 1o grau, (3 x – x = 8), você acha que esta solução implementada
no programa ajuda ou atrapalha na resolução do problema? Diga o porquê?
#include <stdio.h>
main()
{
int x = -100;
while ( x ++ < 100)
printf("\nx = %i\t3x - x = %i\t%s",
x ,
3* x - x ,
((3* x - x ) == 8)?"8^)":"8^(");
}
*/
