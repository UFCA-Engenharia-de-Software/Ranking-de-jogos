#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../../lista_encadeada_dinamica.h"
#include "../sorting_utils.h"
#include "bubble_sort_dinamico.h"

int main()
{

    SetConsoleOutputCP(65001);
    NoDuplo *inicio = NULL;

    // Criando jogadores com dados desordenados para garantir cenários abrangentes.
    Jogador j1 = {"Alice", 1500, 10, 50.5};
    Jogador j2 = {"Bob", 2000, 12, 60.0};
    Jogador j3 = {"Charlie", 1500, 15, 45.0};
    Jogador j4 = {"Diana", 3000, 20, 100.0};
    Jogador j5 = {"Evan", 800, 5, 20.0};
    Jogador j6 = {"Fiona", 1500, 15, 30.0};

    inserir(&inicio, j1);
    inserir(&inicio, j2);
    inserir(&inicio, j3);
    inserir(&inicio, j4);
    inserir(&inicio, j5);
    inserir(&inicio, j6);

    printf("==================================================\n");
    printf("              ESTADO INICIAL DA LISTA             \n");
    printf("==================================================\n");
    imprimir(&inicio);

    /* TESTE 1: Pontuação (Maior para o Menor) */
    printf("\n==================================================\n");
    printf("        TESTE 1: ORDENADO POR PONTUACAO           \n");
    printf("==================================================\n");
    // Diana(3000) deve ser a primeira, Evan(800) o último.
    bubble_sort_dinamico(&inicio, ORDENAR_PONTUACAO);
    imprimir(&inicio);

    /* TESTE 2: Nível (Maior para o Menor) */
    printf("\n==================================================\n");
    printf("          TESTE 2: ORDENADO POR NIVEL             \n");
    printf("==================================================\n");
    // Diana(20) continua em primeiro, mas agora Charlie e Fiona(15) sobem.
    bubble_sort_dinamico(&inicio, ORDENAR_NIVEL);
    imprimir(&inicio);

    /* TESTE 3: Tempo Jogado (Menor para o Maior) */
    printf("\n==================================================\n");
    printf("          TESTE 3: ORDENADO POR TEMPO             \n");
    printf("==================================================\n");
    // Aqui a lógica inverte! Evan(20.0) e Fiona(30.0) devem ser os primeiros.
    bubble_sort_dinamico(&inicio, ORDENAR_TEMPO);
    imprimir(&inicio);

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
    bubble_sort_dinamico(&inicio, ORDENAR_COMBINADO);
    imprimir(&inicio);

    // Limpeza
    liberar_lista(&inicio);
    printf("\nMemoria liberada com sucesso. Fim dos testes.\n");

    return 0;
}