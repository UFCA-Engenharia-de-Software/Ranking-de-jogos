#ifndef QUICK_SORT_STATIC_LIST_H
#define QUICK_SORT_STATIC_LIST_H

#include "jogador.h"

#define MAX_LIST_SIZE 100

typedef struct {
    Jogador data[MAX_LIST_SIZE];
    int size;
} StaticList;

void quickSortStaticList(StaticList *list, int low, int high);

#endif
