#include <stdio.h>
#include "quick_sort_static_list.h"

int main() {
    StaticList list;
    list.size = 5;

    // Exemplo de jogadores fictícios
    list.data[0].pontuacao = 10;
    list.data[1].pontuacao = 30;
    list.data[2].pontuacao = 20;
    list.data[3].pontuacao = 50;
    list.data[4].pontuacao = 40;

    quickSortStaticList(&list, 0, list.size - 1);

    printf("Lista ordenada (decrescente por pontuação):\n");
    for (int i = 0; i < list.size; i++) {
        printf("%d ", list.data[i].pontuacao);
    }
    printf("\n");

    return 0;
}
