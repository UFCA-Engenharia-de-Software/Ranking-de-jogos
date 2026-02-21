/*
Arquivo: teste_merge_estatico.c
Descrição:
Teste do Merge Sort aplicado à lista encadeada estática.
Ordena os jogadores por pontuação (ordem crescente).
*/

#include <stdio.h>
#include "../../jogador.h"
#include "../../lista_encadeada_estatica.h"
#include "merge_sort_lista_estatica.h"

/* Função auxiliar para criar jogadores */
static Jogador criarJogadorTeste(const char *nickname,
                                 int pontuacao,
                                 int nivel,
                                 float tempo)
{
    Jogador j;

    snprintf(j.nickname, sizeof(j.nickname), "%s", nickname);
    j.pontuacao = pontuacao;
    j.nivel = nivel;
    j.tempo_jogado = tempo;

    return j;
}

int main()
{
    Lista lista;

    /* CORRIGIDO: usar iniciarLista */
    iniciarLista(&lista);

    inserir(&lista, criarJogadorTeste("Carlos", 300, 10, 25.5));
    inserir(&lista, criarJogadorTeste("Ana", 150, 5, 10.0));
    inserir(&lista, criarJogadorTeste("Bruno", 450, 15, 40.2));
    inserir(&lista, criarJogadorTeste("Daniel", 200, 7, 18.4));

    printf("=== Antes da ordenação ===\n");
    imprimir(&lista);

    /* Chamada do merge sort */
    mergeSortListaEstatica(&lista);

    printf("\n=== Depois da ordenação (Merge Sort) ===\n");
    imprimir(&lista);

    return 0;
}