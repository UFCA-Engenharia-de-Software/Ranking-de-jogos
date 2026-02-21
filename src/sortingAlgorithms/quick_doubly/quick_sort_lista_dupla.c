#include <stdlib.h>
#include "quick_sort_lista_dupla.h"

/* Particiona a lista duplamente encadeada em torno de um pivô */
static DoublyNode* partition(DoublyNode *low, DoublyNode *high) {
    int pivot = high->data.pontuacao;
    DoublyNode *i = low->prev;

    for (DoublyNode *j = low; j != high; j = j->next) {
        if (j->data.pontuacao >= pivot) {
            i = (i == NULL) ? low : i->next;
            Jogador temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
    i = (i == NULL) ? low : i->next;
    Jogador temp = i->data;
    i->data = high->data;
    high->data = temp;
    return i;
}

/* Função recursiva do Quick Sort */
static void _quickSort(DoublyNode *low, DoublyNode *high) {
    if (high != NULL && low != high && low != high->next) {
        DoublyNode *p = partition(low, high);
        _quickSort(low, p->prev);
        _quickSort(p->next, high);
    }
}

/* Interface pública */
void quickSortDoublyLinkedList(DoublyNode **head) {
    if (*head == NULL) return;

    DoublyNode *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    _quickSort(*head, last);
}
