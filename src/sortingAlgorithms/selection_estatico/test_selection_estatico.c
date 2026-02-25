#include <stdio.h>
#include <stdlib.h>

#include "../../lista_encadeada_estatica.h"
#include "../sorting_utils.h"
#include "selection_sort_estatico.h"

int main() {
    Lista minha_lista;
    
    iniciarLista(&minha_lista); 

    Jogador j1 = {"Alice", 1500, 10, 50.5};
    Jogador j2 = {"Bob", 2000, 12, 60.0};
    Jogador j3 = {"Charlie", 1500, 15, 45.0};
    Jogador j4 = {"Diana", 3000, 20, 100.0};

    inserir(&minha_lista, j1);
    inserir(&minha_lista, j2);
    inserir(&minha_lista, j3);
    inserir(&minha_lista, j4);

    printf("--- LISTA ANTES DA ORDENACAO ---\n");
    imprimir(&minha_lista); 

    printf("\n--- ORDENANDO POR PONTUACAO ---\n");
    selection_sort_estatico(&minha_lista, ORDENAR_PONTUACAO);
    imprimir(&minha_lista);

    printf("\n--- ORDENANDO POR CRITERIO COMBINADO ---\n");
    selection_sort_estatico(&minha_lista, ORDENAR_COMBINADO);
    imprimir(&minha_lista);

    return 0;
}