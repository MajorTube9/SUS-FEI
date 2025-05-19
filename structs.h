#ifndef STRUCTS_H
#define STRUCTS_H

// Header que armazena as structs universais
// (As que todos os outros arquivos usam)

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

#endif
