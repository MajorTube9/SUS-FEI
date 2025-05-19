#ifndef DESFAZER_H
#define DESFAZER_H

#include "structs.h"

EPilha *inicializar_epilha(Registro reg, int operacao);
Pilha *inicializar_pilha();
void push(Pilha *pilha, Registro reg, int operacao);
int desfazerr(Pilha *pilha, Fila *fila);
void mostrar_pilha(Pilha *pilha);

#endif
