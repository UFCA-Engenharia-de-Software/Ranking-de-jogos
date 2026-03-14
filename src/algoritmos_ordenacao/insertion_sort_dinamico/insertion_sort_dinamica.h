#ifndef INSERTION_SORT_DINAMICO_H
#define INSERTION_SORT_DINAMICO_H

#include "../../estruturas/dinamica/lista_encadeada_dinamica.h"
#include "../../utilitarios/utilitarios_ordenacao.h"

/*
 * Insertion Sort (lista dinamica):
 * - Implementacao: iterativa em lista duplamente encadeada, realocando dados.
 * - Melhor caso: O(n)         (lista ja ordenada)
 * - Caso medio: O(n^2)
 * - Pior caso:   O(n^2)
 * - Espaco extra: O(1)
 */
void insertionSortListaDinamica(NoDuplo **head, CriterioOrdenacao criterio);

#endif
