#include <stdlib.h>
#include "insertion_sort_dinamica.h"

void insertionSortListaDinamica(DoublyNode **head)
{
    if (head == NULL || *head == NULL)
        return;

    DoublyNode *atual = (*head)->next;

    while (atual != NULL)
    {
        DoublyNode *chave = atual;
        DoublyNode *anterior = atual->prev;

        while (anterior != NULL &&
               anterior->data.pontuacao > chave->data.pontuacao)
        {
            anterior = anterior->prev;
        }

        DoublyNode *proximo = atual->next;

        /* Remove chave da posição atual */
        if (chave->prev)
            chave->prev->next = chave->next;
        if (chave->next)
            chave->next->prev = chave->prev;

        /* Insere na nova posição */
        if (anterior == NULL)
        {
            chave->next = *head;
            chave->prev = NULL;
            (*head)->prev = chave;
            *head = chave;
        }
        else
        {
            chave->next = anterior->next;
            chave->prev = anterior;
            if (anterior->next)
                anterior->next->prev = chave;
            anterior->next = chave;
        }

        atual = proximo;
    }
}