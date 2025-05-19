#include <stdio.h>
#include <stdlib.h>

#include "cadastrar.h"
#include "atendimento.h"
#include "atendPrior.h"
#include "pesquisa.h"

// TODO Arrumar o sistema de datas (deixar mais bonito e limitar a 31 dias e 12 meses)
// TODO Deixar a apresentação mais bonita
// TODO Transferir TODAS (talvez) as structs para o structs.h
// TODO Resolver o sistema de salvar (salvar também as filas)
// TODO Comentar o código

int main() {
    Lista lista;
    Fila fila;
    inicializar_fila(&fila);
    Fila filaPrior;
    inicializar_fila(&filaPrior);
    inicializar_lista(&lista);
    Heap *heap = malloc (sizeof(Heap));
    heap->qtde = 0;
    ABB *arvAno = cria_arvore();
    ABB *arvMes = cria_arvore();
    ABB *arvDia = cria_arvore();
    ABB *arvIdade = cria_arvore();
    Elista *atual = lista.inicio;

    int opcao;

    do {
        atualizar_arvores(arvAno, arvMes, arvDia, arvIdade, &lista);
        printf("\nMenu:\n");
        printf("1. Cadastrar\n");
        printf("2. Atendimento\n");
        printf("3. Atendimento prioritario\n");
        printf("4. Pesquisa\n");
        printf("5. Desfazer\n");
        printf("6. Sobre\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Por favor, digite um número.\n");
            while (getchar() != '\n');
            continue;
        }

        switch(opcao) {
            case 1: {
                int cadastro;
                do {
                    printf("\nMenu Cadastro:\n");
                    printf("1. Cadastrar novo paciente\n");
                    printf("2. Consultar paciente cadastrado\n");
                    printf("3. Mostrar lista completa\n");
                    printf("4. Atualizar dados de paciente\n");
                    printf("5. Remover paciente\n");
                    printf("6. Voltar\n");
                    printf("Escolha uma opcao: ");

                    if (scanf("%d", &cadastro) != 1) {
                        printf("Entrada invalida! Por favor, digite um número.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    switch (cadastro) {
                        case 1:
                            cadastrar_paciente(&lista);
                            break;
                        case 2:
                            consultar_paciente(&lista);
                            break;
                        case 3:
                            listar_pacientes(&lista);
                            break;
                        case 4:
                            atualizar_paciente(&lista);
                            break;
                        case 5:
                            remover_paciente(&lista);
                            break;
                        case 6:
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");
                    }
                } while (cadastro != 6);
                break;
            }
            case 2: {
                int atendimento;
                do {
                    printf("\nMenu Atendimento:\n");
                    printf("1. Enfileirar Paciente\n");
                    printf("2. Desenfileirar Paciente\n");
                    printf("3. Mostrar fila completa\n");
                    printf("4. Voltar\n");

                    printf("Escolha uma opcao: ");

                    if (scanf("%d", &atendimento) != 1) {
                        printf("Entrada invalida! Por favor, digite um número.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    switch (atendimento) {
                        case 1:
                            enfileirar(&fila, &lista);
                            break;
                        case 2:
                            desenfileirar(&fila);
                            break;
                        case 3:
                            mostrar_fila(&fila);
                            break;
                        case 4:
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");
                    }
                } while (atendimento != 4);
                break;
            }
            case 3: {
                int atendPrior;
                do {
                    printf("\nMenu Atendimento Prioritario:\n");
                    printf("1. Enfileirar Paciente\n");
                    printf("2. Desenfileirar Paciente\n");
                    printf("3. Mostrar fila prioritaria completa\n");
                    printf("4. Voltar\n");

                    printf("Escolha uma opcao: ");

                    if (scanf("%d", &atendPrior) != 1) {
                        printf("Entrada invalida! Por favor, digite um número.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    switch (atendPrior) {
                        case 1:
                            enfileirar_prior(&filaPrior, &lista, heap);
                            break;
                        case 2:
                            desenfileirar(&filaPrior);
                            break;
                        case 3:
                            mostrar_fila(&filaPrior);
                            break;
                        case 4:
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");
                    }
                } while (atendPrior != 4);
                break;
            }
            case 4: {
                int pesquisa;
                do {
                    printf("\nMenu Pesquisa:\n");
                    printf("1. Mostrar Registros ordenados por Ano de Registro\n");
                    printf("2. Mostrar Registros ordenados por Mes de Registro\n");
                    printf("3. Mostrar Registros ordenados por Dia de Registro\n");
                    printf("4. Mostrar Registros ordenados por Idade de Registro\n");
                    printf("5. Voltar\n");
                    printf("Escolha uma opcao: ");

                    if (scanf("%d", &pesquisa) != 1) {
                        printf("Entrada invalida! Por favor, digite um número.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    switch (pesquisa) {
                        case 1:
                            mostrar(arvAno->raiz);
                            break;
                        case 2:
                            mostrar(arvMes->raiz);
                            break;
                        case 3:
                            mostrar(arvDia->raiz);
                            break;
                        case 4:
                            mostrar(arvIdade->raiz);
                            break;

                        case 5:
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");
                    }
                } while (pesquisa != 5);
                break;
            }
            case 6:
                printf("Gabriel Machado Da Silva & Sergio de Siqueira Santos\n");
                printf("RA: 22.123.005-5 / 22.124.082-3\n");
                printf("Ciencia da Computacao\n");
                printf("Estrutura de Dados\n");
                printf("Feito em no mes de maio\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
