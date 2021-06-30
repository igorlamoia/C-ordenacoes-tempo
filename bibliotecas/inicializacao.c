void inicializarAleatoriamente(int vetor[], int n);
void inicializarOrdemCrescente(int vetor[], int n);
void inicializarOrdemDecrescente(int vetor[], int n);

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
