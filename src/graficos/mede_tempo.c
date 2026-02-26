#define _POSIX_C_SOURCE 199309L

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

typedef long long int64;
typedef int64 (*medidor_t)(int quantidade, int tipo_ordem);

static int64 diff_ns(struct timespec inicio, struct timespec fim)
{
    return (int64)(fim.tv_sec - inicio.tv_sec) * 1000000000LL +
           (int64)(fim.tv_nsec - inicio.tv_nsec);
}

/*CRONOMETRO PARA ALGORITMOS DE ORDENACAO NA LISTA ESTATICA*/

int64 medir_tempo_bubble_estatico(int quantidade, int tipo_ordem){
    Lista lista;
    struct timespec inicio, fim;

    iniciarLista(&lista);
    gerarJogadores(&lista, quantidade, tipo_ordem);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    bubbleSortEstatica(&lista, ORDENAR_PONTUACAO);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    return diff_ns(inicio, fim);
}

int64 medir_tempo_insertion_estatico(int quantidade, int tipo_ordem) {
    Lista lista;
    struct timespec inicio, fim;

    iniciarLista(&lista);
    gerarJogadores(&lista, quantidade, tipo_ordem);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    insertionSortEstatica(&lista, ORDENAR_PONTUACAO);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    return diff_ns(inicio, fim);
}

int64 medir_tempo_merge_estatico(int quantidade, int tipo_ordem){
    Lista lista;
    struct timespec inicio, fim;

    iniciarLista(&lista);
    gerarJogadores(&lista, quantidade, tipo_ordem);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    mergeSortListaEstatica(&lista, ORDENAR_PONTUACAO);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    return diff_ns(inicio, fim);
}

int64 medir_tempo_quick_estatico(int quantidade, int tipo_ordem){
    Lista lista;
    struct timespec inicio, fim;

    iniciarLista(&lista);
    gerarJogadores(&lista, quantidade, tipo_ordem);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    quick_sort_estatico(&lista, ORDENAR_PONTUACAO);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    return diff_ns(inicio, fim);
}

int64 medir_tempo_selection_estatico(int quantidade, int tipo_ordem) {
    Lista lista;
    struct timespec inicio, fim;

    iniciarLista(&lista);
    gerarJogadores(&lista, quantidade, tipo_ordem);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    selection_sort_estatico(&lista, ORDENAR_PONTUACAO);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    return diff_ns(inicio, fim);
}

/*CRONOMETRO PARA ALGORITMOS DE ORDENACAO NA LISTA DINAMICA*/

int64 medir_tempo_bubble_dinamico(int quantidade, int tipo_ordem) {
    NoDuplo *head = NULL;
    struct timespec inicio, fim;

    gerarJogadoresDinamica(&head, quantidade, tipo_ordem);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    bubble_sort_dinamico(&head, ORDENAR_PONTUACAO);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    liberar_lista(&head);
    return diff_ns(inicio, fim);
}

int64 medir_tempo_insertion_dinamico(int quantidade, int tipo_ordem) {
    NoDuplo *head = NULL;
    struct timespec inicio, fim;

    gerarJogadoresDinamica(&head, quantidade, tipo_ordem);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    insertionSortListaDinamica(&head, ORDENAR_PONTUACAO);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    liberar_lista(&head);
    return diff_ns(inicio, fim);
}

int64 medir_tempo_merge_dinamico(int quantidade, int tipo_ordem) {
    NoDuplo *head = NULL;
    struct timespec inicio, fim;

    gerarJogadoresDinamica(&head, quantidade, tipo_ordem);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    mergeSortListaDupla(&head, ORDENAR_PONTUACAO);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    liberar_lista(&head);
    return diff_ns(inicio, fim);
}

int64 medir_tempo_quick_dinamico(int quantidade, int tipo_ordem) {
    NoDuplo *head = NULL;
    struct timespec inicio, fim;

    gerarJogadoresDinamica(&head, quantidade, tipo_ordem);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    quickSortDoublyLinkedList(&head, ORDENAR_PONTUACAO);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    liberar_lista(&head);
    return diff_ns(inicio, fim);
}

int64 medir_tempo_selection_dinamico(int quantidade, int tipo_ordem) {
    NoDuplo *head = NULL;
    struct timespec inicio, fim;

    gerarJogadoresDinamica(&head, quantidade, tipo_ordem);

    clock_gettime(CLOCK_MONOTONIC, &inicio);
    ordenacaoPorSelecaoListaDuplamenteEncadeada(&head, ORDENAR_PONTUACAO);
    clock_gettime(CLOCK_MONOTONIC, &fim);

    liberar_lista(&head);
    return diff_ns(inicio, fim);
}

