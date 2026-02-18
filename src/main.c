/*
Arquivo: main.c
Descrição:
Arquivo principal do sistema de Ranking de Jogos Online.
Responsável por controlar a execução do programa, criar os dados de
teste, chamar as estruturas de dados e os algoritmos de ordenação,
bem como medir o tempo de execução dos algoritmos.

O programa simula um sistema de ranking de jogos online e permite
avaliar o desempenho de diferentes algoritmos de ordenação aplicados
a listas encadeadas dinâmica e estática, considerando diferentes
volumes de dados e tipos de entrada.
*/
#include "ordenacoes.h"

int main() {
    // Exemplo com lista estática
    ListaEstatica lista;
    lista.tamanho = 5;
    lista.elementos[0] = 42;
    lista.elementos[1] = 17;
    lista.elementos[2] = 8;
    lista.elementos[3] = 99;
    lista.elementos[4] = 23;

    quickSortListaEstatica(lista.elementos, 0, lista.tamanho - 1);

    for (int i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.elementos[i]);
    }

    return 0;
}

