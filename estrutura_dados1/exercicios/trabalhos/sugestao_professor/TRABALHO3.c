/*
3. Suponha que voc� foi encarregado de escrever um programa em linguagem C cuja tarefa ser� auxiliar na administra��o do estoque de
   mantimentos de uma creche. A quantidade de produtos neste estoque � de exatamente 80. O controle dos produtos � feito da seguinte maneira:
   existe uma planilha na qual s�o cadastradas as seguintes informa��es de cada produto: descri��o, pre�o e quantidade, esta �ltima indicando
   quanto existe daquele produto em estoque. A seguir � apresentado um exemplo desta planilha:
	Descri��o	Pre�o Unit�rio	Quantidade (unidades)

    1	Arroz	       R$ 17,50	3
    2	Feij�o	       R$ 8,99 	4
    3	Sagu	       R$ 3,30	10
    ...	......		..................
   79	Milho Verde	   R$ 2,99	0
   80	Farinha	       R$ 2,50	1

Quando acontece a retirada de algum produto do estoque, a planilha � atualizada em seu campo quantidade.  Com base nesta descri��o,
construa um programa em linguagem C que apresente as seguintes funcionalidades:
a)	Permita ler do teclado a descri��o, pre�o e quantidade dos 80 produtos do estoque, armazenando-os em um array todos de uma s� vez.
b)	Permita fazer uma retirada de produto do estoque, solicitando que sejam digitadas do teclado a descri��o e a quantidade a serem
    retiradas. Caso o produto digitado n�o exista no estoque, uma mensagem de erro dever� ser apresentada. Se o produto existir, mas a
    quantidade digitada for superior � quantidade cadastrada, uma mensagem de erro dever� ser apresentada. Se nenhuma destas duas situa��es
    de erro ocorrer, a quantidade digitada do produto dever� ser subtra�da da respectiva quantidade armazenada
c)	Permita imprimir na tela a descri��o, pre�o e quantidade de todos os 80 produtos do estoque e ao final da impress�o, o valor total dos
    produtos no estoque. Este valor � calculado pelo somat�rio do valor total de cada um dos produtos (quantidade do produto vezes pre�o do
    produto)

Observa��o: o programa dever� contar com um menu principal a partir do qual as funcionalidades poder�o ser selecionadas pelo usu�rio.
            Este menu dever� conter uma op��o adicional que permita ao usu�rio encerrar o programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4

struct produto
{
  char descricao[50];
  float preco;
  int quantidade;
};

void main()
{
  struct produto estoque[MAX] = {
                                   "Batata", 12.0, 23,
                                   "Cenoura", 34.0, 56,
                                   "Alho porroh", 78.0, 90,
                                   "Catuaba", 112.0, 34
                                };
  char umaDescricao[50];
  int umaQuantidade;
  int opcao, i;
  do
  {
    system("cls");
    printf("\nControlinho de Estoque do Trabalho 3\n");
    printf("\n1. Inserir todos os %i produtos", MAX);
    printf("\n2. Retirada de produto");
    printf("\n3. Impressao do estoque");
    printf("\n0. Sair");
    fflush(stdin);
    printf("\n\nDigite sua opcao: ");
    scanf("%i", &opcao);
    switch(opcao)
    {
      case 1: /// inserir os produtos. Ser�o apenas 4 ao inv�s de 80.
      {
        puts("\nInsercao dos produtos");

        for(i = 0; i < MAX; i++)
        {
          fflush(stdin);
          printf("\nDigite a descricao do produto %i: ", i);
          gets(estoque[i].descricao);

          fflush(stdin);
          printf("\nDigite o preco do produto %i: ", i);
          scanf("%f", &estoque[i].preco);

          fflush(stdin);
          printf("\nDigite a quantidade do produto %i: ", i);
          scanf("%i", &estoque[i].quantidade);
        }
        break;
      }
      case 2: // retirada de produto
      {
        char umaDescricao[50];
        int umaQuantidade;
        int achou, suficiente;

        puts("\nRetirada dos produtos");

        fflush(stdin);
        printf("\nDigite a descricao do produto a ser retirado: ");
        gets(umaDescricao);

        do
        {
          fflush(stdin);
          printf("\nDigite a quantidade a ser retirada do produto: ");
          scanf("%i", &umaQuantidade);
        }
        while(umaQuantidade <= 0); ///fica em loop at� que a quantidade seja maior que 0

        achou = 0; /// come�a assumindo que � falso que achou o produto sendo procurado
        suficiente = 0;  ///falso que eh suficiente

        for(i = 0; i < MAX && !achou; i++) /// vai pesquisar em todos os produtos do estoque enquanto n�o achar ou quando chegar no final do estoque
        {
          if(strcmp(estoque[i].descricao, umaDescricao) == 0) /// comparou as strings (strcmp) e achou a descri��o do produto no estoque
          {
            achou = 1; /// verdadeiro que achou o produto
            if(umaQuantidade <= estoque[i].quantidade) ///tem quantidade suficiente no estoque para retirar
            {
              suficiente = 1; /// verdadeiro que a quantidade eh suficiente para retirada
              estoque[i].quantidade = estoque[i].quantidade - umaQuantidade; ///da quantidade dispon�vel retira uma quantidade pedida
            }
          }
        } /// for
        if(!achou) ///nao achou
        {
          printf("\nO produto %s nao existe no estoque!", umaDescricao);
        }
        else
        {
          if(!suficiente)
          {
            printf("\nA quantidade do produto %s nao eh suficiente para permitir a retirada de %i itens!",
                   umaDescricao, umaQuantidade);
          }
          else
          {
            printf("\nA retirada de %i itens do produto %s foi realizada com sucesso.", umaQuantidade, umaDescricao);
          }
        }


        break;
      }
      case 3: // impressao do estoque
      {
        float valorTotal = 0;
        puts("\nImpressao do estoque");

        for(i = 0; i < MAX; i++)
        {
          printf("\n\nDescricao do produto: %s",       estoque[i].descricao);
          printf("\nPreco do produto: R$ %.2f",        estoque[i].preco);
          printf("\nQuantidade do produto : %i itens", estoque[i].quantidade);
          valorTotal += (estoque[i].preco * estoque[i].quantidade); ///multiplica o pre�o pela quantidade de cada produto e soma ao valor total
        }
        printf("\n\nValor total do estoque: R$ %.2f\n", valorTotal);
        break;
      }
      case 0:
      {
        puts("\nSaindo...");
        break;
      }
      default:
      {
        puts("\nOpcao i n v a l i d a!\n");
      }
    } // switch
    printf("\n");
    system("pause");
  }
  while(opcao != 0);

}
