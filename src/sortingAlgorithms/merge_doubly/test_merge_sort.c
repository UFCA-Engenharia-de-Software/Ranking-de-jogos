#include <stdio.h>
#include <string.h>
#include "../../lista_encadeada_dinamica.h"
#include "merge_sort_doubly_linked_list.h"

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
    inserir(&lista, criarJogador("Alice", 300, 5, 12.5));
    inserir(&lista, criarJogador("Bob", 150, 3, 8.0));
    inserir(&lista, criarJogador("Carlos", 500, 10, 25.0));
    inserir(&lista, criarJogador("Diana", 200, 4, 10.0));
    inserir(&lista, criarJogador("Eve", 500, 8, 20.0));
    inserir(&lista, criarJogador("Frank", 50, 1, 2.0));

    printf("Antes da ordenação:\n");
    imprimir(&lista);

    mergeSortListaDupla(&lista);

    printf("Depois da ordenação (pontuação decrescente):\n");
    imprimir(&lista);

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
    mergeSortListaDupla(&vazia);
    printf("Lista vazia após ordenação: ");
    imprimir(&vazia);

    /* ---- Teste 3: lista com 1 elemento ---- */
    printf("=== Teste 3: lista com 1 elemento ===\n");
    NoDuplo *unico = NULL;
    inserir(&unico, criarJogador("Solo", 999, 99, 100.0));
    mergeSortListaDupla(&unico);
    printf("Lista com 1 elemento após ordenação:\n");
    imprimir(&unico);
    liberar_lista(&unico);

    /* ---- Teste 4: lista com 2 elementos ---- */
    printf("=== Teste 4: lista com 2 elementos ===\n");
    NoDuplo *dupla = NULL;
    inserir(&dupla, criarJogador("Menor", 10, 1, 1.0));
    inserir(&dupla, criarJogador("Maior", 90, 9, 9.0));
    mergeSortListaDupla(&dupla);
    printf("Lista com 2 elementos após ordenação:\n");
    imprimir(&dupla);
    liberar_lista(&dupla);

    /* ---- Teste 5: lista já ordenada ---- */
    printf("=== Teste 5: lista já ordenada ===\n");
    NoDuplo *ordenada = NULL;
    inserir(&ordenada, criarJogador("A", 500, 5, 5.0));
    inserir(&ordenada, criarJogador("B", 400, 4, 4.0));
    inserir(&ordenada, criarJogador("C", 300, 3, 3.0));
    mergeSortListaDupla(&ordenada);
    printf("Lista já ordenada após merge sort:\n");
    imprimir(&ordenada);
    liberar_lista(&ordenada);

    /* ---- Teste 6: lista em ordem inversa ---- */
    printf("=== Teste 6: lista em ordem inversa ===\n");
    NoDuplo *inversa = NULL;
    inserir(&inversa, criarJogador("X", 100, 1, 1.0));
    inserir(&inversa, criarJogador("Y", 200, 2, 2.0));
    inserir(&inversa, criarJogador("Z", 300, 3, 3.0));
    mergeSortListaDupla(&inversa);
    printf("Lista inversa após merge sort:\n");
    imprimir(&inversa);
    liberar_lista(&inversa);

    printf("Todos os testes finalizados.\n");
    return 0;
}
