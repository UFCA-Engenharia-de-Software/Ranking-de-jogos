/*
Arquivo: selection_sort_lista_dinamica.h
Descrição:
Declara a função de Selection Sort para lista duplamente
encadeada dinâmica (NoDuplo). A ordenação é feita de
forma decrescente pela pontuação do jogador.

Complexidade e implementacao:
- Implementacao: iterativa, busca o maior no sufixo e troca dados.
- Melhor caso: O(n^2)
- Caso medio: O(n^2)
- Pior caso:   O(n^2)
- Espaco extra: O(1)
*/

#ifndef SELECTION_SORT_LISTA_DUPLAMENTE_ENCADEADA_H
#define SELECTION_SORT_LISTA_DUPLAMENTE_ENCADEADA_H

#include "../../estruturas/dinamica/lista_encadeada_dinamica.h"
#include "../../utilitarios/utilitarios_ordenacao.h"

void ordenacaoPorSelecaoListaDinamica(NoDuplo **cabeca,
                                                 CriterioOrdenacao criterio);

#endif
