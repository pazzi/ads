#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int codigo;
    time_t t = time(NULL);
    long int ano;
    struct tm tm = *localtime(&t);
    long int anoNascimento;
    long int anoIngresso;
    ano=tm.tm_year + 1900;
    system("clear");
    fflush(stdin);
    printf("\nInforme o código do empregado:");
    scanf("%i",&codigo);
    fflush(stdin);
    printf("\nInforme o ano do nascimento:");
    scanf("%ld",&anoNascimento);
    fflush(stdin);
    printf("\nInforme o ano de ingresso:");
    scanf("%ld",&anoIngresso);
    printf("\nA idade do empregado é %ld anos\n", ano - anoNascimento);
    printf("\nO tempo de trabalho do empregado é %ld anos \n", ano - anoIngresso);
    if (ano - anoNascimento >= 65 || ano - anoIngresso >= 30 || (ano - anoNascimento >=60 && ano - anoIngresso >=25))
        printf("\nRequerer Aposentadoria\n\n");
    else
        printf("\nNão Requerer\n\n");
}
