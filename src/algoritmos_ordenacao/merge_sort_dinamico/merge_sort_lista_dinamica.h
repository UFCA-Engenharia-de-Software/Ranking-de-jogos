/*
Arquivo: merge_sort_lista_dinamica.h
Descrição:
Declara a função de Merge Sort para lista duplamente encadeada
dinâmica (NoDuplo). A ordenação é feita de forma decrescente
pela pontuação do jogador.

Complexidade e implementacao:
- Implementacao: recursiva (divisao e conquista), dividindo pela metade e mesclando.
- Melhor caso: O(n log n)
- Caso medio: O(n log n)
- Pior caso:   O(n log n)
- Espaco extra: O(log n) de pilha recursiva (alocacao auxiliar relevante por ponteiros)
*/

#ifndef MERGE_SORT_DOUBLY_LINKED_LIST_H
#define MERGE_SORT_DOUBLY_LINKED_LIST_H

#include "../../estruturas/dinamica/lista_encadeada_dinamica.h"
#include "../../utilitarios/utilitarios_ordenacao.h"

void mergeSortListaDinamica(NoDuplo **head, CriterioOrdenacao criterio);

#endif /* MERGE_SORT_DOUBLY_LINKED_LIST_H */
