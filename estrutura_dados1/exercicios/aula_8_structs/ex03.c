/*
3) Suponha que você foi incumbido de construir um programa em linguagem C
para auxiliar a secretaria da Faculdade a descobrir quantos alunos
matriculados são casados, quantos são solteiros e quantos são divorciados,
assim também como a média de idade de cada um destes três grupos.
As funcionalidades esperadas do programa são:
a) Cadastrar 1000 (mil) alunos em um array. Os campos a serem cadastrados
   para cada aluno são: nome (string), endereço (string), idade (inteiro)
   e estado civil (caractere - C: Casado, S: Solteiro e D: Divorciado).
b) Somente após o cadastro destes 1000 alunos, deverá ser efetuada uma
   busca no array para se descobrir as informações solicitadas.
c) Terminada a busca, o programa deverá imprimir na tela quantos alunos
   matriculados são casados, quantos são solteiros e quantos são
   divorciados, assim também como a média de idade de cada um destes
   três grupos.
*/

#include <stdio.h>
#include <ctype.h>
#define MAX 3

struct aluno
{
  char nome[50], endereco[70], estadoCivil;
  int idade;
};

int main()
{
  struct aluno matriculados[MAX];
  int indice;
  int quantosC, quantosS, quantosD;
  float mediaC, mediaS, mediaD, somaC, somaS, somaD;


  //cadastrar os alunos
  for(indice = 0; indice < MAX; indice++)
  {

    getchar();
    fflush(stdin);
    printf("\nDigite o nome do aluno %i: ", indice);
    gets(matriculados[indice].nome,50,stdin);

    fflush(stdin);
    printf("\nDigite o endereco do aluno %i: ", indice);
    gets(matriculados[indice].endereco,70,stdin);

    fflush(stdin);
    printf("\nDigite a idade do aluno %i: ", indice);
    scanf("%i", &matriculados[indice].idade);

    //do
    while(matriculados[indice].estadoCivil != 'C' &&
          matriculados[indice].estadoCivil != 'S' &&
          matriculados[indice].estadoCivil != 'D')
    {
      printf("\nDigite o estado civil do aluno (c, s, d) %i: ", indice);
      matriculados[indice].estadoCivil = toupper(getchar());
      fflush(stdin);
    }
   // while(matriculados[indice].estadoCivil != 'C' &&
    //      matriculados[indice].estadoCivil != 'S' &&
    //      matriculados[indice].estadoCivil != 'D');
  }

  // pesquisar as informações
  quantosC = quantosS = quantosD = 0;
  somaC = somaS = somaD = 0;

  for(indice = 0; indice < MAX; indice++)
  {
    if(matriculados[indice].estadoCivil == 'C')
    {
      quantosC++;
      somaC+=matriculados[indice].idade;
    }
    if(matriculados[indice].estadoCivil == 'S')
    {
      quantosS++;
      somaS+=matriculados[indice].idade;
    }
    if(matriculados[indice].estadoCivil == 'D')
    {
      quantosD++;
      somaD+=matriculados[indice].idade;
    }
  }

  // exibindo as informações
  mediaC = (float) quantosC>0?(somaC/quantosC):0;
  mediaS = (float) quantosS>0?(somaS/quantosS):0;
  mediaD = (float) quantosD>0?(somaD/quantosD):0;
  printf("\nExistem %i alunos casados e a media de idade eh: %.2f anos", quantosC, mediaC);
  printf("\nExistem %i alunos solteiros e a media de idade eh: %.2f anos", quantosS, mediaS);
  printf("\nExistem %i alunos divorciados e a media de idade eh: %.2f anos", quantosD, mediaD);
  return(0);
}
