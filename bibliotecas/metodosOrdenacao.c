#include <stdio.h>

void bubbleSort(int vetor[], int tamanho);
void selectionSort(int vetor[], int tamanho);
void insertionSort(int vetor[], int tamanho);
void quickSort(int vetor[], int inicio, int fim);
void merge(int vetor[], int tamanho);
void mergeSort(int vetor[], int tamanho);
//<- FUNCOES PARA HEAP SORT ->
void trocar(int *heap, int i, int j);
void maxHeapify(int *heap, int tamanho, int i);
void criarMaxHeap(int *heap, int tamanho);
void heapSort(int *heap, int tamanho);

//Complexidade O(n2) -> Os maiores elementros "flutuam" para o topo
void bubbleSort(int vetor[], int tamanho)
{
  int i, j;
  for (i = tamanho - 1; i > 0; i--)
  {
    for (j = 0; j < i; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        int auxiliar;
        auxiliar = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = auxiliar;
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
