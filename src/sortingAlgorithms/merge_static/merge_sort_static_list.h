/*
Arquivo: merge_sort_static_list.h
Descrição:
Declara a função de Merge Sort para lista encadeada estática
(implementada sobre vetor). A ordenação é feita de forma
decrescente pela pontuação do jogador.
*/

#ifndef MERGE_SORT_STATIC_LIST_H
#define MERGE_SORT_STATIC_LIST_H

#include "../../lista_encadeada_estatica.h"

/* Ordena a lista estática por pontuação (decrescente). */
void mergeSortStaticList(Lista *lista);

#endif /* MERGE_SORT_STATIC_LIST_H */