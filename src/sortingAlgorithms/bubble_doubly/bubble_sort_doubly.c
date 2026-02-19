#include "bubble_sort_doubly.h"
#include <stddef.h>

void bubble_sort_dinamico(DoublyNode **head, CriterioOrdenacao criterio) {
    if (head == NULL || *head == NULL || (*head)->next == NULL) {
        return;
    }

    int trocou;
    DoublyNode *atual;
    DoublyNode *ultimo = NULL;

    do {
        trocou = 0;
        atual = *head;

        while (atual->next != ultimo) {
            
            if (comparar(atual->next->data, atual->data, criterio)) {
                Jogador temp = atual->data;
                atual->data = atual->next->data;
                atual->next->data = temp;
                trocou = 1;
            }
            atual = atual->next;
        }
        ultimo = atual;

    } while (trocou);
}