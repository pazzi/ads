#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curses.h>

#define MAXCLIENTES 100
#define MAXPRODUTOS 100
#define MAXPEDIDOS 100

struct endereco
{
  char rua[40];
  int numero;
  char cidade[50];
  char estado[3];
  char cep[15];
};

struct cliente
{
  char cpf[12];
  char nome[50];
  struct endereco umEndereco;
};

struct produto
{
  char codigo[10];
  char descricao[50];
  float preco;
};

struct qualProduto
{
  int produto, quantidade;
};

struct pedido
{
  int cliente;
  char data[11];
  int quantosProdutos;
  float valorTotal;
  struct qualProduto listaDeProdutos[30];
};

 void mypause(void)
 {
   printf ("Aperte [Enter] para continuar . . .");
   fflush (stdout);
   getchar();
 }

/*C�DIGO PARA MANIPULA��O DE ENDERE�O */
struct endereco pegaEndereco()
{
  struct endereco novoEndereco;
  printf("\nDigite a rua...: ");
  fgets(novoEndereco.rua,40, stdin);
  __fpurge(stdin);
  printf("\nDigite o numero: ");
  scanf("%i", &novoEndereco.numero);
  __fpurge(stdin);
  printf("\nDigite a cidade: ");
  fgets(novoEndereco.cidade,50, stdin);
  __fpurge(stdin);
  printf("\nDigite o estado: ");
  fgets(novoEndereco.estado,3,stdin);
  __fpurge(stdin);
  printf("\nDigite o cep...: ");
  fgets(novoEndereco.cep,15,stdin);
  __fpurge(stdin);
  return(novoEndereco);
};

void imprimeEndereco(struct endereco umEndereco)
{
  printf("Rua: %s", umEndereco.rua);
  printf("No.: %i", umEndereco.numero);
  printf("Cidade: %s", umEndereco.cidade);
  printf("Estado: %s", umEndereco.estado);
  printf("Cep: %s", umEndereco.cep);
}

/*C�DIGO PARA MANIPULA��O DE CLIENTE */
struct cliente pegaCliente()
{
  struct cliente novoCliente;
  do
  {
    __fpurge(stdin);
    printf("\nDigite o CPF: ");
    fgets(novoCliente.cpf,15,stdin);
  }
  while(strlen(novoCliente.cpf) <= 0);

  do
  {
    __fpurge(stdin);
    printf("\nDigite o nome: ");
    fgets(novoCliente.nome,50,stdin);
  }
  while(strlen(novoCliente.nome) <= 0);

  novoCliente.umEndereco = pegaEndereco();

  return(novoCliente);
};

int devolveIndiceCliente(struct cliente novoCliente,
                         struct cliente clientes[],
                         int quantosClientes)
{
  int i, indice = -1;
  for(i = 0; i < quantosClientes; i++)
  {
    if(strcmp(novoCliente.cpf, clientes[i].cpf)==0)
    {
      indice = i;
    }
  }
  return(indice);
}

void insereCliente(struct cliente clientes[], int *quantosClientes)
{
  if(*quantosClientes == MAXCLIENTES)
  {
     puts("\nErro. Nao tem mais espaco no cadastro de clientes.");
  }
  else
  {
    int indiceCliente;
    struct cliente novoCliente;
    do
    {
      novoCliente = pegaCliente();
      indiceCliente = devolveIndiceCliente(novoCliente, clientes, *quantosClientes);
      if(indiceCliente != -1)
      {
        puts("\nErro. Este cliente jah estah cadastrado.");
      }
    }
    while(indiceCliente != -1);
    clientes[(*quantosClientes)++] = novoCliente;
  }
}

void imprimeCliente(struct cliente umCliente)
{
  char opt;
  printf("\nCPF.: %s", umCliente.cpf);
  printf(" - %s", umCliente.nome);
  imprimeEndereco(umCliente.umEndereco);
  opt=getchar();

}

void imprimeClientes(struct cliente clientes[], int quantos)
{
  int i;
  printf("\nImpressao de Clientes\n");
  for(i = 0; i < quantos; i++)
  {
    imprimeCliente(clientes[i]);
  }
}

/*C�DIGO PARA MANIPULA��O DE PRODUTOS */
struct produto pegaProduto()
{
  struct produto novoProduto;
  do
  {
    __fpurge(stdin);
    printf("\nDigite o codigo do produto.....: ");
    fgets(novoProduto.codigo,10,stdin);
  }
  while(strlen(novoProduto.codigo) <= 0);

