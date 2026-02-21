#include "bubble_sort_dinamico.h"
#include <stddef.h>

void bubble_sort_dinamico(NoDuplo **inicio, CriterioOrdenacao criterio)
{
    if (inicio == NULL || *inicio == NULL || (*inicio)->next == NULL)
    {
        return;
    }

    int trocou;
    NoDuplo *atual;
    NoDuplo *ultimo = NULL;

    do
    {
        trocou = 0;
        atual = *inicio;

        while (atual->next != ultimo)
        {

            if (comparar(atual->next->data, atual->data, criterio))
            {
                Jogador temporario = atual->data;
                atual->data = atual->next->data;
                atual->next->data = temporario;
                trocou = 1;
            }
            atual = atual->next;
        }
        ultimo = atual;

    } while (trocou);
}