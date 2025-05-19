#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include "structs.h"
#include "cadastrar.h"



void inicializar_fila();
void enfileirar(Fila *fila, Lista *lista, Pilha *pilha);
void desenfileirar(Fila *fila, Pilha *pilha);
void mostrar_fila(Fila *fila);

#endif
