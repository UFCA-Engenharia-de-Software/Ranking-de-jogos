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
void ordenacaoPorSelecaoListaDuplamenteEncadeada(DoublyNode **cabeca)
{
    if (*cabeca == NULL || (*cabeca)->next == NULL)
        return;

    for (DoublyNode *atual = *cabeca; atual != NULL; atual = atual->next)
    {
        DoublyNode *maior = atual;

        /* Busca o maior elemento restante */
        for (DoublyNode *varredura = atual->next;
             varredura != NULL;
             varredura = varredura->next)
        {
            if (varredura->data.pontuacao > maior->data.pontuacao)
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