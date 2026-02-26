#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "../lista_encadeada_dinamica.h"
#include "../lista_encadeada_estatica.h"

#include "../sortingAlgorithms/bubble_doubly/bubble_sort_dinamico.h"
#include "../sortingAlgorithms/bubble_sort_estatico/bubble_sort_estatica.h"
#include "../sortingAlgorithms/insertion_sort_dinamico/insertion_sort_dinamica.h"
#include "../sortingAlgorithms/insertion_sort_estatico/insertion_sort_estatico.h"
#include "../sortingAlgorithms/merge_doubly/merge_sort_doubly_linked_list.h"
#include "../sortingAlgorithms/merge_estatica/merge_sort_lista_estatica.h"
#include "../sortingAlgorithms/quick_doubly/quick_sort_lista_dupla.h"
#include "../sortingAlgorithms/quick_static/quick_sort_lista_estatica.h"
#include "../sortingAlgorithms/selection_estatico/selection_sort_estatico.h"
#include "../sortingAlgorithms/selection_sort_duplamente_encadeada/selection_sort_lista_duplamente_encadeada.h"

#include "../jogador.h"
#include "../sortingAlgorithms/sorting_utils.h"
#include "../utilitarios/gerador_jogadores.h"

/*CRONÔMETRO PARA ALGORITMOS DE ORDENAÇÃO NA LISTA ESTÁTICA*/

