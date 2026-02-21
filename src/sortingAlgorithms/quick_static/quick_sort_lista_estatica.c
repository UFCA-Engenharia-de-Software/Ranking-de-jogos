#include <stdlib.h>
#include "quick_sort_lista_estatica.h"

/* Particiona o vetor de jogadores em torno de um pivô */
static int partition(Jogador v[], int low, int high) {
    int pivot = v[high].pontuacao;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (v[j].pontuacao >= pivot) {
            i++;
            Jogador temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    Jogador temp = v[i + 1];
    v[i + 1] = v[high];
    v[high] = temp;
    return i + 1;
}

/* Função recursiva do Quick Sort */
static void quick_sort_rec(Jogador v[], int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quick_sort_rec(v, low, pi - 1);
        quick_sort_rec(v, pi + 1, high);
    }
}

/* Interface pública */
void quick_sort_estatico(Jogador v[], int tamanho) {
    if (!v || tamanho <= 1) return;
    quick_sort_rec(v, 0, tamanho - 1);
}
