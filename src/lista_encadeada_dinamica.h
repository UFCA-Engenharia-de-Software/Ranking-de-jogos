/*
Arquivo: lista_encadeada_dinamica.h
Descrição:
Define a estrutura da lista encadeada dinâmica e declara as funções
responsáveis por sua manipulação, incluindo inserção, remoção,
busca, impressão e liberação de memória.

A lista encadeada dinâmica utiliza alocação dinâmica de memória,
permitindo crescimento flexível conforme a quantidade de jogadores.
*/

#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"

typedef struct No{
    Jogador dado;
    struct No* anterior;
    struct No* proximo;
}No;

typedef struct{
    No* inicio;
    No* fim;
}Lista;
