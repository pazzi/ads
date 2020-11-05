#include <stdio.h>
#include <stdlib.h>

int main(){
    int quant=0;
    int soma=0;
    int i;
    system("clear");
    for(i=-1000; i<=1000; i++)
    {
      if (i%3==0) 
      {
         quant++;
         soma=soma+i;
      }
    }
    printf("\nEntre -1000 e 1000 foram encontrados %i numeros  multiplos de 3\n", quant);
    printf("A média entre esses números é %i\n\n", soma/quant);
}
