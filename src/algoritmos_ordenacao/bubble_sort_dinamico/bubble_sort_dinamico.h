#ifndef BUBBLE_SORT_DINAMICO_H
#define BUBBLE_SORT_DINAMICO_H

#include "../../estruturas/dinamica/lista_encadeada_dinamica.h"
#include "../../utilitarios/utilitarios_ordenacao.h"

/*
 * Bubble Sort (lista dinamica):
 * - Implementacao: iterativa em lista duplamente encadeada, trocando dados dos nos.
 * - Melhor caso: O(n)         (lista ja ordenada, com otimizacao de parada)
 * - Caso medio: O(n^2)
 * - Pior caso:   O(n^2)
 * - Espaco extra: O(1)
 */
void bubble_sort_dinamico(NoDuplo **inicio, CriterioOrdenacao criterio);

#endif /* BUBBLE_SORT_DINAMICO_H */
