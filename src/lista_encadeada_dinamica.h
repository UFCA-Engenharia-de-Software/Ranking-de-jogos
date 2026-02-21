/*
Arquivo: lista_encadeada_dinamica.h
Descrição:
Define a estrutura da lista duplamente encadeada dinâmica (NoDuplo)
e declara as funções responsáveis por sua manipulação, incluindo
inserção, remoção, busca, impressão e liberação de memória.

Cada nó armazena um Jogador e ponteiros para o nó anterior e próximo,
permitindo crescimento flexível conforme a quantidade de jogadores.
*/

#ifndef LISTA_ENCADEADA_DINAMICA_H
#define LISTA_ENCADEADA_DINAMICA_H

#include "jogador.h"

typedef struct NoDuplo
{
    Jogador data;
    struct NoDuplo *prev;
    struct NoDuplo *next;
} NoDuplo;

/* Insere um jogador ao final da lista. */
void inserir(NoDuplo **head, Jogador jogador);

/* Inicializa a lista lendo 'length' jogadores da entrada padrão. */
NoDuplo *inicializar(int length);

/* Remove o nó na posição 'idx' (0-based). */
void remover(NoDuplo **head, int idx);

/* Busca um jogador pelo nickname. Retorna ponteiro para o nó ou NULL. */
NoDuplo *buscar(NoDuplo **head, const char *nickname);

/* Imprime todos os jogadores da lista. */
void imprimir(NoDuplo **head);

/* Libera toda a memória alocada pela lista. */
void liberar_lista(NoDuplo **head);

/* Retorna o nó do meio (final da primeira metade). */
NoDuplo *obterMeio(NoDuplo **head);

/* Retorna o comprimento da lista. */
int tamanhoListaDupla(NoDuplo **head);

#endif /* LISTA_ENCADEADA_DINAMICA_H */
