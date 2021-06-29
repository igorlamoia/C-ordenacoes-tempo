#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #define TAM 100000
#define TAM 10

void menuOrdenacao();
void escolherOrdenacao(char opcao[], int vetor[]);
void inicializarAleatoriamente(int vetor[], int n);
void inicializarOrdemCrescente(int vetor[], int n);
void inicializarOrdemDecrescente(int vetor[], int n);
void menuMetodo();
void escolherMetodo(char opcao[], int vetor[]);
void bubbleSort(int vetor[], int tamanho);
void selectionSort(int vetor[], int tamanho);
void insertionSort(int vetor[], int tamanho);
void quickSort(int vetor[], int inicio, int fim);
void merge(int vetor[], int tamanho);
void mergeSort(int vetor[], int tamanho);
void imprimir(int vetor[], int tamanho);
//<- FUNCOES PARA HEAP SORT ->
void trocar(int *heap, int i, int j);
void maxHeapify(int *heap, int tamanho, int i);
void criarMaxHeap(int *heap, int tamanho);
void heapSort(int *heap, int tamanho);

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

    escolherOrdenacao(opcao, vetor);
    imprimir(vetor, TAM);

    menuMetodo();
    printf("\t\t\t");
    gets(opcao);
    escolherMetodo(opcao, vetor);
    imprimir(vetor, TAM);

  } while (opcao[0] != '7');

  return 0;
}

// Mini interface para Ordenação do Vetor
void menuOrdenacao()
{
  printf("\n");
  printf("\t\t\t ----------------- \n");
  printf("\t\t\t|    Ordenacao    |\n");
  printf("\t\t\t|-----------------|\n");
  printf("\t\t\t| 1-Aleatoria     |\n");
  printf("\t\t\t| 2-Crescente     |\n");
  printf("\t\t\t| 3-Decrescente   |\n");
  printf("\t\t\t -----------------\n");
  printf("\n\t\t\t Digite 4 para sair\n");
}

// Mini interface para Métodos
void menuMetodo()
{
  printf("\t\t\t ----------------- \n");
  printf("\t\t\t|  Metodos Sort   |\n");
  printf("\t\t\t|-----------------|\n");
  printf("\t\t\t| 1-Bubble        |\n");
  printf("\t\t\t| 2-Selection     |\n");
  printf("\t\t\t| 3-Insert        |\n");
  printf("\t\t\t| 4-Quick         |\n");
  printf("\t\t\t| 5-Merge         |\n");
  printf("\t\t\t| 6-Heap          |\n");
  printf("\t\t\t -----------------\n");
  printf("\n\t\t\t Digite 7 para sair\n");
}

// Escolha do menuMetodo
void escolherMetodo(char opcao[], int vetor[])
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
void escolherOrdenacao(char opcao[], int vetor[])
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

//Complexidade O(n2) -> Os maiores elementros "flutuam" para o topo
void bubbleSort(int vetor[], int tamanho)
{
  int i, contador, auxiliar;

  for (contador = 1; contador < tamanho; contador++)
  {
    for (i = 0; i < tamanho - 1; i++)
    {
      if (vetor[i] > vetor[i + 1])
      {
        auxiliar = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = auxiliar;
      }
    }
  }
}

//Complexidade assintótica -  n² comparações Seleciona o MENOR a cada passada
void selectionSort(int vetor[], int tamanho)
{
  int i, j, min, auxiliar;

  for (i = 0; i < (tamanho - 1); i++)
  {
    // Min -> Primeiro número ainda não ordenado
    min = i;
    for (j = i + 1; j < tamanho; j++)
    {
      if (vetor[j] < vetor[min])
      {
        min = j;
      }
    }
    // if minimo != do 1º numero não ordenado, realizar troca
    if (i != min)
    {
      auxiliar = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = auxiliar;
    }
  }
}

