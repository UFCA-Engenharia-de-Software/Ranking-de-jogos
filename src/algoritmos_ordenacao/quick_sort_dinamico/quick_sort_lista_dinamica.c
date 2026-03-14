#include <stdlib.h>
#include "quick_sort_lista_dinamica.h"

static void swapJogadores(NoDuplo *a, NoDuplo *b) {
    if (a == b) {
        return;
    }
    Jogador temp = a->data;
    a->data = b->data;
    b->data = temp;
}

static NoDuplo *obterMeioIntervalo(NoDuplo *low, NoDuplo *high) {
    NoDuplo *slow = low;
    NoDuplo *fast = low;

    while (fast != high && fast->next != high) {
        fast = fast->next;
        if (fast != high && fast->next != high) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

static NoDuplo *escolherPivoMedianOfThree(NoDuplo *low, NoDuplo *high,
                                          CriterioOrdenacao criterio) {
    NoDuplo *mid = obterMeioIntervalo(low, high);
    Jogador a = low->data;
    Jogador b = mid->data;
    Jogador c = high->data;

    if (comparar(a, b, criterio)) {
        if (comparar(b, c, criterio)) {
            return mid;
        }
        if (comparar(a, c, criterio)) {
            return high;
        }
        return low;
    }

    if (comparar(a, c, criterio)) {
        return low;
    }
    if (comparar(b, c, criterio)) {
        return high;
    }
    return mid;
}

/* Particiona a lista duplamente encadeada em torno de um pivô */
static NoDuplo *partition(NoDuplo *low, NoDuplo *high, CriterioOrdenacao criterio) {
    NoDuplo *pivoEscolhido = escolherPivoMedianOfThree(low, high, criterio);
    swapJogadores(pivoEscolhido, high);

    Jogador pivot = high->data;
    NoDuplo *i = low->prev;

    for (NoDuplo *j = low; j != high; j = j->next) {
        if (comparar(j->data, pivot, criterio)) {
            i = (i == NULL) ? low : i->next;
            swapJogadores(i, j);
        }
    }
    i = (i == NULL) ? low : i->next;
    swapJogadores(i, high);
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
void quickSortListaDinamica(NoDuplo **head, CriterioOrdenacao criterio) {
    if (head == NULL || *head == NULL)
        return;

    NoDuplo *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    _quickSort(*head, last, criterio);
}
