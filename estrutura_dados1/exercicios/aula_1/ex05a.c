#include <stdio.h>
#include <stdlib.h>

int main(){
    float n1, n2;
    system("clear");
    printf("\nInforme dois números: ");
    scanf("%f %f", &n1, &n2);
    if (n2 != 0)
        {
            printf("\nA divisão de %.2f por %.2f é %.2f\n\n",n1, n2, n1/n2 );
        }
        else{
                printf("\n DIVISÃO POR ZERO!!!!\n\n");
            }
}
