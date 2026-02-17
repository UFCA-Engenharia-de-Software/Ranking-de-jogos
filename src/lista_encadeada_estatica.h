/*
Arquivo: lista_encadeada_estatica.h
Descrição:
Define a lista encadeada estática, implementada a partir de um vetor
pré-alocado, e declara as funções responsáveis por sua manipulação.

O gerenciamento manual das posições livres permite comparar esta
estrutura com a lista encadeada dinâmica em termos de desempenho.
*/

#ifndef LISTA_ENCADEADA_ESTATICA_H
#define LISTA_ENCADEADA_ESTATICA_H

#define MAX 100
#define INVALIDO -1

typedef struct {
    int valor;
    int proximo;
    int anterior;
} No;

typedef struct {
    No vetor[MAX];
    int inicio;
    int livre;
} Lista;

#endif
