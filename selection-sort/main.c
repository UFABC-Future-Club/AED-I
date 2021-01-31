#include <stdio.h>

void insere_vetor(int *, int);
void selection_sort(int *, int);
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
    selection_sort(vetor, tamanho);
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

int menor(int *v, int a, int b)
{
  int i, index_menor_valor = a;
  for (i = a + 1; i <= b; i++)
  {
    if (v[i] < v[index_menor_valor])
    {
      index_menor_valor = i;
    }
  }
  return index_menor_valor;
}

void selection_sort(int *vetor, int tamanho)
{
  int tmp;
  int index_menor_valor = 0;
  for (int i = 0; i < tamanho; i++)
  {
    // Obtem o indice do menor valor não ordenado
    index_menor_valor = menor(vetor, i, tamanho - 1);
    // Troco a posição que o menor valor estava pela que ele deveria estar assim que ordenado
    tmp = vetor[index_menor_valor];
    vetor[index_menor_valor] = vetor[i];
    vetor[i] = tmp;
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