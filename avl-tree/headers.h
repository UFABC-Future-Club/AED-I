#pragma once
// Definindo estrutura dos nós e da árvore
typedef struct No
{
  int valor;
  struct No * esq;
  struct No * dir;
  int altura;
} No;

typedef struct 
{
  No * raiz;
} Arvore;

// Funções ABB
Arvore * cria_arvore();
void insere(Arvore *, int);
int arvore_vazia(Arvore *);
// Funções de impressão
void inordem(Arvore *);
void preordem(Arvore *);
void posordem(Arvore *);
// Funções "Simples" AVL
int maior (int, int);
int altura (No *);
int fator_balanceamento(No *);
void balanceamento(No *, Arvore *);
// Funções de rotação da AVL
No * rotacaoRR (No *);
No * rotacaoLL (No *);