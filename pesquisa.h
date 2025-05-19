#ifndef PESQUISA_H
#define PESQUISA_H

#include "structs.h"
#include "cadastrar.h"

typedef struct EABB {
    Registro dados;
    struct EABB *filhoEsq;
    struct EABB *filhoDir;
    struct EABB *pai;
} EABB;

typedef struct {
    EABB *raiz;
    int qtde;
} ABB;

ABB *cria_arvore();
EABB *cria_vertice(Registro reg);
void inserir_vertice(ABB *arvore, Registro reg, int operacao);
void mostrar(EABB *raiz);
void liberaNos(EABB *raiz);
void limpaABB(ABB *arvore);
void atualizar_arvores(ABB *arvAno, ABB *arvMes, ABB *arvDia, ABB *arvIdade, Lista *lista);

#endif
