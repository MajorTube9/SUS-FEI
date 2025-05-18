#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include "structs.h"
#include "cadastrar.h"

typedef struct Efila{
    Registro dados;
    struct Efila *proximo;
    struct Efila *anterior;
} Efila;

typedef struct {
    Efila *head;
    Efila *tail;
    int qtde;
} Fila;

void inicializar_fila();
void enfileirar(Fila *fila, Lista *lista);
void mostrar_fila(Fila *fila);

#endif
