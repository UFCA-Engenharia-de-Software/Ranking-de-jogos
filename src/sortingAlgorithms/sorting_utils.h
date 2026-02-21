/*
Arquivo: src/sortingAlgorithms/sorting_utils.h
Descrição: Contém definições e funções auxiliares compartilhadas 
por todos os algoritmos de ordenação.
*/

#ifndef SORTING_UTILS_H
#define SORTING_UTILS_H

#include "../jogador.h"

typedef enum {
    ORDENAR_PONTUACAO = 1,
    ORDENAR_NIVEL,
    ORDENAR_TEMPO,
    ORDENAR_COMBINADO
} CriterioOrdenacao;

int comparar(Jogador a, Jogador b, CriterioOrdenacao criterio);

#endif /* SORTING_UTILS_H */