#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "../../lista_encadeada_estatica.h"
#include "../sorting_utils.h"
#include "selection_sort_estatico.h"

int main() {
    SetConsoleOutputCP(65001);
    Lista minha_lista;
    
    initLista(&minha_lista); 

    Jogador j1 = {"Alice", 1500, 10, 50.5};
    Jogador j2 = {"Bob", 2000, 12, 60.0};
    Jogador j3 = {"Charlie", 1500, 15, 45.0};
    Jogador j4 = {"Diana", 3000, 20, 100.0};

    insert(&minha_lista, j1);
    insert(&minha_lista, j2);
    insert(&minha_lista, j3);
    insert(&minha_lista, j4);

    printf("--- LISTA ANTES DA ORDENACAO ---\n");
    print(&minha_lista); 

    printf("\n--- ORDENANDO POR PONTUACAO ---\n");
    selection_sort_estatico(&minha_lista, ORDENAR_PONTUACAO);
    print(&minha_lista);

    printf("\n--- ORDENANDO POR CRITERIO COMBINADO ---\n");
    selection_sort_estatico(&minha_lista, ORDENAR_COMBINADO);
    print(&minha_lista);

    return 0;
}