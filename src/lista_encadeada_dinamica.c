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

void insert(DoublyNode **head, Jogador jogador)
{
    DoublyNode *new = malloc(sizeof(DoublyNode));
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

    for (DoublyNode *ptr = *head; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->next == NULL)
        {
            ptr->next = new;
            new->prev = ptr;
            break;
        }
    }
}

DoublyNode *init(int length)
{
    DoublyNode *head = NULL;
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

        insert(&head, jogador);
    }
    return head;
}

void delete(DoublyNode **head, int idx)
{
    int count = 0;
    for (DoublyNode *ptr = *head; ptr != NULL; ptr = ptr->next)
    {
        if (count == idx)
        {
            DoublyNode *prev = ptr->prev;
            DoublyNode *next = ptr->next;

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

DoublyNode *search(DoublyNode **head, const char *nickname)
{
    for (DoublyNode *ptr = *head; ptr != NULL; ptr = ptr->next)
    {
        if (strcmp(ptr->data.nickname, nickname) == 0)
            return ptr;
    }
    return NULL;
}

void print(DoublyNode **head)
{
    for (DoublyNode *ptr = *head; ptr != NULL; ptr = ptr->next)
    {
        printf("Nickname: %s | Pontuação: %d | Nível: %d | Tempo jogado: %.2f\n",
               ptr->data.nickname, ptr->data.pontuacao,
               ptr->data.nivel, ptr->data.tempo_jogado);
    }
    printf("\n");
}

void free_list(DoublyNode **head)
{
    DoublyNode *ptr = *head;
    while (ptr != NULL)
    {
        DoublyNode *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    *head = NULL;
}

DoublyNode *getMiddler(DoublyNode **head)
{
    DoublyNode *slow = *head;

    for (DoublyNode *fast = (*head)->next;
         fast != NULL && fast->next != NULL;
         fast = (fast->next)->next)
    {
        slow = slow->next;
    }
    return slow;
}

int DoublyLinkedListLength(DoublyNode **head)
{
    int count = 0;

    DoublyNode *ptr = *head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}
