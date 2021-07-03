#include <stdlib.h>
#include "./bibliotecas/escolhas.c"            // Escolher métodos e ordenação inicial do vetor
#include "./bibliotecas/inicializacao.c"      // Funções que irão inicializar o vetor de acordo com a escolha
#include "./bibliotecas/menu.c"              // Mini interface para auxiliar nas escolhas
#include "./bibliotecas/metodosOrdenacao.c" // Funções que, de fato, ordenarão o vetor

#define TAM 100000

void imprimir(int vetor[], int tamanho);

int main()
{
  char opcao[2];
  int vetor[TAM];

  do
  {
    menuOrdenacao();
    printf("\t\t\t");
    gets(opcao);

    if (opcao[0] == '4')
      exit(0); // Forçando saída do programa

    escolherOrdenacao(opcao, vetor, TAM);
    // imprimir(vetor, TAM);

    menuMetodo();
    printf("\t\t\t");
    gets(opcao);
    escolherMetodo(opcao, vetor, TAM);
    // imprimir(vetor, TAM);

  } while (opcao[0] != '7');

  return 0;
}

void imprimir(int vetor[], int tamanho)
{
  int contador;
  printf("\n\t\t\t");
  for (contador = 0; contador < tamanho; contador++)
    printf("%d  ", vetor[contador]);
  printf("\n");
}
