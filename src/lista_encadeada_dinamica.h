/*
Arquivo: lista_encadeada_dinamica.h
Descrição:
Define a estrutura da lista duplamente encadeada dinâmica (DoublyNode)
e declara as funções responsáveis por sua manipulação, incluindo
inserção, remoção, busca, impressão e liberação de memória.

Cada nó armazena um Jogador e ponteiros para o nó anterior e próximo,
permitindo crescimento flexível conforme a quantidade de jogadores.
*/

#ifndef LISTA_ENCADEADA_DINAMICA_H
#define LISTA_ENCADEADA_DINAMICA_H

#include "jogador.h"

typedef struct DoublyNode
{
    Jogador data;
    struct DoublyNode *prev;
    struct DoublyNode *next;
} DoublyNode;

/* Insere um jogador ao final da lista. */
void insert(DoublyNode **head, Jogador jogador);

/* Inicializa a lista lendo 'length' jogadores da entrada padrão. */
DoublyNode *init(int length);

/* Remove o nó na posição 'idx' (0-based). */
void delete (DoublyNode **head, int idx);

/* Busca um jogador pelo nickname. Retorna ponteiro para o nó ou NULL. */
DoublyNode *search(DoublyNode **head, const char *nickname);

/* Imprime todos os jogadores da lista. */
void print(DoublyNode **head);

/* Libera toda a memória alocada pela lista. */
void free_list(DoublyNode **head);

/* Retorna o nó do meio (final da primeira metade). */
DoublyNode *getMiddler(DoublyNode **head);

/* Retorna o comprimento da lista. */
int DoublyLinkedListLength(DoublyNode **head);

#endif /* LISTA_ENCADEADA_DINAMICA_H */
