#ifndef QUICK_SORT_LISTA_ESTATICA_H
#define QUICK_SORT_LISTA_ESTATICA_H

#include "../../estruturas/estatica/lista_encadeada_estatica.h"
#include "../../utilitarios/utilitarios_ordenacao.h"

/*
 * Quick Sort (lista estatica):
 * - Implementacao: recursiva, particionamento in-place.
 * - Melhor caso: O(n log n)
 * - Caso medio: O(n log n)
 * - Pior caso:   O(n^2) (particoes muito desbalanceadas)
 * - Espaco extra: O(log n) medio de pilha recursiva
 */
void quick_sort_estatico(Lista *lista, CriterioOrdenacao criterio);

#endif
