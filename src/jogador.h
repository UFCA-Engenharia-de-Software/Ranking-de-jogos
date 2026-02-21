/*
Arquivo: jogador.h
Descrição:
Define a estrutura Jogador, que representa a entidade básica do sistema
de ranking de jogos online. A estrutura armazena as informações
necessárias para a ordenação e análise de desempenho dos jogadores,
como nickname, pontuação, nível e tempo jogado.

Também contém a declaração das funções relacionadas ao jogador.
*/
#ifndef JOGADOR_H
#define JOGADOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Jogador{
    char nickname[50];
    int pontuacao;
    int nivel;
    float tempo_jogado;
}Jogador;

#endif
