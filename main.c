#include <stdio.h>
#include "cadastrar.h"

int main() {
    Lista lista;

    int opcao;

    do {
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
                inicializar_lista(&lista);
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
