#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "atendimento.h"
#include "desfazer.h"
#include "structs.h"

// Inicializa a fila dinâmica
void inicializar_fila(Fila *fila) {
    fila->head = NULL;
    fila->tail = NULL;
    fila->qtde = 0;
}

// Enfileirar um paciente na fila
void enfileirar(Fila *fila, Lista *lista, Pilha *pilha) {
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
            printf("Entrada: %d/%d/%d\n", atual->dados.entrada.dia,
                                            atual->dados.entrada.mes,
                                            atual->dados.entrada.ano);
            novo->dados = atual->dados;
            achou = 1;
        }
        atual = atual->proximo;
    }
    if (achou == 1) { // Se achou
        if (fila->qtde == 0) {
            fila->head = novo;
        } else {
            fila->tail->proximo = novo;
            novo->anterior = fila->tail;
        }
        fila->tail = novo;
        fila->qtde++;

        push(pilha, novo->dados, 1);

        return;
    }
    printf("Paciente nao cadastrado!\n"); // Senao sai
}

// Desenfileirar o primeiro da fila
void desenfileirar(Fila *fila, Pilha *pilha) {
    if (fila->qtde == 0) {
        printf("Fila vazia!\n");
        return;
    }

    Efila *liberar = fila->head;
    if (fila->qtde == 1) {
        fila->head = NULL;
        fila->tail = NULL;
    } else {
        fila->head->proximo->anterior = NULL;
        fila->head = fila->head->proximo;
    }
    fila->qtde--;
    push(pilha, liberar->dados, 2);
    printf("Paciente %s desenfileirado!\n", liberar->dados.nome);
    free(liberar);
}

// Mostra a fila atual
void mostrar_fila(Fila *fila) {
    Efila *atual = fila->head;
    printf("Fila atual:\n");
    printf("Primeiro da fila:\n");
    while (atual != NULL) {
        printf("Nome: %s, Idade: %d, CPF: %s, ", atual->dados.nome, atual->dados.idade, atual->dados.cpf);
        printf("Entrada: %d/%d/%d\n", atual->dados.entrada.dia,
                                            atual->dados.entrada.mes,
                                            atual->dados.entrada.ano);
        atual = atual->proximo;
    }
    printf("Ultimo da fila\n");
}
