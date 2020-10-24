#include <stdio.h>
#include <stdlib.h>

int main(){
    float bruto, desconto;
    int dias;
    system("clear");
    printf("\nInforme a quantidade de dias trabalhados: ");
    scanf("%i", &dias);
    bruto = 60 * dias;
    desconto = bruto * 0.11;
    printf("\nO trabalhador trabalhou %i dias", dias);
    printf("\nO valor bruto a receber é R$ %.2f", bruto);
    printf("\nO desconto de IR é R$ %.2f", desconto);
    printf("\nO valor líquido a receber é R$ %.2f\n\n: ", bruto - desconto);

}
