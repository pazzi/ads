#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char diaCurso;
    char areaCurso;
    char controle;
    diaCurso=0;
    areaCurso='n';
    diaCurso='n';
    int contSemana, contSabado, contQ, contI, diaArea, contSemanaQuimica, contSabadoQuimica, contSemanaInfo, contSabadoInfo;
    contQ=0;
    contI=0;
    contSemana=0;
    contSabado=0;
    contSabadoInfo=0;
    contSabadoQuimica=0;
    contSemanaInfo=0;
    contSemanaQuimica=0;
    system("clear");
    do
    {
        diaArea=0;
        fflush(stdin);
        printf("\nDia da oferta do curso [1-Durante a semana ou 2-aos sábados]: ");
        scanf(" %c",&diaCurso);
        if(diaCurso == '1')
        {
            contSemana++; 
            diaArea=2;
        }
        else{
                contSabado++; 
                diaArea=4;
            }
        fflush(stdin);
        printf("\nÁrea do curso [Q para Química ou I para Informática: ");
        scanf(" %c",&areaCurso);
        if(toupper(areaCurso) =='Q')
        {
            contQ++;
            diaArea+=8;
        }
        else{
                contI++; 
                diaArea+=16;
            }
        switch (diaArea)
        {
            case 10:
                    contSemanaQuimica++;
                    break;
            case 12:
                    contSabadoQuimica++;
                    break;
            case 18:
                    contSemanaInfo++;
                    break;
            case 20:
                    contSabadoInfo++;
                    break;
        
        }
        fflush(stdin);
        printf("\nDeseja continuar a inserção [S/N]: ");
        scanf(" %c",&controle);
        system("clear");
    } while (toupper(controle) == 'S');
    printf("\n\nDas 285 inserções foram verificadas %i\n", contQ+contI);
    printf("\nForam incluídos %i alunos que preferem o curso durante a semana", contSemana);
    printf("\nForam incluídos %i alunos que preferem o curso aos Sábados", contSabado);
    printf("\nForam incluídos %i alunos que preferem a área de informática", contI);
    printf("\nForam incluídos %i alunos que preferem a área de química", contQ);
    printf("\nForam incluídos %i alunos que preferem a área de química durante a semana", contSemanaQuimica);
    printf("\nForam incluídos %i alunos que preferem a área de química aos sábados", contSabadoQuimica);
    printf("\nForam incluídos %i alunos que preferem a área de informática durante a semana", contSemanaInfo);
    printf("\nForam incluídos %i alunos que preferem a área de informática aos sábados\n\n", contSabadoInfo);

}
