#include <stdio.h>
#include <string.h>
#include "../../lista_encadeada_dinamica.h"
#include "insertion_sort_dinamica.h"

/* Função auxiliar LOCAL ao teste */
static Jogador criarJogador(const char *nick,
                            int pontos,
                            int nivel,
                            float tempo)
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
    NoDuplo *lista = NULL;

    inserir(&lista, criarJogador("Carlos", 300, 10, 25.5));
    inserir(&lista, criarJogador("Ana", 150, 5, 10.0));
    inserir(&lista, criarJogador("Bruno", 450, 15, 40.2));
    inserir(&lista, criarJogador("Daniel", 200, 7, 18.4));

    printf("Antes:\n");
    imprimir(&lista);

    insertionSortListaDinamica(&lista, ORDENAR_PONTUACAO);

    printf("\nDepois:\n");
    imprimir(&lista);

    liberar_lista(&lista);

    return 0;
}
