#include "bubble_sort_estatica.h"

void bubbleSortEstatica(Lista *lista, CriterioOrdenacao criterio) {
    if (lista == NULL || lista->inicio == INVALIDO) {
        return;
    }

    int trocou;

    do {
        trocou = 0;
        int atual = lista->inicio;

        while (lista->vetor[atual].proximo != INVALIDO) {
            int prox = lista->vetor[atual].proximo;
            if (comparar(lista->vetor[prox].jogador, lista->vetor[atual].jogador, criterio)) {
                Jogador temp = lista->vetor[atual].jogador;
                lista->vetor[atual].jogador = lista->vetor[prox].jogador;
                lista->vetor[prox].jogador = temp;

                trocou = 1;
            }

            atual = lista->vetor[atual].proximo;
        }

    } while (trocou == 1);
}
