#include <stdio.h>
#include <stdlib.h>
#include "motorista.h"
#include "despesa.h"

void menuMotoristas(Motorista **motoristas, int *tamMotoristas);
void menuDespesas(Despesa **despesas, int *tamDespesas);

void menuPrincipal(Motorista **motoristas, int *tamMotoristas, Despesa **despesas, int *tamDespesas) {
    int opcao;

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Gerenciar Motoristas\n");
        printf("2. Gerenciar Despesas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuMotoristas(motoristas, tamMotoristas);
                break;

            case 2:
                menuDespesas(despesas, tamDespesas);
                break;

            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuMotoristas(Motorista **motoristas, int *tamMotoristas) {
    int opcao;

    do {
        printf("\n--- Menu de Motoristas ---\n");
        printf("1. Cadastrar Motorista\n");
        printf("2. Exibir Motoristas\n");
        printf("3. Atualizar Motorista\n");
        printf("4. Deletar Motorista\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarMotorista(motoristas, tamMotoristas);
                break;

            case 2:
                exibirMotoristas(*motoristas, *tamMotoristas);
                break;

            case 3:
                atualizarMotorista(*motoristas, *tamMotoristas);
                break;

            case 4:
                deletarMotorista(motoristas, tamMotoristas);
                break;

            case 0:
                printf("Voltando ao Menu Principal...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

void menuDespesas(Despesa **despesas, int *tamDespesas) {
    int opcao;

    do {
        printf("\n--- Menu de Despesas ---\n");
        printf("1. Cadastrar Despesa\n");
        printf("2. Exibir Despesas\n");
        printf("3. Atualizar Despesa\n");
        printf("4. Deletar Despesa\n");
        printf("0. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarDespesa(despesas, tamDespesas);
                break;

            case 2:
                exibirDespesas(*despesas, *tamDespesas);
                break;

            case 3:
                atualizarDespesa(*despesas, *tamDespesas);
                break;

            case 4:
                deletarDespesa(despesas, tamDespesas);
                break;

            case 0:
                printf("Voltando ao Menu Principal...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

int main() {
    Motorista *motoristas;
    int tamMotoristas;

    Despesa *despesas;
    int tamDespesas;

    inicializarMotoristas(&motoristas, &tamMotoristas);
    inicializarDespesas(&despesas, &tamDespesas);

    menuPrincipal(&motoristas, &tamMotoristas, &despesas, &tamDespesas);

    free(motoristas);
    free(despesas);

    return 0;
}
