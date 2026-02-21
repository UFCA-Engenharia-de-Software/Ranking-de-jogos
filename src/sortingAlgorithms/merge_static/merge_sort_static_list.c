#include <stdlib.h>
#include "merge_sort_static_list.h"

/*
 * Divide a lista em duas metades usando técnica
 * de ponteiro lento e rápido (baseado em índices).
 */
static int getMiddle(Lista *lista, int inicio)
{
    if (inicio == INVALIDO)
        return INVALIDO;

    int lento = inicio;
    int rapido = inicio;

    while (rapido != INVALIDO &&
           lista->vetor[rapido].proximo != INVALIDO &&
           lista->vetor[lista->vetor[rapido].proximo].proximo != INVALIDO)
    {
        lento = lista->vetor[lento].proximo;
        rapido = lista->vetor[lista->vetor[rapido].proximo].proximo;
    }

    return lento;
}

/*
 * Mescla duas sublistas ordenadas (por índice).
 * Retorna o novo início da lista mesclada.
 */
static int merge(Lista *lista, int left, int right)
{
    if (left == INVALIDO)
        return right;
    if (right == INVALIDO)
        return left;

    if (lista->vetor[left].jogador.pontuacao >=
        lista->vetor[right].jogador.pontuacao)
    {
        int next = lista->vetor[left].proximo;
        lista->vetor[left].proximo = merge(lista, next, right);

        if (lista->vetor[left].proximo != INVALIDO)
            lista->vetor[lista->vetor[left].proximo].anterior = left;

        lista->vetor[left].anterior = INVALIDO;
        return left;
    }
    else
    {
        int next = lista->vetor[right].proximo;
        lista->vetor[right].proximo = merge(lista, left, next);

        if (lista->vetor[right].proximo != INVALIDO)
            lista->vetor[lista->vetor[right].proximo].anterior = right;

        lista->vetor[right].anterior = INVALIDO;
        return right;
    }
}

/*
 * Função recursiva principal do Merge Sort.
 * Trabalha com índices.
 */
static int mergeSort(Lista *lista, int head)
{
    if (head == INVALIDO ||
        lista->vetor[head].proximo == INVALIDO)
    {
        return head;
    }

    int middle = getMiddle(lista, head);
    int secondHalf = lista->vetor[middle].proximo;

    lista->vetor[middle].proximo = INVALIDO;
    if (secondHalf != INVALIDO)
        lista->vetor[secondHalf].anterior = INVALIDO;

    int left = mergeSort(lista, head);
    int right = mergeSort(lista, secondHalf);

    return merge(lista, left, right);
}

/*
 * Interface pública.
 */
void mergeSortStaticList(Lista *lista)
{
    if (lista == NULL || lista->inicio == INVALIDO)
        return;

    lista->inicio = mergeSort(lista, lista->inicio);
}