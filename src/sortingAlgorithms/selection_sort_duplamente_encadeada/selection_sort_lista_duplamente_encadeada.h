/*
Arquivo: selection_sort_lista_duplamente_encadeada.h
Descrição:
Declara a função de Selection Sort para lista duplamente
encadeada dinâmica (NoDuplo). A ordenação é feita de
forma decrescente pela pontuação do jogador.
*/

#ifndef SELECTION_SORT_LISTA_DUPLAMENTE_ENCADEADA_H
#define SELECTION_SORT_LISTA_DUPLAMENTE_ENCADEADA_H

#include "../../lista_encadeada_dinamica.h"
#include "../sorting_utils.h"

void ordenacaoPorSelecaoListaDuplamenteEncadeada(NoDuplo **cabeca,
                                                 CriterioOrdenacao criterio);

#endif
