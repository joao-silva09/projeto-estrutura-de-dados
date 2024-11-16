#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "despesa.h"

void inicializarDespesas(Despesa **despesas, int *tamanho) {
    *despesas = NULL;
    *tamanho = 0;
}

void criarDespesa(Despesa **despesas, int *tamanho) {
    *despesas = realloc(*despesas, (*tamanho + 1) * sizeof(Despesa));
    if (*despesas == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    Despesa *d = &(*despesas)[*tamanho];
    d->id = *tamanho + 1;

    printf("Descrição da despesa: ");
    scanf(" %[^\n]s", d->descricao);

    printf("Valor: ");
    scanf("%f", &d->valor);

    printf("Data (dd/mm/yyyy): ");
    scanf(" %[^\n]s", d->data);

    (*tamanho)++;
    printf("Despesa cadastrada com sucesso!\n");
}

void exibirDespesas(Despesa *despesas, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhuma despesa cadastrada.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("ID: %d\n", despesas[i].id);
        printf("Descrição: %s\n", despesas[i].descricao);
        printf("Valor: %.2f\n", despesas[i].valor);
        printf("Data: %s\n", despesas[i].data);
        printf("---------------------------\n");
    }
}

void atualizarDespesa(Despesa *despesas, int tamanho) {
    int id;
    printf("Informe o ID da despesa que deseja atualizar: ");
    scanf("%d", &id);

    if (id < 1 || id > tamanho) {
        printf("Despesa não encontrada.\n");
        return;
    }

    Despesa *d = &despesas[id - 1];
    printf("Atualizando despesa %s\n", d->descricao);

    printf("Nova descrição: ");
    scanf(" %[^\n]s", d->descricao);

    printf("Novo valor: ");
    scanf("%f", &d->valor);

    printf("Nova data (dd/mm/yyyy): ");
    scanf(" %[^\n]s", d->data);

    printf("Despesa atualizada com sucesso!\n");
}

void deletarDespesa(Despesa **despesas, int *tamanho) {
    int id;
    printf("Informe o ID da despesa que deseja deletar: ");
    scanf("%d", &id);

    if (id < 1 || id > *tamanho) {
        printf("Despesa não encontrada.\n");
        return;
    }

    for (int i = id - 1; i < *tamanho - 1; i++) {
        (*despesas)[i] = (*despesas)[i + 1];
    }

    *despesas = realloc(*despesas, (*tamanho - 1) * sizeof(Despesa));
    (*tamanho)--;

    printf("Despesa deletada com sucesso!\n");
}
