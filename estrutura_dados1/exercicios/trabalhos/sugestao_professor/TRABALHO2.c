/*
2. Construa uma fun��o em C que receba uma senha por par�metro (string) e devolva verdadeiro se a senha estiver correta
   ou falso, caso contr�rio. As regras para indicar a corre��o da senha s�o: a) tamanho m�nimo de 8 caracteres; b) pelo
   menos 2 caracteres contendo valores num�ricos; c) dos demais caracteres, pelo menos um em mai�sculo. Fa�a um programa
   simples para invocar a fun��o e demonstrar seu funcionamento.

*/

#include <stdio.h>
#include <string.h>

int estahCorreta(char senha[20]) ///a fun��o estahCorreta recebe a senha e devolve 0 (falso) se incorreta ou 1 (verdadeiro), se correta
{
  int i, conta, oQueRetorna = 1;
  if(strlen(senha) < 8) ///o tamanho � menor que 8
  {
    oQueRetorna = 0; ///vai retornar falso
  }

  conta = 0;
  for(i = 0; i < strlen(senha); i++) ///percorre toda a senha, caractere a caractere contandop quantos n�meros (0-9) vai encontrando
  {
    if(senha[i] == '0' || senha[i] == '1' || senha[i] == '2' || senha[i] == '3' || senha[i] == '4' ||
       senha[i] == '5' || senha[i] == '6' || senha[i] == '7' || senha[i] == '8' || senha[i] == '9') /// as duas barrinhas || s�o o operador OU
    {
      conta++; ///conta mais um n�mero encontrado
    }
  }
  if(conta < 2) ///se encontrou menos que dois n�meros
  {
    oQueRetorna = 0; ///vai retornar falso
  }

  conta = 0; ///aproveita a mesma vari�vel para fazer outra contagem
  for(i = 0; i < strlen(senha); i++) ///percorre toda a senha de novo, caractere a caractere
  {
    if(isupper(senha[i])) ///se eh verdadeiro que o caractere � mai�sculo. isupper(caractere) � a fun��o que descobre se � ou n�o mai�sculo
    {
      conta++; ///conta mais um caractere mai�sculo
    }
  }
  if(conta == 0) ///se n�o conseguiu contar nenhum caractere mai�sculo
  {
    oQueRetorna = 0; ///vai retornar falso
  }

  return(oQueRetorna); ///retorna 0 ou 1 para quem chamou esta fun��o estahCorreta.
}

main()
{
  char senha[20];
  printf("\nDigite a senha: ");
  gets(senha);
  if(estahCorreta(senha) == 1) ///chama a fun��o mandando a senha como par�metro para ela trabalhar
  {
    puts("\nA senha estah correta");
  }
  else
  {
    puts("\nA senha NAO estah correta");
  }
}
