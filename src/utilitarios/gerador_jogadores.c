#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gerador_jogadores.h"

void gerarJogadores(Lista *lista, int quantidade, int tipo_ordem) {

    iniciarLista(lista);

    srand(time(NULL));

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
