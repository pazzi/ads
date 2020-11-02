/*6. Um operador aritmético unário é aquele que precisa de apenas um operando para funcionar.
Exemplos comuns são os operadores de incremento ( ++ ) e decremento ( -- ). Execute o
programa a seguir e observe a diferença quando eles são posicionados antes ou depois do
operando.
#include <stdio.h>
main()
{
1int umValor, outroValor;
printf("\nO operador vai DEPOIS da variavel (umValor++):");
umValor = 10;
outroValor = umValor ++ ;
printf(" Um valor: %i\tOutro valor: %i", umValor, outroValor);
printf("\nO operador vai ANTES da variavel (++umValor):");
umValor = 10;
outroValor = ++ umValor;
printf(" Um valor: %i\tOutro valor: %i\n\n", umValor, outroValor);
}
*/
