/*
1. Os n�meros do Cadastro Nacional de Pessoa Jur�dica (CNPJ) possuem 14 d�gitos: XX.XXX.XXX/000Y-ZZ.
   Os oito primeiros n�meros (XX.XXX.XXX) formam a "raiz", que identifica a empresa. Os quatro d�gitos seguintes ap�s
   a barra (000Y) formam o sufixo, que identifica uma unidade de atua��o de empresa e os dois �ltimos (ZZ), ap�s o
   tra�o, formam o "d�gito verificador". Construa um programa em linguagem C que solicite a digita��o de um CNPJ
   do teclado e informe se ele foi ou n�o digitado corretamente. A verifica��o dever� informar:
   a)	Se ele tem ou n�o o tamanho correto (18 caracteres);
   b)	Se os pontos (.), a barra (/) e o tra�o (-) est�o ou n�o nas posi��es corretas;
   c)	Se os tr�s primeiros d�gitos do sufixo s�o ou n�o iguais a �000�.
*/

#include <stdio.h>

main()
{
  int estahCorreto = 1; ///assume que est� correto
  char cnpj[19] = "XX.XXX.XXX/000Y-ZZ"; ///jah declara a vari�vel e incializa
  printf("\nDigite o CNPJ: ");
/// gets(cnpj); ///estah comentado para n�o ter que digitar toda vez

  if(strlen(cnpj) != 18) ///testando a condi��o da op��o a)
  {
    estahCorreto = 0; ///falso que est� correto
  }
  if(cnpj[2] != '.' || cnpj[6] != '.' || cnpj[10] != '/' || cnpj[15] != '-') ///testando a condi��o da op��o b)
  {
    estahCorreto = 0; ///falso que est� correto
  }
  if(cnpj[11] != '0' || cnpj[12] != '0' || cnpj[13] != '0') ///testando a condi��o da op��o c)
  {
    estahCorreto = 0; ///falso que est� correto
  }

  if(estahCorreto == 1) ///continua verdadeiro. Em nenhum momento ficou falso (0)
  {
    printf("\nO CNPJ %s estah correto", cnpj);
  }
  else
  {
    printf("\nO CNPJ %s N A O estah correto", cnpj);
  }
}