// Ordena o início até o fim, ignorando os elementos mais a direita. Pior caso n² comparações, melhor: n comparações
void insertionSort(int vetor[], int tamanho)
{
  int i, selecionado, j;
  for (i = 1; i < tamanho; i++)
  {
    selecionado = vetor[i];
    j = i - 1;
    while (j >= 0 && vetor[j] > selecionado)
    {
      vetor[j + 1] = vetor[j];
      j = j - 1;
    }
    vetor[j + 1] = selecionado;
  }
}

//Complexidade Θ(nlogn) -> o baseado em divisão e conquista.
void quickSort(int vetor[], int inicio, int fim)
{
  int i, j, pivo, aux;
  i = inicio;
  j = fim - 1;
  pivo = vetor[(inicio + fim) / 2];

  while (i <= j)
  {
    while (vetor[i] < pivo && i < fim)
      i++;
    while (vetor[j] > pivo && j > inicio)
      j--;
    if (i <= j)
    {
      aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
      i++;
      j--;
    }
  }
  if (j > inicio)
    quickSort(vetor, inicio, j + 1);
  if (i < fim)
    quickSort(vetor, i, fim);
}

void inicializarAleatoriamente(int vetor[], int tamanho)
{
  int i;
  for (i = 0; i < tamanho; i++)
    vetor[i] = rand();
}

void inicializarOrdemCrescente(int vetor[], int tamanho)
{
  int i;
  for (i = 0; i < tamanho; i++)
    vetor[i] = i;
}

void inicializarOrdemDecrescente(int vetor[], int tamanho)
{
  int i;
  for (i = 0; i < tamanho; i++)
    vetor[i] = tamanho - i;
}

void merge(int vetor[], int tamanho)
{
  int mid;
  int i, j, k;
  int *tmp;
  tmp = (int *)malloc(tamanho * sizeof(int));
  if (tmp == NULL)
  {
    exit(1);
  }
  mid = tamanho / 2;
  i = 0;
  j = mid;
  k = 0;
  while (i < mid && j < tamanho)
  {
    if (vetor[i] < vetor[j])
    {
      tmp[k] = vetor[i];
      ++i;
    }
    else
    {
      tmp[k] = vetor[j];
      ++j;
    }
    ++k;
  }
  if (i == mid)
  {
    while (j < tamanho)
    {
      tmp[k] = vetor[j];
      ++j;
      ++k;
    }
  }
  else
  {
    while (i < mid)
    {
      tmp[k] = vetor[i];
      ++i;
      ++k;
    }
  }
  for (i = 0; i < tamanho; ++i)
  {
    vetor[i] = tmp[i];
  }
  free(tmp);
}

void mergeSort(int vetor[], int tamanho)
{
  int mid;

  if (tamanho > 1)
  {
    mid = tamanho / 2;
    mergeSort(vetor, mid);
    mergeSort(vetor + mid, tamanho - mid);
    merge(vetor, tamanho);
  }
}

void imprimir(int vetor[], int tamanho)
{
  int contador;
  printf("\n\t\t\t");
  for (contador = 0; contador < tamanho; contador++)
    printf("%d  ", vetor[contador]);
  printf("\n");
}

void trocar(int *heap, int i, int j)
{
  int aux;

  aux = heap[i];
  heap[i] = heap[j];
  heap[j] = aux;
}

void maxHeapify(int *heap, int tamanho, int i)
{
  int maior = i;
  int esquerda = (2 * i) + 1;
  int direita = (2 * i) + 2;

  if (esquerda < tamanho && heap[esquerda] > heap[maior])
    maior = esquerda;

  if (direita < tamanho && heap[direita] > heap[maior])
    maior = direita;

  if (maior != i)
  {
    trocar(heap, i, maior);

    maxHeapify(heap, tamanho, maior);
  }
}

void criarMaxHeap(int *heap, int tamanho)
{
  int i;

  for (i = (tamanho / 2) - 1; i >= 0; i--)
    maxHeapify(heap, tamanho, i);
}

void heapSort(int *heap, int tamanho)
{
  criarMaxHeap(heap, tamanho);

  int i;

  for (i = tamanho - 1; i > 0; i--)
  {
    trocar(heap, 0, i);
    maxHeapify(heap, i, 0);
  }
}
