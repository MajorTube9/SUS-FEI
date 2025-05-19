#include <stdio.h>
#include <stdlib.h>

#include "desfazer.h"
#include "structs.h"

// Inicializa o elemento da pilha
EPilha *inicializar_epilha(Registro reg, int operacao) {
    EPilha *novo = malloc(sizeof(EPilha));
    novo->anterior = NULL;
    novo->proximo = NULL;
    novo->dados = reg;
    novo->operacao = operacao;
    return novo;
}

Pilha *inicializar_pilha() {
    Pilha *pilha = malloc(sizeof(Pilha));
    pilha->qtde = 0;
    pilha->topo = NULL;
    return pilha;
}

// Coloca o registro na pilha
// operacao: 1 = enfileirou, 2 = desenfileirou
void push(Pilha *pilha, Registro reg, int operacao) {
    EPilha *novo = inicializar_epilha(reg, operacao);
    if (pilha->qtde != 0) {
        novo->proximo = pilha->topo;
        pilha->topo->anterior = novo;
    }
    pilha->topo = novo;
    pilha->qtde++;
}

// Desfaz o enfileiramento ou o desenfileiramento
// retorna 0 se foi e 1 se nao
int desfazerr(Pilha *pilha, Fila *fila) {
    int escolha;
    printf("Acao mais recente: ");
    if (pilha->topo->operacao == 1) {
        printf("Enfileirou paciente %s, CPF: %s\n", pilha->topo->dados.nome, pilha->topo->dados.cpf);
    } else {
        printf("Desenfileirou paciente %s, CPF: %s\n", pilha->topo->dados.nome, pilha->topo->dados.cpf);
    }
    do {
        printf("Tem certeza de que deseja desfazer a ultima acao? 1 = Sim, 0 = Nao\n");
        if (scanf("%d", &escolha) != 1) {
            printf("Entrada invalida! Por favor, digite um numero.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        if (escolha == 0) {
            return 1;
        } else if (escolha == 1) {
            break;
        } else {
            printf("Opcao invalida!\n");
        }
    } while (1);
    if (pilha->qtde > 0) {
        EPilha *topo = pilha->topo;
        if (topo->operacao == 1) { // Se enfileirou, desfaz
            Efila *liberar = fila->tail;
            if (fila->qtde == 1) {
                fila->head = NULL;
                fila->tail = NULL;
            } else {
                fila->tail->anterior->proximo = NULL;
                fila->tail = fila->tail->anterior;
            }
            fila->qtde--;
            printf("Paciente %s desenfileirado!\n", liberar->dados.nome);
            free(liberar);
        } else { // Se desenfileirou, desfaz
            Efila *novo = (Efila*) malloc(sizeof(Efila));
            novo->dados = topo->dados;
            novo->anterior = NULL;
            novo->proximo = NULL;
            if (fila->qtde == 0) {
                fila->tail = novo;
            } else {
                fila->head->anterior = novo;
                novo->proximo = fila->head;
            }
            fila->head = novo;
            fila->qtde++;
            printf("Paciente %s enfileirado!\n", topo->dados.nome);
        }
        pilha->topo = pilha->topo->proximo;
        if (pilha->topo != NULL) {
            pilha->topo->anterior = NULL;
        }
        pilha->qtde--;
        free(topo);
        return 0;
    } else {
        return 1;
    }
}

// Mostra o log atual
void mostrar_pilha(Pilha *pilha) {
    EPilha *atual = pilha->topo;
    printf("Acao mais antiga:\n");
    while (atual != NULL) {
        if (atual->operacao == 1) {
            printf("Enfileirou paciente %s, CPF: %s\n", atual->dados.nome, atual->dados.cpf);
        } else {
            printf("Desenfileirou paciente %s, CPF: %s\n", atual->dados.nome, atual->dados.cpf);
        }
        atual = atual->proximo;
    }
    printf("Acao mais recente:\n");
}
