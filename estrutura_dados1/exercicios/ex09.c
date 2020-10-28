#include <stdio.h>
#include <stdlib.h>

int main(){
    int quant=0;
    int soma=0;
    int i;
    system("clear");
    for(i=1; i<=5000; i++)
    {
      if (i%7==0 && i%2==0) 
      {
         quant++;
         soma=soma+i;
      }
    }
    printf("\nEntre 1 e 5000 foram encontrados %i numeros pares e multiplos de 7\n", quant);
    printf("A média entre esses números é %i\n\n", soma/quant);
}
