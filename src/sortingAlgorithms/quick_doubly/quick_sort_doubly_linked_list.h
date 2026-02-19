#ifndef QUICK_SORT_DOUBLY_LINKED_LIST_H
#define QUICK_SORT_DOUBLY_LINKED_LIST_H

#include "jogador.h"

typedef struct DoublyNode {
    Jogador data;
    struct DoublyNode *prev;
    struct DoublyNode *next;
} DoublyNode;

void quickSortDoublyLinkedList(DoublyNode **head);

#endif
