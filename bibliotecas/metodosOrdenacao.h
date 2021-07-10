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