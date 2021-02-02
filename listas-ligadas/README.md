# Listas Ligadas (_Linked Lists_)

As listas ligadas, listas encadeadas ou _linked lists_ são estruturas de dados que permitem o armazenamento de dados de forma iterável sem comprimento fixo. Ou seja, é possível armazenar valores como em um vetor, porém sem precisar se preocupar com seu tamanho fixo.

Listas ligadas são compostas por nós. Cada nó é uma estrutura composta por um **valor** e um ponteiro, que aponta para o próximo nó da lista (ou no caso do ultimo nó, será vazio).

![Lista Ligada](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6d/Singly-linked-list.svg/408px-Singly-linked-list.svg.png)

```c
struct no
{
    int valor;
    struct no* proximo;
}
```

## Vantagens

- Como listas ligadas não possuem tamanho fixo, essa estrutura pode ser muito vantajosa quando é preciso armazenar valores em uma lista de tamanho desconhecido ou variável.
- A operação de inserção no meio de uma lista é muito mais simples que a operação de inserção em um vetor, onde é preciso reatribuir todos os elementos a partir do item inserido e possivelmente alocar um novo vetor para inserir o elemento.

## Desvantagens

- Para inserir, excluir e armazenar um elemento, é preciso passar por todos os elementos da lista até o item que será alterado.****
- Além do espaço ocupado pelo valor, cada nó possui um ponteiro, aumentando significativamente a memória ocupada pela lista.
- É possível iterar através de um vetor do fim ao começo, porém isso não é possível com listas ligadas (exceto se listas ligadas duplas forem usadas, que ocupam ainda mais memória por possuirem dois ponteiros por nó).

## Veja mais

- [Wikipédia](https://pt.wikipedia.org/wiki/Lista_ligada)
- [learn-c.org](https://www.learn-c.org/en/Linked_lists)
