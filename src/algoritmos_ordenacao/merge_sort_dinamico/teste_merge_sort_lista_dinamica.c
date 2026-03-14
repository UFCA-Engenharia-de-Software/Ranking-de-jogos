#include <stdio.h>
#include <string.h>
#include "../../estruturas/dinamica/lista_encadeada_dinamica.h"
#include "merge_sort_lista_dinamica.h"

/* Cria um jogador com os dados fornecidos. */
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
    NoDuplo *lista = NULL;

    /* ---- Teste 1: lista com vários elementos ---- */
    printf("=== Teste 1: lista com 6 jogadores ===\n");
    inserirDinamica(&lista, criarJogador("Alice", 300, 5, 12.5));
    inserirDinamica(&lista, criarJogador("Bob", 150, 3, 8.0));
    inserirDinamica(&lista, criarJogador("Carlos", 500, 10, 25.0));
    inserirDinamica(&lista, criarJogador("Diana", 200, 4, 10.0));
    inserirDinamica(&lista, criarJogador("Eve", 500, 8, 20.0));
    inserirDinamica(&lista, criarJogador("Frank", 50, 1, 2.0));

    printf("Antes da ordenação:\n");
    imprimirDinamica(&lista);

    mergeSortListaDinamica(&lista, ORDENAR_PONTUACAO);

    printf("Depois da ordenação (pontuação decrescente):\n");
    imprimirDinamica(&lista);

    /* Verifica se os ponteiros prev estão corretos */
    printf("Verificando ponteiros prev... ");
    int ok = 1;
    for (NoDuplo *p = lista; p != NULL && p->next != NULL; p = p->next)
    {
        if (p->next->prev != p)
        {
            printf("ERRO: %s->next->prev != %s\n",
                   p->data.nickname, p->data.nickname);
            ok = 0;
        }
    }
    if (lista && lista->prev != NULL)
    {
        printf("ERRO: head->prev != NULL\n");
        ok = 0;
    }
    if (ok)
        printf("OK!\n");

    liberar_lista(&lista);

    /* ---- Teste 2: lista vazia ---- */
    printf("\n=== Teste 2: lista vazia ===\n");
    NoDuplo *vazia = NULL;
    mergeSortListaDinamica(&vazia, ORDENAR_PONTUACAO);
    printf("Lista vazia após ordenação: ");
    imprimirDinamica(&vazia);

    /* ---- Teste 3: lista com 1 elemento ---- */
    printf("=== Teste 3: lista com 1 elemento ===\n");
    NoDuplo *unico = NULL;
    inserirDinamica(&unico, criarJogador("Solo", 999, 99, 100.0));
    mergeSortListaDinamica(&unico, ORDENAR_PONTUACAO);
    printf("Lista com 1 elemento após ordenação:\n");
    imprimirDinamica(&unico);
    liberar_lista(&unico);

    /* ---- Teste 4: lista com 2 elementos ---- */
    printf("=== Teste 4: lista com 2 elementos ===\n");
    NoDuplo *dupla = NULL;
    inserirDinamica(&dupla, criarJogador("Menor", 10, 1, 1.0));
    inserirDinamica(&dupla, criarJogador("Maior", 90, 9, 9.0));
    mergeSortListaDinamica(&dupla, ORDENAR_PONTUACAO);
    printf("Lista com 2 elementos após ordenação:\n");
    imprimirDinamica(&dupla);
    liberar_lista(&dupla);

    /* ---- Teste 5: lista já ordenada ---- */
    printf("=== Teste 5: lista já ordenada ===\n");
    NoDuplo *ordenada = NULL;
    inserirDinamica(&ordenada, criarJogador("A", 500, 5, 5.0));
    inserirDinamica(&ordenada, criarJogador("B", 400, 4, 4.0));
    inserirDinamica(&ordenada, criarJogador("C", 300, 3, 3.0));
    mergeSortListaDinamica(&ordenada, ORDENAR_PONTUACAO);
    printf("Lista já ordenada após merge sort:\n");
    imprimirDinamica(&ordenada);
    liberar_lista(&ordenada);

    /* ---- Teste 6: lista em ordem inversa ---- */
    printf("=== Teste 6: lista em ordem inversa ===\n");
    NoDuplo *inversa = NULL;
    inserirDinamica(&inversa, criarJogador("X", 100, 1, 1.0));
    inserirDinamica(&inversa, criarJogador("Y", 200, 2, 2.0));
    inserirDinamica(&inversa, criarJogador("Z", 300, 3, 3.0));
    mergeSortListaDinamica(&inversa, ORDENAR_PONTUACAO);
    printf("Lista inversa após merge sort:\n");
    imprimirDinamica(&inversa);
    liberar_lista(&inversa);

    printf("Todos os testes finalizados.\n");
    return 0;
}
