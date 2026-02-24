#include <stdio.h>
#include <string.h>
#include "../../lista_encadeada_dinamica.h"
#include "selection_sort_lista_duplamente_encadeada.h"

/* Função auxiliar para criar jogadores no teste */
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

    printf("=== Teste: Selection Sort (Lista Duplamente Encadeada) ===\n");

    inserir(&lista, criarJogador("Alice",   300,  5, 12.5));
    inserir(&lista, criarJogador("Bob",     150,  3,  8.0));
    inserir(&lista, criarJogador("Carlos",  500, 10, 25.0));
    inserir(&lista, criarJogador("Diana",   200,  4, 10.0));
    inserir(&lista, criarJogador("Eve",     500,  8, 20.0));
    inserir(&lista, criarJogador("Frank",    50,  1,  2.0));

    printf("\nAntes da ordenação:\n");
    imprimir(&lista);

    ordenacaoPorSelecaoListaDuplamenteEncadeada(&lista, ORDENAR_PONTUACAO);

    printf("\nDepois da ordenação (pontuação decrescente):\n");
    imprimir(&lista);

    /* Verificação estrutural dos ponteiros prev */
    printf("\nVerificando ponteiros prev... ");
    int ok = 1;
    for (NoDuplo *p = lista; p != NULL && p->next != NULL; p = p->next)
    {
        if (p->next->prev != p)
        {
            printf("ERRO estrutural!\n");
            ok = 0;
        }
    }
    if (lista && lista->prev != NULL)
    {
        printf("ERRO: cabeça->prev != NULL\n");
        ok = 0;
    }
    if (ok)
        printf("OK!\n");

    liberar_lista(&lista);

    printf("\nTeste finalizado.\n");
    return 0;
}
