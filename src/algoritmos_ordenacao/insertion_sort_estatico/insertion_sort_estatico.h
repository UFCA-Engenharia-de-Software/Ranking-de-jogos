#ifndef INSERTION_SORT_ESTATICO_H
#define INSERTION_SORT_ESTATICO_H

#include "../../estruturas/estatica/lista_encadeada_estatica.h"
#include "../../utilitarios/utilitarios_ordenacao.h"

/*
 * Insertion Sort (lista estatica):
 * - Implementacao: iterativa, insere cada elemento na parte ja ordenada.
 * - Melhor caso: O(n)         (lista ja ordenada)
 * - Caso medio: O(n^2)
 * - Pior caso:   O(n^2)
 * - Espaco extra: O(1)
 */
void insertionSortEstatica(Lista *lista, CriterioOrdenacao criterio);

#endif /* INSERTION_SORT_ESTATICO_H */
