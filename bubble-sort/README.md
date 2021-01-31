# Bubble Sort

O algoritmo de ordenação **Bubble Sort**, ou **Ordenação por flutuação**, é um dos mais simples. O intuito desse algoritmo é percorrer o vetor várias vezes, e a cada *loop*, os elementos são comparados entre si, e sempre o maior valor não ordenado é empurrado para as posições finais do vetor.

O GIF abaixo mostra essa lógica em funcionamento:

![GIF do algoritmo de Bubble Sort](https://upload.wikimedia.org/wikipedia/commons/thumb/5/54/Sorting_bubblesort_anim.gif/250px-Sorting_bubblesort_anim.gif)

### Implementação

O código completo está em: [main.c](./main.c)

```c
void bubble_sort(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                // troca posição
                int tmp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = tmp;
            }
        }
    }
}
```

### Complexidade

| Algoritmo             | Melhor caso     | Caso Médio          | Pior caso           |
| --------------------- | :-------------: | :-----------------: | :-----------------: |
| **Bubble sort**       | n               | n<sup>2</sup>       | n<sup>2</sup>       |

### Veja mais

- [Wikipedia](https://pt.wikipedia.org/wiki/Bubble_sort)
- [GeeksforGeeks](https://www.geeksforgeeks.org/bubble-sort/)