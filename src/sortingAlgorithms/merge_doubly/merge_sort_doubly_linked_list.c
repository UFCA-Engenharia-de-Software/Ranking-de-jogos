#include <stdlib.h>
#include "merge_sort_doubly_linked_list.h"

/*
 * Mescla duas sublistas ordenadas em uma única lista duplamente
 * encadeada ordenada (decrescente por pontuação).
 *
 * Abordagem recursiva: a cada chamada, escolhe o nó com maior
 * pontuação e o coloca na frente da lista resultante.
 */
static DoublyNode *merge(DoublyNode *left, DoublyNode *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    if (left->data.pontuacao >= right->data.pontuacao)
    {
        left->next = merge(left->next, right);
        if (left->next)
            left->next->prev = left;
        left->prev = NULL;
        return left;
    }
    else
    {
        right->next = merge(left, right->next);
        if (right->next)
            right->next->prev = right;
        right->prev = NULL;
        return right;
    }
}

/*
 * mergeSort(head):
 *   SE (lista tem 0 ou 1 elemento):
 *       RETORNA (já está "ordenada")
 *
 *   1. Encontre o nó do meio usando getMiddler()
 *   2. Divida a lista em duas metades
 *   3. Chame mergeSort() recursivamente nas duas metades
 *   4. Chame merge() para mesclar as duas metades ordenadas
 */
void mergeSortDoublyLinkedList(DoublyNode **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    DoublyNode *middle = getMiddler(head);
    DoublyNode *secondHalf = middle->next;

    middle->next = NULL;
    if (secondHalf != NULL)
        secondHalf->prev = NULL;

    mergeSortDoublyLinkedList(head);
    mergeSortDoublyLinkedList(&secondHalf);

    *head = merge(*head, secondHalf);
}