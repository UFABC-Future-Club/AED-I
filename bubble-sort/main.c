#include <stdio.h>

void insere_vetor(int *, int);
void bubble_sort(int *, int);
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
        bubble_sort(vetor, tamanho);
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

void bubble_sort(int *vetor, int tamanho)
{
    /**
     * O vetor será percorrido até o penúltimo elemento
     **/
    for (int i = 0; i < tamanho - 1; i++)
    {
        /**
         * Cada vez que o vetor é percorrido, será executado outro laço, percorrendo do índice 0 
         * até o índice X do vetor, que no caso é: (tamanho - i - 1), pois sempre que esse laço 
         * é executado, os maiores valores são ordenados no final do vetor, não há a necessidade 
         * de percorrer novamente os valores já ordenados.
         **/
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            /**
             * É verificado se o valor na posição atual é maior que o da prox.
             * Caso positivo será invertida a posição dos elementos
             **/
            if (vetor[j] > vetor[j + 1])
            {
                int tmp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = tmp;
            }
        }
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