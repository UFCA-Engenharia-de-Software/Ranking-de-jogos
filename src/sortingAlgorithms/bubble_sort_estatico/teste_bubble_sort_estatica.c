#include <stdio.h>
#include <string.h>
#include "bubble_sort_estatica.h"

int main() {
    printf("=== INICIANDO TESTE DA TASK 10 (BUBBLE SORT) ===\n\n");

    Lista minha_lista;
    iniciarLista(&minha_lista);

    // Criando jogadores com pontuações bagunçadas
    Jogador j1, j2, j3, j4;
    
    strcpy(j1.nickname, "Taco");
    j1.pontuacao = 1800;
    j1.nivel = 45;
    j1.tempo_jogado = 110.2;

    strcpy(j2.nickname, "Fnx");
    j2.pontuacao = 3000;
    j2.nivel = 70;
    j2.tempo_jogado = 200.0;

    strcpy(j3.nickname, "Fallen");
    j3.pontuacao = 2000;
    j3.nivel = 50;
    j3.tempo_jogado = 120.5;

    strcpy(j4.nickname, "Coldzera");
    j4.pontuacao = 2500;
    j4.nivel = 60;
    j4.tempo_jogado = 150.0;

    // Inserindo na lista
    inserir(&minha_lista, j1);
    inserir(&minha_lista, j2);
    inserir(&minha_lista, j3);
    inserir(&minha_lista, j4);

    printf("--- LISTA ANTES DA ORDENACAO ---\n");
    imprimir(&minha_lista);

    // Chamando o algoritmo da Task 10
    bubbleSortEstatica(&minha_lista, ORDENAR_PONTUACAO);

    printf("\n--- LISTA APOS BUBBLE SORT (Maior para o Menor) ---\n");
    imprimir(&minha_lista);

    printf("=== TESTE FINALIZADO ===\n");
    return 0;
}
