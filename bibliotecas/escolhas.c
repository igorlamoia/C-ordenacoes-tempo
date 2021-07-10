#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "metodosOrdenacao.h"
#include "inicializacao.h"

// Escolha do menuMetodo
void escolherMetodo(char opcao[], int vetor[], int TAM)
{
  double start, stop, elapsed; // variaveis para medir o tempo
  srand(time(NULL));
  switch (opcao[0])
  {
  case '1':
    start = (double)clock() / CLOCKS_PER_SEC;
    bubbleSort(vetor, TAM);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\n\n\t\t\tTempo total em segundos: %f\n\n\n", elapsed);
    break;
  case '2':
    start = (double)clock() / CLOCKS_PER_SEC;
    selectionSort(vetor, TAM);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\n\n\t\t\tTempo total em segundos: %f\n\n\n", elapsed);
    break;
  case '3':
    start = (double)clock() / CLOCKS_PER_SEC;
    insertionSort(vetor, TAM);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\n\n\t\t\tTempo total em segundos: %f\n\n\n", elapsed);
    break;
  case '4':
    start = (double)clock() / CLOCKS_PER_SEC;
    quickSort(vetor, 0, TAM);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\n\n\t\t\tTempo total em segundos: %f\n\n\n", elapsed);
    break;
  case '5':
    start = (double)clock() / CLOCKS_PER_SEC;
    mergeSort(vetor, TAM);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\n\n\t\t\tTempo total em segundos: %f\n\n\n", elapsed);
    break;
  case '6':
    start = (double)clock() / CLOCKS_PER_SEC;
    heapSort(vetor, TAM);
    stop = (double)clock() / CLOCKS_PER_SEC;
    elapsed = stop - start;
    printf("\n\n\t\t\tTempo total em segundos: %f\n\n\n", elapsed);
    break;
  default:
    printf("\n\n\t\t\tMetodo incompativel\n");
    break;
  }
}

// Cria vetor com números ordenados a partir da escolha
void escolherOrdenacao(char opcao[], int vetor[], int TAM)
{
  switch (opcao[0])
  {
  case '1':
    inicializarAleatoriamente(vetor, TAM);
    break;
  case '2':
    inicializarOrdemCrescente(vetor, TAM);
    break;
  case '3':
    inicializarOrdemDecrescente(vetor, TAM);
    break;
  default:
    printf("\n\n\t\t\tOrdenacao inexistente\n");
    break;
  }
}