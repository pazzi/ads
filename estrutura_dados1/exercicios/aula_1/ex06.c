#include <stdio.h>
#include <stdlib.h>

int main(){
    int n1, n2, n3, n4, soma, par;
    soma=0;
    par=0;
    system("clear");
    fflush(stdin);
    printf("\nInforme quatro números: ");
    scanf("%i %i %i %i", &n1, &n2, &n3, &n4);
    if (n1%2 == 0)
    {  
        soma+=n1;
        par++;
    }
    if (n2%2 == 0)
    {
        soma+=n2;
        par++;
    }
    if(n3%2 == 0)
    {
        soma+=n3;
        par++;
    }
    if(n4%2 == 0)
    {
        soma+=n4;
        par++;
    }

    printf("\nForam inseridos  %i números pares e a soma deles é %i.\n\n",par, soma);
}
