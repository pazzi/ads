/*
  exemplo para demonstrar que a passagem de parametros por referencia usa 
  ponteiros, ou seja, a funcao chamadora passa o endereco da variavel para
  a funcao chamada, que armazena este endereco em um ponteiro

*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void funcao(int valor);
void outraFuncao(int *valor);

int main()
{
  int i;
  system("clear");  


  int valor = 10;
  printf("\nEndereco de valor na funcao main: %p", &valor);
  funcao(valor); // passagem por valor
  outraFuncao(&valor); // passagem por referencia
  
  printf("\n\n");
  return 0;  
  
}

void funcao(int valor) // receber o parametro por valor
{                      // fez copia; o endereco eh diferente da funcao main
  printf("\n\nEndereco de valor dentro da funcao : %p", &valor);
}

void outraFuncao(int * valor) // receber o parametro por referencia.
{                             // eh a mesma variavel (mesmo endereco da funcao main)
  printf("\n\nEndereco de valor dentro da outra funcao : %p", valor);
}
