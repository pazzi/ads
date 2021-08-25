#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <ncurses.h>

#define MAX 3
#define MAXEMBARALHA 3

//funções e tipos para manipulação de coisa
struct coisa
{
  int codigo;
  char nome[40];
  float peso;
};

typedef struct coisa Coisa;

void imprimeCoisa(Coisa umaCoisa)
{
  printf("\nCodigo: %i", umaCoisa.codigo);
///  printf("\nNome..: %s", umaCoisa.nome);
///  printf("\nPeso..: %.2f\n", umaCoisa.peso);
}

Coisa devolveCoisa()
{
  Coisa umaCoisa;
  fflush(stdin);
  printf("\nDigite o codigo: ");
  scanf("%i", &umaCoisa.codigo);
  fflush(stdin);
  printf("\nDigite o nome: ");
  fgets(umaCoisa.nome,40,stdin);
  fflush(stdin);
  printf("\nDigite o peso: ");
  scanf("%f", &umaCoisa.peso);
  return(umaCoisa);
}

int comparaCoisas(Coisa umaCoisa, Coisa outraCoisa)
{
  int saoIguais = 1;
  if(umaCoisa.codigo != outraCoisa.codigo)
  {
    saoIguais = 0;
  }
  return(saoIguais);
}

int ehMaiorACoisa(Coisa umaCoisa, Coisa outraCoisa)
{
  int ehMaior = 0;
  if(umaCoisa.codigo > outraCoisa.codigo)
  {
    ehMaior = 1;
  }
  return(ehMaior);
}

// funções e tipos para manipulação dos nós
struct no
{
  Coisa umaCoisa;
  struct no *prox;
};

typedef struct no No;

void inicializa(No **inicio)
{
  *inicio = NULL;
}

void insereNoInicio(No **inicio, Coisa umaCoisa)
{
  No *novo;
  novo = (No *) malloc(sizeof(No));
  novo->umaCoisa = umaCoisa;
  novo->prox = NULL;
  if(*inicio != NULL)
  {
    novo->prox = *inicio;
  }
  *inicio = novo;
}

void imprime(No *inicio)
{
  No *aux;
  if(inicio != NULL)
  {
    aux = inicio;
    while(aux != NULL)
    {
      imprimeCoisa(aux->umaCoisa);
      aux = aux->prox;
    }
  }
  else
  {
    printf("\nImpossivel imprimir. Lista vazia.");
  }
}

void insereNoFinal(No **inicio, Coisa umaCoisa)
{
  No *novo, *aux;
  novo = (No *) malloc(sizeof(No));
  if(novo != NULL)
  {
    novo->umaCoisa = umaCoisa;
    novo->prox = NULL;
    if(*inicio == NULL)
    {
      insereNoInicio(&*inicio, umaCoisa);
    }
    else
    {
      aux = *inicio;
      while(aux->prox != NULL)
      {
        aux = aux->prox;
      }
      aux->prox = novo;
    }
  }
  else
  {
    puts("ERRO. Memoria insuficiente.");
  }
}

void destruir(No **inicio)
{
  No *aux;
  while(*inicio != NULL)
  {
    aux = *inicio;
    *inicio = (*inicio)->prox;
    free(aux);
  }
  printf("\nLista destruida.");
}

void salvarEmArquivo(No *inicio, char nomeArquivo[])
{
  FILE *fp;
  No *aux;
  if(inicio != NULL)
  {
    fp = fopen(nomeArquivo, "wb");
    if(fp != NULL)
    {
      aux = inicio;
      while(aux != NULL)
      {
        fwrite(&aux->umaCoisa, sizeof(aux->umaCoisa), 1, fp);
        aux = aux->prox;
      }
      fclose(fp);
    }
    else
    {
      printf("\nERRO NA CRIACAO DO ARQUIVO");
    }
  }
  else
  {
    printf("\nImpossivel salvar. Lista vazia.");
  }
}

