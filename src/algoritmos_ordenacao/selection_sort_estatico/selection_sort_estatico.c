#include "selection_sort_estatico.h"
#include <stddef.h>

void selection_sort_estatico(Lista *lista, CriterioOrdenacao criterio){
    if (lista == NULL || lista->inicio == INVALIDO) {
        return;
    }

    int atual = lista -> inicio;

    while (atual != INVALIDO) {
        int melhor_idx = atual;
        int iterador = lista->vetor[atual].proximo;

        //Busca o melhor elemento no restante da lista.
        while (iterador != INVALIDO) {
            //Compara e avalia quem deve ser o primeiro.
            if (comparar(lista->vetor[iterador].jogador, lista->vetor[melhor_idx].jogador, criterio)){
                melhor_idx = iterador;
            }
            iterador = lista->vetor[iterador].proximo;
        }
        //Verifica quem deve ocupar a posição de melhor e troca, se necessário.
        if (melhor_idx != atual) {
            Jogador temporario = lista->vetor[atual].jogador;
            lista->vetor[atual].jogador = lista->vetor[melhor_idx].jogador;
            lista->vetor[melhor_idx].jogador = temporario;
        }
        atual = lista->vetor[atual].proximo;
    }
}