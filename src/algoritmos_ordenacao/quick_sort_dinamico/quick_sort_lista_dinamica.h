#ifndef QUICK_SORT_LISTA_DUPLA_H
#define QUICK_SORT_LISTA_DUPLA_H

#include "../../estruturas/dinamica/lista_encadeada_dinamica.h"
#include "../../utilitarios/utilitarios_ordenacao.h"

/*
 * Quick Sort (lista dinamica):
 * - Implementacao: recursiva em lista duplamente encadeada, com median-of-three.
 * - Melhor caso: O(n log n)
 * - Caso medio: O(n log n)
 * - Pior caso:   O(n^2) (particoes muito desbalanceadas)
 * - Espaco extra: O(log n) medio de pilha recursiva
 */
void quickSortListaDinamica(NoDuplo **head, CriterioOrdenacao criterio);

#endif
