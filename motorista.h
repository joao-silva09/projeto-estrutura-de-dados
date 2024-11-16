#ifndef MOTORISTA_H
#define MOTORISTA_H

typedef struct {
    int id;
    char nome[50];
    char cpf[15];
    char telefone[20];
} Motorista;

void inicializarMotoristas(Motorista **motoristas, int *tamanho);
void criarMotorista(Motorista **motoristas, int *tamanho);
void exibirMotoristas(Motorista *motoristas, int tamanho);
void atualizarMotorista(Motorista *motoristas, int tamanho);
void deletarMotorista(Motorista **motoristas, int *tamanho);

#endif
