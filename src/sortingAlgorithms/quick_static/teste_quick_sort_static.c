#include <stdio.h>
#include <string.h>
#include "quick_sort_lista_estatica.h"

/* Cria um jogador com os dados fornecidos */
static Jogador criarJogador(const char *nick, int pontos, int nivel, float tempo) {
    Jogador j;
    strncpy(j.nickname, nick, sizeof(j.nickname) - 1);
    j.nickname[sizeof(j.nickname) - 1] = '\0';
    j.pontuacao = pontos;
    j.nivel = nivel;
    j.tempo_jogado = tempo;
    return j;
}

static void imprimir(Jogador v[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s - %d pontos, nível %d, tempo %.1f\n",
               v[i].nickname, v[i].pontuacao, v[i].nivel, v[i].tempo_jogado);
    }
}

int main(void) {
    /* ---- Teste 1: vetor com vários elementos ---- */
    printf("=== Teste 1: vetor com 6 jogadores ===\n");
    Jogador jogadores1[6] = {
        criarJogador("Alice",   300,  5, 12.5),
        criarJogador("Bob",     150,  3,  8.0),
        criarJogador("Carlos",  500, 10, 25.0),
        criarJogador("Diana",   200,  4, 10.0),
        criarJogador("Eve",     500,  8, 20.0),
        criarJogador("Frank",    50,  1,  2.0)
    };

    printf("Antes da ordenação:\n");
    imprimir(jogadores1, 6);

    quick_sort_estatico(jogadores1, 6);

    printf("Depois da ordenação (pontuação decrescente):\n");
    imprimir(jogadores1, 6);

    /* ---- Teste 2: vetor vazio ---- */
    printf("\n=== Teste 2: vetor vazio ===\n");
    Jogador vazio[0];
    quick_sort_estatico(vazio, 0);
    printf("Vetor vazio após ordenação.\n");

    /* ---- Teste 3: vetor com 1 elemento ---- */
    printf("\n=== Teste 3: vetor com 1 elemento ===\n");
    Jogador unico[1] = { criarJogador("Solo", 999, 99, 100.0) };
    quick_sort_estatico(unico, 1);
    imprimir(unico, 1);

    /* ---- Teste 4: vetor já ordenado ---- */
    printf("\n=== Teste 4: vetor já ordenado ===\n");
    Jogador ordenado[3] = {
        criarJogador("A", 500, 5, 5.0),
        criarJogador("B", 400, 4, 4.0),
        criarJogador("C", 300, 3, 3.0)
    };
    quick_sort_estatico(ordenado, 3);
    imprimir(ordenado, 3);

    /* ---- Teste 5: vetor em ordem inversa ---- */
    printf("\n=== Teste 5: vetor em ordem inversa ===\n");
    Jogador inverso[3] = {
        criarJogador("X", 100, 1, 1.0),
        criarJogador("Y", 200, 2, 2.0),
        criarJogador("Z", 300, 3, 3.0)
    };
    quick_sort_estatico(inverso, 3);
    imprimir(inverso, 3);

    printf("\nTodos os testes do Quick Sort estático finalizados.\n");
    return 0;
}