  do
  {
    printf("\nDigite a descricao do produto %s: ", novoProduto.codigo);
    __fpurge(stdin);
    fgets(novoProduto.descricao,50,stdin);
  }
  while(strlen(novoProduto.descricao) <= 0);

  do
  {
    __fpurge(stdin);
    printf("\nDigite o preco do produto %s....: ", novoProduto.codigo);
    scanf("%f", &novoProduto.preco);
  }
  while(novoProduto.preco <= 0);

  return(novoProduto);
};

int devolveIndiceProduto(struct produto novoProduto,
                         struct produto produtos[],
                         int quantosProdutos)
{
  int i, indice = -1;
  for(i = 0; i < quantosProdutos; i++)
  {
    if(strcmp(novoProduto.codigo, produtos[i].codigo)==0)
    {
      indice = i;
    }
  }
  return(indice);
}

void insereProduto(struct produto produtos[], int *quantosProdutos)
{
  if(*quantosProdutos == MAXCLIENTES)
  {
     printf("\nErro. Nao tem mais espaco no cadastro de produtos.");
  }
  else
  {
    int indiceProduto;
    struct produto novoProduto;
    do
    {
      novoProduto = pegaProduto();
      indiceProduto = devolveIndiceProduto(novoProduto, produtos, *quantosProdutos);
      if(indiceProduto != -1)
      {
        puts("\nErro. Este produto jah estah cadastrado.");
      }
    }
    while(indiceProduto != -1);
    produtos[(*quantosProdutos)++] = novoProduto;
  }
}

void imprimeProduto(struct produto umProduto)
{
  char op;
  printf("\n%s %s %.2f\n\n", umProduto.codigo, umProduto.descricao, umProduto.preco);
  /*
  printf("\nCodigo: %s", umProduto.codigo);
  printf(" Descricao: %10s", umProduto.descricao);
  printf(" Preco: R$ %.2f\n\n", umProduto.preco);
  */
  op=getchar();

}

void imprimeProdutos(struct produto produtos[], int quantos)
{
  int i;
  printf("\nImpressao de produtos");
  for(i = 0; i < quantos; i++)
  {
    imprimeProduto(produtos[i]);
  }
}

/*CODIGO PARA MANIPULACAO DE PEDIDOS */
void inserePedido(
                  struct pedido pedidos[],
                  int *quantosPedidos,
                  struct cliente clientes[],
                  int quantosClientes,
                  struct produto produtos[],
                  int quantosProdutos
                 )
{
  if(*quantosPedidos == MAXPEDIDOS)
  {
    printf("\nErro. Nao tem mais espaco no cadastro de pedidos");
  }
  else
  {
    struct pedido novoPedido;
    novoPedido.quantosProdutos = 0;
    novoPedido.valorTotal = 0;

    /*DIGITA O CPF E DESCOBRE O INDICE DO CLIENTE DO NOVO PEDIDO */
    do
    {
      struct cliente novoCliente;
      __fpurge(stdin);
      printf("\nDigite o CPF do cliente: ");
      fgets(novoCliente.cpf,12,stdin);
      novoPedido.cliente = devolveIndiceCliente(novoCliente, clientes, quantosClientes);
      if(novoPedido.cliente == -1)
      {
        puts("\nErro. Este cliente nao estah cadastrado.");
      }
    }
    while(novoPedido.cliente == -1);

    /*DIGITA A DATA DO NOVO PEDIDO */
    do
    {
      __fpurge(stdin);
      printf("\nDigite a data do novo pedido: ");
      fgets(novoPedido.data,11,stdin);
    }
    while(strlen(novoPedido.data)<= 0);

    /*DIGITA O CODIGO E A QUANTIDADE DE CADA UM DOS PRODUTOS DO NOVO PEDIDO */
    char insereMaisUm;
    do
    {
      struct produto novoProduto;

      int indice;
      do
      {
        __fpurge(stdin);
        printf("\nDigite o codigo do produto: ");
        fgets(novoProduto.codigo,10,stdin);
        indice = devolveIndiceProduto(novoProduto, produtos, quantosProdutos);
        if(indice == -1)
        {
          printf("\nErro. este produto nao estah cadastrado.");
        }
      }
      while(indice == -1);

      int quantidade;
      do
      {
        __fpurge(stdin);
        printf("\nDigite a quantidade do produto %s: ", produtos[indice].descricao);
        scanf("%i", &quantidade);
      }
      while(quantidade <= 0);

      novoPedido.listaDeProdutos[novoPedido.quantosProdutos].produto = indice;
      novoPedido.listaDeProdutos[novoPedido.quantosProdutos].quantidade = quantidade;

      novoPedido.valorTotal += (produtos[indice].preco * quantidade);

      novoPedido.quantosProdutos++;

      __fpurge(stdin);
      printf("\nInsere mais um produto? (S/N) (Total: %2i\tDisponivel: %2i)", novoPedido.quantosProdutos, 30 - novoPedido.quantosProdutos);
      /*insereMaisUm = getch(); */
      scanf("%c", &insereMaisUm);
    }
    while((toupper(insereMaisUm) == 'S') && (novoPedido.quantosProdutos <= 30));
    pedidos[(*quantosPedidos) ++] = novoPedido;
  }
}

