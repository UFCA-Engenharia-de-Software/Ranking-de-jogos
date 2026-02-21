#include "merge_sort_lista_estatica.h"

static int obterMeio(Lista *lista, int inicio)
{
    if (inicio == INVALIDO)
        return INVALIDO;

    int lento = inicio;
    int rapido = inicio;

    while (rapido != INVALIDO &&
           lista->vetor[rapido].proximo != INVALIDO &&
           lista->vetor[lista->vetor[rapido].proximo].proximo != INVALIDO)
    {
        lento = lista->vetor[lento].proximo;
        rapido = lista->vetor[lista->vetor[rapido].proximo].proximo;
    }

    return lento;
}

static int mesclar(Lista *lista, int esquerda, int direita,
                   CriterioOrdenacao criterio)
{
    if (esquerda == INVALIDO)
        return direita;
    if (direita == INVALIDO)
        return esquerda;

    if (comparar(lista->vetor[esquerda].jogador,
                 lista->vetor[direita].jogador,
                 criterio))
    {
        int prox = lista->vetor[esquerda].proximo;
        lista->vetor[esquerda].proximo = mesclar(lista, prox, direita, criterio);

        if (lista->vetor[lista->vetor[esquerda].proximo].proximo != INVALIDO)
            lista->vetor[lista->vetor[esquerda].proximo].anterior = esquerda;

        lista->vetor[esquerda].anterior = INVALIDO;
        return esquerda;
    }
    else
    {
        int prox = lista->vetor[direita].proximo;
        lista->vetor[direita].proximo = mesclar(lista, esquerda, prox, criterio);

        if (lista->vetor[lista->vetor[direita].proximo].proximo != INVALIDO)
            lista->vetor[lista->vetor[direita].proximo].anterior = direita;

        lista->vetor[direita].anterior = INVALIDO;
        return direita;
    }
}

static int mergeRecursivo(Lista *lista, int cabeca, CriterioOrdenacao criterio)
{
    if (cabeca == INVALIDO ||
        lista->vetor[cabeca].proximo == INVALIDO)
        return cabeca;

    int meio = obterMeio(lista, cabeca);
    int segunda = lista->vetor[meio].proximo;

    lista->vetor[meio].proximo = INVALIDO;

    if (segunda != INVALIDO)
        lista->vetor[segunda].anterior = INVALIDO;

    int esquerda = mergeRecursivo(lista, cabeca, criterio);
    int direita = mergeRecursivo(lista, segunda, criterio);

    return mesclar(lista, esquerda, direita, criterio);
}

void mergeSortListaEstatica(Lista *lista, CriterioOrdenacao criterio)
{
    if (lista == NULL || lista->inicio == INVALIDO)
        return;

    lista->inicio = mergeRecursivo(lista, lista->inicio, criterio);
}
