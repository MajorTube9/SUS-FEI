#include "cadastrar.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicializa a lista dinâmica
void inicializar_lista(Lista *lista) {
    lista->inicio = NULL;
    lista->qtde = 0;
}

// Função para cadastrar um novo paciente no início da lista
void cadastrar_paciente(Lista *lista) {
    Elista *novo = (Elista *)malloc(sizeof(Elista));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    // Entrada dos dados do paciente
    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", novo->dados.nome);
    printf("Digite a idade do paciente: ");
    scanf("%d", &novo->dados.idade);
    printf("Digite o CPF do paciente: ");
    scanf(" %[^\n]", novo->dados.cpf);
    printf("Digite o dia da entrada: ");
    scanf(" %d", &novo->dados.entrada.dia);
    printf("Digite o mes da entrada: ");
    scanf(" %d", &novo->dados.entrada.mes);
    printf("Digite o ano da entrada: ");
    scanf(" %d", &novo->dados.entrada.ano);

    // Inserção no início da lista
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->qtde++;

    printf("Paciente cadastrado com sucesso!\n");
}

// Função para consultar paciente pelo CPF
void consultar_paciente(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    char cpf[12];
    printf("Digite o CPF do paciente: ");
    scanf(" %[^\n]", cpf);

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
            return;
        }
        atual = atual->proximo;
    }

    printf("Paciente não encontrado!\n");
}

// Função para listar todos os pacientes
void listar_pacientes(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    printf("\nLista de pacientes cadastrados:\n");
    Elista *atual = lista->inicio;
    while (atual != NULL) {
        printf("Nome: %s, Idade: %d, CPF: %s, ", atual->dados.nome, atual->dados.idade, atual->dados.cpf);
        printf("Entrada: %d/%d/%d\n", atual->dados.entrada.dia,
                                            atual->dados.entrada.mes,
                                            atual->dados.entrada.ano);
        atual = atual->proximo;
    }
}

// Função para atualizar os dados de um paciente
void atualizar_paciente(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("A lista está vazia!\n");
        return;
    }

    char cpf[12];
    printf("Digite o CPF do paciente que deseja atualizar: ");
    scanf(" %[^\n]", cpf);

    Elista *atual = lista->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dados.cpf, cpf) == 0) {
            printf("\nPaciente encontrado. Atualize os dados:\n");
            printf("Digite o novo nome: ");
            scanf(" %[^\n]", atual->dados.nome);
            printf("Digite a nova idade: ");
            scanf("%d", &atual->dados.idade);
            printf("Digite o novo CPF: ");
            scanf(" %[^\n]", atual->dados.cpf);
            printf("Digite o novo dia da entrada: ");
            scanf(" %d", &atual->dados.entrada.dia);
            printf("Digite o novo mes da entrada: ");
            scanf(" %d", &atual->dados.entrada.mes);
            printf("Digite o novo ano da entrada: ");
            scanf(" %d", &atual->dados.entrada.ano);

            printf("Dados do paciente atualizados com sucesso!\n");
            return;
        }
        atual = atual->proximo;
    }

    printf("Paciente nao encontrado!\n");
}

// Função para remover um paciente
void remover_paciente(Lista *lista) {
    if (lista->inicio == NULL) {
        printf("A lista esta vazia!\n");
        return;
    }

    char cpf[12];
    printf("Digite o CPF do paciente que deseja remover: ");
    scanf(" %[^\n]", cpf);

    Elista *atual = lista->inicio;
    Elista *anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->dados.cpf, cpf) == 0) {
            if (anterior == NULL) { // Remoção do primeiro elemento
                lista->inicio = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            lista->qtde--;
            printf("Paciente removido com sucesso!\n");
            return;
        }

        anterior = atual;
        atual = atual->proximo;
    }

    printf("Paciente nao encontrado!\n");
}
