/*
Arquivo: ordenacoes.h
Descrição:
Declara os algoritmos clássicos de ordenação utilizados no trabalho,
como Bubble Sort, Insertion Sort, Selection Sort, Quick Sort e Merge
Sort.

Os algoritmos permitem a ordenação dos jogadores segundo diferentes
critérios, como pontuação, nível e tempo jogado.
*/
#ifndef ORDENACOES_H
#define ORDENACOES_H

#include "lista_encadeada_dinamica.h"
#include "lista_encadeada_estatica.h"

// QuickSort para lista dinâmica
void quickSortListaDupla(No* low, No* high);

// QuickSort para lista estática
void quickSortListaEstatica(int arr[], int low, int high);

#endif
