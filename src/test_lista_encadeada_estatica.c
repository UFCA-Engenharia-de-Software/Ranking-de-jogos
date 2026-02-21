#include <stdio.h>
#include <string.h>
#include "lista_encadeada_estatica.h"

int main() {
    printf("=== INICIANDO TESTES DA TASK 4 ===\n\n");

    // 1. Criar e iniciar a lista
    Lista minha_lista;
    iniciarLista(&minha_lista);
    printf("[OK] Lista iniciada com sucesso.\n");

    // 2. Criar alguns jogadores de teste
    Jogador j1, j2, j3;
    
    strcpy(j1.nickname, "Fallen");
    j1.pontuacao = 2000;
    j1.nivel = 50;
    j1.tempo_jogado = 120.5;

    strcpy(j2.nickname, "Coldzera");
    j2.pontuacao = 2500;
    j2.nivel = 60;
    j2.tempo_jogado = 150.0;

    strcpy(j3.nickname, "Taco");
    j3.pontuacao = 1800;
    j3.nivel = 45;
    j3.tempo_jogado = 110.2;

    // 3. Testar a Inserção
    printf("\n--- INSERINDO JOGADORES ---\n");
    inserir(&minha_lista, j1);
    inserir(&minha_lista, j2);
    inserir(&minha_lista, j3);
    
    // 4. Testar a Impressão
    imprimir(&minha_lista);

    // 5. Testar a Busca
    printf("--- BUSCANDO JOGADOR 'Coldzera' ---\n");
    int indice_encontrado = busca(&minha_lista, "Coldzera");
    
    if (indice_encontrado != INVALIDO) {
        printf("[OK] Jogador encontrado no indice interno: %d\n", indice_encontrado);
    } else {
        printf("[ERRO] Jogador nao encontrado.\n");
    }

    // 6. Testar a Remoção
    printf("\n--- DELETANDO JOGADOR 'Coldzera' ---\n");
    if (indice_encontrado != INVALIDO) {
        deletar(&minha_lista, indice_encontrado);
        printf("[OK] Comando de deletar executado.\n");
    }

    // 7. Imprimir novamente para verificar a remoção
    printf("\n--- LISTA APOS REMOCAO ---\n");
    imprimir(&minha_lista);

    printf("=== TESTES FINALIZADOS ===\n");
    return 0;
}