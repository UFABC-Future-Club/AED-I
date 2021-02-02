#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
  int valor;
  struct No *esq;
  struct No *dir;
} No;

typedef struct
{
  No *raiz;
} Arvore;

Arvore *cria_arvore();

void insere(Arvore *, int);

No *retira(Arvore *, int);

No *busca(Arvore *, int);

int arvore_vazia(Arvore *);

void inordem(Arvore *);

void preordem(Arvore *);

void posordem(Arvore *);

int main()
{
  Arvore *a1 = cria_arvore();

  int numero;
  char proxChar;

  while (scanf("%d%c", &numero, &proxChar) == 2)
  {
    insere(a1, numero);
    if (proxChar == '\n')
      break;
  }

  inordem(a1);

  return 0;
}

/* Cria uma árvore vazia */
Arvore *cria_arvore()
{
  Arvore *nova = (Arvore *)malloc(sizeof(Arvore));
  nova->raiz = NULL;

  return nova;
}

int arvore_vazia(Arvore *A)
{
  return (A->raiz == NULL);
}

/* Função recursiva que insere o no "n" na subárvore em que o no "pai"
   eh raiz
*/
void insere_no(No *pai, No *n)
{
  if (pai != NULL)
  {
    if (n->valor < pai->valor)
    {
      if (pai->esq == NULL)
      {
        pai->esq = n;
      }
      else
      {
        insere_no(pai->esq, n);
      }
    }
    else if (n->valor > pai->valor)
    {
      if (pai->dir == NULL)
      {
        pai->dir = n;
      }
      else
      {
        insere_no(pai->dir, n);
      }
    }
  }

  return;
}

/* Insere um novo nó na arvore binária de busca "A" contendo
   o valor "v"
*/
void insere(Arvore *A, int v)
{
  No *novo = (No *)malloc(sizeof(No));
  novo->valor = v;
  novo->esq = NULL;
  novo->dir = NULL;

  if (arvore_vazia(A))
  {
    A->raiz = novo;
  }
  else
  {
    insere_no(A->raiz, novo);
  }

  return;
}

/* Função recursiva que imprime os elementos da subárvore cuja raiz
   eh "n" usando rastreamento inordem
*/

void imprime_inordem(No *n)
{
  if (n != NULL)
  {
    imprime_inordem(n->esq);
    printf("%d ", n->valor);
    imprime_inordem(n->dir);
  }

  return;
}

/* Imprime na tela os elmentos da árvore "A" rastreada usando
   o algoritmo "esquerda-raiz-direita"
*/
void inordem(Arvore *A)
{
  imprime_inordem(A->raiz);

  return;
}