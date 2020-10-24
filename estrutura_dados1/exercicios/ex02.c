
#include <stdio.h>

int main(){
    float bruto, desconto;
    int dias;
    printf("\nInforme a quantidade de dias trabalhados: ");
    scanf("%i", &dias);
    bruto = 60 * dias;
    desconto = bruto * 0.11;
    printf("\nO trabalhador trabalhou %i: ", dias);
    printf("\nO  valor bruto a receber é %f: ", bruto);
    printf("\nO desconto de IR é %f: ", desconto);
    printf("\nO valor líquido a receber é %f: ", bruto - desconto);

}
