#include <stdio.h>
#include <string.h>

#include "../../lista_encadeada_estatica.h"
#include "insertion_sort_estatico.h"

static Jogador criarJogador(const char *nick, int pontuacao, int nivel, float tempo)
{
    Jogador j;
    strncpy(j.nickname, nick, sizeof(j.nickname) - 1);
    j.nickname[sizeof(j.nickname) - 1] = '\0';
    j.pontuacao = pontuacao;
    j.nivel = nivel;
    j.tempo_jogado = tempo;
    return j;
}

int main(void)
{
    Lista lista;
    iniciarLista(&lista);

    inserir(&lista, criarJogador("Taco", 1800, 45, 110.2f));
    inserir(&lista, criarJogador("Fnx", 3000, 70, 200.0f));
    inserir(&lista, criarJogador("Fallen", 2000, 50, 120.5f));
    inserir(&lista, criarJogador("Coldzera", 2500, 60, 150.0f));
    inserir(&lista, criarJogador("Kscerato", 3000, 65, 210.0f));

    printf("=== LISTA ANTES DO INSERTION SORT ===\n");
    imprimir(&lista);

    insertionSortEstatica(&lista);

    printf("\n=== LISTA APOS INSERTION SORT (pontuacao decrescente) ===\n");
    imprimir(&lista);

    return 0;
}
