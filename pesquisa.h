#ifndef PESQUISA_H
#define PESQUISA_H

#include "structs.h"

ABB *cria_arvore();
EABB *cria_vertice(Registro reg);
void inserir_vertice(ABB *arvore, Registro reg, int operacao);
void mostrar(EABB *raiz);
void liberaNos(EABB *raiz);
void limpaABB(ABB *arvore);
void atualizar_arvores(ABB *arvAno, ABB *arvMes, ABB *arvDia, ABB *arvIdade, Lista *lista);

#endif //PESQUISA_H
