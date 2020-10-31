#include <stdio.h>
#include <stdlib.h>

int main(){
    system("clear");
    float base, altura;
    fflush(stdin);
    printf("\nInforme o valor da base do retângulo: ");
    scanf("%f", &base);
    fflush(stdin);
    printf("\nInforme o valor da altura do retângulo: ");
    scanf("%f", &altura);
    printf("\nO valor da área do retângulo é:%.2f\n\n", base*altura);

}
