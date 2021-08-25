/*
  exemplo para demonstrar que todo array eh, na verdade, um ponteiro
  que aponta para o primeiro elemento do array
*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main()
{
  int i;
  system("clear");  

  char frase[15];
  printf("\nDigite uma frase: ");
  fgets(frase,15,stdin);
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

  printf("\n");
  //system("pause");  
  return 0;
  
}