void recuperarDoArquivo(No **inicio, char nomeArquivo[])
{
  FILE *fp;
  No *aux;
  Coisa umaCoisa;
  fp = fopen(nomeArquivo, "rb");
  if (fp == NULL)
  {
    printf("\nERRO NA ABERTURA DO ARQUIVO");
  }
  else
  {
    destruir(&*inicio);
    printf("\nLista destruida");
    while(fread(&umaCoisa, sizeof(umaCoisa), 1, fp) == 1)
    {
      insereNoFinal(&*inicio, umaCoisa);
    }
    printf("\nLista reconstruida");
    fclose(fp);
  }
}

int removerDoInicio(No **inicio, Coisa *umaCoisa)
{
  int deuCerto = 1;
  No *aux;
  if(*inicio == NULL)
  {
    printf("\nImpossivel remover. Lista vazia.");
    deuCerto = 0;
  }
  else
  {
    aux = *inicio;
    *inicio = (*inicio)->prox;
    *umaCoisa = aux->umaCoisa;
    free(aux);
  }
  return(deuCerto);
}

int removerDoFinal(No **inicio, Coisa *umaCoisa)
{
  int deuCerto = 1;
  No *aux1, *aux2;
  if(*inicio == NULL) // lista vazia
  {
    printf("\nImpossivel remover. Lista vazia.");
    deuCerto = 0;
  }
  else
  {
    if((*inicio)->prox == NULL) //removendo o unico No da lista
    {
      *umaCoisa = (*inicio)->umaCoisa;
      free(*inicio);
      *inicio = NULL;
    }
    else
    {
      aux1 = *inicio;
      aux2 = (*inicio)->prox;
      while(aux2->prox != NULL)
      {
        aux1 = aux2;
        aux2 = aux2->prox;
      }
      *umaCoisa = aux2->umaCoisa;
      aux1->prox = NULL;
      free(aux2);
    }
  }
  return(deuCerto);
}

int removerUm(No **inicio, Coisa umaCoisa)
{
  int deuCerto = 0;
  No *aux1, *aux2;
  if(*inicio != NULL)
  {
    if(comparaCoisas((*inicio)->umaCoisa, umaCoisa)) //remover do início
    {
      aux1 = *inicio;
      *inicio = (*inicio)->prox;
      free(aux1);
      deuCerto = 1;
    }
    else
    {
      aux1 = *inicio;
      aux2 = (*inicio)->prox;
      while((aux2 != NULL) &&(!comparaCoisas(aux2->umaCoisa, umaCoisa)))
      {
        aux1 = aux2;
        aux2 = aux2->prox;
      }
      if(aux2 != NULL)
      {
        aux1->prox = aux2->prox;
        free(aux2);
        deuCerto = 1;
      }
    }
  }
  else
  {
    printf("\nImpossivel remover. Lista vazia.");
  }
  return(deuCerto);
}

int pesquisar(No *inicio, Coisa umaCoisa)
{
  int achou = 0;
  No *aux;
  aux = inicio;
  while(aux != NULL && !achou)
  {
    if(comparaCoisas(aux->umaCoisa, umaCoisa))
    {
      achou = 1;
    }
    else
    {
      aux = aux->prox;
    }
  }
  return(achou);
}

void inverterAListaProfissional(No **inicio)
{
  No *p1, *p2, *p3;
  if((*inicio != NULL) && ((*inicio)->prox != NULL))
  {
    p1 = NULL;
    p2 = *inicio;
    p3 = (*inicio)->prox;
    while(p2 != NULL)
    {
      p2->prox = p1;
      p1 = p2;
      p2 = p3;
      if(p3 != NULL)
      {
        p3 = p3->prox;
      }
    }
    *inicio = p1;
  }
}

