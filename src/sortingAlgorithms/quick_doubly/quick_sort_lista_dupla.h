#ifndef QUICK_SORT_LISTA_DUPLA_H
#define QUICK_SORT_LISTA_DUPLA_H

#include "jogador.h"

typedef struct DoublyNode {
    Jogador data;
    struct DoublyNode *prev;
    struct DoublyNode *next;
} DoublyNode;

void quickSortDoublyLinkedList(DoublyNode **head);

#endif
