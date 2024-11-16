#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "motorista.h"

void inicializarMotoristas(Motorista **motoristas, int *tamanho) {
    *motoristas = NULL;
    *tamanho = 0;
}

void criarMotorista(Motorista **motoristas, int *tamanho) {
    *motoristas = realloc(*motoristas, (*tamanho + 1) * sizeof(Motorista));
    if (*motoristas == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    Motorista *m = &(*motoristas)[*tamanho];
    m->id = *tamanho + 1;
    
    printf("Nome: ");
    scanf(" %[^\n]s", m->nome);
    
    printf("CPF: ");
    scanf(" %[^\n]s", m->cpf);
    
    printf("Telefone: ");
    scanf(" %[^\n]s", m->telefone);
    
    (*tamanho)++;
    printf("Motorista cadastrado com sucesso!\n");
}

void exibirMotoristas(Motorista *motoristas, int tamanho) {
    if (tamanho == 0) {
        printf("Nenhum motorista cadastrado.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("ID: %d\n", motoristas[i].id);
        printf("Nome: %s\n", motoristas[i].nome);
        printf("CPF: %s\n", motoristas[i].cpf);
        printf("Telefone: %s\n", motoristas[i].telefone);
        printf("---------------------------\n");
    }
}

void atualizarMotorista(Motorista *motoristas, int tamanho) {
    int id;
    printf("Informe o ID do motorista que deseja atualizar: ");
    scanf("%d", &id);

    if (id < 1 || id > tamanho) {
        printf("Motorista não encontrado.\n");
        return;
    }

    Motorista *m = &motoristas[id - 1];
    printf("Atualizando motorista %s\n", m->nome);
    
    printf("Novo Nome: ");
    scanf(" %[^\n]s", m->nome);
    
    printf("Novo CPF: ");
    scanf(" %[^\n]s", m->cpf);
    
    printf("Novo Telefone: ");
    scanf(" %[^\n]s", m->telefone);

    printf("Motorista atualizado com sucesso!\n");
}

void deletarMotorista(Motorista **motoristas, int *tamanho) {
    int id;
    printf("Informe o ID do motorista que deseja deletar: ");
    scanf("%d", &id);

    if (id < 1 || id > *tamanho) {
        printf("Motorista não encontrado.\n");
        return;
    }

    for (int i = id - 1; i < *tamanho - 1; i++) {
        (*motoristas)[i] = (*motoristas)[i + 1];
    }

    *motoristas = realloc(*motoristas, (*tamanho - 1) * sizeof(Motorista));
    (*tamanho)--;

    printf("Motorista deletado com sucesso!\n");
}