void inverterAListaAmador(No **inicio)
{
  No *outroInicio;
  Coisa umaCoisa;
  int ok;
  outroInicio = NULL;
  while(*inicio != NULL)
  {
    ok = removerDoInicio(&*inicio, &umaCoisa);
    if(ok)
    {
      insereNoInicio(&outroInicio, umaCoisa);
    }
  }
  *inicio = outroInicio;
}

void repartir(No *inicio, No *array[])
{
  int i = 0;
  Coisa umaCoisa;
  No *aux = inicio;
  while(aux != NULL)
  {
    insereNoFinal(&array[i], aux->umaCoisa);
    i = (i==MAX-1)?0:++i;
    aux = aux->prox;
  }
}

int devolveTamanho(No *inicio)
{
  int quantos = 0;
  while(inicio != NULL)
  {
    quantos++;
    inicio = inicio->prox;
  }
  return(quantos);
}

No *devolveMeioDaLista(No *inicio, int quantos)
{
  No *meio = inicio;
  int i;
  for(i = 0; i < (quantos/2); i++)
  {
    meio = meio->prox;
  }
  return(meio);
}

void embaralhar1(No **inicio)
{
  Coisa umaCoisa;
  No *aux1, *aux2, *meioDaLista, *inicioAuxiliar = NULL;
  int vezes, quantos, alterna;
  if(*inicio == NULL)
  {
    printf("\nImpossivel embaralhar. Lista vazia.");
  }
  else
  {
    if((*inicio)->prox != NULL) // a lista tem mais de um Nó armazenado
    {
      // a partir daqui embaralha MAXEMBARALHA vezes os Nós da lista
      alterna = 0;
      for(vezes = 0; vezes < MAXEMBARALHA; vezes++)
      {
        quantos = devolveTamanho(*inicio);
        meioDaLista = devolveMeioDaLista(*inicio, quantos);
        aux1 = *inicio;
        aux2 = (*inicio)->prox;
        while(aux2 != meioDaLista)
        {
          aux1 = aux2;
          aux2 = aux2->prox;
        }
        aux1->prox = NULL; //"quebrou" a lista em duas: uma apontada por inicio e outra apontada por meioDaLista
        while(*inicio != NULL || meioDaLista != NULL)
        {
          if(alterna == 0)
          {
            if(*inicio != NULL)
            {
              removerDoInicio(&*inicio, &umaCoisa);
              insereNoFinal(&inicioAuxiliar, umaCoisa);
            }
            if(meioDaLista != NULL)
            {
              removerDoInicio(&meioDaLista, &umaCoisa);
              insereNoFinal(&inicioAuxiliar, umaCoisa);
            }
            alterna = 1;
          }
          else
          {
            if(meioDaLista != NULL)
            {
              removerDoInicio(&meioDaLista, &umaCoisa);
              insereNoFinal(&inicioAuxiliar, umaCoisa);
            }
            if(*inicio != NULL)
            {
              removerDoInicio(&*inicio, &umaCoisa);
              insereNoFinal(&inicioAuxiliar, umaCoisa);
            }
            alterna = 0;
          }
        }
        *inicio = inicioAuxiliar;
        inicioAuxiliar = NULL;
      }
      imprime(*inicio);
      getch();
    }
    else
    {
      printf("\nImpossivel embaralhar. A lista tem somente um elemento.");
    }
  }
}

No *posicionaOPonteiro(int vezes, No *inicio)
{
  No *aux = inicio;
  int i;
  for(i = 0; i < vezes; i++)
  {
    aux = aux->prox;
  }
  return(aux);
}

