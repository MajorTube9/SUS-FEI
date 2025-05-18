#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "atendPrior.h"
#include "atendimento.h"

int filho_esq(int pai) {
    return 2 * pai + 1;
}

int filho_dir(int pai) {
    return 2 * pai + 2;
}

int pai(int filho) {
    return (filho - 1) / 2;
}

int ultimo_pai(Heap *h) {
    return (h->qtde / 2) - 1;
}

void peneirar(Heap *h, int pai) {
    int maior = pai;
    int esq = filho_esq(pai);
    int dir = filho_dir(pai);

    if (esq < h->qtde && h->dados[esq].idade > h->dados[maior].idade) {
        maior = esq;
    }
    if (dir < h->qtde && h->dados[dir].idade > h->dados[maior].idade) {
        maior = dir;
    }

    if (maior != pai) {
        Registro temp = h->dados[pai];
        h->dados[pai] = h->dados[maior];
        h->dados[maior] = temp;
        peneirar(h, maior);
    }
}

void construir(Heap *h) {
    for (int i = ultimo_pai(h); i >= 0; i--) {
        peneirar(h, i);
    }
}

void inserir(Heap *h, Registro reg) {
    h->dados[h->qtde] = reg;
    h->qtde++;

    int i = h->qtde - 1;
    while (i != 0 && h->dados[pai(i)].idade < h->dados[i].idade) {
        Registro temp = h->dados[pai(i)];
        h->dados[pai(i)] = h->dados[i];
        h->dados[i] = temp;
        i = pai(i);
    }
}

void remover(Heap *h) {
    h->dados[0] = h->dados[h->qtde - 1];
    h->qtde--;

    peneirar(h, 0);
}

void enfileirar_prior(Fila *fila, Lista *lista, Heap *heap) {
    if (lista->inicio == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    char cpf[12];
    printf("Digite o CPF do paciente que deseja enfileirar: ");
    scanf(" %[^\n]", cpf);

    Elista *atual_lista = lista->inicio;
    while (atual_lista != NULL) {
        if (strcmp(atual_lista->dados.cpf, cpf) == 0) {
            printf("\nPaciente encontrado:\n");
            printf("Nome: %s\n", atual_lista->dados.nome);
            printf("Idade: %d\n", atual_lista->dados.idade);
            printf("CPF: %s\n", atual_lista->dados.cpf);
            printf("Entrada: %d/%d/%d\n", atual_lista->dados.entrada.dia,
                                         atual_lista->dados.entrada.mes,
                                         atual_lista->dados.entrada.ano);

            // Limpa a heap atual
            heap->qtde = 0;

            // Insere todos os pacientes da fila na heap
            Efila *atual_fila = fila->head;
            while (atual_fila != NULL) {
                inserir(heap, atual_fila->dados);  // Adiciona à heap
                atual_fila = atual_fila->proximo;
            }

            // Insere o novo paciente na heap
            inserir(heap, atual_lista->dados);

            // Limpa a fila atual
            while (fila->head != NULL) {
                Efila *temp = fila->head;
                fila->head = fila->head->proximo;
                free(temp);
            }
            fila->qtde = 0;
            fila->tail = NULL;

            // Reconstrói a fila a partir da heap
            while (heap->qtde > 0) {
                Efila *novo = (Efila*) malloc(sizeof(Efila));
                novo->dados = heap->dados[0];  // Pega o de maior prioridade (idade)
                novo->proximo = NULL;
                novo->anterior = fila->tail;

                if (fila->qtde == 0) {
                    fila->head = novo;
                } else {
                    fila->tail->proximo = novo;
                }
                fila->tail = novo;
                fila->qtde++;

                // Remove o elemento da heap após inserir na fila
                remover(heap);
            }

            printf("Paciente enfileirado com sucesso!\n");
            return;
        }
        atual_lista = atual_lista->proximo;
    }

    printf("Paciente não cadastrado!\n");
}

// Desenfileirar o primeiro da fila
void desenfileirar_prior(Fila *fila) {
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
    printf("Paciente %s desenfileirado!\n", liberar->dados.nome);
    free(liberar);
}
