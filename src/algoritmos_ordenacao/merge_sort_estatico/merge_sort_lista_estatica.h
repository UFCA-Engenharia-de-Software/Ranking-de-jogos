#ifndef MERGE_SORT_LISTA_ESTATICA_H
#define MERGE_SORT_LISTA_ESTATICA_H

#include "../../estruturas/estatica/lista_encadeada_estatica.h"
#include "../../utilitarios/utilitarios_ordenacao.h"

/*
 * Merge Sort (lista estatica):
 * - Implementacao: recursiva (divisao e conquista), mesclando sublistas ordenadas.
 * - Melhor caso: O(n log n)
 * - Caso medio: O(n log n)
 * - Pior caso:   O(n log n)
 * - Espaco extra: O(n) (vetor auxiliar na mesclagem)
 */
void mergeSortListaEstatica(Lista *lista, CriterioOrdenacao criterio);

#endif
