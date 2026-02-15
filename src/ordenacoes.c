#include <stddef.h>             
#include "ordenacoes.h"
#include "jogador.h"                 
#include "lista_encadeada_dinamica.h"

/* Função de comparação (critério selecionável) */
static int comparar(Jogador a, Jogador b, CriterioOrdenacao criterio) {
    switch (criterio) {

        case ORDENAR_PONTUACAO:
            return a.pontuacao > b.pontuacao;

        case ORDENAR_NIVEL:
            return a.nivel > b.nivel;

        case ORDENAR_TEMPO:
            return a.tempo_jogado < b.tempo_jogado;

        case ORDENAR_COMBINADO:
            if (a.pontuacao != b.pontuacao)
                return a.pontuacao > b.pontuacao;
            if (a.nivel != b.nivel)
                return a.nivel > b.nivel;
            return a.tempo_jogado < b.tempo_jogado;
    }
    return 0;
}

/* Insection Sort – Lista Duplamente Encadeada */
void insertion_sort(No **head, CriterioOrdenacao criterio) {
    if (!head || !*head || !(*head)->next)
        return;

    No *atual = (*head)->next;

    while (atual) {
        No *proximo = atual->next;
        No *pos = atual->prev;

        /* Remove o nó da posição atual */
        if (atual->prev)
            atual->prev->next = atual->next;
        if (atual->next)
            atual->next->prev = atual->prev;

        /* Busca a posição correta */
        while (pos && comparar(atual->dado, pos->dado, criterio))
            pos = pos->prev;

        /* Insere na posição correta */
        if (!pos) {
            atual->next = *head;
            atual->prev = NULL;
            (*head)->prev = atual;
            *head = atual;
        } else {
            atual->next = pos->next;
            atual->prev = pos;

            if (pos->next)
                pos->next->prev = atual;

            pos->next = atual;
        }

        atual = proximo;
    }
}

/* Merge Sort – Funções auxiliares  */
static No* dividir_lista(No *head) {
    No *lento = head;
    No *rapido = head;

    while (rapido->next && rapido->next->next) {
        rapido = rapido->next->next;
        lento = lento->next;
    }

    No *segunda = lento->next;
    lento->next = NULL;

    if (segunda)
        segunda->prev = NULL;

    return segunda;
}

static No* merge(No *a, No *b, CriterioOrdenacao criterio) {
    if (!a) return b;
    if (!b) return a;

    if (comparar(a->dado, b->dado, criterio)) {
        a->next = merge(a->next, b, criterio);
        if (a->next)
            a->next->prev = a;
        a->prev = NULL;
        return a;
    } else {
        b->next = merge(a, b->next, criterio);
        if (b->next)
            b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}

static No* merge_sort_rec(No *head, CriterioOrdenacao criterio) {
    if (!head || !head->next)
        return head;

    No *segunda = dividir_lista(head);

    head = merge_sort_rec(head, criterio);
    segunda = merge_sort_rec(segunda, criterio);

    return merge(head, segunda, criterio);
}

/* MERGE SORT – Interface pública */
void merge_sort(No **head, CriterioOrdenacao criterio) {
    if (!head || !*head)
        return;

    *head = merge_sort_rec(*head, criterio);
}