# QuickSort

O algoritmo de **Quicksort** é um método de ordenação rápido e eficiente. Esse algoritmo segue os seguintes passos:

1. Um elemento é escolhido como **pivô**, esse elemento pode ser o último, o primeiro, ou um aleatório, para esse exemplo iremos selecionar o último elemento como pivô.

2. No segundo passo devemos particionar o vetor em 2 sub listas, mais a direita os valores maiores que o valor do pivô, e mais a esquerda os valores menores que o pivô, após trocar a posição dos elementos para obdecer essa regra, o pivô é colocado no indice correto, que divide as duas partes.

3. Aplicamos os passos acima recursivamente para todas as sub listas geradas, até que o vetor esteja ordenado.

O GIF abaixo mostra essa lógica em funcionamento:

![GIF do algoritmo de QuickSort](https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)

### Implementação

O código completo está em: [main.c](./main.c)

```c
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
```

### Complexidade

| Algoritmo             | Melhor caso     | Caso Médio          | Pior caso           |
| --------------------- | :-------------: | :-----------------: | :-----------------: |
| **Bubble sort**       | n&nbsp;log(n)   | n&nbsp;log(n)       | n<sup>2</sup>       |

### Veja mais

- [Wikipedia](https://pt.wikipedia.org/wiki/Quicksort)
- [GeeksforGeeks](https://www.geeksforgeeks.org/quick-sort/)