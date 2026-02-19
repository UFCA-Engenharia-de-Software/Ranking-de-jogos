/*
Arquivo: ordenacoes.h
Descrição:
Declara os algoritmos clássicos de ordenação utilizados no trabalho,
como Bubble Sort, Insertion Sort, Selection Sort, Quick Sort e Merge
Sort.

Os algoritmos permitem a ordenação dos jogadores segundo diferentes
critérios, como pontuação, nível e tempo jogado.
*/

#ifndef ORDENACOES_H
#define ORDENACOES_H

/* Forward declaration do nó da lista dinâmica */
typedef struct No No;

#include "lista_encadeada_estatica.h"

/* Critérios de ordenação */
typedef enum {
    ORDENAR_PONTUACAO = 1,
    ORDENAR_NIVEL,
    ORDENAR_TEMPO,
    ORDENAR_COMBINADO
} CriterioOrdenacao;

/* Algoritmos de ordenação dinâmicos */

/* Insertion Sort*/
void insertion_sort_dinamico(No **head, CriterioOrdenacao criterio);

/* Merge Sort*/
void merge_sort(No **head, CriterioOrdenacao criterio);

/* Algoritmos de ordenação estáticos */

/* Merge Sort – lista estática */
void merge_sort_estatico(Jogador v[], int tamanho,
                         CriterioOrdenacao criterio);

void insertion_sort_estatico(Lista *lista);

void quick_sort_dinamico(No **head, CriterioOrdenacao criterio);
void quick_sort_estatico(Lista *lista, CriterioOrdenacao criterio);

#endif