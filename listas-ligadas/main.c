#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} no;

no* criar_no(int);
no* inserir_final(no*, int);
void imprimir_lista(no*);
void liberar_lista(no*);

int main()
{
    int entrada = 0;
    no *lista_exemplo = NULL;
    while(entrada != -1)
    {   
        printf("Digite o próximo elemento da lista (ou -1 para encerrar):\n");
        scanf("%d", &entrada);
        if (entrada != -1)
            lista_exemplo = inserir_final(lista_exemplo, entrada);
    }
    imprimir_lista(lista_exemplo);
    liberar_lista(lista_exemplo);
    return 0;
}

no* criar_no(int valor)
{
    no *novo = malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

no* inserir_final(no *lista, int valor)
{
    /**
      * Se a lista não foi iniciada, basta criar um nó e o atribuir ao ponteiro da lista.
      * Caso já exista, é preciso:
      * - Percorrer a lista toda para chegar ao seu último nó
      * - Criar um novo nó e o atribuir como próximo elemento do último nó.
      **/
    if (lista == NULL)
        return criar_no(valor);
    no *fim = lista;
    while (fim->proximo != NULL)
        fim = fim->proximo;
    fim->proximo = criar_no(valor);
    return lista;
}

void imprimir_lista(no *lista)
{
    no *atual = lista;
    while (atual != NULL)
    {
        printf("%d", atual->valor);
        atual = atual->proximo;
    }
}

void liberar_lista(no *lista)
{
    no *atual = lista, *alvo;
    while (atual != NULL)
    {
        alvo = atual;
        atual = atual->proximo;
        free(alvo);
    }
}
