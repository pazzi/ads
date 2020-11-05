#include <stdio.h>
#include <stdlib.h>

int main(){
    int timeCasa, timeAdversario;
    system("clear");
    fflush(stdin);
    printf("\nInforme os gols marcados pela equipe da casa e pelo adversário ");
    scanf("%i %i", &timeCasa, &timeAdversario);
    if (timeCasa == timeAdversario)
        printf("\nEMPATE\n");
    if (timeCasa > timeAdversario)
    {
        printf("\nVITÓRIA DO TIME DA CASA\n\n");
    }
    else 
    {
        printf("\nVITÓRIA DA EQUIPE VISITANTE\n\n");
        }
}
