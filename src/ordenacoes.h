#ifndef ORDENACOES_H
#define ORDENACOES_H

/* Forward declaration do nó da lista dinâmica */
typedef struct No No;

/* Critérios de ordenação */
typedef enum {
    ORDENAR_PONTUACAO = 1,
    ORDENAR_NIVEL,
    ORDENAR_TEMPO,
    ORDENAR_COMBINADO
} CriterioOrdenacao;

/* Lista Duplamente Encadeada */

/* Insertion Sort – lista dinâmica */
void insertion_sort(No **head, CriterioOrdenacao criterio);

/* Merge Sort – lista dinâmica */
void merge_sort(No **head, CriterioOrdenacao criterio);

/* Lista Estática (vetor) */

/* Merge Sort – lista estática */
void merge_sort_estatico(Jogador v[], int tamanho,
                         CriterioOrdenacao criterio);

#endif