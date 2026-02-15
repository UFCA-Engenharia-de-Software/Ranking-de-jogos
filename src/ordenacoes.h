#ifndef ORDENACOES_H
#define ORDENACOES_H

/* Forward declaration do nó da lista */
typedef struct No No;

/* Critérios de ordenação */
typedef enum {
    ORDENAR_PONTUACAO = 1,
    ORDENAR_NIVEL,
    ORDENAR_TEMPO,
    ORDENAR_COMBINADO
} CriterioOrdenacao;

/* Algoritmos de ordenação */
void insertion_sort(No **head, CriterioOrdenacao criterio);
void merge_sort(No **head, CriterioOrdenacao criterio);

#endif