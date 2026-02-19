#include <stdlib.h>
#include "quick_sort_static_list.h"

/*
 * Particiona a lista estática em torno de um pivô.
 */
static int partition(StaticList *list, int low, int high) {
    int pivot = list->data[high].pontuacao;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (list->data[j].pontuacao >= pivot) {
            i++;
            Jogador temp = list->data[i];
            list->data[i] = list->data[j];
            list->data[j] = temp;
        }
    }
    Jogador temp = list->data[i + 1];
    list->data[i + 1] = list->data[high];
    list->data[high] = temp;
    return i + 1;
}

/*
 * Função recursiva para aplicar Quick Sort na lista estática.
 */
void quickSortStaticList(StaticList *list, int low, int high) {
    if (low < high) {
        int pi = partition(list, low, high);
        quickSortStaticList(list, low, pi - 1);
        quickSortStaticList(list, pi + 1, high);
    }
}
