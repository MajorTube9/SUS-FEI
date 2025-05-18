#include "atendimento.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastrar.h"

// Inicializa a fila dinâmica
void inicializar_fila(Fila *fila) {
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;
}

// Enfileirar um paciente na fila
void enfileirar(Fila *fila, Lista *lista) {
    if (lista->inicio == NULL) {
        printf("A lista está vazia!\n");
        return;
    }
    Efila *novo = (Efila*) malloc(sizeof(Efila));

    char cpf[12];
    printf("Digite o CPF do paciente que deseja enfileirar: ");
    scanf(" %[^\n]", cpf);

    int achou = 0;
    Elista *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados.cpf, cpf) == 0) {
            printf("\nPaciente encontrado:\n");
            printf("Nome: %s\n", atual->dados.nome);
            printf("Idade: %d\n", atual->dados.idade);
            printf("CPF: %s\n", atual->dados.cpf);
            printf("Entrada: %d/%d/%d", atual->dados.entrada.dia,
                                            atual->dados.entrada.mes,
                                            atual->dados.entrada.ano);
            strcpy(novo->dados.nome, atual->dados.nome);
            novo->dados.idade = atual->dados.idade;
            strcpy(novo->dados.cpf, atual->dados.cpf);
            novo->dados.entrada = atual->dados.entrada;
            achou = 1;
        }
        atual = atual->proximo;
    }
    if (achou == 1) {
        if (fila->qtde == 0) {
            fila->head = novo;
        } else {
            fila->tail->proximo = novo;
            novo->anterior = fila->tail;
        }
        fila->tail = novo;
        fila->qtde++;
        return;
    }
    printf("Paciente nao cadastrado!\n");
}

void mostrar_fila(Fila *fila) {
    Efila *atual = fila->head;
    printf("fila:\n");
    while (atual != NULL) {
        printf("Nome: %s, Idade: %d, CPF: %s, ", atual->dados.nome, atual->dados.idade, atual->dados.cpf);
        printf("Entrada: %d/%d/%d\n", atual->dados.entrada.dia,
                                            atual->dados.entrada.mes,
                                            atual->dados.entrada.ano);
        atual = atual->proximo;
    }
    printf("\n");
}
