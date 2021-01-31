# Insertion Sort

O algoritmo de ordenação **Insertion Sort**, ou **Ordenação por inserção**, é um dos mais simples. Sua ideia é partir de um vetor pequeno, e já inserir os valores de forma ordenada, iniciamos na posição 1 do vetor, e verificamos se o indice 0 e indice 1 estão ordenados, se não estiverem, trocamos suas posições e assim que ordenados partimos para a posição, verificamos se o o indice 0, 1 e 2 estão ordenados, caso negativo, inserimos o valor desordenado na sua posição correta, e assim sucessivamente até finalizarmos o vetor.

O **Insertion Sort** é menos eficiente em entradas grandes, do que algoritmos mais avançados, como quicksort, heapsort ou merge sort.

O GIF abaixo mostra essa lógica em funcionamento:

![GIF do algoritmo de Insertion Sort](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

### Implementação

O código completo está em: [main.c](./main.c)

```c
void insertion_sort(int *vetor, int tamanho)
{
  int i, j, tmp;

  for (i = 1; i < tamanho; i++)
  {
    tmp = vetor[i];

    for (j = i - 1; j >= 0 && vetor[j] > tmp; j--)
    {
      vetor[j + 1] = vetor[j];
    }
    
    vetor[j + 1] = tmp;
  }
}
```

### Complexidade

| Algoritmo             | Melhor caso     | Caso Médio          | Pior caso           |
| --------------------- | :-------------: | :-----------------: | :-----------------: |
| **Bubble sort**       | n               | n<sup>2</sup>       | n<sup>2</sup>       |

### Veja mais

- [Wikipedia](https://en.wikipedia.org/wiki/Insertion_sort)
- [GeeksforGeeks](https://www.geeksforgeeks.org/insertion-sort/)