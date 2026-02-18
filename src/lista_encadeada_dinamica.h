/*
Arquivo: lista_encadeada_dinamica.h
Descrição:
Define a estrutura da lista encadeada dinâmica e declara as funções
responsáveis por sua manipulação, incluindo inserção, remoção,
busca, impressão e liberação de memória.

A lista encadeada dinâmica utiliza alocação dinâmica de memória,
permitindo crescimento flexível conforme a quantidade de jogadores.
*/
#ifndef LISTA_ENCADEADA_DINAMICA_H
#define LISTA_ENCADEADA_DINAMICA_H

typedef struct No {
    int chave;              // campo usado para ordenação
    struct No* prev;
    struct No* next;
} No;

#endif
