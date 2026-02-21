/*
Arquivo: merge_sort_doubly_linked_list.h
Descrição:
Declara a função de Merge Sort para lista duplamente encadeada
dinâmica (NoDuplo). A ordenação é feita de forma decrescente
pela pontuação do jogador.
*/

#ifndef MERGE_SORT_DOUBLY_LINKED_LIST_H
#define MERGE_SORT_DOUBLY_LINKED_LIST_H

#include "../../lista_encadeada_dinamica.h"
#include "../sorting_utils.h"

void mergeSortListaDupla(NoDuplo **head, CriterioOrdenacao criterio);

#endif /* MERGE_SORT_DOUBLY_LINKED_LIST_H */
