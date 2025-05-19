#ifndef ATENDIMENTO_H
#define ATENDIMENTO_H

#include "structs.h"

void inicializar_fila();
void enfileirar(Fila *, Lista *, Pilha *);
void desenfileirar(Fila *, Pilha *);
void mostrar_fila(Fila *);

#endif
