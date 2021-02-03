#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main()
{

  Arvore *a1 = cria_arvore();

  int num;
  char proxChar;

  while (scanf("%d%c", &num, &proxChar) == 2)
  {
    insere(a1, num);

    if (proxChar == '\n')
    {
      break;
    }
  }

  inordem(a1);
  preordem(a1);
  // posordem(a1);

  return 0;
}
/* Criando árvore */
Arvore *cria_arvore()
{
  Arvore *nova = (Arvore *)malloc(sizeof(Arvore));
  nova->raiz = NULL;

  return nova;
}
/* Verificando se a árvore está vazia */
int arvore_vazia(Arvore *A)
{
  return (A->raiz == NULL);
}
/* Inserindo Nó */
void insere_no(No *pai, No *n, Arvore *A)
{
  if (pai != NULL)
  {
    /* inserir a esq */
    if (n->valor < pai->valor)
    {
      if (pai->esq == NULL)
      {
        /* esse é o nó folha */
        pai->esq = n;
      }
      /* indo para prox no e chamando func recursiva */
      else
      {
        insere_no(pai->esq, n, A);
      }
    }
    /* insere a direita */
    else if (n->valor > pai->valor)
    {
      if (pai->dir == NULL)
      {
        pai->dir = n;
      }
      else
      {
        insere_no(pai->dir, n, A);
      }
    }
    /* altualizando altura */
    balanceamento(pai, A);
    pai->altura = 1 + maior(altura(pai->esq), altura(pai->dir));
  }
}
/* Insere um novo nó na árvore binária */
void insere(Arvore *A, int v)
{
  No *novo = (No *)malloc(sizeof(No));
  novo->valor = v;
  novo->esq = NULL;
  novo->dir = NULL;
  novo->altura = 1;

  if (arvore_vazia(A))
  {
    A->raiz = novo;
  }
  else
  {
    insere_no(A->raiz, novo, A);
  }

  return;
}
/* Impressões */
/* In Ordem */
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
void inordem(Arvore *A)
{
  imprime_inordem(A->raiz);
  printf("\n");

  return;
}
/* Pré ordem */
void imprime_preordem(No *n)
{
  if (n != NULL)
  {
    printf("%d ", n->valor);
    imprime_preordem(n->esq);
    imprime_preordem(n->dir);
  }
  return;
}
void preordem(Arvore *A)
{
  imprime_preordem(A->raiz);
  printf("\n");

  return;
}
/* Pós Ordem */
void imprime_posordem(No *n)
{
  if (n != NULL)
  {
    imprime_posordem(n->esq);
    imprime_posordem(n->dir);
    printf("%d ", n->valor);
  }
  return;
}
void posordem(Arvore *A)
{
  imprime_posordem(A->raiz);
  printf("\n");

  return;
}

/* Obter maior entre 2 números */
int maior(int a, int b)
{
  if (a > b)
  {
    return a;
  }
  else
  {
    return b;
  }
}
/* função para retornar a altura */
int altura(No *n)
{
  if (n == NULL)
  {
    return 0;
  }
  else
  {
    return n->altura;
  }
}
/* fb = hdir - hesq */
int fator_balanceamento(No *n)
{
  if (n == NULL)
  {
    return 0;
  }
  else
  {
    return (altura(n->dir) - altura(n->esq));
  }
}
void balanceamento(No *n, Arvore *A)
{
  if (n != NULL)
  {
    balanceamento(n->esq, A);
    int bl = fator_balanceamento(n);
    /* Arvore direita está maior */
    if (bl > 1)
    {
      int sinalRaiz = fator_balanceamento(A->raiz->dir);
      if ((bl * sinalRaiz) < 0)
      {
        /* Se os sinais são diferentes é uma rotação dupla */
        /* Rotação RL */
        printf("Rotação RL\n");
        A->raiz->dir = rotacaoLL(A->raiz->dir);
        A->raiz = rotacaoRR(A->raiz);
      }
      /* Rotação RR */
      else
      {
        /* Verificando se irá rotacionar a raiz */
        /* Se o valor da direita da raiz for maior que o atual, irá rotacionar*/
        if (n->valor < A->raiz->dir->valor)
        {
          // printf("n->valor %d a->raiz->dir->valor %d\n", n->valor, A->raiz->dir->valor);
          printf("Rotação LL t1 \n");
          A->raiz = rotacaoRR(n);
        }
        /* Não irá rotacionar a raiz */
        else
        {
          printf("n->valor %d a->raiz->dir->valor %d\n", n->valor, A->raiz->dir->valor);
          A->raiz->dir = rotacaoRR(n);
          printf("Rotação LL t2 \n");
        }
      }
    }
    /*Arvore esquerda está maior */
    else if (bl < -1)
    {
      int sinalRaiz = fator_balanceamento(A->raiz->esq);
      /* Se os sinais são diferentes é uma rotação dupla */
      if ((sinalRaiz * bl) < 0)
      {

        // Rotação LR
        printf("Rotação LR\n");
        A->raiz->esq = rotacaoRR(A->raiz->esq);
        A->raiz = rotacaoLL(A->raiz);
      }
      /* Rotação LL */
      else
      {
        /* Verificando de irá ou não rotacionar a raiz */
        /* Não irá rotacionar a raiz */
        if (n->valor < A->raiz->esq->valor)
        {
          printf("Rotação RR t1 \n");
          A->raiz = rotacaoLL(A->raiz);
        }
        /* Irá rotacionar a raiz */
        else
        {
          printf("Rotação RR t2 \n");
          A->raiz->esq = rotacaoLL(n);
        }
      }
    }
    balanceamento(n->dir, A);
  }
}
/* Rotacionando da direita para esquerda */
No *rotacaoRR(No *n)
{
  No *p, *tmp;

  if (n != NULL)
  {

    tmp = n;
    p = n->dir;
    tmp->dir = p->esq;
    p->esq = tmp;

    tmp->altura = 1 + maior(altura(tmp->esq), altura(tmp->dir));
    p->altura = maior(altura(p->dir), tmp->altura) + 1;

    n = p;
  }

  return n;
}
/* Rotacionando da esquerda para direita */
No *rotacaoLL(No *n)
{
  No *p, *tmp;

  if (n != NULL)
  {

    tmp = n;
    p = n->esq;
    tmp->esq = p->dir;
    p->dir = tmp;

    tmp->altura = 1 + maior(altura(tmp->esq), altura(tmp->dir));
    p->altura = maior(altura(p->esq), tmp->altura) + 1;

    n = p;
  }

  return n;
}