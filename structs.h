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

#endif
