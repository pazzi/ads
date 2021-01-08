/*
4) Suponha que você foi incumbido de construir um programa em linguagem C para auxiliar o setor de bolsas de
   estudo de uma Faculdade a conceder desconto para um novo aluno que possui irmãos já matriculados em cursos da
   Faculdade. A regra para concessão de bolsas é:
a) Se o novo aluno não possui irmão matriculado, a bolsa é 0%
b) Se o novo aluno possui um irmão matriculado, a bolsa é 15%
c) Se o novo aluno possui dois irmãos matriculados, a bolsa é 30%
d) Se o novo aluno possui três ou mais irmãos matriculados, a bolsa é 50%.
As funcionalidades esperadas do programa são:
1) Cadastrar 1000 (mil) alunos em um array. Os campos a serem cadastrados para cada aluno são nome (string),
   endereço (string), nome do pai (string) e nome da mãe (string).
2) Após o cadastro, deverá ser lido do teclado o nome do novo aluno, assim também como os nomes de seu pai e de
   sua mãe.
3) Feita esta leitura, deverá ser efetuada uma busca no array para se descobrir a quantidade de irmãos
   matriculados que este novo aluno possui. Assume-se que são irmãos aqueles que possuem os mesmos pai e mãe,
   ou seja, aqueles cujos nomes do pai e da mãe são exatamente iguais.
d) Terminada a busca no array, o programa deverá imprimir um número que represente a porcentagem de desconto à
   qual o novo aluno tem direito.*/

#include <stdio.h>
#define MAX 10

struct aluno
{
  char nome[50], endereco[70], pai[50], mae[50];
};

main()
{
  struct aluno alunos[MAX];
  int indice, quantosIrmaos, desconto;
  char umPai[50], umaMae[50];


  //cadastrar os alunos
  for(indice = 0; indice < MAX; indice++)
  {
    fflush(stdin);
    printf("\nDigite o nome do aluno %i: ", indice);
    gets(alunos[indice].nome);

    fflush(stdin);
    printf("\nDigite o endereco do aluno %i: ", indice);
    gets(alunos[indice].endereco);

    fflush(stdin);
    printf("\nDigite o nome do pai do aluno %i: ", indice);
    gets(alunos[indice].pai);

    fflush(stdin);
    printf("\nDigite o nome da mae do aluno %i: ", indice);
    gets(alunos[indice].mae);
  }

  // pesquisar a quantidade de irmaos
  quantosIrmaos = 0;
  desconto = 0;
  fflush(stdin);
  printf("\nDigite o nome do pai do novo aluno: ");
  gets(umPai);

  fflush(stdin);
  printf("\nDigite o nome da mae do novo aluno: ");
  gets(umaMae);

  for(indice = 0; indice < MAX; indice++)
  {
    if(strcmp(alunos[indice].pai, umPai) == 0 &&
       strcmp(alunos[indice].mae, umaMae) == 0)
    {
      quantosIrmaos++;
    }
  }

  switch(quantosIrmaos)
  {
    case 0:
    {
      desconto = 0;
      break;
    }
    case 1:
    {
      desconto = 15;
      break;
    }
    case 2:
    {
      desconto = 30;
      break;
    }
    default:
    {
      desconto = 50;
      break;
    }
  }

  // exibindo as informações
  printf("\nO novo aluno possui %i irmaos matriculados e o desconto eh de %i%%.", quantosIrmaos, desconto);
}
