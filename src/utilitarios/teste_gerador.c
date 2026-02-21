#include <stdio.h>
#include "gerador_jogadores.h"

int main() {
    Lista minha_lista;

    printf("=== INICIANDO TESTES DO GERADOR (TASK 16) ===\n\n");

    // Cenário 1: 100 Elementos Aleatórios
    printf("-> Gerando 100 jogadores ALEATORIOS...\n");
    gerarJogadores(&minha_lista, 100, ALEATORIA);
    printf("[OK] Sucesso! (Primeiro da lista: %s)\n\n", minha_lista.vetor[minha_lista.inicio].jogador.nickname);

    // Cenário 2: 1.000 Elementos Ordenados
    printf("-> Gerando 1.000 jogadores ORDENADOS...\n");
    gerarJogadores(&minha_lista, 1000, ORDENADA);
    printf("[OK] Sucesso! (Primeiro da lista: %s)\n\n", minha_lista.vetor[minha_lista.inicio].jogador.nickname);

    // Cenário 3: 10.000 Elementos Inversamente Ordenados
    printf("-> Gerando 10.000 jogadores INVERSAMENTE ORDENADOS...\n");
    gerarJogadores(&minha_lista, 10000, INVERSAMENTE_ORDENADA);
    printf("[OK] Sucesso! (Primeiro da lista: %s)\n\n", minha_lista.vetor[minha_lista.inicio].jogador.nickname);

    printf("=== TODOS OS TESTES CONCLUIDOS ===\n");

    return 0;
}