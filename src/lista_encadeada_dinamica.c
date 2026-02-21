/*
Arquivo: lista_encadeada_dinamica.c
Descrição:
Implementa as funções declaradas em lista_encadeada_dinamica.h.
Utiliza uma lista duplamente encadeada dinâmica para armazenar
estruturas do tipo Jogador.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_encadeada_dinamica.h"

void inserir(NoDuplo **head, Jogador jogador)
{
    NoDuplo *new = malloc(sizeof(NoDuplo));
    if (new == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    new->next = NULL;
    new->data = jogador;

    if (*head == NULL)
    {
        new->prev = NULL;
        *head = new;
        return;
    }

    for (NoDuplo *ptr = *head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->next == NULL)
        {
            ptr->next = new;
            new->prev = ptr;
            break;
        }
    }
}

NoDuplo *inicializar(int length)
{
    NoDuplo *head = NULL;
    if (length == 0)
    {
        return head;
    }

    for (int i = 0; i < length; i++)
    {
        Jogador jogador;
        printf("Nickname: ");
        scanf("%49s", jogador.nickname);
        printf("Pontuação: ");
        scanf("%d", &jogador.pontuacao);
        printf("Nível: ");
        scanf("%d", &jogador.nivel);
        printf("Tempo jogado: ");
        scanf("%f", &jogador.tempo_jogado);

        inserir(&head, jogador);
    }
    return head;
}

void remover(NoDuplo **head, int idx)
{
    int count = 0;
    for (NoDuplo *ptr = *head; ptr != NULL; ptr = ptr->next)
    {
        if (count == idx)
        {
            NoDuplo *prev = ptr->prev;
            NoDuplo *next = ptr->next;

            if (prev != NULL)
                prev->next = next;
            else
                *head = next;

            if (next != NULL)
                next->prev = prev;

            free(ptr);
            return;
        }
        count++;
    }
    printf("Índice %d não encontrado.\n", idx);
}

NoDuplo *buscar(NoDuplo **head, const char *nickname)
{
    for (NoDuplo *ptr = *head; ptr != NULL; ptr = ptr->next)
    {
        if (strcmp(ptr->data.nickname, nickname) == 0)
            return ptr;
    }
    return NULL;
}

void imprimir(NoDuplo **head)
{
    for (NoDuplo *ptr = *head; ptr != NULL; ptr = ptr->next)
    {
        printf("Nickname: %s | Pontuação: %d | Nível: %d | Tempo jogado: %.2f\n",
               ptr->data.nickname, ptr->data.pontuacao,
               ptr->data.nivel, ptr->data.tempo_jogado);
    }
    printf("\n");
}

void liberar_lista(NoDuplo **head)
{
    NoDuplo *ptr = *head;
    while (ptr != NULL)
    {
        NoDuplo *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    *head = NULL;
}

NoDuplo *obterMeio(NoDuplo **head)
{
    NoDuplo *slow = *head;

    for (NoDuplo *fast = (*head)->next;
         fast != NULL && fast->next != NULL;
         fast = (fast->next)->next)
    {
        slow = slow->next;
    }
    return slow;
}

int tamanhoListaDupla(NoDuplo **head)
{
    int count = 0;

    NoDuplo *ptr = *head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
