#include <stdlib.h>
#include "./bibliotecas/escolhas.c"
#include "./bibliotecas/inicializacao.c"
#include "./bibliotecas/menu.c"
#include "./bibliotecas/metodosOrdenacao.c"

// #define TAM 100000
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
