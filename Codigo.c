#include <stdio.h>

int main() {
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1.Cadastrar\n");
        printf("2.Atendimento Prioritario\n");
        printf("3.Pesquisa\n");
        printf("4.Desfazer\n");
        printf("5.Carregar/Salvar\n");
        printf("6.Sobre\n");
        printf("0.Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
    
        switch(opcao) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Gabriel Machado Da Silva & Sergio de Siqueira Santos\n");
                printf("RA:22.123.005-5 / 22.124.082-3\n");
                printf("Ciência da Computação\n");
                printf("Estrutura de Dados\n");
                printf("feito em algum dia de maio\n");
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(opcao != 0);
    
    return 0;
}
