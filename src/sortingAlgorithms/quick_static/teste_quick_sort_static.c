#include <stdio.h>
#include <string.h>
#include "../../lista_encadeada_estatica.h"
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

int main(void) {
    /* ---- Teste 1: lista estática com vários elementos ---- */
    printf("=== Teste 1: lista com 6 jogadores ===\n");
    Lista lista;
    iniciarLista(&lista);
    inserir(&lista, criarJogador("Alice",   300,  5, 12.5));
    inserir(&lista, criarJogador("Bob",     150,  3,  8.0));
    inserir(&lista, criarJogador("Carlos",  500, 10, 25.0));
    inserir(&lista, criarJogador("Diana",   200,  4, 10.0));
    inserir(&lista, criarJogador("Eve",     500,  8, 20.0));
    inserir(&lista, criarJogador("Frank",    50,  1,  2.0));

    printf("Antes da ordenação:\n");
    imprimir(&lista);

    quick_sort_estatico(&lista, ORDENAR_PONTUACAO);

    printf("Depois da ordenação (pontuação decrescente):\n");
    imprimir(&lista);

    /* ---- Teste 2: lista vazia ---- */
    printf("\n=== Teste 2: lista vazia ===\n");
    Lista vazio;
    iniciarLista(&vazio);
    quick_sort_estatico(&vazio, ORDENAR_PONTUACAO);
    imprimir(&vazio);

    /* ---- Teste 3: lista com 1 elemento ---- */
    printf("\n=== Teste 3: lista com 1 elemento ===\n");
    Lista unico;
    iniciarLista(&unico);
    inserir(&unico, criarJogador("Solo", 999, 99, 100.0));
    quick_sort_estatico(&unico, ORDENAR_PONTUACAO);
    imprimir(&unico);

    /* ---- Teste 4: lista já ordenada ---- */
    printf("\n=== Teste 4: lista já ordenada ===\n");
    Lista ordenado;
    iniciarLista(&ordenado);
    inserir(&ordenado, criarJogador("A", 500, 5, 5.0));
    inserir(&ordenado, criarJogador("B", 400, 4, 4.0));
    inserir(&ordenado, criarJogador("C", 300, 3, 3.0));
    quick_sort_estatico(&ordenado, ORDENAR_PONTUACAO);
    imprimir(&ordenado);

    /* ---- Teste 5: lista em ordem inversa ---- */
    printf("\n=== Teste 5: lista em ordem inversa ===\n");
    Lista inverso;
    iniciarLista(&inverso);
    inserir(&inverso, criarJogador("X", 100, 1, 1.0));
    inserir(&inverso, criarJogador("Y", 200, 2, 2.0));
    inserir(&inverso, criarJogador("Z", 300, 3, 3.0));
    quick_sort_estatico(&inverso, ORDENAR_PONTUACAO);
    imprimir(&inverso);

    printf("\nTodos os testes do Quick Sort estático finalizados.\n");
    return 0;
}
