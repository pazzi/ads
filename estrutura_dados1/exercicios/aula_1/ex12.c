#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///Declaracao de variaveis
    int umNumero, outroNumero;
    ///Entrada de dados
    //processamento
    system("clear");
    for(umNumero = 1; umNumero <= 10; umNumero++)
    {
        printf("\n\n Taboada do %i \n", umNumero);
        for(outroNumero = 1; outroNumero <=10; outroNumero++)    
        { 
           printf("%2i x%2i = %2i\t",
                   umNumero, outroNumero, umNumero * outroNumero);
        } 
    
    }
    printf("\n\n Fim da taboada\n\n");

}
