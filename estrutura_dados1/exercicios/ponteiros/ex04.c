/*
  exemplo para demonstrar que eh possivel fazer "aritmetica" de ponteiros

*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
  int i;
  system("clear");  
  int variavel;
  int *ponteiro;
  variavel = 10;
  ponteiro = &variavel;
  printf("\nImprimindo o valor da variavel atraves do ponteiro: %i", *ponteiro);
  printf("\nImprimindo o endereco da variavel armazenado no ponteiro: %p", ponteiro);
  printf("\nImprimindo o conteudo do endereco armazenado em ponteiro + 1 (%p): %d", ponteiro, *ponteiro++);
  printf("\nImprimindo o conteudo do endereco armazenado em ponteiro + 2 (%p): %d", ponteiro, *ponteiro++);
  printf("\nImprimindo o conteudo do endereco armazenado em ponteiro + 3 (%p): %d", ponteiro, *ponteiro++);
  printf("\nImprimindo o conteudo do endereco armazenado em ponteiro + 4 (%p): %d", ponteiro, *ponteiro++);
  printf("\nImprimindo o conteudo do endereco armazenado em ponteiro + 5 (%p): %d", ponteiro, *ponteiro++);
  
  printf("\n");

  printf("\nImprimindo o conteudo da memoria (lixo) a partir do endereco %p\n", ponteiro);
  for(i = 0; i < 1000; i++)
  {
    printf("%c", *ponteiro++);
  }
  printf("\n\n");
  return 0;  


}
