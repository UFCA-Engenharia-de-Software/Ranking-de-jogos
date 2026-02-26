#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gerador_jogadores.h"

static void inicializar_seed_uma_vez(void)
{
    static int inicializado = 0;
    if (!inicializado) {
        srand((unsigned int)time(NULL));
        inicializado = 1;
    }
}

void gerarJogadores(Lista *lista, int quantidade, int tipo_ordem) {

    iniciarLista(lista);
    inicializar_seed_uma_vez();

    for (int i = 0; i < quantidade; i++) {
        Jogador j;
        sprintf(j.nickname, "Player_%d", i + 1);
        
        // Atributos aleatórios padrão
        j.nivel = (rand() % 100) + 1;            
        j.tempo_jogado = (rand() % 5000) / 10.0; 

        
        if (tipo_ordem == ALEATORIA) {
            j.pontuacao = rand() % 100000; 
            
        } else if (tipo_ordem == ORDENADA) {
            j.pontuacao = i * 10; 
            
        } else if (tipo_ordem == INVERSAMENTE_ORDENADA) {
            j.pontuacao = (quantidade - i) * 10; 
        }
        
        inserir(lista, j);
    }
}

void gerarJogadoresDinamica(NoDuplo **head, int quantidade, int tipo_ordem) {
    *head = NULL;
    inicializar_seed_uma_vez();

    for (int i = 0; i < quantidade; i++) {
        Jogador novo_jogador;

        sprintf(novo_jogador.nickname, "Player_%d", i + 1);
        
        // Atributos aleatórios padrão
        novo_jogador.nivel = (rand() % 100) + 1;            
        novo_jogador.tempo_jogado = (rand() % 5000) / 10.0; 

        
        if (tipo_ordem == ALEATORIA) {
            novo_jogador.pontuacao = rand() % 100000; 
            
        } else if (tipo_ordem == ORDENADA) {
            novo_jogador.pontuacao = i * 10; 
            
        } else if (tipo_ordem == INVERSAMENTE_ORDENADA) {
            novo_jogador.pontuacao = (quantidade - i) * 10; 
        }
        
        inserirDinamica(head, novo_jogador);
    }
}
