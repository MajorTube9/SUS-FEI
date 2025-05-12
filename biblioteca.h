#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef struct {
    char nome[100];
    int idade;
    char cpf[12];
} Paciente;

void cadastrar_paciente();
void consultar_paciente();
void listar_pacientes();
void atualizar_paciente();
void remover_paciente();

#endif