void imprimePedido(
                  struct pedido umPedido,
                  struct cliente clientes[],
                  int quantosClientes,
                  struct produto produtos[],
                  int quantosProdutos
                 )
{
	char op;
  	printf("\n%s - %10s %10i %10.2f\n\n", clientes[umPedido.cliente].nome, umPedido.data, umPedido.quantosProdutos, umPedido.valorTotal);
	/*
	printf("%s ", clientes[umPedido.cliente].nome);
	printf("%s ", umPedido.data);
	printf("%i ", umPedido.quantosProdutos);
	printf("%f ", umPedido.valorTotal);
	*/
	op=getchar();

}

void imprimePedidos(
                  struct pedido pedidos[],
                  int quantosPedidos,
                  struct cliente clientes[],
                  int quantosClientes,
                  struct produto produtos[],
                  int quantosProdutos
                 )
{
  printf("\nImpressao de Pedidos\n\n");
  int i;
  for(i = 0; i < quantosPedidos; i++)
  {
    imprimePedido(pedidos[i], clientes, quantosClientes, produtos, quantosProdutos);
  }
}


void exibeMenu()
{
  system("clear");
  printf("\nM E N U    P R I N C I P A L\n");
  printf("\n Inserir <C>liente");
  printf("\n Imprimir c<L>iente");
  printf("\n Inserir <P>roduto");
  printf("\n Imprimir p<R>oduto");
  printf("\n Inserir p<E>dido");
  printf("\n Imprimir pe<D>ido");
  printf("\n\n <S>air");
}

char pegaOpcao()
{
  char opcao;
  __fpurge(stdin);
  printf("\n\nDigite sua opcao: ");
  opcao = getchar();
  return(toupper(opcao));
}

int main()
{
  struct cliente clientes[100];
  int quantosClientes = 0;

  struct produto produtos[500];
  int quantosProdutos = 0;

  struct pedido pedidos[1000];
  int quantosPedidos = 0;

  char opcao;

  do
  {
    exibeMenu();
    opcao = pegaOpcao();
    switch(opcao)
    {
      case 'C': /*inserir <C>liente*/
      {
        insereCliente(clientes, &quantosClientes);
        break;
      }
      case 'L': /*imprimir c<L>iente*/
      {
        imprimeClientes(clientes, quantosClientes);
	mypause();
        break;
      }
      case 'P': /*inserir <P>roduto*/
      {
        insereProduto(produtos, &quantosProdutos);
        break;
      }
      case 'R': /*imprimir p<R>oduto*/
      {
        imprimeProdutos(produtos, quantosProdutos);
	mypause();
        break;
      }
      case 'E': /*inserir p<E>dido*/
      {
        inserePedido(pedidos, &quantosPedidos, clientes, quantosClientes, produtos, quantosProdutos);
        break;
      }
      case 'D': /*imprimir pe<D>ido*/
      {
        imprimePedidos(pedidos, quantosPedidos, clientes, quantosClientes, produtos, quantosProdutos);
	mypause();
        break;
      }
      case 'S':
      {
        puts("\nSaindo.");
        break;
      }
      default:
      {
        puts("\nOpcao invalida.");
        break;
      }
    }
/*
    printf("\n\n");
    if(opcao != 'S')
     system("read -p \"Opcao invalida\".");
        puts("\nOpcao Inválida.");
*/
  }
  while(opcao != 'S');
  return 0;
}
