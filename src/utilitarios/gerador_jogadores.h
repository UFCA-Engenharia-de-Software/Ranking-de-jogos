#ifndef GERADOR_TESTES_H
#define GERADOR_TESTES_H

#include "../lista_encadeada_estatica.h" // Ajuste o caminho (../) se colocar em subpastas depois

// Definindo as constantes de ordem para o código ficar chique e legível
#define ALEATORIA 1
#define ORDENADA 2
#define INVERSAMENTE_ORDENADA 3

// Declaração da função da Task 16
void gerarJogadores(Lista *lista, int quantidade, int tipo_ordem);

#endif