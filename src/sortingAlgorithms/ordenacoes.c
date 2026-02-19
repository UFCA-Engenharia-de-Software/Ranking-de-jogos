
/*
Arquivo: ordenacoes.c
Descrição:
Implementa os algoritmos de ordenação declarados em ordenacoes.h.
Cada algoritmo é aplicado sobre as estruturas de dados utilizadas
no sistema.

Os algoritmos são avaliados por meio de análises teóricas e
experimentos práticos, considerando diferentes volumes de dados e
tipos de entrada.
*/

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
void insertion_sort_dinamico(No **head, CriterioOrdenacao criterio) {
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

/* Merge Sort – Lista Estática (Funções auxiliares) */

/* Função auxiliar para mesclar dois subvetores */
static void merge_estatico(Jogador v[], int inicio, int meio, int fim,
                           CriterioOrdenacao criterio) {

    int i = inicio;
    int j = meio + 1;
    int k = 0;

    Jogador temp[fim - inicio + 1];

    while (i <= meio && j <= fim) {
        if (comparar(v[i], v[j], criterio))
            temp[k++] = v[i++];
        else
            temp[k++] = v[j++];
    }

    while (i <= meio)
        temp[k++] = v[i++];

    while (j <= fim)
        temp[k++] = v[j++];

    for (i = inicio, k = 0; i <= fim; i++, k++)
        v[i] = temp[k];
}

/* Função recursiva do Merge Sort */
static void merge_sort_estatico_rec(Jogador v[], int inicio, int fim,
                                    CriterioOrdenacao criterio) {

    if (inicio >= fim)
        return;

    int meio = (inicio + fim) / 2;

    merge_sort_estatico_rec(v, inicio, meio, criterio);
    merge_sort_estatico_rec(v, meio + 1, fim, criterio);
    merge_estatico(v, inicio, meio, fim, criterio);
}

/* MERGE SORT – Interface pública (Lista Estática) */
void merge_sort_estatico(Jogador v[], int tamanho,
                         CriterioOrdenacao criterio) {

    if (!v || tamanho <= 1)
        return;

    merge_sort_estatico_rec(v, 0, tamanho - 1, criterio);
}

// Insertion sort estático 

void insertion_sort_estatico(Lista *lista) {
    if (lista->inicio == -1 || lista->vetor[lista->inicio].proximo == -1)
        return;

    int ordenado = lista->inicio;
    int atual = lista->vetor[ordenado].proximo;

    lista->vetor[ordenado].proximo = -1;
    lista->vetor[ordenado].anterior = -1;

    while (atual != -1) {
        int proximoAtual = lista->vetor[atual].proximo;

        // desconecta o nó atual
        lista->vetor[atual].proximo = -1;
        lista->vetor[atual].anterior = -1;

        int proximo = ordenado;
        int anterior = -1;

        while (proximo != -1 &&
               lista->vetor[proximo].valor < lista->vetor[atual].valor) {
            anterior = proximo;
            proximo = lista->vetor[proximo].proximo;
        }

        // inserção no início
        if (anterior == -1) {
            lista->vetor[atual].proximo = ordenado;
            lista->vetor[ordenado].anterior = atual;
            ordenado = atual;
        }
        // inserção no meio ou fim
        else {
            lista->vetor[atual].proximo = proximo;
            lista->vetor[atual].anterior = anterior;
            lista->vetor[anterior].proximo = atual;

            if (proximo != -1)
                lista->vetor[proximo].anterior = atual;
        }

        atual = proximoAtual;
    }

    lista->inicio = ordenado;
}
