#ifndef ATENDPRIOR_H
#define ATENDPRIOR_H

#include "structs.h"
#include "cadastrar.h"

typedef struct {
    Registro dados[20];
    int qtde;
} Heap;

int filho_esq(int pai);
int filho_dir(int pai);
int pai(int filho);
int ultimo_pai(Heap *h);
void peneirar(Heap *h, int pai);
void construir(Heap *h);
void inserir(Heap *h, Registro reg);
void remover(Heap *h);
void enfileirar_prior(Fila *fila, Lista *lista, Heap *heap);
void desenfileirar_prior(Fila *fila);


#endif //ATENDPRIOR_H
