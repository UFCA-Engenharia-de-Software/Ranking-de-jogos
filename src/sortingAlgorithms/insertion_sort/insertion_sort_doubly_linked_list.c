#include "insertion_sort_doubly_linked_list.h"

/*
 * Insertion Sort para lista duplamente encadeada.
 * Ordenação decrescente por pontuação.
 */
void insertionSortDoublyLinkedList(DoublyNode **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return;

    DoublyNode *sorted = NULL;
    DoublyNode *current = *head;

    while (current != NULL)
    {
        DoublyNode *next = current->next;

        current->prev = current->next = NULL;

        if (sorted == NULL ||
            current->data.pontuacao >= sorted->data.pontuacao)
        {
            current->next = sorted;
            if (sorted)
                sorted->prev = current;
            sorted = current;
        }
        else
        {
            DoublyNode *temp = sorted;

            while (temp->next != NULL &&
                   temp->next->data.pontuacao > current->data.pontuacao)
            {
                temp = temp->next;
            }

            current->next = temp->next;
            if (temp->next)
                temp->next->prev = current;

            temp->next = current;
            current->prev = temp;
        }

        current = next;
    }

    *head = sorted;
}