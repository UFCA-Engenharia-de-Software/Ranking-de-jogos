#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../../lista_encadeada_dinamica.h"
#include "../sorting_utils.h"
#include "bubble_sort_doubly.h"

int main() {

    SetConsoleOutputCP(65001);
    DoublyNode *head = NULL;

    // Criando jogadores com dados desordenados para garantir cenários abrangentes.
    Jogador j1 = {"Alice", 1500, 10, 50.5};
    Jogador j2 = {"Bob", 2000, 12, 60.0};
    Jogador j3 = {"Charlie", 1500, 15, 45.0}; 
    Jogador j4 = {"Diana", 3000, 20, 100.0};
    Jogador j5 = {"Evan", 800, 5, 20.0};
    Jogador j6 = {"Fiona", 1500, 15, 30.0}; 

    insert(&head, j1);
    insert(&head, j2);
    insert(&head, j3);
    insert(&head, j4);
    insert(&head, j5);
    insert(&head, j6);

    printf("==================================================\n");
    printf("              ESTADO INICIAL DA LISTA             \n");
    printf("==================================================\n");
    print(&head);

    /* TESTE 1: Pontuação (Maior para o Menor) */
    printf("\n==================================================\n");
    printf("        TESTE 1: ORDENADO POR PONTUACAO           \n");
    printf("==================================================\n");
    // Diana(3000) deve ser a primeira, Evan(800) o último.
    bubble_sort_dinamico(&head, ORDENAR_PONTUACAO);
    print(&head);

    /* TESTE 2: Nível (Maior para o Menor) */
    printf("\n==================================================\n");
    printf("          TESTE 2: ORDENADO POR NIVEL             \n");
    printf("==================================================\n");
    // Diana(20) continua em primeiro, mas agora Charlie e Fiona(15) sobem.
    bubble_sort_dinamico(&head, ORDENAR_NIVEL);
    print(&head);

    /* TESTE 3: Tempo Jogado (Menor para o Maior) */
    printf("\n==================================================\n");
    printf("          TESTE 3: ORDENADO POR TEMPO             \n");
    printf("==================================================\n");
    // Aqui a lógica inverte! Evan(20.0) e Fiona(30.0) devem ser os primeiros.
    bubble_sort_dinamico(&head, ORDENAR_TEMPO);
    print(&head);

    /* TESTE 4: Combinado (Pontos -> Nível -> Tempo) */
    printf("\n==================================================\n");
    printf("        TESTE 4: CRITERIO COMBINADO               \n");
    printf("==================================================\n");
    /* A ordem esperada aqui é:
       1. Diana (3000 pts)
       2. Bob (2000 pts)
       3. Fiona (1500 pts, Nivel 15, Tempo 30.0) -> Ganha do Charlie no tempo
       4. Charlie (1500 pts, Nivel 15, Tempo 45.0) -> Perde da Fiona no tempo, ganha da Alice no nível
       5. Alice (1500 pts, Nivel 10)
       6. Evan (800 pts)
    */
    bubble_sort_dinamico(&head, ORDENAR_COMBINADO);
    print(&head);

    // Limpeza
    free_list(&head);
    printf("\nMemoria liberada com sucesso. Fim dos testes.\n");

    return 0;
}