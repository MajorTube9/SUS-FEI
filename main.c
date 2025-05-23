#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "cadastrar.h"
#include "atendimento.h"
#include "atendPrior.h"
#include "pesquisa.h"
#include "desfazer.h"
#include "structs.h"

int main() {
    // Iniciaçizando as variáveis, estruturas etc
    Lista lista;
    inicializar_lista(&lista);

    Fila fila;
    inicializar_fila(&fila);

    Fila filaPrior;
    inicializar_fila(&filaPrior);

    Heap *heap = malloc (sizeof(Heap));
    heap->qtde = 0;

    ABB *arvAno = cria_arvore();
    ABB *arvMes = cria_arvore();
    ABB *arvDia = cria_arvore();
    ABB *arvIdade = cria_arvore();

    Pilha *pilha = inicializar_pilha();

    int opcao;

    // MENU PRINCIPAL
    do {
        atualizar_arvores(arvAno, arvMes, arvDia, arvIdade, &lista);
        printf("----------------------------------------------------");
        printf("\nMenu Principal:\n");
        printf("1. Cadastrar\n");
        printf("2. Atendimento\n");
        printf("3. Atendimento prioritario\n");
        printf("4. Pesquisa\n");
        printf("5. Desfazer\n");
        printf("6. Sobre\n");
        printf("0. Sair\n");
        printf("----------------------------------------------------\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Por favor, digite um numero.\n");
            while (getchar() != '\n');
            continue;
        }

        switch(opcao) {
                // MENU CADASTRO
            case 1: {
                int cadastro;
                do {

                    printf("----------------------------------------------------");
                    printf("\nMenu Cadastro:\n");
                    printf("1. Cadastrar novo paciente\n");
                    printf("2. Consultar paciente cadastrado\n");
                    printf("3. Mostrar lista completa\n");
                    printf("4. Atualizar dados de paciente\n");
                    printf("5. Remover paciente\n");
                    printf("6. Voltar\n");
                    printf("----------------------------------------------------\n");
                    printf("Escolha uma opcao: ");

                    if (scanf("%d", &cadastro) != 1) {
                        printf("Entrada invalida! Por favor, digite um numero.\n");
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
                // MENU ATENDIMENTO
            case 2: {
                int atendimento;
                do {
                    printf("----------------------------------------------------");
                    printf("\nMenu Atendimento:\n");
                    printf("1. Enfileirar Paciente\n");
                    printf("2. Desenfileirar Paciente\n");
                    printf("3. Mostrar fila completa\n");
                    printf("4. Voltar\n");
                    printf("----------------------------------------------------\n");

                    printf("Escolha uma opcao: ");

                    if (scanf("%d", &atendimento) != 1) {
                        printf("Entrada invalida! Por favor, digite um número.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    switch (atendimento) {
                        case 1:
                            enfileirar(&fila, &lista, pilha);

                            break;
                        case 2:
                            desenfileirar(&fila, pilha);
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
                // MENU ATENDIMENTO PRIORITÁRIO
            case 3: {
                int atendPrior;
                do {
                    printf("----------------------------------------------------");
                    printf("\nMenu Atendimento Prioritario:\n");
                    printf("1. Enfileirar Paciente\n");
                    printf("2. Desenfileirar Paciente\n");
                    printf("3. Mostrar fila prioritaria completa\n");
                    printf("4. Voltar\n");
                    printf("----------------------------------------------------\n");

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
                            desenfileirar_prior(&filaPrior);
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
                // MENU PESQUISA
            case 4: {
                int pesquisa;
                do {
                    printf("----------------------------------------------------");
                    printf("\nMenu Pesquisa:\n");
                    printf("1. Mostrar Registros ordenados por Ano de Registro\n");
                    printf("2. Mostrar Registros ordenados por Mes de Registro\n");
                    printf("3. Mostrar Registros ordenados por Dia de Registro\n");
                    printf("4. Mostrar Registros ordenados por Idade de Registro\n");
                    printf("5. Voltar\n");
                    printf("----------------------------------------------------\n");
                    printf("Escolha uma opcao: ");

                    if (scanf("%d", &pesquisa) != 1) {
                        printf("Entrada invalida! Por favor, digite um número.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    switch (pesquisa) {
                        case 1:
                            printf("Menor\n");
                            mostrar(arvAno->raiz);
                            printf("Maior\n");
                            break;
                        case 2:
                            printf("Menor\n");
                            mostrar(arvMes->raiz);
                            printf("Maior\n");
                            break;
                        case 3:
                            printf("Menor\n");
                            mostrar(arvDia->raiz);
                            printf("Maior\n");
                            break;
                        case 4:
                            printf("Menor\n");
                            mostrar(arvIdade->raiz);
                            printf("Maior\n");
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
                // MENU DESFAZER
            case 5: {
                int desfazer;
                do {
                    printf("----------------------------------------------------");
                    printf("\nMenu Desfazer:\n");
                    printf("1. Mostrar Operacoes da Fila de Atendimento\n");
                    printf("2. Desfazer Ultima Operacao da Fila de Atendimento\n");
                    printf("3. Voltar\n");
                    printf("----------------------------------------------------\n");
                    printf("Escolha uma opcao: ");

                    if (scanf("%d", &desfazer) != 1) {
                        printf("Entrada invalida! Por favor, digite um número.\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    switch (desfazer) {
                        case 1:
                            mostrar_pilha(pilha);
                            break;
                        case 2:
                            desfazerr(pilha, &fila);
                            break;
                        case 3:
                            printf("Voltando ao menu principal...\n");
                            break;
                        default:
                            printf("Opcao invalida! Tente novamente.\n");
                    }
                } while (desfazer != 3);
                break;
            }
                // SOBRE
            case 6:
                printf("----------------------------------------------------\n");
                printf("Gabriel Machado Da Silva & Sergio de Siqueira Santos\n");
                printf("RA: 22.123.005-5 / 22.124.082-3\n");
                printf("Ciencia da Computacao da FEI\n");
                printf("Estrutura de Dados, Professor Luciano Rossi\n");
                printf("Feito em maio de 2025\n");
                printf("----------------------------------------------------\n");
                break;
            case 0:
                // SAIR
                printf("Saindo...\n");
                sleep(3);
                exit(0);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
