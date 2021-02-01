#include <stdio.h>

void insere_vetor(int *, int);
void quicksort(int *, int, int);
void imprime_vetor(int *, int);

int main()
{
  printf("Digite o tamanho do vetor:\n");

  int tamanho;
  scanf("%d", &tamanho);

  if (tamanho > 0)
  {
    int vetor[tamanho];

    insere_vetor(vetor, tamanho);
    quicksort(vetor, 0, tamanho - 1);
    imprime_vetor(vetor, tamanho);
  }

  return 0;
}

void insere_vetor(int *vetor, int tamanho)
{
  printf("Digite o(s) elemento(s) do vetor:\n");

  for (int i = 0; i < tamanho; i++)
  {
    scanf("%d", &vetor[i]);
  }
}

void troca(int *i, int *j)
{
  int tmp;
  tmp = *i;
  *i = *j;
  *j = tmp;
}

int particiona(int *v, int p, int r)
{
  int j, pivo, k;

  pivo = v[r];
  j = p;

  for (k = p; k <= r; k++)
  {
    if (v[k] < pivo)
    {
      troca(&v[k], &v[j]);
      j++;
    }
  }

  v[r] = v[j];
  v[j] = pivo;

  return j;
}
void quicksort(int *v, int p, int r)
{
  int j;

  if (p < r)
  {
    j = particiona(v, p, r);

    quicksort(v, p, j - 1);
    quicksort(v, j + 1, r);
  }
}

void imprime_vetor(int *vetor, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }

  printf("\n");
}