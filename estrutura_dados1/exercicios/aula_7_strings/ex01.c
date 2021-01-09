/*1. Construa um programa em linguagem C que leia uma frase (string com 80
 * caracteres) do teclado e imprima a string invertida. O esquema abaixo ilustra o
 * funcionamento do programa:
 * Digite a string: UNIÃO AGRÍCOLA BARBARENSE
 * String invertida: ESNERABRAB ALOCÍRGA OÃINU
  */
#include "stdio.h"
#include "string.h"

int main()
{
        //char c*;
        char frase[80];
        int x;

        // Captura frase
        printf("Informe uma frase: ");
        fgets(frase,80,stdin);
        //gets(frase);
	//scanf("%s", &frase);


        // Navega pelo nome informado, em um laco de repeticao que corre de tras para frente
        for(x=strlen(frase)-1; x>=0; x--)
        {
                printf("%c", frase[x]);
        }

//        scanf("%c", &caractere);
        return 0;
}

