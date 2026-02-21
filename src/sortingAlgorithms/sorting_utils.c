/*
Arquivo: src/sortingAlgorithms/sorting_utils.c
*/

#include "sorting_utils.h"

int comparar(Jogador a, Jogador b, CriterioOrdenacao criterio) {
    switch (criterio) {
        case ORDENAR_PONTUACAO:
            return a.pontuacao > b.pontuacao;

        case ORDENAR_NIVEL:
            return a.nivel > b.nivel;

        case ORDENAR_TEMPO:
            return a.tempo_jogado < b.tempo_jogado;

        case ORDENAR_COMBINADO:
            if (a.pontuacao != b.pontuacao)
                return a.pontuacao > b.pontuacao;
            if (a.nivel != b.nivel)
                return a.nivel > b.nivel;
            return a.tempo_jogado < b.tempo_jogado;
    }
    return 0;
}