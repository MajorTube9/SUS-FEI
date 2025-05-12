#include <stdio.h>
#include "biblioteca.h" // Incluindo o header com as funções auxiliares

int main() {
    int opcao;

    do {
        // Menu Principal
        printf("\nMenu:\n");
        printf("1. Cadastrar\n");
        printf("2. Atendimento Prioritario\n");
        printf("3. Pesquisa\n");
        printf("4. Desfazer\n");
        printf("5. Carregar/Salvar\n");
        printf("6. Sobre\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {  // Validação da entrada
            printf("Entrada invalida! Por favor, digite um número.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch(opcao) {
            case 1: { // Menu Cadastro
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
                        while (getchar() != '\n'); // Limpa o buffer
                        continue;
                    }

                    switch (cadastro) {
                        case 1:
                            cadastrar_paciente();
                            break;
                        case 2:
                            consultar_paciente();
                            break;
                        case 3:
                            listar_pacientes();
                            break;
                        case 4:
                            atualizar_paciente();
                            break;
                        case 5:
                            remover_paciente();
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
            case 2:
                printf("Funcao Atendimento Prioritario ainda nao implementada.\n");
                break;
            case 3:
                printf("Funcao Pesquisa ainda nao implementada.\n");
                break;
            case 4:
                printf("Funcao Desfazer ainda nao implementada.\n");
                break;
            case 5:
                printf("Funcao Carregar/Salvar ainda nao implementada.\n");
                break;
            case 6:
                // Exibe informações sobre os desenvolvedores
                printf("Gabriel Machado Da Silva & Sergio de Siqueira Santos\n");
                printf("RA: 22.123.005-5 / 22.124.082-3\n");
                printf("Ciência da Computação\n");
                printf("Estrutura de Dados\n");
                printf("Feito em algum dia de maio\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}
