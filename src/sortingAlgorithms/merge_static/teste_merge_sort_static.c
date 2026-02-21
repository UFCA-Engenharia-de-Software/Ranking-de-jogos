#include <stdio.h>
#include <string.h>
#include "../../lista_encadeada_estatica.h"
#include "merge_sort_static_list.h"

/* Função auxiliar para criar jogador */
static Jogador criarJogador(const char *nick, int pontos, int nivel, float tempo)
{
    Jogador j;
    strncpy(j.nickname, nick, sizeof(j.nickname) - 1);
    j.nickname[sizeof(j.nickname) - 1] = '\0';
    j.pontuacao = pontos;
    j.nivel = nivel;
    j.tempo_jogado = tempo;
    return j;
}

int main(void)
{
    Lista lista;
    initLista(&lista);

    printf("=== Inserindo jogadores ===\n");

    insert(&lista, criarJogador("Alice", 300, 5, 12.5));
    insert(&lista, criarJogador("Bob", 150, 3, 8.0));
    insert(&lista, criarJogador("Carlos", 500, 10, 25.0));
    insert(&lista, criarJogador("Diana", 200, 4, 10.0));
    insert(&lista, criarJogador("Eve", 500, 8, 20.0));
    insert(&lista, criarJogador("Frank", 50, 1, 2.0));

    printf("\nAntes da ordenação:\n");
    print(&lista);

    mergeSortStaticList(&lista);

    printf("\nDepois da ordenação (pontuação decrescente):\n");
    print(&lista);

    printf("\nTestando lista vazia:\n");
    Lista vazia;
    initLista(&vazia);
    mergeSortStaticList(&vazia);
    print(&vazia);

    printf("\nTestando lista com 1 elemento:\n");
    Lista unico;
    initLista(&unico);
    insert(&unico, criarJogador("Solo", 999, 99, 100.0));
    mergeSortStaticList(&unico);
    print(&unico);

    return 0;
}