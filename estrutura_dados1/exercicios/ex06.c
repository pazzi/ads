#include <stdio.h>
#include <stdlib.h>

int main(){
    int n1, n2, n3, n4, soma, par;
    soma=0;
    par=0;
    system("clear");
    printf("\nInforme quatro números: ");
    scanf("%i %i %i %i", &n1, &n2, &n3, &n4);
    if (n1%2 == 0)
    {  
        soma+=n1;
        par++;
    }
    else
        { 
            if (n2%2 == 0)
            {
                soma+n2;
                par++;
            }
            else
               {
                 if(n3%2 == 0)
                 {
                    soma+n3;
                    par++;
                }
    else
    {
        if(n4%2 == 0)
        {
        soma+n4;
        par++;
        }

            printf("\nA divisão de %.2f por %.2f é %.2f\n\n",n1, n2, n1/n2 );
}