double medir_tempo_bubble_estatico(int quantidade, int tipo_ordem){
    Lista lista;

    iniciarLista(&lista);
    gerarJogadores(&lista, quantidade, tipo_ordem);

    clock_t inicio, fim;

    inicio = clock();

    bubbleSortEstatica(&lista, ORDENAR_PONTUACAO);

    fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_insertion_estatico(int quantidade, int tipo_ordem) {
    Lista lista;

    iniciarLista(&lista);
    gerarJogadores(&lista, quantidade, tipo_ordem);

    clock_t inicio, fim;

    inicio = clock();

    insertionSortEstatica(&lista, ORDENAR_PONTUACAO);

    fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_merge_estatico(int quantidade, int tipo_ordem){
    Lista lista;

    iniciarLista(&lista);
    gerarJogadores(&lista, quantidade, tipo_ordem);

    clock_t inicio, fim;

    inicio = clock();

    mergeSortListaEstatica(&lista, quantidade);

    fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_quick_estatico(int quantidade, int tipo_ordem){
    Lista lista;

    iniciarLista(&lista);
    gerarJogadores(&lista, quantidade, tipo_ordem);

    clock_t inicio, fim;

    inicio = clock();

    quick_sort_estatico(&lista, ORDENAR_PONTUACAO);

    fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_selection_estatico(int quantidade, int tipo_ordem) {
    Lista lista;

    iniciarLista(&lista);
    gerarJogadores(&lista, quantidade, tipo_ordem);

    clock_t inicio, fim;

    inicio = clock();

    selection_sort_estatico(&lista, ORDENAR_PONTUACAO);

    fim = clock();
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

/*CRONÔMETRO PARA ALGORITMOS DE ORDENAÇÃO NA LISTA DINÂMICA*/

double medir_tempo_bubble_dinamico(int quantidade, int tipo_ordem) {
    NoDuplo *head = NULL; 
    gerarJogadoresDinamica(&head, quantidade, tipo_ordem);

    clock_t inicio, fim;
    
    inicio = clock();
    
    bubble_sort_dinamico(&head, ORDENAR_PONTUACAO); 
    
    fim = clock();

    liberar_lista(&head); 
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_insertion_dinamico(int quantidade, int tipo_ordem) {
    NoDuplo *head = NULL;
    gerarJogadoresDinamica(&head, quantidade, tipo_ordem);

    clock_t inicio, fim;

    inicio = clock();

    insertionSortListaDinamica(&head, ORDENAR_PONTUACAO);

    fim = clock();

    liberar_lista(&head);
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_merge_dinamico(int quantidade, int tipo_ordem) {
    NoDuplo *head = NULL;
    gerarJogadoresDinamica(&head, quantidade, tipo_ordem);

    clock_t inicio, fim;

    inicio = clock();

    mergeSortListaDupla(&head, ORDENAR_PONTUACAO);

    fim = clock();

    liberar_lista(&head);
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_quick_dinamico(int quantidade, int tipo_ordem) {
    NoDuplo *head = NULL;
    gerarJogadoresDinamica(&head, quantidade, tipo_ordem);

    clock_t inicio, fim;

    inicio = clock();

    quickSortDoublyLinkedList(&head, ORDENAR_PONTUACAO);

    fim = clock();

    liberar_lista(&head);
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

double medir_tempo_selection_dinamico(int quantidade, int tipo_ordem) {
    NoDuplo *head = NULL;
    gerarJogadoresDinamica(&head, quantidade, tipo_ordem);

    clock_t inicio, fim;

    inicio = clock();

    ordenacaoPorSelecaoListaDuplamenteEncadeada(&head, ORDENAR_PONTUACAO);

    fim = clock();

    liberar_lista(&head);
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC;
}

int main() {
    // Os tamanhos exigidos para o teste
    int tamanhos[] = {100, 1000, 10000};
    int num_tamanhos = 3;

    printf("========================================================\n");
    printf("     BENCHMARK DE ALGORITMOS DE ORDENACAO (TASK 15)     \n");
    printf("========================================================\n");

    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i];
        printf("\n\n>>> TESTANDO COM N = %d ELEMENTOS <<<\n", n);
        printf("--------------------------------------------------------\n");

        // --- BUBBLE SORT ---
        printf("[BUBBLE SORT]\n");
        printf("Lista Estatica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n", 
            medir_tempo_bubble_estatico(n, ALEATORIA),
            medir_tempo_bubble_estatico(n, ORDENADA),
            medir_tempo_bubble_estatico(n, INVERSAMENTE_ORDENADA));
            
        printf("Lista Dinamica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n", 
            medir_tempo_bubble_dinamico(n, ALEATORIA),
            medir_tempo_bubble_dinamico(n, ORDENADA),
            medir_tempo_bubble_dinamico(n, INVERSAMENTE_ORDENADA));
        printf("--------------------------------------------------------\n");

         // --- INSERTION SORT ---
        printf("[INSERTION SORT]\n");
        printf("Lista Estatica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n", 
            medir_tempo_insertion_estatico(n, ALEATORIA),
            medir_tempo_insertion_estatico(n, ORDENADA),
            medir_tempo_insertion_estatico(n, INVERSAMENTE_ORDENADA));
            
        printf("Lista Dinamica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n", 
            medir_tempo_insertion_dinamico(n, ALEATORIA),
            medir_tempo_insertion_dinamico(n, ORDENADA),
            medir_tempo_insertion_dinamico(n, INVERSAMENTE_ORDENADA));
        printf("--------------------------------------------------------\n");

         // --- MERGE SORT ---
        printf("[MERGE SORT]\n");
        printf("Lista Estatica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n", 
            medir_tempo_merge_estatico(n, ALEATORIA),
            medir_tempo_merge_estatico(n, ORDENADA),
            medir_tempo_merge_estatico(n, INVERSAMENTE_ORDENADA));
            
        printf("Lista Dinamica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n", 
            medir_tempo_merge_dinamico(n, ALEATORIA),
            medir_tempo_merge_dinamico(n, ORDENADA),
            medir_tempo_merge_dinamico(n, INVERSAMENTE_ORDENADA));
        printf("--------------------------------------------------------\n");

         // --- QUICK SORT ---
        printf("[QUICK SORT]\n");
        printf("Lista Estatica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n", 
            medir_tempo_quick_estatico(n, ALEATORIA),
            medir_tempo_quick_estatico(n, ORDENADA),
            medir_tempo_quick_estatico(n, INVERSAMENTE_ORDENADA));
            
        printf("Lista Dinamica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n", 
            medir_tempo_quick_dinamico(n, ALEATORIA),
            medir_tempo_quick_dinamico(n, ORDENADA),
            medir_tempo_quick_dinamico(n, INVERSAMENTE_ORDENADA));
        printf("--------------------------------------------------------\n");


        // --- SELECTION SORT ---
        printf("[SELECTION SORT]\n");
        printf("Lista Estatica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n", 
            medir_tempo_selection_estatico(n, ALEATORIA),
            medir_tempo_selection_estatico(n, ORDENADA),
            medir_tempo_selection_estatico(n, INVERSAMENTE_ORDENADA));
            
        printf("Lista Dinamica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n", 
            medir_tempo_selection_dinamico(n, ALEATORIA),
            medir_tempo_selection_dinamico(n, ORDENADA),
            medir_tempo_selection_dinamico(n, INVERSAMENTE_ORDENADA));
        printf("--------------------------------------------------------\n");
        
    }

    printf("\nBenchmark concluido com sucesso!\n");
    return 0;
}