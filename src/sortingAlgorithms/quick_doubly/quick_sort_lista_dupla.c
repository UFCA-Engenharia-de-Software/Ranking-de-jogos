#include <stdlib.h>
#include "quick_sort_lista_dupla.h"

/* Particiona a lista duplamente encadeada em torno de um pivô */
static NoDuplo *partition(NoDuplo *low, NoDuplo *high, CriterioOrdenacao criterio) {
    Jogador pivot = high->data;
    NoDuplo *i = low->prev;

    for (NoDuplo *j = low; j != high; j = j->next) {
        if (comparar(j->data, pivot, criterio)) {
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
static void _quickSort(NoDuplo *low, NoDuplo *high, CriterioOrdenacao criterio) {
    if (high != NULL && low != high && low != high->next) {
        NoDuplo *p = partition(low, high, criterio);
        _quickSort(low, p->prev, criterio);
        _quickSort(p->next, high, criterio);
    }
}

/* Interface pública */
void quickSortDoublyLinkedList(NoDuplo **head, CriterioOrdenacao criterio) {
    if (head == NULL || *head == NULL)
        return;

    NoDuplo *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    _quickSort(*head, last, criterio);
}
