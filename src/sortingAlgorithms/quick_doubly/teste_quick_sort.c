#include <stdio.h>
#include <string.h>
#include "../../lista_encadeada_dinamica.h"
#include "quick_sort_lista_dupla.h"

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
    NoDuplo *lista = NULL;

    /* ---- Teste 1: lista com vários elementos ---- */
    printf("=== Teste 1: lista com 6 jogadores ===\n");
    inserirDinamica(&lista, criarJogador("Alice",   300,  5, 12.5));
    inserirDinamica(&lista, criarJogador("Bob",     150,  3,  8.0));
    inserirDinamica(&lista, criarJogador("Carlos",  500, 10, 25.0));
    inserirDinamica(&lista, criarJogador("Diana",   200,  4, 10.0));
    inserirDinamica(&lista, criarJogador("Eve",     500,  8, 20.0));
    inserirDinamica(&lista, criarJogador("Frank",    50,  1,  2.0));

    printf("Antes da ordenação:\n");
    imprimirDinamica(&lista);

    quickSortDoublyLinkedList(&lista, ORDENAR_PONTUACAO);

    printf("Depois da ordenação (pontuação decrescente):\n");
    imprimirDinamica(&lista);

    liberar_lista(&lista);

    /* ---- Teste 2: lista vazia ---- */
    printf("\n=== Teste 2: lista vazia ===\n");
    NoDuplo *vazia = NULL;
    quickSortDoublyLinkedList(&vazia, ORDENAR_PONTUACAO);
    imprimirDinamica(&vazia);

    /* ---- Teste 3: lista com 1 elemento ---- */
    printf("\n=== Teste 3: lista com 1 elemento ===\n");
    NoDuplo *unico = NULL;
    inserirDinamica(&unico, criarJogador("Solo", 999, 99, 100.0));
    quickSortDoublyLinkedList(&unico, ORDENAR_PONTUACAO);
    imprimirDinamica(&unico);
    liberar_lista(&unico);

    /* ---- Teste 4: lista já ordenada ---- */
    printf("\n=== Teste 4: lista já ordenada ===\n");
    NoDuplo *ordenada = NULL;
    inserirDinamica(&ordenada, criarJogador("C", 300, 3, 3.0));
    inserirDinamica(&ordenada, criarJogador("B", 400, 4, 4.0));
    inserirDinamica(&ordenada, criarJogador("A", 500, 5, 5.0));
    quickSortDoublyLinkedList(&ordenada, ORDENAR_PONTUACAO);
    imprimirDinamica(&ordenada);
    liberar_lista(&ordenada);

    /* ---- Teste 5: lista em ordem inversa ---- */
    printf("\n=== Teste 5: lista em ordem inversa ===\n");
    NoDuplo *inversa = NULL;
    inserirDinamica(&inversa, criarJogador("X", 100, 1, 1.0));
    inserirDinamica(&inversa, criarJogador("Y", 200, 2, 2.0));
    inserirDinamica(&inversa, criarJogador("Z", 300, 3, 3.0));
    quickSortDoublyLinkedList(&inversa, ORDENAR_PONTUACAO);
    imprimirDinamica(&inversa);
    liberar_lista(&inversa);

    printf("\nTodos os testes do Quick Sort dinâmico finalizados.\n");
    return 0;
}
