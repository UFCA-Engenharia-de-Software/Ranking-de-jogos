/*
Arquivo: lista_encadeada_estatica.c
Descrição:
Implementa as funções declaradas em lista_encadeada_estatica.h, realizando o
controle manual das posições livres em um vetor pré-alocado.

Essa estrutura é utilizada nos experimentos para comparar o impacto
das diferentes estruturas de dados no desempenho dos algoritmos de
ordenação.
*/
#include <stdlib.h>
#include <stdio.h>
#include "lista_encadeada_estatica.h"
#include <string.h>

void iniciarLista(Lista *lista) {

    lista ->inicio = INVALIDO;
    lista ->livre = 0;
    for (int i = 0; i < MAX - 1; i++) {
        lista ->vetor[i].proximo = i + 1;
    }

    lista ->vetor[MAX - 1].proximo = INVALIDO;

}


int inserir(Lista *lista, Jogador jogador) {

    if (lista == NULL) {
        return INVALIDO;
    }

    if (lista ->livre == INVALIDO) {
        return 0;
    }

    int novo_indice = lista ->livre;
    lista ->livre = lista ->vetor[novo_indice].proximo;

    lista -> vetor[novo_indice].jogador = jogador;
    lista ->vetor[novo_indice].proximo = INVALIDO;

    if (lista ->inicio == INVALIDO) {
        lista ->vetor[novo_indice].anterior = INVALIDO;
        lista ->inicio = novo_indice;
    } else {
        int aux = lista ->inicio;
        while (lista ->vetor[aux].proximo != INVALIDO) {
            aux = lista ->vetor[aux].proximo;
        }

        lista ->vetor[aux].proximo = novo_indice;
        lista ->vetor[novo_indice].anterior = aux;
    }

    return 1;
    
}

void imprimir(Lista *lista) {

    if (lista == NULL || lista ->inicio == INVALIDO) {
        printf("Lista Vazia");
        return;
    }

    int atual = lista->inicio;
    
    int posicao = 1;

    while (atual != INVALIDO) {

        printf("Posicao: %d | Nickname: %s | Pontuacao: %d | Nivel: %d | Tempo: %.2f\n", 
               posicao, 
               lista->vetor[atual].jogador.nickname,
               lista->vetor[atual].jogador.pontuacao,
               lista->vetor[atual].jogador.nivel,
               lista->vetor[atual].jogador.tempo_jogado);

        
        atual = lista->vetor[atual].proximo; 
        
        posicao++; 
    }
    printf("\n");
    
}

int busca(Lista *lista, const char *nickname) {
    if (lista == NULL || lista ->inicio== INVALIDO) {
        
        return INVALIDO;
    }

    int atual = lista->inicio;

    int posicao = 1;

    while (atual != INVALIDO) {
        if (strcmp(lista ->vetor[atual].jogador.nickname, nickname) == 0) {
            return atual;
        }
        atual = lista ->vetor[atual].proximo;
    }

    return INVALIDO;
}

void deletar(Lista *lista, int indice_alvo) {

    if (lista == NULL || lista->inicio == INVALIDO || indice_alvo == INVALIDO) {
        return; 
    }
    
    int ant = lista->vetor[indice_alvo].anterior;
    int prox = lista->vetor[indice_alvo].proximo;

    if (ant == INVALIDO) {
        lista->inicio = prox; 
    } else {
        
        lista->vetor[ant].proximo = prox;
    }

    if (prox != INVALIDO) {
        
        lista->vetor[prox].anterior = ant;
    }
    
    lista->vetor[indice_alvo].proximo = lista->livre;
   
    lista->vetor[indice_alvo].anterior = INVALIDO; 
    
    lista->livre = indice_alvo; 
}