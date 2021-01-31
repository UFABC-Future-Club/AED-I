#include <stdio.h>

void insere_vetor(int *, int);
void insertion_sort(int *, int);
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
    insertion_sort(vetor, tamanho);
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

void insertion_sort(int *vetor, int tamanho)
{

  int i, j, tmp;
  /**
  * O vetor será percorrido até o último elemento
  **/
  for (i = 1; i < tamanho; i++)
  {
    tmp = vetor[i];

    /**
     * Cada vez que o vetor é percorrido, será executado outro laço, percorrendo no sentido inverso,
     * verificando se o indice atual é menor que o valor dos indices a esquerda, caso seja, significa que
     * o vetor desordenado, então ele verifica qual posição deve ser inserido esse valor para que o vetor esteja 
     * ordenado
     **/
    for (j = i - 1; j >= 0 && vetor[j] > tmp; j--)
    {
      vetor[j + 1] = vetor[j];
    }

    vetor[j + 1] = tmp;
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