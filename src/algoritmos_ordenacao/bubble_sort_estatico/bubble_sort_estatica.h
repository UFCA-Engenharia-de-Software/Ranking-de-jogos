#ifndef BUBBLE_SORT_ESTATICA_H
#define BUBBLE_SORT_ESTATICA_H

#include "../../estruturas/estatica/lista_encadeada_estatica.h"
#include "../../utilitarios/utilitarios_ordenacao.h"

/*
 * Bubble Sort (lista estatica):
 * - Implementacao: iterativa, com trocas adjacentes no vetor da lista.
 * - Melhor caso: O(n)         (lista ja ordenada, com otimizacao de parada)
 * - Caso medio: O(n^2)
 * - Pior caso:   O(n^2)
 * - Espaco extra: O(1)
 */
void bubbleSortEstatica(Lista *lista, CriterioOrdenacao criterio);

#endif
