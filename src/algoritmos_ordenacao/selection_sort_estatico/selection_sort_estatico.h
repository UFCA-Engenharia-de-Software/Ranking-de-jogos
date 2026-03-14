#ifndef SELECTION_SORT_ESTATICO_H
#define SELECTION_SORT_ESTATICO_H

#include "../../estruturas/estatica/lista_encadeada_estatica.h"
#include "../../utilitarios/utilitarios_ordenacao.h"

/*
 * Selection Sort (lista estatica):
 * - Implementacao: iterativa, seleciona o maior elemento e posiciona no inicio da faixa.
 * - Melhor caso: O(n^2)
 * - Caso medio: O(n^2)
 * - Pior caso:   O(n^2)
 * - Espaco extra: O(1)
 */
void selection_sort_estatico(Lista *lista, CriterioOrdenacao criterio);

#endif /*SELECTIO_SORT_ESTATICO_H*/