void embaralhar2(No *inicio)
{
  int i, j, quantos, vezes;
  Coisa auxCoisa;
  No *aux1, *aux2;
  if(inicio == NULL)
  {
    printf("\nImpossivel embaralhar. Lista vazia.");
  }
  else
  {
    if(inicio->prox == NULL) // a lista soh tem um No armazenado
    {
      printf("\nImpossivel embaralhar. A lista tem somente um elemento.");
    }
    else
    {
      quantos = devolveTamanho(inicio);
      for(vezes = 0; vezes < quantos; vezes++)
      {
        i = rand() % quantos;
        aux1 = posicionaOPonteiro(i, inicio);
        j = rand() % quantos;
        aux2 = posicionaOPonteiro(j, inicio);

        auxCoisa = aux1->umaCoisa;
        aux1->umaCoisa = aux2->umaCoisa;
        aux2->umaCoisa = auxCoisa;
      }
      imprime(inicio);
      getch();
    }
  }
}

void ordenar(No **inicio)
{
  No *aux1, *aux2, *qualSaiu, *inicioAuxiliar = NULL;
  Coisa umaCoisa;
  if(*inicio != NULL)
  {
    if((*inicio)->prox == NULL)
    {
      printf("\nImpossivel ordenar. A lista tem somente um elemento.");
    }
    else
    {
      while(*inicio != NULL)
      {
        qualSaiu = *inicio;
        *inicio = (*inicio)->prox;
        qualSaiu->prox = NULL;
        if(inicioAuxiliar == NULL)
        {
          inicioAuxiliar = qualSaiu;
        }
        else
        {
          if(ehMaiorACoisa(inicioAuxiliar->umaCoisa, qualSaiu->umaCoisa)) ///insere no inicio de inicioAuxiliar
          {
            qualSaiu->prox = inicioAuxiliar;
            inicioAuxiliar = qualSaiu;
          }
          else
          {
            aux1 = inicioAuxiliar;
            aux2 = inicioAuxiliar->prox;
            while((aux2 != NULL) && (ehMaiorACoisa(qualSaiu->umaCoisa, aux2->umaCoisa)))
            {
              aux1 = aux2;
              aux2 = aux2->prox;
            }
            aux1->prox = qualSaiu;
            qualSaiu->prox = aux2;
          }
        }
      }
      *inicio = inicioAuxiliar;
      imprime(*inicio);
      getch();
    }
  }
  else
  {
    printf("\nImpossivel ordenar. Lista vazia.");
  }
}

void preencheParaTestar(No **inicio)
{
  Coisa umaCoisa;
  int i;
  for(i = 1; i <= 100; i++)
  {
    umaCoisa.codigo = umaCoisa.peso = i;
    insereNoFinal(&*inicio, umaCoisa);
  }
  imprime(*inicio);
  getch();
}

