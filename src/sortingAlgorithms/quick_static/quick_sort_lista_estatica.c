#include "quick_sort_lista_estatica.h"

/* Troca os dados de dois nós da lista estática. */
static void swapJogadores(Lista *lista, int indiceA, int indiceB)
{
    if (indiceA == indiceB)
        return;

    Jogador temp = lista->vetor[indiceA].jogador;
    lista->vetor[indiceA].jogador = lista->vetor[indiceB].jogador;
    lista->vetor[indiceB].jogador = temp;
}

/* Particiona os índices dos nós em torno de um pivô. */
static int partition(Lista *lista, int indices[], int low, int high,
                     CriterioOrdenacao criterio)
{
    Jogador pivot = lista->vetor[indices[high]].jogador;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (comparar(lista->vetor[indices[j]].jogador, pivot, criterio))
        {
            i++;
            swapJogadores(lista, indices[i], indices[j]);
        }
    }
    swapJogadores(lista, indices[i + 1], indices[high]);
    return i + 1;
}

/* Função recursiva do Quick Sort por posições da lista encadeada estática. */
static void quick_sort_rec(Lista *lista, int indices[], int low, int high,
                           CriterioOrdenacao criterio)
{
    if (low < high)
    {
        int pi = partition(lista, indices, low, high, criterio);
        quick_sort_rec(lista, indices, low, pi - 1, criterio);
        quick_sort_rec(lista, indices, pi + 1, high, criterio);
    }
}

/* Interface pública */
void quick_sort_estatico(Lista *lista, CriterioOrdenacao criterio)
{
    if (lista == NULL || lista->inicio == INVALIDO)
        return;

    int indices[MAX];
    int tamanho = 0;
    int atual = lista->inicio;

    while (atual != INVALIDO && tamanho < MAX)
    {
        indices[tamanho++] = atual;
        atual = lista->vetor[atual].proximo;
    }

    if (tamanho <= 1)
        return;

    quick_sort_rec(lista, indices, 0, tamanho - 1, criterio);
}
