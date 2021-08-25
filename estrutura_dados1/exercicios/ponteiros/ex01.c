/*
Basico:
  definir um ponteiro
  operadores especificos para ponteiros: &, *, *
  exemplinhos
Coisas praticas do dia a dia:
  a passagem de parametros por referencia usa ponteiros
  o nome de um array eh um ponteiro
  eh possivel fazer "aritmetica" de ponteiros
  a passagem de structs por referencia usa ponteiros "c/ um detalhe"
  dah para uma funcao retornar uma string
  dah para passar parametros para o programa
*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void funcao(int valor);
void funcao1(int *valor);

int main()
{
  int i;
  system("clear");  

  char frase[15];
  printf("\nDigite uma frase: ");
  fgets(frase,15, stdin);
  printf("%s", frase);
  printf("\nTamanho de um char: %ld bytes", sizeof(char));
  char *pont;
  pont = frase;
  printf("\n");
  while(*pont)
  {
    printf("%c - ", *pont++ );
    printf("%p\n", pont);
  }

  
  printf("\nTamanho de um float: %ld bytes\n", sizeof(float));
  float vetor[] = {1,2,3,4,5,6,7,8,9,10};
  float *pont1;
  pont1 = vetor;
  for (i = 0; i < 10; i++)
  {
    printf("%5.2f - ", *pont1++ );
    printf("%p\n", pont1);
  }

  printf("\nTamanho de um inteiro: %ld bytes\n", sizeof(int));
  int vetor1[] = {1,2,3,4,5,6,7,8,9,10};
  int *pont2;
  pont2 = vetor1;
  for (i = 0; i < 10; i++)
  {
    printf("%2d - ", *pont2++ );
    printf("%p\n", pont2);
  }

  int valor = 10;
  printf("\nEndereco de valor na funcao main: %p", &valor);
  funcao(valor); // passagem por valor
  funcao1(&valor); // passagem por referencia
  
  printf("\n");
 
  ///system("pause");  
  return 0;
  
}

void funcao(int valor) // receber o parametro por valor
{
  printf("\nEndereco de valor dentro da funcao : %p", &valor);
}

void funcao1(int * valor) // receber o parametro por referencia
{
  printf("\nEndereco de valor dentro da outra funcao : %p", valor);
}