int main()
{
  No *inicio, *novo;
  Coisa umaCoisa;
  int opcao;
  inicializa(&inicio);
  preencheParaTestar(&inicio); ///tirar a chamada desta função quando for usar de verdade
  do
  {
    system("cls");
    printf("\nOperacoes em LLSE");
    printf("\n 1. Inserir no inicio");
    printf("\n 2. Imprimir");
    printf("\n 3. Inserir no final");
    printf("\n 4. Destruir lista");
    printf("\n 5. Remover do inicio");
    printf("\n 6. Remover do final");
    printf("\n 7. Remover um qualquer");
    printf("\n 8. Pesquisar um no");
    printf("\n 9. Inverter a lista Profissional");
    printf("\n10. Inverter a lista Amador");
    printf("\n11. Salvar em arquivo");
    printf("\n12. Recuperar do arquivo");
    printf("\n13. Repartir a lista");
    printf("\n14. Embaralhar a lista de um jeito");
    printf("\n15. Embaralhar a lista de outro jeito");
    printf("\n16. Ordenar a lista");
    printf("\n 0. Sair");
    printf("\n\nDigite sua opcao: ");
    scanf("%i", &opcao);
    switch(opcao)
    {
      case 1: // inserir no inicio
      {
        umaCoisa = devolveCoisa();
        insereNoInicio(&inicio, umaCoisa);
        break;
      }
      case 2: //imprimir
      {
        imprime(inicio);
        break;
      }
      case 3: // inserir no final
      {
        umaCoisa = devolveCoisa();
        insereNoFinal(&inicio, umaCoisa);
        break;
      }
      case 4: // destruir lista
      {
        char temCerteza;
        do
        {
          fflush(stdin);
          printf("\nTem certeza que deseja destruir a lista (S/N)? ");
          scanf("%c", &temCerteza);
        }
        while(toupper(temCerteza) != 'S' && toupper(temCerteza) != 'N');
        if(toupper(temCerteza) == 'S')
        {
          destruir(&inicio);
        }
        break;
      }
      case 5: // remover do início
      {
        int deuCerto;
        deuCerto = removerDoInicio(&inicio, &umaCoisa);
        if(deuCerto)
        {
          printf("\nNo removido do inicio da lista:");
          imprimeCoisa(umaCoisa);
        }
        break;
      }
      case 6: // remover do final
      {
        int deuCerto;
        deuCerto = removerDoFinal(&inicio, &umaCoisa);
        if(deuCerto)
        {
          printf("\nNo removido do final da lista:");
          imprimeCoisa(umaCoisa);
        }
        break;
      }
      case 7: // remover um qualquer
      {
        int deuCerto=0;
        umaCoisa = devolveCoisa();
        deuCerto = removerUm(&inicio, umaCoisa);
        if(deuCerto)
        {
          printf("\nNo removido da lista");
        }
        else
        {
          printf("\nNo NAO removido da lista");
        }
        break;
      }
      case 8: // pesquisar um noh
      {
        int achou;
        umaCoisa = devolveCoisa();
        achou = pesquisar(inicio, umaCoisa);
        if(achou)
        {
          printf("\nNoh encontrado na lista");
        }
        else
        {
          printf("\nNoh NAO encontrado na lista");
        }
        break;
      }
      case 9: //inverter profissional
      {
        inverterAListaProfissional(&inicio);
        break;
      }
      case 10: //inverter amador
      {
        inverterAListaAmador(&inicio);
        break;
      }
      case 11: //salvar em arquivo
      {
        char nomeArquivo[30];
        fflush(stdin);
        printf("\nDigite o nome do arquivo: ");
        fgets(nomeArquivo,30,stdin);
        salvarEmArquivo(inicio, nomeArquivo);
        break;
      }
      case 12: //recuperar do arquivo
      {
        char continua;
        char nomeArquivo[30];
        fflush(stdin);
        printf("\n A T E N C A O: recuperar do arquivo vai destruir a lista atual");
        printf("\n                para construir a lista nova");
        printf("\nDeseja continuar? (S/N) ");
        scanf("%c", &continua);
        if(toupper(continua) == 'S')
        {
          fflush(stdin);
          printf("\nDigite o nome do arquivo: ");
          fgets(nomeArquivo,30,stdin);
          recuperarDoArquivo(&inicio, nomeArquivo);
        }
        break;
      }
      case 13: // repartir a lista
      {
        No *array[MAX];
        int i;
        for(i = 0; i < MAX; i++)
        {
          inicializa(&array[i]);
        }
        printf("\nRepartindo a lista");
        repartir(inicio, array);
        printf("\nImprimindo as listas repartidas");
        for(i = 0; i < MAX; i++)
        {
          printf("\nLista %i: ", i);
          imprime(array[i]);
        }
        break;
      }
      case 14: // embaralhar a lista do jeito parecido com o embaralhar de cartas
      {
        embaralhar1(&inicio);
        break;
      }
      case 15: // embaralhar a lista trocando as coisas de lugar
      {
        embaralhar2(inicio);
        break;
      }
      case 16:
      {
        ordenar(&inicio);
        break;
      }
      case 0:
      {
        printf("\nSaindo...");
        break;
      }
      default:
      {
        printf("\nOpcao invalida");
      }
    }
    printf("\n");
    system("pause");
  }
  while(opcao != 0);
  return 0;
}
