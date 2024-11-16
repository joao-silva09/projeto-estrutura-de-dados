#ifndef DESPESA_H
#define DESPESA_H

typedef struct {
    int id;
    char descricao[100];
    float valor;
    char data[11];
} Despesa;

void inicializarDespesas(Despesa **despesas, int *tamanho);
void criarDespesa(Despesa **despesas, int *tamanho);
void exibirDespesas(Despesa *despesas, int tamanho);
void atualizarDespesa(Despesa *despesas, int tamanho);
void deletarDespesa(Despesa **despesas, int *tamanho);

#endif
