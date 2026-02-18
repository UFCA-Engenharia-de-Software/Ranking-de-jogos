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
#include "ordenacoes.h"
#include <stddef.h>
#include <stdlib.h>

// ===== QUICK SORT LISTA DINÂMICA =====
static void trocarInt(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static No* partition(No* low, No* high) {
    int pivot = high->chave; // ⚠️ use o campo correto (ex: pontuacao)
    No* i = low->prev;

    for (No* j = low; j != high; j = j->next) {
        if (j->chave <= pivot) {
            i = (i == NULL) ? low : i->next;
            trocarInt(&(i->chave), &(j->chave));
        }
    }
    i = (i == NULL) ? low : i->next;
    trocarInt(&(i->chave), &(high->chave));
    return i;
}

void quickSortListaDupla(No* low, No* high) {
    if (high != NULL && low != high && low != high->next) {
        No* p = partition(low, high);
        quickSortListaDupla(low, p->prev);
        quickSortListaDupla(p->next, high);
    }
}

// ===== QUICK SORT LISTA ESTÁTICA =====
static int partitionEstatica(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            trocarInt(&arr[i], &arr[j]);
        }
    }
    trocarInt(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortListaEstatica(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionEstatica(arr, low, high);
        quickSortListaEstatica(arr, low, pi - 1);
        quickSortListaEstatica(arr, pi + 1, high);
    }
}
