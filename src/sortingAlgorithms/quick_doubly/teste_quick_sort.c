#include <stdio.h>
#include <string.h>
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

/* Funções auxiliares de lista (apenas para o teste) */
static void inserir(DoublyNode **head, Jogador j) {
    DoublyNode *novo = (DoublyNode*) malloc(sizeof(DoublyNode));
    novo->data = j;
    novo->next = *head;
    novo->prev = NULL;
    if (*head) (*head)->prev = novo;
    *head = novo;
}

static void imprimir(DoublyNode *head) {
    for (DoublyNode *p = head; p != NULL; p = p->next) {
        printf("%s - %d pontos, nível %d, tempo %.1f\n",
               p->data.nickname, p->data.pontuacao, p->data.nivel, p->data.tempo_jogado);
    }
}

static void liberar(DoublyNode **head) {
    DoublyNode *p = *head;
    while (p) {
        DoublyNode *tmp = p;
        p = p->next;
        free(tmp);
    }
    *head = NULL;
}

int main(void) {
    DoublyNode *lista = NULL;

    /* ---- Teste 1: lista com vários elementos ---- */
    printf("=== Teste 1: lista com 6 jogadores ===\n");
    inserir(&lista, criarJogador("Alice",   300,  5, 12.5));
    inserir(&lista, criarJogador("Bob",     150,  3,  8.0));
    inserir(&lista, criarJogador("Carlos",  500, 10, 25.0));
    inserir(&lista, criarJogador("Diana",   200,  4, 10.0));
    inserir(&lista, criarJogador("Eve",     500,  8, 20.0));
    inserir(&lista, criarJogador("Frank",    50,  1,  2.0));

    printf("Antes da ordenação:\n");
    imprimir(lista);

    quickSortDoublyLinkedList(&lista);

    printf("Depois da ordenação (pontuação decrescente):\n");
    imprimir(lista);

    liberar(&lista);

    /* ---- Teste 2: lista vazia ---- */
    printf("\n=== Teste 2: lista vazia ===\n");
    DoublyNode *vazia = NULL;
    quickSortDoublyLinkedList(&vazia);
    imprimir(vazia);

    /* ---- Teste 3: lista com 1 elemento ---- */
    printf("\n=== Teste 3: lista com 1 elemento ===\n");
    DoublyNode *unico = NULL;
    inserir(&unico, criarJogador("Solo", 999, 99, 100.0));
    quickSortDoublyLinkedList(&unico);
    imprimir(unico);
    liberar(&unico);

    /* ---- Teste 4: lista já ordenada ---- */
    printf("\n=== Teste 4: lista já ordenada ===\n");
    DoublyNode *ordenada = NULL;
    inserir(&ordenada, criarJogador("C", 300, 3, 3.0));
    inserir(&ordenada, criarJogador("B", 400, 4, 4.0));
    inserir(&ordenada, criarJogador("A", 500, 5, 5.0));
    quickSortDoublyLinkedList(&ordenada);
    imprimir(ordenada);
    liberar(&ordenada);

    /* ---- Teste 5: lista em ordem inversa ---- */
    printf("\n=== Teste 5: lista em ordem inversa ===\n");
    DoublyNode *inversa = NULL;
    inserir(&inversa, criarJogador("X", 100, 1, 1.0));
    inserir(&inversa, criarJogador("Y", 200, 2, 2.0));
    inserir(&inversa, criarJogador("Z", 300, 3, 3.0));
    quickSortDoublyLinkedList(&inversa);
    imprimir(inversa);
    liberar(&inversa);

    printf("\nTodos os testes do Quick Sort dinâmico finalizados.\n");
    return 0;
}
