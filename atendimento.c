#include "atendimento.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializa a fila dinâmica
void inicializar_fila(Fila *fila) {
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;
}

// Enfileirar um paciente na fila
void enfileirar(Fila *fila) {
    Efila *novo = (Efila*) malloc(sizeof(Efila));
    if (fila->qtde == 0) {
        fila->head = novo;
    } else {
        fila->tail->proximo = novo;
        novo->anterior = fila->tail;
    }
    fila->tail = novo;
    fila->qtde++;
}
