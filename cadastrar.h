#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "structs.h"

void inicializar_lista(Lista *lista);
void cadastrar_paciente(Lista *lista);
void consultar_paciente(Lista *lista);
void listar_pacientes(Lista *lista);
void atualizar_paciente(Lista *lista);
void remover_paciente(Lista *lista);

#endif
