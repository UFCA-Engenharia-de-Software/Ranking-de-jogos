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

#include "jogador.h"

#define MAX 10000
#define INVALIDO -1

typedef struct {
    Jogador jogador;
    int proximo;
    int anterior;
} No;

typedef struct {
    No vetor[MAX];
    int inicio;
    int livre;
} Lista;

/* === Declaração das funções === */

/* Inicializa a lista estática */
void iniciarLista(Lista *lista);

/* Insere um jogador na lista.
   Retorna o índice onde foi inserido ou INVALIDO se falhar */
int inserir(Lista *lista, Jogador jogador);

/* Imprime todos os jogadores da lista */
void imprimir(Lista *lista);

/* Busca um jogador pelo nickname.
   Retorna o índice ou INVALIDO se não encontrar */
int busca(Lista *lista, const char *nickname);

/* Remove o nó correspondente ao índice informado */
void deletar(Lista *lista, int indice_alvo);
#endif
