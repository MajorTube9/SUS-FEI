#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef struct {
    char nome[100];
    int idade;
    char cpf[12];
} Paciente;

typedef struct Elista {
    Paciente dados;
    struct Elista *proximo;
} Elista;

typedef struct {
    Elista *inicio;
    int qtde;
} Lista;

void inicializar_lista(Lista *lista);
void cadastrar_paciente(Lista *lista);
void consultar_paciente(Lista *lista);
void listar_pacientes(Lista *lista);
void atualizar_paciente(Lista *lista);
void remover_paciente(Lista *lista);

#endif
