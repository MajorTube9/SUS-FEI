#ifndef STRUCTS_H
#define STRUCTS_H

// Header que armazena as structs universais
// (As que todos os outros arquivos usam)
// Melhor assim do que importar uma biblioteca inteira
// so pra usar as structs

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
    int idade;
    char cpf[12];
    Data entrada;
} Registro;

// Structs de pilha
typedef struct EPilha {
    struct Epilha *anterior;
    struct Epilha *proximo;
    Registro dados;
    int operacao;
} EPilha;

typedef struct {
    EPilha *topo;
    int qtde;
} Pilha;

// Structs de fila
typedef struct Efila{
    Registro dados;
    struct Efila *proximo;
    struct Efila *anterior;
} Efila;

typedef struct {
    Efila *head;
    Efila *tail;
    int qtde;
} Fila;

// Struct de heap
typedef struct {
    Registro dados[20];
    int qtde;
} Heap;

// Structs de fila dinamica
typedef struct Elista {
    Registro dados;
    struct Elista *proximo;
} Elista;

typedef struct {
    Elista *inicio;
    int qtde;
} Lista;

// Structs de arvore binaria de busca
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

#endif
