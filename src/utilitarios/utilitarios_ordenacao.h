/*
Arquivo: src/utilitarios/utilitarios_ordenacao.h
Descrição: Contém definições e funções auxiliares compartilhadas 
por todos os algoritmos de ordenação.
*/

#ifndef UTILITARIOS_ORDENACAO_H
#define UTILITARIOS_ORDENACAO_H

#include "../estruturas/jogador/jogador.h"

typedef enum {
    ORDENAR_PONTUACAO = 1,
    ORDENAR_NIVEL,
    ORDENAR_TEMPO,
    ORDENAR_COMBINADO
} CriterioOrdenacao;

int comparar(Jogador a, Jogador b, CriterioOrdenacao criterio);

#endif /* UTILITARIOS_ORDENACAO_H */
