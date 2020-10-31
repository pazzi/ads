#include <stdio.h>
#include <stdlib.h>

int main(){
    int ano, mes, dia;
    system("clear");
    printf("\nInforme a idade em anos, meses e dias\n\n");
    fflush(stdin);
    printf("\nQuantos anos?:  ");
    scanf("%i", &ano);
    fflush(stdin);
    printf("\nQuantos meses?:  ");
    scanf("%i", &mes);
    fflush(stdin);
    printf("\nQuantos dias?:  ");
    scanf("%i", &dia);
    printf("\nO correspondente a sua idade em dias é %i dias\n\n", ano*365+mes*30+dia);

}