static double executar_media(const char *estrutura,
                            const char *algoritmo,
                            medidor_t medidor,
                            int quantidade,
                            int tipo_ordem,
                            const char *tipo_nome,
                            int repeticoes,
                            FILE *csv_execucoes,
                            FILE *csv_medias)
{
    int i = 0;
    int64 soma_ns = 0;

    for (i = 1; i <= repeticoes; i++) {
        int64 tempo_ns = medidor(quantidade, tipo_ordem);
        soma_ns += tempo_ns;

        if (csv_execucoes != NULL) {
            fprintf(csv_execucoes,
                    "%s,%s,pontuacao,%d,%s,%d,%lld\n",
                    estrutura,
                    algoritmo,
                    quantidade,
                    tipo_nome,
                    i,
                    tempo_ns);
        }
    }

    {
        double media_ns = (double)soma_ns / repeticoes;

        if (csv_medias != NULL) {
            fprintf(csv_medias,
                    "%s,%s,pontuacao,%d,%s,%d,%.2f\n",
                    estrutura,
                    algoritmo,
                    quantidade,
                    tipo_nome,
                    repeticoes,
                    media_ns);
        }

        return media_ns / 1000000000.0;
    }
}

int main() {
    int tamanhos[] = {100, 1000, 10000};
    int num_tamanhos = 3;
    int repeticoes = 100;
    const char *nomes_entrada[] = {"aleatoria", "ordenada", "inversamente_ordenada"};

    FILE *csv_execucoes = fopen("resultados_execucoes.csv", "w");
    FILE *csv_medias = fopen("resultados_medias.csv", "w");

    const char *env_rep = getenv("BENCH_REPETICOES");
    if (env_rep != NULL) {
        int valor = atoi(env_rep);
        if (valor > 0) {
            repeticoes = valor;
        }
    }

    if (csv_execucoes == NULL || csv_medias == NULL) {
        fprintf(stderr, "Erro ao abrir arquivos de saida CSV.\n");
        if (csv_execucoes != NULL) fclose(csv_execucoes);
        if (csv_medias != NULL) fclose(csv_medias);
        return 1;
    }

    fprintf(csv_execucoes, "estrutura,algoritmo,criterio,n,tipo_entrada,execucao,tempo_ns\n");
    fprintf(csv_medias, "estrutura,algoritmo,criterio,n,tipo_entrada,repeticoes,media_ns\n");

    printf("========================================================\n");
    printf("     BENCHMARK DE ALGORITMOS DE ORDENACAO (TASK 15)     \n");
    printf("========================================================\n");
    printf("Repeticoes por cenario: %d\n", repeticoes);

    for (int i = 0; i < num_tamanhos; i++) {
        int n = tamanhos[i];
        printf("\n\n>>> TESTANDO COM N = %d ELEMENTOS <<<\n", n);
        printf("--------------------------------------------------------\n");

        printf("[BUBBLE SORT]\n");
        printf("Lista Estatica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n",
            executar_media("estatica", "bubble", medir_tempo_bubble_estatico, n, ALEATORIA, nomes_entrada[0], repeticoes, csv_execucoes, csv_medias),
            executar_media("estatica", "bubble", medir_tempo_bubble_estatico, n, ORDENADA, nomes_entrada[1], repeticoes, csv_execucoes, csv_medias),
            executar_media("estatica", "bubble", medir_tempo_bubble_estatico, n, INVERSAMENTE_ORDENADA, nomes_entrada[2], repeticoes, csv_execucoes, csv_medias));

        printf("Lista Dinamica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n",
            executar_media("dinamica", "bubble", medir_tempo_bubble_dinamico, n, ALEATORIA, nomes_entrada[0], repeticoes, csv_execucoes, csv_medias),
            executar_media("dinamica", "bubble", medir_tempo_bubble_dinamico, n, ORDENADA, nomes_entrada[1], repeticoes, csv_execucoes, csv_medias),
            executar_media("dinamica", "bubble", medir_tempo_bubble_dinamico, n, INVERSAMENTE_ORDENADA, nomes_entrada[2], repeticoes, csv_execucoes, csv_medias));
        printf("--------------------------------------------------------\n");

        printf("[INSERTION SORT]\n");
        printf("Lista Estatica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n",
            executar_media("estatica", "insertion", medir_tempo_insertion_estatico, n, ALEATORIA, nomes_entrada[0], repeticoes, csv_execucoes, csv_medias),
            executar_media("estatica", "insertion", medir_tempo_insertion_estatico, n, ORDENADA, nomes_entrada[1], repeticoes, csv_execucoes, csv_medias),
            executar_media("estatica", "insertion", medir_tempo_insertion_estatico, n, INVERSAMENTE_ORDENADA, nomes_entrada[2], repeticoes, csv_execucoes, csv_medias));

        printf("Lista Dinamica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n",
            executar_media("dinamica", "insertion", medir_tempo_insertion_dinamico, n, ALEATORIA, nomes_entrada[0], repeticoes, csv_execucoes, csv_medias),
            executar_media("dinamica", "insertion", medir_tempo_insertion_dinamico, n, ORDENADA, nomes_entrada[1], repeticoes, csv_execucoes, csv_medias),
            executar_media("dinamica", "insertion", medir_tempo_insertion_dinamico, n, INVERSAMENTE_ORDENADA, nomes_entrada[2], repeticoes, csv_execucoes, csv_medias));
        printf("--------------------------------------------------------\n");

        printf("[MERGE SORT]\n");
        printf("Lista Estatica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n",
            executar_media("estatica", "merge", medir_tempo_merge_estatico, n, ALEATORIA, nomes_entrada[0], repeticoes, csv_execucoes, csv_medias),
            executar_media("estatica", "merge", medir_tempo_merge_estatico, n, ORDENADA, nomes_entrada[1], repeticoes, csv_execucoes, csv_medias),
            executar_media("estatica", "merge", medir_tempo_merge_estatico, n, INVERSAMENTE_ORDENADA, nomes_entrada[2], repeticoes, csv_execucoes, csv_medias));

        printf("Lista Dinamica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n",
            executar_media("dinamica", "merge", medir_tempo_merge_dinamico, n, ALEATORIA, nomes_entrada[0], repeticoes, csv_execucoes, csv_medias),
            executar_media("dinamica", "merge", medir_tempo_merge_dinamico, n, ORDENADA, nomes_entrada[1], repeticoes, csv_execucoes, csv_medias),
            executar_media("dinamica", "merge", medir_tempo_merge_dinamico, n, INVERSAMENTE_ORDENADA, nomes_entrada[2], repeticoes, csv_execucoes, csv_medias));
        printf("--------------------------------------------------------\n");

        printf("[QUICK SORT]\n");
        printf("Lista Estatica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n",
            executar_media("estatica", "quick", medir_tempo_quick_estatico, n, ALEATORIA, nomes_entrada[0], repeticoes, csv_execucoes, csv_medias),
            executar_media("estatica", "quick", medir_tempo_quick_estatico, n, ORDENADA, nomes_entrada[1], repeticoes, csv_execucoes, csv_medias),
            executar_media("estatica", "quick", medir_tempo_quick_estatico, n, INVERSAMENTE_ORDENADA, nomes_entrada[2], repeticoes, csv_execucoes, csv_medias));

        printf("Lista Dinamica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n",
            executar_media("dinamica", "quick", medir_tempo_quick_dinamico, n, ALEATORIA, nomes_entrada[0], repeticoes, csv_execucoes, csv_medias),
            executar_media("dinamica", "quick", medir_tempo_quick_dinamico, n, ORDENADA, nomes_entrada[1], repeticoes, csv_execucoes, csv_medias),
            executar_media("dinamica", "quick", medir_tempo_quick_dinamico, n, INVERSAMENTE_ORDENADA, nomes_entrada[2], repeticoes, csv_execucoes, csv_medias));
        printf("--------------------------------------------------------\n");

        printf("[SELECTION SORT]\n");
        printf("Lista Estatica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n",
            executar_media("estatica", "selection", medir_tempo_selection_estatico, n, ALEATORIA, nomes_entrada[0], repeticoes, csv_execucoes, csv_medias),
            executar_media("estatica", "selection", medir_tempo_selection_estatico, n, ORDENADA, nomes_entrada[1], repeticoes, csv_execucoes, csv_medias),
            executar_media("estatica", "selection", medir_tempo_selection_estatico, n, INVERSAMENTE_ORDENADA, nomes_entrada[2], repeticoes, csv_execucoes, csv_medias));

        printf("Lista Dinamica  | Aleatorio: %.10f s | Ordenado: %.10f s | Inverso: %.10f s\n",
            executar_media("dinamica", "selection", medir_tempo_selection_dinamico, n, ALEATORIA, nomes_entrada[0], repeticoes, csv_execucoes, csv_medias),
            executar_media("dinamica", "selection", medir_tempo_selection_dinamico, n, ORDENADA, nomes_entrada[1], repeticoes, csv_execucoes, csv_medias),
            executar_media("dinamica", "selection", medir_tempo_selection_dinamico, n, INVERSAMENTE_ORDENADA, nomes_entrada[2], repeticoes, csv_execucoes, csv_medias));
        printf("--------------------------------------------------------\n");
    }

    fclose(csv_execucoes);
    fclose(csv_medias);

    printf("\nBenchmark concluido com sucesso!\n");
    printf("CSV gerados: resultados_execucoes.csv e resultados_medias.csv\n");
    return 0;
}
