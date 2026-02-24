#include <stdlib.h>
#include "insertion_sort_dinamica.h"

void insertionSortListaDinamica(NoDuplo **head, CriterioOrdenacao criterio)
{
    if (head == NULL || *head == NULL)
        return;

    NoDuplo *atual = (*head)->next;

    while (atual != NULL)
    {
        NoDuplo *chave = atual;
        NoDuplo *anterior = atual->prev;

        while (anterior != NULL &&
               comparar(chave->data, anterior->data, criterio))
        {
            anterior = anterior->prev;
        }

        NoDuplo *proximo = atual->next;

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
