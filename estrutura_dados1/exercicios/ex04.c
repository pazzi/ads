#include <stdio.h>
#include <stdlib.h>

int main(){
    float custoFabrica;
    system("clear");
    fflush(stdin);
    printf("\nInforme o custo de fabrica do veículo: ");
    scanf("%f", &custoFabrica);
    printf("\nO custo final do veículo para o consumidor é R$ %.2f \n\n", custoFabrica + custoFabrica * 0.28 + custoFabrica * 0.45);

}
