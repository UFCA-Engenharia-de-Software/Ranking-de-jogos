#include "insertion_sort_estatico.h"

void insertionSortEstatica(Lista *lista)
{
    if (lista == NULL || lista->inicio == INVALIDO) {
        return;
    }

    int primeiro = lista->inicio;
    if (lista->vetor[primeiro].proximo == INVALIDO) {
        return;
    }

    int atual = lista->vetor[primeiro].proximo;

    while (atual != INVALIDO) {
        Jogador chave = lista->vetor[atual].jogador;
        int posicao_insercao = atual;
        int anterior = lista->vetor[atual].anterior;

        while (anterior != INVALIDO &&
               lista->vetor[anterior].jogador.pontuacao < chave.pontuacao) {
            int destino = lista->vetor[anterior].proximo;
            lista->vetor[destino].jogador = lista->vetor[anterior].jogador;

            posicao_insercao = anterior;
            anterior = lista->vetor[anterior].anterior;
        }

        lista->vetor[posicao_insercao].jogador = chave;
        atual = lista->vetor[atual].proximo;
    }
}
