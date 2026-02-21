#include "selection_sort_lista_duplamente_encadeada.h"

/*
 * ordenacaoPorSelecaoListaDuplamenteEncadeada(cabeca):
 *
 * Para cada posição da lista, encontra o nó com maior
 * pontuação no restante da lista e realiza a troca
 * dos dados entre os nós.
 *
 * Critério: pontuação decrescente.
 *
 * Observação:
 * Para simplificar e manter estabilidade estrutural,
 * apenas os dados (Jogador) são trocados,
 * não os ponteiros da lista.
 */
void ordenacaoPorSelecaoListaDuplamenteEncadeada(NoDuplo **cabeca,
                                                 CriterioOrdenacao criterio)
{
    if (cabeca == NULL)
        return;

    if (*cabeca == NULL || (*cabeca)->next == NULL)
        return;

    for (NoDuplo *atual = *cabeca; atual != NULL; atual = atual->next)
    {
        NoDuplo *maior = atual;

        /* Busca o maior elemento restante */
        for (NoDuplo *varredura = atual->next;
             varredura != NULL;
             varredura = varredura->next)
        {
            if (comparar(varredura->data, maior->data, criterio))
            {
                maior = varredura;
            }
        }

        /* Troca os dados */
        if (maior != atual)
        {
            Jogador temp = atual->data;
            atual->data = maior->data;
            maior->data = temp;
        }
    }
}
