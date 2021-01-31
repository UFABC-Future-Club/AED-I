# Selection Sort

O algoritmo de ordenação **Selection Sort**, ou **Ordenação por seleção**, é um dos mais simples. Ele basicamente seleciona o menor valor não ordernado o insere ma primeira posição não ordenada, até finalmente ordenar todos os elementos.

O GIF abaixo mostra essa lógica em funcionamento:

![GIF do algoritmo de Selection Sort](https://miro.medium.com/max/700/1*5WXRN62ddiM_Gcf4GDdCZg.gif)

### Implementação

O código completo está em: [main.c](./main.c)

```c
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
    index_menor_valor = menor(vetor, i, tamanho - 1);

    tmp = vetor[index_menor_valor];
    vetor[index_menor_valor] = vetor[i];
    vetor[i] = tmp;
  }
}
```

### Complexidade

| Algoritmo             | Melhor caso     | Caso Médio          | Pior caso           |
| --------------------- | :-------------: | :-----------------: | :-----------------: |
| **Bubble sort**       | n<sup>2</sup>   | n<sup>2</sup>       | n<sup>2</sup>       |

### Veja mais

- [Wikipedia](https://en.wikipedia.org/wiki/selection_sort)
- [GeeksforGeeks](https://www.geeksforgeeks.org/selection-sort/)