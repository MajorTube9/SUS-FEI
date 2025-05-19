#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pesquisa.h"
#include "cadastrar.h"

ABB *cria_arvore() {
    ABB *arvore = malloc(sizeof(ABB));
    arvore->raiz = NULL;
    arvore->qtde = 0;

    return arvore;
}

EABB *cria_vertice(Registro reg) {
    EABB *novo = malloc(sizeof(EABB));
    novo->filhoDir = NULL;
    novo->filhoEsq = NULL;
    novo->pai = NULL;
    novo->dados = reg;

    return novo;
}

// operacao: 1 = ordem por ano, 2 = ordem por mes, 3 = ordem por dia, 4 = ordem por idade
void inserir_vertice(ABB *arvore, Registro reg, int operacao) {
    EABB *novo = cria_vertice(reg);

    EABB *anterior = NULL;
    EABB *atual = arvore->raiz;

    if (operacao == 1) {
        while (atual != NULL) {
            anterior = atual;
            if (reg.entrada.ano <= anterior->dados.entrada.ano) {
                atual = atual->filhoEsq;
            } else {
                atual = atual->filhoDir;
            }
        }
        novo->pai = anterior;
        if (anterior != NULL) {
            if (reg.entrada.ano <= anterior->dados.entrada.ano) {
                anterior->filhoEsq = novo;
            } else {
                anterior->filhoDir = novo;
            }
        } else {
            arvore->raiz = novo;
        }
    } else if (operacao == 2) {
        while (atual != NULL) {
            anterior = atual;
            if (reg.entrada.mes <= anterior->dados.entrada.mes) {
                atual = atual->filhoEsq;
            } else {
                atual = atual->filhoDir;
            }
        }
        novo->pai = anterior;
        if (anterior != NULL) {
            if (reg.entrada.mes <= anterior->dados.entrada.mes) {
                anterior->filhoEsq = novo;
            } else {
                anterior->filhoDir = novo;
            }
        } else {
            arvore->raiz = novo;
        }
    } else if (operacao == 3) {
        while (atual != NULL) {
            anterior = atual;
            if (reg.entrada.dia <= anterior->dados.entrada.dia) {
                atual = atual->filhoEsq;
            } else {
                atual = atual->filhoDir;
            }
        }
        novo->pai = anterior;
        if (anterior != NULL) {
            if (reg.entrada.dia <= anterior->dados.entrada.dia) {
                anterior->filhoEsq = novo;
            } else {
                anterior->filhoDir = novo;
            }
        } else {
            arvore->raiz = novo;
        }
    } else {
        while (atual != NULL) {
            anterior = atual;
            if (reg.idade <= anterior->dados.idade) {
                atual = atual->filhoEsq;
            } else {
                atual = atual->filhoDir;
            }
        }
        novo->pai = anterior;
        if (anterior != NULL) {
            if (reg.idade <= anterior->dados.idade) {
                anterior->filhoEsq = novo;
            } else {
                anterior->filhoDir = novo;
            }
        } else {
            arvore->raiz = novo;
        }
    }

    arvore->qtde++;
}

void mostrar(EABB *raiz) {
    if (raiz != NULL) {
        mostrar(raiz->filhoEsq);
        printf("Nome: %s, Idade: %d, CPF: %s, ", raiz->dados.nome, raiz->dados.idade, raiz->dados.cpf);
        printf("Entrada: %d/%d/%d\n", raiz->dados.entrada.dia,
                                            raiz->dados.entrada.mes,
                                            raiz->dados.entrada.ano);
        mostrar(raiz->filhoDir);
    }
}

void libera_arvore(EABB *raiz) {
    if (raiz != NULL) {
        libera_arvore(raiz->filhoEsq);
        libera_arvore(raiz->filhoDir);
        free(raiz);
    }
}

void atualizar_arvores(ABB *arvAno, ABB *arvMes, ABB *arvDia, ABB *arvIdade, Lista *lista) {
    // Limpar as árvores existentes
    libera_arvore(arvAno->raiz);
    libera_arvore(arvMes->raiz);
    libera_arvore(arvDia->raiz);
    libera_arvore(arvIdade->raiz);

    // Criar novas árvores vazias
    arvAno->raiz = NULL;
    arvMes->raiz = NULL;
    arvDia->raiz = NULL;
    arvIdade->raiz = NULL;

    // Reconstruir as árvores com os dados atuais
    Elista *atual = lista->inicio;
    while (atual != NULL) {
        inserir_vertice(arvAno, atual->dados, 1);
        inserir_vertice(arvMes, atual->dados, 2);
        inserir_vertice(arvDia, atual->dados, 3);
        inserir_vertice(arvIdade, atual->dados, 4);

        atual = atual->proximo;
    }
}
